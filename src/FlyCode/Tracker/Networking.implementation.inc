procedure TTracker.netSendCurrentChannel;
var 
    buf : array [0..2] of longint;

begin

    if (not isConnected) or (not netsync) then exit;
    
    buf[0]:= Tracker.currentChannel;
    buf[1]:= Tracker.mainScrollBar.curValue;
    buf[2]:= Tracker.drawCursorChannel;

    sendTCP(IDCurrentChannel, buf);

end;

    
procedure TTracker.netSendCurrentCursor;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) or (not netsync) then exit;

    case Tracker.currentChannelMode of
        cursorMode.note : buf[0]:= 1;
        cursorMode.instrument1 : buf[0]:= 2;
        cursorMode.instrument2 : buf[0]:= 3;
        cursorMode.volume1 : buf[0]:= 4;
        cursorMode.volume2 : buf[0]:= 5;
        cursorMode.effect1 : buf[0]:= 6;
        cursorMode.effect2 : buf[0]:= 7;
        cursorMode.effect3 : buf[0]:= 8;
    end;

    sendTCP(IDCurrentCursor, buf);

end;


procedure TTracker.netSendTrackerScrollBar(value: longint);
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) or (not netsync) then exit;

    buf[0]:= value;

    sendTCP(IDTrackerMainScrollbar, buf);

end;


procedure TTracker.netSendCurrentEditMode;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) or (not netsync) then exit;

    buf[0]:= longint(tracker.trackerInEditMode);

    sendTCP(IDCurrentEditMode, buf);

end;






procedure TTracker.netSendSetNote(pattern, row, channel: longint; note: TNote);
var 
    buf : array [0..10] of longint;

begin

    if not isConnected then exit;

    buf[0]:= pattern;
    buf[1]:= row;
    buf[2]:= channel;

    buf[3]:= note.note;
    buf[4]:= note.Instrument;
    buf[5]:= longint(note.volume.EffectType);
    buf[6]:= note.volume.EffectParam;
    buf[7]:= longint(note.panning.EffectType); 
    buf[8]:= note.panning.EffectParam;
    buf[9]:= longint(note.EffectType);
    buf[10]:= note.EffectParam;

    sendTCP(IDSetNote, buf);

end;


procedure TTracker.netSendPlayNote(channel: longint; key: longint; mode: longint);
var 
    buf : array [0..2] of longint;

begin
    
    if (not isConnected) or (not netsync) then exit;

    if not allowVirtualPiano then exit;

    buf[0]:= key;
    buf[1]:= currentInstrument;
    buf[2]:= mode;

    sendTCP(IDPlayNote, buf);

end;




procedure TTracker.netSendButtonPlaySong;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonPlaySong, buf);

end;


procedure TTracker.netSendButtonPlayPattern;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonPlayPattern, buf);

end;


procedure TTracker.netSendButtonStopSong;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonStopSong, buf);

end;


procedure TTracker.netSendButtonRecordSong;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRecordSong, buf);

end;


procedure TTracker.netSendButtonRecordPattern;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRecordPattern, buf);

end;


procedure TTracker.netSendButtonTranspose;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonTranspose, buf);

end;


procedure TTracker.netSendButtonAdvancedEdit;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAdvancedEdit, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentTrackUp;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentTrackUP, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentTrackDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentTrackDown, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentTrack12UP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentTrack12UP, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentTrack12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentTrack12Down, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsTrackUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsTrackUP, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsTrackDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsTrackDown, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsTrack12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsTrack12Up, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsTrack12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsTrack12Down, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentPatternUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentPatternUP, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentPatternDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentPatternDown, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentPattern12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentPattern12Up, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentPattern12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentPattern12Down, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsPatternUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsPatternUP, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsPatternDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsPatternDown, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsPattern12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsPattern12Up, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsPattern12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsPattern12Down, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentSongUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentSongUP, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentSongDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentSongDown, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentSong12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentSong12Up, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentSong12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentSong12Down, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsSongUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsSongUP, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsSongDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsSongDown, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsSong12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsSong12Up, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsSong12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsSong12Down, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentBlockUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentBlockUP, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentBlockDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentBlockDown, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentBlock12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentBlock12Up, buf);

end;


