procedure TInstrumentEditor.BuildEnvelopePanel;
begin

	EnvelopePanel:= TtuiBox.create(InstrumentEditorTUI, 116, 632 - 200, 827, 200, 'EnvelopePanel', tuiBoxStatic);
    EnvelopePanel.ThemeBox:= LoadThemeBox;
    EnvelopePanel.ThemeBox.BackgroundColor:= Theme_InstrumentEditor_MainPanel_BackgroundColor;
    InstrumentEditorTUI.addBox(EnvelopePanel);

    EnvelopeCheckBoxVolume:= TtuiCheckBox.Create(EnvelopePanel,'EnvelopeCheckBoxVolume', 0, 5, 120, 24, 'Volume envelope', @execProcEnvelopeCheckBoxVolume);
    EnvelopeCheckBoxVolume.theme:= LoadThemeCheckBox;    
    EnvelopeCheckBoxVolume.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxVolume.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxVolume.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    EnvelopeCheckBoxVolume.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxVolume);

    EnvelopeCheckBoxPanning:= TtuiCheckBox.Create(EnvelopePanel, 'EnvelopeCheckBoxPanning', 0, 5, 120, 24, 'Panning envelope', @execProcEnvelopeCheckBoxPanning);
    EnvelopeCheckBoxPanning.theme:= LoadThemeCheckBox;    
    EnvelopeCheckBoxPanning.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxPanning.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxPanning.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    EnvelopeCheckBoxPanning.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxPanning);

    EnvelopeCheckBoxPitch:= TtuiCheckBox.Create(EnvelopePanel, 'EnvelopeCheckBoxPitch', 0, 5, 120, 24, 'Pitch envelope', @execProcEnvelopeCheckBoxPitch);
    EnvelopeCheckBoxPitch.theme:= LoadThemeCheckBox;    
    EnvelopeCheckBoxPitch.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxPitch.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxPitch.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    EnvelopeCheckBoxPitch.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxPitch);


    allocImage(EnvelopeImage, 328 * 2, 68 * 2);
    fastfill(EnvelopeImage.data, EnvelopeImage.width * EnvelopeImage.height, $ff000000);
    EnvelopeSelectableImage:= TtuiSelectableImage.create(EnvelopePanel, 'EnvelopeSelectableImage', 1, 28, EnvelopeImage, nil);
    EnvelopeSelectableImage.theme:= LoadThemeSelectableImage;
    EnvelopePanel.addItem(EnvelopeSelectableImage);

    EnvelopePreDefButton1:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton1', 328 * 2 - 26 - 26 - 26 - 26 - 26 - 26 - 5, 6, 26, 16, '1', @EnvelopePreDefButton1LeftClick);
    EnvelopePreDefButton1.applyYcorrection(3); 
    EnvelopePreDefButton1.execProcRightClick:= @EnvelopePreDefButton1RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton1);

    EnvelopePreDefButton2:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton2', 328 * 2 - 26 - 26 - 26 - 26 - 26 - 4, 6, 26, 16, '2', @EnvelopePreDefButton2LeftClick);
    EnvelopePreDefButton2.applyYcorrection(3);
    EnvelopePreDefButton2.execProcRightClick:= @EnvelopePreDefButton2RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton2);

    EnvelopePreDefButton3:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton3', 328 * 2 - 26 - 26 - 26 - 26 - 3, 6, 26, 16, '3', @EnvelopePreDefButton3LeftClick);
    EnvelopePreDefButton3.applyYcorrection(4);
    EnvelopePreDefButton3.execProcRightClick:= @EnvelopePreDefButton3RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton3);

    EnvelopePreDefButton4:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton4', 328 * 2 - 26 - 26 - 26 - 2, 6, 26, 16, '4', @EnvelopePreDefButton4LeftClick);
    EnvelopePreDefButton4.applyYcorrection(4);
    EnvelopePreDefButton4.execProcRightClick:= @EnvelopePreDefButton4RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton4);

    EnvelopePreDefButton5:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton5', 328 * 2 - 26 - 26 - 1, 6, 26, 16, '5', @EnvelopePreDefButton5LeftClick);
    EnvelopePreDefButton5.applyYcorrection(4);
    EnvelopePreDefButton5.execProcRightClick:= @EnvelopePreDefButton5RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton5);

    EnvelopePreDefButton6:= TtuiButton.create(EnvelopePanel, 'EnvelopePreDefButton6', 328 * 2 - 26, 6, 26, 16, '6', @EnvelopePreDefButton6LeftClick);
    EnvelopePreDefButton6.execProcRightClick:= @EnvelopePreDefButton6RightClick;
    EnvelopePanel.addItem(EnvelopePreDefButton6);
    
    
    EnvelopeAddButton:= TtuiButton.create(EnvelopePanel, 'EnvelopeAddButton', 340 * 2, 6, 64, 24, 'Add', @execProcEnvlopeAddButton);
    EnvelopePanel.addItem(EnvelopeAddButton);

    EnvelopeDelButton:= TtuiButton.create(EnvelopePanel, 'EnvelopeDelButton', 340 * 2 + 64 + 4, 6, 64, 24, 'Del', @execProcEnvlopeDelButton);
    EnvelopePanel.addItem(EnvelopeDelButton);


    EnvelopeCheckBoxSustain:= TtuiCheckBox.Create(EnvelopePanel, 'EnvelopeCheckBoxSustain', 333 * 2 + 6, 36, 120, 24, 'Sustain:', @execProcEnvelopeCheckBoxSustain);
    EnvelopeCheckBoxSustain.theme:= LoadThemeCheckBox;
    EnvelopeCheckBoxSustain.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxSustain.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxSustain.theme.SelectedColor:= Theme_InstrumentEditor_SelectFontColor;
    EnvelopeCheckBoxSustain.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxSustain);

    EnvelopeTextFieldSustainPointBegin:= TtuiTextField.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointBegin', 340 * 2, 60, 'Start 0');
    EnvelopeTextFieldSustainPointBegin.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointBegin);

    EnvelopeTextFieldSustainPointBeginButtonUP:= TtuiButtonUP.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointBeginButtonUP', 340 * 2 + 64 + 4 + 45 + 1 - 19, 58, @execProcEnvelopeSustainPointBeginButtonUP);
    EnvelopeTextFieldSustainPointBeginButtonUP.theme:= LoadThemeButtonUP;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointBeginButtonUP);

    EnvelopeTextFieldSustainPointBeginButtonDOWN:= TtuiButtonDOWN.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointBeginButtonDOWN', 340 * 2 + 64 + 4 + 45 + 1, 58, @execProcEnvelopeSustainPointBeginButtonDOWN);
    EnvelopeTextFieldSustainPointBeginButtonDOWN.theme:= LoadThemeButtonDOWN;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointBeginButtonDOWN);

    EnvelopeTextFieldSustainPointEnd:= TtuiTextField.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointEnd', 340 * 2, 80, 'End 0');
    EnvelopeTextFieldSustainPointEnd.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointEnd);

    EnvelopeTextFieldSustainPointEndButtonUP:= TtuiButtonUP.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointEndButtonUP', 340 * 2 + 64 + 4 + 45 + 1 - 19, 80 - 3, @execProcEnvelopeSustainPointEndButtonUP);
    EnvelopeTextFieldSustainPointEndButtonUP.theme:= LoadThemeButtonUP;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointEndButtonUP);

    EnvelopeTextFieldSustainPointEndButtonDOWN:= TtuiButtonDOWN.Create(EnvelopePanel, 'EnvelopeTextFieldSustainPointEndButtonDOWN', 340 * 2 + 64 + 4 + 45 + 1, 80 - 3, @execProcEnvelopeSustainPointEndButtonDOWN);
    EnvelopeTextFieldSustainPointEndButtonDOWN.theme:= LoadThemeButtonDOWN;
    EnvelopePanel.addItem(EnvelopeTextFieldSustainPointEndButtonDOWN);


    EnvelopeCheckBoxLoop:= TtuiCheckBox.Create(EnvelopePanel, 'EnvelopeCheckBoxLoop', 333 * 2 + 6, 80 + 20, 120, 24, 'Env.loop:', @execProcEnvelopeCheckBoxLoop);
    EnvelopeCheckBoxLoop.theme:= LoadThemeCheckBox;
    EnvelopeCheckBoxLoop.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxLoop.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxLoop.theme.SelectedColor:= Theme_InstrumentEditor_SelectFontColor;
    EnvelopeCheckBoxLoop.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxLoop);

    EnvelopeTextFieldLoopStart:= TtuiTextField.Create(EnvelopePanel, 'EnvelopeTextFieldLoopStart', 340 * 2, 104 + 20, 'Start 0');
    EnvelopeTextFieldLoopStart.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopePanel.addItem(EnvelopeTextFieldLoopStart);

    EnvelopeEnvelopeLoopStartButtonUP:= TtuiButtonUP.Create(EnvelopePanel, 'EnvelopeEnvelopeLoopStartButtonUP', 340 * 2 + 64 + 4 + 45 + 1 - 19, 103 + 20, @execProcEnvelopeLoopPointBeginButtonUP);
    EnvelopeEnvelopeLoopStartButtonUP.theme:= LoadThemeButtonUP;
    EnvelopePanel.addItem(EnvelopeEnvelopeLoopStartButtonUP);

    EnvelopeEnvelopeLoopStartButtonDOWN:= TtuiButtonDOWN.Create(EnvelopePanel, 'EnvelopeEnvelopeLoopStartButtonDOWN', 340 * 2 + 64 + 4 + 45 + 1, 103 + 20, @execProcEnvelopeLoopPointBeginButtonDOWN);
    EnvelopeEnvelopeLoopStartButtonDOWN.theme:= LoadThemeButtonDOWN;
    EnvelopePanel.addItem(EnvelopeEnvelopeLoopStartButtonDOWN);

    EnvelopeTextFieldLoopEnd:= TtuiTextField.Create(EnvelopePanel, 'EnvelopeTextFieldLoopEnd', 340 * 2, 124 + 20, 'End 0');
    EnvelopeTextFieldLoopEnd.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopePanel.addItem(EnvelopeTextFieldLoopEnd);

    EnvelopeEnvelopeLoopEndButtonUP:= TtuiButtonUP.Create(EnvelopePanel, 'EnvelopeEnvelopeLoopEndButtonUP', 340 * 2 + 64 + 4 + 45 + 1 - 19, 122 + 20, @execProcEnvelopeLoopPointEndButtonUP);
    EnvelopeEnvelopeLoopEndButtonUP.theme:= LoadThemeButtonUP;
    EnvelopePanel.addItem(EnvelopeEnvelopeLoopEndButtonUP);

    EnvelopeEnvelopeLoopEndButtonDOWN:= TtuiButtonDOWN.Create(EnvelopePanel, 'EnvelopeEnvelopeLoopEndButtonDOWN', 340 * 2 + 64 + 4 + 45 + 1, 122 + 20, @execProcEnvelopeLoopPointEndButtonDOWN);
    EnvelopeEnvelopeLoopEndButtonDOWN.theme:= LoadThemeButtonDOWN;
    EnvelopePanel.addItem(EnvelopeEnvelopeLoopEndButtonDOWN);

    
    EnvelopeCheckBoxCarry:= TtuiCheckBox.Create(EnvelopePanel, 'EnvelopeCheckBoxCarry', 333 * 2 + 6, 170, 120, 24, 'Carry', @execProcEnvelopeCheckBoxCarry);
    EnvelopeCheckBoxCarry.theme:= LoadThemeCheckBox;    
    EnvelopeCheckBoxCarry.theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxCarry.theme.CheckBoxColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    EnvelopeCheckBoxCarry.theme.SelectedColor:= Theme_Tracker_MainPanel_SelectFontColor;
    EnvelopeCheckBoxCarry.isChecked:= false;
    EnvelopePanel.addItem(EnvelopeCheckBoxCarry);


    currentNode:= 0;

