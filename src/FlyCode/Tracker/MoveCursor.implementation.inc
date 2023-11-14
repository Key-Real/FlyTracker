procedure TTracker.doRightKey;
begin

	if currentChannelMode = cursorMode.effect3 then begin

		inc(currentChannel);
		if currentChannel > Module.NumberOFChannels then begin
			currentChannel:= 1;
			mainScrollBar.setCurValue(0);
		end;

		
		moveRight:= true;

		currentChannelMode:= cursorMode.note;
	end
	else if currentChannelMode = cursorMode.effect2 then currentChannelMode:= cursorMode.effect3
	else if currentChannelMode = cursorMode.effect1 then currentChannelMode:= cursorMode.effect2
	else if currentChannelMode = cursorMode.volume2 then currentChannelMode:= cursorMode.effect1
	else if currentChannelMode = cursorMode.volume1 then currentChannelMode:= cursorMode.volume2
	else if currentChannelMode = cursorMode.instrument2 then currentChannelMode:= cursorMode.volume1
	else if currentChannelMode = cursorMode.instrument1 then currentChannelMode:= cursorMode.instrument2
	else if currentChannelMode = cursorMode.note then currentChannelMode:= cursorMode.instrument1;

	netSendCurrentChannel;	
	netSendCurrentCursor;

end;


procedure TTracker.handleRightKey;
begin

	if keyboard[KEY_RIGHT] and (not RightKeyDB) then begin
		RightKeyDB:= true;
		doRightKey;
	end;

	if not keyboard[KEY_RIGHT] then begin
		RightKeyDB:= false;
		RightKeyStartTimeDB:= false;
        RightKeyAllow:= false;
	end;

    if keyboard[KEY_RIGHT] then begin
    
	    if not RightKeyStartTimeDB then begin
	        RightKeyStartTimeDB:= true;
	        RightKeyStartTime:= GetTickCount64;
	    end;

	    if ((RightKeyStartTime + Theme_Tracker_DisplayPattern_Key_TimeOut) < GetTickCount64) and (not RightKeyAllow) then begin
	        RightKeyStartTime:= GetTickCount64;
	        RightKeyAllow:= true;
	    end;

	    if RightKeyAllow then inc(RightKeyTime);

	    if RightKeyTime > Theme_Tracker_DisplayPattern_Key_Time_Counter then begin
	        RightKeyTime:= 0;

	        doRightKey;
	        
	    end;

	end;

end;


procedure TTracker.doLeftKey;
begin
	
	if currentChannelMode = cursorMode.note then begin

			dec(currentChannel);

			if currentChannel < 1 then begin
				currentChannel:= Module.NumberOFChannels;
				mainScrollBar.setCurValue(mainScrollBar.maxValue);
			end;

			moveLeft:= true;

			currentChannelMode:= cursorMode.effect3;
	end
	else if currentChannelMode = cursorMode.effect3 then currentChannelMode:= cursorMode.effect2
	else if currentChannelMode = cursorMode.effect2 then currentChannelMode:= cursorMode.effect1
	else if currentChannelMode = cursorMode.effect1 then currentChannelMode:= cursorMode.volume2
	else if currentChannelMode = cursorMode.volume2 then currentChannelMode:= cursorMode.volume1
	else if currentChannelMode = cursorMode.volume1 then currentChannelMode:= cursorMode.instrument2
	else if currentChannelMode = cursorMode.instrument2 then currentChannelMode:= cursorMode.instrument1
	else if currentChannelMode = cursorMode.instrument1 then currentChannelMode:= cursorMode.note;

	netSendCurrentChannel;
	netSendCurrentCursor;	
	
end;


procedure TTracker.handleLeftKey;
begin

	if keyboard[KEY_LEFT] and (not LeftKeyDB) then begin
		LeftKeyDB:= true;
		doLeftKey;
	end;

	if not keyboard[KEY_LEFT] then begin
		LeftKeyDB:= false;
		LeftKeyStartTimeDB:= false;
        LeftKeyAllow:= false;
	end;

    if keyboard[KEY_LEFT] then begin
    
	    if not LeftKeyStartTimeDB then begin
	        LeftKeyStartTimeDB:= true;
	        LeftKeyStartTime:= GetTickCount64;
	    end;

	    if ((LeftKeyStartTime + Theme_Tracker_DisplayPattern_Key_TimeOut) < GetTickCount64) and (not LeftKeyAllow) then begin
	        LeftKeyStartTime:= GetTickCount64;
	        LeftKeyAllow:= true;
	    end;

	    if LeftKeyAllow then inc(LeftKeyTime);

	    if LeftKeyTime > Theme_Tracker_DisplayPattern_Key_Time_Counter then begin
	        LeftKeyTime:= 0;

	        doLeftKey;
	        
	    end;

	end;

end;


procedure TTracker.doUpKey;
begin	

  	dec(currentRow);
  	if currentRow < 0 then currentRow:= Module.Patterns[CurrentPattern].RowsCount - 1;
  	netSendChangeRow(currentRow);

end;


