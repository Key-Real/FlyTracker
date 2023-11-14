



procedure TInstrumentEditor.DrawWave(start, sampleLength: longint); 
var 
		x, y : longint;
    whole_buf : pointer;
    bitsPerSample : longint;
		xprev, yprev : longint;
    step : longint;
    ymax : longint;
    yoffset : longint;
    s : longint;
    stereo : longint;
  

function getY: longint;
begin
	
	if stereo = 1 then begin
		if bitsPerSample = 8 then result:= yoffset + ymax div 2 + (PShortInt(whole_buf)[start] * ymax div 256 * -1);
  	if bitsPerSample = 16 then result:= yoffset + ymax div 2 + (PSmallInt(whole_buf)[start] * ymax div 65536 * -1);
	end else begin
		if bitsPerSample = 8 then result:= yoffset + ymax div 2 + ((PShortInt(whole_buf)[start * 2 + 0] + PShortInt(whole_buf)[start * 2 + 1]) * ymax div (256 * 2) * -1);
  	if bitsPerSample = 16 then result:= yoffset + ymax div 2 + ((PSmallInt(whole_buf)[start * 2 + 0] + PSmallInt(whole_buf)[start * 2 + 1]) * ymax div (65536 * 2) * -1);
  end;

end;


begin

	if sampleLength <= 0 then exit;

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);		

		if not Module.samples[CurrentSample].data.Stereo then stereo:= 1 else stereo:= 2;

		whole_buf:= Module.samples[CurrentSample].data.lock;

		bitsPerSample:= Module.samples[CurrentSample].data.bits;

		sampleLength:= sampleLength div (bitsPerSample div 8) div stereo;
		start:= start div (bitsPerSample div 8) div stereo;

		yoffset:= 222 - 3;
		ymax:= 191;
	
		Step:= 1;

		xprev:= 0;
		if start = 0 then yprev:=yoffset + ymax div 2 else yprev:= getY;

		s:= start;
    while start <= (s + sampleLength) do begin            
      
      x:= (start - s) * vscreen.width div sampleLength;
      y:= getY;

      drawLine(vscreen, XPrev, YPrev, x, y, theme_Tracker_MainPanel_FontColor);

      XPrev:= x;
      YPrev:= y;

      Inc(start, step);
    end;


		Module.samples[CurrentSample].data.unlock;

	tralalaEngine.Unlock_ReadOnly;
end;



procedure TInstrumentEditor.drawCurrentPosition;
var 
		MainVirtualChannel : integer;
		pos : longint;
begin

	if not playing then exit;

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		if Module.Samples[CurrentSample].Data.Length > 0 then begin
	
			MainVirtualChannel:= PlayerState.HostChannels[1].MainVirtualChannel;		
			if MainVirtualChannel <> 0 then begin
					pos:= (playerState.VirtualChannels[MainVirtualChannel].SamplePosition.PositionInt) * (vscreen.width - 1) div Module.Samples[CurrentSample].Data.Length;
			end;

			drawVlineClip(vscreen, 200, 632 - 200 - 22, pos, Theme_InstrumentEditor_WaveColor);
		end;

	tralalaEngine.Unlock_ReadOnly;

end;





procedure TInstrumentEditor.updateWaveEditor;
begin

	selectBlock;	

	drawBlock;


	DrawWave(drawWaveStart,drawWaveLength);

	drawCurrentPosition;

	if RadioButtonLoopTypeForward.checked or RadioButtonLoopTypePingPong.checked then begin
		updateToucher;
	end;
	
end;


procedure TInstrumentEditor.buildWave;
begin
	selectedBlockStart:= -1;
	selectedBlockEnd:= -1;

	toucherLeftPos:= -1;
	toucherRightPos:= -1;
	
	
	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		Module.samples[CurrentInstrument].data.lock;
			
			drawWaveStart:= 0;
			drawWaveLength:= Module.samples[CurrentInstrument].data.LengthBytes;
		
		Module.samples[CurrentInstrument].data.unlock;

	tralalaEngine.Unlock_ReadOnly;


	getToucherLeftRightPos;

	reloadScrollbar;

end;


procedure TInstrumentEditor.reloadScrollbar;
begin
		
		tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

			if (drawWaveLength <> 0) and ((Module.samples[CurrentSample].data.LengthBytes * (vscreen.width-1) div drawWaveLength) >= (vscreen.width - 1)) then 
				mainScrollBar.resetMaxValue((Module.samples[CurrentSample].data.LengthBytes * (vscreen.width-1) div drawWaveLength) - (vscreen.width - 1))
			else
				mainScrollBar.resetMaxValue(0);

    	if mainScrollBar.maxValue > 0 then mainScrollBar.setCurValue(round(drawWaveStart / drawWaveLength * (vscreen.width - 1)));

    tralalaEngine.Unlock_ReadOnly;

end;


procedure TInstrumentEditor.ScrollBarInstrumentEditorMainProc(const param: string);
begin
	if drawWaveLength <= 0 then exit;
	drawWaveStart:= round(strnum(param) * (drawWaveLength / (vscreen.width - 1)));
	allowSelectBlock:= false;
	allowPianoKeys:= false;
	getToucherLeftRightPos;
	getBlockDrawLeftRightPos;
end;