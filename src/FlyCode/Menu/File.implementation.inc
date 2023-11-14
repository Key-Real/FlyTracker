


procedure TMainMenu.execProcMenuFileSelect(const param: string);
var 
    aItem : TtuiMenuHorizontalItem;

begin

    aItem:= MenuHorizontal.getItemByName('Menu File');

    BoxVerticalMenuFile:= TtuiBox.Create(MenuTUI, aItem.x, 18, 0, 0, 'Box Vertical Menu File', tuiBoxStatic);
    BoxVerticalMenuFile.themeBox:= LoadThemeBox;
    MenuTUI.addBox(BoxVerticalMenuFile);

    FileMenuVertical:= TtuiMenuVertical.create(BoxVerticalMenuFile, 'Vertical Menu File');
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - NewFile', 'New', @execProcMenuItemNewFile);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - SaveFile', 'Save File', @execProcMenuItemSaveFile);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - LoadFile', 'Load File', @execProcMenuItemLoadFile);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - ExportFile', 'Export File', nil);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - Wav Mixdown', 'Wav Mixdown', @execProcMenuItemWavSaveFile);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - Connection', 'Connection', @execProcMenuItemConnection);
    FileMenuVertical.addMenuVerticalItem('Vertical Menu File - Exit', 'Exit', @execProcMenuItemExit);
    FileMenuVertical.theme:= LoadThemeMenuVertical;


    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - NewFile')].MouseOverExecProc:= @execProcMenuItemNewFileSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - SaveFile')].MouseOverExecProc:= @execProcMenuItemSaveFileSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - LoadFile')].MouseOverExecProc:= @execProcMenuItemLoadFileSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - Wav Mixdown')].MouseOverExecProc:= @execProcMenuItemWavSaveFileSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - Connection')].MouseOverExecProc:= @execProcMenuItemConnectionSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - Exit')].MouseOverExecProc:= @execProcMenuItemExitSelect;

    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - ExportFile')].mouseOverExecProc:= @execProcMenuItemExportFileSelect;
    FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - ExportFile')].leaveMouseOverExecProc:= @execProcMenuItemExportFileUnSelect;
    FileMenuVertical.allowMouse2Buttons:= true;
    BoxVerticalMenuFile.addItem(FileMenuVertical);

end;

procedure TMainMenu.execProcMenuFileUnSelect(const param: string);
begin

    MenuTUI.closeBox(BoxVerticalMenuFileExport);

    MenuTUI.closeBox(BoxVerticalMenuFile);

end;



//////////////////////////////////////////////////////////////////////////////////////////////////




procedure TMainMenu.execProcMenuItemLoadFile(const param: string);
begin    

    if assigned(aDialogLoadFile) then exit;
    aDialogLoadFile:= TmyLoadFileDialog.Create(@aDialogLoadFile, MenuTUI);

end;



constructor TMainMenu.TmyLoadFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin

    parentTUI:= theTUI;
    theDialogLoadFile:= TtuiDialogLoadFile.Create(@theDialogLoadFile, parentTUI);
    theDialogLoadFile.addExtentionHint('Modules');
    theDialogLoadFile.addExtention('.669');
    theDialogLoadFile.addExtention('.it');
    theDialogLoadFile.addExtention('.mod');
    theDialogLoadFile.addExtention('.mtm');
    theDialogLoadFile.addExtention('.s3m');
    theDialogLoadFile.addExtention('.stm');
    theDialogLoadFile.addExtention('.umx');
    theDialogLoadFile.addExtention('.xm');
    theDialogLoadFile.addExtentionHint('All Files');
    theDialogLoadFile.addExtention('.*');

    theDialogLoadFile.curState.curPath:= LoadFileLastStateCurPath;
    theDialogLoadFile.curState.chosen:= LoadFileLastStateChosen;
    theDialogLoadFile.curState.Scrolled:= LoadFileLastStateScrolled;
    theDialogLoadFile.curState.ScrollBarPosition:= LoadFileLastStateScrollBarPosition;

    theDialogLoadFile.execute(@execProcSuccess, @execProcCancel);

    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileLoadDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmyLoadFileDialog.destroy;
begin

    this^:= nil;
    inMenuItem:= false;

end;