procedure TTracker.handleUpKey;
begin

	if keyboard[KEY_UP] and (not UpKeyDB) then begin
		UpKeyDB:= true;
		doUpKey;
	end;

	if not keyboard[KEY_UP] then begin
		UpKeyDB:= false;
		UpKeyStartTimeDB:= false;
        UpKeyAllow:= false;
	end;

    if keyboard[KEY_UP] then begin
    
	    if not UpKeyStartTimeDB then begin
	        UpKeyStartTimeDB:= true;
	        UpKeyStartTime:= GetTickCount64;
	    end;

	    if ((UpKeyStartTime + Theme_Tracker_DisplayPattern_Key_TimeOut) < GetTickCount64) and (not UpKeyAllow) then begin
	        UpKeyStartTime:= GetTickCount64;
	        UpKeyAllow:= true;
	    end;

	    if UpKeyAllow then inc(UpKeyTime);

	    if UpKeyTime > Theme_Tracker_DisplayPattern_Key_Time_Counter then begin
	        UpKeyTime:= 0;

	        doUpKey;
	        
	    end;

	end;	

end;


procedure TTracker.doDownKey;
begin

	inc(currentRow);
	if currentRow > (Module.Patterns[CurrentPattern].RowsCount - 1) then currentRow:= 0;
	netSendChangeRow(currentRow);

end;


procedure TTracker.handleDownKey;
begin

	if keyboard[KEY_DOWN] and (not DownKeyDB) then begin
		DownKeyDB:= true;
		doDownKey;
	end;

	if not keyboard[KEY_DOWN] then begin
		DownKeyDB:= false;
		DownKeyStartTimeDB:= false;
        DownKeyAllow:= false;
	end;

    if keyboard[KEY_DOWN] then begin
    
	    if not DownKeyStartTimeDB then begin
	        DownKeyStartTimeDB:= true;
	        DownKeyStartTime:= GetTickCount64;
	    end;

	    if ((DownKeyStartTime + Theme_Tracker_DisplayPattern_Key_TimeOut) < GetTickCount64) and (not DownKeyAllow) then begin
	        DownKeyStartTime:= GetTickCount64;
	        DownKeyAllow:= true;
	    end;

	    if DownKeyAllow then inc(DownKeyTime);

	    if DownKeyTime > Theme_Tracker_DisplayPattern_Key_Time_Counter then begin
	        DownKeyTime:= 0;

	        doDownKey;
	        
	    end;

	end;	

end;


procedure TTracker.handleWheel;
begin

	if ((mouseWheel <> 0) and (mouseY > 18 + 190) and (mouseY < 720 - 18 - 16)) then begin
		
		if mouseWheel <> 0 then currentRow:= currentRow + mouseWheel;

  		if currentRow < 0 then currentRow:= Module.Patterns[CurrentPattern].RowsCount - 1;
  		if currentRow > (Module.Patterns[CurrentPattern].RowsCount - 1) then currentRow:= 0;

  		netSendChangeRow(currentRow);

	end;

end;



procedure TTracker.moveCursor;
label 
	l1, l2;

var
	channelChanged : boolean;

