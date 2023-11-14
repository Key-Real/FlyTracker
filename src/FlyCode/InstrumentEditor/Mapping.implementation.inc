


procedure TInstrumentEditor.buildMapping;
var i : longint;
	execProcNote : array [0..88] of TtuiExecProc;
	execProcMouseOverNote : array [0..88] of TtuiExecProc;

begin

	execProcNote[0]:= @execProcNote0;
	execProcNote[1]:= @execProcNote1;
	execProcNote[2]:= @execProcNote2;
	execProcNote[3]:= @execProcNote3;
	execProcNote[4]:= @execProcNote4;
	execProcNote[5]:= @execProcNote5;
	execProcNote[6]:= @execProcNote6;
	execProcNote[7]:= @execProcNote7;
	execProcNote[8]:= @execProcNote8;
	execProcNote[9]:= @execProcNote9;
	execProcNote[10]:= @execProcNote10;
	execProcNote[11]:= @execProcNote11;
	execProcNote[12]:= @execProcNote12;
	execProcNote[13]:= @execProcNote13;
	execProcNote[14]:= @execProcNote14;
	execProcNote[15]:= @execProcNote15;
	execProcNote[16]:= @execProcNote16;
	execProcNote[17]:= @execProcNote17;
	execProcNote[18]:= @execProcNote18;
	execProcNote[19]:= @execProcNote19;
	execProcNote[20]:= @execProcNote20;
	execProcNote[21]:= @execProcNote21;
	execProcNote[22]:= @execProcNote22;
	execProcNote[23]:= @execProcNote23;
	execProcNote[24]:= @execProcNote24;
	execProcNote[25]:= @execProcNote25;
	execProcNote[26]:= @execProcNote26;
	execProcNote[27]:= @execProcNote27;
	execProcNote[28]:= @execProcNote28;
	execProcNote[29]:= @execProcNote29;
	execProcNote[30]:= @execProcNote30;
	execProcNote[31]:= @execProcNote31;
	execProcNote[32]:= @execProcNote32;
	execProcNote[33]:= @execProcNote33;
	execProcNote[34]:= @execProcNote34;
	execProcNote[35]:= @execProcNote35;
	execProcNote[36]:= @execProcNote36;
	execProcNote[37]:= @execProcNote37;
	execProcNote[38]:= @execProcNote38;
	execProcNote[39]:= @execProcNote39;
	execProcNote[40]:= @execProcNote40;
	execProcNote[41]:= @execProcNote41;
	execProcNote[42]:= @execProcNote42;
	execProcNote[43]:= @execProcNote43;
	execProcNote[44]:= @execProcNote44;
	execProcNote[45]:= @execProcNote45;
	execProcNote[46]:= @execProcNote46;
	execProcNote[47]:= @execProcNote47;
	execProcNote[48]:= @execProcNote48;
	execProcNote[49]:= @execProcNote49;
	execProcNote[50]:= @execProcNote50;
	execProcNote[51]:= @execProcNote51;
	execProcNote[52]:= @execProcNote52;
	execProcNote[53]:= @execProcNote53;
	execProcNote[54]:= @execProcNote54;
	execProcNote[55]:= @execProcNote55;
	execProcNote[56]:= @execProcNote56;
	execProcNote[57]:= @execProcNote57;
	execProcNote[58]:= @execProcNote58;
	execProcNote[59]:= @execProcNote59;
	execProcNote[60]:= @execProcNote60;
	execProcNote[61]:= @execProcNote61;
	execProcNote[62]:= @execProcNote62;
	execProcNote[63]:= @execProcNote63;
	execProcNote[64]:= @execProcNote64;
	execProcNote[65]:= @execProcNote65;
	execProcNote[66]:= @execProcNote66;
	execProcNote[67]:= @execProcNote67;
	execProcNote[68]:= @execProcNote68;
	execProcNote[69]:= @execProcNote69;
	execProcNote[70]:= @execProcNote70;
	execProcNote[71]:= @execProcNote71;
	execProcNote[72]:= @execProcNote72;
	execProcNote[73]:= @execProcNote73;
	execProcNote[74]:= @execProcNote74;
	execProcNote[75]:= @execProcNote75;
	execProcNote[76]:= @execProcNote76;
	execProcNote[77]:= @execProcNote77;
	execProcNote[78]:= @execProcNote78;
	execProcNote[79]:= @execProcNote79;
	execProcNote[80]:= @execProcNote80;
	execProcNote[81]:= @execProcNote81;
	execProcNote[82]:= @execProcNote82;
	execProcNote[83]:= @execProcNote83;
	execProcNote[84]:= @execProcNote84;
	execProcNote[85]:= @execProcNote85;
	execProcNote[86]:= @execProcNote86;
	execProcNote[87]:= @execProcNote87;
	execProcNote[88]:= @execProcNote88;

	execProcMouseOverNote[0]:= @execProcMouseOverNote0;
	execProcMouseOverNote[1]:= @execProcMouseOverNote1;
	execProcMouseOverNote[2]:= @execProcMouseOverNote2;
	execProcMouseOverNote[3]:= @execProcMouseOverNote3;
	execProcMouseOverNote[4]:= @execProcMouseOverNote4;
	execProcMouseOverNote[5]:= @execProcMouseOverNote5;
	execProcMouseOverNote[6]:= @execProcMouseOverNote6;
	execProcMouseOverNote[7]:= @execProcMouseOverNote7;
	execProcMouseOverNote[8]:= @execProcMouseOverNote8;
	execProcMouseOverNote[9]:= @execProcMouseOverNote9;
	execProcMouseOverNote[10]:= @execProcMouseOverNote10;
	execProcMouseOverNote[11]:= @execProcMouseOverNote11;
	execProcMouseOverNote[12]:= @execProcMouseOverNote12;
	execProcMouseOverNote[13]:= @execProcMouseOverNote13;
	execProcMouseOverNote[14]:= @execProcMouseOverNote14;
	execProcMouseOverNote[15]:= @execProcMouseOverNote15;
	execProcMouseOverNote[16]:= @execProcMouseOverNote16;
	execProcMouseOverNote[17]:= @execProcMouseOverNote17;
	execProcMouseOverNote[18]:= @execProcMouseOverNote18;
	execProcMouseOverNote[19]:= @execProcMouseOverNote19;
	execProcMouseOverNote[20]:= @execProcMouseOverNote20;
	execProcMouseOverNote[21]:= @execProcMouseOverNote21;
	execProcMouseOverNote[22]:= @execProcMouseOverNote22;
	execProcMouseOverNote[23]:= @execProcMouseOverNote23;
	execProcMouseOverNote[24]:= @execProcMouseOverNote24;
	execProcMouseOverNote[25]:= @execProcMouseOverNote25;
	execProcMouseOverNote[26]:= @execProcMouseOverNote26;
	execProcMouseOverNote[27]:= @execProcMouseOverNote27;
	execProcMouseOverNote[28]:= @execProcMouseOverNote28;
	execProcMouseOverNote[29]:= @execProcMouseOverNote29;
	execProcMouseOverNote[30]:= @execProcMouseOverNote30;
	execProcMouseOverNote[31]:= @execProcMouseOverNote31;
	execProcMouseOverNote[32]:= @execProcMouseOverNote32;
	execProcMouseOverNote[33]:= @execProcMouseOverNote33;
	execProcMouseOverNote[34]:= @execProcMouseOverNote34;
	execProcMouseOverNote[35]:= @execProcMouseOverNote35;
	execProcMouseOverNote[36]:= @execProcMouseOverNote36;
	execProcMouseOverNote[37]:= @execProcMouseOverNote37;
	execProcMouseOverNote[38]:= @execProcMouseOverNote38;
	execProcMouseOverNote[39]:= @execProcMouseOverNote39;
	execProcMouseOverNote[40]:= @execProcMouseOverNote40;
	execProcMouseOverNote[41]:= @execProcMouseOverNote41;
	execProcMouseOverNote[42]:= @execProcMouseOverNote42;
	execProcMouseOverNote[43]:= @execProcMouseOverNote43;
	execProcMouseOverNote[44]:= @execProcMouseOverNote44;
	execProcMouseOverNote[45]:= @execProcMouseOverNote45;
	execProcMouseOverNote[46]:= @execProcMouseOverNote46;
	execProcMouseOverNote[47]:= @execProcMouseOverNote47;
	execProcMouseOverNote[48]:= @execProcMouseOverNote48;
	execProcMouseOverNote[49]:= @execProcMouseOverNote49;
	execProcMouseOverNote[50]:= @execProcMouseOverNote50;
	execProcMouseOverNote[51]:= @execProcMouseOverNote51;
	execProcMouseOverNote[52]:= @execProcMouseOverNote52;
	execProcMouseOverNote[53]:= @execProcMouseOverNote53;
	execProcMouseOverNote[54]:= @execProcMouseOverNote54;
	execProcMouseOverNote[55]:= @execProcMouseOverNote55;
	execProcMouseOverNote[56]:= @execProcMouseOverNote56;
	execProcMouseOverNote[57]:= @execProcMouseOverNote57;
	execProcMouseOverNote[58]:= @execProcMouseOverNote58;
	execProcMouseOverNote[59]:= @execProcMouseOverNote59;
	execProcMouseOverNote[60]:= @execProcMouseOverNote60;
	execProcMouseOverNote[61]:= @execProcMouseOverNote61;
	execProcMouseOverNote[62]:= @execProcMouseOverNote62;
	execProcMouseOverNote[63]:= @execProcMouseOverNote63;
	execProcMouseOverNote[64]:= @execProcMouseOverNote64;
	execProcMouseOverNote[65]:= @execProcMouseOverNote65;
	execProcMouseOverNote[66]:= @execProcMouseOverNote66;
	execProcMouseOverNote[67]:= @execProcMouseOverNote67;
	execProcMouseOverNote[68]:= @execProcMouseOverNote68;
	execProcMouseOverNote[69]:= @execProcMouseOverNote69;
	execProcMouseOverNote[70]:= @execProcMouseOverNote70;
	execProcMouseOverNote[71]:= @execProcMouseOverNote71;
	execProcMouseOverNote[72]:= @execProcMouseOverNote72;
	execProcMouseOverNote[73]:= @execProcMouseOverNote73;
	execProcMouseOverNote[74]:= @execProcMouseOverNote74;
	execProcMouseOverNote[75]:= @execProcMouseOverNote75;
	execProcMouseOverNote[76]:= @execProcMouseOverNote76;
	execProcMouseOverNote[77]:= @execProcMouseOverNote77;
	execProcMouseOverNote[78]:= @execProcMouseOverNote78;
	execProcMouseOverNote[79]:= @execProcMouseOverNote79;
	execProcMouseOverNote[80]:= @execProcMouseOverNote80;
	execProcMouseOverNote[81]:= @execProcMouseOverNote81;
	execProcMouseOverNote[82]:= @execProcMouseOverNote82;
	execProcMouseOverNote[83]:= @execProcMouseOverNote83;
	execProcMouseOverNote[84]:= @execProcMouseOverNote84;
	execProcMouseOverNote[85]:= @execProcMouseOverNote85;
	execProcMouseOverNote[86]:= @execProcMouseOverNote86;
	execProcMouseOverNote[87]:= @execProcMouseOverNote87;
	execProcMouseOverNote[88]:= @execProcMouseOverNote88;


	for i:= 0 to 11 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i + 12), 40, 4 + i * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

		mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i + 12), 70, 4 + i * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i + 12), 100, 4 + i * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 12 to 23 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i + 12), 140, 4 + (i - 12) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i + 12), 170, 4 + (i - 12) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i + 12), 200, 4 + (i - 12) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 24 to 35 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 240, 4 + (i - 24) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 270, 4 + (i - 24) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 300, 4 + (i - 24) * 16,'..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 36 to 47 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 340, 4 + (i - 36) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 370, 4 + (i - 36) * 16,NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 400, 4 + (i - 36) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 48 to 59 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 440, 4 + (i - 48) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 470, 4 + (i - 48) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 500, 4 + (i - 48) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 60 to 71 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 540, 4 + (i - 60) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 570, 4 + (i - 60) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 600, 4 + (i - 60) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 72 to 83 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 640, 4 + (i - 72) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);
		
    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 670, 4 + (i - 72) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 700, 4 + (i - 72) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	for i:= 84 to 88 do begin
		noteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'noteTextField' + numstr(i), 740, 4 + (i - 84) * 16, NoteValueTo3Str(i + 12));
    	noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
    	noteTextField[i].theme.HighlightOnMouseOver:= true;
    	noteTextField[i].execProcClick:= execProcNote[i];
    	noteTextField[i].execProcMouseOver:= execProcMouseOverNote[i];
    	EnvelopePanel.addItem(noteTextField[i]);

    	mappedNoteTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedNoteTextField' + numstr(i), 770, 4 + (i - 84) * 16, NoteValueTo3Str(i + 12));
    	mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappednoteTextField[i]);

		mappedSampleTextField[i]:= TtuiTextField.Create(EnvelopePanel, 'mappedSampleTextField' + numstr(i), 800, 4 + (i - 84) * 16, '..');
    	mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
    	EnvelopePanel.addItem(mappedSampleTextField[i]);
	end;

	separationLine1:= TtuiLine.Create(EnvelopePanel, 'separationLine1', 125, 8, 125, 194);
	separationLine1.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine1);
	separationLine2:= TtuiLine.Create(EnvelopePanel, 'separationLine2', 225, 8, 225, 194);
	separationLine2.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine2);
	separationLine3:= TtuiLine.Create(EnvelopePanel, 'separationLine3', 325, 8, 325, 194);
	separationLine3.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine3);
	separationLine4:= TtuiLine.Create(EnvelopePanel, 'separationLine4', 425, 8, 425, 194);
	separationLine4.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine4);
	separationLine5:= TtuiLine.Create(EnvelopePanel, 'separationLine5', 525, 8, 525, 194);
	separationLine5.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine5);
	separationLine6:= TtuiLine.Create(EnvelopePanel, 'separationLine6', 625, 8, 625, 194);
	separationLine6.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine6);
	separationLine7:= TtuiLine.Create(EnvelopePanel, 'separationLine7', 725, 8, 725, 194);
	separationLine7.theme.color:= Theme_InstrumentEditor_MappedLineColor;
	EnvelopePanel.addItem(separationLine7);
	
	ButtonClear:= TtuiButton.create(EnvelopePanel, 'ButtonClear', 731, 144, 90, 24, 'Clear', @execProcButtonClear);
    EnvelopePanel.addItem(ButtonClear);

	ButtonClearAll:= TtuiButton.create(EnvelopePanel, 'ButtonClearAll', 731, 170, 90, 24, 'ClearAll', @execProcButtonClearAll);
    EnvelopePanel.addItem(ButtonClearAll);