procedure TMainMenu.TmyLoadFileDialog.execProcSuccess(const param: string);
var 
    aMessage: TtuiMessage;

begin

    tralalaEngine.StopPlaying;

    try
        tralalaEngine.LoadModule(param);
    except
        if assigned(theCantLoadFileDialogMessageBox) then freeandnil(theCantLoadFileDialogMessageBox);
        theCantLoadFileDialogMessageBox:= TtuiDialogMessageBox.Create(@theCantLoadFileDialogMessageBox, trackerTUI, 'Can''t load File');
    end;

    CurrentOrder:= 0;
    
    Tracker.reload(true);

    if currentmode = modeInstrumentEditor then begin
        InstrumentEditor.reloadInstrumentEditor;
    end;

    LoadFileLastStateCurPath:= theDialogLoadFile.curState.curPath;
    LoadFileLastStateChosen:= theDialogLoadFile.curState.Chosen;
    LoadFileLastStateScrolled:= theDialogLoadFile.curState.Scrolled;
    LoadFileLastStateScrollBarPosition:= theDialogLoadFile.curState.ScrollBarPosition;

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileLoadDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;



procedure TMainMenu.TmyLoadFileDialog.execProcCancel(const param: string);
var 
    aMessage:TtuiMessage;

begin

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileLoadDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;




//////////////////////////////////////////////////////////////////////////////////////////////////


procedure TMainMenu.execProcMenuItemSaveFile(const param: string);
begin    

    if assigned(aDialogSaveFile) then exit;
    aDialogSaveFile:= TmySaveFileDialog.Create(@aDialogSaveFile, MenuTUI);

end;



constructor TMainMenu.TmySaveFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin

    parentTUI:= theTUI;
    theDialogSaveFile:= TtuiDialogSaveFile.Create(@theDialogSaveFile, parentTUI);
    theDialogSaveFile.chosenFile:= lastFileName;
    theDialogSaveFile.addExtentionHint('Modules');
    theDialogSaveFile.addExtention('.669');
    theDialogSaveFile.addExtention('.it');
    theDialogSaveFile.addExtention('.mod');
    theDialogSaveFile.addExtention('.mtm');
    theDialogSaveFile.addExtention('.s3m');
    theDialogSaveFile.addExtention('.stm');
    theDialogSaveFile.addExtention('.umx');
    theDialogSaveFile.addExtention('.xm');
    theDialogSaveFile.addExtentionHint('All Files');
    theDialogSaveFile.addExtention('.*');

    theDialogSaveFile.curState.curPath:= lastPathSaveFile;
    theDialogSaveFile.curState.Chosen:= lastChosenSaveFile;
    theDialogSaveFile.curState.Scrolled:= lastScrollSaveFile;
    theDialogSaveFile.curState.ScrollBarPosition:= lastScrollBarPositionSaveFile;

    theDialogSaveFile.execute(@execProcSuccess, @execProcCancel);
    
    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmySaveFileDialog.destroy;
begin

    this^:= nil;
    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveFileDialog.execProcSuccess(const param: string);
var
    Module : TModule;
    SaveFlags : TModuleSaveFlags;
    Stream : TStream = nil;
    Logger : TLogger = nil;

    aMessage : TtuiMessage;

begin
    
    lastFileName:= ExtractFileName(ChangeFileExt(param, '.it'));
    
    tralalaEngine.StopPlaying;

    Stream:= TFileStream.Create(ChangeFileExt(param, '.it'), fmCreate or fmShareExclusive);
    Logger:= TSilentLogger.Create;

    SaveFlags:= [];
    Include(SaveFlags, msfDoNotWriteMidiConfig);

    tralalaEngine.Lock_Module_ReadOnly(Module);
      Loaders.SaveModule(Module, Stream, msffITNotCompressed, SaveFlags, Logger);
    tralalaEngine.Unlock_Module_ReadOnly;

    FreeAndNil(Logger);
    FreeAndNil(Stream);

    lastPathSaveFile:= theDialogSaveFile.curState.curPath;
    lastChosenSaveFile:= theDialogSaveFile.curState.Chosen;
    lastScrollSaveFile:= theDialogSaveFile.curState.Scrolled;
    lastScrollBarPositionSaveFile:= theDialogSaveFile.curState.ScrollBarPosition;

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveFileDialog.execProcCancel(const param: string);
var 
    aMessage : TtuiMessage;
