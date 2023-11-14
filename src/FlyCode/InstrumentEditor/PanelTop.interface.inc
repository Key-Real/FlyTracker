var
	TopPanel : TtuiBox;

	RadioButtonGroupLoopType : TtuiRadioButtonGroup;
	RadioButtonLoopTypeNoLoop : TtuiRadioButton;
	RadioButtonLoopTypeForward : TtuiRadioButton;
	RadioButtonLoopTypePingPong : TtuiRadioButton;
	procedure doRadioButtonLoopType;
	procedure execProcRadioButtonLoopTypeNoLoop(const param: string);
	procedure execProcRadioButtonLoopTypeForwardLoop(const param: string);
	procedure execProcRadioButtonLoopTypePingPongLoop(const param: string);

var
	RadioButtonGroupSampleBits : TtuiRadioButtonGroup;
	RadioButtonSampleBits8 : TtuiRadioButton;
	RadioButtonSampleBits16 : TtuiRadioButton;
	procedure doRadioButtonSampleBits8;
	procedure execProcRadioButtonSampleBits8(const param: string);
	procedure doRadioButtonSampleBits16;
	procedure execProcRadioButtonSampleBits16(const param: string);

var
	RadioButtonGroupSampleMonoStereo : TtuiRadioButtonGroup;
	RadioButtonSampleMono : TtuiRadioButton;
	RadioButtonSampleStereo : TtuiRadioButton;
	procedure doRadioButtonSampleMono;
	procedure execProcRadioButtonSampleMono(const param: string);
	procedure doRadioButtonSampleStereo;
	procedure execProcRadioButtonSampleStereo(const param: string);

var
	ImageWaveStyle1Sprite : gfxImage;
	ImageWaveStyle1SpriteOver : gfxImage;
	ImageWaveStyle2Sprite : gfxImage;
	ImageWaveStyle2SpriteOver : gfxImage;	
	ImageWaveStyle3Sprite : gfxImage;
	ImageWaveStyle3SpriteOver : gfxImage;
	ImageWaveStyle4Sprite : gfxImage;
	ImageWaveStyle4SpriteOver : gfxImage;

	RadioButtonGroupWaveStyle: TtuiRadioButtonGroup;
	RadioButtonWaveStyle1 : TtuiRadioButton;
	RadioButtonWaveStyle2 : TtuiRadioButton;
	RadioButtonWaveStyle3 : TtuiRadioButton;
	RadioButtonWaveStyle4 : TtuiRadioButton;
	RadioButtonWaveStyle5 : TtuiRadioButton;


procedure doRadioButtonWaveStyle1;
procedure execProcRadioButtonWaveStyle1(const param: string);
procedure doRadioButtonWaveStyle2;
procedure execProcRadioButtonWaveStyle2(const param: string);
procedure doRadioButtonWaveStyle3;
procedure execProcRadioButtonWaveStyle3(const param: string);
procedure doRadioButtonWaveStyle4;
procedure execProcRadioButtonWaveStyle4(const param: string);
procedure doRadioButtonWaveStyle5;
procedure execProcRadioButtonWaveStyle5(const param: string);

var
	RadioButtonGroupLoopSustainOrNormal : TtuiRadioButtonGroup;
	RadioButtonLoopNormal : TtuiRadioButton;
	RadioButtonLoopSustain : TtuiRadioButton;
	
procedure doRadioButtonLoop;
procedure execProcRadioButtonLoopNormal(const param: string);
procedure execProcRadioButtonSustain(const param: string);


var
	ButtonStop : TtuiButton;
procedure doButtonStop;
procedure execProcButtonStop(const param: string);

var
	ButtonWave : TtuiButton;
procedure doButtonWave;
procedure execProcButtonWave(const param: string);

var
	ButtonRange : TtuiButton;
procedure doButtonRange;
procedure execProcButtonRange(const param: string);

var
	ButtonDisplay : TtuiButton;
procedure doButtonDisplay;
procedure execProcButtonDisplay(const param: string);

