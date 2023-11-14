procedure TTracker.reloadPatternEditor(const param: string);
begin
	
	currentChannelMode:= cursorMode.note;
	currentChannel:= 1;
	currentRow:= 0;
	TrackerInEditMode:= false;
    CurrentInstrument:= 1;    
    CurrentFreeChannel:= 1;	// PAY ATTENTION ON THIS !!!!
	mainScrollBar.setCurValue(0);
	AllowVirtualPiano:= true;

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
		CurrentPattern:= Module.Order[currentOrder];
	tralalaEngine.Unlock_ReadOnly;

	MIDINote:= -1;

end;


function TTracker.isInPatternEditor: boolean;
begin

	result:= false;
	if ((mouseY > 232) and (mouseY < 704)) or ((Mouse2Y > 232) and (mouse2Y < 704)) then result:= true;

end;


function TTracker.is1InPatternEditor: boolean;
begin

	result:= false;
	if (mouseY > 232) and (mouseY < 704) then result:= true;

end;


function TTracker.is2InPatternEditor: boolean;
begin

	result:= false;
	if (Mouse2Y > 232) and (mouse2Y < 704) then result:= true;

end;


procedure TTracker.PatternEditor;
var 
	t : longint;
	aRow : longint;

begin
	
	if (not TrackerInEditMode) and AllowVirtualPiano then begin
        VirtualPianoPlaySampleFromKeyboard;
    end;

    PrintKeyStroke;

	if (not TrackerTUI.drawOnly) and TrackerInEditMode and AllowVirtualPiano then begin
	        if isInPreviewSample then begin
                VirtualPianoPlaySampleFromKeyboard;
                PrintKeyStroke;    
                exit;
            end;
		updateTrackerInEditMode;
	end;

	if not TrackerTUI.drawOnly then
		processChannelNumberMenu;


	if (not TrackerTUI.drawonly) and PatternEditor_AllowCursor then HandleBlock;


  	CurrentOrder:= PatternSelector.PatternSelector.curStringNum;
  	PatternSelector.SetOrder(CurrentOrder);




	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
		
		if CurrentPattern <> -1 then begin
			TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);

			if PlayerState.ModuleTickPosition.PlayMode <> TPlayMode.pmStopped then begin
				currentPlaying:= true;
				currentRow:= PlayerState.CurrentRow;
				TextFieldCurrentBPM.caption:= 'Current BPM  ' + numstr(PlayerState.currentBPM);
				TextFieldCurrentSpeed.caption:= 'Current Speed  ' + numstr(PlayerState.currentSpeed);
			end else currentPlaying:= false;

			if (not TrackerTUI.drawonly) and PatternEditor_AllowCursor and (not inMenuItem) then moveCursor;


			aRow:= 0;
		  	repeat
	    	  	t:= aRow - CurrentRow;

	    	  	if (t >= -12) and (t <= 13) then
	    	  		drawBar(vscreen, 0, Theme_Tracker_TrackerBar_YPosition + t * 18 , 1278, Theme_Tracker_TrackerBar_YPosition + 18 + t * 18, Theme_Tracker_4Row_BackgroundColor);

	    	  	inc(aRow, 4);
		  	until aRow >= Module.Patterns[CurrentPattern].RowsCount;


		 	drawCursorBar;
		 	
			if selectedPattern = CurrentPattern then begin
				DrawBlock;
			end;

			drawCursor;

		 	DisplayPattern;
	 	end;

  	tralalaEngine.Unlock_ReadOnly;

end;


procedure TTracker.getStartEndChannel;
begin

	startChannel:= 1 + (mainScrollBar.curValue div 64);
  	if Module.NumberOFChannels > 10 then
  		endChannel:= startChannel + 10
  	else endChannel:= Module.NumberOFChannels;

end;


procedure TTracker.DisplayPattern;
var
	Channel : Integer;
  	aNote : TnoteValue;
  	aRow : Integer;
  	theRow : Integer;
  	y, i : longint;
  	aInstrument : Integer;
  	aVolume : TVolumeColumnEffect;
  	aEffectType : TEffectType;
  	aEffectParam : Integer;
  	s : String;    
  	color : dword;

