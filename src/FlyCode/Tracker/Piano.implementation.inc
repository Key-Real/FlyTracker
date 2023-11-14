
{
	0 = C0
	1 = C#0
	2 = D0
	3 = D#0
	4 = E0
	5 = F0
	6 = F#0
	7 = G0
	8 = G#0
	9 = A0
   10 = A#0
   11 = B0

   12 = C1
   13 = C#1
   14 = D1
   15 = D#1
   16 = E1
   17 = F1
   18 = F#1
   19 = G1
   20 = G#1
   21 = A1
   22 = A#1
   23 = B1

   24 = C2
   25 = C#2
   26 = D2
   27 = D#2
   28 = E2
   29 = F2
   30 = F#2
   31 = G2
   32 = G#2
   33 = A2
   34 = A#2
   35 = B2

   36 = C3
   37 = C#3
   38 = D3
   39 = D#3
   40 = E3
   41 = F3
   42 = F#3
   43 = G3
   44 = G#3
   45 = A3
   46 = A#3
   47 = B3

   48 = C4
   49 = C#4
   50 = D4
   51 = D#4
   52 = E4
   53 = F4
   54 = F#4
   55 = G4
   56 = G#4
   57 = A4
   58 = A#4
   59 = B4

   60 = C5
   61 = C#5
   62 = D5
   63 = D#5
   64 = E5
   65 = F5
   66 = F#5
   67 = G5
   68 = G#5
   69 = A5
   70 = A#5
   71 = B5

   72 = C6
   73 = C#6
   74 = D6
   75 = D#6
   76 = E6
   77 = F6
   78 = F#6
   79 = G6
   80 = G#6
   81 = A6
   82 = A#6
   83 = B6

   84 = C7
   85 = C#7
   86 = D7
   87 = D#7
   88 = E7
   89 = F7
   90 = F#7
   91 = G7
   92 = G#7
   93 = A7
   94 = A#7
   95 = B7

   96 = C8
   97 = C#8
   98 = D8
   99 = D#8
  100 = E8
  101 = F8
  102 = F#8
  103 = G8
  104 = G#8
  105 = A8
  106 = A#8
  107 = B8

  108 = C9
  109 = C#9
  110 = D9
  111 = D#9
  112 = E9
  113 = F9
  114 = F#9
  115 = G9
  116 = G#9
  117 = A9
  118 = A#9
  119 = B9

  124 = NoteFade
  125 = NoteOff

  126 = NoteCut
  127 = NoteNothing
}