begin
	
	channelChanged:= false;

	lastCursorPositionChannel:= currentChannel;
	lastCursorPositionRow:= currentRow;

	handleRightKey;
	handleLeftKey;
	handleUpKey;
	handleDownKey;
	handleWheel;


	if keyboard[KEY_HOME] then begin
		
		currentChannel:= 1;
		currentChannelMode:= note;		
		mainScrollBar.setCurValue(0);
		drawCursorChannel:= 1;
		if drawCursorChannel < 1 then drawCursorChannel:= 1;
		if drawCursorChannel > 11 then drawCursorChannel:= 11;

		netSendCurrentChannel;

		exit;
	end;

	if keyboard[KEY_END] then begin

		currentChannel:= Module.NumberOFChannels;
		currentChannelMode:= note;				
		mainScrollBar.setCurValue(mainScrollBar.maxValue);
		drawCursorChannel:= Module.NumberOFChannels;
		if drawCursorChannel < 1 then drawCursorChannel:= 1;
		if drawCursorChannel > 11 then drawCursorChannel:= 11;
		
		netSendCurrentChannel;
		
		exit;
	end;


	if keyboard[KEY_TAB] and (not TabKeyOnce) then begin
		TabKeyOnce:= true;

		inc(currentChannel);
		if currentChannel > Module.NumberOFChannels then currentChannel:= 1;

		netSendCurrentChannel;
	end;

	if not keyboard[KEY_TAB] then TabKeyOnce:= false;


	if keyboard[KEY_PAGEUP] and (not PageUpOnce) then begin
		PageUpOnce:= true;
		
		dec(currentRow, 16);	
		l1:
		if currentRow < 0 then begin
			currentRow:= Module.Patterns[CurrentPattern].RowsCount + currentRow;
			goto l1;
		end;

		netSendChangeRow(currentRow);
	end;
	if not keyboard[KEY_PAGEUP] then PageUpOnce:= false;


	if keyboard[KEY_PAGEDOWN] and (not PageDownOnce) then begin
		PageDownOnce:= true;
		
		inc(currentRow, 16);	
		l2:
		if currentRow >= Module.Patterns[CurrentPattern].RowsCount then begin
			currentRow:= currentRow - Module.Patterns[CurrentPattern].RowsCount;
			goto l2;
		end;
		
		netSendChangeRow(currentRow);
	end;
	if not keyboard[KEY_PAGEDOWN] then PageDownOnce:= false;


	if keyboard[KEY_LALT] and keyboard[KEY_Q] then begin
		currentChannel:= 1;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_W] then begin
		currentChannel:= 2; 
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_E] then begin
		currentChannel:= 3;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_R] then begin
		currentChannel:= 4;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_T] then begin
		currentChannel:= 5;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_Z] then begin
		currentChannel:= 6;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_U] then begin
		currentChannel:= 7;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_I] then begin
		currentChannel:= 8;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_A] then begin
		currentChannel:= 9;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_S] then begin
		currentChannel:= 10;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_D] then begin
		currentChannel:= 11;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_F] then begin
		currentChannel:= 12;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_G] then begin
		currentChannel:= 13;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_H] then begin
		currentChannel:= 14;
		channelChanged:= true;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_J] then begin
		currentChannel:= 15;
	end;
	if keyboard[KEY_LALT] and keyboard[KEY_K] then begin
		currentChannel:= 16;
	end;

 	if currentChannel > Module.NumberOFChannels then currentChannel:= Module.NumberOFChannels;

	
	drawCursorChannel:= currentChannel - (mainScrollBar.curValue div 64);
	if drawCursorChannel < 1 then begin
		inc(currentChannel);
		if not mainScrollBar.isMoving then mainScrollBar.setCurValue(mainScrollBar.curValue - 64);
		channelChanged:= true;
	end;

	if drawCursorChannel > 11 then begin
		dec(currentChannel);
		if not mainScrollBar.isMoving then mainScrollBar.setcurValue(mainScrollBar.curValue + 64);
		channelChanged:= true;
	end;

	if drawCursorChannel < 1 then drawCursorChannel:= 1;
	if drawCursorChannel > 11 then drawCursorChannel:= 11;

	if channelChanged then netSendCurrentChannel;
end;


procedure TTracker.drawCursorBar;
begin

	drawBar(vscreen, 0, Theme_Tracker_TrackerBar_YPosition, 1280, Theme_Tracker_TrackerBar_YPosition + 17, Theme_Tracker_TrackerBar_BackgroundColor);

end;


procedure TTracker.drawCursor;
begin	

	if currentChannelMode = cursorMode.note then
  		drawBar(vscreen, (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Note_Offset,
  			             Theme_Tracker_TrackerBar_YPosition + 2,
  			             (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Note_Offset + Theme_Tracker_DisplayPattern_CursorMode_Note_Length,
  			             Theme_Tracker_TrackerBar_YPosition + 16, Theme_Tracker_DisplayPattern_CursorColor);

	if currentChannelMode = cursorMode.instrument1 then
  		drawBar(vscreen, (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Instrument1_Offset,
  						 Theme_Tracker_TrackerBar_YPosition + 2,
  						 (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Instrument1_Offset + Theme_Tracker_DisplayPattern_CursorMode_Instrument1_Length,
  						 Theme_Tracker_TrackerBar_YPosition + 16, Theme_Tracker_DisplayPattern_CursorColor);

	if currentChannelMode = cursorMode.instrument2 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Instrument2_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Instrument2_Offset + Theme_Tracker_DisplayPattern_CursorMode_Instrument2_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16, Theme_Tracker_DisplayPattern_CursorColor);

  	if currentChannelMode = cursorMode.volume1 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Volume1_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Volume1_Offset + Theme_Tracker_DisplayPattern_CursorMode_Volume1_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16,
  			            Theme_Tracker_DisplayPattern_CursorColor);

	if currentChannelMode = cursorMode.volume2 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Volume2_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Volume2_Offset + Theme_Tracker_DisplayPattern_CursorMode_Volume2_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16, Theme_Tracker_DisplayPattern_CursorColor);

	if currentChannelMode = cursorMode.effect1 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect1_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect1_Offset + Theme_Tracker_DisplayPattern_CursorMode_Effect1_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16,
  			            Theme_Tracker_DisplayPattern_CursorColor);

	if currentChannelMode = cursorMode.effect2 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect2_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect2_Offset + Theme_Tracker_DisplayPattern_CursorMode_Effect2_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16,
  			            Theme_Tracker_DisplayPattern_CursorColor);
	
	if currentChannelMode = cursorMode.effect3 then
  		drawBar(vscreen,(drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect3_Offset,
  			            Theme_Tracker_TrackerBar_YPosition + 2,
  			            (drawCursorChannel - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + Theme_Tracker_DisplayPattern_LeftOffset + Theme_Tracker_DisplayPattern_CursorMode_Effect3_Offset + Theme_Tracker_DisplayPattern_CursorMode_Effect3_Length,
  			            Theme_Tracker_TrackerBar_YPosition + 16,
  			            Theme_Tracker_DisplayPattern_CursorColor);
end;