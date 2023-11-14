procedure TTracker.buildMainPanel;
var
    x : dword;

begin

    x:= 126 * 4 + 3;

    PatternEditor_AllowCursor:= true;

    ButtonPlaySong:= TtuiButton.create(MainPanel, 'Tracker_ButtonPlaySong', x + 1, 1, 100, 28, 'Play song', @ButtonPlaySongProc);
    ButtonPlaySong.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonPlaySong);

    ButtonPlayPattern:= TtuiButton.create(MainPanel, 'Tracker_ButtonPlayPattern', x + 1, 1 * 28 + 2, 100, 27, 'Play pattern', @ButtonPlayPatternProc);
    ButtonPlayPattern.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonPlayPattern);

    ButtonStop:= TtuiButton.create(MainPanel, 'Tracker_ButtonStop', x + 1, 2 * 28 + 3 - 1, 100, 26, 'Stop', @ButtonStopProc);   
    ButtonStop.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonStop);

    ButtonRecordSong:= TtuiButton.create(MainPanel, 'Tracker_ButtonRecordSong', x + 1, 3 * 28 + 1, 100, 28, 'Record Song', @ButtonRecordSongProc);  
    ButtonRecordSong.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRecordSong);

    ButtonRecordPattern:= TtuiButton.create(MainPanel, 'Tracker_ButtonRecordPattern', x + 1, 4 * 28 + 2, 100, 28, 'Record Pattern', @ButtonRecordPatternProc);
    ButtonRecordPattern.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRecordPattern);

    ButtonTranspose:= TtuiButton.create(MainPanel, 'Tracker_ButtonTranspose', x + 1, 5 * 28 + 3, 100, 28, 'Transpose', @ButtonTransposeProc);
    ButtonTranspose.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonTranspose);

    ButtonAdvancedEdit:= TtuiButton.create(MainPanel, 'Tracker_ButtonAdvancedEdit', x + 1, 6 * 28 + 4, 100, 28, 'Advanced Edit', @ButtonAdvancedEditProc);
    ButtonAdvancedEdit.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAdvancedEdit);


    ButtonExpand:= TtuiButton.create(MainPanel, 'Tracker_ButtonExpand', x - 88, 1, 88, 28, 'Expand', @ButtonExpandProc);
    ButtonExpand.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonExpand);

    ButtonShrink:= TtuiButton.create(MainPanel, 'Tracker_ButtonShrink', x - 88, 26 + 4, 88, 27, 'Shrink', @ButtonShrinkProc);
    ButtonShrink.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonShrink);

    CurrentNoteAdd:= 1;


    TextFieldRepeatStart:= TtuiTextField.create(MainPanel, 'TextField RepeatStart', 134, 3, 'Repeat Start  ' + numstr(0));
    TextFieldRepeatStart.theme:= LoadThemeTextField;
    TextFieldRepeatStart.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldRepeatStart);

    ButtonUPRepeatStart:= TtuiButtonUP.Create(MainPanel, 'RepeatStart ButtonUP', 126 * 2 + 2, 1, @execProcRepeatStartButtonUP);
    ButtonUPRepeatStart.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPRepeatStart);
    ButtonDOWNRepeatStart:= TtuiButtonDOWN.Create(MainPanel, 'RepeatStart ButtonDOWN', 126 * 2 + 16 + 1 + 4, 1, @execProcRepeatStartButtonDOWN);
    ButtonDOWNRepeatStart.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNRepeatStart);


    TextFieldSongChannels:= TtuiTextField.create(MainPanel, 'TextField SongChannels', 134, 16 + 4 + 2, 'Song Channels  ' + numstr(0));
    TextFieldSongChannels.theme:= LoadThemeTextField;
    TextFieldSongChannels.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldSongChannels);

    ButtonUPSongChannels:= TtuiButtonUP.Create(MainPanel, 'SongChannels ButtonUP', 126 * 2 + 2, 16 + 4, @execProcSongChannelsButtonUP);
    ButtonUPSongChannels.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPSongChannels);

    ButtonDOWNSongChannels:= TtuiButtonDOWN.Create(MainPanel, 'SongChannels ButtonDOWN', 126 * 2 + 16 + 1 + 4, 16 + 4, @execProcSongChannelsButtonDOWN);
    ButtonDOWNSongChannels.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNSongChannels);


	TextFieldPatternLength:= TtuiTextField.create(MainPanel, 'TextField PatternLength', 134, 32 + 9, 'Pattern Length  ' + numstr(0));
    TextFieldPatternLength.theme:= LoadThemeTextField;
	TextFieldPatternLength.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldPatternLength);

    ButtonUPPatternLength:= TtuiButtonUP.Create(MainPanel, 'PatternLength ButtonUP', 126 * 2 + 2, 32 + 7, @execProcPatternLengthButtonUP);
    ButtonUPPatternLength.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPPatternLength);

    ButtonDOWNPatternLength:= TtuiButtonDOWN.Create(MainPanel, 'PatternLength ButtonDOWN', 126 * 2 + 16 + 1 + 4, 32 + 7, @execProcPatternLengthButtonDOWN);
    ButtonDOWNPatternLength.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNPatternLength);


    TextFieldOctave:= TtuiTextField.create(MainPanel, 'TextField Octave', 134, 48 + 12, 'Octave  ' + numstr(CurrentOctave));
    TextFieldOctave.theme:= LoadThemeTextField;
    TextFieldOctave.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldOctave);

    ButtonUPOctave:= TtuiButtonUP.Create(MainPanel, 'Octave ButtonUP', 126 * 2 + 2, 48 + 10, @execProcOctaveButtonUP);
    ButtonUPOctave.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPOctave);

    ButtonDOWNOctave:= TtuiButtonDOWN.Create(MainPanel, 'Octave ButtonDOWN', 126 * 2 + 16 + 1 + 4, 48 + 10, @execProcOctaveButtonDOWN);
    ButtonDOWNOctave.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNOctave);


    TextFieldBPM:= TtuiTextField.create(MainPanel, 'TextField BPM', 294 + 3, 3, 'BPM  ' + numstr(0));
    TextFieldBPM.theme:= LoadThemeTextField;
    TextFieldBPM.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldBPM);

    ButtonUPBPM:= TtuiButtonUP.Create(MainPanel, 'BPM ButtonUP', 126 * 3 + 3, 1, @execProcBPMButtonUP);
    ButtonUPBPM.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPBPM);

    ButtonDOWNBPM:= TtuiButtonDOWN.Create(MainPanel, 'BPM ButtonDOWN', 126 * 3 + 16 + 1 + 3 + 2, 1, @execProcBPMButtonDOWN);
    ButtonDOWNBPM.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNBPM);

    TextFieldSpeed:= TtuiTextField.create(MainPanel, 'TextField Speed', 294 + 3, 16 + 4 + 2, 'Speed  ' + numstr(0));
    TextFieldSpeed.theme:= LoadThemeTextField;
    TextFieldSpeed.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldSpeed);

    ButtonUPSpeed:= TtuiButtonUP.Create(MainPanel, 'Speed ButtonUP', 126 * 3 + 3, 16 + 4, @execProcSpeedButtonUP);
    ButtonUPSpeed.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPSpeed);

    ButtonDOWNSpeed:= TtuiButtonDOWN.Create(MainPanel, 'Speed ButtonDOWN', 126 * 3 + 16 + 1 + 3 + 2, 16 + 4, @execProcSpeedButtonDOWN);
    ButtonDOWNSpeed.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNSpeed);


	TextFieldNoteAdd:= TtuiTextField.create(MainPanel, 'TextField NoteAdd', 294 + 3, 32 + 9, 'Note Add  ' + numstr(CurrentNoteAdd));
    TextFieldNoteAdd.theme:= LoadThemeTextField;
	TextFieldNoteAdd.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldNoteAdd);

    ButtonUPNoteAdd:= TtuiButtonUP.Create(MainPanel, 'NoteAdd ButtonUP', 126 * 3 + 3, 32 + 7, @execProcNoteAddButtonUP);
    ButtonUPNoteAdd.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonUPNoteAdd);
    
    ButtonDOWNNoteAdd:= TtuiButtonDOWN.Create(MainPanel, 'NoteAdd ButtonDOWN', 126 * 3 + 16 + 1 + 3 + 2, 32 + 7, @execProcNoteAddButtonDOWN);
    ButtonDOWNNoteAdd.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonDOWNNoteAdd);

    TextFieldSongName:= TtuiTextField.create(MainPanel, 'TextField Song Name', 888, 160, 'Song Name');
    TextFieldSongName.theme:= LoadThemeTextField;
    TextFieldSongName.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldSongName);


    BuildRightSide;
    BuildTranspose;
    BuildAdvancedEdit;
    BuildBlockButtons;

