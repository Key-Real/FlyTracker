var
    	SongTrimBox : TtuiBox;
    	TextFieldTrim : TtuiTextField;
		ButtonTrimBoxTrim : TtuiButton;
		ButtonTrimBoxCancel : TtuiButton;
		CheckBoxTrimPatterns : TtuiCheckBox;
		CheckBoxTrimInstruments : TtuiCheckBox;
		CheckBoxTrimSamples : TtuiCheckBox;
		CheckBoxTrimSampleDataAfterLoop : TtuiCheckBox;

		RadioButtonGroupModuleDrivenType : TtuiRadioButtonGroup;
		RadioButtonSampleDriven : TtuiRadioButton;
		RadioButtonInstrumentDriven : TtuiRadioButton;

    procedure execProcMenuSongUnSelect(const param: string);
    procedure execProcMenuSongSelect(const param: string);
	

	procedure execProcMenuItemTrim(const param: string);
	procedure execProcTrimBoxTrim(const param: string);
	procedure execProcTrimBoxCancel(const param: string);


	procedure execProcMenuItemSongMessage(const param: string);
	procedure execProcButton_BoxSongMessage_ButtonOK(const param: string);
 

 var
 	TextFileldConvert : TtuiTextField;


 	procedure execProcMenuItemConvert(const param: string);
 	procedure execProcButtonBoxSongConvertButtonOK(const param: string);
 	procedure execProcButtonBoxSongConvertButtonCancel(const param: string);

var
	aDialog : TtuiDialogMessageBox;
 	procedure execProcNotImplemented(const param: string);