begin
    
    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


procedure TMainMenu.execProcMenuItemWavSaveFile(const param: string);
begin    

    if assigned(aDialogWavSaveFile) then exit;
    aDialogWavSaveFile:= TmyWavSaveFileDialog.Create(@aDialogWavSaveFile, MenuTUI);

end;


constructor TMainMenu.TmyWavSaveFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin
    
    parentTUI:= theTUI;
    theDialogWavSaveFile:= TtuiDialogSaveFile.Create(@theDialogWavSaveFile, parentTUI);
    theDialogWavSaveFile.chosenFile:= lastWavFileName;
    
    theDialogWavSaveFile.curState.curPath:= lastPathWavSaveFile;
    theDialogWavSaveFile.curState.Chosen:= lastChosenWavSaveFile;
    theDialogWavSaveFile.curState.Scrolled:= lastScrollWavSaveFile;
    theDialogWavSaveFile.curState.ScrollBarPosition:= lastScrollBarPositionWavSaveFile;

    theDialogWavSaveFile.addExtentionHint('wav');
    theDialogWavSaveFile.addExtention('.wav');
    theDialogWavSaveFile.addExtentionHint('All Files');
    theDialogWavSaveFile.addExtention('.*');
    theDialogWavSaveFile.execute(@execProcSuccess, @execProcCancel);

    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveWavDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmyWavSaveFileDialog.destroy;
begin
    this^:= nil;
    inMenuItem:= false;
end;


procedure TMainMenu.TmyWavSaveFileDialog.execProcSuccess(const param: string);
begin

    save2wave:= true;
    waveFileName:= param;

    lastWavFileName:= theDialogWavSaveFile.chosenFile;
    lastPathWavSaveFile:= theDialogWavSaveFile.curState.curPath;
    lastChosenWavSaveFile:= theDialogWavSaveFile.curState.Chosen;
    lastScrollWavSaveFile:= theDialogWavSaveFile.curState.Scrolled;
    lastScrollBarPositionWavSaveFile:= theDialogWavSaveFile.curState.ScrollBarPosition;

end;


procedure TMainMenu.TmyWavSaveFileDialog.execProcCancel(const param: string);
var 
    aMessage : TtuiMessage;    
begin

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveWavDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


//////////////////////////////////////////////////////////////////////////////////////////////////