end;


procedure TTracker.doButtonTranspose;
begin

    EnableDisableTranspose(false);
    EnableDisableAdvancedEdit(false);
    EnableDisableRightSide(false);

    AdvancedEditEnabled:= false;
    TransposeEnabled:= not TransposeEnabled;
    EnableDisableTranspose(TransposeEnabled);

    if blockButtonsEnabled then enableBlockButtons(false);
    
    if (not TransposeEnabled) and (not AdvancedEditEnabled) then begin
        EnableDisableRightSide(true);
        enableBlockButtons(true);
    end;

end;

procedure TTracker.ButtonTransposeProc(const param: string);
begin

    doButtonTranspose;
    netSendButtonTranspose;

end;


procedure TTracker.doButtonAdvancedEdit;
begin
    EnableDisableTranspose(false);
    EnableDisableAdvancedEdit(false);
    EnableDisableRightSide(false);

    TransposeEnabled:= false;
    AdvancedEditEnabled:= not AdvancedEditEnabled;
    EnableDisableAdvancedEdit(AdvancedEditEnabled);

    if blockButtonsEnabled then enableBlockButtons(false);

    if (not TransposeEnabled) and (not AdvancedEditEnabled) then begin
        EnableDisableRightSide(true);
        enableBlockButtons(true);
    end;
