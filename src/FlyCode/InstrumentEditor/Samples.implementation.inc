procedure TInstrumentEditor.BuildSamples;
var
	i : longint;	

begin
  
    TextBoxSampleDriven:= TtuiTextBox.Create(TopPanel, 'TextBox Sample Driven', 1280 - 222 - 222 - 2, 1, 222, 200 - 2);
    TextBoxSampleDriven.theme:= LoadThemeTextBox;
    TextBoxSampleDriven.theme.borderColor:= Theme_SelectBox_BorderColor;

    TopPanel.addItem(TextBoxSampleDriven);
    TextBoxSampleDriven.loadText(#10#13 + #10#13 + #10#13 + 'Module' + #10#13 + '                is in' + #10#13 + '                         sample driven' + #10#13 + '                                                    mode');


    SampleSelector:= TtuiEditableSelectBoxNumbered.create(TopPanel, 'SampleSelector', 1280 - 222 - 222 - 2, 1, 222, 200 - 2, @execProcSampleSelectorClick);
    SampleSelector.theme:= LoadThemeEditableSelectBoxNumbered;
    SampleSelector.theme.GlobalYoffset:= 4;
    TopPanel.addItem(SampleSelector);
    
     for i:= 0 to 99 do begin
        SampleSelector.addString('');
        SampleSelector.strings[i].Color:= Theme_Tracker_EmptyInstrumentColor;
    end;

    SampleSelector.exec;
	selectedNote:= -1;

	reloadSamples;

end;



procedure TInstrumentEditor.reloadSamples;
var 
    i : longint;	

begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick); 
    if mfInstrumentsControl in Module.Flags then begin
        tralalaEngine.Unlock_ReadOnly;
        SampleSelector.enabled:= true;
        TextBoxSampleDriven.enabled:= false;
    end else begin
        tralalaEngine.Unlock_ReadOnly;
        SampleSelector.enabled:= false;
        TextBoxSampleDriven.enabled:= true;
        exit;
    end;


	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        for i:= 0 to 99 do begin        
            SampleSelector.strings[i].theString:= Module.Samples.Sample[i + 1].name;  
            SampleSelector.strings[i].Color:= Theme_Tracker_EmptyInstrumentColor;    
        end;

    	for i:= NoteMin to NoteMax - 1 do begin  
        	if Module.Instruments.Instrument[currentInstrument].Mapping[i + 1].Sample > 0 then begin
        		SampleSelector.strings[Module.Instruments.Instrument[currentInstrument].Mapping[i + 1].Sample - 1].Color:= Theme_Tracker_MainPanel_FontColor;
        	end;

        end;             

	tralalaEngine.Unlock_ReadOnly;
    
    SampleSelector.reset(false);
    SampleSelector.reloadEditFields;

end;	


procedure TInstrumentEditor.execProcSampleSelectorClick(const param: string);
begin

	reloadSamples;
    reloadMapping;

end;


procedure TInstrumentEditor.attachSamples2PianoKey;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.Instruments.Instrument[currentInstrument].Mapping[selectedNote+12].Note:= mappedNote;
        Module.Instruments.Instrument[currentInstrument].Mapping[selectedNote+12].Sample:= SampleSelector.curChosen + 1;
        
        noteTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MappedNoteSelectedColor;
        mappednoteTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MappedNoteSelectedColor;
        mappedSampleTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MappedNoteSelectedColor;

        inChoseMode:= false;
        
    tralalaEngine.Unlock_Module_ReadWrite; 

    reloadSamples;
    reloadMapping;

    setlength(freshMappedSampleOnPanoKey[currentInstrument], length(freshMappedSampleOnPanoKey[currentInstrument]) + 1);
    freshMappedSampleOnPanoKey[currentInstrument, length(freshMappedSampleOnPanoKey[currentInstrument]) - 1]:= selectedNote;

end;


procedure TInstrumentEditor.selectingSamples;
var 
    i : longint;
    note : longint;

begin

    if selectedNote = -1 then exit;

    i:= isPianoWhiteKeyMouseOver;
    if i <> -1 then begin 
        note:=convertWhiteKey2noteNumber(i);
    end;
    
    i:= isPianoBlackKeyMouseOver;        
    if i <> -1 then begin
        note:=convertBlackKey2noteNumber(i);
    end;
    

    if note <> NoteCut then CurrentNoteTextField.caption:= 'Current Note: ' + NoteValueTo3Str(note) else CurrentNoteTextField.caption:= 'Current Note: ';

    attachSamples2PianoKey;

end;


procedure TInstrumentEditor.MakeNoteChosen(note: longint);
begin

    if note > 100 then exit;

    ClearMappingTextFieldColors(true);

    noteTextField[note].theme.FontColor:= Theme_InstrumentEditor_MappedChosenColor;
    mappednoteTextField[note].theme.FontColor:= Theme_InstrumentEditor_MappedChosenColor;
    mappedSampleTextField[note].theme.FontColor:= Theme_InstrumentEditor_MappedChosenColor;
    noteTextField[note].theme.HighlightOnMouseOver:= false;

    selectedNote:= note;

    selectionRangeStart:= selectedNote;
    selectionRangeEnd:= selectedNote;

    inChoseMode:= true;

end;


procedure TInstrumentEditor.drawPianoSamples;
var 
    i, note : longint;