function TTracker.VirtualPianoGetNoteFromKeyboardPress: longint;
begin

    result:= -1;
    if keyboard[KEY_Z] then result:= CurrentOctave * 12 + 0;  // C4
    if keyboard[KEY_S] then result:= CurrentOctave * 12 + 1;  // C#4
    if keyboard[KEY_X] then result:= CurrentOctave * 12 + 2;  // D4
    if keyboard[KEY_D] then result:= CurrentOctave * 12 + 3;  // D#4
    if keyboard[KEY_C] then result:= CurrentOctave * 12 + 4;  // E4
    if keyboard[KEY_V] then result:= CurrentOctave * 12 + 5;  // F4
    if keyboard[KEY_G] then result:= CurrentOctave * 12 + 6;  // F#4
    if keyboard[KEY_B] then result:= CurrentOctave * 12 + 7;  // G4
    if keyboard[KEY_H] then result:= CurrentOctave * 12 + 8;  // G#4
    if keyboard[KEY_N] then result:= CurrentOctave * 12 + 9;  // A4
    if keyboard[KEY_J] then result:= CurrentOctave * 12 + 10;  // A#4
    if keyboard[KEY_M] then result:= CurrentOctave * 12 + 11;  // B4

    if keyboard[KEY_Q] then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if keyboard[KEY_OEM_COMMA] then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if keyboard[KEY_2] then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if keyboard[KEY_L] then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if keyboard[KEY_W] then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if keyboard[KEY_OEM_PERIOD] then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if keyboard[KEY_3] then result:= (CurrentOctave + 1) * 12 + 3;  // D#5
    if keyboard[KEY_OEM_3] then result:= (CurrentOctave + 1) * 12 + 3;  // D#5   key = ö
    if keyboard[KEY_E] then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if keyboard[KEY_OEM_MINUS] then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if keyboard[KEY_R] then result:= (CurrentOctave + 1) * 12 + 5;  // F5
    if keyboard[KEY_5] then result:= (CurrentOctave + 1) * 12 + 6;  // F#5
    if keyboard[KEY_OEM_2] then result:= (CurrentOctave + 1) * 12 + 6;  // F#5   key = #
    if keyboard[KEY_T] then result:= (CurrentOctave + 1) * 12 + 7;  // G5
    if keyboard[KEY_6] then result:= (CurrentOctave + 1) * 12 + 8;  // G#5
    if keyboard[KEY_Y] then result:= (CurrentOctave + 1) * 12 + 9;  // A5
    if keyboard[KEY_7] then result:= (CurrentOctave + 1) * 12 + 10;  // A#5
    if keyboard[KEY_U] then result:= (CurrentOctave + 1) * 12 + 11;  // B5

    if keyboard[KEY_I] then result:= (CurrentOctave + 2) * 12 + 0;  // C6
    if keyboard[KEY_9] then result:= (CurrentOctave + 2) * 12 + 1;  // C#6
    if keyboard[KEY_o] then result:= (CurrentOctave + 2) * 12 + 2;  // D6
    if keyboard[KEY_0] then result:= (CurrentOctave + 2) * 12 + 3;  // D#6
    if keyboard[KEY_P] then result:= (CurrentOctave + 2) * 12 + 4;  // E6
    if keyboard[KEY_OEM_1] then result:= (CurrentOctave + 2) * 12 + 5;  // F6   key = ü
    if keyboard[KEY_OEM_6] then result:= (CurrentOctave + 2) * 12 + 6;  // F#6   key = ´
    if keyboard[KEY_OEM_PLUS] then result:= (CurrentOctave + 2) * 12 + 7;  // G6   key = +
    if keyboard[KEY_RETURN] then result:= (CurrentOctave + 2) * 12 + 9;  // A6

    if keyboard[KEY_CAPSLOCK] then result:= 125;  // NoteOff
    if keyboard[KEY_OEM_102] then result:= 126;  // NoteCut   key = <
end;


function TTracker.VirtualPianoGetNoteFromKeyboard(key: longint): longint;
begin

    result:= -1;
    if key = KEY_Z then result:= CurrentOctave * 12 + 0;  // C4
    if key = KEY_S then result:= CurrentOctave * 12 + 1;  // C#4
    if key = KEY_X then result:= CurrentOctave * 12 + 2;  // D4
    if key = KEY_D then result:= CurrentOctave * 12 + 3;  // D#4
    if key = KEY_C then result:= CurrentOctave * 12 + 4;  // E4
    if key = KEY_V then result:= CurrentOctave * 12 + 5;  // F4
    if key = KEY_G then result:= CurrentOctave * 12 + 6;  // F#4
    if key = KEY_B then result:= CurrentOctave * 12 + 7;  // G4
    if key = KEY_H then result:= CurrentOctave * 12 + 8;  // G#4
    if key = KEY_N then result:= CurrentOctave * 12 + 9;  // A4
    if key = KEY_J then result:= CurrentOctave * 12 + 10;  // A#4
    if key = KEY_M then result:= CurrentOctave * 12 + 11;  // B4

    if key = KEY_Q then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if key = KEY_OEM_COMMA then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if key = KEY_2 then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if key = KEY_L then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if key = KEY_W then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if key = KEY_OEM_PERIOD then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if key = KEY_3 then result:= (CurrentOctave + 1) * 12 + 3;  // D#5
    if key = KEY_OEM_3 then result:= (CurrentOctave + 1) * 12 + 3;  // D#5   key = ö
    if key = KEY_E then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if key = KEY_OEM_MINUS then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if key = KEY_R then result:= (CurrentOctave + 1) * 12 + 5;  // F5
    if key = KEY_5 then result:= (CurrentOctave + 1) * 12 + 6;  // F#5
    if key = KEY_OEM_2 then result:= (CurrentOctave + 1) * 12 + 6;  // F#5   key = #
    if key = KEY_T then result:= (CurrentOctave + 1) * 12 + 7;  // G5
    if key = KEY_6 then result:= (CurrentOctave + 1) * 12 + 8;  // G#5
    if key = KEY_Y then result:= (CurrentOctave + 1) * 12 + 9;  // A5
    if key = KEY_7 then result:= (CurrentOctave + 1) * 12 + 10;  // A#5
    if key = KEY_U then result:= (CurrentOctave + 1) * 12 + 11;  // B5

    if key = KEY_I then result:= (CurrentOctave + 2) * 12 + 0;  // C6
    if key = KEY_9 then result:= (CurrentOctave + 2) * 12 + 1;  // C#6
    if key = KEY_O then result:= (CurrentOctave + 2) * 12 + 2;  // D6
    if key = KEY_0 then result:= (CurrentOctave + 2) * 12 + 3;  // D#6
    if key = KEY_P then result:= (CurrentOctave + 2) * 12 + 4;  // E6
    if key = KEY_OEM_1 then result:= (CurrentOctave + 2) * 12 + 5;  // F6   key = ü
    if key = KEY_OEM_6 then result:= (CurrentOctave + 2) * 12 + 6;  // F#6   key = ´
    if key = KEY_OEM_PLUS then result:= (CurrentOctave + 2) * 12 + 7;  // G6   key = +
    if key = KEY_RETURN then result:= (CurrentOctave + 2) * 12 + 9;  // A6

    if keyboard[KEY_CAPSLOCK] then result:= 125;  // NoteOff
    if keyboard[KEY_OEM_102] then result:= 126;  // NoteCut   key = <