end;


procedure TInstrumentEditor.disableMapping;
var 
	i : longint;	

begin

	for i:= 0 to 88 do begin
		noteTextField[i].enabled:= false;
		mappedNoteTextField[i].enabled:= false;
		mappedSampleTextField[i].enabled:= false;
	end;
	ButtonClearAll.enabled:= false;
	ButtonClear.enabled:= false;
	separationLine1.enabled:= false;
	separationLine2.enabled:= false;
	separationLine3.enabled:= false;
	separationLine4.enabled:= false;
	separationLine5.enabled:= false;
	separationLine6.enabled:= false;
	separationLine7.enabled:= false;

	TextFiledNewNoteAction.enabled:= false;
	RadioButtonGroupNewNoteAction.enabled:= false;
	RadioButtonNewNoteActionNoteCut.enabled:= false;
	RadioButtonNewNoteActionNoteContinue.enabled:= false;
	RadioButtonNewNoteActionNoteOff.enabled:= false;
	RadioButtonNewNoteActionNoteFade.enabled:= false;

	TextFiledDuplicateCheckType.enabled:= false;
	RadioButtonGroupDuplicateCheckType.enabled:= false;
	RadioButtonDuplicateCheckTypeDisabled.enabled:= false;
	RadioButtonDuplicateCheckTypeNote.enabled:= false;
	RadioButtonDuplicateCheckTypeSample.enabled:= false;
	RadioButtonDuplicateCheckTypeInstrument.enabled:= false;

	TextFiledDuplicateCheckAction.enabled:= false;
	RadioButtonGroupDuplicateCheckAction.enabled:= false;
	RadioButtonDuplicateCheckActionNoteCut.enabled:= false;
	RadioButtonDuplicateCheckActionNoteOff.enabled:= false;
	RadioButtonDuplicateCheckActionNoteFade.enabled:= false;