end; 

procedure TInstrumentEditor.buildEnvelopeNodes;
begin

    setlength(EnvelopePreDefButton1VolumeNodes, 6);
    EnvelopePreDefButton1VolumeNodes[0].x:= 0;
    EnvelopePreDefButton1VolumeNodes[0].y:= 48;
    EnvelopePreDefButton1VolumeNodes[1].x:= 4;
    EnvelopePreDefButton1VolumeNodes[1].y:= 64;
    EnvelopePreDefButton1VolumeNodes[2].x:= 8;
    EnvelopePreDefButton1VolumeNodes[2].y:= 44;
    EnvelopePreDefButton1VolumeNodes[3].x:= 14;
    EnvelopePreDefButton1VolumeNodes[3].y:= 8;
    EnvelopePreDefButton1VolumeNodes[4].x:= 24;
    EnvelopePreDefButton1VolumeNodes[4].y:= 22;
    EnvelopePreDefButton1VolumeNodes[5].x:= 32;
    EnvelopePreDefButton1VolumeNodes[5].y:= 8;
    EnvelopePreDefButton1VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton1VolumeSustainLoopEnd:= 0;
    EnvelopePreDefButton1VolumeLoopStart:= 0;
    EnvelopePreDefButton1VolumeLoopEnd:= 0;
    EnvelopePreDefButton1VolumeSustainLoop:= false;
    EnvelopePreDefButton1VolumeLoop:= false;

    setlength(EnvelopePreDefButton1PanningNodes, 6);
    EnvelopePreDefButton1PanningNodes[0].x:= 0;
    EnvelopePreDefButton1PanningNodes[0].y:= 0;
    EnvelopePreDefButton1PanningNodes[1].x:= 10;
    EnvelopePreDefButton1PanningNodes[1].y:= 8;
    EnvelopePreDefButton1PanningNodes[2].x:= 30;
    EnvelopePreDefButton1PanningNodes[2].y:= -8;
    EnvelopePreDefButton1PanningNodes[3].x:= 50;
    EnvelopePreDefButton1PanningNodes[3].y:= 0;
    EnvelopePreDefButton1PanningNodes[4].x:= 60;
    EnvelopePreDefButton1PanningNodes[4].y:= 0;
    EnvelopePreDefButton1PanningNodes[5].x:= 70;
    EnvelopePreDefButton1PanningNodes[5].y:= 0;
    EnvelopePreDefButton1PanningSustainLoopStart:= 0;
    EnvelopePreDefButton1PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton1PanningLoopStart:= 0;
    EnvelopePreDefButton1PanningLoopEnd:= 0;
    EnvelopePreDefButton1PanningSustainLoop:= false;
    EnvelopePreDefButton1PanningLoop:= false;

    setlength(EnvelopePreDefButton1PitchNodes, 2);
    EnvelopePreDefButton1PitchNodes[0].x:= 0;
    EnvelopePreDefButton1PitchNodes[0].y:= 0;
    EnvelopePreDefButton1PitchNodes[1].x:= 64;
    EnvelopePreDefButton1PitchNodes[1].y:= 0;
    EnvelopePreDefButton1PitchSustainLoopStart:= 0;
    EnvelopePreDefButton1PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton1PitchLoopStart:= 0;
    EnvelopePreDefButton1PitchLoopEnd:= 0;
    EnvelopePreDefButton1PitchSustainLoop:= false;
    EnvelopePreDefButton1PitchLoop:= false;

    setlength(EnvelopePreDefButton2VolumeNodes, 6);
    EnvelopePreDefButton2VolumeNodes[0].x:= 0;
    EnvelopePreDefButton2VolumeNodes[0].y:= 48;
    EnvelopePreDefButton2VolumeNodes[1].x:= 4;
    EnvelopePreDefButton2VolumeNodes[1].y:= 64;
    EnvelopePreDefButton2VolumeNodes[2].x:= 8;
    EnvelopePreDefButton2VolumeNodes[2].y:= 44;
    EnvelopePreDefButton2VolumeNodes[3].x:= 14;
    EnvelopePreDefButton2VolumeNodes[3].y:= 8;
    EnvelopePreDefButton2VolumeNodes[4].x:= 24;
    EnvelopePreDefButton2VolumeNodes[4].y:= 22;
    EnvelopePreDefButton2VolumeNodes[5].x:= 32;
    EnvelopePreDefButton2VolumeNodes[5].y:= 8;
    EnvelopePreDefButton2VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton2VolumeSustainLoopEnd:= 2;
    EnvelopePreDefButton2VolumeLoopStart:= 3;
    EnvelopePreDefButton2VolumeLoopEnd:= 5;
    EnvelopePreDefButton2VolumeSustainLoop:= true;
    EnvelopePreDefButton2VolumeLoop:= true;

    setlength(EnvelopePreDefButton2PanningNodes, 6);
    EnvelopePreDefButton2PanningNodes[0].x:= 0;
    EnvelopePreDefButton2PanningNodes[0].y:= 0;
    EnvelopePreDefButton2PanningNodes[1].x:= 10;
    EnvelopePreDefButton2PanningNodes[1].y:= 8;
    EnvelopePreDefButton2PanningNodes[2].x:= 30;
    EnvelopePreDefButton2PanningNodes[2].y:= -8;
    EnvelopePreDefButton2PanningNodes[3].x:= 50;
    EnvelopePreDefButton2PanningNodes[3].y:= 0;
    EnvelopePreDefButton2PanningNodes[4].x:= 60;
    EnvelopePreDefButton2PanningNodes[4].y:= 0;
    EnvelopePreDefButton2PanningNodes[5].x:= 70;
    EnvelopePreDefButton2PanningNodes[5].y:= 0;
    EnvelopePreDefButton2PanningSustainLoopStart:= 0;
    EnvelopePreDefButton2PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton2PanningLoopStart:= 0;
    EnvelopePreDefButton2PanningLoopEnd:= 0;
    EnvelopePreDefButton2PanningSustainLoop:= false;
    EnvelopePreDefButton2PanningLoop:= false;

    setlength(EnvelopePreDefButton2PitchNodes, 2);
    EnvelopePreDefButton2PitchNodes[0].x:= 0;
    EnvelopePreDefButton2PitchNodes[0].y:= 0;
    EnvelopePreDefButton2PitchNodes[1].x:= 64;
    EnvelopePreDefButton2PitchNodes[1].y:= 0;
    EnvelopePreDefButton2PitchSustainLoopStart:= 0;
    EnvelopePreDefButton2PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton2PitchLoopStart:= 0;
    EnvelopePreDefButton2PitchLoopEnd:= 0;
    EnvelopePreDefButton2PitchSustainLoop:= false;
    EnvelopePreDefButton2PitchLoop:= false;

    setlength(EnvelopePreDefButton3VolumeNodes, 6);
    EnvelopePreDefButton3VolumeNodes[0].x:= 0;
    EnvelopePreDefButton3VolumeNodes[0].y:= 48;
    EnvelopePreDefButton3VolumeNodes[1].x:= 4;
    EnvelopePreDefButton3VolumeNodes[1].y:= 64;
    EnvelopePreDefButton3VolumeNodes[2].x:= 8;
    EnvelopePreDefButton3VolumeNodes[2].y:= 44;
    EnvelopePreDefButton3VolumeNodes[3].x:= 14;
    EnvelopePreDefButton3VolumeNodes[3].y:= 8;
    EnvelopePreDefButton3VolumeNodes[4].x:= 24;
    EnvelopePreDefButton3VolumeNodes[4].y:= 22;
    EnvelopePreDefButton3VolumeNodes[5].x:= 172;
    EnvelopePreDefButton3VolumeNodes[5].y:= 52;
    EnvelopePreDefButton3VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton3VolumeSustainLoopEnd:= 2;
    EnvelopePreDefButton3VolumeLoopStart:= 3;
    EnvelopePreDefButton3VolumeLoopEnd:= 5;
    EnvelopePreDefButton3VolumeSustainLoop:= true;
    EnvelopePreDefButton3VolumeLoop:= true;

    setlength(EnvelopePreDefButton3PanningNodes, 6);
    EnvelopePreDefButton3PanningNodes[0].x:= 0;
    EnvelopePreDefButton3PanningNodes[0].y:= 0;
    EnvelopePreDefButton3PanningNodes[1].x:= 10;
    EnvelopePreDefButton3PanningNodes[1].y:= 8;
    EnvelopePreDefButton3PanningNodes[2].x:= 30;
    EnvelopePreDefButton3PanningNodes[2].y:= -8;
    EnvelopePreDefButton3PanningNodes[3].x:= 50;
    EnvelopePreDefButton3PanningNodes[3].y:= 0;
    EnvelopePreDefButton3PanningNodes[4].x:= 60;
    EnvelopePreDefButton3PanningNodes[4].y:= 0;
    EnvelopePreDefButton3PanningNodes[5].x:= 70;
    EnvelopePreDefButton3PanningNodes[5].y:= 0;
    EnvelopePreDefButton3PanningSustainLoopStart:= 0;
    EnvelopePreDefButton3PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton3PanningLoopStart:= 0;
    EnvelopePreDefButton3PanningLoopEnd:= 0;
    EnvelopePreDefButton3PanningSustainLoop:= false;
    EnvelopePreDefButton3PanningLoop:= false;

    setlength(EnvelopePreDefButton3PitchNodes, 2);
    EnvelopePreDefButton3PitchNodes[0].x:= 0;
    EnvelopePreDefButton3PitchNodes[0].y:= 0;
    EnvelopePreDefButton3PitchNodes[1].x:= 64;
    EnvelopePreDefButton3PitchNodes[1].y:= 0;
    EnvelopePreDefButton3PitchSustainLoopStart:= 0;
    EnvelopePreDefButton3PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton3PitchLoopStart:= 0;
    EnvelopePreDefButton3PitchLoopEnd:= 0;
    EnvelopePreDefButton3PitchSustainLoop:= false;
    EnvelopePreDefButton3PitchLoop:= false;

    setlength(EnvelopePreDefButton4VolumeNodes, 6);
    EnvelopePreDefButton4VolumeNodes[0].x:= 0;
    EnvelopePreDefButton4VolumeNodes[0].y:= 48;
    EnvelopePreDefButton4VolumeNodes[1].x:= 4;
    EnvelopePreDefButton4VolumeNodes[1].y:= 64;
    EnvelopePreDefButton4VolumeNodes[2].x:= 8;
    EnvelopePreDefButton4VolumeNodes[2].y:= 44;
    EnvelopePreDefButton4VolumeNodes[3].x:= 14;
    EnvelopePreDefButton4VolumeNodes[3].y:= 8;
    EnvelopePreDefButton4VolumeNodes[4].x:= 24;
    EnvelopePreDefButton4VolumeNodes[4].y:= 22;
    EnvelopePreDefButton4VolumeNodes[5].x:= 32;
    EnvelopePreDefButton4VolumeNodes[5].y:= 8;
    EnvelopePreDefButton4VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton4VolumeSustainLoopEnd:= 2;
    EnvelopePreDefButton4VolumeLoopStart:= 3;
    EnvelopePreDefButton4VolumeLoopEnd:= 5;
    EnvelopePreDefButton4VolumeSustainLoop:= true;
    EnvelopePreDefButton4VolumeLoop:= true;

    setlength(EnvelopePreDefButton4PanningNodes, 6);
    EnvelopePreDefButton4PanningNodes[0].x:= 0;
    EnvelopePreDefButton4PanningNodes[0].y:= 0;
    EnvelopePreDefButton4PanningNodes[1].x:= 10;
    EnvelopePreDefButton4PanningNodes[1].y:= 8;
    EnvelopePreDefButton4PanningNodes[2].x:= 30;
    EnvelopePreDefButton4PanningNodes[2].y:= -8;
    EnvelopePreDefButton4PanningNodes[3].x:= 50;
    EnvelopePreDefButton4PanningNodes[3].y:= 0;
    EnvelopePreDefButton4PanningNodes[4].x:= 60;
    EnvelopePreDefButton4PanningNodes[4].y:= 0;
    EnvelopePreDefButton4PanningNodes[5].x:= 70;
    EnvelopePreDefButton4PanningNodes[5].y:= 0;
    EnvelopePreDefButton4PanningSustainLoopStart:= 0;
    EnvelopePreDefButton4PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton4PanningLoopStart:= 0;
    EnvelopePreDefButton4PanningLoopEnd:= 0;
    EnvelopePreDefButton4PanningSustainLoop:= false;
    EnvelopePreDefButton4PanningLoop:= false;

    setlength(EnvelopePreDefButton4PitchNodes, 2);
    EnvelopePreDefButton4PitchNodes[0].x:= 0;
    EnvelopePreDefButton4PitchNodes[0].y:= 0;
    EnvelopePreDefButton4PitchNodes[1].x:= 64;
    EnvelopePreDefButton4PitchNodes[1].y:= 0;
    EnvelopePreDefButton4PitchSustainLoopStart:= 0;
    EnvelopePreDefButton4PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton4PitchLoopStart:= 0;
    EnvelopePreDefButton4PitchLoopEnd:= 0;
    EnvelopePreDefButton4PitchSustainLoop:= false;
    EnvelopePreDefButton4PitchLoop:= false;

    setlength(EnvelopePreDefButton5VolumeNodes, 6);
    EnvelopePreDefButton5VolumeNodes[0].x:= 0;
    EnvelopePreDefButton5VolumeNodes[0].y:= 48;
    EnvelopePreDefButton5VolumeNodes[1].x:= 4;
    EnvelopePreDefButton5VolumeNodes[1].y:= 64;
    EnvelopePreDefButton5VolumeNodes[2].x:= 8;
    EnvelopePreDefButton5VolumeNodes[2].y:= 44;
    EnvelopePreDefButton5VolumeNodes[3].x:= 14;
    EnvelopePreDefButton5VolumeNodes[3].y:= 8;
    EnvelopePreDefButton5VolumeNodes[4].x:= 24;
    EnvelopePreDefButton5VolumeNodes[4].y:= 22;
    EnvelopePreDefButton5VolumeNodes[5].x:= 32;
    EnvelopePreDefButton5VolumeNodes[5].y:= 8;
    EnvelopePreDefButton5VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton5VolumeSustainLoopEnd:= 2;
    EnvelopePreDefButton5VolumeLoopStart:= 3;
    EnvelopePreDefButton5VolumeLoopEnd:= 5;
    EnvelopePreDefButton5VolumeSustainLoop:= true;
    EnvelopePreDefButton5VolumeLoop:= true;

    setlength(EnvelopePreDefButton5PanningNodes, 6);
    EnvelopePreDefButton5PanningNodes[0].x:= 0;
    EnvelopePreDefButton5PanningNodes[0].y:= 0;
    EnvelopePreDefButton5PanningNodes[1].x:= 10;
    EnvelopePreDefButton5PanningNodes[1].y:= 8;
    EnvelopePreDefButton5PanningNodes[2].x:= 30;
    EnvelopePreDefButton5PanningNodes[2].y:= -8;
    EnvelopePreDefButton5PanningNodes[3].x:= 50;
    EnvelopePreDefButton5PanningNodes[3].y:= 0;
    EnvelopePreDefButton5PanningNodes[4].x:= 60;
    EnvelopePreDefButton5PanningNodes[4].y:= 0;
    EnvelopePreDefButton5PanningNodes[5].x:= 70;
    EnvelopePreDefButton5PanningNodes[5].y:= 0;
    EnvelopePreDefButton5PanningSustainLoopStart:= 0;
    EnvelopePreDefButton5PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton5PanningLoopStart:= 0;
    EnvelopePreDefButton5PanningLoopEnd:= 0;
    EnvelopePreDefButton5PanningSustainLoop:= false;
    EnvelopePreDefButton5PanningLoop:= false;

    setlength(EnvelopePreDefButton5PitchNodes, 2);
    EnvelopePreDefButton5PitchNodes[0].x:= 0;
    EnvelopePreDefButton5PitchNodes[0].y:= 0;
    EnvelopePreDefButton5PitchNodes[1].x:= 64;
    EnvelopePreDefButton5PitchNodes[1].y:= 0;
    EnvelopePreDefButton5PitchSustainLoopStart:= 0;
    EnvelopePreDefButton5PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton5PitchLoopStart:= 0;
    EnvelopePreDefButton5PitchLoopEnd:= 0;
    EnvelopePreDefButton5PitchSustainLoop:= false;
    EnvelopePreDefButton5PitchLoop:= false;

    setlength(EnvelopePreDefButton6VolumeNodes, 7);
    EnvelopePreDefButton6VolumeNodes[0].x:= 0;
    EnvelopePreDefButton6VolumeNodes[0].y:= 48;
    EnvelopePreDefButton6VolumeNodes[1].x:= 4;
    EnvelopePreDefButton6VolumeNodes[1].y:= 64;
    EnvelopePreDefButton6VolumeNodes[2].x:= 8;
    EnvelopePreDefButton6VolumeNodes[2].y:= 44;
    EnvelopePreDefButton6VolumeNodes[3].x:= 14;
    EnvelopePreDefButton6VolumeNodes[3].y:= 8;
    EnvelopePreDefButton6VolumeNodes[4].x:= 24;
    EnvelopePreDefButton6VolumeNodes[4].y:= 22;
    EnvelopePreDefButton6VolumeNodes[5].x:= 235;
    EnvelopePreDefButton6VolumeNodes[5].y:= 10;
    EnvelopePreDefButton6VolumeNodes[6].x:= 245;
    EnvelopePreDefButton6VolumeNodes[6].y:= 10;
    EnvelopePreDefButton6VolumeSustainLoopStart:= 0;
    EnvelopePreDefButton6VolumeSustainLoopEnd:= 2;
    EnvelopePreDefButton6VolumeLoopStart:= 3;
    EnvelopePreDefButton6VolumeLoopEnd:= 5;
    EnvelopePreDefButton6VolumeSustainLoop:= true;
    EnvelopePreDefButton6VolumeLoop:= true;

    setlength(EnvelopePreDefButton6PanningNodes, 6);
    EnvelopePreDefButton6PanningNodes[0].x:= 0;
    EnvelopePreDefButton6PanningNodes[0].y:= 0;
    EnvelopePreDefButton6PanningNodes[1].x:= 10;
    EnvelopePreDefButton6PanningNodes[1].y:= 8;
    EnvelopePreDefButton6PanningNodes[2].x:= 30;
    EnvelopePreDefButton6PanningNodes[2].y:= -8;
    EnvelopePreDefButton6PanningNodes[3].x:= 50;
    EnvelopePreDefButton6PanningNodes[3].y:= 0;
    EnvelopePreDefButton6PanningNodes[4].x:= 60;
    EnvelopePreDefButton6PanningNodes[4].y:= 0;
    EnvelopePreDefButton6PanningNodes[5].x:= 70;
    EnvelopePreDefButton6PanningNodes[5].y:= 0;
    EnvelopePreDefButton6PanningSustainLoopStart:= 0;
    EnvelopePreDefButton6PanningSustainLoopEnd:= 0;
    EnvelopePreDefButton6PanningLoopStart:= 0;
    EnvelopePreDefButton6PanningLoopEnd:= 0;
    EnvelopePreDefButton6PanningSustainLoop:= false;
    EnvelopePreDefButton6PanningLoop:= false;

    setlength(EnvelopePreDefButton6PitchNodes, 2);
    EnvelopePreDefButton6PitchNodes[0].x:= 0;
    EnvelopePreDefButton6PitchNodes[0].y:= 0;
    EnvelopePreDefButton6PitchNodes[1].x:= 64;
    EnvelopePreDefButton6PitchNodes[1].y:= 0;
    EnvelopePreDefButton6PitchSustainLoopStart:= 0;
    EnvelopePreDefButton6PitchSustainLoopEnd:= 0;
    EnvelopePreDefButton6PitchLoopStart:= 0;
    EnvelopePreDefButton6PitchLoopEnd:= 0;
    EnvelopePreDefButton6PitchSustainLoop:= false;
    EnvelopePreDefButton6PitchLoop:= false;

