{$MODE OBJFPC}{$H+}
unit theInstrumentSelector;
interface
uses 
    sysutils, strutils, iostream, classes,
    tools, vipgfx, myTTF,
    TrackerEngine, TralalaPlayer, loaders, loaderit,
    tui.Core, tui.Button, tui.ScrollBarHorizontal, tui.MiddleScrollBox2Entries,
    tui.TextField, tui.SelectBox, tui.SelectableImage, tui.EditField, tui.CheckBox, tui.EditableSelectBoxNumbered,
    tui.ButtonUP, tui.ButtonDOWN, tui.MenuVertical, tui.Image,
    tui.Dialog.LoadFile, tui.Dialog.SaveFile, tui.Dialog.MessageBox,
    Note2Str,
    theTheme, theMain;


type 
    TInstrumentSelector = class
        
        ParentPanel : TtuiBox;
        theTUI : TtuiTUI;
        constructor Create(tui: TtuiTUI; thePanel: TtuiBox);

    var
        allowMenuGo2Editor : boolean;

        onInstrumentSelect : TtuiExecProc;

        execProcSelectorClick : procedure(const param: string);

    procedure buildInstrumentSelector(height: longint);
    procedure reloadInstrumentSelector(zap: boolean);

    procedure execProcInstrumentSelectorClick(const param: string);
    procedure execProcInstrumentSelectorUpdate(const param: string);
    procedure execProcLoseFocus(const param: string);
    procedure execProcRightMouseButton(const param: string);


    procedure execProcMenuClear(const param: string);
    procedure execProcMenuLoad(const param: string);
    procedure execProcMenuSave(const param: string);
    procedure execProcMenuEditor(const param: string);

    var
        InstrumentSelector : TtuiEditableSelectBoxNumbered;

        InstrumentMenuVerticalBox : TtuiBox;
        InstrumentMenuVertical : TtuiMenuVertical;

        theDialogMessageBox : TtuiDialogMessageBox;

        lastInstrumentLoadSate : TtuiDialogLoadFileState;

        theDialogLoadSample:TtuiDialogLoadFile;
        lastSampleName : string;

    procedure execProcSuccessLoadSample(const param: string);
    procedure execProcCancelLoadSample(const param: string);


    var
        theDialogSaveSample : TtuiDialogSaveFile;
        lastInstrumentSavePath : string;
        lastInstrumentSaveLastChosen : longint;
        lastInstrumentSaveScroll : longint;
        lastInstrumentSaveScrollBarPosition : longint;

    procedure execProcSuccessSaveSample(const param: string);
    procedure execProcCancelSaveSample(const param: string);

    function EmptyInstrumentSlot(num: longint): boolean;

    function LoadWav(const name: string): boolean;
    function LoadITI(const name: string): boolean;

    procedure SaveWAV(const name: string);
    procedure SaveITI(const name: string);

    procedure ClickExecProc(const param: string);
 

    var
        lastInstrument : dword;     // becuase of TUI menu selection Bug?? does he jups to another instrument?
        editingName : boolean;
       

    const
        InstrumentNumber4PlayingOnLoad : dword = 64;


    private

            Module : TModule;
            PlayerState : TPlayerState;
            FramesSinceLastTick : Integer;
end;



implementation


constructor TInstrumentSelector.Create(TUI: TtuiTUI; thePanel: TtuiBox);
begin

    ParentPanel:= thePanel;
    theTUI:= TUI;

end;


procedure TInstrumentSelector.buildInstrumentSelector(height: longint);
var 
    i : longint;

begin

    InstrumentSelector:= TtuiEditableSelectBoxNumbered.create(ParentPanel, 'InstrumentSelector', 1280 - 222 - 1, 1, 222, height, @execProcInstrumentSelectorClick);
    InstrumentSelector.theme:= LoadThemeEditableSelectBoxNumbered;
    InstrumentSelector.theme.GlobalYoffset:= 4;
    
    ParentPanel.addItem(InstrumentSelector);

    for i:= 0 to 99 do begin
        InstrumentSelector.addString('');
    end;

    InstrumentSelector.ExecProcEditFieldUpdate:= @execProcInstrumentSelectorUpdate;
    InstrumentSelector.ExecProcLoseFocus:= @execProcLoseFocus;
    InstrumentSelector.ExecProcRightMouseButton:= @execProcRightMouseButton;
    InstrumentSelector.ExecProcEnter:= @execProcLoseFocus;
    InstrumentSelector.exec;

end;


