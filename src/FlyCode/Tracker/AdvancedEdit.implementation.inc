procedure TTracker.BuildAdvancedEdit;
begin
	
	BuildInstrumentRemap;
	BuildMasking;

	EnableDisableAdvancedEdit(false);

end;


procedure TTracker.BuildInstrumentRemap;
var 
	x, y : longint;

begin

	x:= 20;
	y:= 10;

	InstrumentRemapOldNumer:= 1;
	InstrumentRemapNewNumer:= 1;


	TextFieldInstrumentRemap:= TtuiTextField.Create(MainPanel, 'TextField Instrument Remap', x + 616, y + 10, 'Instrument Remap:');
	TextFieldInstrumentRemap.theme:= LoadThemeTextField;
	TextFieldInstrumentRemap.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldInstrumentRemap);

	TextFieldInstrumentRemapOldNumber:= TtuiTextField.Create(MainPanel, 'TextField Instrument Remap OldNumber', x + 616, y + 37 - 2, 'Old Number  ' + numstr(InstrumentRemapOldNumer));
	TextFieldInstrumentRemapOldNumber.theme:= LoadThemeTextField;
	TextFieldInstrumentRemapOldNumber.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldInstrumentRemapOldNumber);

	TextFieldInstrumentRemapNewNumber:= TtuiTextField.Create(MainPanel, 'TextField Instrument Remap NewNumber', x + 616, y + 37 + 19 - 2, 'New Number  ' + numstr(InstrumentRemapNewNumer));
	TextFieldInstrumentRemapNewNumber.theme:= LoadThemeTextField;
	TextFieldInstrumentRemapNewNumber.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldInstrumentRemapNewNumber);

	ButtonInstrumentRemapOldNumberUP:= TtuiButtonUP.create(MainPanel, 'Tracker_ButtonInstrumentRemapOldNumberUP', x + 720, y + 36 - 2, @execProcButtonInstrumentRemapOldNumberUP);
	ButtonInstrumentRemapOldNumberUP.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonInstrumentRemapOldNumberUP);
    
    ButtonInstrumentRemapOldNumberDown:= TtuiButtonDown.create(MainPanel, 'Tracker_ButtonInstrumentRemapOldNumberDown', x + 737 + 2, y + 36 - 2, @execProcButtonInstrumentRemapOldNumberDown);
    ButtonInstrumentRemapOldNumberDown.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonInstrumentRemapOldNumberDown);

    ButtonInstrumentRemapNewNumberUP:= TtuiButtonUP.create(MainPanel, 'Tracker_ButtonInstrumentRemapNewNumberUP', x + 720, y + 37 + 18 - 2, @execProcButtonInstrumentRemapNewNumberUP);
    ButtonInstrumentRemapNewNumberUP.theme:= LoadThemeButtonUP;
    MainPanel.addItem(ButtonInstrumentRemapNewNumberUP);

    ButtonInstrumentRemapNewNumberDown:= TtuiButtonDown.create(MainPanel, 'Tracker_ButtonInstrumentRemapNewNumberDown', x + 737 + 2, y + 37 + 18 - 2, @execProcButtonInstrumentRemapNewNumberDown);
    ButtonInstrumentRemapNewNumberDown.theme:= LoadThemeButtonDOWN;
    MainPanel.addItem(ButtonInstrumentRemapNewNumberDown);

    ButtonRemapInstrumentTrack:= TtuiButton.create(MainPanel, 'Tracker_ButtonRemapInstrumentTrack', x + 616, y + 74 - 2, 70, 20, 'Track', @execProcButtonRemapInstrumentTrack);
    ButtonRemapInstrumentTrack.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRemapInstrumentTrack);

    ButtonRemapInstrumentPattern:= TtuiButton.create(MainPanel, 'Tracker_ButtonRemapInstrumentPattern', x + 616 + 71, y + 74 - 2, 70, 20, 'Pattern', @execProcButtonRemapInstrumentPattern);
    ButtonRemapInstrumentPattern.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRemapInstrumentPattern);

	ButtonRemapInstrumentSong:= TtuiButton.create(MainPanel, 'Tracker_ButtonRemapInstrumentSong', x + 616, y + 95 - 2, 70, 20, 'Song', @execProcButtonRemapInstrumentSong);
    ButtonRemapInstrumentSong.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRemapInstrumentSong);

    ButtonRemapInstrumentBlock:= TtuiButton.create(MainPanel, 'Tracker_ButtonRemapInstrumentBlock', x + 616 + 71, y + 95 - 2, 70, 20,'Block', @execProcButtonRemapInstrumentBlock);
    ButtonRemapInstrumentBlock.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonRemapInstrumentBlock);

end;


