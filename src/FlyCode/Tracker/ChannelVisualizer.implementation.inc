procedure TTracker.buildChannelVisualizer;
begin

	ChannelImageWidth:= 126;
	ChannelImageHeight:= 90;

	allocImage(ChannelImage0, ChannelImageWidth, ChannelImageHeight);
	allocImage(ChannelImage1, ChannelImageWidth, ChannelImageHeight);
	allocImage(ChannelImage2, ChannelImageWidth, ChannelImageHeight);
	allocImage(ChannelImage3, ChannelImageWidth, ChannelImageHeight);


	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		ChannelVisualizerScrollBar:= TtuiScrollBarHorizontal.Create(MainPanel, 'ChannelVisualizerScrollBar', 0, 184, ChannelImageWidth * 4 + 5, 32 * (Module.NumberOFChannels - 4), @ScrollBarChannelVisualizerMainProc);
		ChannelVisualizerScrollBar.theme:= LoadThemeScrollbarHorizontal;
    	MainPanel.addItem(ChannelVisualizerScrollBar);

    tralalaEngine.Unlock_ReadOnly;


	ChannelSelectableImage0:= TtuiSelectableImage.create(MainPanel, 'ChannelSelectableImage ' + numstr(0), ChannelImageWidth * 0, 93, ChannelImage0, @execProcSelectableImageClick0);
	ChannelSelectableImage0.theme:= LoadThemeSelectableImage;
	ChannelSelectableImage0.execProcDoubleClick:= @execProcSelectableImageDoubleClick0;
	ChannelSelectableImage0.execProcRightClick:= @execProcSelectableImageRightClick0;
	MainPanel.addItem(ChannelSelectableImage0);

	ChannelSelectableImage1:= TtuiSelectableImage.create(MainPanel, 'ChannelSelectableImage ' + numstr(1), ChannelImageWidth * 1 + 1, 93, ChannelImage1, @execProcSelectableImageClick1);
	ChannelSelectableImage1.theme:= LoadThemeSelectableImage;
	ChannelSelectableImage1.execProcDoubleClick:= @execProcSelectableImageDoubleClick1;
	ChannelSelectableImage1.execProcRightClick:= @execProcSelectableImageRightClick1;
	MainPanel.addItem(ChannelSelectableImage1);

	ChannelSelectableImage2:= TtuiSelectableImage.create(MainPanel, 'ChannelSelectableImage ' + numstr(2), ChannelImageWidth * 2 + 2, 93, ChannelImage2, @execProcSelectableImageClick2);
	ChannelSelectableImage2.theme:= LoadThemeSelectableImage;
	ChannelSelectableImage2.execProcDoubleClick:= @execProcSelectableImageDoubleClick2;
	ChannelSelectableImage2.execProcRightClick:= @execProcSelectableImageRightClick2;
	MainPanel.addItem(ChannelSelectableImage2);

	ChannelSelectableImage3:= TtuiSelectableImage.create(MainPanel, 'ChannelSelectableImage ' + numstr(3), ChannelImageWidth * 3 + 3, 93, ChannelImage3, @execProcSelectableImageClick3);
	ChannelSelectableImage3.theme:= LoadThemeSelectableImage;
	ChannelSelectableImage3.execProcDoubleClick:= @execProcSelectableImageDoubleClick3;
	ChannelSelectableImage3.execProcRightClick:= @execProcSelectableImageRightClick3;
	MainPanel.addItem(ChannelSelectableImage3);


	curLeftChannel:= 1;

end;


procedure TTracker.reloadChannelVisualizer;
begin

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		ChannelVisualizerScrollBar.resetMaxValue(32 * (Module.NumberOFChannels - 4));

    tralalaEngine.Unlock_ReadOnly;

end;


procedure TTracker.ScrollBarChannelVisualizerMainProc(const param: string);
begin

	curLeftChannel:=strnum(param) div 32 + 1;

end;	


procedure TTracker.execProcSelectableImageClick0(const param: string);
begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
		Module.ChannelsConfig[curLeftChannel].enabled:= not Module.ChannelsConfig[curLeftChannel].enabled;
	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSelectableImageClick1(const param: string);
begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
		Module.ChannelsConfig[curLeftChannel + 1].enabled:= not Module.ChannelsConfig[curLeftChannel + 1].enabled;
	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSelectableImageClick2(const param: string);
begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
		Module.ChannelsConfig[curLeftChannel + 2].enabled:= not Module.ChannelsConfig[curLeftChannel + 2].enabled;
	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSelectableImageClick3(const param: string);