begin

	if TrackerInEditMode then drawRectangle(vscreen, 0, 219, 1279, 719 - 16, $ffff0000);

	getStartEndChannel;

  	i:= -1;
	for Channel:= startChannel to endChannel do begin
			inc(i);
			if check4mouseClickChannelNumber <> Channel then
				ttfPrintStringXY(vscreen, PatternEditorFont, i*Theme_Tracker_DisplayPattern_ChannelWidth + 38, 216, RGBA(255, 255, 255, 255), numstr(Channel))
			else
				ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + 38, 216, Theme_Tracker_MainPanel_SelectFontColor, numstr(Channel));

			if Module.ChannelsConfig[Channel].enabled then color:= Theme_Tracker_TrackerBar_NoteColor else color:= Theme_Tracker_TrackerBar_NoteColor_DisabledChannel;

	    for aRow:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin

	          theRow:= aRow - CurrentRow;
	          
	          y:= theRow * 18 + Theme_Tracker_TrackerBar_YPosition;

	          if (y > 220) and (y < 690) then begin	

				aNote:= Module.Patterns[CurrentPattern].notes[aRow, Channel].note;
				aInstrument:= Module.Patterns[CurrentPattern].notes[aRow, Channel].instrument;
				aVolume:= Module.Patterns[CurrentPattern].notes[aRow, Channel].volume;
				aEffectType:= Module.Patterns[CurrentPattern].notes[aRow, Channel].EffectType;
				aEffectParam:= Module.Patterns[CurrentPattern].notes[aRow, Channel].EffectParam;


				ttfPrintStringXY(vscreen, PatternEditorFont, 6, y, RGBA(255, 255, 255, 255), numstr(aRow));


				if (aNote <> NoteNothing) and (aNote <> noteOff) then 
					ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset, y, color, NoteValueTo3Str(aNote)) 
				else if aNote = noteOff then
					drawRectangle(vscreen, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset, y + 9, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + 20, y + 9 + 4, color)
				else 
					ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset, y - 4, color, '........' );


				if (aInstrument <> 0) and (aNote <> noteOff) and (aNote <> noteCut) then begin
					s:= '';
					if aInstrument < 10 then s:= '0';
					s:= s + numstr(aInstrument);
					ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + 28, y, color, s);
				end;


				if aVolume.EffectType <> vcetNoEffect then begin
					ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + 46, y, color, Volume2String(aVolume))
				end else 
					ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + 46, y - 4, color, '....');


				ttfPrintStringXY(vscreen, PatternEditorFont, i * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + 64, y, color, Effect2Str(aEffectType, aEffectParam));

	          end;


	    end;

	end;

end;


procedure TTracker.processChannelNumberMenu;
begin

	if mouseR or mouse2R then begin
		selectedChannelNumberMenu:= check4mouseClickChannelNumber;
		if selectedChannelNumberMenu <> -1 then begin
			if ChannelMenuVerticalClicked then exit;
			ChannelMenuVerticalClicked:= true;
			if mouseR then ChannelMenuVerticalBox:= TtuiBox.create(TrackerTUI, mouseX, mouseY, 0, 0, 'box Vertical Menu Channel', tuiBoxStatic);
			if mouse2R then ChannelMenuVerticalBox:= TtuiBox.create(TrackerTUI, mouse2X, mouse2Y, 0, 0, 'box Vertical Menu Channel', tuiBoxStatic);
    		ChannelMenuVerticalBox.themeBox:= LoadThemeBox;
    		TrackerTUI.addBox(ChannelMenuVerticalBox);

    		ChannelMenuVertical:= TtuiMenuVertical.create(ChannelMenuVerticalBox, 'ChannelMenuVertical');
    		ChannelMenuVertical.addMenuVerticalItem('ChannelPanning', 'Channel Panning', @execProcChannelPanning);
    		ChannelMenuVertical.addMenuVerticalItem('PatternMixdown', 'Channel Mixdown Pattern', @execProcChannelMixdownPattern);
            ChannelMenuVertical.addMenuVerticalItem('ChannelMixdown', 'Channel Mixdown Channel', @execProcChannelMixdownChannel);
		    ChannelMenuVertical.Theme:= LoadThemeMenuVertical;
    		ChannelMenuVertical.Theme.drawBorder:= true;
    		ChannelMenuVertical.execProcOnClickInNirvana:= @execProcChannelNirvana;

    		ChannelMenuVerticalBox.addItem(ChannelMenuVertical);  
		end;
	end;

end;


function TTracker.check4mouseClickChannelNumber: longint;
var 
	i : dword;

