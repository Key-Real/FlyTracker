

procedure TInstrumentEditor.buildBottomLeftPanel;
begin

    BottomLeftPanel:= TtuiBox.create(InstrumentEditorTUI, 0, 632 - 200, 116, 200, 'BottomLeftPanel', tuiBoxStatic);
    BottomLeftPanel.ThemeBox:= LoadThemeBox;
    BottomLeftPanel.ThemeBox.BackgroundColor:= Theme_InstrumentEditor_MainPanel_BackgroundColor;
    InstrumentEditorTUI.addBox(BottomLeftPanel);

	ButtonVolumeEnvelope:= TtuiButton.create(BottomLeftPanel, 'ButtonVolumeEnvelope', 1, 20, 100, 32, 'Volume', @execProcButtonVolume);
    BottomLeftPanel.addItem(ButtonVolumeEnvelope);

    ButtonPanningEnvelope:= TtuiButton.create(BottomLeftPanel, 'ButtonPanningEnvelope', 1, 20 + 33, 100, 32, 'Panning', @execProcButtonPanning);
    BottomLeftPanel.addItem(ButtonPanningEnvelope);

    ButtonPitchEnvelope:= TtuiButton.create(BottomLeftPanel, 'ButtonPitchEnvelope', 1, 20 + 33 + 33, 100, 32, 'Pitch', @execProcButtonPitch);
    BottomLeftPanel.addItem(ButtonPitchEnvelope);

    ButtonMapping:= TtuiButton.create(BottomLeftPanel, 'ButtonMapping', 1, 200 - 36, 100, 32, 'Mapping', @execProcButtonMapping);
    BottomLeftPanel.addItem(ButtonMapping);

end; 