begin

	tralalaEngine.Lock_Module_ReadWrite(Module);
		Module.ChannelsConfig[curLeftChannel + 3].enabled:= not Module.ChannelsConfig[curLeftChannel + 3].enabled;
	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSelectableImageDoubleClick0(const param: string);
var 
	i : dword;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		if not ChannelSelectMuteAll0 then begin
	
			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= false;
			Module.ChannelsConfig[curLeftChannel].enabled:= true;	
			ChannelSelectMuteAll0:= true;
	
		end else begin
	
			for i:=1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= true;
			ChannelSelectMuteAll0:= false;
	
		end;

	tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcSelectableImageDoubleClick1(const param: string);
var 
	i : dword;
begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		if not ChannelSelectMuteAll1 then begin

			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= false;
			Module.ChannelsConfig[curLeftChannel + 1].enabled:= true;
			ChannelSelectMuteAll1:= true;

		end else begin

			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= true;
			ChannelSelectMuteAll1:= false;

		end;	

	tralalaEngine.Unlock_Module_ReadWrite;	

end;


procedure TTracker.execProcSelectableImageDoubleClick2(const param: string);
var 
	i : dword;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		if not ChannelSelectMuteAll2 then begin
			
			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:=false;
			Module.ChannelsConfig[curLeftChannel + 2].enabled:= true;	
			ChannelSelectMuteAll2:= true;

		end else begin

			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= true;
			ChannelSelectMuteAll2:= false;

		end;	
	
	tralalaEngine.Unlock_Module_ReadWrite;	

end;


procedure TTracker.execProcSelectableImageDoubleClick3(const param: string);
var 
	i : dword;

begin

	tralalaEngine.Lock_Module_ReadWrite(Module);

		if not ChannelSelectMuteAll3 then begin

			for i:= 1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= false;
			Module.ChannelsConfig[curLeftChannel + 3].enabled:= true;
			ChannelSelectMuteAll3:= true;

		end else begin

			for i:=1 to Module.NumberOFChannels do Module.ChannelsConfig[i].enabled:= true;
			ChannelSelectMuteAll3:= false;

		end;

	tralalaEngine.Unlock_Module_ReadWrite;	

end;



procedure TTracker.execProcSelectableImageRightClick0(const param: string);
begin
end;
procedure TTracker.execProcSelectableImageRightClick1(const param: string);
begin
end;
procedure TTracker.execProcSelectableImageRightClick2(const param: string);
begin
end;
procedure TTracker.execProcSelectableImageRightClick3(const param: string);
begin
end;


procedure TTracker.updateChannelVisualizer;
begin
	
	fastfill(ChannelImage0.data, ChannelImageWidth * ChannelImageHeight, $ff000000);
	fastfill(ChannelImage1.data, ChannelImageWidth * ChannelImageHeight, $ff000000);
	fastfill(ChannelImage2.data, ChannelImageWidth * ChannelImageHeight, $ff000000);
	fastfill(ChannelImage3.data, ChannelImageWidth * ChannelImageHeight, $ff000000);

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
		if not Module.ChannelsConfig[curLeftChannel].enabled then ttfPrintStringXY(ChannelImage0, MainPanel.tuiSelf.mainFont, 48, 32, $ffffffff, 'OFF');
		if not Module.ChannelsConfig[curLeftChannel + 1].enabled then ttfPrintStringXY(ChannelImage1, MainPanel.tuiSelf.mainFont, 48, 32, $ffffffff, 'OFF');
		if not Module.ChannelsConfig[curLeftChannel + 2].enabled then ttfPrintStringXY(ChannelImage2, MainPanel.tuiSelf.mainFont, 48, 32, $ffffffff, 'OFF');
		if not Module.ChannelsConfig[curLeftChannel + 3].enabled then ttfPrintStringXY(ChannelImage3, MainPanel.tuiSelf.mainFont, 48, 32, $ffffffff, 'OFF');
	tralalaEngine.Unlock_ReadOnly;

	ttfPrintStringXY(ChannelImage0, MainPanel.tuiSelf.mainFont, 8, 2, $ffffffff, numstr(curLeftChannel));
	ttfPrintStringXY(ChannelImage1, MainPanel.tuiSelf.mainFont, 8, 2, $ffffffff, numstr(curLeftChannel + 1));
	ttfPrintStringXY(ChannelImage2, MainPanel.tuiSelf.mainFont, 8, 2, $ffffffff, numstr(curLeftChannel + 2));
	ttfPrintStringXY(ChannelImage3, MainPanel.tuiSelf.mainFont, 8, 2, $ffffffff, numstr(curLeftChannel + 3));

end;