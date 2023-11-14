
public 
	procedure buildChannelVisualizer;
	procedure reloadChannelVisualizer;

	var
		ChannelImage0 : gfxImage;
		ChannelImage1 : gfxImage;
		ChannelImage2 : gfxImage;
		ChannelImage3 : gfxImage;

		ChannelSelectableImage0 : TtuiSelectableImage;
		ChannelSelectableImage1 : TtuiSelectableImage;
		ChannelSelectableImage2 : TtuiSelectableImage;
		ChannelSelectableImage3 : TtuiSelectableImage;

		ChannelSelectMuteAll0 : boolean;
		ChannelSelectMuteAll1 : boolean;
		ChannelSelectMuteAll2 : boolean;
		ChannelSelectMuteAll3 : boolean;

		ChannelImageWidth, ChannelImageHeight : dword;

		ChannelVisualizerScrollBar : TtuiScrollBarHorizontal;


		curLeftChannel : longint;

	procedure ScrollBarChannelVisualizerMainProc(const param: string);

	procedure execProcSelectableImageClick0(const param: string);
	procedure execProcSelectableImageClick1(const param: string);
	procedure execProcSelectableImageClick2(const param: string);
	procedure execProcSelectableImageClick3(const param: string);

	procedure execProcSelectableImageDoubleClick0(const param: string);
	procedure execProcSelectableImageDoubleClick1(const param: string);
	procedure execProcSelectableImageDoubleClick2(const param: string);
	procedure execProcSelectableImageDoubleClick3(const param: string);


	procedure execProcSelectableImageRightClick0(const param: string);
	procedure execProcSelectableImageRightClick1(const param: string);
	procedure execProcSelectableImageRightClick2(const param: string);
	procedure execProcSelectableImageRightClick3(const param: string);



	procedure updateChannelVisualizer;