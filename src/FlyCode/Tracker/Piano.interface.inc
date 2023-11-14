
function VirtualPianoGetNoteFromKeyboardPress: longint;
function VirtualPianoGetNoteFromKeyboard(key: longint): longint;

procedure VirtualPianoPlaySampleFromKeyboard;
function VirtualPianogetKeyFromSample(smp: longint): longint;

 
const
	MIDIKeyDown : longint = 144;
	MIDIKeyUp : longint = 128;

var
	MIDICommand : longint;
	MIDINote : longint;
	MIDIPlaying : boolean;
	MIDIKeyPressed : boolean;

procedure MIDIKeypress(command, param1, param2: longint);

procedure PianoPlaySample(key: longint; who: TwhoPalys);
procedure PianoStopSample(key: longint; who: TwhoPalys);
procedure PianoStopAllSamples;