end;


procedure TTracker.ButtonAdvancedEditProc(const param: string);
begin

    doButtonAdvancedEdit;
    
    netSendButtonAdvancedEdit;

end;


procedure TTracker.doPlaySong;
begin
    
    tralalaEngine.PlaySongFromOrder(CurrentOrder);

    playPatternOnly:= false;
    TrackerInEditMode:= false;
     
end;

procedure TTracker.ButtonPlaySongProc(const param: string);
begin

    doPlaySong;

    netSendButtonPlaySong;

end;


procedure TTracker.doPlayPattern;
begin

    tralalaEngine.PlaySongFromOrder(CurrentOrder);
    oldOrder:= CurrentOrder;
    playPatternOnly:= true;

    TrackerInEditMode:= false;

end;

procedure TTracker.ButtonPlayPatternProc(const param: string);
begin

    doPlayPattern;

    netSendButtonPlayPattern;

end;


procedure TTracker.doStopSong;
begin
    
    tralalaEngine.StopPlaying;
    playPatternOnly:= false;

end;

procedure TTracker.ButtonStopProc(const param: string);
begin

    doStopSong;

    netSendButtonStopSong;

end;


procedure TTracker.doRecordSong;
begin
    
    aDialog:= TtuiDialogMessageBox.Create(@aDialog, TrackerTUI, 'Not implmented jet');

end;

procedure TTracker.ButtonRecordSongProc(const param: string);
begin

    doRecordSong;

    netSendButtonRecordSong;
end;


procedure TTracker.doRecordPattern;
begin

    aDialog:= TtuiDialogMessageBox.Create(@aDialog, TrackerTUI, 'Not implmented jet');

end;


procedure TTracker.ButtonRecordPatternProc(const param: string);
begin

    doRecordPattern;
    netSendButtonRecordPattern;
    
end;


procedure TTracker.reloadMainPanel;
begin

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		EditFieldSongName.reloadText(Module.SongName);		
		TextFieldBPM.caption:= 'BPM  ' + numstr(Module.InitialBPM);
		TextFieldSpeed.caption:= 'Speed  ' + numstr(Module.InitialSpeed);
        TextFieldCurrentBPM.caption:= 'Current BPM  ' + numstr(Module.InitialBPM);
        TextFieldCurrentSpeed.caption:= 'Current Speed  ' + numstr(Module.InitialSpeed);
		TextFieldSongChannels.caption:= 'Song Channels  ' + numstr(Module.NumberOfChannels);
		TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);
		TextFieldGlobalVolume.caption:= 'Global Volume  ' + numstr(Module.GlobalVolume);
        TextFieldRepeatStart.caption:= 'Repeat Start  ' + numstr(Module.Order.RestartPosition);

	tralalaEngine.Unlock_ReadOnly;