begin

	result:= -1;

	if TrackerTUI.lockedItem <> -1 then exit;

	for i:= 1 to 11 do
		if ((mouseX >= (32 + (i - 1) * Theme_Tracker_DisplayPattern_ChannelWidth)) and (mouseX <= (32 + (i - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + 24)) and (mouseY >= 220) and (mouseY <= 240)) or ((mouse2X >= (32 + (i - 1) * Theme_Tracker_DisplayPattern_ChannelWidth)) and (mouse2X <= (32 + (i - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + 24)) and (mouse2Y >= 220) and (mouse2Y <= 240)) then begin
			result:= (startChannel - 1) + i;
		end; 

end;


procedure TTracker.execProcChannelPanning(const param: string);
var 
	value : longint;

begin

	ChannelMenuVerticalClicked:= false;
	TrackerTUI.CloseBox(ChannelMenuVerticalBox);


    ChannelPanningBox:= TtuiBox.create(TrackerTUI, TrackerTUI.screen.width div 2 - 100, TrackerTUI.screen.height div 2 - 100, 200, 128, 'box Panning', tuiBoxStd);
    ChannelPanningBox.themeBox:= LoadThemeBox;
    TrackerTUI.addBox(ChannelPanningBox);

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
        value:= Module.ChannelsConfig[selectedChannelNumberMenu].InitialPanning;
    tralalaEngine.Unlock_ReadOnly;

    TextFieldCannelPanning:= TtuiTextField.create(ChannelPanningBox, 'Tracker_TextFieldChannelPanning', 10, 18, 'Channel Panning ' + numstr(value - 128));
    TextFieldCannelPanning.theme:= LoadThemeTextField;
    TextFieldCannelPanning.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ChannelPanningBox.addItem(TextFieldCannelPanning);

    CannelPaningScrollBar:= TtuiScrollBarHorizontal.Create(ChannelPanningBox, 'Tracker_CannelPaningScrollBar', 10, 52, 200 - 20, 255, @execProcChannelPanningScrollBar);
    CannelPaningScrollBar.theme:= LoadThemeScrollbarHorizontal;
    CannelPaningScrollBar.setCurValue(value);
    ChannelPanningBox.addItem(CannelPaningScrollBar);

    ButtonChannelPanningOK:= TtuiButton.create(ChannelPanningBox, 'Tracker_ButtonChannelPanningOK', ChannelPanningBox.boxWidth div 2 - 50, 128 - 16 - 26, 100, 26, 'OK', @execProcChannelPanningOK);
    ButtonChannelPanningOK.theme:= LoadThemeButton;
    ChannelPanningBox.addItem(ButtonChannelPanningOK);

end;


procedure TTracker.execProcChannelPanningScrollBar(const param: string);
var 
	value : longint;

begin

    value:= strnum(param);

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.ChannelsConfig[selectedChannelNumberMenu].InitialPanning:= value;
    tralalaEngine.Unlock_Module_ReadWrite;

    TextFieldCannelPanning.caption:= 'Channel Panning ' + numstr(value - 128);

end;


procedure TTracker.execProcChannelPanningOK(const param: string);
begin

    TrackerTUI.CloseBox(ChannelPanningBox);

end;


procedure TTracker.execProcChannelMixdownPattern(const param: string);
begin

	ChannelMenuVerticalClicked:= false;
	TrackerTUI.CloseBox(ChannelMenuVerticalBox);
	MessageBoxDialog:= TtuiDialogMessageBox.Create(@aDialog, TrackerTUI, 'Not implmented jet');

end;


procedure TTracker.execProcChannelMixdownChannel(const param: string);
begin

    ChannelMenuVerticalClicked:= false;
    TrackerTUI.CloseBox(ChannelMenuVerticalBox);
    MessageBoxDialog:= TtuiDialogMessageBox.Create(@aDialog, TrackerTUI, 'Not implmented jet');

end;


procedure TTracker.execProcChannelNirvana(const param: string);
begin
	ChannelMenuVerticalClicked:= false;
end;


procedure TTracker.HandleMainKeys;
begin

    if keyboard[KEY_SPACE] and (not keySpacePressed) then begin

        keySpacePressed:= true;
        
        if not CurrentPlaying then TrackerInEditMode:= not TrackerInEditMode;
        if currentPlaying then tralalaEngine.StopPlaying;

        netSendCurrentEditMode;

    end;
    if not keyboard[KEY_SPACE] then keySpacePressed:=false;


    if keyboard[KEY_LCTRL] and keyboard[KEY_F9] and (not keyControlF9Pressed) then begin
    	keyControlF9Pressed:= true;
    	tralalaEngine.PlaySongFromOrder(CurrentOrder, $10);
        TrackerInEditMode:= false;
        playPatternOnly:= false;
    end;

    if keyboard[KEY_LCTRL] and keyboard[KEY_F10] and (not keyControlF10Pressed) then begin
    	keyControlF10Pressed:= true;
    	tralalaEngine.PlaySongFromOrder(CurrentOrder, $20);
        TrackerInEditMode:= false;
        playPatternOnly:= false;
    end;

    if keyboard[KEY_LCTRL] and keyboard[KEY_F11] and (not keyControlF11Pressed) then begin
    	keyControlF11Pressed:= true;
    	tralalaEngine.PlaySongFromOrder(CurrentOrder, $30);
        TrackerInEditMode:= false;
        playPatternOnly:= false;
    end;

    if keyboard[KEY_LCTRL] and keyboard[KEY_F12] and (not keyControlF12Pressed) then begin
    	keyControlF12Pressed:= true;
    	tralalaEngine.PlaySongFromOrder(CurrentOrder, $40);
        TrackerInEditMode:= false;
        playPatternOnly:= false;
    end;


    if keyboard[KEY_LCTRL] and (not keyControlPressed) then begin
        keyControlPressed:= true;
        playSong:= true;
    end;

    if not keyboard[KEY_LCTRL] and keyControlPressed and playSong then begin
    	tralalaEngine.PlaySongFromOrder(CurrentOrder);
        TrackerInEditMode:= false;
        keyControlPressed:= false;
        playPatternOnly:= false;
    end;

    if not keyboard[KEY_LCTRL] then begin
    	keyControlF9Pressed:= false;
    	keyControlF10Pressed:= false;
    	keyControlF11Pressed:= false;
		keyControlF12Pressed:= false;

    	keyControlPressed:= false;

    	keyUndoPressed:= false;
    	keyRedoPressed:= false;
    	
    	AllowVirtualPiano:= true;
    end;


    if keyboard[KEY_F9] then currentRow:= 0;
    if keyboard[KEY_F10] then currentRow:= 16;
    if keyboard[KEY_F11] then currentRow:= 32;
    if keyboard[KEY_F12] then currentRow:= 48;

    if (CurrentPattern > -1) and (currentRow > Module.Patterns[CurrentPattern].RowsCount) then currentRow:= Module.Patterns[CurrentPattern].RowsCount;


    if keyboard[KEY_F1] then begin CurrentOctave:= 0; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F2] then begin CurrentOctave:= 1; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F3] then begin CurrentOctave:= 2; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F4] then begin CurrentOctave:= 3; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F5] then begin CurrentOctave:= 4; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F6] then begin CurrentOctave:= 5; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;
    if keyboard[KEY_F7] then begin CurrentOctave:= 6; TextFieldOctave.caption:= 'Octave  ' + numstr(CurrentOctave); end;

    if keyboard[KEY_LCTRL] and keyboard[KEY_Z] and keyboard[KEY_LSHIFT] and (not keyRedoPressed) then begin
    	keyRedoPressed:= true;
    	playSong:= false;
    	keyUndoPressed:= true;
    	AllowVirtualPiano:= false;
    	Redo;
    end;

    if keyboard[KEY_LCTRL] and (not keyboard[KEY_Z]) and keyboard[KEY_LSHIFT] and (keyRedoPressed) then begin
    	keyRedoPressed:= false;
    	playSong:= false;
    	keyUndoPressed:= true;
    end;

    if keyboard[KEY_LCTRL] and keyboard[KEY_Z] and (not keyUndoPressed) then begin
    	keyUndoPressed:= true;
    	playSong:= false;
    	AllowVirtualPiano:= false;
    	Undo;
    end;

    if keyboard[KEY_LCTRL] and (not keyboard[KEY_Z]) and (keyUndoPressed) then begin
    	keyUndoPressed:= false;
    	playSong:= false;
    end;