procedure TMainMenu.execProcMenuItemNewFile(const param: string);
begin
    
    MenuTUI.closeBox(BoxVerticalMenuFile);
    MenuTUI.closeBox(NewFileBox);

    tralalaEngine.StopPlaying;

    NewFileBox:= TtuiBox.create(MenuTUI, TrackerTUI.screen.width div 2 - 100, TrackerTUI.screen.height div 2 - 100, 200 + 10 + 10 + 10, 240, 'NewFileBox', tuiBoxStd);
    NewFileBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(NewFileBox);


    TextFieldNewFile:= TtuiTextField.create(NewFileBox, 'TextFieldNewFile', 10, 16, 'New File');
    TextFieldNewFile.theme:= LoadThemeTextField;
    NewFileBox.addItem(TextFieldNewFile);


    NewFileCheckBoxKeepPatterns:= TtuiCheckBox.Create(NewFileBox, 'NewFileCheckBoxKeepPatterns', 16, 40, 120, 24, 'Keep Patterns', nil);
    NewFileCheckBoxKeepPatterns.theme:= LoadThemeCheckBox;
    NewFileCheckBoxKeepPatterns.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepPatterns.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepPatterns.isChecked:= false;
    NewFileBox.addItem(NewFileCheckBoxKeepPatterns);

    NewFileCheckBoxKeepSamples:= TtuiCheckBox.Create(NewFileBox, 'NewFileCheckBoxKeepSamples', 16, 64, 120, 24, 'Keep Samples', nil);
    NewFileCheckBoxKeepSamples.theme:= LoadThemeCheckBox;    
    NewFileCheckBoxKeepSamples.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepSamples.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepSamples.isChecked:= false;
    NewFileBox.addItem(NewFileCheckBoxKeepSamples);

    NewFileCheckBoxKeepInstruments:= TtuiCheckBox.Create(NewFileBox, 'NewFileCheckBoxKeepInstruments', 16, 88, 120, 24, 'Keep Instruments', nil);
    NewFileCheckBoxKeepInstruments.theme:= LoadThemeCheckBox;    
    NewFileCheckBoxKeepInstruments.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepInstruments.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepInstruments.isChecked:= false;
    NewFileBox.addItem(NewFileCheckBoxKeepInstruments);

    NewFileCheckBoxKeepOrder:= TtuiCheckBox.Create(NewFileBox, 'NewFileCheckBoxKeepOrder', 16, 112, 120, 24, 'Keep Order', nil);
    NewFileCheckBoxKeepOrder.theme:= LoadThemeCheckBox;    
    NewFileCheckBoxKeepOrder.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepOrder.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
    NewFileCheckBoxKeepOrder.isChecked:= false;
    NewFileBox.addItem(NewFileCheckBoxKeepOrder);



    RadioButtonGroupModuleType:= TtuiRadioButtonGroup.Create(NewFileBox, 'RadioButtonLoopTypeGroup');
    NewFileBox.addItem(RadioButtonGroupModuleType);

    RadioButtonModuleTypeSample:= TtuiRadioButton.Create(NewFileBox, 'RadioButtonModuleTypeSample', 16, 150, 'Sample Driven Module', nil);
    RadioButtonModuleTypeSample.theme:= LoadThemeRadioButton;
    RadioButtonGroupModuleType.add2group(RadioButtonModuleTypeSample);

    RadioButtonModuleTypeInstrument:= TtuiRadioButton.Create(NewFileBox, 'RadioButtonModuleTypeInstrument', 16, 174, 'Instrument Driven Module', nil);
    RadioButtonModuleTypeInstrument.theme:= LoadThemeRadioButton;
    RadioButtonModuleTypeInstrument.checked:= true;
    RadioButtonGroupModuleType.add2group(RadioButtonModuleTypeInstrument);


    ButtonNewFileOK:= TtuiButton.create(NewFileBox, 'ButtonNewFileOK', 120, 240 - 16 - 26, 100, 26, 'Ok', @execProcMenuItemNewFileOK);   
    ButtonNewFileOK.theme:= LoadThemeButton;
    NewFileBox.addItem(ButtonNewFileOK);

    ButtonNewFileCancel:= TtuiButton.create(NewFileBox, 'ButtonNewFileCancel', 10, 240 - 16 - 26, 100, 26, 'Cancel', @execProcMenuItemNewFileCancel);   
    ButtonNewFileCancel.theme:= LoadThemeButton;
    NewFileBox.addItem(ButtonNewFileCancel);

    inMenuItem:=true;

end;


procedure TMainMenu.execProcMenuItemNewFileOK(const param: string);
begin

    MenuTUI.closeBox(NewFileBox);


    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        if not NewFileCheckBoxKeepPatterns.isChecked then begin 
            Module.NumberOfChannels:= 8;
            Module.Patterns.Clear;
        end;
        if not NewFileCheckBoxKeepSamples.isChecked then Module.Samples.Clear;
        
        if not NewFileCheckBoxKeepInstruments.isChecked then Module.Instruments.Clear else begin
            if not (mfInstrumentsControl in Module.Flags) then begin
                module.InitialiseInstruments;
            end;
        end;

        if not NewFileCheckBoxKeepOrder.isChecked then begin
            Module.Order.Clear;
            Module.order[0]:= 0;
            Module.order[1]:= EndOfSongMarker;
        end;

        Module.ChannelsConfig.Clear;
        Module.MidiConfig.Clear;
        Module.ClearVariables;

        if RadioButtonModuleTypeInstrument.checked then Module.Flags:= Module.Flags + [mfInstrumentsControl];

    tralalaEngine.Unlock_Module_ReadWrite;



    

    if currentmode = modeTracker then begin
        CurrentOrder:= 0;
        Tracker.reload(true);
    end;

    if currentmode = modeInstrumentEditor then begin
        InstrumentEditor.reloadInstrumentEditor;
    end;


    inMenuItem:= false;
end;