end;


procedure TInstrumentEditor.execProcEnvelopeCheckBoxVolume(const param: string);
var 
    flags : TEnvelopeFlags;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        flags:= Module.instruments[CurrentInstrument].VolumeEnvelope.flags;

        if EnvelopeCheckBoxVolume.isChecked = true then include(flags,efEnabled) else exclude(flags,efEnabled);

        Module.instruments[CurrentInstrument].VolumeEnvelope.flags:= flags;

    tralalaEngine.Unlock_Module_ReadWrite; 

end;


procedure TInstrumentEditor.execProcEnvelopeCheckBoxPanning(const param: string);
var 
    flags : TEnvelopeFlags;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        flags:= Module.instruments[CurrentInstrument].PanningEnvelope.flags;

        if EnvelopeCheckBoxPanning.isChecked = true then include(flags,efEnabled) else exclude(flags,efEnabled);
        
        Module.instruments[CurrentInstrument].PanningEnvelope.flags:= flags;

    tralalaEngine.Unlock_Module_ReadWrite; 

end;


procedure TInstrumentEditor.execProcEnvelopeCheckBoxPitch(const param: string);
var 
    flags : TEnvelopeFlags;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        flags:= Module.instruments[CurrentInstrument].PitchEnvelope.flags;

        if EnvelopeCheckBoxPitch.isChecked = true then include(flags,efEnabled) else exclude(flags,efEnabled);

        Module.instruments[CurrentInstrument].PitchEnvelope.flags:= flags;

    tralalaEngine.Unlock_Module_ReadWrite; 