end;


procedure TTracker.PrintKeyStroke;
var 
	i : longint;

begin
    TextFieldCurrentVirtualPinoKeyStroke.caption:= 'Key Stroke  ';
    for i:= 0 to maxKeys do
        if playingSample[i].isPlaying then TextFieldCurrentVirtualPinoKeyStroke.caption:= TextFieldCurrentVirtualPinoKeyStroke.caption + NoteValueTo3Str(i) + ' ';
end;



function TTracker.updateEditModeSpecialKeys: boolean;
var      
    note : TNote;
    i, ii : longint;
    notes : array of TNote;

begin

	if keyboard[KEY_DELETE] and keyboard[KEY_LSHIFT] then begin

		tralalaEngine.Lock_Module_ReadWrite(Module);

			note:= Module.Patterns[CurrentPattern][currentRow, currentChannel];

			collectNote(CurrentPattern, currentRow, currentChannel, note);
	      
	        note:= EmptyNote;

	        Module.Patterns[CurrentPattern][currentRow,currentChannel]:= note;
	        netSendSetNote(CurrentPattern,currentRow,currentChannel,note);

        tralalaEngine.Unlock_Module_ReadWrite;
        exit;

    end;


	if keyboard[KEY_DELETE] and keyboard[KEY_LALT] then begin
      	
      	tralalaEngine.Lock_Module_ReadWrite(Module);

	        Note:= Module.Patterns[CurrentPattern][currentRow, currentChannel];

	        collectNote(CurrentPattern, currentRow, currentChannel, note);
	        
	        note.EffectType:= etNoEffect;
	        note.EffectParam:= 0;

	        Module.Patterns[CurrentPattern][currentRow,currentChannel]:= note;
	        netSendSetNote(CurrentPattern, currentRow, currentChannel, note);

        tralalaEngine.Unlock_Module_ReadWrite;
        result:= true;
    end;                


    if keyboard[KEY_DELETE] then begin

    	tralalaEngine.Lock_Module_ReadWrite(Module);

	        Note:= Module.Patterns[CurrentPattern][currentRow, currentChannel];

	        if currentChannelMode = cursorMode.note then note:= EmptyNote;
	        if currentChannelMode = cursorMode.note then note:= EmptyNote;
	        if currentChannelMode = cursorMode.instrument1 then note.instrument:= 0;
	        if currentChannelMode = cursorMode.instrument2 then note.instrument:= 0;
	        if currentChannelMode = cursorMode.volume1 then begin note.Volume.EffectType:= vcetNoEffect; note.Volume.EffectParam:= 0; end;
	        if currentChannelMode = cursorMode.volume2 then begin note.Volume.EffectType:= vcetNoEffect; note.Volume.EffectParam:= 0; end;
	        if currentChannelMode = cursorMode.effect1 then begin note.EffectType:= etNoEffect; note.EffectParam:= 0; end;
	        if currentChannelMode = cursorMode.effect2 then begin note.EffectType:= etNoEffect; note.EffectParam:= 0; end;
	        if currentChannelMode = cursorMode.effect3 then begin note.EffectType:= etNoEffect; note.EffectParam:= 0; end;

			collectNote(CurrentPattern, currentRow, currentChannel, note);

	        Module.Patterns[CurrentPattern][currentRow, currentChannel]:= note;
	        netSendSetNote(CurrentPattern, currentRow, currentChannel, note);

	        CurrentRow:= CurrentRow + CurrentNoteAdd;
	        if currentRow >= Module.Patterns[CurrentPattern].RowsCount then currentRow:= 0;

        tralalaEngine.Unlock_Module_ReadWrite;
        result:= true;
    end;

    
    if keyboard[KEY_LSHIFT] and keyboard[KEY_BACKSPACE] then begin

    	tralalaEngine.Lock_Module_ReadWrite(Module);

	    	if CurrentRow > 0 then begin

	    		collectShiftBackspace(CurrentPattern, currentRow);

	        	for ii:= 1 to Module.NumberOFChannels do begin

	                    for i:= currentRow to Module.Patterns[CurrentPattern].RowsCount - 1 do begin

	                    	Module.Patterns[CurrentPattern][i - 1, ii]:= Module.Patterns[CurrentPattern][i, ii];
	                    	netSendSetNote(CurrentPattern, i - 1, ii, Module.Patterns[CurrentPattern][i, ii]);

	                    end;

	                    Module.Patterns[CurrentPattern][Module.Patterns[CurrentPattern].RowsCount - 1, ii]:= EmptyNote;
	                    netSendSetNote(CurrentPattern, Module.Patterns[CurrentPattern].RowsCount - 1, ii, EmptyNote);

	            end;

				CurrentRow:=CurrentRow - 1;


        	tralalaEngine.Unlock_Module_ReadWrite;
        	result:= true;
        end;

    end;


    if keyboard[KEY_BACKSPACE] then begin
    	
    	tralalaEngine.Lock_Module_ReadWrite(Module);

	        if CurrentRow > 0 then begin
	            
	            collectBackSpace(CurrentPattern, currentRow, currentChannel);
	            
	            for i:= currentRow to Module.Patterns[CurrentPattern].RowsCount - 1 do begin

	            	Module.Patterns[CurrentPattern][i - 1, currentChannel]:= Module.Patterns[CurrentPattern][i, currentChannel];
	            	netSendSetNote(CurrentPattern, i - 1, currentChannel, Module.Patterns[CurrentPattern][i, currentChannel]);

	            end;

	            Module.Patterns[CurrentPattern][Module.Patterns[CurrentPattern].RowsCount - 1, currentChannel]:= EmptyNote;
	            netSendSetNote(CurrentPattern, Module.Patterns[CurrentPattern].RowsCount - 1, currentChannel, EmptyNote);

	            CurrentRow:=CurrentRow - 1;
	        end;

        tralalaEngine.Unlock_Module_ReadWrite;
        result:= true;

    end;

	if keyboard[KEY_LSHIFT] and keyboard[KEY_INSERT] then begin
        
    	tralalaEngine.Lock_Module_ReadWrite(Module);    

	        collectShiftInsert(CurrentPattern, currentRow);

	        for ii:= 1 to Module.NumberOFChannels do begin

	            setlength(notes, Module.Patterns[CurrentPattern].RowsCount - CurrentRow - 1);

	            for i:= 0 to length(notes) - 1 do notes[i]:= Module.Patterns[CurrentPattern][i + CurrentRow, ii];

	            for i:=currentRow to currentRow + length(notes) - 1 do begin

	            	Module.Patterns[CurrentPattern][i + 1, ii]:= notes[i - currentRow];
	            	netSendSetNote(CurrentPattern,i + 1, ii, notes[i - CurrentRow]);

	            end;
	            
	            Module.Patterns[CurrentPattern][CurrentRow, ii]:= EmptyNote;
	            netSendSetNote(CurrentPattern, currentRow, ii, EmptyNote);

	         end;

        tralalaEngine.Unlock_Module_ReadWrite;

        setlength(notes, 0);
        result:= true;
    end;


    if keyboard[KEY_INSERT] then begin
        
        tralalaEngine.Lock_Module_ReadWrite(Module);

		    collectInsert(CurrentPattern, currentRow, currentChannel);

		    setlength(notes, Module.Patterns[CurrentPattern].RowsCount - CurrentRow - 1);
		    for i:= 0 to length(notes) - 1 do notes[i]:= Module.Patterns[CurrentPattern][i + CurrentRow, currentChannel];

		    for i:= currentRow to currentRow+length(notes) - 1 do begin

		    	Module.Patterns[CurrentPattern][i + 1, currentChannel]:= notes[i - currentRow];
		    	netSendSetNote(CurrentPattern, i + 1, currentChannel, notes[i - CurrentRow]);

		    end;
		    
		    Module.Patterns[CurrentPattern][CurrentRow, currentChannel]:= EmptyNote;
		    netSendSetNote(CurrentPattern, currentRow, currentChannel, EmptyNote);

        tralalaEngine.Unlock_Module_ReadWrite;

        setlength(notes, 0);
        result:= true;
    end;

