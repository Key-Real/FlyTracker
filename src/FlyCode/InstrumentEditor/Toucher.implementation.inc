
procedure TInstrumentEditor.drawToucherLeft;
var 
	color : dword;
	pos : dword;

begin

	if toucherLeftPos < 0 then exit;

	if isMouseInToucherLeft or movingToucherLeft then color:= Theme_InstrumentEditor_ToucherMouseOverColor else color:= Theme_InstrumentEditor_ToucherColor;
	pos:= toucherLeftPos;

	drawTouchLineLeft;

	drawhlineclip(vscreen, pos - 17, pos + 17, 219, color);
	drawhlineclip(vscreen, pos - 16, pos + 16, 220, color);
	drawhlineclip(vscreen, pos - 15, pos + 15, 221, color);
	drawhlineclip(vscreen, pos - 14, pos + 14, 222, color);
	drawhlineclip(vscreen, pos - 13, pos + 13, 223, color);
	drawhlineclip(vscreen, pos - 12, pos + 12, 224, color);
	drawhlineclip(vscreen, pos - 11, pos + 11, 225, color);
	drawhlineclip(vscreen, pos - 10, pos + 10, 226, color);
	drawhlineclip(vscreen, pos - 09, pos + 09, 227, color);
	drawhlineclip(vscreen, pos - 08, pos + 08, 228, color);
	drawhlineclip(vscreen, pos - 07, pos + 07, 229, color);
	drawhlineclip(vscreen, pos - 06, pos + 06, 230, color);
	drawhlineclip(vscreen, pos - 05, pos + 05, 231, color);
	drawhlineclip(vscreen, pos - 04, pos + 04, 232, color);
	drawhlineclip(vscreen, pos - 03, pos +  03, 233, color);

end;


function TInstrumentEditor.isInToucherLeft: boolean;
begin

	result:= false;
	if (mouseX >= (toucherLeftPos - 17)) and (mouseX <= (toucherLeftPos + 17)) and (mouseY >= 219) and (mouseY <= 233) then begin
		if (mouseX >= (toucherLeftPos - 17)) and (mouseX <= (toucherLeftPos + 17)) and (mouseY = 219) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 16)) and (mouseX <= (toucherLeftPos + 16)) and (mouseY = 220) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 15)) and (mouseX <= (toucherLeftPos + 15)) and (mouseY = 221) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 14)) and (mouseX <= (toucherLeftPos + 14)) and (mouseY = 222) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 13)) and (mouseX <= (toucherLeftPos + 13)) and (mouseY = 223) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 12)) and (mouseX <= (toucherLeftPos + 12)) and (mouseY = 224) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 11)) and (mouseX <= (toucherLeftPos + 11)) and (mouseY = 225) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 10)) and (mouseX <= (toucherLeftPos + 10)) and (mouseY = 226) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 09)) and (mouseX <= (toucherLeftPos + 09)) and (mouseY = 227) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 08)) and (mouseX <= (toucherLeftPos + 08)) and (mouseY = 228) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 07)) and (mouseX <= (toucherLeftPos + 07)) and (mouseY = 229) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 06)) and (mouseX <= (toucherLeftPos + 06)) and (mouseY = 230) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 05)) and (mouseX <= (toucherLeftPos + 05)) and (mouseY = 231) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 04)) and (mouseX <= (toucherLeftPos + 04)) and (mouseY = 232) then begin result:= true; exit; end;
		if (mouseX >= (toucherLeftPos - 03)) and (mouseX <= (toucherLeftPos + 03)) and (mouseY = 233) then begin result:= true; exit; end;
	end;

	if (mouse2X >= (toucherLeftPos - 17)) and (mouse2X <= (toucherLeftPos + 17)) and (mouse2Y >= 219) and (mouse2Y <= 233) then begin
		if (mouse2X >= (toucherLeftPos - 17)) and (mouse2X <= (toucherLeftPos + 17)) and (mouse2Y = 219) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 16)) and (mouse2X <= (toucherLeftPos + 16)) and (mouse2Y = 220) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 15)) and (mouse2X <= (toucherLeftPos + 15)) and (mouse2Y = 221) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 14)) and (mouse2X <= (toucherLeftPos + 14)) and (mouse2Y = 222) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 13)) and (mouse2X <= (toucherLeftPos + 13)) and (mouse2Y = 223) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 12)) and (mouse2X <= (toucherLeftPos + 12)) and (mouse2Y = 224) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 11)) and (mouse2X <= (toucherLeftPos + 11)) and (mouse2Y = 225) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 10)) and (mouse2X <= (toucherLeftPos + 10)) and (mouse2Y = 226) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 09)) and (mouse2X <= (toucherLeftPos + 09)) and (mouse2Y = 227) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 08)) and (mouse2X <= (toucherLeftPos + 08)) and (mouse2Y = 228) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 07)) and (mouse2X <= (toucherLeftPos + 07)) and (mouse2Y = 229) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 06)) and (mouse2X <= (toucherLeftPos + 06)) and (mouse2Y = 230) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 05)) and (mouse2X <= (toucherLeftPos + 05)) and (mouse2Y = 231) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 04)) and (mouse2X <= (toucherLeftPos + 04)) and (mouse2Y = 232) then begin result:= true; exit; end;
		if (mouse2X >= (toucherLeftPos - 03)) and (mouse2X <= (toucherLeftPos + 03)) and (mouse2Y = 233) then begin result:= true; exit; end;
	end;