end;


procedure TTracker.execProcSongName(const param: string);
begin	

	allowVirtualPiano:= false;
    PatternEditor_AllowCursor:= false;

	tralalaEngine.Lock_Module_ReadWrite(Module);
		Module.SongName:= EditFieldSongName.theText;
	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSongNameLoseFocus(const param: string);
begin   

        PatternEditor_AllowCursor:= true;
        allowVirtualPiano:= true;
        keyboard[KEY_RETURN]:= false;
        writeln('losefocus');

end;


procedure TTracker.execProcBPMButtonUP(const param: string);
var 
    i : longint;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

        i:= Module.InitialBPM;
		inc(i);
        if i >= 255 then i:= 255;
        Module.InitialBPM:= i;

		TextFieldBPM.caption:= 'BPM  ' + numstr(Module.InitialBPM);

        netSendButtonUPBPM(Module.InitialBPM);        

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcBPMButtonDOWN(const param: string);
var 
    i : longint;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        i:= Module.InitialBPM;
        dec(i);
        if i <= 31 then i:= 31;
        Module.InitialBPM:= i;

        TextFieldBPM.caption:= 'BPM  ' + numstr(Module.InitialBPM);        
        
        netSendButtonDOWNBPM(Module.InitialBPM); 

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSpeedButtonUP(const param: string);
var 
    i : longint;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		i:= Module.InitialSpeed;
        inc(i);
        if i >= 255 then i:= 255;        
        Module.InitialSpeed:= i;

		TextFieldSpeed.caption:= 'Speed  ' + numstr(Module.InitialSpeed);

        netSendButtonUPSpeed(Module.InitialSpeed);

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSpeedButtonDOWN(const param: string);
var 
    i : longint;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		i:= Module.InitialSpeed;
        dec(i);
        if i <= 1 then i:= 1;
        Module.InitialSpeed:= i;

		TextFieldSpeed.caption:= 'Speed  ' + numstr(Module.InitialSpeed);
        
        netSendButtonDOWNSpeed(Module.InitialSpeed);

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcPatternLengthButtonUP(const param: string);
var 
    i : longint;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
	   
       i:= Module.Patterns[CurrentPattern].RowsCount;
       inc(i);
       if i >= 255 then i:= 255;
       Module.Patterns[CurrentPattern].RowsCount:= i;

	   TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);
       
       netSendButtonUPLength(Module.Patterns[CurrentPattern].RowsCount);

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcPatternLengthButtonDOWN(const param: string);
var 
    i : longint;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
	    
       i:= Module.Patterns[CurrentPattern].RowsCount;
       dec(i);
       if i <= 1 then i:= 1;
       Module.Patterns[CurrentPattern].RowsCount:= i;
       
	   TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);
       if currentRow >= Module.Patterns[CurrentPattern].RowsCount then currentRow:= Module.Patterns[CurrentPattern].RowsCount - 1;
	   
       netSendButtonDOWNLength(Module.Patterns[CurrentPattern].RowsCount);

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSongChannelsButtonUP(const param: string);
var 
    i : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        i:= Module.NumberOfChannels;
        inc(i);
        if i >= 64 then i:= 64;
        Module.NumberOfChannels:= i;

        netSendButtonUPChannels(Module.NumberOfChannels);

    tralalaEngine.Unlock_Module_ReadWrite;

    Tracker.reload(false);

end;


procedure TTracker.execProcSongChannelsButtonDown(const param: string);
var 
    i : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        i:= Module.NumberOfChannels;
        dec(i);
        if i <= 4 then i:= 4;
        Module.NumberOfChannels:= i;

        netSendButtonDOWNChannels(Module.NumberOfChannels);

    tralalaEngine.Unlock_Module_ReadWrite;

    Tracker.reload(false);

end;