procedure TTracker.netSendButtonCurrentInstrumentBlock12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonCurrentInstrumentBlock12Down, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsBlockUP;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsBlockUP, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsBlockDown;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsBlockDown, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsBlock12Up;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsBlock12Up, buf);

end;


procedure TTracker.netSendButtonAllInstrumentsBlock12Down;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonAllInstrumentsBlock12Down, buf);

end;


procedure TTracker.netSendButtonRemapInstrumentTrack;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRemapInstrumentTrack, buf);

end;


procedure TTracker.netSendButtonRemapInstrumentPattern;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRemapInstrumentPattern, buf);

end;


procedure TTracker.netSendButtonRemapInstrumentSong;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRemapInstrumentSong, buf);

end;


procedure TTracker.netSendButtonRemapInstrumentBlock;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonRemapInstrumentBlock, buf);

end;


procedure TTracker.netSendButtonShrink;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonShrink, buf);

end;


procedure TTracker.netSendButtonExpand;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonExpand, buf);

end;

procedure TTracker.netSendButtonUPRepeatStart(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPRepeatStart, buf);

end;


procedure TTracker.netSendButtonDOWNRepeatStart(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNRepeatStart, buf);

end;



procedure TTracker.netSendButtonUPBPM(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPBPM, buf);

end;


procedure TTracker.netSendButtonDOWNBPM(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNBPM, buf);

end;


procedure TTracker.netSendButtonUPSpeed(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPSpeed, buf);

end;


procedure TTracker.netSendButtonDOWNSpeed(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNSpeed, buf);

end;


procedure TTracker.netSendButtonUPLength(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPLength, buf);

end;


procedure TTracker.netSendButtonDOWNLength(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNLength, buf);

end;


procedure TTracker.netSendButtonUPChannels(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPChannels, buf);

end;


procedure TTracker.netSendButtonDOWNChannels(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNChannels, buf);

end;


procedure TTracker.netSendButtonUPAdd(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPAdd, buf);

end;


procedure TTracker.netSendButtonDOWNAdd(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if not isConnected then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNAdd, buf);

end;


procedure TTracker.netSendButtonUPOctave(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if (not isConnected) and (not netsync) then exit;

    buf[0]:= value;

    sendTCP(IDButtonUPOctave, buf);

end;


procedure TTracker.netSendButtonDOWNOctave(value: longint);
var 
    buf : array [0..0] of longint;
    
begin

    if (not isConnected) and (not netsync) then exit;

    buf[0]:= value;

    sendTCP(IDButtonDOWNOctave, buf);

end;


procedure TTracker.netSendChangeRow(value: longint);
var 
    buf : array [0..0] of longint;

begin
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= value;

    sendTCP(IDChangeRow, buf);

end;









procedure TTracker.netSendButtonCopyBlock;
begin
{
    if (not isConnected) or (not netsync) then exit;

    netBuf[0]:= IDButtonCopyBlock;

    sendTCP;
}
end;


procedure TTracker.netSendButtonPasteBlock;  
begin
{
    if (not isConnected) or (not netsync) then exit;

    netBuf[0]:= IDButtonPasteBlock;

    sendTCP;
}
end;


procedure TTracker.netSendButtonSelectTrackBlock;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) or (not netsync) then exit;

    buf[0]:=0;
    
    sendTCP(IDButtonSelectTrackBlock, buf);

end; 





















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



















procedure TTracker.netGetCurrentChannel;
var 
    buf : array [0..2] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tracker.currentChannel:= buf[0];                
    tracker.mainScrollBar.setcurValue(buf[1]);


    tracker.drawCursorChannel:= tracker.currentChannel - (tracker.mainScrollBar.curValue div 64);
    if tracker.drawCursorChannel < 1 then tracker.drawCursorChannel:= 1;
    if tracker.drawCursorChannel > 11 then tracker.drawCursorChannel:= 11;

end;


procedure TTracker.netGetCurrentCursorPos;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    case buf[0] of
        1 : Tracker.currentChannelMode:= cursorMode.note;
        2 : Tracker.currentChannelMode:= cursorMode.instrument1;
        3 : Tracker.currentChannelMode:= cursorMode.instrument2;
        4 : Tracker.currentChannelMode:= cursorMode.volume1;
        5 : Tracker.currentChannelMode:= cursorMode.volume2;
        6 : Tracker.currentChannelMode:= cursorMode.effect1;
        7 : Tracker.currentChannelMode:= cursorMode.effect2;
        8 : Tracker.currentChannelMode:= cursorMode.effect3;
    end;