function IsEmpty(Sample: TSample): Boolean;
begin

  Result:= not Sample.ContainsData and
    (Sample.VibratoSpeed = 0) and
    (Sample.VibratoDepth = 0) and
    (Sample.VibratoType = svtSine) and
    (Sample.VibratoDepthIncreaseType = svditRate) and
    (Sample.VibratoFT2StyleKeyOff = False) and
    (Sample.VibratoRateOrSweep = 0) and
    (Sample.DefaultPanEnabled = False) and
    (Sample.DefaultPan = 0) and
    (Sample.GlobalVolume = 64) and
    (Sample.LoopStart = 0) and
    (Sample.LoopEnd = 0) and
    (Sample.LoopType = sltNoLoop) and
    (Sample.SustainLoopStart = 0) and
    (Sample.SustainLoopEnd = 0) and
    (Sample.SustainLoopType = sltNoLoop) and
    (Sample.C5Freq = 8363) and
    (Sample.BaseFineTune = 0);

end;


function TInstrumentSelector.EmptyInstrumentSlot(num: longint): boolean;
var 
    n : longint;

begin

    result:= true;

    if mfInstrumentsControl in Module.Flags then begin
        for N:=NoteMin to NoteMax do
           if (Module.Instruments.Instrument[num].Mapping[N].Sample <> 0) and (Module.Instruments.Instrument[num].Mapping[N].Sample <> 2049) then begin
             result:= false;
             exit;
           end;
    end else begin
        if not isEmpty(Module.Samples.Sample[num]) then result:= false;
    end;

end;


procedure TInstrumentSelector.reloadInstrumentSelector(zap: boolean);
var 
    i : longint;
begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        for i:= 0 to 99 do begin        
            if mfInstrumentsControl in Module.Flags then 
                InstrumentSelector.strings[i].theString:= Module.Instruments.Instrument[i + 1].name 
            else
                InstrumentSelector.strings[i].theString:= Module.Samples.Sample[i + 1].name;

            if emptyInstrumentSlot(i + 1) then InstrumentSelector.strings[i].Color:= Theme_Tracker_EmptyInstrumentColor else InstrumentSelector.strings[i].Color:= Theme_Tracker_MainPanel_FontColor;
        end;

    tralalaEngine.Unlock_ReadOnly;
    
    InstrumentSelector.reset(zap);
    InstrumentSelector.reloadEditFields;
    InstrumentSelector.curChosen:= CurrentInstrument - 1;

end;


procedure TInstrumentSelector.execProcInstrumentSelectorClick(const param: string);
begin

    CurrentInstrument:= InstrumentSelector.curChosen + 1;
    if assigned(onInstrumentSelect) then onInstrumentSelect('');

end;


procedure TInstrumentSelector.execProcInstrumentSelectorUpdate(const param: string);
begin

    allowVirtualPiano:= false;
    tralalaEngine.Lock_Module_ReadWrite(Module);            
    
        Module.Instruments.Instrument[CurrentInstrument].name:= InstrumentSelector.strings[InstrumentSelector.curChosen].theString;
        
    tralalaEngine.Unlock_Module_ReadWrite;

    editingName:= true;

end;


procedure TInstrumentSelector.execProcLoseFocus(const param: string);
begin

    if editingName then begin
        editingName:= false;
        allowVirtualPiano:= true;
        keyboard[KEY_RETURN]:= false;
    end;

end;


procedure TInstrumentSelector.execProcRightMouseButton(const param: string);
begin

    CurrentInstrument:= strnum(param) + 1;
    if mouseR then
        InstrumentMenuVerticalBox:= TtuiBox.create(theTUI, mouseX, mouseY, 0, 0, 'Vertical Menu Instrument Editor', tuiBoxStatic);
    if mouse2R then
        InstrumentMenuVerticalBox:= TtuiBox.create(theTUI, mouse2X, mouse2Y, 0, 0, 'Vertical Menu Instrument Editor', tuiBoxStatic);

    InstrumentMenuVerticalBox.themeBox:= LoadThemeBox;
    theTUI.addBox(InstrumentMenuVerticalBox);

    InstrumentMenuVertical:= TtuiMenuVertical.create(InstrumentMenuVerticalBox, 'Vertical Menu Instrument ' + param);
    InstrumentMenuVertical.addMenuVerticalItem('Vertical Menu Clear', 'Clear Instrument', @execProcMenuClear);
    InstrumentMenuVertical.addMenuVerticalItem('Vertical Menu Load', 'Load Instrument', @execProcMenuLoad);
    InstrumentMenuVertical.addMenuVerticalItem('Vertical Menu Save', 'Save Instrument', @execProcMenuSave);

    if allowMenuGo2Editor then
        InstrumentMenuVertical.addMenuVerticalItem('Vertical Menu Editor', 'Instrument Editor', @execProcMenuEditor);

    if (InstrumentMenuVerticalBox.boxX + InstrumentMenuVerticalBox.boxWidth) >= vscreen.width then InstrumentMenuVerticalBox.BoxX:= vscreen.width - InstrumentMenuVerticalBox.BoxWidth;
    InstrumentMenuVertical.Theme:= LoadThemeMenuVertical;
    InstrumentMenuVertical.Theme.drawBorder:= true;

    InstrumentMenuVerticalBox.addItem(InstrumentMenuVertical);  