end;


procedure TInstrumentEditor.buildVolumeEnvelope;
begin

    currentEnvelopMode:= 1;

    EnvelopeCheckBoxVolume.enabled:= true;
    EnvelopeCheckBoxPanning.enabled:= false;
    EnvelopeCheckBoxPitch.enabled:= false;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
        
        if efEnabled in Module.instruments[CurrentInstrument].VolumeEnvelope.flags then EnvelopeCheckBoxVolume.isChecked:= true else EnvelopeCheckBoxVolume.isChecked:= false;

        if Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType = esltNoLoop then EnvelopeCheckBoxSustain.isChecked:= false;
        if Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType = esltForwardLoop then EnvelopeCheckBoxSustain.isChecked:= true;

        if Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType = eltNoLoop then EnvelopeCheckBoxLoop.isChecked:= false;
        if Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType = eltForwardLoop then EnvelopeCheckBoxLoop.isChecked:= true;

        if efCarry in Module.instruments[CurrentInstrument].VolumeEnvelope.flags then EnvelopeCheckBoxCarry.isChecked:= true else EnvelopeCheckBoxCarry.isChecked:= false;

        EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
        EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

        EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
        EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.BuildPanningEnvelope;
begin

    currentEnvelopMode:= 2;

    EnvelopeCheckBoxVolume.enabled:= false;
    EnvelopeCheckBoxPanning.enabled:= true;
    EnvelopeCheckBoxPitch.enabled:= false;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType = esltNoLoop then EnvelopeCheckBoxSustain.isChecked:= false;
        if Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType = esltForwardLoop then EnvelopeCheckBoxSustain.isChecked:= true;

        if Module.instruments[CurrentInstrument].PanningEnvelope.LoopType = eltNoLoop then EnvelopeCheckBoxLoop.isChecked:= false;
        if Module.instruments[CurrentInstrument].PanningEnvelope.LoopType = eltForwardLoop then EnvelopeCheckBoxLoop.isChecked:= true;

        if efCarry in Module.instruments[CurrentInstrument].PanningEnvelope.flags then EnvelopeCheckBoxCarry.isChecked:= true else EnvelopeCheckBoxCarry.isChecked:= false;

        EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
        EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

        EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
        EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);
   
   tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.BuildPitchEnvelope;