end;


procedure TInstrumentEditor.drawTouchLineRight;
begin	

	if (toucherRightPos >= (toucherLeftPos - 17)) and (toucherRightPos <= (toucherLeftPos + 17)) then begin
		if (toucherRightPos = (toucherLeftPos - 17)) or (toucherRightPos = (toucherLeftPos + 17)) then begin drawVline(vscreen, 220, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 16)) or (toucherRightPos = (toucherLeftPos + 16)) then begin drawVline(vscreen, 221, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 15)) or (toucherRightPos = (toucherLeftPos + 15)) then begin drawVline(vscreen, 222, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 14)) or (toucherRightPos = (toucherLeftPos + 14)) then begin drawVline(vscreen, 223, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 13)) or (toucherRightPos = (toucherLeftPos + 13)) then begin drawVline(vscreen, 224, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 12)) or (toucherRightPos = (toucherLeftPos + 12)) then begin drawVline(vscreen, 225, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 11)) or (toucherRightPos = (toucherLeftPos + 11)) then begin drawVline(vscreen, 226, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 10)) or (toucherRightPos = (toucherLeftPos + 10)) then begin drawVline(vscreen, 227, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 09)) or (toucherRightPos = (toucherLeftPos + 09)) then begin drawVline(vscreen, 228, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 08)) or (toucherRightPos = (toucherLeftPos + 08)) then begin drawVline(vscreen, 229, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 07)) or (toucherRightPos = (toucherLeftPos + 07)) then begin drawVline(vscreen, 230, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 06)) or (toucherRightPos = (toucherLeftPos + 06)) then begin drawVline(vscreen, 231, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 05)) or (toucherRightPos = (toucherLeftPos + 05)) then begin drawVline(vscreen, 232, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 04)) or (toucherRightPos = (toucherLeftPos + 04)) then begin drawVline(vscreen, 233, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
		if (toucherRightPos = (toucherLeftPos - 03)) or (toucherRightPos = (toucherLeftPos + 03)) then begin drawVline(vscreen, 234, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor); exit; end;
	end else
		drawVline(vscreen, 200, 632 - 200 - 36, toucherRightPos, Theme_InstrumentEditor_LoopLineColor);

end;


procedure TInstrumentEditor.drawTouchLineLeft;
begin	

	drawVline(vscreen, 220, 632 - 200 - 22, toucherLeftPos, Theme_InstrumentEditor_LoopLineColor);

end;


procedure TInstrumentEditor.drawToucherRight;
var 
	color : dword;
	pos : dword;

begin

	if toucherRightPos < 0 then exit;

	if isMouseInToucherRight or movingToucherRight then color:=Theme_InstrumentEditor_ToucherMouseOverColor else color:=Theme_InstrumentEditor_ToucherColor;
	pos:= toucherRightPos;

	drawTouchLineRight;

	drawhlineclip(vscreen, pos - 17, pos + 17, 632 - 200 - 22, color);
	drawhlineclip(vscreen, pos - 16, pos + 16, 632 - 200 - 23, color);
	drawhlineclip(vscreen, pos - 15, pos + 15, 632 - 200 - 24, color);
	drawhlineclip(vscreen, pos - 14, pos + 14, 632 - 200 - 25, color);
	drawhlineclip(vscreen, pos - 13, pos + 13, 632 - 200 - 26, color);
	drawhlineclip(vscreen, pos - 12, pos + 12, 632 - 200 - 27, color);
	drawhlineclip(vscreen, pos - 11, pos + 11, 632 - 200 - 28, color);
	drawhlineclip(vscreen, pos - 10, pos + 10, 632 - 200 - 29, color);
	drawhlineclip(vscreen, pos - 09, pos + 09, 632 - 200 - 30, color);
	drawhlineclip(vscreen, pos - 08, pos + 08, 632 - 200 - 31, color);
	drawhlineclip(vscreen, pos - 07, pos + 07, 632 - 200 - 32, color);
	drawhlineclip(vscreen, pos - 06, pos + 06, 632 - 200 - 33, color);
	drawhlineclip(vscreen, pos - 05, pos + 05, 632 - 200 - 34, color);
	drawhlineclip(vscreen, pos - 04, pos + 04, 632 - 200 - 35, color);
	drawhlineclip(vscreen, pos - 03, pos + 03, 632 - 200 - 36, color);

end;



function TInstrumentEditor.isInToucherRight: boolean;
begin

	result:= false;

	if (mouseX >= (toucherRightPos - 17)) and (mouseX <= (toucherRightPos + 17)) and (mouseY >= 396) and (mouseY <= 410) then begin
		if (mouseX >= (toucherRightPos - 17)) and (mouseX <= (toucherRightPos + 17)) and (mouseY = 410) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 16)) and (mouseX <= (toucherRightPos + 16)) and (mouseY = 409) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 15)) and (mouseX <= (toucherRightPos + 15)) and (mouseY = 408) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 14)) and (mouseX <= (toucherRightPos + 14)) and (mouseY = 407) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 13)) and (mouseX <= (toucherRightPos + 13)) and (mouseY = 406) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 12)) and (mouseX <= (toucherRightPos + 12)) and (mouseY = 405) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 11)) and (mouseX <= (toucherRightPos + 11)) and (mouseY = 404) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 10)) and (mouseX <= (toucherRightPos + 10)) and (mouseY = 403) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 09)) and (mouseX <= (toucherRightPos + 09)) and (mouseY = 402) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 08)) and (mouseX <= (toucherRightPos + 08)) and (mouseY = 401) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 07)) and (mouseX <= (toucherRightPos + 07)) and (mouseY = 400) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 06)) and (mouseX <= (toucherRightPos + 06)) and (mouseY = 399) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 05)) and (mouseX <= (toucherRightPos + 05)) and (mouseY = 398) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 04)) and (mouseX <= (toucherRightPos + 04)) and (mouseY = 397) then begin result:= true; exit; end;
		if (mouseX >= (toucherRightPos - 03)) and (mouseX <= (toucherRightPos + 03)) and (mouseY = 396) then begin result:= true; exit; end;
	end;

	if (mouse2X >= (toucherRightPos - 17)) and (mouse2X <= (toucherRightPos + 17)) and (mouse2Y >= 396) and (mouse2Y <= 410) then begin
		if (mouse2X >= (toucherRightPos - 17)) and (mouse2X <= (toucherRightPos + 17)) and (mouse2Y = 410) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 16)) and (mouse2X <= (toucherRightPos + 16)) and (mouse2Y = 409) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 15)) and (mouse2X <= (toucherRightPos + 15)) and (mouse2Y = 408) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 14)) and (mouse2X <= (toucherRightPos + 14)) and (mouse2Y = 407) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 13)) and (mouse2X <= (toucherRightPos + 13)) and (mouse2Y = 406) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 12)) and (mouse2X <= (toucherRightPos + 12)) and (mouse2Y = 405) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 11)) and (mouse2X <= (toucherRightPos + 11)) and (mouse2Y = 404) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 10)) and (mouse2X <= (toucherRightPos + 10)) and (mouse2Y = 403) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 09)) and (mouse2X <= (toucherRightPos + 09)) and (mouse2Y = 402) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 08)) and (mouse2X <= (toucherRightPos + 08)) and (mouse2Y = 401) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 07)) and (mouse2X <= (toucherRightPos + 07)) and (mouse2Y = 400) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 06)) and (mouse2X <= (toucherRightPos + 06)) and (mouse2Y = 399) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 05)) and (mouse2X <= (toucherRightPos + 05)) and (mouse2Y = 398) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 04)) and (mouse2X <= (toucherRightPos + 04)) and (mouse2Y = 397) then begin result:= true; exit; end;
		if (mouse2X >= (toucherRightPos - 03)) and (mouse2X <= (toucherRightPos + 03)) and (mouse2Y = 396) then begin result:= true; exit; end;
	end;