begin

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
    for i:= 0 to length(freshMappedSampleOnPanoKey[currentInstrument]) - 1 do begin
            note:= freshMappedSampleOnPanoKey[currentInstrument, i];
            case (note) of
                0  : drawHline(PianoImage, 17, 32, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                1  : drawHline(PianoImage, 32, 47, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                2  : drawHline(PianoImage, 47, 57, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                3  : drawHline(PianoImage, 57, 71, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                4  : drawHline(PianoImage, 71, 85, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                5  : drawHline(PianoImage, 89, 104, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                6  : drawHline(PianoImage, 104, 119, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                7  : drawHline(PianoImage, 119, 129, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                8  : drawHline(PianoImage, 129, 143, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                9  : drawHline(PianoImage, 143, 153, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                10 : drawHline(PianoImage, 153, 167, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                11 : drawHline(PianoImage, 167, 181, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                12 : drawHline(PianoImage, 185, 200, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                13 : drawHline(PianoImage, 200, 215, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                14 : drawHline(PianoImage, 215, 224, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                15 : drawHline(PianoImage, 224, 239, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                16 : drawHline(PianoImage, 239, 253, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       

                17 : drawHline(PianoImage, 257, 272, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                18 : drawHline(PianoImage, 272, 287, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                19 : drawHline(PianoImage, 287, 296, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                20 : drawHline(PianoImage, 296, 311, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                21 : drawHline(PianoImage, 311, 320, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                22 : drawHline(PianoImage, 320, 335, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                23 : drawHline(PianoImage, 335, 350, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       

                24 : drawHline(PianoImage, 353, 368, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                25 : drawHline(PianoImage, 368, 383, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                26 : drawHline(PianoImage, 383, 393, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                27 : drawHline(PianoImage, 393, 406, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                28 : drawHline(PianoImage, 406, 421, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       

                29 : drawHline(PianoImage, 425, 440, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                30 : drawHline(PianoImage, 440, 455, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                31 : drawHline(PianoImage, 455, 464, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                32 : drawHline(PianoImage, 464, 479, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                33 : drawHline(PianoImage, 479, 489, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                34 : drawHline(PianoImage, 489, 504, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       
                35 : drawHline(PianoImage, 504, 517, 0, Theme_InstrumentEditor_KeyBoardSampledColor);       

                36 : drawHline(PianoImage, 521, 536, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                37 : drawHline(PianoImage, 536, 551, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                38 : drawHline(PianoImage, 551, 560, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                39 : drawHline(PianoImage, 560, 575, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                40 : drawHline(PianoImage, 575, 589, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                41 : drawHline(PianoImage, 593, 607, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                42 : drawHline(PianoImage, 607, 622, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                43 : drawHline(PianoImage, 622, 631, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                44 : drawHline(PianoImage, 631, 646, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                45 : drawHline(PianoImage, 646, 656, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                46 : drawHline(PianoImage, 656, 671, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                47 : drawHline(PianoImage, 671, 685, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                48 : drawHline(PianoImage, 689, 704, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                49 : drawHline(PianoImage, 704, 719, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                50 : drawHline(PianoImage, 719, 728, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                51 : drawHline(PianoImage, 728, 743, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                52 : drawHline(PianoImage, 743, 757, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                53 : drawHline(PianoImage, 761, 776, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                54 : drawHline(PianoImage, 776, 790, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                55 : drawHline(PianoImage, 790, 800, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                56 : drawHline(PianoImage, 800, 813, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                57 : drawHline(PianoImage, 813, 824, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                58 : drawHline(PianoImage, 824, 838, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                59 : drawHline(PianoImage, 838, 853, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                60 : drawHline(PianoImage, 857, 872, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                61 : drawHline(PianoImage, 872, 887, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                62 : drawHline(PianoImage, 887, 897, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                63 : drawHline(PianoImage, 897, 911, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                64 : drawHline(PianoImage, 911, 925, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                65 : drawHline(PianoImage, 929, 944, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                66 : drawHline(PianoImage, 944, 959, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                67 : drawHline(PianoImage, 959, 968, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                68 : drawHline(PianoImage, 968, 983, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                69 : drawHline(PianoImage, 983, 992, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                70 : drawHline(PianoImage, 992, 1007, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                71 : drawHline(PianoImage, 1007, 1021, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                72 : drawHline(PianoImage, 1025, 1040, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                73 : drawHline(PianoImage, 1040, 1055, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                74 : drawHline(PianoImage, 1055, 1064, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                75 : drawHline(PianoImage, 1064, 1078, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                76 : drawHline(PianoImage, 1078, 1093, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                77 : drawHline(PianoImage, 1097, 1112, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                78 : drawHline(PianoImage, 1112, 1127, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                79 : drawHline(PianoImage, 1127, 1137, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                80 : drawHline(PianoImage, 1137, 1150, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                81 : drawHline(PianoImage, 1150, 1160, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                82 : drawHline(PianoImage, 1160, 1175, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                83 : drawHline(PianoImage, 1175, 1189, 0, Theme_InstrumentEditor_KeyBoardSampledColor);

                84 : drawHline(PianoImage, 1193, 1208, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                85 : drawHline(PianoImage, 1208, 1223, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                86 : drawHline(PianoImage, 1223, 1232, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                87 : drawHline(PianoImage, 1232, 1246, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
                88 : drawHline(PianoImage, 1246, 1261, 0, Theme_InstrumentEditor_KeyBoardSampledColor);
            end;
        end;

    tralalaEngine.Unlock_ReadOnly;
    
end;