procedure TTracker.execProcNoteAddButtonUP(const param: string);
begin

	inc(CurrentNoteAdd);
	if CurrentNoteAdd >= 16 then CurrentNoteAdd:= 16;

	TextFieldNoteAdd.caption:='Note Add  ' + numstr(CurrentNoteAdd);

    netSendButtonUPAdd(CurrentNoteAdd);

end;


procedure TTracker.execProcNoteAddButtonDOWN(const param: string);
begin

	dec(CurrentNoteAdd);
	if CurrentNoteAdd <= 0 then CurrentNoteAdd:= 0;

	TextFieldNoteAdd.caption:='Note Add  ' + numstr(CurrentNoteAdd);

    netSendButtonDOWNAdd(CurrentNoteAdd);

end; 


procedure TTracker.execProcOctaveButtonUP(const param: string);
begin
    
    inc(CurrentOctave);
    if CurrentOctave > 8 then CurrentOctave:= 8;

    TextFieldOctave.caption:='Octave  ' + numstr(CurrentOctave);

    netSendButtonUPOctave(CurrentOctave);

end;


procedure TTracker.execProcOctaveButtonDOWN(const param: string);
begin

    dec(CurrentOctave);
    if CurrentOctave < 0 then CurrentOctave:= 0;

    TextFieldOctave.caption:='Octave  ' + numstr(CurrentOctave);

    netSendButtonDOWNOctave(CurrentOctave);

end;


procedure TTracker.execProcRepeatStartButtonUP(const param: string);
var 
    i : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        i:= Module.Order.RestartPosition;
        inc(i);
        if i >= Module.Order.LastOrder then i:= Module.Order.LastOrder;
        Module.Order.RestartPosition:= i;

        TextFieldRepeatStart.caption:= 'Repeat Start  ' + numstr(Module.Order.RestartPosition);

        netSendButtonUPRepeatStart(Module.Order.RestartPosition);

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcRepeatStartButtonDOWN(const param: string);
var 
    i : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        i:= Module.Order.RestartPosition;
        dec(i);
        if i <= 0 then i:= 0;
        Module.Order.RestartPosition:= i;

        TextFieldRepeatStart.caption:= 'Repeat Start  ' + numstr(Module.Order.RestartPosition);

        netSendButtonDOWNRepeatStart(Module.Order.RestartPosition);

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.ButtonExpandProc(const param: string);
var 
    i, j, chn : longint;
    a : array of TNote;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

    if isInSelection then begin

            setlength(a, Module.Patterns[CurrentPattern].RowsCount);
            for chn:= slotX1 to slotX2 do begin
                
                for i:= slotY1 to (slotY2 + 1) do begin
                    if i < Module.Patterns[CurrentPattern].RowsCount then a[i]:= Module.Patterns[CurrentPattern][i, chn];
                end;

                for i:= slotY1 to (slotY2 + 1) do begin
                    if i < Module.Patterns[CurrentPattern].RowsCount then Module.Patterns[CurrentPattern][i, chn]:= EmptyNote;
                end;

                Module.Patterns[CurrentPattern][slotY1, chn]:= a[slotY1];
                i:= slotY1;
                j:= slotY1;
         
                repeat
                    Module.Patterns[CurrentPattern][i, chn]:= a[j];

                    inc(i, 2);
                    inc(j);
                until i >= (slotY2 + 1);

            end;

        end;


        if not isInSelection then begin
            
            setlength(a, Module.Patterns[CurrentPattern].RowsCount);
            for chn:= 1 to Module.NumberOfChannels do begin
                
                for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
                    a[i]:= Module.Patterns[CurrentPattern][i, chn];
                end;

                for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
                    Module.Patterns[CurrentPattern][i, chn]:= EmptyNote;
                end;

                Module.Patterns[CurrentPattern][0, chn]:= a[0];
                i:= 0;
                j:= 0;
         
                repeat
                    Module.Patterns[CurrentPattern][i, chn]:= a[j];

                    inc(i, 2);
                    inc(j);
                until i >= (Module.Patterns[CurrentPattern].RowsCount - 1);

            end;


        end;

    tralalaEngine.Unlock_Module_ReadWrite;


    netSendButtonExpand;

end;