var
	ButtonVolume : TtuiButton;
procedure doButtonVolume;
procedure execProcButtonWaveVolume(const param: string);
var	
	ButtonXFade : TtuiButton;
procedure doButtonXFade;
procedure execProcButtonXFade(const param: string);

var
	ButtonShow : TtuiButton;
	ButtonZoomOut : TtuiButton;
	ButtonRangeAll : TtuiButton;
	ButtonShowAll : TtuiButton;
	ButtonCrop : TtuiButton;
procedure doButtonCrop;
procedure execProcButtonCrop(const param: string);


var
	ButtonCut : TtuiButton;
procedure doButtonCut;
procedure execProcButtonCut(const param: string);

var
	ButtonCopy : TtuiButton;
procedure doButtonCopy;
procedure execProcButtonCopy(const param: string);

var
	ButtonPaste : TtuiButton;
procedure doButtonPaste;
procedure execProcButtonPaste(const param: string);

var	
	aDialog:TtuiDialogMessageBox;
	
	TextFiledSampleLength : TtuiTextField;

var
	TextFiledLoopStart : TtuiTextField;
	ButtonUPLoopStart : TtuiButtonUP;
	ButtonDOWNLoopStart : TtuiButtonDOWN;
	procedure doButtonLoopStart(value: longint);
	procedure execProcButtonUPLoopStart(const param: string);
	procedure execProcButtonDOWNLoopStart(const param: string);

var	
	TextFiledLoopEnd : TtuiTextField;
	ButtonUPLoopEnd : TtuiButtonUP;
	ButtonDOWNLoopEnd : TtuiButtonDOWN;
	procedure doButtonLoopEnd(value: longint);
	procedure execProcButtonUPLoopEnd(const param: string);
	procedure execProcButtonDOWNLoopEnd(const param: string);

var
	TextFiledSustainLoopStart : TtuiTextField;
	ButtonUPSustainLoopStart : TtuiButtonUP;
	ButtonDOWNSustainLoopStart : TtuiButtonDOWN;
	procedure doButtonSustainLoopStart(value: longint);
	procedure execProcButtonUPSustainLoopStart(const param: string);
	procedure execProcButtonDOWNSustainLoopStart(const param: string);

var
	TextFiledSustainLoopEnd : TtuiTextField;
	ButtonUPSustainLoopEnd : TtuiButtonUP;
	ButtonDOWNSustainLoopEnd : TtuiButtonDOWN;
	procedure doButtonSustainLoopEnd(value: longint);
	procedure execProcButtonUPSustainLoopEnd(const param: string);
	procedure execProcButtonDOWNSustainLoopEnd(const param: string);	


var
	ScrollBarFineTune : TtuiScrollBarHorizontal;
	TextFieldFineTune : TtuiTextField;
	procedure execProcScrollBarFineTune(const param: string);



var

	ScrollBarVibratoSpeed : TtuiScrollBarHorizontal;
	TextFiledVibratoSpeed : TtuiTextField;
	procedure execProcScrollBarVibratoSpeed(const param: string);
var
	ScrollBarVibratoDepth : TtuiScrollBarHorizontal;
	TextFiledVibratoDepth : TtuiTextField;
	procedure execProcScrollBarVibratoDepth(const param: string);

var

	ScrollBarVibratoSweep : TtuiScrollBarHorizontal;
	TextFiledVibratoSweep : TtuiTextField;
	procedure execProcScrollBarVibratoSweep(const param: string);









procedure buildTopPanel; 
procedure reloadTopPanel;

procedure reloadInstrumentEditor;


procedure execProcOnInstrumentSelect(const param: string);

procedure execProcNotImplemented(const param: string);


	
var
	ScrollBarBox : TtuiBox;
	mainScrollBar : TtuiScrollBarHorizontal;

	procedure ScrollBarInstrumentEditorMainProc(const param: string);

	procedure buildScrollbar;
    procedure reloadScrollBar;