end;


function TTracker.VirtualPianoGetKeyFromSample(smp: longint): longint;
begin

    result:= -1;
    if smp = (CurrentOctave * 12 + 0) then result:= KEY_Z;  // C4
    if smp = (CurrentOctave * 12 + 1) then result:= KEY_S;  // C#4
    if smp = (CurrentOctave * 12 + 2) then result:= KEY_X;  // D4
    if smp = (CurrentOctave * 12 + 3) then result:= KEY_D;  // D#4
    if smp = (CurrentOctave * 12 + 4) then result:= KEY_C;  // E4
    if smp = (CurrentOctave * 12 + 5) then result:= KEY_V;  // F4
    if smp = (CurrentOctave * 12 + 6) then result:= KEY_G;  // F#4
    if smp = (CurrentOctave * 12 + 7) then result:= KEY_B;  // G4
    if smp = (CurrentOctave * 12 + 8) then result:= KEY_H;  // G#4
    if smp = (CurrentOctave * 12 + 9) then result:= KEY_N;  // A4
    if smp = (CurrentOctave * 12 + 10) then result:= KEY_J;  // A#4
    if smp = (CurrentOctave * 12 + 11) then result:= KEY_M;  // B4
    if smp = ((CurrentOctave + 1) * 12 + 0) then result:= KEY_Q;  // C5
    if smp = ((CurrentOctave + 1) * 12 + 0) then result:= KEY_OEM_COMMA;  // C5
    if smp = ((CurrentOctave + 1) * 12 + 1) then result:= KEY_2;  // C#5
    if smp = ((CurrentOctave + 1) * 12 + 1) then result:= KEY_L;  // C#5
    if smp = ((CurrentOctave + 1) * 12 + 2) then result:= KEY_W;  // D5
    if smp = ((CurrentOctave + 1) * 12 + 2) then result:= KEY_OEM_PERIOD;  // D5
    if smp = ((CurrentOctave + 1) * 12 + 3) then result:= KEY_3;  // D#5
    if smp = ((CurrentOctave + 1) * 12 + 3) then result:= KEY_OEM_3;  // D#5   key = ö
    if smp = ((CurrentOctave + 1) * 12 + 4) then result:= KEY_E;  // E5
    if smp = ((CurrentOctave + 1) * 12 + 4) then result:= KEY_OEM_MINUS;  // E5
    if smp = ((CurrentOctave + 1) * 12 + 5) then result:= KEY_R;  // F5
    if smp = ((CurrentOctave + 1) * 12 + 6) then result:= KEY_5;  // F#5
    if smp = ((CurrentOctave + 1) * 12 + 6) then result:= KEY_OEM_2;  // F#5   key = #
    if smp = ((CurrentOctave + 1) * 12 + 7) then result:= KEY_T;  // G5
    if smp = ((CurrentOctave + 1) * 12 + 8) then result:= KEY_6;  // G#5
    if smp = ((CurrentOctave + 1) * 12 + 9) then result:= KEY_Y;  // A5
    if smp = ((CurrentOctave + 1) * 12 + 10) then result:= KEY_7;  // A#5
    if smp = ((CurrentOctave + 1) * 12 + 11) then result:= KEY_U;  // B5

    if smp = ((CurrentOctave + 2) * 12 + 0) then result:= KEY_I;  // C6
    if smp = ((CurrentOctave + 2) * 12 + 1) then result:= KEY_9;  // C#6
    if smp = ((CurrentOctave + 2) * 12 + 2) then result:= KEY_O;  // D6
    if smp = ((CurrentOctave + 2) * 12 + 3) then result:= KEY_0;  // D#6
    if smp = ((CurrentOctave + 2) * 12 + 4) then result:= KEY_P;  // E6
    if smp = ((CurrentOctave + 2) * 12 + 5) then result:= KEY_OEM_1;  // F6   key = ü
    if smp = ((CurrentOctave + 2) * 12 + 6) then result:=KEY_OEM_6;  // F#6   key = ´
    if smp = ((CurrentOctave + 2) * 12 + 7) then result:=KEY_OEM_PLUS;  // G6   key = +
    if smp = ((CurrentOctave + 2) * 12 + 9) then result:=KEY_RETURN;  // A6

    //if keyboard[KEY_CAPSLOCK] then result:=125;  // NoteOff
    //if keyboard[KEY_OEM_102] then result:=126;  // NoteCut   key = <

