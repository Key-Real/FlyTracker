	

var

	BottomLeftPanel : TtuiBox; 

	ButtonMapping : TtuiButton;
	
	procedure buildBottomLeftPanel;
	procedure buildBottomRightPanel;


var
	RightPanel : TtuiBox;
	CurrentSampleTextField : TtuiTextField;
	CurrentNoteTextField : TtuiTextField;	
	CurrentCursorPosition : TtuiTextField;






var
	ButtonVolumeEnvelope  : TtuiButton;
	ButtonPanningEnvelope  : TtuiButton;
	ButtonPitchEnvelope  : TtuiButton;

procedure doButtonVolumeEnvelope;
procedure execProcButtonVolume(const param: string);
procedure doButtonPanningEnvelope;	
procedure execProcButtonPanning(const param: string);
procedure doButtonPitchEnvelope;
procedure execProcButtonPitch(const param: string);
procedure doButtonMapping;
procedure execProcButtonMapping(const param: string);	



var
	ScrollBarGlobalVolume : TtuiScrollBarHorizontal;
	TextFiledGlobalVolume : TtuiTextField;
	procedure execProcScrollBarGlobalVolume(const param: string);

var
	ScrollBarDefaultVolume : TtuiScrollBarHorizontal;
	TextFiledDefaultVolume : TtuiTextField;
	procedure execProcScrollBarDefaultVolume(const param: string);

var
	ScrollBarVolumeSwing : TtuiScrollBarHorizontal;
	TextFieldVolumeSwing : TtuiTextField;
	procedure execProcScrollBarVolumeSwing(const param: string);

var
	ScrollBarFadeOut : TtuiScrollBarHorizontal;
	TextFiledFadeOut : TtuiTextField;
	procedure execProcScrollBarFadeOut(const param: string);








var
	ScrollBarModulePanSeperation : TtuiScrollBarHorizontal;
	TextFieldModulePanSeperation : TtuiTextField;
	procedure execProcScrollBarModulePanSeperation(const param:string);


var
	ScrollBarPanning : TtuiScrollBarHorizontal;
	CheckBoxPanning : TtuiCheckBox;
	procedure execProcScrollBarPanning(const param:string);
	procedure execProcCheckBoxPanning(const param:string);




var
	ScrollBarPanSeparation : TtuiScrollBarHorizontal;
	TextFieldPanSeparation : TtuiTextField;
	procedure execProcScrollBarPanSeparation(const param:string);

var

	ScrollBarPanSwing : TtuiScrollBarHorizontal;
	TextFieldPanSwing : TtuiTextField;
	procedure execProcScrollBarPanSwing(const param:string);


	
var
	ButtonUPPanCenter : TtuiButtonUP;
	ButtonDOWNPanCenter : TtuiButtonDOWN;
	TextFieldPanCenter : TtuiTextField;
	
	procedure execProcButtonUPPanCenter(const param:string);
	procedure execProcButtonDOWNPanCenter(const param:string);	



var
	CheckBoxPitchCutOff : TtuiCheckBox;
	ScrollBarPitchCuffOff : TtuiScrollBarHorizontal;
	procedure execProcCheckBoxPitchCutOff(const param:string);
	procedure execProcScrollBarPitchCuffOff(const param:string);

var
	CheckBoxPitchResonance : TtuiCheckBox;
	ScrollBarPitchResonance : TtuiScrollBarHorizontal;
	procedure execProcCheckBoxPitchResonance(const param:string);
	procedure execProcScrollBarPitchResonance(const param:string);


procedure enableVolumePanel;
procedure disableVolumePanel;
procedure enablePanningPanel;
procedure disablePanningPanel;
procedure enablePitchPanel;
procedure disablePitchPanel;
procedure enableMappingPanel;
procedure disableMappingPanel;


procedure ReloadBottomPanel;



var
	TextFiledNewNoteAction : TtuiTextField;
	RadioButtonGroupNewNoteAction: TtuiRadioButtonGroup;
	RadioButtonNewNoteActionNoteCut : TtuiRadioButton;
	RadioButtonNewNoteActionNoteContinue : TtuiRadioButton;
	RadioButtonNewNoteActionNoteOff : TtuiRadioButton;
	RadioButtonNewNoteActionNoteFade : TtuiRadioButton;
	procedure execProcNewNoteActionNoteCut(const param:string);
	procedure execProcNewNoteActionNoteContinue(const param:string);
	procedure execProcNewNoteActionNoteOff(const param:string);
	procedure execProcNewNoteActionNoteFade(const param:string);


var
	ScrollBarMIDIChannel : TtuiScrollBarHorizontal;
	TextFiledMIDIChannel : TtuiTextField;
	procedure execProcScrollBarMIDIChannel(const param:string);



var
	ScrollBarMIDIProgram : TtuiScrollBarHorizontal;
	TextFiledMIDIProgram  : TtuiTextField;
	procedure execProcScrollBarMIDIProgram(const param:string);



var
	ScrollBarMIDIBankLo : TtuiScrollBarHorizontal;
	TextFiledMIDIBankLo  : TtuiTextField;	
	procedure execProcScrollBarMIDIBankLo(const param:string);


var
	ScrollBarMIDIBankHigh : TtuiScrollBarHorizontal;
	TextFiledMIDIBankHigh : TtuiTextField;		
	procedure execProcScrollBarMIDIBankHigh(const param:string);


	

var
	TextFiledDuplicateCheckType : TtuiTextField;
	RadioButtonGroupDuplicateCheckType: TtuiRadioButtonGroup;
	RadioButtonDuplicateCheckTypeDisabled : TtuiRadioButton;
	RadioButtonDuplicateCheckTypeNote : TtuiRadioButton;
	RadioButtonDuplicateCheckTypeSample : TtuiRadioButton;
	RadioButtonDuplicateCheckTypeInstrument : TtuiRadioButton;
	procedure execProcDuplicateCheckTypeDisabled(const param:string);
	procedure execProcDuplicateCheckTypeNote(const param:string);
	procedure execProcDuplicateCheckTypeSample(const param:string);
	procedure execProcDuplicateCheckTypeInstrument(const param:string);



var
	TextFiledDuplicateCheckAction : TtuiTextField;
	RadioButtonGroupDuplicateCheckAction: TtuiRadioButtonGroup;
	RadioButtonDuplicateCheckActionNoteCut : TtuiRadioButton;
	RadioButtonDuplicateCheckActionNoteOff : TtuiRadioButton;
	RadioButtonDuplicateCheckActionNoteFade : TtuiRadioButton;
	procedure execProcDuplicateCheckActionCut(const param:string);
	procedure execProcDuplicateCheckActionOff(const param:string);
	procedure execProcDuplicateCheckActionFade(const param:string);