end;

procedure TInstrumentEditor.updateToucherLeft;
var 
	waveLengthMultiplicator : longint;

begin
	if RadioButtonSampleBits8.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 1
	else if RadioButtonSampleBits8.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 4;


	tralalaEngine.Lock_Module_ReadWrite(Module);

		if RadioButtonLoopNormal.checked then begin				
			
			Module.Samples[CurrentSample].LoopStart:= drawWaveStart + toucherLeftPos * (drawWaveLength div waveLengthMultiplicator) div (vscreen.width - 1);

			if Module.Samples[CurrentSample].LoopStart >= Module.Samples[CurrentSample].LoopEnd then begin
				Module.Samples[CurrentSample].LoopStart:= Module.Samples[CurrentSample].LoopEnd - 1;
				if RadioButtonLoopTypeForward.checked then Module.samples[CurrentSample].LoopType:= sltForwardLoop;
				if RadioButtonLoopTypePingPong.checked then Module.samples[CurrentSample].LoopType:= sltPingPongLoop;
			end;

			TextFiledLoopStart.caption:= 'Loop Start at ' + numstr(Module.samples[CurrentSample].LoopStart);
		end;

		if RadioButtonLoopSustain.checked then begin	
			
			Module.Samples[CurrentSample].SustainLoopStart:= drawWaveStart + toucherLeftPos * (drawWaveLength div waveLengthMultiplicator) div (vscreen.width - 1);

			if Module.Samples[CurrentSample].SustainLoopStart >= Module.Samples[CurrentSample].SustainLoopEnd then begin
				Module.Samples[CurrentSample].SustainLoopStart:= Module.Samples[CurrentSample].SustainLoopEnd - 1;
				if RadioButtonLoopTypeForward.checked then Module.samples[CurrentSample].SustainLoopType:= sltForwardLoop;
				if RadioButtonLoopTypePingPong.checked then Module.samples[CurrentSample].SustainLoopType:= sltPingPongLoop;
			end;

			TextFiledSustainLoopStart.caption:= 'Sustain Loop Start at ' + numstr(Module.samples[CurrentSample].SustainLoopStart);

		end;

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.updateToucherRight;
var
	waveLengthMultiplicator : longint;