procedure TMainMenu.execProcMenuItemNewFileCancel(const param: string);
begin
     MenuTUI.closeBox(NewFileBox);
    inMenuItem:=false;
end;


/////////////////////////


procedure TMainMenu.execProcMenuItemExit(const param: string);
begin
    MenuTUI.closeBox(BoxVerticalMenuFile);
    gfxDone:= true;
end;





procedure TMainMenu.execProcMenuItemExportFileSelect(const param: string);
var 
    aItem : TtuiMenuVerticalItem;

begin

    if assigned(BoxVerticalMenuFileExport) then exit;
    
    aItem:= FileMenuVertical.verticalItems[FileMenuVertical.getVerticalItemNum('Vertical Menu File - ExportFile')];

    BoxVerticalMenuFileExport:= TtuiBox.Create(MenuTUI, FileMenuVertical.parentBox.boxX + FileMenuVertical.parentBox.boxWidth, FileMenuVertical.parentBox.boxY + aItem.y, 0, 0, 'Box Vertical Menu File Export', tuiBoxStatic);
    BoxVerticalMenuFileExport.themeBox:= LoadThemeBox;
    MenuTUI.addBox(BoxVerticalMenuFileExport);


    FileExportMenuVertical:= TtuiMenuVertical.create(BoxVerticalMenuFileExport, 'Vertical Menu File Export');
    FileExportMenuVertical.addMenuVerticalItem('Vertical Menu File Export - mod', 'mod', @execProcMenuItemSaveMODFile);
    FileExportMenuVertical.addMenuVerticalItem('Vertical Menu File Export - s3m', 's3m', @execProcMenuItemSaveS3MFile);
    FileExportMenuVertical.addMenuVerticalItem('Vertical Menu File Export - xm', 'xm', @execProcMenuItemSaveXMFile);
    FileExportMenuVertical.theme:= LoadThemeMenuVertical;

    BoxVerticalMenuFileExport.addItem(FileExportMenuVertical);

end;

procedure TMainMenu.execProcMenuItemExportFileUnSelect(const param: string);
begin

    if not assigned(BoxVerticalMenuFileExport) then exit;

    if not FileExportMenuVertical.isInAnyMenu then
        MenuTUI.closeBox(BoxVerticalMenuFileExport);


end;


procedure TMainMenu.execProcMenuItemNewFileSelect(const param: string);
begin
    
    MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;


procedure TMainMenu.execProcMenuItemSaveFileSelect(const param: string);
begin

    MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;


procedure TMainMenu.execProcMenuItemLoadFileSelect(const param: string);
begin

        MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;


procedure TMainMenu.execProcMenuItemWavSaveFileSelect(const param: string);
begin

        MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;


procedure TMainMenu.execProcMenuItemConnectionSelect(const param: string);
begin

        MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;

procedure TMainMenu.execProcMenuItemExitSelect(const param: string);
begin

        MenuTUI.closeBox(BoxVerticalMenuFileExport);

end;




//////////////////////////////////////////////////////////////////////////////////////////////////


procedure TMainMenu.execProcMenuItemSaveMODFile(const param: string);
begin    

     MenuTUI.closeBox(BoxVerticalMenuFileExport);

    if assigned(aDialogSaveMODFile) then exit;
    aDialogSaveMODFile:= TmySaveMODFileDialog.Create(@aDialogSaveMODFile, MenuTUI);

end;



constructor TMainMenu.TmySaveMODFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin

    parentTUI:= theTUI;
    theDialogSaveMODFile:= TtuiDialogSaveFile.Create(@theDialogSaveMODFile, parentTUI);
    theDialogSaveMODFile.chosenFile:= lastMODFileName;
    theDialogSaveMODFile.addExtentionHint('Pro Tracker Modules');
    theDialogSaveMODFile.addExtention('.mod');
    theDialogSaveMODFile.addExtentionHint('All Files');
    theDialogSaveMODFile.addExtention('.*');

    theDialogSaveMODFile.curState.curPath:= lastPathSaveMODFile;
    theDialogSaveMODFile.curState.Chosen:= lastChosenSaveMODFile;
    theDialogSaveMODFile.curState.Scrolled:= lastScrollSaveMODFile;
    theDialogSaveMODFile.curState.ScrollBarPosition:= lastScrollBarPositionSaveMODFile;

    theDialogSaveMODFile.execute(@execProcSuccess, @execProcCancel);
    
    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveMODDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmySaveMODFileDialog.destroy;