procedure TTracker.ButtonShrinkProc(const param: string);
var 
    i, j, chn : longint;
    a : array of TNote;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if isInSelection then begin

            setlength(a, Module.Patterns[CurrentPattern].RowsCount);
            for chn:= slotX1 to slotX2 do begin
                
                for i:= slotY1 to (slotY2 + 1) do begin
                    if i < Module.Patterns[CurrentPattern].RowsCount then a[i]:= Module.Patterns[CurrentPattern][i, chn];
                end;

                for i:= slotY1 to (slotY2 + 1) do begin
                    if i < Module.Patterns[CurrentPattern].RowsCount then Module.Patterns[CurrentPattern][i, chn]:= EmptyNote;
                end;

                Module.Patterns[CurrentPattern][slotY1, chn]:= a[slotY1];
                i:= slotY1;
                j:= slotY1;
         
                repeat
                    Module.Patterns[CurrentPattern][i, chn]:= a[j];

                    inc(i);
                    inc(j, 2);
                until j >= (slotY2 + 1);

            end;

        end;


        if not isInSelection then begin
            
            setlength(a, Module.Patterns[CurrentPattern].RowsCount);
            for chn:= 1 to Module.NumberOfChannels do begin
                
                for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
                    a[i]:= Module.Patterns[CurrentPattern][i, chn];
                end;

                for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
                    Module.Patterns[CurrentPattern][i, chn]:= EmptyNote;
                end;

                Module.Patterns[CurrentPattern][0, chn]:= a[0];
                i:= 0;
                j:= 0;
         
                repeat
                    Module.Patterns[CurrentPattern][i, chn]:= a[j];

                    inc(i);
                    inc(j, 2);
                until j >= (Module.Patterns[CurrentPattern].RowsCount - 1);

            end;


        end;

    tralalaEngine.Unlock_Module_ReadWrite;


    netSendButtonShrink;

end;


procedure TTracker.BuildRightSide;
begin

    EditFieldSongName:= TtuiEditField.create(MainPanel, 'EditField SongName', 811, 180, 226, '', @execProcSongName);
    EditFieldSongName.theme:= LoadThemeEditField;
    EditFieldSongName.EditUpdateExecProc:= @execProcSongName;
    EditFieldSongName.LoseFocusExecProc:= @execProcSongNameLoseFocus;
    EditFieldSongName.EnterExecProc:= @execProcSongNameLoseFocus;
    MainPanel.addItem(EditFieldSongName);


    TextFieldSongTime:= TtuiTextField.create(MainPanel, 'TextField SongTime', 616, 1 + 6, 'Current Song Time  ' + numstr(0));
    TextFieldSongTime.theme:= LoadThemeTextField;
    TextFieldSongTime.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldSongTime);

    TextFieldGlobalVolume:= TtuiTextField.create(MainPanel, 'TextField GlobalVolume', 616, 16 + 4 + 2 + 6, 'Global Volume  ' + numstr(0));
    TextFieldGlobalVolume.theme:= LoadThemeTextField;
    TextFieldGlobalVolume.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldGlobalVolume);

    TextFieldCurrentBPM:= TtuiTextField.create(MainPanel, 'TextField CurrentBPM', 616, 32 + 9 + 1 + 6, 'Current BPM  ' + numstr(0));
    TextFieldCurrentBPM.theme:= LoadThemeTextField;
    TextFieldCurrentBPM.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldCurrentBPM);

    TextFieldCurrentSpeed:= TtuiTextField.create(MainPanel, 'TextField CurrentSpeed', 616, 48 + 12 + 2 + 6, 'Current Speed  ' + numstr(0));
    TextFieldCurrentSpeed.theme:= LoadThemeTextField;
    TextFieldCurrentSpeed.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldCurrentSpeed);

    TextFieldCurrentVirtualPinoKeyStroke:= TtuiTextField.create(MainPanel, 'TextField CurrentVirtualPinoKeyStroke', 616, 48 + 30 + 4 + 6, 'Key Stroke  ');
    TextFieldCurrentVirtualPinoKeyStroke.theme:= LoadThemeTextField;
    TextFieldCurrentVirtualPinoKeyStroke.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldCurrentVirtualPinoKeyStroke);

end;