end;


procedure TTracker.netGetTrackerMainScrollbar;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tracker.mainScrollBar.setCurValue(buf[0]);

end;

procedure TTracker.netGetCurrentEditMode;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tracker.trackerInEditMode:= boolean(buf[0]);

end;


procedure TTracker.netGetSetNote;
var
    note : TNote;
    buf : array [0..10] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        note.note:= buf[3];
        note.Instrument:=  buf[4];
        longint(note.volume.EffectType):= buf[5];
        note.volume.EffectParam:= buf[6];
        longint(note.panning.EffectType):= buf[7];
        note.panning.EffectParam:= buf[8];
        longint(note.EffectType):= buf[9];
        note.EffectParam:= buf[10];

        Module.Patterns[buf[0]][buf[1],buf[2]]:= note;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.netGetPlayNote;
var
    buf : array [0..2] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if (CurrentMode = modeTracker) and assigned(tracker) then begin

        if buf[2] = PlayNote then begin
            currentInstrument:= buf[1];
            Tracker.PianoPlaySample(buf[0], NETKeyboard);
            Tracker.printKeyStroke;
        end;
        if buf[2] = StopNote then begin
            currentInstrument:= buf[1];
            Tracker.PianoStopSample(buf[0], NETKeyboard);
            Tracker.printKeyStroke;
        end;

    end;

end;


procedure TTracker.netGetButtonPlaySong;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
	
	if netsync then ButtonPlaySong.blink;

    doPlaySong;

end;


procedure TTracker.netGetButtonPlayPattern;
var 
    buf : array [0..0] of longint;

begin
    
    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonPlayPattern.blink;

    doPlayPattern;

end;


procedure TTracker.netGetButtonStopSong;
var 
    buf : array [0..0] of longint;

begin
        
    fprecv(socketTCP, @buf, sizeof(buf), 0);

	if netsync then ButtonStop.blink;

    doStopSong;

end;


procedure TTracker.netGetButtonRecordSong;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonRecordSong.blink;

    doRecordSong;
    
end;


procedure TTracker.netGetButtonRecordPattern;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
    
    if netsync then ButtonRecordPattern.blink;

    doRecordPattern;

end;


procedure TTracker.netGetButtonTranspose;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonTranspose.blink;

    doButtonTranspose;

end;


procedure TTracker.netGetButtonAdvancedEdit;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAdvancedEdit.blink;

    doButtonAdvancedEdit;

end;


procedure TTracker.netGetButtonCurrentInstrumentTrackUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentTrackUP.blink;

    doButtonCurrentInstrumentTrackUP;

end;


procedure TTracker.netGetButtonCurrentInstrumentTrackDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

	if netsync then ButtonCurrentInstrumentTrackDown.blink;

    doButtonCurrentInstrumentTrackDown;

end;


procedure TTracker.netGetButtonCurrentInstrumentTrack12UP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
	
	if netsync then ButtonCurrentInstrumentTrack12UP.blink;

	doButtonCurrentInstrumentTrack12UP;

end;


procedure TTracker.netGetButtonCurrentInstrumentTrack12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentTrack12Down.blink;

    doButtonCurrentInstrumentTrack12Down;

end;


procedure TTracker.netGetButtonAllInstrumentsTrackUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsTrackUP.blink;

    doButtonAllInstrumentsTrackUP;

end;


procedure TTracker.netGetButtonAllInstrumentsTrackDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsTrackDown.blink;
    
    doButtonAllInstrumentsTrackDown;

end;


procedure TTracker.netGetButtonAllInstrumentsTrack12UP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsTrack12UP.blink;

    doButtonAllInstrumentsTrack12UP;

end;


procedure TTracker.netGetButtonAllInstrumentsTrack12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsTrack12Down.blink;

    doButtonAllInstrumentsTrack12Down;

end;



procedure TTracker.netGetButtonCurrentInstrumentPatternUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentPatternUP.blink;

    doButtonCurrentInstrumentPatternUP;

end;


procedure TTracker.netGetButtonCurrentInstrumentPatternDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentPatternDown.blink;

    doButtonCurrentInstrumentPatternDown;