end;


procedure TInstrumentEditor.enableMapping;
var 
	i : longint;	

begin
	for i:= 0 to 88 do begin
		noteTextField[i].enabled:= true;
		mappedNoteTextField[i].enabled:= true;
		mappedSampleTextField[i].enabled:= true;
	end;
	ButtonClearAll.enabled:= true;
	ButtonClear.enabled:= true;
	separationLine1.enabled:= true;
	separationLine2.enabled:= true;
	separationLine3.enabled:= true;
	separationLine4.enabled:= true;
	separationLine5.enabled:= true;
	separationLine6.enabled:= true;
	separationLine7.enabled:= true;

	TextFiledNewNoteAction.enabled:= true;
	RadioButtonGroupNewNoteAction.enabled:= true;
	RadioButtonNewNoteActionNoteCut.enabled:= true;
	RadioButtonNewNoteActionNoteContinue.enabled:= true;
	RadioButtonNewNoteActionNoteOff.enabled:= true;
	RadioButtonNewNoteActionNoteFade.enabled:= true;

	TextFiledDuplicateCheckType.enabled:= true;
	RadioButtonGroupDuplicateCheckType.enabled:= true;
	RadioButtonDuplicateCheckTypeDisabled.enabled:= true;
	RadioButtonDuplicateCheckTypeNote.enabled:= true;
	RadioButtonDuplicateCheckTypeSample.enabled:= true;
	RadioButtonDuplicateCheckTypeInstrument.enabled:= true;

	TextFiledDuplicateCheckAction.enabled:= true;
	RadioButtonGroupDuplicateCheckAction.enabled:= true;
	RadioButtonDuplicateCheckActionNoteCut.enabled:= true;
	RadioButtonDuplicateCheckActionNoteOff.enabled:= true;
	RadioButtonDuplicateCheckActionNoteFade.enabled:= true;