end; 



procedure TTracker.VirtualPianoPlaySampleFromKeyboard;
begin
    if keyboard[KEY_Z] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_Z), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_Z), VirtualKeyboard);  // C4
    if keyboard[KEY_S] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_S), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_S), VirtualKeyboard);  // C#4
    if keyboard[KEY_X] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_X), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_X), VirtualKeyboard);  // D4
    if keyboard[KEY_D] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_D), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_D), VirtualKeyboard);  // D#4
    if keyboard[KEY_C] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_C), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_C), VirtualKeyboard);  // E4
    if keyboard[KEY_V] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_V), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_V), VirtualKeyboard);  // F4
    if keyboard[KEY_G] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_G), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_G), VirtualKeyboard);  // F#4
    if keyboard[KEY_B] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_B), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_B), VirtualKeyboard);  // G4
    if keyboard[KEY_H] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_H), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_H), VirtualKeyboard);  // G#4
    if keyboard[KEY_N] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_N), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_N), VirtualKeyboard);  // A4
    if keyboard[KEY_J] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_J), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_J), VirtualKeyboard);  // A#4
    if keyboard[KEY_M] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_M), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_M), VirtualKeyboard);  // B4

    if keyboard[KEY_Q] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_Q), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_Q), VirtualKeyboard);  // C5
    if keyboard[KEY_OEM_COMMA] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_COMMA), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_COMMA), VirtualKeyboard);  // C5
    if keyboard[KEY_2] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_2), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_2), VirtualKeyboard);  // C#5
    if keyboard[KEY_L] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_L), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_L), VirtualKeyboard);  // C#5
    if keyboard[KEY_W] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_W), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_W), VirtualKeyboard);  // D5
    if keyboard[KEY_OEM_PERIOD] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_PERIOD), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_PERIOD), VirtualKeyboard);  // D5
    if keyboard[KEY_3] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_3), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_3), VirtualKeyboard);  // D#5
    if keyboard[KEY_OEM_3] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_3), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_3), VirtualKeyboard);  // D#5   key = ö
    if keyboard[KEY_E] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_E), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_E), VirtualKeyboard);  // E5
    if keyboard[KEY_OEM_MINUS] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_MINUS), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_MINUS), VirtualKeyboard);  // E5
    if keyboard[KEY_R] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_R), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_R), VirtualKeyboard);  // F5
    if keyboard[KEY_5] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_5), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_5), VirtualKeyboard);  // F#5
    if keyboard[KEY_OEM_2] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_2), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_2), VirtualKeyboard);  // F#5   key = #
    if keyboard[KEY_T] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_T), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_T), VirtualKeyboard);  // G5
    if keyboard[KEY_6] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_6), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_6), VirtualKeyboard);  // G#5
    if keyboard[KEY_Y] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_Y), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_Y), VirtualKeyboard);  // A5
    if keyboard[KEY_7] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_7), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_7), VirtualKeyboard);  // A#5
    if keyboard[KEY_U] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_U), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_U), VirtualKeyboard);  // B5

    if keyboard[KEY_I] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_I), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_I), VirtualKeyboard);  // C6
    if keyboard[KEY_9] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_9), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_9), VirtualKeyboard);  // C#6
    if keyboard[KEY_o] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_O), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_O), VirtualKeyboard);  // D6
    if keyboard[KEY_0] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_0), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_0), VirtualKeyboard);  // D#6
    if keyboard[KEY_P] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_P), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_P), VirtualKeyboard);  // E6
    if keyboard[KEY_OEM_1] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_1), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_1), VirtualKeyboard);  // F6   key = ü
    if keyboard[KEY_OEM_6] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_6), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_6), VirtualKeyboard);  // F#6   key = ´
    if keyboard[KEY_OEM_PLUS] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_PLUS), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_OEM_PLUS), VirtualKeyboard);  // G6   key = +
    if keyboard[KEY_RETURN] then PianoPlaySample(VirtualPianoGetNoteFromKeyboard(KEY_RETURN), VirtualKeyboard) else PianoStopSample(VirtualPianoGetNoteFromKeyboard(KEY_RETURN), VirtualKeyboard);  // A6

