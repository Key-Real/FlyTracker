public
    var
        ButtonPlaySong : TtuiButton;
        ButtonPlayPattern : TtuiButton;
        ButtonStop : TtuiButton;
        ButtonRecordSong : TtuiButton;
        ButtonRecordPattern : TtuiButton;
        ButtonTranspose : TtuiButton;
        ButtonAdvancedEdit : TtuiButton;

    procedure doButtonTranspose;
    procedure ButtonTransposeProc(const param: string);

    procedure doButtonAdvancedEdit;
    procedure ButtonAdvancedEditProc(const param: string);

    procedure doPlaySong;
	procedure ButtonPlaySongProc(const param: string);

	procedure doPlayPattern;
    procedure ButtonPlayPatternProc(const param: string);

    procedure doStopSong;
    procedure ButtonStopProc(const param: string);

    procedure doRecordSong;
    procedure ButtonRecordSongProc(const param: string);

    procedure doRecordPattern;
    procedure ButtonRecordPatternProc(const param: string);

    
    procedure buildMainPanel;
    procedure reloadMainPanel;

  var
        aDialog : TtuiDialogMessageBox;


	procedure execProcSongName(const param: string);
	procedure execProcSongNameLoseFocus(const param: string);

	procedure execProcBPMButtonUP(const param: string);
	procedure execProcBPMButtonDOWN(const param: string);

	procedure execProcSpeedButtonUP(const param: string);
	procedure execProcSpeedButtonDOWN(const param: string);

	procedure execProcSongChannelsButtonUP(const param: string);
	procedure execProcSongChannelsButtonDOWN(const param: string);

	procedure execProcPatternLengthButtonUP(const param: string);
	procedure execProcPatternLengthButtonDOWN(const param: string);

	procedure execProcNoteAddButtonUP(const param: string);
	procedure execProcNoteAddButtonDOWN(const param: string);

	procedure execProcOctaveButtonUP(const param: string);
	procedure execProcOctaveButtonDOWN(const param: string);

	procedure execProcRepeatStartButtonUP(const param: string);
	procedure execProcRepeatStartButtonDOWN(const param: string);



	var
	// LEFT SIDE
		TextFieldBPM : TtuiTextField;
		ButtonUPBPM : TtuiButtonUP;
		ButtonDOWNBPM : TtuiButtonDOWN;

		TextFieldSpeed : TtuiTextField;
		ButtonUPSpeed : TtuiButtonUP;
		ButtonDOWNSpeed : TtuiButtonDOWN;

		TextFieldPatternLength : TtuiTextField;
		ButtonUPPatternLength : TtuiButtonUP;
		ButtonDOWNPatternLength : TtuiButtonDOWN;

		TextFieldSongChannels : TtuiTextField;
		ButtonUPSongChannels : TtuiButtonUP;
		ButtonDOWNSongChannels : TtuiButtonDOWN;

	
		TextFieldOctave : TtuiTextField;
		ButtonUPOctave : TtuiButtonUP;
		ButtonDOWNOctave : TtuiButtonDOWN;


		TextFieldRepeatStart : TtuiTextField;
		ButtonUPRepeatStart : TtuiButtonUP;
		ButtonDOWNRepeatStart : TtuiButtonDOWN;

		TextFieldNoteAdd : TtuiTextField;
		ButtonUPNoteAdd : TtuiButtonUP;
		ButtonDOWNNoteAdd : TtuiButtonDOWN;



	// RIGHT SIDE
		
var
		TextFieldSongTime : TtuiTextField;
		TextFieldGlobalVolume : TtuiTextField;
		TextFieldCurrentBPM  : TtuiTextField;
		TextFieldCurrentSpeed  : TtuiTextField;
		TextFieldCurrentVirtualPinoKeyStroke : TtuiTextField;
		TextFieldSongName : TtuiTextField;
		EditFieldSongName : TtuiEditField;


	procedure BuildRightSide;
	procedure EnableDisableRightSide(enable: boolean);


var

		ButtonExpand : TtuiButton;
		ButtonShrink : TtuiButton;

	procedure ButtonExpandProc(const param: string);
	procedure ButtonShrinkProc(const param: string);


var
	ScrollBarBox : TtuiBox;

	procedure buildScrollbar;
    procedure reloadScrollBar;



var
		MetersValue : TVUMeterStereoValue;
		vuMeters : TtuiImage;
		vuMetersImage : gfxImage;

	procedure buildVUMeters;

	procedure updateVUMeters;

	procedure VUbar(x: dword; height: integer);


var
	
	mainScrollBar : TtuiScrollBarHorizontal;
	procedure execProcMainScrollBar(const param: string);