procedure TTracker.execProcButtonInstrumentRemapOldNumberUP(const param: string);
begin

	inc(InstrumentRemapOldNumer);
	TextFieldInstrumentRemapOldNumber.caption:= 'Old Number  ' + numstr(InstrumentRemapOldNumer);

end;


procedure TTracker.execProcButtonInstrumentRemapOldNumberDown(const param: string);
begin

	dec(InstrumentRemapOldNumer);
	if InstrumentRemapOldNumer <= 1 then InstrumentRemapOldNumer:= 1;
	TextFieldInstrumentRemapOldNumber.caption:= 'Old Number  ' + numstr(InstrumentRemapOldNumer);

end;


procedure TTracker.execProcButtonInstrumentRemapNewNumberUP(const param: string);
begin

	inc(InstrumentRemapNewNumer);
	TextFieldInstrumentRemapNewNumber.caption:= 'New Number  ' + numstr(InstrumentRemapNewNumer);

end;


procedure TTracker.execProcButtonInstrumentRemapNewNumberDown(const param: string);
begin

	dec(InstrumentRemapNewNumer);
	if InstrumentRemapNewNumer <= 1 then InstrumentRemapNewNumer:= 1;
	TextFieldInstrumentRemapNewNumber.caption:= 'New Number  ' + numstr(InstrumentRemapNewNumer);

end;


procedure TTracker.execProcButtonRemapInstrumentTrack(const param: string);
var 
	i : longint;
	note : TNote;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin

			note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];

			if note.note <> NoteNothing then
			if note.instrument = InstrumentRemapOldNumer then begin
				note.instrument:= InstrumentRemapNewNumer;
				Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
			end;
	
		end;

	tralalaEngine.Unlock_Module_ReadWrite;


	netSendButtonRemapInstrumentTrack;

end;


procedure TTracker.execProcButtonRemapInstrumentPattern(const param: string);
var 
	i, l : longint;
	note : TNote;

begin
	
	tralalaEngine.Lock_Module_ReadWrite(Module);

		for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
			for l:= 1 to Module.NumberOFChannels do begin

				note:= Module.Patterns[CurrentPattern].notes[i, l];
				if note.note <> NoteNothing then
				if note.instrument = InstrumentRemapOldNumer then begin
					note.instrument:= InstrumentRemapNewNumer;
					Module.Patterns[CurrentPattern].notes[i,l]:= note;
				end;

			end;
		end;

	tralalaEngine.Unlock_Module_ReadWrite;


	netSendButtonRemapInstrumentPattern;


end;


procedure TTracker.execProcButtonRemapInstrumentSong(const param: string);
var 
	i, l, k : longint;
	note : TNote;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		for k:= 0 to Module.Patterns.HighestNonEmptyPattern do
			for i:= 0 to Module.Patterns[k].RowsCount - 1 do
				for l:= 1 to Module.NumberOFChannels do begin

					note:= Module.Patterns[k].notes[i, l];

					if (note.note <> NoteNothing) and (note.instrument = InstrumentRemapOldNumer) then begin
						note.instrument:= InstrumentRemapNewNumer;
						Module.Patterns[k].notes[i, l]:= note;
					end;

				end;

	tralalaEngine.Unlock_Module_ReadWrite;


	netSendButtonRemapInstrumentSong;

end;


procedure TTracker.execProcButtonRemapInstrumentBlock(const param: string);
var 
	x, y : longint;
	note : Tnote;

begin
	
	netSendButtonRemapInstrumentBlock;

	if selectedPattern <> CurrentPattern then exit;
	if not isInSelection then exit;

	tralalaEngine.Lock_Module_ReadWrite(Module);

		for x:= 0 to blockWidth do
			for y:= 0 to blockHeight do begin

				note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];				
					if (note.note <> NoteNothing) and (note.instrument = InstrumentRemapOldNumer) then begin
						note.instrument:= InstrumentRemapNewNumer;
						Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:=note;
					end;

			end;

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.BuildMasking;
var 
	x, y : longint;	
