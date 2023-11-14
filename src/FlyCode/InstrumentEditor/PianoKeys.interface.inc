var
	
	pianoKeysBox : TtuiBox;
	pianoImage : gfxImage;
	pianoSelectableImage : TtuiSelectableImage;
	allowPianoKeys : boolean;


const
	pianokeysY = 633;
	pianokeyWhiteWidth = 20;
	pianokeyBlackWidth = 15;
	pianokeyWhiteLineHeight = 20;

procedure BuildPianoKeys;

procedure DrawPianoBlackKeys;
procedure DrawPianoWhiteKeys;

procedure DrawPianoWhiteKey(x: longint);
procedure DrawPianoPressedWhiteKey(x: longint);

procedure DrawPianoBlackKey(x: longint);
procedure DrawPianoPressedBlackKey(x: longint);


function isPianoWhiteKeyMouseOver: longint;
function isPianoBlackKeyMouseOver: longint;



procedure updatePianoPressedBlackKeys(key: longint);
procedure updatePianoWhiteKeys;
procedure updatePianoBlackKeys;

function ConvertNote2WhitePianoKeyboard(note: longint): longint;
function ConvertNote2BlackPianoKeyboard(note: longint): longint;

var
	playing : boolean;
	oldPlayedKey : longint;

procedure playSample;
procedure playNote(n: longint);


function convertWhiteKey2noteNumber(key: longint): longint;
function convertBlackKey2noteNumber(key: longint): longint;

function GetPianoKeyFromKeyboard: longint;
function ConvertNote2PianoKeyboard(note: longint): longint;

function VirtualPianoGetNoteFromKeyboard: longint;