end;


procedure TInstrumentEditor.ClearMappingTextFieldColors(clearChosen: boolean);
var 
	i : longint;

begin

	for i:= 0 to 88 do begin
		if noteTextField[i].theme.FontColor = noteTextField[i].theme.onMouseOverColor then begin
			noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
			mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
			mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
			noteTextField[i].theme.HighlightOnMouseOver:= true;
		end;
		if clearChosen and (noteTextField[i].theme.FontColor = Theme_InstrumentEditor_MappedChosenColor) then begin
			noteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
			mappednoteTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
			mappedSampleTextField[i].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
			noteTextField[i].theme.HighlightOnMouseOver:= true;
		end;
	end;

end;



procedure TInstrumentEditor.reloadMapping;
var 
	i : longint;
	
begin
	
	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
		for i:= 0 to 88 do begin
			mappednoteTextField[i].caption:= NoteValueTo3Str(Module.Instruments.Instrument[currentInstrument].Mapping[i + 12].Note);
			mappedSampleTextField[i].caption:= numstr(Module.Instruments.Instrument[currentInstrument].Mapping[i + 12].Sample);
		end;
	tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.selectNoteInSheet(note: longint);
begin

	if inChoseMode then begin
		mappedNote:= note + 12;
		mappednoteTextField[selectedNote].caption:= NoteValueTo3Str(mappedNote);
		exit;
	end;

	ClearMappingTextFieldColors(false);

	if noteTextField[note].theme.FontColor <> Theme_InstrumentEditor_MappedNoteSelectedColor then
		noteTextField[note].theme.FontColor:= noteTextField[note].theme.onMouseOverColor;