end;


procedure TInstrumentSelector.execProcMenuClear(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module); 
        Module.Instruments.Instrument[CurrentInstrument].clear;
        Module.Samples.Sample[CurrentInstrument].clear; 
    tralalaEngine.Unlock_Module_ReadWrite;

    reloadInstrumentSelector(false);

    theTUI.CloseBox(InstrumentMenuVerticalBox);

end;


procedure TInstrumentSelector.execProcMenuLoad(const param: string);
begin

    PatternEditor_allowCursor:= false;

    lastInstrument:=CurrentInstrument;

    theTUI.CloseBox(InstrumentMenuVerticalBox);

    if assigned(theDialogLoadSample) then exit;
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        lastSampleName:= module.Instruments[CurrentInstrument].name;      
        Module.Samples.Sample[129].Assign(Module.Samples.Sample[CurrentInstrument]);  // <- what about instruments
    tralalaEngine.Unlock_Module_ReadWrite;
    

    theDialogLoadSample:= TtuiDialogLoadFile.Create(@theDialogLoadSample, theTUI);
    theDialogLoadSample.ExecProcClick:= @ClickExecProc;

    theDialogLoadSample.addExtentionHint('Sample / Instrument');
    theDialogLoadSample.addExtention('.wav');
    theDialogLoadSample.addExtention('.iti');
    theDialogLoadSample.addExtentionHint('All Files');
    theDialogLoadSample.addExtention('.*');
    theDialogLoadSample.curState:= lastInstrumentLoadSate;
    theDialogLoadSample.execute(@execProcSuccessLoadSample, @execProcCancelLoadSample);

end;


function TInstrumentSelector.loadWav(const name: string): boolean;
var 
    Sample : TSample;
    Logger : TLogger = nil;
    n : longint;

begin

    result:= true;

    Logger:= TSilentLogger.Create;
    Sample:= TSample.Create;

    try
        LoadSample(Sample, name, [], logger);
    except
        result:= false;

        Sample.Free;
        Logger.free;

        exit;
    end;


    tralalaEngine.Lock_Module_ReadWrite(Module);
    
        module.Samples[CurrentInstrument].Assign(Sample);

        for N:= NoteMin to NoteMax do begin
            Module.Instruments[CurrentInstrument].Mapping[N].Note:= N;
            Module.Instruments[CurrentInstrument].Mapping[N].Sample:= CurrentInstrument;
        end;
        
        module.Instruments[CurrentInstrument].name:= extractfilename(name);

    tralalaEngine.Unlock_Module_ReadWrite;

    Sample.Free;
    Logger.free;

    reloadInstrumentSelector(false);

end;


function TInstrumentSelector.loadITI(const name: string): boolean;
var 
    Logger : TLogger = nil;

begin
    
    result:= true;

    Logger:= TSilentLogger.Create;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        try            
            LoadInstrument(Module, CurrentInstrument, 1, MaxNumberOfSamples, name, [], logger);
        except
            result:= false;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

    Logger.free;

end;

 

procedure TInstrumentSelector.execProcSuccessLoadSample(const param: string);
var 
    s : string;
begin
   
{
    tralalaEngine.Lock_Module_ReadWrite(Module);
        module.Instruments[CurrentInstrument].clear;
        module.Samples[CurrentInstrument].clear;
    tralalaEngine.Unlock_Module_ReadWrite;
}
    
    PatternEditor_allowCursor:= true;

    CurrentInstrument:= lastInstrument;

    s:= ExtractFileExt(param);

    if upcase(s) = '.WAV' then 
        if not loadWav(param) then begin
            theDialogMessageBox:= TtuiDialogMessageBox.Create(@theDialogMessageBox, theTUI, 'Can''t load File');
            exit;
        end;
    if upcase(s) = '.ITI' then 
        if not loadITI(param) then begin
            theDialogMessageBox:= TtuiDialogMessageBox.Create(@theDialogMessageBox, theTUI, 'Can''t load File');
            exit;
        end;

    reloadInstrumentSelector(false);

    isInPreviewSample:= false;

    lastInstrumentLoadSate:= theDialogLoadSample.curState;