begin

	x:= 20;
	y:= -16;

	CheckBoxMaskingEnable:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMaskingEnable', x + 792, y + 37 - 2, 120, 24, 'Masking Enbled', nil);
	CheckBoxMaskingEnable.theme:= LoadThemeCheckBox;
	CheckBoxMaskingEnable.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxMaskingEnable.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxMaskingEnable.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxMaskingEnable.isChecked:= true;
	MainPanel.addItem(CheckBoxMaskingEnable);

	TextFieldC:= TtuiTextField.Create(MainPanel, 'TextField Masking C', x + 920, y + 38, 'C');
	TextFieldC.theme:= LoadThemeTextField;
	TextFieldC.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldC);

	CheckBoxNoteC:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Note C', x + 910, y + 37 + 22, 20, 24, '', nil);
	CheckBoxNoteC.theme:= LoadThemeCheckBox;
	CheckBoxNoteC.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxNoteC.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxNoteC.isChecked:= true;
	MainPanel.addItem(CheckBoxNoteC);

	CheckBoxInstrumentNumberC:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Instrument Number C', x + 910, y + 37 + 22 + 20, 20, 24, '', nil);
	CheckBoxInstrumentNumberC.theme:= LoadThemeCheckBox;
	CheckBoxInstrumentNumberC.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxInstrumentNumberC.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxInstrumentNumberC.isChecked:= true;
	MainPanel.addItem(CheckBoxInstrumentNumberC);

	CheckBoxVolumeColumnC:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Volume Column C', x + 910, y + 37 + 22 + 20 + 20, 20, 24, '', nil);
	CheckBoxVolumeColumnC.theme:= LoadThemeCheckBox;
	CheckBoxVolumeColumnC.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxVolumeColumnC.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxVolumeColumnC.isChecked:= true;
	MainPanel.addItem(CheckBoxVolumeColumnC);

	CheckBoxEffectDigit1C:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Digit 1 C', x + 910, y + 37 + 22 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit1C.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit1C.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit1C.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxEffectDigit1C.isChecked:= true;
	MainPanel.addItem(CheckBoxEffectDigit1C);

	CheckBoxEffectDigit23C:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Digit 23 C', x + 910, y + 37 + 22 + 20 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit23C.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit23C.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit23C.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxEffectDigit23C.isChecked:= true;
	MainPanel.addItem(CheckBoxEffectDigit23C);


	TextFieldP:= TtuiTextField.Create(MainPanel, 'TextField Masking P', x + 946 - 4, y + 38, 'P');
	TextFieldP.theme:= LoadThemeTextField;
	TextFieldP.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldP);

	CheckBoxNoteP:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Note P', x + 936 - 4, y + 37 + 22, 20, 24, '', nil);
	CheckBoxNoteP.theme:= LoadThemeCheckBox;
	CheckBoxNoteP.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxNoteP.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxNoteP.isChecked:= true;
	MainPanel.addItem(CheckBoxNoteP);

	CheckBoxInstrumentNumberP:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Instrument Number P', x + 936 - 4, y + 37 + 22 + 20, 20, 24, '', nil);
	CheckBoxInstrumentNumberP.theme:= LoadThemeCheckBox;
	CheckBoxInstrumentNumberP.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxInstrumentNumberP.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxInstrumentNumberP.isChecked:= true;
	MainPanel.addItem(CheckBoxInstrumentNumberP);

	CheckBoxVolumeColumnP:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Volume Column P', x + 936 - 4, y + 37 + 22 + 20 + 20, 20, 24, '', nil);
	CheckBoxVolumeColumnP.theme:= LoadThemeCheckBox;
	CheckBoxVolumeColumnP.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxVolumeColumnP.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxVolumeColumnP.isChecked:= true;
	MainPanel.addItem(CheckBoxVolumeColumnP);

	CheckBoxEffectDigit1P:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Digit 1 P', x + 936 - 4, y + 37 + 22 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit1P.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit1P.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit1P.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxEffectDigit1P.isChecked:= true;
	MainPanel.addItem(CheckBoxEffectDigit1P);

	CheckBoxEffectDigit23P:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Digit 23 P', x + 936 - 4, y + 37 + 22 + 20 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit23P.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit23P.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit23P.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	CheckBoxEffectDigit23P.isChecked:= true;
	MainPanel.addItem(CheckBoxEffectDigit23P);



	TextFieldT:= TtuiTextField.Create(MainPanel, 'TextField Masking T', x + 970 - 6, y + 38, 'T');
	TextFieldT.theme:= LoadThemeTextField;
	TextFieldT.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldT);

	CheckBoxNoteT:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Note T', x + 960 - 6, y + 37 + 22, 20, 24, '', nil);
	CheckBoxNoteT.theme:= LoadThemeCheckBox;
	CheckBoxNoteT.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxNoteT.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	MainPanel.addItem(CheckBoxNoteT);

	CheckBoxInstrumentNumberT:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Instrument Number T', x + 960 - 6, y + 37 + 22 + 20, 20, 24, '', nil);
	CheckBoxInstrumentNumberT.theme:= LoadThemeCheckBox;
	CheckBoxInstrumentNumberT.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxInstrumentNumberT.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	MainPanel.addItem(CheckBoxInstrumentNumberT);

	CheckBoxVolumeColumnT:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Volume Column T', x + 960 - 6, y + 37 + 22 + 20 + 20, 20, 24, '', nil);
	CheckBoxVolumeColumnT.theme:= LoadThemeCheckBox;
	CheckBoxVolumeColumnT.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxVolumeColumnT.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	MainPanel.addItem(CheckBoxVolumeColumnT);

	CheckBoxEffectDigit1T:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Dight 1 T', x + 960 - 6, y + 37 + 22 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit1T.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit1T.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit1T.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	MainPanel.addItem(CheckBoxEffectDigit1T);

	CheckBoxEffectDigit23T:= TtuiCheckBox.Create(MainPanel, 'CheckBoxMasking Effect Dight 23 T', x + 960 - 6, y + 37 + 22 + 20 + 20 + 20 + 20, 20, 24, '', nil);
	CheckBoxEffectDigit23T.theme:= LoadThemeCheckBox;
	CheckBoxEffectDigit23T.theme.CheckBoxColor:= Theme_Tracker_MainPanel_FontColor;
	CheckBoxEffectDigit23T.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
	MainPanel.addItem(CheckBoxEffectDigit23T);



	TextFieldNote:= TtuiTextField.Create(MainPanel, 'TextField Masking Note', x + 880, y + 37 + 25, 'Note');
	TextFieldNote.theme:= LoadThemeTextField;
	TextFieldNote.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldNote);

	TextFieldInstrumentNumber:= TtuiTextField.Create(MainPanel, 'TextField Masking Instrument', x + 801, y + 82, 'Instrument Number');
	TextFieldInstrumentNumber.theme:= LoadThemeTextField;
	TextFieldInstrumentNumber.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldInstrumentNumber);

	TextFieldVolumeColumn:= TtuiTextField.Create(MainPanel, 'TextField Masking Volume Column', x + 820, y + 81 + 19 + 1, 'Volume Column');
	TextFieldVolumeColumn.theme:= LoadThemeTextField;
	TextFieldVolumeColumn.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldVolumeColumn);

	TextFieldEffectDigit1:= TtuiTextField.Create(MainPanel, 'TextField Masking Effect Digit 1', x + 836, y + 81 + 19 + 1 + 19 + 1, 'Effect Digit 1');
	TextFieldEffectDigit1.theme:= LoadThemeTextField;
	TextFieldEffectDigit1.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldEffectDigit1);
	
	TextFieldEffectDigit23:= TtuiTextField.Create(MainPanel, 'TextField Masking Effect Digit 23', x + 827, y + 81 + 19 + 1 + 19 + 1 + 19 + 1, 'Effect Digit 2,3');
	TextFieldEffectDigit23.theme:= LoadThemeTextField;
	TextFieldEffectDigit23.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldEffectDigit23);
	