end;



procedure TInstrumentEditor.execProcButtonClear(const param: string);
begin
	
	tralalaEngine.Lock_Module_ReadWrite(Module);
		
            Module.Instruments.Instrument[currentInstrument].Mapping[selectedNote+12].Note:= selectedNote + 12;
            Module.Instruments.Instrument[currentInstrument].Mapping[selectedNote+12].Sample:= 0;
        
	tralalaEngine.Unlock_Module_ReadWrite;

    noteTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MainPanel_FontColor;
	mappednoteTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
	mappedSampleTextField[selectedNote].theme.FontColor:= Theme_InstrumentEditor_MappedNoteColor;
	noteTextField[selectedNote].theme.HighlightOnMouseOver:= true;

	inChoseMode:= false;
	
	reloadMapping;

end;


procedure TInstrumentEditor.execProcButtonClearAll(const param: string);
var 
	i : longint;	

begin
	
	tralalaEngine.Lock_Module_ReadWrite(Module);
		for i:= NoteMin to NoteMax - 1 do begin
            Module.Instruments.Instrument[currentInstrument].Mapping[i].Note:= i;
            Module.Instruments.Instrument[currentInstrument].Mapping[i].Sample:= 0;
        end;
	tralalaEngine.Unlock_Module_ReadWrite;

	ClearMappingTextFieldColors(true);

	inChoseMode:= false;

	reloadMapping;

