
procedure TInstrumentEditor.selectBlock;
var 
	i : longint;
begin

	if drawWaveLength <= 0 then exit;
	
	if InstrumentEditorTUI.lockedItem <> -2 then
		if InstrumentEditorTUI.lockedItem <> -1 then exit;

	if mainMenu.MenuHorizontalBox.tuiSelf.isInAnyBox then exit;		


	if isMouseInToucherLeft or isMouseInToucherRight or movingToucherLeft or movingToucherRight then exit;

	if (not mouseL) and (not mouse2L) then begin

		startSelectingBlockStart:= false;
		startSelectingBlockStartOnce:= false;
		
		if selectedBlockEnd < selectedBlockStart then begin
			i:= selectedBlockEnd;
			selectedBlockEnd:= selectedBlockStart;
			selectedBlockStart:= i;
		end;

		allowSelectBlock:= true;
		allowPianoKeys:= true;
		
	end;

	if not allowSelectBlock then exit;

	if (mouseL and (mouseY >= 220) and (mouseY <= 410) and (mouseX < vscreen.width)) or (mouse2L and (mouse2Y >= 220) and (mouse2Y <= 410) and (mouse2X < vscreen.width)) then begin
		startSelectingBlockStart:= true;
	end;

	if startSelectingBlockStartOnce then begin
		if mouseL then begin
			if mouseX > (vscreen.width - 1) then mouseX:= vscreen.width - 1;
			selectedBlockEnd:= drawWaveStart + mouseX * drawWaveLength div vscreen.width;
			InstrumentEditorTUI.lockedItem:= -2;
		end;

		if mouse2L then begin
			if mouse2X > (vscreen.width - 1) then mouse2X:= vscreen.width - 1;
			selectedBlockEnd:= drawWaveStart + mouse2X * drawWaveLength div vscreen.width;
			InstrumentEditorTUI.lockedItem:= -2;
		end;
	end;

	if startSelectingBlockStart and (not startSelectingBlockStartOnce) then begin
		if mouseL then begin	
			selectedBlockEnd:= -1;	
			selectedBlockStart:= drawWaveStart + mouseX * drawWaveLength div vscreen.width;
			startSelectingBlockStartOnce:= true;
			InstrumentEditorTUI.lockedItem:= -2;
		end;

		if mouse2L then begin		
			selectedBlockEnd:= -1;
			selectedBlockStart:= drawWaveStart + mouse2X * drawWaveLength div vscreen.width;
			startSelectingBlockStartOnce:= true;
			InstrumentEditorTUI.lockedItem:= -2;
		end;
	end;

	if (mouseR and (mouseY >= 220) and (mouseY <= 410)) or (mouse2R and (mouse2Y >= 220) and (mouse2Y <= 410)) then begin
		selectedBlockStart:= -1;
		selectedBlockEnd:= -1;
		getBlockDrawLeftRightPos;
	end;

	if (selectedBlockStart <> -1) and (selectedBlockEnd <> -1) then begin	
		getBlockDrawLeftRightPos;
	end;

end;
 
procedure TInstrumentEditor.drawBlock;
begin
	drawBarClip(vscreen, drawSelectedBlockStart, 200, drawSelectedBlockEnd, 632 - 200 - 22, Theme_InstrumentEditor_SelectColor);
end;


procedure TInstrumentEditor.getBlockDrawLeftRightPos;
begin
	drawSelectedBlockStart:= (selectedBlockStart - drawWaveStart) * (vscreen.width - 1) div drawWaveLength;
	drawSelectedBlockEnd:= (selectedBlockEnd - drawWaveStart) * (vscreen.width - 1) div drawWaveLength;
end;




procedure TInstrumentEditor.doShowSelectedWave;
begin

	if (selectedBlockStart <> -1) and (selectedBlockEnd <> -1) then begin
		if (selectedBlockEnd - selectedBlockStart) > 2 then begin
			drawWaveStart:= selectedBlockStart;
			drawWaveLength:= selectedBlockEnd - selectedBlockStart;
		end;
	end;

	getToucherLeftRightPos;

	reloadScrollbar;

end;


procedure TInstrumentEditor.execProcShowSelectedWave(const param:string);
begin

	doShowSelectedWave;

	netSendButtonShowSelectedWave;

end;


procedure TInstrumentEditor.doZoomOutWave;
begin

	drawWaveStart:= drawWaveStart - 1024;
	if drawWaveStart < 0 then drawWaveStart:= 0;

	drawWaveLength:= drawWaveLength + 1024 * 2;
	
	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
	
		if (drawWaveLength) > (Module.samples[CurrentSample].data.LengthBytes - drawWaveStart) then 
			drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes - drawWaveStart;		

		mainScrollBar.resetMaxValue((Module.samples[CurrentSample].data.LengthBytes * (vscreen.width - 1) div drawWaveLength) - (vscreen.width - 1));
    	mainScrollBar.setCurValue(round(drawWaveStart / drawWaveLength * (vscreen.width - 1)));
    		
	tralalaEngine.Unlock_ReadOnly;

	getToucherLeftRightPos;
	getBlockDrawLeftRightPos;

end;


procedure TInstrumentEditor.execProcZoomOutWave(const param:string);
begin

	doZoomOutWave;

	netSendButtonZoomOutWave;

end;


procedure TInstrumentEditor.doRangeAllWave;
begin

	selectedBlockStart:= drawWaveStart;
	selectedBlockEnd:= drawWaveStart + drawWaveLength;

end;

procedure TInstrumentEditor.execProcRangeAllWave(const param:string);	
begin
	
	doRangeAllWave;

	netSendButtonRangeAllWave;

end;


procedure TInstrumentEditor.doShowAllWave;
begin

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
	
		drawWaveStart:= 0;
		drawWaveLength:= Module.samples[CurrentSample].data.LengthBytes;

		mainScrollBar.resetMaxValue((Module.samples[CurrentSample].data.LengthBytes * (vscreen.width - 1) div drawWaveLength) - (vscreen.width - 1));
	 	mainScrollBar.setCurValue(round(drawWaveStart / drawWaveLength * (vscreen.width - 1)));
	
	tralalaEngine.Unlock_ReadOnly;

	getToucherLeftRightPos;
	getBlockDrawLeftRightPos;

end;


procedure TInstrumentEditor.execProcShowAllWave(const param:string);
begin
	
	doShowAllWave;	

	netSendButtonShowAllWave;

end;