end;



procedure TTracker.netGetButtonCurrentInstrumentPattern12UP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentPattern12UP.blink;

    doButtonCurrentInstrumentPattern12UP;

end;


procedure TTracker.netGetButtonCurrentInstrumentPattern12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentPattern12Down.blink;

    doButtonCurrentInstrumentPattern12Down;

end;


procedure TTracker.netGetButtonAllInstrumentsPatternUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsPatternUP.blink;

    doButtonAllInstrumentsPatternUP;

end;


procedure TTracker.netGetButtonAllInstrumentsPatternDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsPatternDown.blink;

    doButtonAllInstrumentsPatternDown;

end;


procedure TTracker.netGetButtonAllInstrumentsPattern12Up;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsPattern12Up.blink;

    doButtonAllInstrumentsPattern12UP;

end;


procedure TTracker.netGetButtonAllInstrumentsPattern12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsPattern12Down.blink;

    doButtonAllInstrumentsPattern12Down;

end;


procedure TTracker.netGetButtonCurrentInstrumentSongUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentSongUP.blink;

    doButtonCurrentInstrumentSongUP;

end;


procedure TTracker.netGetButtonCurrentInstrumentSongDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentSongDown.blink;

    doButtonCurrentInstrumentSongDown;

end;


procedure TTracker.netGetButtonCurrentInstrumentSong12Up;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentSong12Up.blink;

    doButtonCurrentInstrumentSong12UP;

end;


procedure TTracker.netGetButtonCurrentInstrumentSong12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentSong12Down.blink;

    doButtonCurrentInstrumentSong12Down;

end;


procedure TTracker.netGetButtonAllInstrumentsSongUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsSongUP.blink;

    doButtonAllInstrumentsSongUP;

end;


procedure TTracker.netGetButtonAllInstrumentsSongDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsSongDown.blink;

    doButtonAllInstrumentsSongDown;

end;


procedure TTracker.netGetButtonAllInstrumentsSong12Up;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsSong12Up.blink;

    doButtonAllInstrumentsSong12UP;

end;


procedure TTracker.netGetButtonAllInstrumentsSong12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsSong12Down.blink;

    doButtonAllInstrumentsSong12Down;

end;


procedure TTracker.netGetButtonCurrentInstrumentBlockUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentBlockUP.blink;

    doButtonCurrentInstrumentBlockUP;

end;


procedure TTracker.netGetButtonCurrentInstrumentBlockDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentBlockDown.blink;

	doButtonCurrentInstrumentBlockDown;
end;


procedure TTracker.netGetButtonCurrentInstrumentBlock12Up;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentBlock12Up.blink;

    doButtonCurrentInstrumentBlock12UP;

end;


procedure TTracker.netGetButtonCurrentInstrumentBlock12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonCurrentInstrumentBlock12Down.blink;

    doButtonCurrentInstrumentBlock12Down;

end;


procedure TTracker.netGetButtonAllInstrumentsBlockUP;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsBlockUP.blink;

    doButtonAllInstrumentsBlockUP;

end;


procedure TTracker.netGetButtonAllInstrumentsBlockDown;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsBlockDown.blink;

    doButtonAllInstrumentsBlockDown;

end;


procedure TTracker.netGetButtonAllInstrumentsBlock12Up;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsBlock12Up.blink;

    doButtonAllInstrumentsBlock12UP;

end;


procedure TTracker.netGetButtonAllInstrumentsBlock12Down;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonAllInstrumentsBlock12Down.blink;

    doButtonAllInstrumentsBlock12Down;

end;


procedure TTracker.netGetButtonRemapInstrumentTrack;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonRemapInstrumentTrack.blink;

end;


procedure TTracker.netGetButtonRemapInstrumentPattern;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonRemapInstrumentPattern.blink;

end;


procedure TTracker.netGetButtonRemapInstrumentSong;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonRemapInstrumentSong.blink;

end;


procedure TTracker.netGetButtonRemapInstrumentBlock;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonRemapInstrumentBlock.blink;

end;


procedure TTracker.netGetButtonShrink;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonShrink.blink;

end;


procedure TTracker.netGetButtonExpand;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    if netsync then ButtonExpand.blink;

end;