end;


procedure TInstrumentEditor.execProcNote0(const param: string);
begin
	MakeNoteChosen(0);
end;


procedure TInstrumentEditor.execProcNote1(const param: string);
begin
	MakeNoteChosen(1);
end;


procedure TInstrumentEditor.execProcNote2(const param: string);
begin
	MakeNoteChosen(2);
end;


procedure TInstrumentEditor.execProcNote3(const param: string);
begin
	MakeNoteChosen(3);
end;


procedure TInstrumentEditor.execProcNote4(const param: string);
begin
	MakeNoteChosen(4);
end;


procedure TInstrumentEditor.execProcNote5(const param: string);
begin
	MakeNoteChosen(5);
end;


procedure TInstrumentEditor.execProcNote6(const param: string);
begin
	MakeNoteChosen(6);
end;


procedure TInstrumentEditor.execProcNote7(const param: string);
begin
	MakeNoteChosen(7);
end;


procedure TInstrumentEditor.execProcNote8(const param: string);
begin
	MakeNoteChosen(8);
end;


procedure TInstrumentEditor.execProcNote9(const param: string);
begin
	MakeNoteChosen(9);
end;


procedure TInstrumentEditor.execProcNote10(const param: string);
begin
	MakeNoteChosen(10);
end;


procedure TInstrumentEditor.execProcNote11(const param: string);
begin
	MakeNoteChosen(11);
end;


procedure TInstrumentEditor.execProcNote12(const param: string);
begin
	MakeNoteChosen(12);
end;


procedure TInstrumentEditor.execProcNote13(const param: string);
begin
	MakeNoteChosen(13);
end;


procedure TInstrumentEditor.execProcNote14(const param: string);
begin
	MakeNoteChosen(14);
end;


procedure TInstrumentEditor.execProcNote15(const param: string);
begin
	MakeNoteChosen(15);
end;


procedure TInstrumentEditor.execProcNote16(const param: string);
begin
	MakeNoteChosen(16);
end;


procedure TInstrumentEditor.execProcNote17(const param: string);
begin
	MakeNoteChosen(17);
end;


procedure TInstrumentEditor.execProcNote18(const param: string);
begin
	MakeNoteChosen(18);
end;


procedure TInstrumentEditor.execProcNote19(const param: string);
begin
	MakeNoteChosen(19);
end;


procedure TInstrumentEditor.execProcNote20(const param: string);
begin
	MakeNoteChosen(20);
end;


procedure TInstrumentEditor.execProcNote21(const param: string);
begin
	MakeNoteChosen(21);
end;


procedure TInstrumentEditor.execProcNote22(const param: string);
begin
	MakeNoteChosen(22);
end;


procedure TInstrumentEditor.execProcNote23(const param: string);
begin
	MakeNoteChosen(23);
end;


procedure TInstrumentEditor.execProcNote24(const param: string);
begin
	MakeNoteChosen(24);
end;


procedure TInstrumentEditor.execProcNote25(const param: string);
begin
	MakeNoteChosen(25);
end;


procedure TInstrumentEditor.execProcNote26(const param: string);
begin
	MakeNoteChosen(26);
end;


procedure TInstrumentEditor.execProcNote27(const param: string);
begin
	MakeNoteChosen(27);
end;


procedure TInstrumentEditor.execProcNote28(const param: string);
begin
	MakeNoteChosen(28);
end;