end;


procedure TTracker.updateEditModeNote(key: longint);
var
    note : TNote;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

        doadd:= false;
        note:= recordNote(key);
       
        collectNote(CurrentPattern, currentRow, currentChannel, note);

        Module.Patterns[CurrentPattern][currentRow, currentChannel]:= note;
        netSendSetNote(CurrentPattern, currentRow, currentChannel, note);

        if doAdd then begin
            CurrentRow:= CurrentRow + CurrentNoteAdd;
            if currentRow >= Module.Patterns[CurrentPattern].RowsCount then currentRow:= 0;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.updateTrackerInEditMode;
begin

	if (keyboard[KEY_DELETE] or keyboard[KEY_BACKSPACE] or keyboard[KEY_INSERT]) and ((GetTickCount64 - keyNoteOldTime) > Theme_Tracker_KeyNote_Timeout) then begin

		keyNoteOldTime:= GetTickCount64;

		if updateEditModeSpecialKeys then exit;

	end;


	if ((VirtualPianoGetNoteFromKeyboardPress <> -1) or (getNumberFromKeyboard <> -1)) and ((GetTickCount64 - keyNoteOldTime) > Theme_Tracker_KeyNote_Timeout) then begin

		keyNoteOldTime:= GetTickCount64;
		
		if MoreThanOneNotePlaying then begin
	
		end else begin
			lastNote:= VirtualPianoGetNoteFromKeyboardPress;
		end;

		updateEditModeNote(lastNote);
		
		virtualPianoPlayingNote:= true;

		if (currentChannelMode = cursorMode.note) then PianoPlaySample(VirtualPianoGetNoteFromKeyboardPress, VirtualKeyboard);

    end;

    if virtualPianoPlayingNote and ((GetTickCount64 - keyNoteOldTime) > Theme_Tracker_KeyNote_Timeout) then begin
	
		PianoStopAllSamples;

    	virtualPianoPlayingNote:= false;

    end;

	
	if (MIDICommand = MIDIKeyDown) and (not MIDIKeyPressed) then begin

		MIDIKeyPressed:= true;
		updateEditModeNote(MIDINote);

		currentMIDIkeyPlaing:= MIDINote;
    			
    end;

    if MIDICommand = MIDIKeyUp then begin

    	if MIDINote = currentMIDIkeyPlaing then begin
	    	if MIDIKeyPressed then PianoStopSample(MIDINote, VirtualKeyboard);
	    	MIDIKeyPressed:= false;

	    	currentMIDIkeyPlaing:=-1;
    	end;

    end;