end;
{$notes on}


procedure TInstrumentSelector.execProcCancelLoadSample(const param: string);
begin
    //CurrentInstrument:=lastInstrument;
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.Samples.Sample[CurrentInstrument].Assign(Module.Samples.Sample[129]); // <- what about instruments?
        module.Instruments[CurrentInstrument].name:= lastSampleName;
    tralalaEngine.Unlock_Module_ReadWrite;

    reloadInstrumentSelector(false);

    PatternEditor_allowCursor:= true;
    isInPreviewSample:=false;

end;


procedure TInstrumentSelector.execProcMenuSave(const param: string);
begin

    PatternEditor_allowCursor:= false;

    theTUI.CloseBox(InstrumentMenuVerticalBox);

    allowVirtualPiano:= false;

    theDialogSaveSample:=TtuiDialogSaveFile.Create(@theDialogSaveSample, theTUI);
    theDialogSaveSample.chosenFile:='mySample';
    theDialogSaveSample.addExtentionHint('Samples');
    theDialogSaveSample.addExtention('.wav');
    theDialogSaveSample.addExtentionHint('Instruments');
    theDialogSaveSample.addExtention('.iti');
    theDialogSaveSample.addExtentionHint('All Files');
    theDialogSaveSample.addExtention('.*');
    theDialogSaveSample.curState.curPath:=lastInstrumentSavePath;
    theDialogSaveSample.curState.Chosen:=lastInstrumentSaveLastChosen;
    theDialogSaveSample.curState.Scrolled:=lastInstrumentSaveScroll;
    theDialogSaveSample.curState.ScrollBarPosition:=lastInstrumentSaveScrollBarPosition;
    theDialogSaveSample.execute(@execProcSuccessSaveSample, @execProcCancelSaveSample);

end;


procedure TInstrumentSelector.SaveWAV(const name: string);
var
    Logger : TLogger = nil;    
    strm : TFileStream;

begin

    strm:= TFileStream.Create(name, fmCreate);

    Logger:= TSilentLogger.Create;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
        SaveSample(module.Samples[CurrentInstrument], strm, sffWAV, Logger);
    tralalaEngine.Unlock_ReadOnly;

    strm.Free;
    Logger.free;

end;


procedure TInstrumentSelector.SaveITI(const name: string);
var
    Logger : TLogger = nil;    
    strm : TFileStream;

begin

    strm:= TFileStream.Create(name, fmCreate);

    Logger:= TSilentLogger.Create;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
        SaveInstrument(module, CurrentInstrument, strm, iffITI, Logger);
    tralalaEngine.Unlock_ReadOnly;

    strm.Free;
    Logger.free;

end;


procedure TInstrumentSelector.execProcSuccessSaveSample(const param: string);
var 
    s : string;

begin

    if theDialogSaveSample.curHint = 'Samples' then begin
        if upcase(ExtractFileExt(param)) <> '.WAV' then s:=param + '.wav' else s:= param;
        SaveWAV(s);
    end;
    if theDialogSaveSample.curHint = 'Instruments' then begin
        if upcase(ExtractFileExt(param)) <> '.ITI' then s:=param + '.iti' else s:= param;
        SaveITI(s);
    end;

    lastInstrumentSavePath:= theDialogSaveSample.curState.curPath;
    lastInstrumentSaveLastChosen:= theDialogSaveSample.curState.Chosen;
    lastInstrumentSaveScroll:= theDialogSaveSample.curState.Scrolled;
    lastInstrumentSaveScrollBarPosition:= theDialogSaveSample.curState.ScrollBarPosition;

    allowVirtualPiano:= true;
    PatternEditor_allowCursor:= true;

end;


procedure TInstrumentSelector.execProcCancelSaveSample(const param: string);
begin

    allowVirtualPiano:= true;
    PatternEditor_allowCursor:= true;

end;


procedure TInstrumentSelector.execProcMenuEditor(const param: string);
begin

    theTUI.CloseBox(InstrumentMenuVerticalBox);

    justChanged:= true;
    CurrentMode:= modeInstrumentEditor;

end;


procedure TInstrumentSelector.ClickExecProc(const param: string);
var 
    s : string;

begin

    isInPreviewSample:= true;

    //CurrentInstrument:=InstrumentNumber4PlayingOnLoad;

    s:=ExtractFileExt(param);

    if upcase(s) = '.WAV' then loadWav(param);
    if upcase(s) = '.RAW' then loadWav(param);
    if upcase(s) = '.ITI' then loadITI(param);
end;


begin
end.