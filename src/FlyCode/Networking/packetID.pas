{$MODE OBJFPC} 
unit packetID;
interface

type
    NetID = (IDNone,
             IDMouseButtons, IDMouseWheel, 
             IDChangeRow, IDCurrentChannel, IDCurrentCursor,
             IDTrackerMainScrollBar, IDCurrentEditMode, IDCurrentOrder,
             IDSetNote, IDPlayNote,
             IDButtonPlaySong, IDButtonPlayPattern, IDButtonStopSong, IDButtonRecordSong, IDButtonRecordPattern,
             IDButtonTranspose, IDButtonAdvancedEdit,
             IDButtonCurrentInstrumentTrackUP, IDButtonCurrentInstrumentTrackDown, IDButtonCurrentInstrumentTrack12UP, IDButtonCurrentInstrumentTrack12Down, IDButtonAllInstrumentsTrackUP, IDButtonAllInstrumentsTrackDown, IDButtonAllInstrumentsTrack12Up, IDButtonAllInstrumentsTrack12Down, IDButtonCurrentInstrumentPatternUP, IDButtonCurrentInstrumentPatternDown, IDButtonCurrentInstrumentPattern12Up, IDButtonCurrentInstrumentPattern12Down, IDButtonAllInstrumentsPatternUP, IDButtonAllInstrumentsPatternDown, IDButtonAllInstrumentsPattern12Up, IDButtonAllInstrumentsPattern12Down, IDButtonCurrentInstrumentSongUP, IDButtonCurrentInstrumentSongDown, IDButtonCurrentInstrumentSong12Up, IDButtonCurrentInstrumentSong12Down, IDButtonAllInstrumentsSongUP, IDButtonAllInstrumentsSongDown, IDButtonAllInstrumentsSong12Up,  IDButtonAllInstrumentsSong12Down, IDButtonCurrentInstrumentBlockUP, IDButtonCurrentInstrumentBlockDown, IDButtonCurrentInstrumentBlock12Up, IDButtonCurrentInstrumentBlock12Down, IDButtonAllInstrumentsBlockUP, IDButtonAllInstrumentsBlockDown, IDButtonAllInstrumentsBlock12Up, IDButtonAllInstrumentsBlock12Down,
             IDButtonRemapInstrumentTrack, IDButtonRemapInstrumentPattern, IDButtonRemapInstrumentSong, IDButtonRemapInstrumentBlock,
             IDButtonShrink, IDButtonExpand,
             IDButtonUPRepeatStart, IDButtonDOWNRepeatStart, IDButtonUPBPM, IDButtonDOWNBPM, IDButtonUPSpeed, IDButtonDOWNSpeed, IDButtonUPLength, IDButtonDOWNLength, IDButtonUPChannels, IDButtonDOWNChannels, IDButtonUPAdd, IDButtonDOWNAdd, IDButtonUPOctave, IDButtonDOWNOctave,
             IDButtonCopyBlock, IDButtonPasteBlock, IDButtonSelectTrackBlock, 
             IDNetSyncStatus,
             IDRadioButtonLoopTypeNoLoop, IDRadioButtonLoopTypeForwardLoop, IDRadioButtonLoopTypePingPongLoop, IDRadioButtonSampleBits8, IDRadioButtonSampleBits16, IDRadioButtonSampleMono, IDRadioButtonSampleStereo, IDRadioButtonWaveStyle1, IDRadioButtonWaveStyle2, IDRadioButtonWaveStyle3, IDRadioButtonWaveStyle4, IDRadioButtonWaveStyle5, IDRadioButtonLoopNormal, IDRadioButtonLoopSustain,
             IDButtonUPLoopStart, IDButtonDOWNLoopStart, IDButtonUPLoopEnd, IDButtonDOWNLoopEnd, IDButtonUPSustainLoopStart, IDButtonDOWNSustainLoopStart, IDButtonUPSustainLoopEnd, IDButtonDOWNSustainLoopEnd,
             IDButtonStopWave, IDButtonPlayWave, IDButtonWaveRange, IDButtonWaveDisplay, IDButtonWaveVolume, IDButtonXFade,
             IDButtonCut, IDButtonCopy, IDButtonPaste,
             IDButtonShowSelectedWave, IDButtonZoomOutWave, IDButtonRangeAllWave, IDButtonShowAllWave, IDButtonCrop,
             IDButtonVolume, IDButtonPanning, IDButtonPitch, IDButtonMapping,
             IDVolumeEnvelopeToucher, IDVolumeEnvelopeTouchedNode);