begin

    currentEnvelopMode:= 3;

    EnvelopeCheckBoxVolume.enabled:= false;
    EnvelopeCheckBoxPanning.enabled:= false;
    EnvelopeCheckBoxPitch.enabled:= true;
   
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
   
        if Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType = esltNoLoop then EnvelopeCheckBoxSustain.isChecked:= false;
        if Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType = esltForwardLoop then EnvelopeCheckBoxSustain.isChecked:= true;
        
        if Module.instruments[CurrentInstrument].PitchEnvelope.LoopType = eltNoLoop then EnvelopeCheckBoxLoop.isChecked:= false;
        if Module.instruments[CurrentInstrument].PitchEnvelope.LoopType = eltForwardLoop then EnvelopeCheckBoxLoop.isChecked:= true;

        if efCarry in Module.instruments[CurrentInstrument].PitchEnvelope.flags then EnvelopeCheckBoxCarry.isChecked:= true else EnvelopeCheckBoxCarry.isChecked:= false;

        EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
        EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

        EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
        EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);
   
    tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.execProcEnvelopeCheckBoxSustain(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin
            if not EnvelopeCheckBoxSustain.isChecked then
                Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop
            else
                Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop;
        end;

        if currentEnvelopMode = 2 then begin
            if not EnvelopeCheckBoxSustain.isChecked then
                Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop
            else
                Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop;
        end;

        if currentEnvelopMode = 3 then begin
            if not EnvelopeCheckBoxSustain.isChecked then
                Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop
            else
                Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop;
        end;        

    tralalaEngine.Unlock_Module_ReadWrite;    

end;


procedure TInstrumentEditor.execProcEnvelopeCheckBoxLoop(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin
            if not EnvelopeCheckBoxLoop.isChecked then
                Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop
            else
                Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop;
        end;

        if currentEnvelopMode = 2 then begin
            if not EnvelopeCheckBoxLoop.isChecked then
                Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop
            else
                Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop;
        end;

        if currentEnvelopMode = 3 then begin
            if not EnvelopeCheckBoxLoop.isChecked then
                Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop
            else
                Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop;
        end;        

    tralalaEngine.Unlock_Module_ReadWrite;    

end;


procedure TInstrumentEditor.calculateNewNode(x1, y1, x2, y2: longint; var x, y: longint);
var
    count : Single;
    Xstep, Ystep : Single;
    xx,yy : single;
    i : longint;

begin
    xx:= 0;
    yy:= 0;
    {case 1 - nach Unten und nach Rechts}
    If (x2 >= x1) And (y2 >= y1) Then begin
         count:= ((x2 - x1) + (y2 - y1));

         Xstep:= (x2 - x1) / count;
         Ystep:= (y2 - y1) / count;

         for i:=0 to round(count / 2) do begin
            xx:= xx + Xstep;
            yy:= yy + Ystep;
         end;
    end;

    {case 4 - nach Oben und nach Rechts}
    If (x1 < x2) and (y1 > y2) then begin
        count:= ((x2 - x1) + (y1 - y2));

        Xstep:= (x2 - x1) / count;
        Ystep:= (y1 - y2) / count;

        For i:=0 to round(count / 2) do begin
            xx:= xx + Xstep;
            yy:= yy - Ystep;
        end;
    End;

    x:= round(x1 + xx);
    y:= round(y1 + yy);
    
end;


procedure TInstrumentEditor.execProcEnvlopeAddButton(const param:string);
label 
    skip;

var 
    aValue : TEnvelopeNode;
    x1, y1, x2, y2 : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if (currentNode + 1) <=  getNodeCount then begin

            x1:= getNodeX(currentNode);
            y1:= getNodeY(currentNode);
            x2:= getNodeX(currentNode + 1);
            y2:= getNodeY(currentNode + 1);

            calculateNewNode(x1, y1, x2, y2, aValue.x, aValue.y);
            if aValue.x = oldNodeX then begin
                goto skip;
            end;
            oldNodeX:= aValue.x;            

        end else begin
            
            aValue.x:= getNodeX(getNodeCount) + ((324 - getNodeX(getNodeCount)) div 2);
            if currentEnvelopMode = 1 then aValue.y:= 32;            
            if currentEnvelopMode = 2 then aValue.y:= 0;
            if currentEnvelopMode = 3 then aValue.y:= 0;
            
        end;

        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.InsertNode(aValue);
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.InsertNode(aValue);
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.InsertNode(aValue);

skip:
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcEnvlopeDelButton(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then 
            if (currentNode > 0) then begin
                if (Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount-1) > 1 then
                    Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(currentNode);

                if currentNode > (Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount-1) then dec(currentNode);
            end;

        if currentEnvelopMode = 2 then 
            if (currentNode > 0) then begin
                if (Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount-1) > 1 then
                    Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(currentNode);

                if currentNode > (Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount-1) then dec(currentNode);    
            end;

        if currentEnvelopMode = 3 then 
            if (currentNode > 0) then begin
                if (Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount-1) > 1 then
                    Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(currentNode);

                if currentNode > (Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount-1) then dec(currentNode);
            end;

    tralalaEngine.Unlock_Module_ReadWrite;    

end;



procedure TInstrumentEditor.drawXYscale;
var 
    x, y : longint;   

begin

    for y:= 0 to 32 do begin
        putpixel(EnvelopeImage, 4, y * 4, Theme_InstrumentEditor_EnvelopeColor);        
    end;
    for x:= 0 to (324 div 2) do begin
        putpixel(EnvelopeImage, x * 4, 64 * 2, Theme_InstrumentEditor_EnvelopeColor);
    end;

    if currentEnvelopMode = 2 then drawHLine(EnvelopeImage, 5, 324 * 2 - 4, 64, Theme_InstrumentEditor_EnvelopePanningLineColor);
    if currentEnvelopMode = 3 then drawHLine(EnvelopeImage, 5, 324 * 2 - 4, 64, Theme_InstrumentEditor_EnvelopePanningLineColor);

end;


procedure TInstrumentEditor.drawNodeToucher(x, y: longint; color: dword);
begin

    drawRectangleclip(EnvelopeImage, x - 4, y - 4, x + 4, y + 4, color);

end;

procedure TInstrumentEditor.drawXYtext;
var 
    sX, sY : string;
    z : longint;

begin

    sX:= '';
    if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[currentNode].x;
    if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.node[currentNode].x;
    if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.node[currentNode].x;

    if z < 100 then sX:= '0';
    if z < 10 then sX:= sX + '0';
    sX:= sX + numstr(z);
    ttfPrintStringXY(EnvelopeImage, TrackerTUI.MainFont, 328 * 2 - 24, 0, Theme_InstrumentEditor_EnvelopeNumbersColor, sX);

    sY:= '';
    if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[currentNode].y;
    if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.node[currentNode].y;
    if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.node[currentNode].y;                
    if (z < 10) and (z > 0) then sY:= '0';
    sY:= sY + numstr(z);
    ttfPrintStringXY(EnvelopeImage, TrackerTUI.MainFont, 328 * 2 - 24, 16, Theme_InstrumentEditor_EnvelopeNumbersColor, sY);

end;


function TInstrumentEditor.isMouseInNodeToucher(x, y: longint): boolean;
begin

    result:= false;
    x:= x + 117;
    y:= y + 632-200+28;
    if ((mouseX >= (x - 4)) and (mouseY >= (y - 4)) and (mouseX <= (x + 4)) and (mouseY <= (y + 4))) then result:= true;

end;


procedure TInstrumentEditor.getCurXcurY(num: longint; var x, y: longint);
begin

    if currentEnvelopMode = 1 then X:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[num].x * 2 + 4;
    if currentEnvelopMode = 2 then X:= Module.instruments[CurrentInstrument].PanningEnvelope.node[num].x * 2 + 4;
    if currentEnvelopMode = 3 then X:= Module.instruments[CurrentInstrument].PitchEnvelope.node[num].x * 2 + 4;

    if currentEnvelopMode = 1 then Y:= EnvelopeImage.height - Module.instruments[CurrentInstrument].VolumeEnvelope.node[num].y * 2 - 4 * 2;
    if currentEnvelopMode = 2 then Y:= EnvelopeImage.height - Module.instruments[CurrentInstrument].PanningEnvelope.node[num].y * 2 - 4 * 2 - 64;
    if currentEnvelopMode = 3 then Y:= EnvelopeImage.height - Module.instruments[CurrentInstrument].PitchEnvelope.node[num].y * 2 - 4 * 2 - 64;

end;    


function TInstrumentEditor.getMouseValueY: longint;
begin
    
    if currentEnvelopMode = 1 then result:= mouseValueY1;
    if currentEnvelopMode = 2 then result:= mouseValueY2;
    if currentEnvelopMode = 3 then result:= mouseValueY3;

    if mouseL then begin
        if currentEnvelopMode = 1 then begin
            result:= 64 - ((mouseY - (632 - 200 + 28)) div 2);
            if result < 0 then result:= 0;
            if result > 64 then result:= 64;
            mouseValueY1:= result;
        end;

        if currentEnvelopMode = 2 then begin
            result:= 32 - ((mouseY - (632 - 200 + 28)) div 2);
            if result < -32 then result:= -32;
            if result > 32 then result:= 32;
            mouseValueY2:= result;
        end;

        if currentEnvelopMode = 3 then begin
            result:= 32 - ((mouseY - (632 - 200 + 28)) div 2);
            if result < -32 then result:= -32;
            if result > 32 then result:= 32;
            mouseValueY3:= result;
        end;
    end;

    

end;


function TInstrumentEditor.getMouseValueX: longint;
begin
    
    result:= mouseValueX;

    if mouseL then begin
        result:= ((mouseX - 115) div 2);
        if result < 0 then result:= 0;
        if result > 324 then result:= 324;
        mouseValueX:= result;
    end;

    

end;


procedure TInstrumentEditor.checkEnvelopeCheckBoxes;
begin

    if efEnabled in Module.instruments[CurrentInstrument].VolumeEnvelope.flags then EnvelopeCheckBoxVolume.isChecked:= true else EnvelopeCheckBoxVolume.isChecked:= false;
    if efEnabled in Module.instruments[CurrentInstrument].PanningEnvelope.flags then EnvelopeCheckBoxPanning.isChecked:= true else EnvelopeCheckBoxPanning.isChecked:= false;
    if efEnabled in Module.instruments[CurrentInstrument].PitchEnvelope.flags then EnvelopeCheckBoxPitch.isChecked:= true else EnvelopeCheckBoxPitch.isChecked:= false;

end;


function TInstrumentEditor.getNodeCount: longint;
begin

    if currentEnvelopMode = 1 then result:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1;
    if currentEnvelopMode = 2 then result:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1;
    if currentEnvelopMode = 3 then result:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1;

end;


function TInstrumentEditor.getNodeX(num: longint): longint;
begin

    if currentEnvelopMode = 1 then result:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[num].x;
    if currentEnvelopMode = 2 then result:= Module.instruments[CurrentInstrument].PanningEnvelope.node[num].x;
    if currentEnvelopMode = 3 then result:= Module.instruments[CurrentInstrument].PitchEnvelope.node[num].x;

end;


function TInstrumentEditor.getNodeY(num: longint): longint;
begin

    if currentEnvelopMode = 1 then result:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[num].y;
    if currentEnvelopMode = 2 then result:= Module.instruments[CurrentInstrument].PanningEnvelope.node[num].y;
    if currentEnvelopMode = 3 then result:= Module.instruments[CurrentInstrument].PitchEnvelope.node[num].y;

end;


procedure TInstrumentEditor.execProcEnvelopeSustainPointBeginButtonUP(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxSustain.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
        
        inc(z);
        if z > getNodeCount then z:= getNodeCount;

        if currentEnvelopMode = 1 then if z > Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 2 then if z > Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 3 then if z > Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeSustainPointBeginButtonDown(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxSustain.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;

        dec(z);
        if z < 0 then z:= 0;

        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeSustainPointEndButtonUP(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxSustain.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

        inc(z);
        if z > getNodeCount then z:= getNodeCount;
        
        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeSustainPointEndButtonDown(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxSustain.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

        dec(z);
        if currentEnvelopMode = 1 then if z < Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
        if currentEnvelopMode = 2 then if z < Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart then z:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
        if currentEnvelopMode = 3 then if z < Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart then z:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;

        if z < 0 then z:= 0;
        
        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeLoopPointBeginButtonUP(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxLoop.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
        
        inc(z);
        if z > getNodeCount then z:= getNodeCount;

        if currentEnvelopMode = 1 then if z > Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
        if currentEnvelopMode = 2 then if z > Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
        if currentEnvelopMode = 3 then if z > Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;

        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeLoopPointBeginButtonDown(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxLoop.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;

        dec(z);
        if z < 0 then z:= 0;

        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeLoopPointEndButtonUP(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxLoop.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;

        inc(z);
        if z > getNodeCount then z:= getNodeCount;
        
        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(z);

end;


procedure TInstrumentEditor.execProcEnvelopeLoopPointEndButtonDown(const param: string);
var 
    z : longint;

begin
    
    if not EnvelopeCheckBoxLoop.isChecked then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);
        
        if currentEnvelopMode = 1 then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
        if currentEnvelopMode = 2 then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
        if currentEnvelopMode = 3 then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;

        dec(z);
        if currentEnvelopMode = 1 then if z < Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart then z:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
        if currentEnvelopMode = 2 then if z < Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart then z:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
        if currentEnvelopMode = 3 then if z < Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart then z:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;

        if z < 0 then z:= 0;
        
        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= z;
        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= z;
        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= z;

    tralalaEngine.Unlock_Module_ReadWrite;

    EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(z);

end;


procedure TInstrumentEditor.updateEnvelope;
var 
    curNode, i : longint;

    curX, curY : longint;   
    oldX, oldY : longint;

    aValue : TEnvelopeNode;

    z : longint;

    sustainCurX, sustainCurY : longint;
    loopCurX, loopCurY : longint;

begin

    fastfill(EnvelopeImage.data, EnvelopeImage.width * EnvelopeImage.height, $ff000000);
    drawXYscale;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        checkEnvelopeCheckBoxes;
        
        getCurXcurY(0, oldX, oldY);
        

        for curNode:= 0 to getNodeCount do begin

            getCurXcurY(curNode, curX, curY);

            drawline(EnvelopeImage, oldX, oldY, curX, curY, Theme_InstrumentEditor_EnvelopeLineColor);

            drawNodeToucher(curX, curY, Theme_InstrumentEditor_EnvelopeToucherColor);

            if currentEnvelopMode = 1 then begin

                if Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType = esltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);
                end;

                if Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType = eltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);
                end;
            end;

            if currentEnvelopMode = 2 then begin
                if Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType = esltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);
                end;

                if Module.instruments[CurrentInstrument].PanningEnvelope.LoopType = eltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);
                end;

            end;

            if currentEnvelopMode = 3 then begin

                if Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType = esltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd, sustainCurX, sustainCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, sustainCurX, Theme_InstrumentEditor_EnvelopeSustainLineColor);

                end;

                if Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType = eltForwardLoop then begin
                    
                    getCurXcurY(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);

                    getCurXcurY(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd, loopCurX, loopCurY);
                    drawVLine(EnvelopeImage, 0, EnvelopeImage.height, loopCurX, Theme_InstrumentEditor_EnvelopeLoopLineColor);

                end;
            end;


            if isMouseInNodeToucher(curX, curY) and (not nodeTouched) then begin
                
                currentNode:= curNode;
                MouseInNodeToucher:= true;
                nodeTouched:= true;
                
                if (curNode <> oldTouchedNode) then begin
                    oldTouchedNode:= curNode;
                    netSendEnvelopeTouchedNode(curNode);
                end;
                
            end else begin
                MouseInNodeToucher:= false;
            end;

            if currentNode = curNode then begin

                drawNodeToucher(curX, curY, Theme_InstrumentEditor_EnvelopeCurrentToucherColor);
                drawXYtext;

                if mouseL and MouseInNodeToucher and EnvelopeSelectableImage.mouseOver then begin
                    touchedEnvelopePoint:= true;
                end;
                if touchedEnvelopePoint then begin

                        aValue.y:= getMouseValueY;

                        if currentNode = 0 then begin
                            aValue.x:= 0;    
                        end else begin

                            aValue.x:= getMouseValueX;

                            for i:=0 to curNode - 1 do begin
                                z:= getNodeX(i);
                                if aValue.x < (z + 1) then aValue.x:= z + 1;
                            end;

       
                            for i:=curNode + 1 to getNodeCount do begin
                                z:= getNodeX(i);
                                if aValue.x > (z - 1) then aValue.x:= z - 1;
                            end;

                        end;


                        if currentEnvelopMode = 1 then Module.instruments[CurrentInstrument].VolumeEnvelope.node[currentNode]:= aValue;
                        if currentEnvelopMode = 2 then Module.instruments[CurrentInstrument].PanningEnvelope.node[currentNode]:= aValue;
                        if currentEnvelopMode = 3 then Module.instruments[CurrentInstrument].PitchEnvelope.node[currentNode]:= aValue;

                        netSendEnvelopeToucher(currentEnvelopMode, CurrentInstrument, currentNode, aValue.x, aValue.y);
                        
                end;
                if (not mouseL) then begin
                    touchedEnvelopePoint:= false;
                    nodeTouched:= false;
                end;

            end;

            oldX:= curX;
            oldY:= curY;
        end;

       
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.EnvelopePreDefButton1LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton1VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton1VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton1VolumeNodes[length(EnvelopePreDefButton1VolumeNodes)-1].x;
            aValue.y:= EnvelopePreDefButton1VolumeNodes[length(EnvelopePreDefButton1VolumeNodes)-1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton1VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton1VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton1VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton1VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton1VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton1VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton1VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton1VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton1VolumeSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    end;

    if currentEnvelopMode = 2 then begin

            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton1PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton1PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton1PanningNodes[length(EnvelopePreDefButton1PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton1PanningNodes[length(EnvelopePreDefButton1PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton1PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton1PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton1PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;

            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton1PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton1PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton1PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton1PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton1PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton1PanningSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);

    end;


    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton1PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton1PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton1PitchNodes[length(EnvelopePreDefButton1PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton1PitchNodes[length(EnvelopePreDefButton1PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton1PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton1PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton1PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton1PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton1PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton1PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton1PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton1PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton1PitchSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);

    end;


    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.EnvelopePreDefButton1RightClick(const param: string);
var 
    i : longint;  

begin
    
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton1VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton1VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton1VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;

            end;
            EnvelopePreDefButton1VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton1VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton1VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton1VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton1VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton1VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton1PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton1PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton1PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;

            end;
            EnvelopePreDefButton1PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton1PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton1PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton1PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton1PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton1PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton1PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:=0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton1PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton1PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;

            end;
            EnvelopePreDefButton1PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton1PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton1PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton1PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton1PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton1PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.EnvelopePreDefButton2LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin
    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton2VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton2VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton2VolumeNodes[length(EnvelopePreDefButton2VolumeNodes)-1].x;
            aValue.y:= EnvelopePreDefButton2VolumeNodes[length(EnvelopePreDefButton2VolumeNodes)-1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton2VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton2VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton2VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton2VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton2VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton2VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton2VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton2VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton2VolumeSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    end;

    if currentEnvelopMode = 2 then begin

            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton2PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton2PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton2PanningNodes[length(EnvelopePreDefButton2PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton2PanningNodes[length(EnvelopePreDefButton2PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton2PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton2PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton2PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton2PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton2PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton2PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton2PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton2PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton2PanningSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);

    end;



    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton2PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton2PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton2PitchNodes[length(EnvelopePreDefButton2PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton2PitchNodes[length(EnvelopePreDefButton2PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton2PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton2PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton2PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton2PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton2PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton2PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton2PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton2PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton2PitchSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);

    end;

    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.EnvelopePreDefButton2RightClick(const param: string);
var 
    i : longint;

begin
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton2VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton2VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton2VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;

            end;
            EnvelopePreDefButton2VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton2VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton2VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton2VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton2VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton2VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton2PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton2PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton2PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;

            end;
            EnvelopePreDefButton2PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton2PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton2PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton2PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton2PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton2PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton2PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton2PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton2PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;

            end;
            EnvelopePreDefButton2PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton2PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton2PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton2PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton2PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton2PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;




procedure TInstrumentEditor.EnvelopePreDefButton3LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin
    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton3VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton3VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton3VolumeNodes[length(EnvelopePreDefButton3VolumeNodes)-1].x;
            aValue.y:= EnvelopePreDefButton3VolumeNodes[length(EnvelopePreDefButton3VolumeNodes)-1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton3VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton3VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton3VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton3VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton3VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton3VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton3VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton3VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton3VolumeSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);
    end;

    if currentEnvelopMode = 2 then begin


            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton3PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton3PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton3PanningNodes[length(EnvelopePreDefButton3PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton3PanningNodes[length(EnvelopePreDefButton3PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton3PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton3PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton3PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;

            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton3PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton3PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton3PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton3PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton3PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton3PanningSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);

    end;


    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton3PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton3PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton3PitchNodes[length(EnvelopePreDefButton3PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton3PitchNodes[length(EnvelopePreDefButton3PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton3PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton3PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton3PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;

            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton3PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton3PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton3PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton3PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton3PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton3PitchSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);

    end;

    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.EnvelopePreDefButton3RightClick(const param: string);
var 
    i : longint;    

begin
    
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton3VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton3VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton3VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;
            end;

            EnvelopePreDefButton3VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton3VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton3VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton3VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton3VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton3VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton3PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton3PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton3PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;
            end;

            EnvelopePreDefButton3PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton3PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton3PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton3PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton3PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton3PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton3PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:=0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton3PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton3PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;
            end;

            EnvelopePreDefButton3PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton3PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton3PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton3PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton3PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton3PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;

procedure TInstrumentEditor.EnvelopePreDefButton4LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton4VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton4VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton4VolumeNodes[length(EnvelopePreDefButton4VolumeNodes)-1].x;
            aValue.y:= EnvelopePreDefButton4VolumeNodes[length(EnvelopePreDefButton4VolumeNodes)-1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:=1 to length(EnvelopePreDefButton4VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton4VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton4VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton4VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton4VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton4VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton4VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton4VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton4VolumeSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    end;

    if currentEnvelopMode = 2 then begin

            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton4PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton4PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton4PanningNodes[length(EnvelopePreDefButton4PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton4PanningNodes[length(EnvelopePreDefButton4PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton4PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton4PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton4PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton4PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton4PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton4PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton4PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton4PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton4PanningSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);

    end;



    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton4PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton4PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton4PitchNodes[length(EnvelopePreDefButton4PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton4PitchNodes[length(EnvelopePreDefButton4PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton4PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton4PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton4PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton4PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton4PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton4PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton4PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton4PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton4PitchSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);

    end;

    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.EnvelopePreDefButton4RightClick(const param: string);
var 
    i : longint;    

begin
    
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton4VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton4VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton4VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;

            end;
            EnvelopePreDefButton4VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton4VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton4VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton4VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton4VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton4VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton4PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton4PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton4PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;

            end;
            EnvelopePreDefButton4PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton4PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton4PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton4PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton4PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton4PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton4PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton4PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton4PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;

            end;
            EnvelopePreDefButton4PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton4PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton4PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton4PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton4PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton4PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;



procedure TInstrumentEditor.EnvelopePreDefButton5LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton5VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton5VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton5VolumeNodes[length(EnvelopePreDefButton5VolumeNodes)-1].x;
            aValue.y:= EnvelopePreDefButton5VolumeNodes[length(EnvelopePreDefButton5VolumeNodes)-1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton5VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton5VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton5VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;

            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton5VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton5VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton5VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton5VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton5VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton5VolumeSustainLoopEnd;


            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    end;

    if currentEnvelopMode = 2 then begin

            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton5PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton5PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton5PanningNodes[length(EnvelopePreDefButton5PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton5PanningNodes[length(EnvelopePreDefButton5PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton5PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton5PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton5PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton5PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton5PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton5PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton5PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton5PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton5PanningSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);

    end;



    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton5PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton5PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton5PitchNodes[length(EnvelopePreDefButton5PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton5PitchNodes[length(EnvelopePreDefButton5PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton5PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton5PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton5PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton5PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton5PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton5PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton5PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton5PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton5PitchSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);

    end;

    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.EnvelopePreDefButton5RightClick(const param: string);
var 
    i : longint;

begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton5VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    
                    EnvelopePreDefButton5VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton5VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;

            end;
            EnvelopePreDefButton5VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton5VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton5VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton5VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton5VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton5VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton5PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton5PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton5PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;
            end;

            EnvelopePreDefButton5PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton5PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton5PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton5PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton5PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton5PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton5PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton5PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton5PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;
            end;

            EnvelopePreDefButton5PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton5PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton5PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton5PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton5PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton5PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;

procedure TInstrumentEditor.EnvelopePreDefButton6LeftClick(const param: string);
var 
    i : longint;
    aValue : TEnvelopeNode;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if currentEnvelopMode = 1 then begin

            for i:= Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].VolumeEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton6VolumeNodes[0].x;
            aValue.y:= EnvelopePreDefButton6VolumeNodes[0].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton6VolumeNodes[length(EnvelopePreDefButton6VolumeNodes) - 1].x;
            aValue.y:= EnvelopePreDefButton6VolumeNodes[length(EnvelopePreDefButton6VolumeNodes) - 1].y;
            Module.instruments[CurrentInstrument].VolumeEnvelope.node[Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton6VolumeNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton6VolumeNodes[i].x;
                aValue.y:= EnvelopePreDefButton6VolumeNodes[i].y;
                Module.instruments[CurrentInstrument].VolumeEnvelope.insertNode(aValue);
            end;
            
            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton6VolumeSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton6VolumeLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart:= EnvelopePreDefButton6VolumeLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd:= EnvelopePreDefButton6VolumeLoopEnd;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart:= EnvelopePreDefButton6VolumeSustainLoopStart;
            Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd:= EnvelopePreDefButton6VolumeSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd);

    end;

    if currentEnvelopMode = 2 then begin

            for i:= Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PanningEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton6PanningNodes[0].x;
            aValue.y:= EnvelopePreDefButton6PanningNodes[0].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton6PanningNodes[length(EnvelopePreDefButton6PanningNodes)-1].x;
            aValue.y:= EnvelopePreDefButton6PanningNodes[length(EnvelopePreDefButton6PanningNodes)-1].y;
            Module.instruments[CurrentInstrument].PanningEnvelope.node[Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1]:= aValue;

            for i:= 1 to length(EnvelopePreDefButton6PanningNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton6PanningNodes[i].x;
                aValue.y:= EnvelopePreDefButton6PanningNodes[i].y;
                Module.instruments[CurrentInstrument].PanningEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton6PanningSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton6PanningLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart:= EnvelopePreDefButton6PanningLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd:= EnvelopePreDefButton6PanningLoopEnd;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart:= EnvelopePreDefButton6PanningSustainLoopStart;
            Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd:= EnvelopePreDefButton6PanningSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd);
    end;



    if currentEnvelopMode = 3 then begin

            for i:= Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 2 downto 1 do begin
                Module.instruments[CurrentInstrument].PitchEnvelope.DeleteNode(i);
            end;        
            
            aValue.x:= EnvelopePreDefButton6PitchNodes[0].x;
            aValue.y:= EnvelopePreDefButton6PitchNodes[0].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[0]:= aValue;

            aValue.x:= EnvelopePreDefButton6PitchNodes[length(EnvelopePreDefButton6PitchNodes)-1].x;
            aValue.y:= EnvelopePreDefButton6PitchNodes[length(EnvelopePreDefButton6PitchNodes)-1].y;
            Module.instruments[CurrentInstrument].PitchEnvelope.node[Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1]:= aValue;

            for i:=1 to length(EnvelopePreDefButton6PitchNodes) - 2 do begin
                aValue.x:= EnvelopePreDefButton6PitchNodes[i].x;
                aValue.y:= EnvelopePreDefButton6PitchNodes[i].y;
                Module.instruments[CurrentInstrument].PitchEnvelope.insertNode(aValue);
            end;

            EnvelopeCheckBoxSustain.isChecked:= EnvelopePreDefButton6PitchSustainLoop;
            EnvelopeCheckBoxLoop.isChecked:= EnvelopePreDefButton6PitchLoop;
            
            if EnvelopeCheckBoxLoop.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.LoopType:= eltNoLoop;
            if EnvelopeCheckBoxSustain.isChecked then Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltForwardLoop else Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopType:= esltNoLoop;

            Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart:= EnvelopePreDefButton6PitchLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd:= EnvelopePreDefButton6PitchLoopEnd;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart:= EnvelopePreDefButton6PitchSustainLoopStart;
            Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd:= EnvelopePreDefButton6PitchSustainLoopEnd;

            EnvelopeTextFieldSustainPointBegin.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart);
            EnvelopeTextFieldSustainPointEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd);

            EnvelopeTextFieldLoopStart.caption:= 'Start ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart);
            EnvelopeTextFieldLoopEnd.caption:= 'End ' + numstr(Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd);
    end;

    execProcEnvelopeCheckBoxSustain('');
    execProcEnvelopeCheckBoxLoop('');

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.EnvelopePreDefButton6RightClick(const param: string);
var 
    i : longint;

begin
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    
        if currentEnvelopMode = 1 then begin
            setlength(EnvelopePreDefButton6VolumeNodes, Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].VolumeEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton6VolumeNodes[i].x:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].x;
                    EnvelopePreDefButton6VolumeNodes[i].y:= Module.instruments[CurrentInstrument].VolumeEnvelope.node[i].y;
            end;
            EnvelopePreDefButton6VolumeLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopStart;
            EnvelopePreDefButton6VolumeLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.LoopEnd;
            EnvelopePreDefButton6VolumeSustainLoopStart:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopStart;
            EnvelopePreDefButton6VolumeSustainLoopEnd:= Module.instruments[CurrentInstrument].VolumeEnvelope.SustainLoopEnd;

            EnvelopePreDefButton6VolumeSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton6VolumeLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 2 then begin
            setlength(EnvelopePreDefButton6PanningNodes, Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PanningEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton6PanningNodes[i].x:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].x;
                    EnvelopePreDefButton6PanningNodes[i].y:= Module.instruments[CurrentInstrument].PanningEnvelope.node[i].y;
            end;
            EnvelopePreDefButton6PanningLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopStart;
            EnvelopePreDefButton6PanningLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.LoopEnd;
            EnvelopePreDefButton6PanningSustainLoopStart:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopStart;
            EnvelopePreDefButton6PanningSustainLoopEnd:= Module.instruments[CurrentInstrument].PanningEnvelope.SustainLoopEnd;

            EnvelopePreDefButton6PanningSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton6PanningLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

        if currentEnvelopMode = 3 then begin
            setlength(EnvelopePreDefButton6PitchNodes, Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount);

            for i:= 0 to Module.instruments[CurrentInstrument].PitchEnvelope.nodeCount - 1 do begin
                    EnvelopePreDefButton6PitchNodes[i].x:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].x;
                    EnvelopePreDefButton6PitchNodes[i].y:= Module.instruments[CurrentInstrument].PitchEnvelope.node[i].y;
            end;
            EnvelopePreDefButton6PitchLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopStart;
            EnvelopePreDefButton6PitchLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.LoopEnd;
            EnvelopePreDefButton6PitchSustainLoopStart:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopStart;
            EnvelopePreDefButton6PitchSustainLoopEnd:= Module.instruments[CurrentInstrument].PitchEnvelope.SustainLoopEnd;

            EnvelopePreDefButton6PitchSustainLoop:= EnvelopeCheckBoxSustain.isChecked;
            EnvelopePreDefButton6PitchLoop:= EnvelopeCheckBoxLoop.isChecked;
        end;

    tralalaEngine.Unlock_ReadOnly;

end;



procedure TInstrumentEditor.execProcEnvelopeCheckBoxCarry(const param: string);
var 
    flags:TEnvelopeFlags;

begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

    if currentEnvelopMode = 1 then begin
        flags:= Module.instruments[CurrentInstrument].VolumeEnvelope.Flags;
        if EnvelopeCheckBoxCarry.isChecked then include(flags, efCarry) else exclude(flags, efCarry);
        Module.instruments[CurrentInstrument].VolumeEnvelope.Flags:= flags;
    end;

    if currentEnvelopMode = 2 then begin
        flags:= Module.instruments[CurrentInstrument].PanningEnvelope.Flags;
        if EnvelopeCheckBoxCarry.isChecked then include(flags, efCarry) else exclude(flags, efCarry);
        Module.instruments[CurrentInstrument].PanningEnvelope.Flags:= flags;
    end;

    if currentEnvelopMode = 3 then begin
        flags:= Module.instruments[CurrentInstrument].PitchEnvelope.Flags;
        if EnvelopeCheckBoxCarry.isChecked then include(flags, efCarry) else exclude(flags, efCarry);
        Module.instruments[CurrentInstrument].PitchEnvelope.Flags:= flags;
    end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;




procedure TInstrumentEditor.disableEnvelopePanel;
begin

    EnvelopeSelectableImage.enabled:= false;
    EnvelopeCheckBoxVolume.enabled:= false;
    EnvelopeCheckBoxPanning.enabled:= false;
    EnvelopeCheckBoxPitch.enabled:= false;

    EnvelopePreDefButton1.enabled:= false;
    EnvelopePreDefButton2.enabled:= false;
    EnvelopePreDefButton3.enabled:= false;
    EnvelopePreDefButton4.enabled:= false;
    EnvelopePreDefButton5.enabled:= false;
    EnvelopePreDefButton6.enabled:= false;

    EnvelopeAddButton.enabled:= false;
    EnvelopeDelButton.enabled:= false;
    EnvelopeCheckBoxSustain.enabled:= false;
    EnvelopeTextFieldSustainPointBegin.enabled:= false;
    EnvelopeTextFieldSustainPointBeginButtonUP.enabled:= false;
    EnvelopeTextFieldSustainPointBeginButtonDOWN.enabled:= false;
    EnvelopeTextFieldSustainPointEnd.enabled:= false;
    EnvelopeTextFieldSustainPointEndButtonUP.enabled:= false;
    EnvelopeTextFieldSustainPointEndButtonDOWN.enabled:= false;

    EnvelopeCheckBoxLoop.enabled:= false;
    EnvelopeTextFieldLoopStart.enabled:= false;
    EnvelopeEnvelopeLoopStartButtonUP.enabled:= false;
    EnvelopeEnvelopeLoopStartButtonDOWN.enabled:= false;
    EnvelopeTextFieldLoopEnd.enabled:= false;
    EnvelopeEnvelopeLoopEndButtonUP.enabled:= false;
    EnvelopeEnvelopeLoopEndButtonDOWN.enabled:= false;
    EnvelopeCheckBoxCarry.enabled:= false;

end;

procedure TInstrumentEditor.enableEnvelopePanel;

begin
    EnvelopeSelectableImage.enabled:= true;
    EnvelopeCheckBoxVolume.enabled:= true;
    EnvelopeCheckBoxPanning.enabled:= true;
    EnvelopeCheckBoxPitch.enabled:= true;

    EnvelopePreDefButton1.enabled:= true;
    EnvelopePreDefButton2.enabled:= true;
    EnvelopePreDefButton3.enabled:= true;
    EnvelopePreDefButton4.enabled:= true;
    EnvelopePreDefButton5.enabled:= true;
    EnvelopePreDefButton6.enabled:= true;

    EnvelopeAddButton.enabled:= true;
    EnvelopeDelButton.enabled:= true;
    EnvelopeCheckBoxSustain.enabled:= true;
    EnvelopeTextFieldSustainPointBegin.enabled:= true;
    EnvelopeTextFieldSustainPointBeginButtonUP.enabled:= true;
    EnvelopeTextFieldSustainPointBeginButtonDOWN.enabled:= true;
    EnvelopeTextFieldSustainPointEnd.enabled:= true;
    EnvelopeTextFieldSustainPointEndButtonUP.enabled:= true;
    EnvelopeTextFieldSustainPointEndButtonDOWN.enabled:= true;

    EnvelopeCheckBoxLoop.enabled:= true;
    EnvelopeTextFieldLoopStart.enabled:= true;
    EnvelopeEnvelopeLoopStartButtonUP.enabled:= true;
    EnvelopeEnvelopeLoopStartButtonDOWN.enabled:= true;
    EnvelopeTextFieldLoopEnd.enabled:= true;
    EnvelopeEnvelopeLoopEndButtonUP.enabled:= true;
    EnvelopeEnvelopeLoopEndButtonDOWN.enabled:= true;
    EnvelopeCheckBoxCarry.enabled:= true;

end;