procedure TInstrumentEditor.execProcNote29(const param: string);
begin
	MakeNoteChosen(29);
end;


procedure TInstrumentEditor.execProcNote30(const param: string);
begin
	MakeNoteChosen(30);
end;


procedure TInstrumentEditor.execProcNote31(const param: string);
begin
	MakeNoteChosen(31);
end;


procedure TInstrumentEditor.execProcNote32(const param: string);
begin
	MakeNoteChosen(32);
end;


procedure TInstrumentEditor.execProcNote33(const param: string);
begin
	MakeNoteChosen(33);
end;


procedure TInstrumentEditor.execProcNote34(const param: string);
begin
	MakeNoteChosen(34);
end;


procedure TInstrumentEditor.execProcNote35(const param: string);
begin
	MakeNoteChosen(35);
end;


procedure TInstrumentEditor.execProcNote36(const param: string);
begin
	MakeNoteChosen(36);
end;


procedure TInstrumentEditor.execProcNote37(const param: string);
begin
	MakeNoteChosen(37);
end;


procedure TInstrumentEditor.execProcNote38(const param : string);
begin
	MakeNoteChosen(38);
end;


procedure TInstrumentEditor.execProcNote39(const param: string);
begin
	MakeNoteChosen(39);
end;


procedure TInstrumentEditor.execProcNote40(const param: string);
begin
	MakeNoteChosen(40);
end;


procedure TInstrumentEditor.execProcNote41(const param: string);
begin
	MakeNoteChosen(41);
end;


procedure TInstrumentEditor.execProcNote42(const param: string);
begin
	MakeNoteChosen(42);
end;


procedure TInstrumentEditor.execProcNote43(const param: string);
begin
	MakeNoteChosen(43);
end;


procedure TInstrumentEditor.execProcNote44(const param: string);
begin
	MakeNoteChosen(44);
end;


procedure TInstrumentEditor.execProcNote45(const param: string);
begin
	MakeNoteChosen(45);
end;


procedure TInstrumentEditor.execProcNote46(const param: string);
begin
	MakeNoteChosen(46);
end;


procedure TInstrumentEditor.execProcNote47(const param: string);
begin
	MakeNoteChosen(47);
end;


procedure TInstrumentEditor.execProcNote48(const param: string);
begin
	MakeNoteChosen(48);
end;


procedure TInstrumentEditor.execProcNote49(const param: string);
begin
	MakeNoteChosen(49);
end;


procedure TInstrumentEditor.execProcNote50(const param: string);
begin
	MakeNoteChosen(50);
end;


procedure TInstrumentEditor.execProcNote51(const param: string);
begin
	MakeNoteChosen(51);
end;


procedure TInstrumentEditor.execProcNote52(const param: string);
begin
	MakeNoteChosen(52);
end;


procedure TInstrumentEditor.execProcNote53(const param: string);
begin
	MakeNoteChosen(53);
end;


procedure TInstrumentEditor.execProcNote54(const param: string);
begin
	MakeNoteChosen(54);
end;


procedure TInstrumentEditor.execProcNote55(const param: string);
begin
	MakeNoteChosen(55);
end;


procedure TInstrumentEditor.execProcNote56(const param: string);
begin
	MakeNoteChosen(56);
end;


procedure TInstrumentEditor.execProcNote57(const param: string);
begin
	MakeNoteChosen(57);
end;


procedure TInstrumentEditor.execProcNote58(const param: string);
begin
	MakeNoteChosen(58);
end;


procedure TInstrumentEditor.execProcNote59(const param: string);
begin
	MakeNoteChosen(59);
end;


procedure TInstrumentEditor.execProcNote60(const param: string);
begin
	MakeNoteChosen(60);
end;


procedure TInstrumentEditor.execProcNote61(const param: string);
begin
	MakeNoteChosen(61);
end;


procedure TInstrumentEditor.execProcNote62(const param: string);
begin
	MakeNoteChosen(62);
end;


procedure TInstrumentEditor.execProcNote63(const param: string);
begin
	MakeNoteChosen(63);
end;


procedure TInstrumentEditor.execProcNote64(const param: string);
begin
	MakeNoteChosen(64);
end;


