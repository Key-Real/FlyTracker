var
		TextFieldCurrentInstrument : TtuiTextField;
		TextFieldAllInstruments : TtuiTextField;

		TextFieldTrack : TtuiTextField;
		TextFieldPattern : TtuiTextField;
		TextFieldSong : TtuiTextField;
		TextFieldBlock : TtuiTextField;

		ButtonCurrentInstrumentTrackUP : TtuiButton;
		ButtonCurrentInstrumentTrackDown : TtuiButton;
		ButtonCurrentInstrumentTrack12UP : TtuiButton;
		ButtonCurrentInstrumentTrack12Down : TtuiButton;
		ButtonCurrentInstrumentPatternUP : TtuiButton;
		ButtonCurrentInstrumentPatternDown : TtuiButton;
		ButtonCurrentInstrumentPattern12Up : TtuiButton;
		ButtonCurrentInstrumentPattern12Down : TtuiButton;
		ButtonCurrentInstrumentSongUp : TtuiButton;
		ButtonCurrentInstrumentSongDown : TtuiButton;
		ButtonCurrentInstrumentSong12Up : TtuiButton;
		ButtonCurrentInstrumentSong12Down : TtuiButton;
		ButtonCurrentInstrumentBlockUp : TtuiButton;
		ButtonCurrentInstrumentBlockDown : TtuiButton;
		ButtonCurrentInstrumentBlock12Up : TtuiButton;
		ButtonCurrentInstrumentBlock12Down : TtuiButton;

		ButtonAllInstrumentsTrackUP : TtuiButton;
		ButtonAllInstrumentsTrackDown : TtuiButton;
		ButtonAllInstrumentsTrack12UP : TtuiButton;
		ButtonAllInstrumentsTrack12Down : TtuiButton;
		ButtonAllInstrumentsPatternUP : TtuiButton;
		ButtonAllInstrumentsPatternDown : TtuiButton;
		ButtonAllInstrumentsPattern12Up : TtuiButton;
		ButtonAllInstrumentsPattern12Down : TtuiButton;
		ButtonAllInstrumentsSongUp : TtuiButton;
		ButtonAllInstrumentsSongDown : TtuiButton;
		ButtonAllInstrumentsSong12Up : TtuiButton;
		ButtonAllInstrumentsSong12Down : TtuiButton;
		ButtonAllInstrumentsBlockUp : TtuiButton;
		ButtonAllInstrumentsBlockDown : TtuiButton;
		ButtonAllInstrumentsBlock12Up : TtuiButton;
		ButtonAllInstrumentsBlock12Down : TtuiButton;

		TransposeEnabled : boolean;

		procedure EnableDisableTranspose(enable: boolean);


		procedure doButtonCurrentInstrumentTrackUP;
		procedure execProcButtonCurrentInstrumentTrackUP(const param: string);

		procedure doButtonCurrentInstrumentTrackDown;
		procedure execProcButtonCurrentInstrumentTrackDown(const param: string);

		procedure doButtonCurrentInstrumentTrack12UP;
		procedure execProcButtonCurrentInstrumentTrack12UP(const param: string);

		procedure doButtonCurrentInstrumentTrack12Down;
		procedure execProcButtonCurrentInstrumentTrack12Down(const param: string);

		
		procedure doButtonAllInstrumentsTrackUP;
		procedure execProcButtonAllInstrumentsTrackUP(const param: string);

		procedure doButtonAllInstrumentsTrackDown;
		procedure execProcButtonAllInstrumentsTrackDown(const param: string);

		procedure doButtonAllInstrumentsTrack12UP;
		procedure execProcButtonAllInstrumentsTrack12UP(const param: string);

		procedure doButtonAllInstrumentsTrack12Down;
		procedure execProcButtonAllInstrumentsTrack12Down(const param: string);


		procedure doButtonCurrentInstrumentPatternUP;
		procedure execProcButtonCurrentInstrumentPatternUP(const param: string);

		procedure doButtonCurrentInstrumentPatternDown;
		procedure execProcButtonCurrentInstrumentPatternDown(const param: string);

		procedure doButtonCurrentInstrumentPattern12UP;
		procedure execProcButtonCurrentInstrumentPattern12UP(const param: string);

		procedure doButtonCurrentInstrumentPattern12Down;
		procedure execProcButtonCurrentInstrumentPattern12Down(const param: string);

		procedure doButtonAllInstrumentsPatternUP;
		procedure execProcButtonAllInstrumentsPatternUP(const param: string);

		procedure doButtonAllInstrumentsPatternDown;
		procedure execProcButtonAllInstrumentsPatternDown(const param: string);

		procedure doButtonAllInstrumentsPattern12UP;
		procedure execProcButtonAllInstrumentsPattern12UP(const param: string);

		procedure doButtonAllInstrumentsPattern12Down;
		procedure execProcButtonAllInstrumentsPattern12Down(const param: string);


		procedure doButtonCurrentInstrumentSongUP;
		procedure execProcButtonCurrentInstrumentSongUP(const param: string);

		procedure doButtonCurrentInstrumentSongDown;
		procedure execProcButtonCurrentInstrumentSongDown(const param: string);

		procedure doButtonCurrentInstrumentSong12UP;
		procedure execProcButtonCurrentInstrumentSong12UP(const param: string);

		procedure doButtonCurrentInstrumentSong12Down;
		procedure execProcButtonCurrentInstrumentSong12Down(const param: string);

		procedure doButtonAllInstrumentsSongUP;
		procedure execProcButtonAllInstrumentsSongUP(const param: string);

		procedure doButtonAllInstrumentsSongDown;
		procedure execProcButtonAllInstrumentsSongDown(const param: string);

		procedure doButtonAllInstrumentsSong12UP;
		procedure execProcButtonAllInstrumentsSong12UP(const param: string);

		procedure doButtonAllInstrumentsSong12Down;
		procedure execProcButtonAllInstrumentsSong12Down(const param: string);

		procedure doButtonCurrentInstrumentBlockUP;
		procedure execProcButtonCurrentInstrumentBlockUP(const param: string);

		procedure doButtonCurrentInstrumentBlockDown;
		procedure execProcButtonCurrentInstrumentBlockDown(const param: string);

		procedure doButtonCurrentInstrumentBlock12UP;
		procedure execProcButtonCurrentInstrumentBlock12UP(const param: string);

		procedure doButtonCurrentInstrumentBlock12Down;
		procedure execProcButtonCurrentInstrumentBlock12Down(const param: string);

		procedure doButtonAllInstrumentsBlockUP;
		procedure execProcButtonAllInstrumentsBlockUP(const param: string);

		procedure doButtonAllInstrumentsBlockDown;
		procedure execProcButtonAllInstrumentsBlockDown(const param: string);

		procedure doButtonAllInstrumentsBlock12UP;
		procedure execProcButtonAllInstrumentsBlock12UP(const param: string);

		procedure doButtonAllInstrumentsBlock12Down;
		procedure execProcButtonAllInstrumentsBlock12Down(const param: string);

		procedure BuildTranspose;