procedure TInstrumentEditor.buildBottomRightPanel;
begin
	RightPanel:= TtuiBox.create(InstrumentEditorTUI, 116 + 827, 632 - 200, 1280 - 116 - 827, 200, 'InstrumentRightPanel', tuiBoxStatic);
    RightPanel.ThemeBox:= LoadThemeBox;
    RightPanel.ThemeBox.BackgroundColor:= $ff000000;
    InstrumentEditorTUI.addBox(RightPanel);

    CurrentNoteTextField:= TtuiTextField.Create(RightPanel, 'CurrentNoteTextField', 4, 200 - 60, 'Current Note:');
    CurrentNoteTextField.theme:= LoadThemeTextField;
    CurrentNoteTextField.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(CurrentNoteTextField);

    CurrentSampleTextField:= TtuiTextField.Create(RightPanel, 'CurrentSampleTextField', 4, 200 - 40, 'Current Sample:');
    CurrentSampleTextField.theme:= LoadThemeTextField;
    CurrentSampleTextField.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(CurrentSampleTextField);

    CurrentCursorPosition:= TtuiTextField.Create(RightPanel, 'CurrentCursorPosition', 4, 200 - 20, 'Current Cursor position in Sample:');
    CurrentCursorPosition.theme:= LoadThemeTextField;
    CurrentCursorPosition.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(CurrentCursorPosition);




    ScrollBarGlobalVolume:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarGlobalVolume', 190, 2, 128, 64, @execProcScrollBarGlobalVolume);
    ScrollBarGlobalVolume.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarGlobalVolume);

    TextFiledGlobalVolume:= TtuiTextField.Create(RightPanel, 'TextFiledGlobalVolume', 82, 4, 'Global Volume ' + numstr(0)); 
    TextFiledGlobalVolume.theme:= LoadThemeTextField;
    TextFiledGlobalVolume.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledGlobalVolume);



    ScrollBarDefaultVolume:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarDefaultVolume', 190, 2 + 18, 128, 64, @execProcScrollBarDefaultVolume);
    ScrollBarDefaultVolume.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarDefaultVolume);

    TextFiledDefaultVolume:= TtuiTextField.Create(RightPanel, 'TextFiledDefualtVolume', 82, 4 + 18, 'Default Volume ' + numstr(0)); 
    TextFiledDefaultVolume.theme:= LoadThemeTextField;
    TextFiledDefaultVolume.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledDefaultVolume);





    ScrollBarVolumeSwing:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarVolumeSwing', 190, 2 + 18 + 18, 128, 100, @execProcScrollBarVolumeSwing);
    ScrollBarVolumeSwing.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarVolumeSwing);


    TextFieldVolumeSwing:= TtuiTextField.Create(RightPanel, 'TextFieldVolumeSwing', 82, 4 + 18 + 18, 'Volume Swing ');
    TextFieldVolumeSwing.theme:= LoadThemeTextField;
    TextFieldVolumeSwing.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFieldVolumeSwing);


    ScrollBarFadeOut:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarFadeOut', 190, 2 + 18 + 18 + 18, 128, 8192, @execProcScrollBarFadeOut);
    ScrollBarFadeOut.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarFadeOut);

    TextFiledFadeOut:= TtuiTextField.Create(RightPanel, 'TextFiledFadeOut', 84, 4 + 18 + 18 + 18, 'Fade Out ' + numstr(0));
    TextFiledFadeOut.theme:= LoadThemeTextField;
    TextFiledFadeOut.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledFadeOut);















    ScrollBarModulePanSeperation:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarModulePanSeperation', 190, 2, 128, 128, @execProcScrollBarModulePanSeperation);
    ScrollBarModulePanSeperation.theme:= LoadThemeScrollbarHorizontal;
    
    RightPanel.addItem(ScrollBarModulePanSeperation);

    TextFieldModulePanSeperation:= TtuiTextField.Create(RightPanel, 'TextFiledModulePanSeperation', 18, 4, 'Song Panning Seperation 0'); 
    TextFieldModulePanSeperation.theme:= LoadThemeTextField;
    TextFieldModulePanSeperation.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFieldModulePanSeperation);



    ScrollBarPanning:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarPanning', 190, 2 + 18, 128, 256, @execProcScrollBarPanning);
    ScrollBarPanning.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarPanning);

    CheckBoxPanning:= TtuiCheckBox.Create(RightPanel, 'CheckBoxPanning', 80, 1 + 18, 120, 24, 'Panning 000', @execProcCheckBoxPanning);
    CheckBoxPanning.theme:= LoadThemeCheckBox;
    CheckBoxPanning.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPanning.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPanning.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    CheckBoxPanning.isChecked:= false;
    RightPanel.addItem(CheckBoxPanning);





    
    ScrollBarPanSeparation:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarPanSeparation', 190, 2 + 18 + 18, 128, 64, @execProcScrollBarPanSeparation);
    ScrollBarPanSeparation.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarPanSeparation);


    TextFieldPanSeparation:= TtuiTextField.Create(RightPanel, 'TextFieldPanSeparation', 80, 4 + 18 + 18, 'Pan Separation ');
    TextFieldPanSeparation.theme:= LoadThemeTextField;
    TextFieldPanSeparation.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFieldPanSeparation);


    ScrollBarPanSwing:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarPanSwing', 190, 2 + 18 + 18 + 18, 128, 64, @execProcScrollBarPanSwing);
    ScrollBarPanSwing.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarPanSwing);


    TextFieldPanSwing:= TtuiTextField.Create(RightPanel, 'TextFieldPanSwing', 104, 4 + 18 + 18 + 18, 'Pan Swing ');
    TextFieldPanSwing.theme:= LoadThemeTextField;
    TextFieldPanSwing.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFieldPanSwing);



    TextFieldPanCenter:= TtuiTextField.Create(RightPanel, 'TextFieldPanCenter', 114, 4 + 18 + 18 + 18 + 18 + 1, 'Center C5');
    TextFieldPanCenter.theme:= LoadThemeTextField;
    TextFieldPanCenter.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFieldPanCenter);

    ButtonUPPanCenter:= TtuiButtonUP.Create(RightPanel, 'ButtonUPPanCenter', 190, 4 + 18 + 18 + 18 + 18, @execProcButtonUPPanCenter);
    ButtonUPPanCenter.theme:= LoadThemeButtonUP;
    RightPanel.addItem(ButtonUPPanCenter);

    ButtonDOWNPanCenter:= TtuiButtonDOWN.Create(RightPanel, 'ButtonDOWNPanCenter', 209, 4 + 18 + 18 + 18 + 18, @execProcButtonDOWNPanCenter);
    ButtonDOWNPanCenter.theme:= LoadThemeButtonDOWN;
    RightPanel.addItem(ButtonDOWNPanCenter);






    CheckBoxPitchCutOff:= TtuiCheckBox.Create(RightPanel, 'CheckBoxPitchCutOff', 20 + 20, 22, 24, 24, 'Pitch Cutoff 000', @execProcCheckBoxPitchCutOff);
    CheckBoxPitchCutOff.theme:= LoadThemeCheckBox;
    CheckBoxPitchCutOff.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPitchCutOff.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPitchCutOff.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    
    RightPanel.addItem(CheckBoxPitchCutOff);

    ScrollBarPitchCuffOff:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarPitchCuffOff', 190, 22, 128, 127, @execProcScrollBarPitchCuffOff);
    ScrollBarPitchCuffOff.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarPitchCuffOff);






    CheckBoxPitchResonance:= TtuiCheckBox.Create(RightPanel, 'CheckBoxPitchResonance', 20 + 20, 4, 120, 24, 'Pitch Resonance 000', @execProcCheckBoxPitchResonance);
    CheckBoxPitchResonance.theme:= LoadThemeCheckBox;
    CheckBoxPitchResonance.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPitchResonance.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    CheckBoxPitchResonance.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    
    RightPanel.addItem(CheckBoxPitchResonance);

    ScrollBarPitchResonance:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarPitchResonance', 190, 4, 128, 127, @execProcScrollBarPitchResonance);
    ScrollBarPitchResonance.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarPitchResonance);





    ScrollBarMIDIChannel:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarMIDIChannel', 190, 4 + 18 + 18 + 4, 128, 17, @execProcScrollBarMIDIChannel);
    ScrollBarMIDIChannel.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarMIDIChannel);


    TextFiledMIDIChannel:= TtuiTextField.Create(RightPanel, 'TextFiledMIDIChannel', 76 + 20, 4 + 18 + 18 + 4, 'MIDI Channel 17');
    TextFiledMIDIChannel.theme:= LoadThemeTextField;
    TextFiledMIDIChannel.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledMIDIChannel);


    ScrollBarMIDIProgram:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarMIDIProgram', 190, 4 + 18 + 18 + 18 + 4, 128, 127, @execProcScrollBarMIDIProgram);
    ScrollBarMIDIProgram.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarMIDIProgram);


    TextFiledMIDIProgram:= TtuiTextField.Create(RightPanel, 'TextFiledMIDIProgram', 67 + 20, 4 + 18 +18 + 18 + 4, 'MIDI Program 127');
    TextFiledMIDIProgram.theme:= LoadThemeTextField;
    TextFiledMIDIProgram.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledMIDIProgram);


    ScrollBarMIDIBankLo:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarMIDIBankLo', 190, 4 + 18 + 18 + 18 + 18 + 4, 128, 127, @execProcScrollBarMIDIBankLo);
    ScrollBarMIDIBankLo.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarMIDIBankLo);


    TextFiledMIDIBankLo:= TtuiTextField.Create(RightPanel, 'TextFiledMIDIBankLo', 70 + 20, 4 + 18 + 18 + 18 + 18 + 4, 'MIDI Bank Lo 127');
    TextFiledMIDIBankLo.theme:= LoadThemeTextField;
    TextFiledMIDIBankLo.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledMIDIBankLo);

    ScrollBarMIDIBankHigh:= TtuiScrollBarHorizontal.Create(RightPanel, 'ScrollBarMIDIBankHigh', 190, 4 + 18 + 18 + 18 + 18 + 18 + 4, 128, 127, @execProcScrollBarMIDIBankHigh);
    ScrollBarMIDIBankHigh.theme:= LoadThemeScrollbarHorizontal;
    RightPanel.addItem(ScrollBarMIDIBankHigh);


    TextFiledMIDIBankHigh:= TtuiTextField.Create(RightPanel, 'TextFiledMIDIBankHigh', 58 + 20, 4 + 18 + 18 + 18 + 18 + 18 + 4, 'MIDI Bank High 127');
    TextFiledMIDIBankHigh.theme:= LoadThemeTextField;
    TextFiledMIDIBankHigh.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    RightPanel.addItem(TextFiledMIDIBankHigh);








    TextFiledNewNoteAction:= TtuiTextField.Create(RightPanel, 'TextFiledNewNoteAction', 4, 2, 'New Note Action');
    TextFiledNewNoteAction.theme:= LoadThemeTextField;
    TextFiledNewNoteAction.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(TextFiledNewNoteAction);

    RadioButtonGroupNewNoteAction:= TtuiRadioButtonGroup.Create(RightPanel, 'RadioButtonGroupNewNoteAction');
    RightPanel.addItem(RadioButtonGroupNewNoteAction);

    RadioButtonNewNoteActionNoteOff:= TtuiRadioButton.Create(RightPanel, 'RadioButtonNewNoteActionNoteOff', 10, 25 + 2, 'Off', @execProcNewNoteActionNoteOff);
    RadioButtonNewNoteActionNoteOff.theme:= LoadThemeRadioButton;    
    RadioButtonGroupNewNoteAction.add2group(RadioButtonNewNoteActionNoteOff);

    RadioButtonNewNoteActionNoteCut:= TtuiRadioButton.Create(RightPanel, 'RadioButtonNewNoteActionNoteCut', 64, 25 + 2, 'Cut', @execProcNewNoteActionNoteCut);
    RadioButtonNewNoteActionNoteCut.theme:= LoadThemeRadioButton;    
    RadioButtonGroupNewNoteAction.add2group(RadioButtonNewNoteActionNoteCut);

    RadioButtonNewNoteActionNoteFade:= TtuiRadioButton.Create(RightPanel, 'RadioButtonNewNoteActionNoteFade', 10, 25 + 2 + 16, 'Fade', @execProcNewNoteActionNoteOff);
    RadioButtonNewNoteActionNoteFade.theme:= LoadThemeRadioButton;    
    RadioButtonGroupNewNoteAction.add2group(RadioButtonNewNoteActionNoteFade);

    RadioButtonNewNoteActionNoteContinue:= TtuiRadioButton.Create(RightPanel, 'RadioButtonNewNoteActionNoteContinue', 64, 25 + 2 + 16, 'Continue', @execProcNewNoteActionNoteContinue);
    RadioButtonNewNoteActionNoteContinue.theme:= LoadThemeRadioButton;    
    RadioButtonGroupNewNoteAction.add2group(RadioButtonNewNoteActionNoteContinue);








    TextFiledDuplicateCheckType:= TtuiTextField.Create(RightPanel, 'TextFiledDuplicateCheckType', 164, 2, 'Duplicate Check Type');
    TextFiledDuplicateCheckType.theme:= LoadThemeTextField;
    TextFiledDuplicateCheckType.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(TextFiledDuplicateCheckType);

    RadioButtonGroupDuplicateCheckType:= TtuiRadioButtonGroup.Create(RightPanel, 'RadioButtonGroupDuplicateCheckType');
    RightPanel.addItem(RadioButtonGroupDuplicateCheckType);

    RadioButtonDuplicateCheckTypeDisabled:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckTypeDisabled', 164, 25 + 2, 'Disabled', @execProcDuplicateCheckTypeDisabled);
    RadioButtonDuplicateCheckTypeDisabled.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckType.add2group(RadioButtonDuplicateCheckTypeDisabled);

    RadioButtonDuplicateCheckTypeNote:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckTypeNote', 164 + 70, 25 + 2, 'Note', @execProcDuplicateCheckTypeNote);
    RadioButtonDuplicateCheckTypeNote.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckType.add2group(RadioButtonDuplicateCheckTypeNote);

    RadioButtonDuplicateCheckTypeSample:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckTypeSample', 164, 25 + 16 + 2, 'Sample', @execProcDuplicateCheckTypeSample);
    RadioButtonDuplicateCheckTypeSample.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckType.add2group(RadioButtonDuplicateCheckTypeSample);

    RadioButtonDuplicateCheckTypeInstrument:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckTypeInstrument', 164 + 70, 25 + 16 + 2, 'Instrument', @execProcDuplicateCheckTypeInstrument);
    RadioButtonDuplicateCheckTypeInstrument.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckType.add2group(RadioButtonDuplicateCheckTypeInstrument);








    


    TextFiledDuplicateCheckAction:= TtuiTextField.Create(RightPanel, 'TextFiledDuplicateCheckAction', 4, 64, 'Duplicate Check Action');
    TextFiledDuplicateCheckAction.theme:= LoadThemeTextField;
    TextFiledDuplicateCheckAction.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    RightPanel.addItem(TextFiledDuplicateCheckAction);

    RadioButtonGroupDuplicateCheckAction:= TtuiRadioButtonGroup.Create(RightPanel, 'RadioButtonGroupDuplicateCheckAction');
    RightPanel.addItem(RadioButtonGroupDuplicateCheckAction);

    RadioButtonDuplicateCheckActionNoteOff:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckActionNoteOff', 10, 10 + 64 + 16, 'Off', @execProcDuplicateCheckActionOff);
    RadioButtonDuplicateCheckActionNoteOff.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckAction.add2group(RadioButtonDuplicateCheckActionNoteOff);

    RadioButtonDuplicateCheckActionNoteCut:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckActionNoteCut', 64, 10 + 64 + 16, 'Cut', @execProcDuplicateCheckActionCut);
    RadioButtonDuplicateCheckActionNoteCut.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckAction.add2group(RadioButtonDuplicateCheckActionNoteCut);



    RadioButtonDuplicateCheckActionNoteFade:= TtuiRadioButton.Create(RightPanel, 'RadioButtonDuplicateCheckActionNoteFade', 10, 10 + 64 + 16 + 16, 'Fade', @execProcDuplicateCheckActionFade);
    RadioButtonDuplicateCheckActionNoteFade.theme:= LoadThemeRadioButton;    
    RadioButtonGroupDuplicateCheckAction.add2group(RadioButtonDuplicateCheckActionNoteFade);