//    if keyboard[KEY_CAPSLOCK] then PlaySample(125);  // NoteOff
//    if keyboard[KEY_OEM_102] then PlaySample(126);  // NoteCut   key = <
 
end;


procedure TTracker.MIDIKeypress(command, param1, param2: longint);
begin

    // writeln(command, ' ', param1, ' ', param2);
    MIDICommand:= command;

    if command = MIDIKeyDown then begin
        PianoPlaySample(param1, MIDIKeyboard);
        MIDINote:= param1;
    end;

    if command = MIDIKeyUp then begin
        PianoStopSample(param1, MIDIKeyboard);
        MIDINote:= param1;
    end;

end;



procedure TTracker.PianoPlaySample(key: longint; who: TwhoPalys);
var 
    note : Tnote;
    i : longint;

begin

    if MoreThanOneNotePlaying then exit;

    if not playingSample[key].isPlaying then begin

        Note:= EmptyNote;
        Note.Note:= key;
        Note.Instrument:= CurrentInstrument;
        
        CurrentFreeChannel:= 0;
        
        for i:= 0 to length(playingSample) - 1 do
            if playingSample[i].isPlaying then
                if playingSample[i].channel > CurrentFreeChannel then CurrentFreeChannel:= playingSample[i].channel else break;
        
        inc(CurrentFreeChannel);
        playingSample[key].channel:= CurrentFreeChannel;

        tralalaEngine.PlayNote(playingSample[key].channel, Note);

        netSendPlayNote(playingSample[key].channel, key, PlayNote);

        playingSample[key].isPlaying:= true;

        playingSample[key].whoisPlaying[longint(who)]:= true;

    end;

end;




procedure TTracker.PianoStopSample(key: longint; who: TwhoPalys);
var 
    note : Tnote;

begin

    if playingSample[key].isPlaying then begin

        if (not playingSample[key].whoisPlaying[longint(VirtualKeyboard)]) and (not playingSample[key].whoisPlaying[longint(MIDIKeyboard)]) and (not playingSample[key].whoisPlaying[longint(NETKeyboard)]) then begin

            playingSample[key].isPlaying:= false;
            Note:= EmptyNote;
            Note.Note:= NoteCut;
            
            tralalaEngine.PlayNote(playingSample[key].channel, Note);
            netSendPlayNote(playingSample[key].channel, 0, StopNote);

            playingSample[key].channel:= 0;



        end;
        
        playingSample[key].whoisPlaying[longint(who)]:= false;

    end;

end;


procedure TTracker.PianoStopAllSamples;
var 
    note : Tnote;
    key : longint;
begin

    for key:= 0 to maxKeys - 1 do begin
        
        if playingSample[key].isPlaying then begin
            playingSample[key].isPlaying:= false;

            Note:= EmptyNote;
            Note.Note:= NoteCut;
            
            tralalaEngine.PlayNote(playingSample[key].channel, Note);
           //  netSendPlayNote(playingSample[key].channel, 0, StopNote);

            playingSample[key].channel:= 0;
        end;

    end;

end;


