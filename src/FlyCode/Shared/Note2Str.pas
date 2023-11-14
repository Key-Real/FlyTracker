{$MODE OBJFPC}
unit Note2Str;
interface
uses tools,math,TralalaPlayer;

function NoteValueTo3Str(ANote: TNoteValue): string;
function LeadingZeros(Q, Z: Integer): string;
function Instrument2String(AInstrument: Integer): string;
function Volume2String(const AVolume: TVolumeColumnEffect): string;
function Effect2Char(AEffectType: TEffectType): Char;
function Effect2Str(AEffectType: TEffectType; AEffectParam: Integer): string;
function Char2Effect(ch:char): TEffectType;

implementation

function NoteValueTo3Str(ANote: TNoteValue): string;
const
  NoteStr: array[0..11] of string =
    ('C-', 'C#', 'D-', 'D#', 'E-', 'F-', 'F#', 'G-', 'G#', 'A-', 'A#', 'B-');
begin
  if InRange(ANote, NoteMin, NoteMax) then
    Result := NoteStr[ANote mod 12] + numstr(ANote div 12)
  else
    if ANote = NoteCut then
      Result := 'cut'
    else
      if ANote = NoteOff then
        Result := 'off'
      else
        if ANote = NoteNothing then
          Result := #173#173#173
        else
          Result := '???';
end;


function LeadingZeros(Q, Z: Integer): string;
var
  Res : string;

begin

  if Q >= 0 then begin
    Str(Q, Res);

    while Length(Res) < Z do Res:= '0' + Res;

    LeadingZeros:= Res;

  end else begin

    Str(-Q, Res);

    while Length(Res) < (Z - 1) do 
      Res := '0' + Res;

    LeadingZeros := '-' + Res;

  end;

end;


function Instrument2String(AInstrument: Integer): string;
begin
  if AInstrument = 0 then
    Result:= #173#173
  else
    Result:= LeadingZeros(AInstrument, 2);
end;


function Volume2String(const AVolume: TVolumeColumnEffect): string;
begin
  case AVolume.EffectType of
    vcetNoEffect:            Result:= #173#173;
    vcetSetVolumeTo:         Result:= LeadingZeros(AVolume.EffectParam, 2);
    vcetFineVolumeSlideUp:   Result:= 'A' + HexStr(AVolume.EffectParam, 1);
    vcetFineVolumeSlideDown: Result:= 'B' + HexStr(AVolume.EffectParam, 1);
    vcetVolumeSlideUp:       Result:= '+' + HexStr(AVolume.EffectParam, 1);
    vcetVolumeSlideDown:     Result:= '-' + HexStr(AVolume.EffectParam, 1);
    vcetPitchSlideDown:      Result:= 'E' + HexStr(AVolume.EffectParam, 1);
    vcetPitchSlideUp:        Result:= 'F' + HexStr(AVolume.EffectParam, 1);
    vcetPortamentoToNoteIT:  Result:= 'G' + HexStr(AVolume.EffectParam, 1);
    vcetPortamentoToNoteFT2: Result:= 'g' + HexStr(AVolume.EffectParam, 1);
    vcetVibrato:             Result:= 'H' + HexStr(AVolume.EffectParam, 1);
    vcetSetVibratoSpeed:     Result:= '$' + HexStr(AVolume.EffectParam, 1);
  end;
end;


function Effect2Char(AEffectType: TEffectType): Char;
begin
  case AEffectType of
    etNoEffect:                   Result:= '0';
    etSetSpeed:                   Result:= 'A';
    etJumpToOrder:                Result:= 'B';
    etBreakToRow:                 Result:= 'C';
    etVolumeSlide:                Result:= 'D';
    etPitchSlideDown:             Result:= 'E';
    etPitchSlideUp:               Result:= 'F';
    etPortamentoToNote:           Result:= 'G';
    etVibrato:                    Result:= 'H';
    etTremor:                     Result:= 'I';
    etArpeggio:                   Result:= 'J';
    etVibratoAndVolumeSlide:      Result:= 'K';
    etPortamentoToAndVolumeSlide: Result:= 'L';
    etSetChannelVolume:           Result:= 'M';
    etSlideChannelVolume:         Result:= 'N';
    etSetSampleOffset:            Result:= 'O';
    etSlidePanning:               Result:= 'P';
    etRetrig:                     Result:= 'Q';
    etTremolo:                    Result:= 'R';
    etSpecialCommand:             Result:= 'S';
    etSetTempo:                   Result:= 'T';
    etFineVibrato:                Result:= 'U';
    etSetGlobalVolume:            Result:= 'V';
    etSlideGlobalVolume:          Result:= 'W';
    etSetPanningPosition:         Result:= 'X';
    etPanbrello:                  Result:= 'Y';
    etMIDIMacros:                 Result:= 'Z';
    etSetVolume:                  Result:= '!';
    etSetEnvelopePosition:        Result:= '&';
    etNOP:                        Result:= ' ';
  end;
end;


function Char2Effect(ch: char): TEffectType;
begin
  case ch of  
    '0' : result:= etNoEffect;
    'A' : result:= etSetSpeed;
    'B' : result:= etJumpToOrder;
    'C' : result:= etBreakToRow;
    'D' : result:= etVolumeSlide;
    'E' : result:= etPitchSlideDown;
    'F' : result:= etPitchSlideUp;
    'G' : result:= etPortamentoToNote;
    'H' : result:= etVibrato;
    'I' : result:= etTremor;
    'J' : result:= etArpeggio;
    'K' : result:= etVibratoAndVolumeSlide;
    'L' : result:= etPortamentoToAndVolumeSlide;
    'M' : result:= etSetChannelVolume;
    'N' : result:= etSlideChannelVolume;
    'O' : result:= etSetSampleOffset;
    'P' : result:= etSlidePanning;
    'Q' : result:= etRetrig;
    'R' : result:= etTremolo;
    'S' : result:= etSpecialCommand;
    'T' : result:= etSetTempo;
    'U' : result:= etFineVibrato;
    'V' : result:= etSetGlobalVolume;
    'W' : result:= etSlideGlobalVolume;
    'X' : result:= etSetPanningPosition;
    'Y' : result:= etPanbrello;
    'Z' : result:= etMIDIMacros;
    '!' : result:= etSetVolume;
    '&' : result:= etSetEnvelopePosition;
    ' ' : result:= etNOP;
  end;
end;



function Effect2Str(AEffectType: TEffectType; AEffectParam: Integer): string;
begin
  Result:= Effect2Char(AEffectType) + HexStr(AEffectParam, 2);
end;


begin
end.