procedure TInstrumentEditor.execProcNote65(const param: string);
begin
	MakeNoteChosen(65);
end;


procedure TInstrumentEditor.execProcNote66(const param: string);
begin
	MakeNoteChosen(66);
end;


procedure TInstrumentEditor.execProcNote67(const param: string);
begin
	MakeNoteChosen(67);
end;


procedure TInstrumentEditor.execProcNote68(const param: string);
begin
	MakeNoteChosen(68);
end;


procedure TInstrumentEditor.execProcNote69(const param: string);
begin
	MakeNoteChosen(69);
end;


procedure TInstrumentEditor.execProcNote70(const param: string);
begin
	MakeNoteChosen(70);
end;


procedure TInstrumentEditor.execProcNote71(const param: string);
begin
	MakeNoteChosen(71);
end;


procedure TInstrumentEditor.execProcNote72(const param: string);
begin
	MakeNoteChosen(72);
end;


procedure TInstrumentEditor.execProcNote73(const param: string);
begin
	MakeNoteChosen(73);
end;


procedure TInstrumentEditor.execProcNote74(const param: string);
begin
	MakeNoteChosen(74);
end;


procedure TInstrumentEditor.execProcNote75(const param: string);
begin
	MakeNoteChosen(75);
end;


procedure TInstrumentEditor.execProcNote76(const param: string);
begin
	MakeNoteChosen(76);
end;


procedure TInstrumentEditor.execProcNote77(const param: string);
begin
	MakeNoteChosen(77);
end;


procedure TInstrumentEditor.execProcNote78(const param: string);
begin
	MakeNoteChosen(78);
end;


procedure TInstrumentEditor.execProcNote79(const param: string);
begin
	MakeNoteChosen(79);
end;


procedure TInstrumentEditor.execProcNote80(const param: string);
begin
	MakeNoteChosen(80);
end;


procedure TInstrumentEditor.execProcNote81(const param: string);
begin
	MakeNoteChosen(81);
end;


procedure TInstrumentEditor.execProcNote82(const param: string);
begin
	MakeNoteChosen(82);
end;


procedure TInstrumentEditor.execProcNote83(const param: string);
begin
	MakeNoteChosen(83);
end;


procedure TInstrumentEditor.execProcNote84(const param: string);
begin
	MakeNoteChosen(84);
end;


procedure TInstrumentEditor.execProcNote85(const param: string);
begin
	MakeNoteChosen(85);
end;


procedure TInstrumentEditor.execProcNote86(const param: string);
begin
	MakeNoteChosen(86);
end;


procedure TInstrumentEditor.execProcNote87(const param: string);
begin
	MakeNoteChosen(87);
end;


procedure TInstrumentEditor.execProcNote88(const param: string);
begin
	MakeNoteChosen(88);
end;











































procedure TInstrumentEditor.execProcMouseOverNote0(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote1(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote2(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote3(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote4(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote5(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;


procedure TInstrumentEditor.execProcMouseOverNote6(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote7(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote8(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote9(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote10(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote11(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote12(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote13(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote14(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote15(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote16(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote17(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote18(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote19(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote20(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote21(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote22(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote23(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote24(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote25(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote26(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote27(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote28(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote29(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote30(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote31(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote32(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote33(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote34(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote35(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote36(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote37(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote38(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote39(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote40(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote41(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote42(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote43(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote44(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote45(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote46(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote47(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote48(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote49(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote50(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote51(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote52(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote53(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote54(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote55(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote56(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote57(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote58(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote59(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote60(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote61(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote62(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote63(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote64(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote65(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote66(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote67(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;


procedure TInstrumentEditor.execProcMouseOverNote68(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote69(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote70(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote71(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote72(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote73(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;


procedure TInstrumentEditor.execProcMouseOverNote74(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote75(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote76(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote77(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote78(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote79(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote80(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote81(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote82(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote83(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote84(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote85(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote86(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote87(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;

procedure TInstrumentEditor.execProcMouseOverNote88(const param: string);
begin
	ClearMappingTextFieldColors(false);
end;