end;

procedure TInstrumentEditor.ReloadBottomPanel;
begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        ScrollBarGlobalVolume.setCurValue(Module.samples[CurrentSample].GlobalVolume);
        TextFiledGlobalVolume.caption:= 'Global Volume ' + numstr(ScrollBarGlobalVolume.curValue);
        ScrollBarDefaultVolume.setCurValue(Module.samples[CurrentSample].DefaultVolume);
        TextFiledDefaultVolume.caption:= 'Default Volume ' + numstr(ScrollBarDefaultVolume.curValue);

        ScrollBarFadeOut.setCurValue(Module.instruments[CurrentInstrument].FadeOut);
        TextFiledFadeOut.caption:= 'Fade Out ' + numstr(ScrollBarFadeOut.curValue);

        ScrollBarPanning.setCurValue(Module.instruments[CurrentInstrument].DefaultPan);
        CheckBoxPanning.caption:= 'Panning ' + numstr(ScrollBarPanning.curValue);
        CheckBoxPanning.isChecked:=Module.instruments[CurrentInstrument].DefaultPanEnabled;

        ScrollBarVolumeSwing.setCurValue(Module.instruments[CurrentInstrument].RandomVolumeSwing);
        TextFieldVolumeSwing.caption:= 'Volume Swing ' + numstr(Module.instruments[CurrentInstrument].RandomVolumeSwing) + '%';

        ScrollBarPanSeparation.setCurValue(Module.instruments[CurrentInstrument].PitchPanSeparation+32);
        TextFieldPanSeparation.caption:= 'Pan Separation ' + numstr(Module.Instruments[CurrentSample].PitchPanSeparation);
        


        TextFieldModulePanSeperation.caption:= 'Song Panning Seperation ' + numstr(Module.PanningSeparation);
        ScrollBarModulePanSeperation.setCurValue(Module.PanningSeparation);

        CheckBoxPitchCutOff.caption:= 'Pitch Cutoff ' + numstr(Module.instruments[CurrentInstrument].DefaultFilterCutoff);
        CheckBoxPitchCutOff.isChecked:= module.instruments[CurrentInstrument].DefaultFilterCutoffEnabled;
        ScrollBarPitchCuffOff.setCurValue(Module.instruments[CurrentInstrument].DefaultFilterCutoff);
        CheckBoxPitchResonance.isChecked:= Module.instruments[CurrentInstrument].DefaultFilterQFactorEnabled;

        
        TextFieldPanCenter.caption:= 'Center ' + NoteValueTo3Str(Module.instruments[CurrentInstrument].PitchPanCenter);





        RadioButtonGroupNewNoteAction.uncheckAll;
        if Module.instruments[CurrentInstrument].NewNoteAction = nnaCut then RadioButtonNewNoteActionNoteCut.checked:= true;
        if Module.instruments[CurrentInstrument].NewNoteAction = nnaContinue then RadioButtonNewNoteActionNoteContinue.checked:= true;
        if Module.instruments[CurrentInstrument].NewNoteAction = nnaOff then RadioButtonNewNoteActionNoteOff.checked:= true;
        if Module.instruments[CurrentInstrument].NewNoteAction = nnaFade then RadioButtonNewNoteActionNoteFade.checked:= true;


        RadioButtonGroupDuplicateCheckType.uncheckAll;
        if Module.instruments[CurrentInstrument].DuplicateNoteCheck = dncOff then RadioButtonDuplicateCheckTypeDisabled.checked:= true;
        if Module.instruments[CurrentInstrument].DuplicateNoteCheck = dncNote then RadioButtonDuplicateCheckTypeNote.checked:= true;
        if Module.instruments[CurrentInstrument].DuplicateNoteCheck = dncSample then RadioButtonDuplicateCheckTypeSample.checked:= true;
        if Module.instruments[CurrentInstrument].DuplicateNoteCheck = dncInstrument then RadioButtonDuplicateCheckTypeInstrument.checked:= true;

        RadioButtonGroupDuplicateCheckAction.uncheckAll;
        if Module.instruments[CurrentInstrument].DuplicateCheckAction = dcaCut then RadioButtonDuplicateCheckActionNoteCut.checked:= true;
        if Module.instruments[CurrentInstrument].DuplicateCheckAction = dcaOff then RadioButtonDuplicateCheckActionNoteOff.checked:= true;
        if Module.instruments[CurrentInstrument].DuplicateCheckAction = dcaFade then RadioButtonDuplicateCheckActionNoteFade.checked:= true;


    tralalaEngine.UnLock_ReadOnly;

