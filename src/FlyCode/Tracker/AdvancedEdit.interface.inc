var

	InstrumentRemapOldNumer : longint;
	InstrumentRemapNewNumer : longint;

	
	AdvancedEditEnabled : boolean;


	TextFieldInstrumentRemap : TtuiTextField;
	TextFieldInstrumentRemapOldNumber : TtuiTextField;
	TextFieldInstrumentRemapNewNumber : TtuiTextField;

	ButtonInstrumentRemapOldNumberUP : TtuiButtonUP;
	ButtonInstrumentRemapOldNumberDown : TtuiButtonDown;	
	ButtonInstrumentRemapNewNumberUP : TtuiButtonUP;
	ButtonInstrumentRemapNewNumberDown : TtuiButtonDown;

	ButtonRemapInstrumentTrack : TtuiButton;
	ButtonRemapInstrumentPattern : TtuiButton;
	ButtonRemapInstrumentSong : TtuiButton;
	ButtonRemapInstrumentBlock : TtuiButton;


	CheckBoxMaskingEnable : TtuiCheckBox;
	TextFieldC : TtuiTextField;
	TextFieldP : TtuiTextField;
	TextFieldT : TtuiTextField;
	TextFieldNote : TtuiTextField;
	TextFieldInstrumentNumber : TtuiTextField;
	TextFieldVolumeColumn : TtuiTextField;
	TextFieldEffectDigit1 : TtuiTextField;
	TextFieldEffectDigit23 : TtuiTextField;

	CheckBoxNoteC : TtuiCheckBox;
	CheckBoxNoteP : TtuiCheckBox;
	CheckBoxNoteT : TtuiCheckBox;

	CheckBoxInstrumentNumberC : TtuiCheckBox;
	CheckBoxInstrumentNumberP : TtuiCheckBox;
	CheckBoxInstrumentNumberT : TtuiCheckBox;

	CheckBoxVolumeColumnC : TtuiCheckBox;
	CheckBoxVolumeColumnP : TtuiCheckBox;
	CheckBoxVolumeColumnT : TtuiCheckBox;

	CheckBoxEffectDigit1C : TtuiCheckBox;
	CheckBoxEffectDigit1P : TtuiCheckBox;
	CheckBoxEffectDigit1T : TtuiCheckBox;

	CheckBoxEffectDigit23C : TtuiCheckBox;
	CheckBoxEffectDigit23P : TtuiCheckBox;
	CheckBoxEffectDigit23T : TtuiCheckBox;


	procedure BuildAdvancedEdit;
	procedure EnableDisableAdvancedEdit(enable: boolean);

	procedure BuildInstrumentRemap;
	procedure execProcButtonInstrumentRemapOldNumberUP(const param: string);
	procedure execProcButtonInstrumentRemapOldNumberDown(const param: string);
	procedure execProcButtonInstrumentRemapNewNumberUP(const param: string);
	procedure execProcButtonInstrumentRemapNewNumberDown(const param: string);

	procedure execProcButtonRemapInstrumentTrack(const param: string);
	procedure execProcButtonRemapInstrumentPattern(const param: string);
	procedure execProcButtonRemapInstrumentSong(const param: string);
	procedure execProcButtonRemapInstrumentBlock(const param: string);

	procedure BuildMasking;