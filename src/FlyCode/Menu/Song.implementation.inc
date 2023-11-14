procedure TMainMenu.execProcNotImplemented(const param: string);
begin
    
    

end;



procedure TMainMenu.execProcMenuItemTrim(const param: string);
begin

    MenuTUI.closeBox(BoxVerticalMenuSong);

    SongTrimBox:= TtuiBox.create(MenuTUI, TrackerTUI.screen.width div 2 - 100, TrackerTUI.screen.height div 2 - 100, 200 + 10 + 10 + 10, 190, 'box Trim', tuiBoxStd);
    SongTrimBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(SongTrimBox);

    TextFieldTrim:= TtuiTextField.create(SongTrimBox, 'Tracker_TextFieldTrim', 10, 16, 'Trim');
    TextFieldTrim.theme:= LoadThemeTextField;
    TextFieldTrim.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    SongTrimBox.addItem(TextFieldTrim);



    CheckBoxTrimPatterns:= TtuiCheckBox.Create(SongTrimBox, 'CheckBoxTrimPatterns', 10, 32 + 8, 32, 24, 'Patterns', nil);
    CheckBoxTrimPatterns.theme:= LoadThemeCheckBox;
    CheckBoxTrimPatterns.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimPatterns.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimPatterns.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    CheckBoxTrimPatterns.isChecked:= true;
    SongTrimBox.addItem(CheckBoxTrimPatterns);

    CheckBoxTrimInstruments:= TtuiCheckBox.Create(SongTrimBox, 'CheckBoxTrimInstruments', 10, 32 + 24 + 8, 32, 24, 'Instruments', nil);
    CheckBoxTrimInstruments.theme:= LoadThemeCheckBox;
    CheckBoxTrimInstruments.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimInstruments.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimInstruments.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    CheckBoxTrimInstruments.isChecked:= true;
    SongTrimBox.addItem(CheckBoxTrimInstruments);

    CheckBoxTrimSamples:= TtuiCheckBox.Create(SongTrimBox, 'CheckBoxTrimSamples', 10, 32 + 24 + 24 + 8, 32, 24, 'Samples', nil);
    CheckBoxTrimSamples.theme:= LoadThemeCheckBox;
    CheckBoxTrimSamples.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimSamples.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimSamples.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    CheckBoxTrimSamples.isChecked:= true;
    SongTrimBox.addItem(CheckBoxTrimSamples);

    CheckBoxTrimSampleDataAfterLoop:= TtuiCheckBox.Create(SongTrimBox, 'CheckBoxTrimSamples', 10, 32 + 24 + 24 + 24 + 8, 32, 24, 'Sample Data After Loop', nil);
    CheckBoxTrimSampleDataAfterLoop.theme:= LoadThemeCheckBox;
    CheckBoxTrimSampleDataAfterLoop.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimSampleDataAfterLoop.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxTrimSampleDataAfterLoop.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    CheckBoxTrimSampleDataAfterLoop.isChecked:= true;
    SongTrimBox.addItem(CheckBoxTrimSampleDataAfterLoop);


    ButtonTrimBoxCancel:= TtuiButton.create(SongTrimBox, 'Tracker_ButtonSongTrimBoxCancel', 10, 190 - 16 - 26, 100, 26, 'Cancel', @execProcTrimBoxCancel);   
    ButtonTrimBoxCancel.theme:= LoadThemeButton;
    SongTrimBox.addItem(ButtonTrimBoxCancel);

    ButtonTrimBoxTrim:= TtuiButton.create(SongTrimBox, 'Tracker_ButtonSongTrimBoxTrim', 120, 190 - 16 - 26, 100, 26, 'Trim', @execProcTrimBoxTrim);   
    ButtonTrimBoxTrim.theme:= LoadThemeButton;
    SongTrimBox.addItem(ButtonTrimBoxTrim);

    InMenuItem:= true;

end;



procedure TMainMenu.execProcTrimBoxTrim(const param: string);
begin

    MenuTUI.closeBox(SongTrimBox);

    aDialog:= TtuiDialogMessageBox.Create(@aDialog, MenuTUI, 'Not implmented jet');

    InMenuItem:= false;

end;


procedure TMainMenu.execProcTrimBoxCancel(const param: string);
begin

    MenuTUI.closeBox(SongTrimBox);
    InMenuItem:= false;

end;


procedure TMainMenu.execProcMenuItemSongMessage(const param: string);
var
    aBox : TtuiBox;
    aTextBox:TtuiTextBox;
    aButton:TtuiButton;

begin

    MenuTUI.closeBox(BoxVerticalMenuSong);

    
    aBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 232, 100, 464, 480, 'box song message', tuiBoxStd);
    aBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(aBox);

    aTextBox:= TtuiTextBox.Create(aBox, 'TextBox Song Message', 10, 10, aBox.boxWidth - 20, aBox.boxHeight - 64);
    aTextBox.theme:= LoadThemeTextBox;
    aBox.addItem(aTextBox);


    aButton:= TtuiButton.create(aBox, 'Button OK', aBox.boxWidth - 128, aBox.boxHeight - 44, 116, 32, 'OK', @execProcButton_BoxSongMessage_ButtonOK);
    aButton.theme:= LoadThemeButton;
    aBox.addItem(aButton);
    
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
        aTextBox.loadText(Module.songmessage);
    tralalaEngine.Unlock_ReadOnly;

    InMenuItem:= true;