end;


function TTracker.recordNote(key: longint): TNote;
begin

    result:= Module.Patterns[CurrentPattern][currentRow, currentChannel];
    
    if (currentChannelMode = cursorMode.note) and (key <> -1) then begin
        result.instrument:= CurrentInstrument;    
        result.note:= key;
        doAdd:= true;
    end;
    if currentChannelMode = cursorMode.instrument1 then result.instrument:= instrumentStroke1(result.instrument);
    if currentChannelMode = cursorMode.instrument2 then result.instrument:= instrumentStroke2(result.instrument);
    if currentChannelMode = cursorMode.volume1 then result.volume:= volumeStroke1(result.volume);
    if currentChannelMode = cursorMode.volume2 then result.volume:= volumeStroke2(result.volume);
    if currentChannelMode = cursorMode.effect1 then result.EffectType:= effectStroke1(result.EffectType);
    if currentChannelMode = cursorMode.effect2 then result.EffectParam:= effectStroke2(result.EffectParam);
    if currentChannelMode = cursorMode.effect3 then result.EffectParam:= effectStroke3(result.EffectParam);

end;


function TTracker.instrumentStroke1(ins: longint): longint;
var 
	s : string;
    i : Integer;

begin

    result:= ins;
    if getNumberFromKeyboard <> -1 then begin

        if (getNumberFromKeyboard < 10) then begin

            s:= numstr(result);
            if length(s) = 2 then i:=strnum(s[2]) else i:= result;

            if (getNumberFromKeyboard * 10 + i) <= 99 then begin
            	result:= getNumberFromKeyboard * 10 + i;
            	doAdd:= true;
            end;

        end;

    end;