begin

    this^:= nil;
    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveMODFileDialog.execProcSuccess(const param: string);
var
    Module : TModule;
    SaveFlags : TModuleSaveFlags;
    Stream : TStream = nil;
    Logger : TLogger = nil;

    aMessage : TtuiMessage;

begin
    
    lastFileName:= ExtractFileName(ChangeFileExt(param, '.mod'));
    
    tralalaEngine.StopPlaying;

    Stream:= TFileStream.Create(ChangeFileExt(param, '.mod'), fmCreate or fmShareExclusive);
    Logger:= TSilentLogger.Create;

    SaveFlags:= [];
    Include(SaveFlags, msfDoNotWriteMidiConfig);

    tralalaEngine.Lock_Module_ReadOnly(Module);
      Loaders.SaveModule(Module, Stream, msffMOD31, SaveFlags, Logger);
    tralalaEngine.Unlock_Module_ReadOnly;

    FreeAndNil(Logger);
    FreeAndNil(Stream);

    lastPathSaveMODFile:= theDialogSaveMODFile.curState.curPath;
    lastChosenSaveMODFile:= theDialogSaveMODFile.curState.Chosen;
    lastScrollSaveMODFile:= theDialogSaveMODFile.curState.Scrolled;
    lastScrollBarPositionSaveMODFile:= theDialogSaveMODFile.curState.ScrollBarPosition;

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveMODDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveMODFileDialog.execProcCancel(const param: string);
var 
    aMessage : TtuiMessage;
begin
    
    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveMODDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;







//////////////////////////////////////////////////////////////////////////////////////////////////


procedure TMainMenu.execProcMenuItemSaveS3MFile(const param: string);
begin    

     MenuTUI.closeBox(BoxVerticalMenuFileExport);

    if assigned(aDialogSaveS3MFile) then exit;
    aDialogSaveS3MFile:= TmySaveS3MFileDialog.Create(@aDialogSaveS3MFile, MenuTUI);

end;



constructor TMainMenu.TmySaveS3MFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin

    parentTUI:= theTUI;
    theDialogSaveS3MFile:= TtuiDialogSaveFile.Create(@theDialogSaveS3MFile, parentTUI);
    theDialogSaveS3MFile.chosenFile:= lastS3MFileName;
    theDialogSaveS3MFile.addExtentionHint('Scream Tracker 3 Modules');
    theDialogSaveS3MFile.addExtention('.s3m');
    theDialogSaveS3MFile.addExtentionHint('All Files');
    theDialogSaveS3MFile.addExtention('.*');

    theDialogSaveS3MFile.curState.curPath:= lastPathSaveS3MFile;
    theDialogSaveS3MFile.curState.Chosen:= lastChosenSaveS3MFile;
    theDialogSaveS3MFile.curState.Scrolled:= lastScrollSaveS3MFile;
    theDialogSaveS3MFile.curState.ScrollBarPosition:= lastScrollBarPositionSaveS3MFile;

    theDialogSaveS3MFile.execute(@execProcSuccess, @execProcCancel);
    
    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveS3MDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmySaveS3MFileDialog.destroy;
begin

    this^:= nil;
    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveS3MFileDialog.execProcSuccess(const param: string);
var
    Module : TModule;
    SaveFlags : TModuleSaveFlags;
    Stream : TStream = nil;
    Logger : TLogger = nil;

    aMessage : TtuiMessage;

begin
    
    lastFileName:= ExtractFileName(ChangeFileExt(param, '.s3m'));
    
    tralalaEngine.StopPlaying;

    Stream:= TFileStream.Create(ChangeFileExt(param, '.s3m'), fmCreate or fmShareExclusive);
    Logger:= TSilentLogger.Create;

    SaveFlags:= [];
    Include(SaveFlags, msfDoNotWriteMidiConfig);

    tralalaEngine.Lock_Module_ReadOnly(Module);
      Loaders.SaveModule(Module, Stream, msffS3M, SaveFlags, Logger);
    tralalaEngine.Unlock_Module_ReadOnly;

    FreeAndNil(Logger);
    FreeAndNil(Stream);

    lastPathSaveS3MFile:= theDialogSaveS3MFile.curState.curPath;
    lastChosenSaveS3MFile:= theDialogSaveS3MFile.curState.Chosen;
    lastScrollSaveS3MFile:= theDialogSaveS3MFile.curState.Scrolled;
    lastScrollBarPositionSaveS3MFile:= theDialogSaveS3MFile.curState.ScrollBarPosition;

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveS3MDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveS3MFileDialog.execProcCancel(const param: string);
var 
    aMessage : TtuiMessage;