begin

	if RadioButtonSampleBits8.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 1
	else if RadioButtonSampleBits8.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 4;

	tralalaEngine.Lock_Module_ReadWrite(Module);

		if RadioButtonLoopNormal.checked then begin
			
			Module.Samples[CurrentSample].LoopEnd:= drawWaveStart + toucherRightPos * (drawWaveLength div waveLengthMultiplicator) div (vscreen.width - 1);

			if Module.Samples[CurrentSample].LoopEnd <= (Module.Samples[CurrentSample].LoopStart) then begin
				Module.Samples[CurrentSample].LoopEnd:= Module.Samples[CurrentSample].LoopStart + 1;
				if RadioButtonLoopTypeForward.checked then Module.samples[CurrentSample].LoopType:= sltForwardLoop;
				if RadioButtonLoopTypePingPong.checked then Module.samples[CurrentSample].LoopType:= sltPingPongLoop;
			end;					
					
			TextFiledLoopEnd.caption:= 'Loop End at ' + numstr(Module.Samples[CurrentSample].LoopEnd);

		end;

		if RadioButtonLoopSustain.checked then begin

			Module.Samples[CurrentSample].SustainLoopEnd:= drawWaveStart + toucherRightPos * (drawWaveLength div waveLengthMultiplicator) div (vscreen.width - 1) + 1;

			if Module.Samples[CurrentSample].SustainLoopEnd <= (Module.Samples[CurrentSample].SustainLoopStart) then begin
				Module.Samples[CurrentSample].SustainLoopEnd:= Module.Samples[CurrentSample].SustainLoopStart + 1;
				if RadioButtonLoopTypeForward.checked then Module.samples[CurrentSample].SustainLoopType:= sltForwardLoop;
				if RadioButtonLoopTypePingPong.checked then Module.samples[CurrentSample].SustainLoopType:= sltPingPongLoop;
			end;					
			
			TextFiledSustainLoopEnd.caption:= 'Sustain Loop End at ' + numstr(Module.Samples[CurrentSample].SustainLoopEnd);

		end;

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TInstrumentEditor.getToucherLeftRightPos;
var 
	waveLengthMultiplicator : longint;	