end;


procedure TMainMenu.execProcButton_BoxSongMessage_ButtonOK(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('box song message');
    MenuTUI.closeBox(aBox);

    InMenuItem:= false;

end;


procedure TMainMenu.execProcMenuSongUnSelect(const param: string);
begin

    MenuTUI.closeBox(BoxVerticalMenuSong);

end;


procedure TMainMenu.execProcMenuSongSelect(const param: string);
var 
    aItem : TtuiMenuHorizontalItem;

begin
  
    aItem:= MenuHorizontal.getItemByName('Menu Song');

    BoxVerticalMenuSong:= TtuiBox.Create(MenuTUI, aItem.x, 18, 0, 0, 'Box Vertical Menu Song', tuiBoxStatic);
    BoxVerticalMenuSong.themeBox:= LoadThemeBox;
    MenuTUI.addBox(BoxVerticalMenuSong);

    SongMenuVertical:= TtuiMenuVertical.create(BoxVerticalMenuSong, 'Vertical Menu Song');
    SongMenuVertical.addMenuVerticalItem('Vertical Menu Song - Trim', 'Trim', @execProcMenuItemTrim);
    SongMenuVertical.addMenuVerticalItem('Vertical Menu Song - Convert', 'Convert', @execProcMenuItemConvert);
    SongMenuVertical.addMenuVerticalItem('Vertical Menu Song - SongMessage', 'Song Message', @execProcMenuItemSongMessage);
    SongMenuVertical.theme:= LoadThemeMenuVertical;
    SongMenuVertical.allowMouse2Buttons:= true;
    BoxVerticalMenuSong.addItem(SongMenuVertical);

end;


procedure TMainMenu.execProcMenuItemConvert(const param: string);
var
    aBox : TtuiBox;
 	aButton:TtuiButton;

 begin

    MenuTUI.closeBox(BoxVerticalMenuSong);

    aBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 150, vscreen.height div 2 - 64, 264, 128, 'box song convert', tuiBoxStd);
    aBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(aBox);

    TextFileldConvert:= TtuiTextField.Create(aBox, 'TextFiledConvert', 10, 10, 'Convert to');
    TextFileldConvert.theme:= LoadThemeTextField;
    TextFileldConvert.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    aBox.addItem(TextFileldConvert);

    
    RadioButtonGroupModuleDrivenType:= TtuiRadioButtonGroup.Create(aBox, 'RadioButtonGroupModuleDrivenType');
    aBox.addItem(RadioButtonGroupModuleDrivenType);

    RadioButtonSampleDriven:= TtuiRadioButton.Create(aBox, 'RadioButtonSampleDriven', 16, 42, 'Sample Driven', nil);
    RadioButtonSampleDriven.theme:= LoadThemeRadioButton;
    RadioButtonGroupModuleDrivenType.add2group(RadioButtonSampleDriven);

    RadioButtonInstrumentDriven:= TtuiRadioButton.Create(aBox, 'RadioButtonInstrumentDriven', 16, 64, 'Instrument Driven', nil);
    RadioButtonInstrumentDriven.theme:= LoadThemeRadioButton;
    RadioButtonGroupModuleDrivenType.add2group(RadioButtonInstrumentDriven);


	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick); 
				
    	if mfInstrumentsControl in Module.Flags then begin
            RadioButtonInstrumentDriven.checked:= true;
    	end else begin
            RadioButtonSampleDriven.checked:= true;
    	end;

	tralalaEngine.Unlock_ReadOnly;


    aButton:= TtuiButton.create(aBox, 'Button Cancel', 10, aBox.boxHeight - 44, 116, 26, 'Cancel', @execProcButtonBoxSongConvertButtonCancel);
    aButton.theme:= LoadThemeButton;
    aBox.addItem(aButton);  

    aButton:= TtuiButton.create(aBox, 'Button OK', aBox.boxWidth - 128, aBox.boxHeight - 44, 116, 26, 'OK', @execProcButtonBoxSongConvertButtonOK);
    aButton.theme:= LoadThemeButton;
    aBox.addItem(aButton);

    InMenuItem:= true;

end;


procedure TMainMenu.execProcButtonBoxSongConvertButtonOK(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('box song convert');
    MenuTUI.closeBox(aBox);

	tralalaEngine.Lock_Module_ReadWrite(Module); 

		if RadioButtonInstrumentDriven.checked then begin
			module.InitialiseInstruments;
            Module.Flags:= Module.Flags + [mfInstrumentsControl];
		end;		

        if RadioButtonSampleDriven.checked then begin
            Module.Flags:= Module.Flags - [mfInstrumentsControl];
        end;

	tralalaEngine.Unlock_Module_ReadWrite;

    InMenuItem:= false;

    InstrumentEditor.reloadInstrumentEditor;

end;


procedure TMainMenu.execProcButtonBoxSongConvertButtonCancel(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('box song convert');
    MenuTUI.closeBox(aBox);

    InMenuItem:= false;
    
end;