end;




procedure TInstrumentEditor.execProcScrollBarGlobalVolume(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].GlobalVolume:= ScrollBarGlobalVolume.curValue;
        TextFiledGlobalVolume.caption:= 'Global Volume ' + numstr(ScrollBarGlobalVolume.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;

end;




procedure TInstrumentEditor.execProcScrollBarDefaultVolume(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].DefaultVolume:= ScrollBarDefaultVolume.curValue;
        TextFiledDefaultVolume.caption:= 'Default Volume ' + numstr(ScrollBarDefaultVolume.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcScrollBarVolumeSwing(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.Instruments[CurrentSample].RandomVolumeSwing:= strnum(param);
    tralalaEngine.Unlock_Module_ReadWrite;

    TextFieldVolumeSwing.caption:='Volume Swing ' + param + '%';

end;


procedure TInstrumentEditor.execProcScrollBarFadeOut(const param: string);
begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].FadeOut:= ScrollBarFadeOut.curValue;
        TextFiledFadeOut.caption:= 'Fade Out ' + numstr(ScrollBarFadeOut.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;      

end;


procedure TInstrumentEditor.execProcScrollBarPanning(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DefaultPan:= strnum(param);
        CheckBoxPanning.caption:= 'Panning ' + param;
    tralalaEngine.Unlock_Module_ReadWrite;       

end;


procedure TInstrumentEditor.execProcCheckBoxPanning(const param: string);
begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DefaultPanEnabled:= CheckBoxPanning.isChecked;
    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.execProcScrollBarPanSeparation(const param: string);
begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.Instruments[CurrentSample].PitchPanSeparation:= strnum(param) - 32;
    tralalaEngine.Unlock_Module_ReadWrite;

    TextFieldPanSeparation.caption:= 'Pan Separation ' + numstr(strnum(param) - 32);

end; 



procedure TInstrumentEditor.execProcScrollBarPanSwing(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.Instruments[CurrentSample].RandomPanningSwing:= strnum(param);
    tralalaEngine.Unlock_Module_ReadWrite;

    TextFieldPanSwing.caption:= 'Pan Swing ' + param;
end;


procedure TInstrumentEditor.enableVolumePanel;
begin

    ScrollBarGlobalVolume.enabled:= true;
    TextFiledGlobalVolume.enabled:= true;
    ScrollBarDefaultVolume.enabled:= true;
    TextFiledDefaultVolume.enabled:= true;
    ScrollBarVolumeSwing.enabled:= true;
    TextFieldVolumeSwing.enabled:= true;
    ScrollBarFadeOut.enabled:= true;
    TextFiledFadeOut.enabled:= true;

end;


procedure TInstrumentEditor.disableVolumePanel;
begin

    ScrollBarGlobalVolume.enabled:= false;
    TextFiledGlobalVolume.enabled:= false;
    ScrollBarDefaultVolume.enabled:= false;
    TextFiledDefaultVolume.enabled:= false;
    ScrollBarVolumeSwing.enabled:= false;
    TextFieldVolumeSwing.enabled:= false;
    ScrollBarFadeOut.enabled:= false;
    TextFiledFadeOut.enabled:= false;

end;


procedure TInstrumentEditor.enablePanningPanel;
begin
    ScrollBarModulePanSeperation.enabled:= true;
    TextFieldModulePanSeperation.enabled:= true;
    ScrollBarPanning.enabled:= true;
    CheckBoxPanning.enabled:= true;
    ScrollBarPanSeparation.enabled:= true;
    TextFieldPanSeparation.enabled:= true;
    ScrollBarPanSwing.enabled:= true;
    TextFieldPanSwing.enabled:= true;
    ButtonUPPanCenter.enabled:= true;
    ButtonDOWNPanCenter.enabled:= true;
    TextFieldPanCenter.enabled:= true;
end;


procedure TInstrumentEditor.disablePanningPanel;
begin
    ScrollBarModulePanSeperation.enabled:= false;
    TextFieldModulePanSeperation.enabled:= false;
    ScrollBarPanning.enabled:= false;
    CheckBoxPanning.enabled:= false;
    ScrollBarPanSeparation.enabled:= false;
    TextFieldPanSeparation.enabled:= false;
    ScrollBarPanSwing.enabled:= false;
    TextFieldPanSwing.enabled:= false;
    ButtonUPPanCenter.enabled:= false;
    ButtonDOWNPanCenter.enabled:= false;
    TextFieldPanCenter.enabled:= false;
end;


procedure TInstrumentEditor.enablePitchPanel;
begin
    CheckBoxPitchCutOff.enabled:= true;
    ScrollBarPitchCuffOff.enabled:= true;
    CheckBoxPitchResonance.enabled:= true;
    ScrollBarPitchResonance.enabled:= true;
    ScrollBarMIDIChannel.enabled:= true;
    TextFiledMIDIChannel.enabled:= true;
    ScrollBarMIDIProgram.enabled:= true;
    TextFiledMIDIProgram.enabled:= true;
    ScrollBarMIDIBankLo.enabled:= true;
    TextFiledMIDIBankLo.enabled:= true;
    ScrollBarMIDIBankHigh.enabled:= true;
    TextFiledMIDIBankHigh.enabled:= true;
end;


procedure TInstrumentEditor.disablePitchPanel;
begin
    CheckBoxPitchCutOff.enabled:= false;
    ScrollBarPitchCuffOff.enabled:= false;
    CheckBoxPitchResonance.enabled:= false;
    ScrollBarPitchResonance.enabled:= false;
    ScrollBarMIDIChannel.enabled:= false;
    TextFiledMIDIChannel.enabled:= false;
    ScrollBarMIDIProgram.enabled:= false;
    TextFiledMIDIProgram.enabled:= false;
    ScrollBarMIDIBankLo.enabled:= false;
    TextFiledMIDIBankLo.enabled:= false;
    ScrollBarMIDIBankHigh.enabled:= false;
    TextFiledMIDIBankHigh.enabled:= false;
end;


procedure TInstrumentEditor.enableMappingPanel;
begin
	enableMapping;
end;


procedure TInstrumentEditor.disableMappingPanel;
begin
	disableMapping;
end;


procedure TInstrumentEditor.doButtonVolumeEnvelope;
begin

    disableMappingPanel;
    enableEnvelopePanel;

    isInMapping:= false;

    buildVolumeEnvelope;

    enableVolumePanel;
    disablePanningPanel;
    disablePitchPanel;
    disableMappingPanel;

end;


procedure TInstrumentEditor.execProcButtonVolume(const param: string);
begin

    doButtonVolumeEnvelope;

    netSendButtonVolume;

end;


procedure TInstrumentEditor.doButtonPanningEnvelope;
begin
    
    disableMappingPanel;
    enableEnvelopePanel;

    isInMapping:= false;

    BuildPanningEnvelope;

    enablePanningPanel;
    disableVolumePanel;
    disablePitchPanel;
    disableMappingPanel;

end;


procedure TInstrumentEditor.execProcButtonPanning(const param: string);
begin
    
    doButtonPanningEnvelope;

    netSendButtonPanning;

end;


procedure TInstrumentEditor.doButtonPitchEnvelope;
begin

    disableMappingPanel;
    enableEnvelopePanel;

    isInMapping:= false;

    buildPitchEnvelope;

    enablePitchPanel;
    disableVolumePanel;
    disablePanningPanel;
    disableMappingPanel;

end;


procedure TInstrumentEditor.execProcButtonPitch(const param: string);
begin

    doButtonPitchEnvelope;

    netSendButtonPitch;

end;


procedure TInstrumentEditor.doButtonMapping;
begin

    disableEnvelopePanel;
    enableMappingPanel;
    reloadMapping;
    isInMapping:= true;

    enableMappingPanel;
    disableVolumePanel;
    disablePanningPanel;    
    disablePitchPanel;

end;

procedure TInstrumentEditor.execProcButtonMapping(const param: string);
begin
	
    doButtonMapping;

    netSendButtonMapping;

end;








procedure TInstrumentEditor.execProcScrollBarModulePanSeperation(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.PanningSeparation:= strnum(param);
    tralalaEngine.Unlock_Module_ReadWrite;

    TextFieldModulePanSeperation.caption:= 'Song Panning Seperation ' + param;
end;

   


procedure TInstrumentEditor.execProcButtonUPPanCenter(const param: string);
var 
    z : longint;

begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        z:= Module.instruments[CurrentInstrument].PitchPanCenter;
        inc(z);
        if z >= NoteMax then z:= noteMax;
        Module.instruments[CurrentInstrument].PitchPanCenter:= z;

        TextFieldPanCenter.caption:= 'Center ' + NoteValueTo3Str(Module.instruments[CurrentInstrument].PitchPanCenter);
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcButtonDOWNPanCenter(const param: string);
var 
    z : longint;    

begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        z:= Module.instruments[CurrentInstrument].PitchPanCenter;
        dec(z);
        if z <= noteMin then z:= noteMin;
        Module.instruments[CurrentInstrument].PitchPanCenter:= z;

        TextFieldPanCenter.caption:= 'Center ' + NoteValueTo3Str(Module.instruments[CurrentInstrument].PitchPanCenter);
    tralalaEngine.Unlock_Module_ReadWrite;
end;




procedure TInstrumentEditor.execProcCheckBoxPitchCutOff(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        module.instruments[CurrentInstrument].DefaultFilterCutoffEnabled:= CheckBoxPitchCutOff.isChecked;
    tralalaEngine.Unlock_Module_ReadWrite;
end;    



procedure TInstrumentEditor.execProcScrollBarPitchCuffOff(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        CheckBoxPitchCutOff.caption:= 'Pitch Cutoff ' + param;
        Module.instruments[CurrentInstrument].DefaultFilterCutoff:= strnum(param);
    tralalaEngine.Unlock_Module_ReadWrite;
end;




procedure TInstrumentEditor.execProcCheckBoxPitchResonance(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DefaultFilterQFactorEnabled:= CheckBoxPitchResonance.isChecked;
    tralalaEngine.Unlock_Module_ReadWrite;
end;    



procedure TInstrumentEditor.execProcScrollBarPitchResonance(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        CheckBoxPitchResonance.caption:= 'Pitch Resonance ' + param;
        Module.instruments[CurrentInstrument].DefaultFilterQFactor:= strnum(param);
    tralalaEngine.Unlock_Module_ReadWrite;
end; 



procedure TInstrumentEditor.execProcScrollBarMIDIChannel(const param: string);
begin
    TextFiledMIDIChannel.caption:= 'MIDI Channel ' + param;
end;


procedure TInstrumentEditor.execProcScrollBarMIDIProgram(const param: string);
begin
    TextFiledMIDIProgram.caption:= 'MIDI Program ' + param;
end;


procedure TInstrumentEditor.execProcScrollBarMIDIBankLo(const param: string);
begin
    TextFiledMIDIBankLo.caption:= 'MIDI Bank Lo ' + param;
end;


procedure TInstrumentEditor.execProcScrollBarMIDIBankHigh(const param: string);
begin
    TextFiledMIDIBankHigh.caption:= 'MIDI Bank High ' + param;
end;