end;



procedure TTracker.EnableDisableAdvancedEdit(enable: boolean);
begin

	TextFieldInstrumentRemap.enabled:= enable;
	TextFieldInstrumentRemapOldNumber.enabled:= enable;
	TextFieldInstrumentRemapNewNumber.enabled:= enable;

	ButtonInstrumentRemapOldNumberUP.enabled:= enable;
	ButtonInstrumentRemapOldNumberDown.enabled:= enable;
	ButtonInstrumentRemapNewNumberUP.enabled:= enable;
	ButtonInstrumentRemapNewNumberDown.enabled:= enable;

	ButtonRemapInstrumentTrack.enabled:= enable;
	ButtonRemapInstrumentPattern.enabled:= enable;
	ButtonRemapInstrumentSong.enabled:= enable;
	ButtonRemapInstrumentBlock.enabled:= enable;


	CheckBoxMaskingEnable.enabled:= enable;
	TextFieldC.enabled:= enable;
	TextFieldP.enabled:= enable;
	TextFieldT.enabled:= enable;
	TextFieldNote.enabled:= enable;
	TextFieldInstrumentNumber.enabled:= enable;
	TextFieldVolumeColumn.enabled:= enable;
	TextFieldEffectDigit1.enabled:= enable;
	TextFieldEffectDigit23.enabled:= enable;

	CheckBoxNoteC.enabled:= enable;
	CheckBoxNoteP.enabled:= enable;
	CheckBoxNoteT.enabled:= enable;

	CheckBoxInstrumentNumberC.enabled:= enable;
	CheckBoxInstrumentNumberP.enabled:= enable;
	CheckBoxInstrumentNumberT.enabled:= enable;

	CheckBoxVolumeColumnC.enabled:= enable;
	CheckBoxVolumeColumnP.enabled:= enable;
	CheckBoxVolumeColumnT.enabled:= enable;

	CheckBoxEffectDigit1C.enabled:= enable;
	CheckBoxEffectDigit1P.enabled:= enable;
	CheckBoxEffectDigit1T.enabled:= enable;

	CheckBoxEffectDigit23C.enabled:= enable;
	CheckBoxEffectDigit23P.enabled:= enable;
	CheckBoxEffectDigit23T.enabled:= enable;

end;