procedure executePacket;


implementation
uses networking, connection, 
     theTracker, theInstrumentEditor;


procedure executePacket;
begin

    case NetID(IDbuf[0]) of
        IDMouseButtons : netGetMouseButtons;
        IDMouseWheel : netGetMouseWheel;

        IDCurrentChannel : Tracker.netGetCurrentChannel;
        IDCurrentCursor : Tracker.netGetCurrentCursorPos;
        IDTrackerMainScrollbar : Tracker.netGetTrackerMainScrollbar;
        IDCurrentEditMode : Tracker.netGetCurrentEditMode;

        IDCurrentOrder : netGetCurrentOrder;

        IDSetNote : Tracker.netGetSetNote;
        IDPlayNote : Tracker.netGetPlayNote;

        IDButtonPlaySong : Tracker.netGetButtonPlaySong;
        IDButtonPlayPattern : Tracker.netGetButtonPlaypattern;
        IDButtonStopSong : Tracker.netGetButtonStopSong;
        IDButtonRecordSong : Tracker.netGetButtonRecordSong;
        IDButtonRecordPattern : Tracker.netGetButtonRecordPattern;

        IDButtonTranspose : Tracker.netGetButtonTranspose;
        IDButtonAdvancedEdit : Tracker.netGetButtonAdvancedEdit;

        IDButtonCurrentInstrumentTrackUP : Tracker.netGetButtonCurrentInstrumentTrackUP;
        IDButtonCurrentInstrumentTrackDown : Tracker.netGetButtonCurrentInstrumentTrackDown;
        IDButtonCurrentInstrumentTrack12UP : Tracker.netGetButtonCurrentInstrumentTrack12UP;
        IDButtonCurrentInstrumentTrack12Down : Tracker.netGetButtonCurrentInstrumentTrack12Down;
        IDButtonAllInstrumentsTrackUP : Tracker.netGetButtonAllInstrumentsTrackUP;
        IDButtonAllInstrumentsTrackDown : Tracker.netGetButtonAllInstrumentsTrackDown;
        IDButtonAllInstrumentsTrack12UP : Tracker.netGetButtonAllInstrumentsTrack12UP;
        IDButtonAllInstrumentsTrack12Down : Tracker.netGetButtonAllInstrumentsTrack12Down;
        IDButtonCurrentInstrumentPatternUP : Tracker.netGetButtonCurrentInstrumentPatternUP;
        IDButtonCurrentInstrumentPatternDown : Tracker.netGetButtonCurrentInstrumentPatternDown;
        IDButtonCurrentInstrumentPattern12Up : Tracker.netGetButtonCurrentInstrumentPattern12Up;
        IDButtonCurrentInstrumentPattern12Down : Tracker.netGetButtonCurrentInstrumentPattern12Down;
        IDButtonAllInstrumentsPatternUP : Tracker.netGetButtonAllInstrumentsPatternUP;
        IDButtonAllInstrumentsPatternDown : Tracker.netGetButtonAllInstrumentsPatternDown;
        IDButtonAllInstrumentsPattern12Up : Tracker.netGetButtonAllInstrumentsPattern12Up;
        IDButtonAllInstrumentsPattern12Down : Tracker.netGetButtonAllInstrumentsPattern12Down;
        IDButtonCurrentInstrumentSongUP : Tracker.netGetButtonCurrentInstrumentSongUP;
        IDButtonCurrentInstrumentSongDown : Tracker.netGetButtonCurrentInstrumentSongDown;
        IDButtonCurrentInstrumentSong12Up : Tracker.netGetButtonCurrentInstrumentSong12Up;
        IDButtonCurrentInstrumentSong12Down : Tracker.netGetButtonCurrentInstrumentSong12Down;
        IDButtonAllInstrumentsSongUP : Tracker.netGetButtonAllInstrumentsSongUP;
        IDButtonAllInstrumentsSongDown : Tracker.netGetButtonAllInstrumentsSongDown;
        IDButtonAllInstrumentsSong12Up : Tracker.netGetButtonAllInstrumentsSong12Up;
        IDButtonAllInstrumentsSong12Down : Tracker.netGetButtonAllInstrumentsSong12Down;
        IDButtonCurrentInstrumentBlockUP : Tracker.netGetButtonCurrentInstrumentBlockUP;
        IDButtonCurrentInstrumentBlockDown : Tracker.netGetButtonCurrentInstrumentBlockDown;
        IDButtonCurrentInstrumentBlock12Up : Tracker.netGetButtonCurrentInstrumentBlock12Up;
        IDButtonCurrentInstrumentBlock12Down : Tracker.netGetButtonCurrentInstrumentBlock12Down;
        IDButtonAllInstrumentsBlockUP : Tracker.netGetButtonAllInstrumentsBlockUP;
        IDButtonAllInstrumentsBlockDown : Tracker.netGetButtonAllInstrumentsBlockDown;
        IDButtonAllInstrumentsBlock12Up : Tracker.netGetButtonAllInstrumentsBlock12Up;
        IDButtonAllInstrumentsBlock12Down : Tracker.netGetButtonAllInstrumentsBlock12Down;

        IDButtonRemapInstrumentTrack : Tracker.netGetButtonRemapInstrumentTrack;
        IDButtonRemapInstrumentPattern : Tracker.netGetButtonRemapInstrumentPattern;
        IDButtonRemapInstrumentSong : Tracker.netGetButtonRemapInstrumentSong;
        IDButtonRemapInstrumentBlock : Tracker.netGetButtonRemapInstrumentBlock;

        IDButtonShrink : Tracker.netGetButtonShrink;
        IDButtonExpand : Tracker.netGetButtonExpand;

        IDButtonUPRepeatStart : Tracker.netGetButtonUPRepeatStart;
        IDButtonDOWNRepeatStart : Tracker.netGetButtonDOWNRepeatStart;
        IDButtonUPBPM : Tracker.netGetButtonUPBPM;
        IDButtonDOWNBPM : Tracker.netGetButtonDOWNBPM;
        IDButtonUPSpeed : Tracker.netGetButtonUPSpeed;
        IDButtonDOWNSpeed : Tracker.netGetButtonDOWNSpeed;
        IDButtonUPLength : Tracker.netGetButtonUPLength;
        IDButtonDOWNLength : Tracker.netGetButtonDOWNLength;
        IDButtonUPChannels : Tracker.netGetButtonUPChannels;
        IDButtonDOWNChannels : Tracker.netGetButtonDOWNChannels;
        IDButtonUPAdd : Tracker.netGetButtonUPAdd;
        IDButtonDOWNAdd : Tracker.netGetButtonDOWNAdd;
        IDButtonUPOctave : Tracker.netGetButtonUPOctave;
        IDButtonDOWNOctave : Tracker.netGetButtonDOWNOctave;

        IDButtonCopyBlock : Tracker.netGetButtonCopyBlock;
        IDButtonPasteBlock : Tracker.netGetButtonPasteBlock;
        IDButtonSelectTrackBlock : Tracker.netGetButtonSelectTrackBlock;

        IDChangeRow : Tracker.netGetChangeRow;


        IDNetSyncStatus : netGetNetSyncStatus;


        IDRadioButtonLoopTypeNoLoop : InstrumentEditor.netGetRadioButtonLoopTypeNoLoop;
        IDRadioButtonLoopTypeForwardLoop : InstrumentEditor.netGetRadioButtonLoopTypeForwardLoop;
        IDRadioButtonLoopTypePingPongLoop : InstrumentEditor.netGetRadioButtonLoopTypePingPongLoop;

        IDRadioButtonSampleBits8 : InstrumentEditor.netGetRadioButtonSampleBits8;
        IDRadioButtonSampleBits16 : InstrumentEditor.netGetRadioButtonSampleBits16;
        IDRadioButtonSampleMono : InstrumentEditor.netGetRadioButtonSampleMono;
        IDRadioButtonSampleStereo : InstrumentEditor.netGetRadioButtonSampleStereo;

        IDRadioButtonWaveStyle1 : InstrumentEditor.netGetRadioButtonWaveStyle1;  
        IDRadioButtonWaveStyle2 : InstrumentEditor.netGetRadioButtonWaveStyle2;  
        IDRadioButtonWaveStyle3 : InstrumentEditor.netGetRadioButtonWaveStyle3;  
        IDRadioButtonWaveStyle4 : InstrumentEditor.netGetRadioButtonWaveStyle4;  
        IDRadioButtonWaveStyle5 : InstrumentEditor.netGetRadioButtonWaveStyle5;

        IDRadioButtonLoopNormal : InstrumentEditor.netGetRadioButtonLoopNormal;
        IDRadioButtonLoopSustain : InstrumentEditor.netGetRadioButtonLoopSustain;

        IDButtonUPLoopStart : InstrumentEditor.netGetButtonUPLoopStart;
        IDButtonDOWNLoopStart : InstrumentEditor.netGetButtonDOWNLoopStart;
        IDButtonUPLoopEnd : InstrumentEditor.netGetButtonUPLoopEnd;
        IDButtonDOWNLoopEnd : InstrumentEditor.netGetButtonDOWNLoopEnd;

        IDButtonUPSustainLoopStart : InstrumentEditor.netGetButtonUPSustainLoopStart;
        IDButtonDOWNSustainLoopStart : InstrumentEditor.netGetButtonDOWNSustainLoopStart;
        IDButtonUPSustainLoopEnd : InstrumentEditor.netGetButtonUPSustainLoopEnd;
        IDButtonDOWNSustainLoopEnd : InstrumentEditor.netGetButtonDOWNSustainLoopEnd;

        IDButtonStopWave : InstrumentEditor.netGetButtonStopWave;
        IDButtonPlayWave : InstrumentEditor.netGetButtonPlayWave;
        IDButtonWaveRange : InstrumentEditor.netGetButtonWaveRange;
        IDButtonWaveDisplay : InstrumentEditor.netGetButtonWaveDisplay;
        IDButtonWaveVolume : InstrumentEditor.netGetButtonWaveVolume;
        IDButtonXFade : InstrumentEditor.netGetButtonXFade;

        IDButtonCut : InstrumentEditor.netGetButtonCut;
        IDButtonCopy : InstrumentEditor.netGetButtonCopy;
        IDButtonPaste : InstrumentEditor.netGetButtonPaste;

        IDButtonShowSelectedWave : InstrumentEditor.netGetButtonShowSelectedWave;
        IDButtonZoomOutWave : InstrumentEditor.netGetButtonZoomOutWave;
        IDButtonRangeAllWave : InstrumentEditor.netGetButtonRangeAllWave;
        IDButtonShowAllWave : InstrumentEditor.netGetButtonShowAllWave;
        IDButtonCrop : InstrumentEditor.netGetButtonCrop;

        IDButtonVolume : InstrumentEditor.netGetButtonVolume;
        IDButtonPanning : InstrumentEditor.netGetButtonPanning;
        IDButtonPitch : InstrumentEditor.netGetButtonPitch;
        IDButtonMapping : InstrumentEditor.netGetButtonMapping;

        IDVolumeEnvelopeToucher : InstrumentEditor.netGetEnvelopeToucher;
        IDVolumeEnvelopeTouchedNode : InstrumentEditor.netGetEnvelopeTouchedNode;


    else
    end;

end;


begin
end.