begin      

	if drawWaveLength = 0 then exit;

	if RadioButtonSampleBits8.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 1
	else if RadioButtonSampleBits8.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleMono.Checked then waveLengthMultiplicator:= 2
	else if RadioButtonSampleBits16.Checked and RadioButtonSampleStereo.Checked then waveLengthMultiplicator:= 4;

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		if (Module.samples[CurrentSample].LoopType <> sltNoLoop) or (Module.samples[CurrentSample].SustainLoopType <> sltNoLoop) then begin


			if RadioButtonLoopNormal.checked then begin

				if (Module.Samples[CurrentSample].LoopStart >= drawWaveStart) and (Module.Samples[CurrentSample].LoopStart < (drawWaveStart + drawWaveLength)) then begin
					toucherLeftPos:= (Module.Samples[CurrentSample].LoopStart - drawWaveStart) * (vscreen.width - 1) div (drawWaveLength div waveLengthMultiplicator);
				end else toucherLeftPos:= -1;
				

				if (Module.Samples[CurrentSample].LoopEnd >= drawWaveStart) and (Module.Samples[CurrentSample].LoopEnd <= (drawWaveStart + drawWaveLength)) then begin
					toucherRightPos:= (Module.Samples[CurrentSample].LoopEnd - drawWaveStart) * (vscreen.width - 1) div (drawWaveLength div waveLengthMultiplicator);
				end else toucherRightPos:= -1;	

			end else begin

				if (Module.Samples[CurrentSample].SustainLoopStart >= drawWaveStart) and (Module.Samples[CurrentSample].SustainLoopStart < (drawWaveStart + drawWaveLength)) then begin
					toucherLeftPos:= (Module.Samples[CurrentSample].SustainLoopStart - drawWaveStart) * (vscreen.width - 1) div (drawWaveLength div waveLengthMultiplicator);
				end else toucherLeftPos:= -1;

				if (Module.Samples[CurrentSample].SustainLoopEnd >= drawWaveStart) and (Module.Samples[CurrentSample].SustainLoopEnd <= (drawWaveStart + drawWaveLength)) then begin
					toucherRightPos:= (Module.Samples[CurrentSample].SustainLoopEnd - drawWaveStart) * (vscreen.width - 1) div (drawWaveLength div waveLengthMultiplicator);
				end else toucherRightPos:= -1;

			end;

		end;

	tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.updateToucher;
begin
	
		drawToucherLeft;
		drawToucherRight;

		if InstrumentEditorTUI.lockedItem <> -1 then exit;

		if isInToucherLeft then isMouseInToucherLeft:= true else isMouseInToucherLeft:= false;
		if isInToucherRight then isMouseInToucherRight:= true else isMouseInToucherRight:= false;

		if (mouseL or mouse2L) and isMouseInToucherLeft then begin
			movingToucherLeft:= true;
		end;

		if (mouseL or mouse2L) and isMouseInToucherRight then begin
			movingToucherRight:= true;
		end;	

		if movingToucherLeft then begin
			if mouseL then toucherLeftPos:= mouseX;
			if mouse2L then toucherLeftPos:= mouse2X;
			
			if toucherLeftPos >= (vscreen.width - 1) then toucherLeftPos:= vscreen.width - 1;

			updateToucherLeft;

		end;

		if movingToucherRight then begin
			if mouseL then toucherRightPos:= mouseX;
			if mouse2L then toucherRightPos:= mouse2X;

			if toucherRightPos >= (vscreen.width - 1) then toucherRightPos:= vscreen.width - 1;

			updateToucherRight;
		end;

		if movingToucherLeft or movingToucherRight then begin
			getToucherLeftRightPos;

			InstrumentEditorTUI.drawOnly:= true;
			allowPianoKeys:= false;
		end;


		if (not mouseL) and (not mouse2L) then begin
			movingToucherLeft:= false;
			movingToucherRight:= false;
			InstrumentEditorTUI.drawOnly:= false;
			allowPianoKeys:= true;
		end;

end;
 