begin
    
    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveS3MDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;










//////////////////////////////////////////////////////////////////////////////////////////////////


procedure TMainMenu.execProcMenuItemSaveXMFile(const param: string);
begin    

     MenuTUI.closeBox(BoxVerticalMenuFileExport);

    if assigned(aDialogSaveXMFile) then exit;
    aDialogSaveXMFile:= TmySaveXMFileDialog.Create(@aDialogSaveXMFile, MenuTUI);

end;



constructor TMainMenu.TmySaveXMFileDialog.create(Instance: PObject; theTUI: TtuiTUI);
var 
    aMessage : TtuiMessage;

begin

    parentTUI:= theTUI;
    theDialogSaveXMFile:= TtuiDialogSaveFile.Create(@theDialogSaveXMFile, parentTUI);
    theDialogSaveXMFile.chosenFile:= lastXMFileName;
    theDialogSaveXMFile.addExtentionHint('Fast Tracker 2 Modules');
    theDialogSaveXMFile.addExtention('.xm');
    theDialogSaveXMFile.addExtentionHint('All Files');
    theDialogSaveXMFile.addExtention('.*');

    theDialogSaveXMFile.curState.curPath:= lastPathSaveXMFile;
    theDialogSaveXMFile.curState.Chosen:= lastChosenSaveXMFile;
    theDialogSaveXMFile.curState.Scrolled:= lastScrollSaveXMFile;
    theDialogSaveXMFile.curState.ScrollBarPosition:= lastScrollBarPositionSaveXMFile;

    theDialogSaveXMFile.execute(@execProcSuccess, @execProcCancel);
    
    aMessage.MessageType:= tuiMessageDialogInit;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveXMDialog';
    parentTUI.postMessage(aMessage);

    this:= Instance;

    inMenuItem:= true;

end;


destructor TMainMenu.TmySaveXMFileDialog.destroy;
begin

    this^:= nil;
    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveXMFileDialog.execProcSuccess(const param: string);
var
    Module : TModule;
    SaveFlags : TModuleSaveFlags;
    Stream : TStream = nil;
    Logger : TLogger = nil;

    aMessage : TtuiMessage;

begin
    
    lastFileName:= ExtractFileName(ChangeFileExt(param, '.xm'));
    
    tralalaEngine.StopPlaying;

    Stream:= TFileStream.Create(ChangeFileExt(param, '.xm'), fmCreate or fmShareExclusive);
    Logger:= TSilentLogger.Create;

    SaveFlags:= [];
    Include(SaveFlags, msfDoNotWriteMidiConfig);

    tralalaEngine.Lock_Module_ReadOnly(Module);
      Loaders.SaveModule(Module, Stream, msffXM, SaveFlags, Logger);
    tralalaEngine.Unlock_Module_ReadOnly;

    FreeAndNil(Logger);
    FreeAndNil(Stream);

    lastPathSaveXMFile:= theDialogSaveXMFile.curState.curPath;
    lastChosenSaveXMFile:= theDialogSaveXMFile.curState.Chosen;
    lastScrollSaveXMFile:= theDialogSaveXMFile.curState.Scrolled;
    lastScrollBarPositionSaveXMFile:= theDialogSaveXMFile.curState.ScrollBarPosition;

    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveXMDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;


procedure TMainMenu.TmySaveXMFileDialog.execProcCancel(const param: string);
var 
    aMessage : TtuiMessage;
begin
    
    aMessage.MessageType:= tuiMessageCloseDialog;
    aMessage.MessageData:= pointer(self);
    aMessage.MessageFunction:= 'FileSaveXMDialog';
    parentTUI.postMessage(aMessage);

    inMenuItem:= false;

end;