procedure TTracker.netGetButtonUPRepeatStart;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.Order.RestartPosition:= buf[0];

        Tracker.TextFieldRepeatStart.caption:= 'Repeat Start  ' + numstr(Module.Order.RestartPosition);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonUPRepeatStart.blink;

end;


procedure TTracker.netGetButtonDOWNRepeatStart;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.Order.RestartPosition:= buf[0];

        Tracker.TextFieldRepeatStart.caption:= 'Repeat Start  ' + numstr(Module.Order.RestartPosition);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonDOWNRepeatStart.blink;

end;


procedure TTracker.netGetButtonUPBPM;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.InitialBPM:= buf[0];

        Tracker.TextFieldBPM.caption:= 'BPM  ' + numstr(Module.InitialBPM);       

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonUPBPM.blink;

end;


procedure TTracker.netGetButtonDOWNBPM;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.InitialBPM:= buf[0];

        Tracker.TextFieldBPM.caption:= 'BPM  ' + numstr(Module.InitialBPM);       

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonDOWNBPM.blink;

end;


procedure TTracker.netGetButtonUPSpeed;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.InitialSpeed:= buf[0];

        Tracker.TextFieldSpeed.caption:= 'Speed  ' + numstr(Module.InitialSpeed);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonUPSpeed.blink;

end;


procedure TTracker.netGetButtonDOWNSpeed;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.InitialSpeed:= buf[0];

        Tracker.TextFieldSpeed.caption:= 'Speed  ' + numstr(Module.InitialSpeed);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonDOWNSpeed.blink;

end;


procedure TTracker.netGetButtonUPLength;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.Patterns[CurrentPattern].RowsCount:= buf[0];

       Tracker.TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonUPPatternLength.blink;

end;


procedure TTracker.netGetButtonDOWNLength;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.Patterns[CurrentPattern].RowsCount:= buf[0];

       Tracker.TextFieldPatternLength.caption:= 'Pattern Length  ' + numstr(Module.Patterns[CurrentPattern].RowsCount);

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonDOWNPatternLength.blink;

end;


procedure TTracker.netGetButtonUPChannels;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.NumberOfChannels:= buf[0];

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonUPSongChannels.blink;
    
    Tracker.reload(false);

end;


procedure TTracker.netGetButtonDOWNChannels;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tralalaEngine.Lock_Module_ReadWrite(Module);

        Module.NumberOfChannels:= buf[0];

    tralalaEngine.Unlock_Module_ReadWrite;

    if netsync then Tracker.ButtonDOWNSongChannels.blink;

    Tracker.reload(false);

end;


procedure TTracker.netGetButtonUPAdd;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    
    Tracker.CurrentNoteAdd:= buf[0];
    Tracker.TextFieldNoteAdd.caption:='Note Add  ' + numstr(Tracker.CurrentNoteAdd);

    if netsync then Tracker.ButtonUPNoteAdd.blink;

end;


procedure TTracker.netGetButtonDOWNAdd;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    
    Tracker.CurrentNoteAdd:= buf[0];
    Tracker.TextFieldNoteAdd.caption:='Note Add  ' + numstr(Tracker.CurrentNoteAdd);

    if netsync then Tracker.ButtonDOWNNoteAdd.blink;

end;


procedure TTracker.netGetButtonUPOctave;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    
    CurrentOctave:= buf[0];
    Tracker.TextFieldOctave.caption:='Octave  ' + numstr(CurrentOctave);

    if netsync then Tracker.ButtonUPOctave.blink;

end;


procedure TTracker.netGetButtonDOWNOctave;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    
    CurrentOctave:= buf[0];
    Tracker.TextFieldOctave.caption:='Octave  ' + numstr(CurrentOctave);

    if netsync then Tracker.ButtonDOWNOctave.blink;

end;


procedure TTracker.netGetChangeRow;
var 
    buf : array [0..0] of longint;
    
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    
    Tracker.currentRow:= buf[0];

end;















procedure TTracker.netGetButtonCopyBlock;
begin
{
    if buf[0] = IDButtonCopyBlock then begin
    end;
}
end;


procedure TTracker.netGetButtonPasteBlock;
begin
{
    if buf[0] = IDButtonPasteBlock then begin
    end;
}
end;


procedure TTracker.netGetButtonSelectTrackBlock;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

end;




