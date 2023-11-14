const
	PlayNote = 0;
	StopNote = 1;


procedure netSendCurrentChannel;
procedure netSendCurrentCursor;
procedure netSendTrackerScrollBar(value: longint);
procedure netSendCurrentEditMode;





procedure netSendSetNote(pattern, row, channel: longint; note: TNote);
procedure netSendPlayNote(channel: longint; key: longint; mode: longint);


procedure netSendButtonPlaySong;
procedure netSendButtonPlayPattern;
procedure netSendButtonStopSong;
procedure netSendButtonRecordSong;
procedure netSendButtonRecordPattern;
procedure netSendButtonTranspose;
procedure netSendButtonAdvancedEdit;	

procedure netSendButtonCurrentInstrumentTrackUp;
procedure netSendButtonCurrentInstrumentTrackDown;
procedure netSendButtonCurrentInstrumentTrack12UP;
procedure netSendButtonCurrentInstrumentTrack12Down;
procedure netSendButtonAllInstrumentsTrackUP;
procedure netSendButtonAllInstrumentsTrackDown;	
procedure netSendButtonAllInstrumentsTrack12Up;
procedure netSendButtonAllInstrumentsTrack12Down;	
procedure netSendButtonCurrentInstrumentPatternUP;
procedure netSendButtonCurrentInstrumentPatternDown;
procedure netSendButtonCurrentInstrumentPattern12Up;
procedure netSendButtonCurrentInstrumentPattern12Down;
procedure netSendButtonAllInstrumentsPatternUp;
procedure netSendButtonAllInstrumentsPatternDown;
procedure netSendButtonAllInstrumentsPattern12Up;
procedure netSendButtonAllInstrumentsPattern12Down;
procedure netSendButtonCurrentInstrumentSongUP;
procedure netSendButtonCurrentInstrumentSongDown;
procedure netSendButtonCurrentInstrumentSong12Up;
procedure netSendButtonCurrentInstrumentSong12Down;	
procedure netSendButtonAllInstrumentsSongUP;
procedure netSendButtonAllInstrumentsSongDown;
procedure netSendButtonAllInstrumentsSong12Up;
procedure netSendButtonAllInstrumentsSong12Down;
procedure netSendButtonCurrentInstrumentBlockUP;
procedure netSendButtonCurrentInstrumentBlockDown;
procedure netSendButtonCurrentInstrumentBlock12Up;
procedure netSendButtonCurrentInstrumentBlock12Down;
procedure netSendButtonAllInstrumentsBlockUP;
procedure netSendButtonAllInstrumentsBlockDown;
procedure netSendButtonAllInstrumentsBlock12Up;
procedure netSendButtonAllInstrumentsBlock12Down;

procedure netSendButtonRemapInstrumentTrack;
procedure netSendButtonRemapInstrumentPattern;
procedure netSendButtonRemapInstrumentSong;
procedure netSendButtonRemapInstrumentBlock;

procedure netSendButtonShrink;
procedure netSendButtonExpand;

procedure netSendButtonUPRepeatStart(value: longint);
procedure netSendButtonDOWNRepeatStart(value: longint);	
procedure netSendButtonUPBPM(value: longint);
procedure netSendButtonDOWNBPM(value: longint);	
procedure netSendButtonUPSpeed(value: longint);
procedure netSendButtonDOWNSpeed(value: longint);
procedure netSendButtonUPLength(value: longint);
procedure netSendButtonDOWNLength(value: longint);
procedure netSendButtonUPChannels(value: longint);
procedure netSendButtonDOWNChannels(value: longint);
procedure netSendButtonUPAdd(value: longint);
procedure netSendButtonDOWNAdd(value: longint);
procedure netSendButtonUPOctave(value: longint);
procedure netSendButtonDOWNOctave(value: longint);

procedure netSendChangeRow(value: longint);

procedure netSendButtonCopyBlock;
procedure netSendButtonPasteBlock;	
procedure netSendButtonSelectTrackBlock; 











// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************
// ****************************************************************************************************************************************











procedure netGetCurrentChannel;
procedure netGetCurrentCursorPos;
procedure netGetTrackerMainScrollbar;
procedure netGetCurrentEditMode;




procedure netGetSetNote;

procedure netGetPlayNote;


procedure netGetButtonPlaySong;
procedure netGetButtonPlayPattern;	
procedure netGetButtonStopSong;		
procedure netGetButtonRecordSong;
procedure netGetButtonRecordPattern;	
procedure netGetButtonTranspose;	
procedure netGetButtonAdvancedEdit;

procedure netGetButtonCurrentInstrumentTrackUP;
procedure netGetButtonCurrentInstrumentTrackDown;
procedure netGetButtonCurrentInstrumentTrack12UP;
procedure netGetButtonCurrentInstrumentTrack12Down;	
procedure netGetButtonAllInstrumentsTrackUP;
procedure netGetButtonAllInstrumentsTrackDown;	
procedure netGetButtonAllInstrumentsTrack12UP;
procedure netGetButtonAllInstrumentsTrack12Down;	
procedure netGetButtonCurrentInstrumentPatternUP;
procedure netGetButtonCurrentInstrumentPatternDown;
procedure netGetButtonCurrentInstrumentPattern12Up;
procedure netGetButtonCurrentInstrumentPattern12Down;
procedure netGetButtonAllInstrumentsPatternUp;
procedure netGetButtonAllInstrumentsPatternDown;
procedure netGetButtonAllInstrumentsPattern12Up;
procedure netGetButtonAllInstrumentsPattern12Down;
procedure netGetButtonCurrentInstrumentSongUp;
procedure netGetButtonCurrentInstrumentSongDown;
procedure netGetButtonCurrentInstrumentSong12Up;
procedure netGetButtonCurrentInstrumentSong12Down;
procedure netGetButtonAllInstrumentsSongUP;
procedure netGetButtonAllInstrumentsSongDown;
procedure netGetButtonAllInstrumentsSong12Up;
procedure netGetButtonAllInstrumentsSong12Down;
procedure netGetButtonCurrentInstrumentBlockUP;
procedure netGetButtonCurrentInstrumentBlockDown;
procedure netGetButtonCurrentInstrumentBlock12Up;
procedure netGetButtonCurrentInstrumentBlock12Down;
procedure netGetButtonAllInstrumentsBlockUP;
procedure netGetButtonAllInstrumentsBlockDown;
procedure netGetButtonAllInstrumentsBlock12Up;
procedure netGetButtonAllInstrumentsBlock12Down;

procedure netGetButtonRemapInstrumentTrack;
procedure netGetButtonRemapInstrumentPattern;
procedure netGetButtonRemapInstrumentSong;
procedure netGetButtonRemapInstrumentBlock;

procedure netGetButtonUPRepeatStart;
procedure netGetButtonDOWNRepeatStart;	
procedure netGetButtonUPBPM;
procedure netGetButtonDOWNBPM;	
procedure netGetButtonUPSpeed;
procedure netGetButtonDOWNSpeed;
procedure netGetButtonUPLength;
procedure netGetButtonDOWNLength;
procedure netGetButtonUPChannels;
procedure netGetButtonDOWNChannels;
procedure netGetButtonUPAdd;
procedure netGetButtonDOWNAdd;
procedure netGetButtonUPOctave;
procedure netGetButtonDOWNOctave;

procedure netGetChangeRow;

procedure netGetButtonShrink;
procedure netGetButtonExpand;


procedure netGetButtonCopyBlock;
procedure netGetButtonPasteBlock;
procedure netGetButtonSelectTrackBlock;