end;


function TTracker.instrumentStroke2(ins : longint): longint;
var 
	i : longint;
    s : string;

begin

    result:= ins;
    if getNumberFromKeyboard <> -1 then begin
        if (getNumberFromKeyboard < 10) then begin

            s:= numstr(result);
            if length(s) = 2 then i:= strnum(s[1]) else i:= 0;
            if ((i * 10 + getNumberFromKeyboard) <= 99) then result:= i * 10 + getNumberFromKeyboard;

            doAdd:= true;
        end;
    end;

end;


function TTracker.volumeStroke1(vol: TVolumeColumnEffect): TVolumeColumnEffect;
var 
	s : string;
    i : Integer;

begin

    result:= vol;
    if keyboard[KEY_OEM_PLUS] then begin

        result.EffectType:= vcetVolumeSlideUp;
        s:= numstr(result.EffectParam);
        
        if length(s) = 2 then begin
            i:= strnum(s[2]);
            if i > 9 then i:= 0;
        end else i:= 0;

        if result.EffectParam > 15 then result.EffectParam:= i;

        doAdd:= true;
        exit;
    end;


    if keyboard[KEY_OEM_MINUS] then begin

        result.EffectType:= vcetVolumeSlideDown;
        s:= numstr(result.EffectParam);
        
        if length(s) = 2 then begin
            i:= strnum(s[2]);
            if i > 9 then i:= 0;
        end else i:= 0;      

        if result.EffectParam>15 then result.EffectParam:= i;

        doAdd:= true;
        exit;
    end;


    if getNumberFromKeyboard <> -1 then begin

        s:= numstr(result.EffectParam);
        if length(s) = 2 then i:= strnum(s[2]) else i:= result.EffectParam;


        if (getNumberFromKeyboard < 7) then begin
            
            if (getNumberFromKeyboard * 10 + i) < 65 then begin
                result.EffectParam:= getNumberFromKeyboard * 10 + i;
                result.EffectType:= vcetSetVolumeTo;
                doAdd:= true;
            end;

        end;


		if (getNumberFromKeyboard >= 10) and (getNumberFromKeyboard <= 17) then begin
			if getNumberFromKeyboard = 10 then result.EffectType:= vcetFineVolumeSlideUp;
			if getNumberFromKeyboard = 11 then result.EffectType:= vcetFineVolumeSlideDown;
			if getNumberFromKeyboard = 12 then result.EffectType:= vcetVolumeSlideUp;
			if getNumberFromKeyboard = 13 then result.EffectType:= vcetVolumeSlideDown;
			if getNumberFromKeyboard = 14 then result.EffectType:= vcetPitchSlideDown;
			if getNumberFromKeyboard = 15 then result.EffectType:= vcetPitchSlideUp;
			if getNumberFromKeyboard = 16 then result.EffectType:= vcetPortamentoToNoteIT;
			if getNumberFromKeyboard = 17 then result.EffectType:= vcetVibrato;
			if result.EffectParam > 9 then result.EffectParam:= strnum(s[2]);
			doAdd:= true;
		end;

    end;

end;


function TTracker.volumeStroke2(vol: TVolumeColumnEffect): TVolumeColumnEffect;
var 
	i : longint;
    s : string;

begin

    result:= vol;
    if getNumberFromKeyboard <> -1 then begin

        if (result.EffectType <> vcetVolumeSlideUp) and 
           (result.EffectType <> vcetVolumeSlideDown) and 
           (result.EffectType <> vcetFineVolumeSlideUp) and 
           (result.EffectType <> vcetFineVolumeSlideDown) and 
           (result.EffectType <> vcetPitchSlideUp) and 
           (result.EffectType <> vcetPitchSlideDown) and 
           (result.EffectType <> vcetPortamentoToNoteIT) and 
           (result.EffectType <> vcetVibrato) then begin
            
            if (getNumberFromKeyboard < 10) then begin
                s:= numstr(result.EffectParam);
                if length(s) = 2 then i:= strnum(s[1]) else i:= 0;

                if ((i * 10 + getNumberFromKeyboard) < 65) then begin
                    result.EffectType:= vcetSetVolumeTo;
                    result.EffectParam:= i * 10 + getNumberFromKeyboard;
                    doAdd:= true;
                end;
            end;

        end else begin
        	if getNumberFromKeyboard < 10 then begin
            	result.EffectParam:= getNumberFromKeyboard;
            	doAdd:= true;
            end;
        end;
    end;

end;