procedure TTracker.EnableDisableRightSide(enable: boolean);
begin

    TextFieldSongTime.enabled:= enable;
    TextFieldGlobalVolume.enabled:= enable;
    TextFieldCurrentBPM.enabled:= enable;
    TextFieldCurrentSpeed.enabled:= enable;
    TextFieldCurrentVirtualPinoKeyStroke.enabled:= enable;
    TextFieldSongName.enabled:= enable;
    EditFieldSongName.enabled:= enable;

end;


procedure TTracker.buildScrollbar;
begin

    ScrollBarBox:= TtuiBox.create(TrackerTUI, 0, 720 - 16, 1280, 18, 'MainScrollBar', tuiBoxStatic);
    ScrollBarBox.ThemeBox:= LoadThemeBox;
    ScrollBarBox.ThemeBox.BackgroundColor:= Theme_Tracker_MainPanel_BackgroundColor;
    TrackerTUI.addBox(ScrollBarBox);

    mainScrollBar:= TtuiScrollBarHorizontal.Create(ScrollBarBox, 'Tracker_MainScrollBar', 0, 0, 1280, 18, @execProcMainScrollBar);
    mainScrollBar.theme:= LoadThemeScrollbarHorizontal;
    ScrollBarBox.addItem(mainScrollBar);

end;


procedure TTracker.execProcMainScrollBar(const param: string);
begin
    netSendTrackerScrollBar(strnum(param));
end;

procedure TTracker.reloadScrollbar;
var
    aValue : dword;

begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if Module.NumberOFChannels > 11 then begin
            aValue:= Module.NumberOFChannels - 11;
            if aValue <= 1 then aValue:= 1;
        end else
            aValue:= 0;

        aValue:= aValue * 64;

    tralalaEngine.Unlock_ReadOnly;

    mainScrollBar.resetMaxValue(aValue);

end;


procedure TTracker.buildVUMeters;
begin

    allocImage(vuMetersImage, 6 + 6, 198);
    vuMeters:= TtuiImage.Create(MainPanel, 'VUMeters', 1280 - 222 - 10 - 6, 3, vuMetersImage, nil);
    MainPanel.addItem(vuMeters);

end;


procedure TTracker.updateVUMeters;
const
    MaxHeightInPixels = 196;
    m = (0.1 * MaxHeightInPixels / 6) * (20 / ln(10));
    LeftX = 0;
    RightX = 3 + 3;

begin

    fastfill(vuMetersImage.data, vuMetersImage.width * vuMetersImage.height, Theme_Tracker_MainPanel_BackgroundColor);

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        if PlayerState.ModuleTickPosition.PlayMode <> TPlayMode.pmStopped then begin
            MetersValue:= PlayerState.VUMeterStereo(FramesSinceLastTick);
           
                if MetersValue.left > 0 then
                    VUbar(LeftX,Round(MaxHeightInPixels + m * ln(MetersValue.left / 128)))
                else
                    VUbar(LeftX, 0);
                if MetersValue.right > 0 then
                    VUbar(RightX, Round(MaxHeightInPixels + m * ln(MetersValue.right / 128)))
                else
                    VUbar(RightX, 0);
           
        end;

    tralalaEngine.Unlock_ReadOnly;

end;


procedure TTracker.VUbar(x: dword; height: integer);
var 
    i : dword;
    r, g, b : byte;

begin

    i:= 0;
    r:= 0;
    g:= 0;
    b:= 0;

    if height >= 196 then height:= 196;

    repeat
        r:= byte(256 + i);
        g:= byte(256 - i);
        r:= r div Theme_Tracker_UVMeters_fadeout;
        g:= g div Theme_Tracker_UVMeters_fadeout;


        putpixel(vuMetersImage, x + 0, vuMetersImage.height - i - 1, RGBA(r, g, b, $ff));
        putpixel(vuMetersImage, x + 1, vuMetersImage.height - i - 1, RGBA(r, g, b, $ff));
        putpixel(vuMetersImage, x + 2, vuMetersImage.height - i - 1, RGBA(r, g, b, $ff));
        putpixel(vuMetersImage, x + 3, vuMetersImage.height - i - 1, RGBA(r, g, b, $ff));

        inc(i);

    until i >= height;

end;