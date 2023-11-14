 


procedure TInstrumentEditor.buildTopPanel;
var 
    x, y : longint;
begin


	TopPanel:= TtuiBox.create(InstrumentEditorTUI, 0, 18, 1280, 200, 'InstrumentEditorTopPanel', tuiBoxStatic);
    TopPanel.ThemeBox:= LoadThemeBox;
    TopPanel.ThemeBox.BackgroundColor:= Theme_InstrumentEditor_MainPanel_BackgroundColor;
    InstrumentEditorTUI.addBox(TopPanel);
    

    x:= 116;
    y:= 158;

    RadioButtonGroupLoopType:= TtuiRadioButtonGroup.Create(TopPanel, 'RadioButtonLoopTypeGroup');
    TopPanel.addItem(RadioButtonGroupLoopType);

    RadioButtonLoopTypeNoLoop:= TtuiRadioButton.Create(TopPanel, 'RadioButtonLoopTypeNoLoop', x, y, 'No Loop', @execProcRadioButtonLoopTypeNoLoop);
    RadioButtonLoopTypeNoLoop.theme:= LoadThemeRadioButton;
    
    RadioButtonGroupLoopType.add2group(RadioButtonLoopTypeNoLoop);

    RadioButtonLoopTypeForward:= TtuiRadioButton.Create(TopPanel, 'RadioButtonLoopTypeForward', x, y + 16, 'Forward', @execProcRadioButtonLoopTypeForwardLoop);
    RadioButtonLoopTypeForward.theme:= LoadThemeRadioButton;
    RadioButtonGroupLoopType.add2group(RadioButtonLoopTypeForward);

    RadioButtonLoopTypePingPong:= TtuiRadioButton.Create(TopPanel, 'RadioButtonLoopTypePingPongLoop', x, y + 32, 'Ping Pong', @execProcRadioButtonLoopTypePingPongLoop);
    RadioButtonLoopTypePingPong.theme:= LoadThemeRadioButton;
    RadioButtonGroupLoopType.add2group(RadioButtonLoopTypePingPong);


    RadioButtonGroupSampleBits:= TtuiRadioButtonGroup.Create(TopPanel, 'RadioButtonGroupSampleBits');
    TopPanel.addItem(RadioButtonGroupSampleBits);

    RadioButtonSampleBits8:= TtuiRadioButton.Create(TopPanel, 'RadioButtonSampleBits8', x, y - 40, '8-Bit', @execProcRadioButtonSampleBits8);
    RadioButtonSampleBits8.theme:= LoadThemeRadioButton;
    RadioButtonGroupSampleBits.add2group(RadioButtonSampleBits8);

    RadioButtonSampleBits16:= TtuiRadioButton.Create(TopPanel, 'RadioButtonSampleBits16', x, y - 40 + 16, '16-Bit', @execProcRadioButtonSampleBits16);
    RadioButtonSampleBits16.theme:= LoadThemeRadioButton;
    RadioButtonGroupSampleBits.add2group(RadioButtonSampleBits16);



    RadioButtonGroupSampleMonoStereo:= TtuiRadioButtonGroup.Create(TopPanel, 'RadioButtonGroupSampleMonoStereo');
    TopPanel.addItem(RadioButtonGroupSampleMonoStereo);

    RadioButtonSampleMono:= TtuiRadioButton.Create(TopPanel, 'RadioButtonSampleMono', 216, y - 40, 'Mono', @execProcRadioButtonSampleMono);
    RadioButtonSampleMono.theme:= LoadThemeRadioButton;
    RadioButtonGroupSampleMonoStereo.add2group(RadioButtonSampleMono);

    RadioButtonSampleStereo:= TtuiRadioButton.Create(TopPanel, 'RadioButtonSampleStereo', 216, y - 40 + 16, 'Stereo', @execProcRadioButtonSampleStereo);
    RadioButtonSampleStereo.theme:= LoadThemeRadioButton;
    RadioButtonGroupSampleMonoStereo.add2group(RadioButtonSampleStereo);




    x:= 1;
    y:= 1;

    ButtonStop:= TtuiButton.create(TopPanel, 'ButtonStop', x, y, 100, 32, 'Stop', @execProcButtonStop);
    TopPanel.addItem(ButtonStop);
    ButtonWave:= TtuiButton.create(TopPanel, 'ButtonWave', x, y +32 + 1, 100, 32, 'Wave', @execProcButtonWave);
    TopPanel.addItem(ButtonWave);
    ButtonRange:= TtuiButton.create(TopPanel, 'ButtonRange', x, y + 32 + 32 + 2, 100, 32, 'Range', @execProcButtonRange);
    TopPanel.addItem(ButtonRange);
    ButtonDisplay:= TtuiButton.create(TopPanel, 'ButtonDisplay', x, y + 32 + 32 + 32 + 3, 100, 32, 'Display', @execProcButtonDisplay);
    TopPanel.addItem(ButtonDisplay);
    ButtonVolume:= TtuiButton.create(TopPanel, 'ButtonVolume', x, y + 32 + 32 + 32 + 32 + 4, 100, 32, 'Volume', @execProcButtonWaveVolume);
    TopPanel.addItem(ButtonVolume);
    ButtonXFade:=TtuiButton.create(TopPanel, 'ButtonXFade', x, y + 32 + 32 + 32 + 32 + 32 + 5, 100, 32, 'X-Fade', @execProcButtonXFade);
    TopPanel.addItem(ButtonXFade);

 
    x:= 102;
    y:= 1;
    ButtonCut:= TtuiButton.create(TopPanel, 'ButtonCut', x, y, 100, 32, 'Cut', @execProcButtonCut);
    TopPanel.addItem(ButtonCut);
    ButtonCopy:= TtuiButton.create(TopPanel, 'ButtonCopy', x, y + 32 + 1, 100, 32, 'Copy', @execProcButtonCopy);
    TopPanel.addItem(ButtonCopy);
    ButtonPaste:= TtuiButton.create(TopPanel, 'ButtonPaste', x, y + 32 + 32 + 2, 100, 32, 'Paste', @execProcButtonPaste);
    TopPanel.addItem(ButtonPaste);



    x:= 1280 - 222 - 222 - 100 - 3;
    y:= 1;

    ButtonShow:= TtuiButton.create(TopPanel, 'ButtonShow', x, y, 100, 32, 'Show', @execProcShowSelectedWave);
    TopPanel.addItem(ButtonShow);
    ButtonZoomOut:= TtuiButton.create(TopPanel, 'ButtonZoomOut', x, y + 32 + 1, 100, 32, 'Zoom out', @execProcZoomOutWave);
    TopPanel.addItem(ButtonZoomOut);
    ButtonRangeAll:= TtuiButton.create(TopPanel, 'ButtonRangeAll', x, y + 32 + 32 + 2, 100, 32, 'Range all', @execProcRangeAllWave);
    TopPanel.addItem(ButtonRangeAll);
    ButtonShowAll:= TtuiButton.create(TopPanel, 'ButtonShowAll', x, y + 32 +  32 + 32 + 3, 100, 32, 'Show all', @execProcShowAllWave);
    TopPanel.addItem(ButtonShowAll);
    ButtonCrop:= TtuiButton.create(TopPanel, 'ButtonCrop', x, y + 32 + 32 + 32 + 32 + 4, 100, 32, 'Crop', @execProcButtonCrop);
    TopPanel.addItem(ButtonCrop);

    
    x:= 380;


    TextFiledSampleLength:= TtuiTextField.Create(TopPanel, 'TextFiledSampleLength', 210, 6, 'Sample length is ' + numstr(0));
    TextFiledSampleLength.theme:= LoadThemeTextField;
    TextFiledSampleLength.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledSampleLength);

    TextFiledLoopStart:= TtuiTextField.Create(TopPanel, 'TextFiledLoopStart', 210, 6 + 20, 'Loop Start at ' + numstr(0));
    TextFiledLoopStart.theme:= LoadThemeTextField;
    TextFiledLoopStart.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledLoopStart);
    
    ButtonUPLoopStart:= TtuiButtonUP.Create(TopPanel, 'ButtonUPLoopStart', x, 24, @execProcButtonUPLoopStart);
    ButtonUPLoopStart.theme:= LoadThemeButtonUP;
    TopPanel.addItem(ButtonUPLoopStart);
    ButtonDOWNLoopStart:= TtuiButtonDOWN.Create(TopPanel, 'ButtonDOWNLoopStart', x + 19, 24, @execProcButtonDOWNLoopStart);
    ButtonDOWNLoopStart.theme:= LoadThemeButtonDOWN;
    TopPanel.addItem(ButtonDOWNLoopStart);



    TextFiledLoopEnd:= TtuiTextField.Create(TopPanel, 'TextFiledLoopEnd', 210, 6 + 20 + 20, 'Loop End at ' + numstr(0));
    TextFiledLoopEnd.theme:= LoadThemeTextField;
    TextFiledLoopEnd.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledLoopEnd);

    ButtonUPLoopEnd:= TtuiButtonUP.Create(TopPanel, 'ButtonUPLoopEnd', x, 24 + 19, @execProcButtonUPLoopEnd);
    ButtonUPLoopEnd.theme:= LoadThemeButtonUP;
    TopPanel.addItem(ButtonUPLoopEnd);
    ButtonDOWNLoopEnd:= TtuiButtonDOWN.Create(TopPanel, 'ButtonDOWNLoopEnd', x + 19, 24 + 19, @execProcButtonDOWNLoopEnd);
    ButtonDOWNLoopEnd.theme:= LoadThemeButtonDOWN;
    TopPanel.addItem(ButtonDOWNLoopEnd);





    TextFiledSustainLoopStart:= TtuiTextField.Create(TopPanel, 'TextFiledSustainLoopStart', 210, 6 + 20 + 20 + 20, 'Sustain Loop Start at ' + numstr(0));
    TextFiledSustainLoopStart.theme:= LoadThemeTextField;
    TextFiledSustainLoopStart.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledSustainLoopStart);
    
    ButtonUPSustainLoopStart:= TtuiButtonUP.Create(TopPanel, 'ButtonUPSustainLoopStart', x, 24 + 20 + 18, @execProcButtonUPSustainLoopStart);
    ButtonUPSustainLoopStart.theme:= LoadThemeButtonUP;
    TopPanel.addItem(ButtonUPSustainLoopStart);
    ButtonDOWNSustainLoopStart:= TtuiButtonDOWN.Create(TopPanel, 'ButtonDOWNSustainLoopStart', x + 19, 24 + 20 + 18, @execProcButtonDOWNSustainLoopStart);
    ButtonDOWNSustainLoopStart.theme:= LoadThemeButtonDOWN;
    TopPanel.addItem(ButtonDOWNSustainLoopStart);



    TextFiledSustainLoopEnd:= TtuiTextField.Create(TopPanel, 'TextFiledSustainLoopEnd', 210, 6 + 20 + 20 + 20 + 20, 'Sustain Loop End at ' + numstr(0));
    TextFiledSustainLoopEnd.theme:= LoadThemeTextField;
    TextFiledSustainLoopEnd.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledSustainLoopEnd);

    ButtonUPSustainLoopEnd:= TtuiButtonUP.Create(TopPanel, 'ButtonUPSustainLoopEnd', x, 24 + 19 + 20 + 18, @execProcButtonUPSustainLoopEnd);
    ButtonUPSustainLoopEnd.theme:= LoadThemeButtonUP;
    TopPanel.addItem(ButtonUPSustainLoopEnd);
    ButtonDOWNSustainLoopEnd:= TtuiButtonDOWN.Create(TopPanel, 'ButtonDOWNSustainLoopEnd', x + 19, 24 + 19 + 20 + 18, @execProcButtonDOWNSustainLoopEnd);
    ButtonDOWNSustainLoopEnd.theme:= LoadThemeButtonDOWN;
    TopPanel.addItem(ButtonDOWNSustainLoopEnd);










    ScrollBarVibratoSpeed:= TtuiScrollBarHorizontal.Create(TopPanel, 'ScrollBarVibratoSpeed', 1280 - 549 - 128, 2, 128, 64, @execProcScrollBarVibratoSpeed);
    ScrollBarVibratoSpeed.theme:= LoadThemeScrollbarHorizontal;
    TopPanel.addItem(ScrollBarVibratoSpeed);

    TextFiledVibratoSpeed:= TtuiTextField.Create(TopPanel, 'TextFiledVibratoSpeed', 1280 - 549 - 128 - 95, 4, 'Vibrato Speed ' + numstr(0));
    TextFiledVibratoSpeed.theme:= LoadThemeTextField;
    TextFiledVibratoSpeed.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledVibratoSpeed);

    ScrollBarVibratoDepth:= TtuiScrollBarHorizontal.Create(TopPanel, 'ScrollBarVibratoDepth', 1280 - 549 - 128, 2 + 18, 128, 32, @execProcScrollBarVibratoDepth);
    ScrollBarVibratoDepth.theme:= LoadThemeScrollbarHorizontal;
    TopPanel.addItem(ScrollBarVibratoDepth);
    
    TextFiledVibratoDepth:= TtuiTextField.Create(TopPanel, 'TextFiledVibratoDepth', 1280 - 549 - 128 - 95, 22, 'Vibrato Depth ' + numstr(0));
    TextFiledVibratoDepth.theme:= LoadThemeTextField;
    TextFiledVibratoDepth.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledVibratoDepth);

    ScrollBarVibratoSweep:= TtuiScrollBarHorizontal.Create(TopPanel, 'ScrollBarVibratoSweep', 1280 - 549 - 128, 2 + 18 + 18, 128, 255, @execProcScrollBarVibratoSweep);
    ScrollBarVibratoSweep.theme:= LoadThemeScrollbarHorizontal;
    TopPanel.addItem(ScrollBarVibratoSweep);

    TextFiledVibratoSweep:= TtuiTextField.Create(TopPanel, 'TextFiledVibratoSweep', 1280 - 549 - 128 - 95 - 8, 22 + 18, 'Vibrato Sweep ' + numstr(0));
    TextFiledVibratoSweep.theme:= LoadThemeTextField;
    TextFiledVibratoSweep.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFiledVibratoSweep);
    

    ScrollBarFineTune:= TtuiScrollBarHorizontal.Create(TopPanel, 'ScrollBarFineTune', 1280 - 549 - 128, 2 + 18 + 18 + 18, 128, 255, @execProcScrollBarFineTune);
    ScrollBarFineTune.theme:= LoadThemeScrollbarHorizontal;
    TopPanel.addItem(ScrollBarFineTune);

    TextFieldFineTune:= TtuiTextField.Create(TopPanel, 'TextFieldFineTune', 1280 - 549 - 128 - 75 - 8, 22 + 18 + 18, 'Fine Tune ' + numstr(0));
    TextFieldFineTune.theme:= LoadThemeTextField;
    TextFieldFineTune.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    TopPanel.addItem(TextFieldFineTune);












    allocImage(ImageWaveStyle1Sprite, 12, 10);
    fastfill(ImageWaveStyle1Sprite.data, ImageWaveStyle1Sprite.width * ImageWaveStyle1Sprite.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    x:= 0;
    y:= 4;
    putpixel(ImageWaveStyle1Sprite, x + 0, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 0, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 1, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 1, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 2, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 3, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 4, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 4, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 5, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 5, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 5, y - 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 5, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 6, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 6, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 7, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 8, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 9, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 9, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 10, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle1Sprite, x + 10, y + 0, Theme_RadioButton_Color);

    allocImage(ImageWaveStyle1SpriteOver, 12, 10);
    fastfill(ImageWaveStyle1SpriteOver.data, ImageWaveStyle1SpriteOver.width * ImageWaveStyle1SpriteOver.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    x:= 0;
    y:= 4;
    putpixel(ImageWaveStyle1SpriteOver, x + 0, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 0, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 1, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 1, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 2, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 3, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 4, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 4, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 5, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 5, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 5, y - 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 5, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 6, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 6, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 7, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 8, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 9, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 9, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 10, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle1SpriteOver, x + 10, y + 0, Theme_RadioButton_SelectColor);


    RadioButtonGroupWaveStyle:= TtuiRadioButtonGroup.Create(TopPanel, 'RadioButtonGroupWaveStyle');
    TopPanel.addItem(RadioButtonGroupWaveStyle);

    RadioButtonWaveStyle1:= TtuiRadioButton.Create(TopPanel, 'RadioButtonWaveStyle1', 329, 158, ImageWaveStyle1Sprite, ImageWaveStyle1SpriteOver, @execProcRadioButtonWaveStyle1);
    RadioButtonWaveStyle1.theme.color:= theme_Tracker_MainPanel_FontColor;
    RadioButtonWaveStyle1.theme.fontcolor:= theme_Tracker_MainPanel_FontColor;
    RadioButtonGroupWaveStyle.add2group(RadioButtonWaveStyle1);






    x:= 0;
    y:= 4;
    allocImage(ImageWaveStyle2Sprite, 12, 10);
    fastfill(ImageWaveStyle2Sprite.data, ImageWaveStyle2Sprite.width * ImageWaveStyle2Sprite.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle2Sprite, x + 0, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 0, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 0, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 0, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 0, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 1, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 2, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 3, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 4, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y - 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 5, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 6, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 7, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 8, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 9, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 10, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 10, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 10, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 10, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle2Sprite, x + 10, y + 0, Theme_RadioButton_Color);

    allocImage(ImageWaveStyle2SpriteOver, 14, 10);
    fastfill(ImageWaveStyle2SpriteOver.data, ImageWaveStyle2SpriteOver.width * ImageWaveStyle2SpriteOver.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 0, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 0, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 0, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 0, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 0, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 1, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 2, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 3, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 4, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y - 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 5, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 6, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 7, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 8, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 9, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 10, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 10, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 10, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 10, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle2SpriteOver, x + 10, y + 0, Theme_RadioButton_SelectColor);

    RadioButtonWaveStyle2:= TtuiRadioButton.Create(TopPanel, 'RadioButtonWaveStyle2', 329, 158 + 16, ImageWaveStyle2Sprite, ImageWaveStyle2SpriteOver, @execProcRadioButtonWaveStyle2);
    RadioButtonWaveStyle2.theme:= LoadThemeRadioButton;
    RadioButtonGroupWaveStyle.add2group(RadioButtonWaveStyle2);



    x:= 0;
    y:= 4;

    allocImage(ImageWaveStyle3Sprite, 12, 10);
    fastfill(ImageWaveStyle3Sprite.data, ImageWaveStyle3Sprite.width * ImageWaveStyle3Sprite.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle3Sprite, x + 0, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 1, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 2, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 3, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 4, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 5, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 5, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 6, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 7, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 8, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 9, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle3Sprite, x + 10, y - 0, Theme_RadioButton_Color);


    allocImage(ImageWaveStyle3SpriteOver, 12, 10);
    fastfill(ImageWaveStyle3SpriteOver.data, ImageWaveStyle3SpriteOver.width * ImageWaveStyle3SpriteOver.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 0, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 1, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 2, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 3, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 4, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 5, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 5, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 6, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 7, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 8, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 9, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle3SpriteOver, x + 10, y - 0, Theme_RadioButton_SelectColor);

    RadioButtonWaveStyle3:= TtuiRadioButton.Create(TopPanel, 'RadioButtonWaveStyle3', 329, 158 + 16 + 16, ImageWaveStyle3Sprite, ImageWaveStyle3SpriteOver, @execProcRadioButtonWaveStyle3);
    RadioButtonWaveStyle3.theme:= LoadThemeRadioButton;
    RadioButtonGroupWaveStyle.add2group(RadioButtonWaveStyle3);


    x:= 0;
    y:= 4;

    allocImage(ImageWaveStyle4Sprite, 12, 10);
    fastfill(ImageWaveStyle4Sprite.data, ImageWaveStyle4Sprite.width * ImageWaveStyle4Sprite.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle4Sprite, x + 0, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 1, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 2, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 3, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 4, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y - 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y - 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y - 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 5, y - 4, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 6, y + 3, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 7, y + 2, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 8, y + 1, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 9, y + 0, Theme_RadioButton_Color);
    putpixel(ImageWaveStyle4Sprite, x + 10, y - 1, Theme_RadioButton_Color);



    allocImage(ImageWaveStyle4SpriteOver, 12, 10);
    fastfill(ImageWaveStyle4SpriteOver.data, ImageWaveStyle4SpriteOver.width * ImageWaveStyle4SpriteOver.height, Theme_InstrumentEditor_MainPanel_BackgroundColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 0, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 1, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 2, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 3, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 4, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y - 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y - 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y - 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 5, y - 4, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 6, y + 3, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 7, y + 2, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 8, y + 1, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 9, y + 0, Theme_RadioButton_SelectColor);
    putpixel(ImageWaveStyle4SpriteOver, x + 10, y - 1, Theme_RadioButton_SelectColor);
     
    RadioButtonWaveStyle4:= TtuiRadioButton.Create(TopPanel, 'RadioButtonWaveStyle4', 364, 158 + 16, ImageWaveStyle4Sprite, ImageWaveStyle4SpriteOver, @execProcRadioButtonWaveStyle4);
    RadioButtonWaveStyle4.theme:= LoadThemeRadioButton;
    RadioButtonGroupWaveStyle.add2group(RadioButtonWaveStyle4);




    RadioButtonWaveStyle5:= TtuiRadioButton.Create(TopPanel, 'RadioButtonWaveStyle5', 364, 158 + 16 + 16, 'random', @execProcRadioButtonWaveStyle5);
    RadioButtonWaveStyle5.theme:= LoadThemeRadioButton;
    RadioButtonGroupWaveStyle.add2group(RadioButtonWaveStyle5);


    RadioButtonGroupLoopSustainOrNormal:= TtuiRadioButtonGroup.Create(TopPanel, 'RadioButtonGroupLoopSustainOrNormal');
    TopPanel.addItem(RadioButtonGroupLoopSustainOrNormal);

    RadioButtonLoopNormal:= TtuiRadioButton.Create(TopPanel, 'RadioButtonLoopNormal', 216, 158 + 16, 'Standart Loop', @execProcRadioButtonLoopNormal);
    RadioButtonLoopNormal.theme:= LoadThemeRadioButton;
    RadioButtonGroupLoopSustainOrNormal.add2group(RadioButtonLoopNormal);

    RadioButtonLoopSustain:= TtuiRadioButton.Create(TopPanel, 'RadioButtonLoopSustain', 216, 158 + 16 + 16, 'Sustain Loop', @execProcRadioButtonSustain);
    RadioButtonLoopSustain.theme:= LoadThemeRadioButton;
    RadioButtonGroupLoopSustainOrNormal.add2group(RadioButtonLoopSustain);

    RadioButtonGroupLoopSustainOrNormal.uncheckAll;
    RadioButtonLoopNormal.checked:= true;

end;


procedure TInstrumentEditor.doRadioButtonWaveStyle1;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoType:= svtSine;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonWaveStyle1(const param: string);
begin

    netSendRadioButtonWaveStyle1;

    doRadioButtonWaveStyle1;

end;


procedure TInstrumentEditor.doRadioButtonWaveStyle2;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoType:= svtSquareIT;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonWaveStyle2(const param: string);
begin
    
    netSendRadioButtonWaveStyle2;

    doRadioButtonWaveStyle2;

end;


procedure TInstrumentEditor.doRadioButtonWaveStyle3;
begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoType:= svtRampDownIT;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonWaveStyle3(const param: string);
begin

    netSendRadioButtonWaveStyle3;

    doRadioButtonWaveStyle3;

end;


procedure TInstrumentEditor.doRadioButtonWaveStyle4;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoType:= svtRampUpFT2;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonWaveStyle4(const param: string);
begin

    netSendRadioButtonWaveStyle4;

    doRadioButtonWaveStyle4;

end;


procedure TInstrumentEditor.doRadioButtonWaveStyle5;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoType:= svtRandom;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonWaveStyle5(const param: string);
begin

    netSendRadioButtonWaveStyle5;

    doRadioButtonWaveStyle5;

end;







procedure TInstrumentEditor.execProcScrollBarVibratoSpeed(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoSpeed:= ScrollBarVibratoSpeed.curValue;
        TextFiledVibratoSpeed.caption:= 'Vibrato Speed ' + numstr(ScrollBarVibratoSpeed.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;    
end;


procedure TInstrumentEditor.execProcScrollBarVibratoDepth(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoDepth:= ScrollBarVibratoDepth.curValue;
        TextFiledVibratoDepth.caption:= 'Vibrato Depth ' + numstr(ScrollBarVibratoDepth.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;    
end;




procedure TInstrumentEditor.execProcScrollBarVibratoSweep(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);        
        Module.samples[CurrentSample].VibratoRateOrSweep:= ScrollBarVibratoSweep.curValue;
        TextFiledVibratoSweep.caption:= 'Vibrato Sweep ' + numstr(ScrollBarVibratoSweep.curValue);
    tralalaEngine.Unlock_Module_ReadWrite;
end;


procedure TInstrumentEditor.execProcScrollBarFineTune(const param: string);
begin
    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.samples[CurrentSample].BaseFineTune:= ScrollBarFineTune.curValue - 128;
        TextFieldFineTune.caption:= 'Fine Tune ' + numstr(ScrollBarFineTune.curValue - 128);
    tralalaEngine.Unlock_Module_ReadWrite;    
end;





procedure TInstrumentEditor.doButtonLoopStart(value: longint);
var
    i : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
    
        Module.samples[CurrentSample].LoopStart:= value;
        TextFiledLoopStart.caption:= 'Loop Start at ' + numstr(value);

        toucherLeftPos:= value * (vscreen.width - 1) div Module.Samples[CurrentSample].Data.Length;

        if toucherLeftPos >= toucherRightPos then begin
            toucherLeftPos:= toucherRightPos;
            i:= toucherLeftPos * Module.Samples[CurrentSample].Data.Length div (vscreen.width - 1);
            Module.samples[CurrentSample].LoopStart:= i;
        end;
    
    tralalaEngine.Unlock_Module_ReadWrite;


    if RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked then 
            updateToucher;

end;

procedure TInstrumentEditor.execProcButtonUPLoopStart(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and RadioButtonLoopNormal.checked then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);

            i:= Module.samples[CurrentSample].LoopStart;

            inc(i);

            if i >= Module.samples[CurrentSample].data.Length then i:= Module.samples[CurrentSample].data.Length;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonLoopStart(i);

        netSendButtonUPLoopStart(i);

    end;

end;


procedure TInstrumentEditor.execProcButtonDOWNLoopStart(const param: string);
var 
    i : longint;
begin
    
    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and RadioButtonLoopNormal.checked then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);
            
            i:= Module.samples[CurrentSample].LoopStart;

            dec(i);

            if i <= 0 then i:= 0;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonLoopStart(i);

        netSendButtonDOWNLoopStart(i);

            
    end;

end;


procedure TInstrumentEditor.doButtonLoopEnd(value: longint);
var
    i : longint;

begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.samples[CurrentSample].LoopEnd:= value;
        TextFiledLoopEnd.caption:= 'Loop End at ' + numstr(value);

        toucherRightPos:= value * (vscreen.width - 1) div Module.Samples[CurrentSample].Data.Length;
            

        if toucherRightPos <= toucherLeftPos then begin
            toucherRightPos:= toucherLeftPos;
            i:= toucherRightPos * Module.Samples[CurrentSample].Data.Length div (vscreen.width - 1);
            Module.samples[CurrentSample].LoopEnd:= i;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

    if RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked then 
        updateToucher;

end;

procedure TInstrumentEditor.execProcButtonUPLoopEnd(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and RadioButtonLoopNormal.checked then begin
        
        tralalaEngine.Lock_Module_ReadWrite(Module);
                
            i:= Module.samples[CurrentSample].LoopEnd;
            inc(i);
            if i >= Module.samples[CurrentSample].data.Length then i:= Module.samples[CurrentSample].data.Length;
            
        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonLoopEnd(i);
        netSendButtonUPLoopEnd(i);

    end;
end;


procedure TInstrumentEditor.execProcButtonDOWNLoopEnd(const param: string);
var 
    i : longint;
begin
    
    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and RadioButtonLoopNormal.checked then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);

            i:= Module.samples[CurrentSample].LoopEnd;
            dec(i);
            if i <= 0 then i:= 0;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonLoopEnd(i);

        netSendButtonDOWNLoopEnd(i);

    end;

end;


procedure TInstrumentEditor.doButtonSustainLoopStart(value: longint);
var
    i : longint;
begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.samples[CurrentSample].SustainLoopStart:= value;

        TextFiledSustainLoopStart.caption:= 'Sustain Loop Start at ' + numstr(value);

        toucherLeftPos:= value * (vscreen.width - 1) div Module.Samples[CurrentSample].Data.Length;

        if toucherLeftPos >= toucherRightPos then begin

            toucherLeftPos:= toucherRightPos;
            i:= toucherLeftPos * Module.Samples[CurrentSample].Data.Length div (vscreen.width - 1);
            Module.samples[CurrentSample].SustainLoopStart:= i;

        end;

    tralalaEngine.Unlock_Module_ReadWrite;

    if RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked then 
            updateToucher;

end;



procedure TInstrumentEditor.execProcButtonUPSustainLoopStart(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and (not RadioButtonLoopNormal.checked) then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);

            i:= Module.samples[CurrentSample].SustainLoopStart;

            inc(i);

            if i >= Module.samples[CurrentSample].data.Length then i:= Module.samples[CurrentSample].data.Length;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonSustainLoopStart(i);

        netSendButtonUPSustainLoopStart(i);
       
    end;

end;


procedure TInstrumentEditor.execProcButtonDOWNSustainLoopStart(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and (not RadioButtonLoopNormal.checked) then begin
    
        tralalaEngine.Lock_Module_ReadWrite(Module);
            
            i:= Module.samples[CurrentSample].SustainLoopStart;

            dec(i);
            if i <= 0 then i:= 0;


        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonSustainLoopStart(i);

        netSendButtonDOWNSustainLoopStart(i);

    end;

end;


procedure TInstrumentEditor.doButtonSustainLoopEnd(value: longint);
var 
    i : longint;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.samples[CurrentSample].SustainLoopEnd:= value;
        TextFiledSustainLoopEnd.caption:= 'Sustain Loop End at ' + numstr(value);

        toucherRightPos:= value * (vscreen.width - 1) div Module.Samples[CurrentSample].Data.Length;
            

        if toucherRightPos <= toucherLeftPos then begin
            toucherRightPos:= toucherLeftPos;
            i:= toucherRightPos * Module.Samples[CurrentSample].Data.Length div (vscreen.width - 1);
            Module.samples[CurrentSample].SustainLoopEnd:= i;
        end;


    tralalaEngine.Unlock_Module_ReadWrite;
    
    if RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked then 
            updateToucher;

end;


procedure TInstrumentEditor.execProcButtonUPSustainLoopEnd(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and (not RadioButtonLoopNormal.checked) then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);
                
            i:= Module.samples[CurrentSample].SustainLoopEnd;

            inc(i);
            if i >= Module.samples[CurrentSample].data.Length then i:= Module.samples[CurrentSample].data.Length;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonSustainLoopEnd(i);

        netSendButtonUPSustainLoopEnd(i);
        
    end;

end;


procedure TInstrumentEditor.execProcButtonDOWNSustainLoopEnd(const param: string);
var 
    i : longint;
begin

    if (RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked) and (not RadioButtonLoopNormal.checked) then begin

        tralalaEngine.Lock_Module_ReadWrite(Module);

            i:= Module.samples[CurrentSample].SustainLoopEnd;

            dec(i);
            if i <= 0 then i:= 0;

        tralalaEngine.Unlock_Module_ReadWrite;

        doButtonSustainLoopEnd(i);

        netSendButtonDOWNSustainLoopEnd(i);

    end;

end;




procedure TInstrumentEditor.execProcNotImplemented(const param: string);
begin
    
    aDialog:= TtuiDialogMessageBox.Create(@aDialog, InstrumentEditorTUI, 'Not implmented jet');

end;


procedure TInstrumentEditor.reloadTopPanel;
begin
    
    currentSample:= CurrentInstrument;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);


        if Module.samples[CurrentSample].VibratoType = svtSine then begin    
            RadioButtonGroupWaveStyle.uncheckAll;
            RadioButtonWaveStyle1.checked:= true;
        end;
        if (Module.samples[CurrentSample].VibratoType = svtSquareIT) or (Module.samples[CurrentSample].VibratoType = svtSquareFT2) then begin
            RadioButtonGroupWaveStyle.uncheckAll;
            RadioButtonWaveStyle2.checked:= true;
        end;
        if (Module.samples[CurrentSample].VibratoType = svtRampDownIT) or (Module.samples[CurrentSample].VibratoType = svtRampDownFT2) then begin
            RadioButtonGroupWaveStyle.uncheckAll;
            RadioButtonWaveStyle3.checked:= true;
        end;
        if Module.samples[CurrentSample].VibratoType = svtRampUpFT2 then begin    
            RadioButtonGroupWaveStyle.uncheckAll;
            RadioButtonWaveStyle4.checked:= true;
        end;
        if Module.samples[CurrentSample].VibratoType = svtRandom then begin    
            RadioButtonGroupWaveStyle.uncheckAll;
            RadioButtonWaveStyle5.checked:= true;
        end;

        if RadioButtonLoopNormal.checked then begin
            if Module.samples[CurrentSample].LoopType = sltNoLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypeNoLoop.checked:= true;
            end;
            if Module.samples[CurrentSample].LoopType = sltForwardLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypeForward.checked:= true;
            end;
            if Module.samples[CurrentSample].LoopType = sltPingPongLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypePingPong.checked:= true;
            end;      
        end else begin        
            if Module.samples[CurrentSample].SustainLoopType = sltNoLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypeNoLoop.checked:= true;
            end;
            if Module.samples[CurrentSample].SustainLoopType = sltForwardLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypeForward.checked:= true;
            end;
            if Module.samples[CurrentSample].SustainLoopType = sltPingPongLoop then begin
                RadioButtonGroupLoopType.uncheckAll;
                RadioButtonLoopTypePingPong.checked:= true;
            end;
        end;


        TextFiledSampleLength.caption:= 'Sample length is ' + numstr(Module.samples[CurrentSample].data.Length);
        TextFiledLoopStart.caption:= 'Loop Start at ' + numstr(Module.samples[CurrentSample].LoopStart);
        TextFiledLoopEnd.caption:= 'Loop End at ' + numstr(Module.samples[CurrentSample].LoopEnd);
        TextFiledSustainLoopStart.caption:= 'Sustain Loop Start at ' + numstr(Module.samples[CurrentSample].SustainLoopStart);
        TextFiledSustainLoopEnd.caption:= 'Sustain Loop End at ' + numstr(Module.samples[CurrentSample].SustainLoopEnd);

        ScrollBarVibratoSpeed.setCurValue(Module.samples[CurrentSample].VibratoSpeed);
        TextFiledVibratoSpeed.caption:= 'Vibrato Speed ' + numstr(ScrollBarVibratoSpeed.curValue);
        
        ScrollBarVibratoDepth.setCurValue(Module.samples[CurrentSample].VibratoDepth);
        TextFiledVibratoDepth.caption:= 'Vibrato Depth ' + numstr(ScrollBarVibratoDepth.curValue);

        ScrollBarVibratoSweep.setCurValue(Module.samples[CurrentSample].VibratoRateOrSweep);
        TextFiledVibratoSweep.caption:= 'Vibrato Sweep ' + numstr(ScrollBarVibratoSweep.curValue);

        ScrollBarFineTune.setCurValue(Module.samples[CurrentSample].BaseFineTune + 128);
        TextFieldFineTune.caption:= 'Fine Tune '+numstr(ScrollBarFineTune.curValue - 128);

        
        if Module.samples[CurrentSample].data.Bits = 8 then begin
            RadioButtonSampleBits8.checked:= true;
            RadioButtonSampleBits16.checked:= false;
        end;
        if Module.samples[CurrentSample].data.Bits = 16 then begin
            RadioButtonSampleBits8.checked:= false;
            RadioButtonSampleBits16.checked:= true;
        end;


        if not Module.samples[CurrentSample].data.Stereo then begin
            RadioButtonSampleMono.checked:= true;
            RadioButtonSampleStereo.checked:= false;
        end;
        if Module.samples[CurrentSample].data.Stereo then begin
            RadioButtonSampleMono.checked:= false;
            RadioButtonSampleStereo.checked:= true;
        end;


    tralalaEngine.Unlock_ReadOnly;

    instrumentSelector.reloadInstrumentSelector(false);
    instrumentSelector.onInstrumentSelect:= @execProcOnInstrumentSelect;    

end;


procedure TInstrumentEditor.doRadioButtonLoopType;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

    
    if RadioButtonLoopTypeNoLoop.checked then begin 
        RadioButtonGroupLoopType.uncheckAll;
        
        if RadioButtonLoopNormal.checked then begin
            Module.samples[CurrentSample].LoopType:= sltNoLoop;
        end else begin
            Module.samples[CurrentSample].SustainLoopType:= sltNoLoop;
        end;

        RadioButtonLoopTypeNoLoop.checked:= true;
    end;


    if RadioButtonLoopTypeForward.checked then begin
        RadioButtonGroupLoopType.uncheckAll;
        
        if RadioButtonLoopNormal.checked then begin
            Module.samples[CurrentSample].LoopType:= sltForwardLoop;
        end else begin
            Module.samples[CurrentSample].SustainLoopType:= sltForwardLoop;
         end;    

        RadioButtonLoopTypeForward.checked:= true;
    end;


    if RadioButtonLoopTypePingPong.checked then begin 
        RadioButtonGroupLoopType.uncheckAll;

        if RadioButtonLoopNormal.checked then begin
            Module.samples[CurrentSample].LoopType:= sltPingPongLoop;
        end else begin
            Module.samples[CurrentSample].SustainLoopType:= sltPingPongLoop;
         end;    

        RadioButtonLoopTypePingPong.checked:= true;
    end;
    
    tralalaEngine.Unlock_Module_ReadWrite;

    reloadTopPanel;
    getToucherLeftRightPos;

end;


procedure TInstrumentEditor.execProcRadioButtonLoopTypeNoLoop(const param: string);
begin

    netSendRadioButtonLoopTypeNoLoop;

    doRadioButtonLoopType;

end;


procedure TInstrumentEditor.execProcRadioButtonLoopTypeForwardLoop(const param: string);
begin

    netSendRadioButtonLoopTypeForwardLoop;

    doRadioButtonLoopType;

end;


procedure TInstrumentEditor.execProcRadioButtonLoopTypePingPongLoop(const param: string);
begin

    netSendRadioButtonLoopTypePingPongLoop;

    doRadioButtonLoopType;

end;


procedure TInstrumentEditor.doRadioButtonSampleBits8;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if Module.samples[CurrentSample].data.Bits = 16 then begin
            Module.samples[CurrentSample].data.Convert16To8Bits;


            drawWaveStart:= 0;
            drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes;

            selectedBlockStart:= -1;
            selectedBlockEnd:= -1;
            drawSelectedBlockStart:= -1;
            drawSelectedBlockEnd:= -1;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;
end;

procedure TInstrumentEditor.execProcRadioButtonSampleBits8(const param: string);
begin

    netSendRadioButtonSampleBits8;

    doRadioButtonSampleBits8;

end;

procedure TInstrumentEditor.doRadioButtonSampleBits16;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if Module.samples[CurrentSample].data.Bits = 8 then begin
            Module.samples[CurrentSample].data.Convert8To16Bits;
            
            aDialog:= TtuiDialogMessageBox.Create(@aDialog, InstrumentEditorTUI, 'It makes no sence to convert' + #13 + ' 8bit to 16bit, but ok');

            drawWaveStart:= 0;
            drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes;

            selectedBlockStart:= -1;
            selectedBlockEnd:= -1;
            drawSelectedBlockStart:= -1;
            drawSelectedBlockEnd:= -1;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonSampleBits16(const param: string);
begin
    
    netSendRadioButtonSampleBits16;

    doRadioButtonSampleBits16;

end;


procedure TInstrumentEditor.doRadioButtonSampleMono;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if Module.samples[CurrentSample].data.Stereo then begin
            Module.samples[CurrentSample].data.ConvertStereoToMono;

            drawWaveStart:= 0;
            drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes;

            selectedBlockStart:= -1;
            selectedBlockEnd:= -1;
            drawSelectedBlockStart:= -1;
            drawSelectedBlockEnd:= -1;

        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcRadioButtonSampleMono(const param: string);
begin

    netSendRadioButtonSampleMono;

    doRadioButtonSampleMono;

end;


procedure TInstrumentEditor.doRadioButtonSampleStereo;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
     
        if not Module.samples[CurrentSample].data.Stereo then begin
            Module.samples[CurrentSample].data.ConvertMonoToStereo;
            
            aDialog:= TtuiDialogMessageBox.Create(@aDialog, InstrumentEditorTUI, 'It makes no sence to convert Mono to Stereo, but ok');
            
            drawWaveStart:= 0;
            drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes;

            selectedBlockStart:= -1;
            selectedBlockEnd:= -1;
            drawSelectedBlockStart:= -1;
            drawSelectedBlockEnd:= -1;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.execProcRadioButtonSampleStereo(const param: string);
begin

    netSendRadioButtonSampleStereo;

    doRadioButtonSampleStereo;

end;




procedure TInstrumentEditor.buildScrollbar;
begin
    
    ScrollBarBox:= TtuiBox.create(InstrumentEditorTUI, 0, 632 - 200 - 20, 1280, 18, 'InstrumentScrollBarBox', tuiBoxStatic);
    ScrollBarBox.ThemeBox:= LoadThemeBox;
    ScrollBarBox.ThemeBox.BackgroundColor:= Theme_InstrumentEditor_MainPanel_BackgroundColor;
    InstrumentEditorTUI.addBox(ScrollBarBox);


    mainScrollBar:= TtuiScrollBarHorizontal.Create(ScrollBarBox, 'InstrumentScrollBar', 0, 0, 1280, 18, @ScrollBarInstrumentEditorMainProc);
    mainScrollBar.theme:= LoadThemeScrollbarHorizontal;
    ScrollBarBox.addItem(mainScrollBar);
    mainScrollBar.resetMaxValue(0);

end;


procedure TInstrumentEditor.doRadioButtonLoop;
begin

    reloadTopPanel;
    getToucherLeftRightPos;

end;

procedure TInstrumentEditor.execProcRadioButtonLoopNormal(const param: string);
begin
    
    netSendRadioButtonLoopNormal;

    doRadioButtonLoop;

end;


procedure TInstrumentEditor.execProcRadioButtonSustain(const param: string);
begin
    
    netSendRadioButtonLoopSustain;

    doRadioButtonLoop;

end;


procedure TInstrumentEditor.execProcNewNoteActionNoteCut(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].NewNoteAction:= nnaCut;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcNewNoteActionNoteContinue(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].NewNoteAction:= nnaContinue;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcNewNoteActionNoteOff(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].NewNoteAction:= nnaOff;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcNewNoteActionNoteFade(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].NewNoteAction:= nnaFade;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcDuplicateCheckTypeDisabled(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateNoteCheck:= dncOff;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcDuplicateCheckTypeNote(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateNoteCheck:= dncNote;
    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.execProcDuplicateCheckTypeSample(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateNoteCheck:= dncSample;
    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TInstrumentEditor.execProcDuplicateCheckTypeInstrument(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateNoteCheck:= dncInstrument;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcDuplicateCheckActionCut(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateCheckAction:= dcaCut;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcDuplicateCheckActionOff(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateCheckAction:= dcaOff;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.execProcDuplicateCheckActionFade(const param: string);
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.instruments[CurrentInstrument].DuplicateCheckAction:= dcaFade;
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.doButtonStop;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonStop(const param: string);
begin

    doButtonStop;

    netSendButtonStopWave;

end;


procedure TInstrumentEditor.doButtonWave;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonWave(const param: string);
begin

    doButtonWave;

    netSendButtonPlayWave;

end;


procedure TInstrumentEditor.doButtonRange;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonRange(const param: string);
begin

    doButtonRange;

    netSendButtonWaveRange;

end;


procedure TInstrumentEditor.doButtonDisplay;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonDisplay(const param: string);
begin

    doButtonDisplay;

    netSendButtonWaveDisplay;

end;


procedure TInstrumentEditor.doButtonVolume;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonWaveVolume(const param: string);
begin

    doButtonVolume;

    netSendButtonWaveVolume;

end;


procedure TInstrumentEditor.doButtonXFade;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonXFade(const param: string);
begin

    doButtonXFade;

    netSendButtonXFade;

end;


procedure TInstrumentEditor.doButtonCut;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonCut(const param: string);
begin

    doButtonCut;

    netSendButtonCut;

end;


procedure TInstrumentEditor.doButtonCopy;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonCopy(const param: string);
begin

    doButtonCopy;

    netSendButtonCopy;

end;


procedure TInstrumentEditor.doButtonPaste;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonPaste(const param: string);
begin

    doButtonPaste;

    netSendButtonPaste;

end;


procedure TInstrumentEditor.doButtonCrop;
begin

    execProcNotImplemented('');

end;


procedure TInstrumentEditor.execProcButtonCrop(const param: string);
begin

    doButtonCrop;

    netSendButtonCrop;
end;