function TTracker.effectStroke1(eff: TEffectType): TEffectType;
begin

    result:= getEffectFromKeyboard;
    if (result = etNoEffect) and (keyboard[KEY_0]) then begin doAdd:= true; exit; end;
    if result = etNoEffect then begin result:= eff; exit; end;
    doAdd:= true;

end;


function TTracker.effectStroke2(eff: longint): longint;
var 
	s : string;
    i : Integer;

begin

    result:= eff;
    if getNumberFromKeyboard <> -1 then begin

            s:= bytehex(result);
            if length(s) = 2 then begin
                i:= hex2dec(s[2]);
                if i > 16 then i:= 0;
            end else i:= 0;

            if (getNumberFromKeyboard * 16 + i) < 256 then begin
            	result:= getNumberFromKeyboard * 16 + i;
            	doAdd:= true;
            end;

    end;

end;


function TTracker.effectStroke3(eff: longint): longint;
var 
	s : string;
    i : Integer;

begin

    result:= eff;
    if getNumberFromKeyboard <> -1 then begin
        
            s:= bytehex(result);
            if length(s) = 2 then begin
                i:= hex2dec(s[1]);
                if i > 16 then i:= 0;
            end else i:= 0;

            if (i * 16 + getNumberFromKeyboard) < 256 then begin
            	result:= i * 16 + getNumberFromKeyboard;
            	doAdd:= true;
            end;

    end;

end;


function TTracker.getEffectFromKeyboard: TEffectType;
begin
    result:= etNoEffect;
    if keyboard[KEY_0] then result:= etNoEffect;
    if keyboard[KEY_A] then result:= etSetSpeed;
    if keyboard[KEY_B] then result:= etJumpToOrder;
    if keyboard[KEY_C] then result:= etBreakToRow;
    if keyboard[KEY_D] then result:= etVolumeSlide;
    if keyboard[KEY_E] then result:= etPitchSlideDown;
    if keyboard[KEY_F] then result:= etPitchSlideUp;
    if keyboard[KEY_G] then result:= etPortamentoToNote;
    if keyboard[KEY_H] then result:= etVibrato;
    if keyboard[KEY_I] then result:= etTremor;
    if keyboard[KEY_J] then result:= etArpeggio;
    if keyboard[KEY_K] then result:= etVibratoAndVolumeSlide;
    if keyboard[KEY_L] then result:= etPortamentoToAndVolumeSlide;
    if keyboard[KEY_M] then result:= etSetChannelVolume;
    if keyboard[KEY_N] then result:= etSlideChannelVolume;
    if keyboard[KEY_O] then result:= etSetSampleOffset;
    if keyboard[KEY_P] then result:= etSlidePanning;
    if keyboard[KEY_Q] then result:= etRetrig;
    if keyboard[KEY_R] then result:= etTremolo;
    if keyboard[KEY_S] then result:= etSpecialCommand;
    if keyboard[KEY_T] then result:= etSetTempo;
    if keyboard[KEY_U] then result:= etFineVibrato;
    if keyboard[KEY_V] then result:= etSetGlobalVolume;
    if keyboard[KEY_W] then result:= etSlideGlobalVolume;
    if keyboard[KEY_X] then result:= etSetPanningPosition;
    if keyboard[KEY_Y] then result:= etPanbrello;
    if keyboard[KEY_Z] then result:= etMIDIMacros;
    if keyboard[KEY_1] then result:= etSetVolume;
    if keyboard[KEY_6] then result:= etSetEnvelopePosition;
    if keyboard[KEY_SPACE] then result:= etNOP;

end;


function TTracker.getNumberFromKeyboard: longint;
begin

    result:= -1;
    if keyboard[KEY_1] then result:= 1;
    if keyboard[KEY_2] then result:= 2;
    if keyboard[KEY_3] then result:= 3;
    if keyboard[KEY_4] then result:= 4;
    if keyboard[KEY_5] then result:= 5;
    if keyboard[KEY_6] then result:= 6;
    if keyboard[KEY_7] then result:= 7;
    if keyboard[KEY_8] then result:= 8;
    if keyboard[KEY_9] then result:= 9;
    if keyboard[KEY_0] then result:= 0;
    if keyboard[KEY_A] then result:= 10;
    if keyboard[KEY_B] then result:= 11;
    if keyboard[KEY_C] then result:= 12;
    if keyboard[KEY_D] then result:= 13;
    if keyboard[KEY_E] then result:= 14;
    if keyboard[KEY_F] then result:= 15;
    if keyboard[KEY_G] then result:= 16;
    if keyboard[KEY_H] then result:= 17;
end;


function TTracker.MoreThanOneNotePlaying: boolean;
var
	i : longint;
	num : longint;
begin

	result:= false;
    
    num:= 0;
    for i:= 0 to maxKeys do begin

        if playingSample[i].isPlaying then inc(num);

    end;

    if num > 0 then result:= true;

end;