{$mode delphi}
uses vipgfx,bass,tools,math;
const
  SPECWIDTH     = 640;  // display width
  SPECHEIGHT    = 256;  // height (changing requires palette adjustments too)
  BANDS         = 28;
  szAppName     = 'BASS-Spectrum';

  BASSErCodes   : array[-1..44] of String = (
    'Some other mystery error',
    'All is OK',
    'Memory error',
    'Can''t open the file',
    'Can''t find a free sound driver',
    'The sample buffer was lost',
    'Invalid handle',
    'Unsupported sample format',
    'Invalid playback position',
    'BASS_Init has not been successfully called',
    'BASS_Start has not been successfully called',
    'Unknown error',
    'Unknown error',
    'Unknown error',
    'Unknown error',
    'Already initialized/paused/whatever',
    'Unknown error',
    'Not paused',
    'Unknown error',
    'Can''t get a free channel',
    'An illegal type was specified',
    'An illegal parameter was specified',
    'No 3D support',
    'No EAX support',
    'Illegal device number',
    'Not playing',
    'Illegal sample rate',
    'Unknown error',
    'The stream is not a file stream',
    'Unknown error',
    'No hardware voices available',
    'Unknown error',
    'The MOD music has no sequence data',
    'No internet connection could be opened',
    'Couldn''t create the file',
    'Effects are not enabled',
    'The channel is playing',
    'Unknown error',
    'Requested data is not available',
    'The channel is a "decoding channel"',
    'A sufficient DirectX version is not installed',
    'Connection timedout',
    'Unsupported file format',
    'Unavailable speaker',
    'Invalid BASS version (used by add-ons)',
    'Codec is not available/supported');

var
  PosX, PosY    : Integer;
  SizeX, SizeY  : Integer;

  Timer         : DWORD = 0;
  Chan          : DWORD;

  
  SpecMode      : Integer = 3;
  SpecPos       : Integer = 0; // spectrum mode (and marker pos for 2nd mode)

//---------------------------------------------------------



//---------------------------------------------------------

function Power(const Base, Exponent: Extended): Extended;
begin
  if Exponent = 0.0 then
    Result := 1.0               { n**0 = 1 }
  else if (Base = 0.0) and (Exponent > 0.0) then
    Result := 0.0               { 0**n = 0, n > 0 }
  else if (Frac(Exponent) = 0.0) and (Abs(Exponent) <= MaxInt) then
    Result := IntPower(Base, Integer(Trunc(Exponent)))
  else
    Result := Exp(Exponent * Ln(Base))
end;

//---------------------------------------------------------
// Log.10(X) := Log.2(X) * Log.10(2)



//---------------------------------------------------------

function IntToStr(I : Integer) : String;
begin
  Str(I, Result);
end;

//---------------------------------------------------------

//---------------------------------------------------------
// display error messages

procedure Error(St : String);
var
  ErrCode : Integer;
  Mes     : String;
begin
  ErrCode := BASS_ErrorGetCode;
  if ErrCode > 44 then
    ErrCode := 10;

  Mes := St + #13#10 + BASSErCodes[ErrCode] + #13#10 + '(Error code: ' + IntToStr(ErrCode) + ')';
  writeln(Mes);
  halt;
end;

//---------------------------------------------------------
// select a file to play, and play it

function PlayFile: Boolean;
var
  TempFileName  : String;
begin
  Result := False;
  TempFileName := '../../src/dubbish.xm';
  chan := BASS_StreamCreateFile(False, PChar(TempFileName), 0, 0, BASS_SAMPLE_LOOP);
  if (chan = 0) then
  begin
    chan := BASS_MusicLoad(False, PChar(TempFileName), 0, 0, BASS_MUSIC_RAMP or BASS_SAMPLE_LOOP, 1);
    if (chan = 0) then
    begin
      Error('Can''t play file'); // Can't load the file
      Exit;
    end;
  end;

  BASS_ChannelPlay(chan, False);
  Result := True;
end;

//---------------------------------------------------------
// update the spectrum display - the interesting bit :)

procedure mainloop;
type
  TSingleArray  = array of Single;
var
  X, Y, Z,
  I, J, sc      : Integer;
  Sum           : Single;
  fft           : array[0..1023] of Single; // get the FFT data
  ci            : BASS_CHANNELINFO;
  Buf           : TSingleArray;
begin
  if SpecMode = 3 then  // waveform
  begin
    fastfill(vscreen.data,vscreen.width*vscreen.height,0);
    BASS_ChannelGetInfo(chan, ci); // get number of channels
    SetLength(Buf, ci.chans * SPECWIDTH);
    Y := 0;
    BASS_ChannelGetData(chan, buf, (ci.chans * SPECWIDTH * SizeOf(Single)) or BASS_DATA_FLOAT); // get the sample data (floating-point to avoid 8 & 16 bit processing)
    for I := 0 to ci.chans - 1 do
    begin
      for X := 0 to SPECWIDTH - 1 do
      begin
        Z := Trunc((1 - Buf[X * Integer(ci.chans) + I]) * SPECHEIGHT / 2); // invert and scale to fit display
        if Z < 0 then
          Z := 0
        else if Z >= SPECHEIGHT then
          Z := SPECHEIGHT - 1;
        if X = 0 then
          Y := Z;
        repeat  // draw line from previous sample...
          if Y < Z then
            inc(Y)
          else if Y > Z then
            dec(Y);
          if (I and 1) = 1 then
            putpixelclip(vscreen,x,y,RGBA(127,127,127,255))
          else
			putpixelclip(vscreen,x,y,RGBA(0,0,127,255));
        until Y = Z;
      end;
    end;
  end
  else
  begin
    BASS_ChannelGetData(chan, @fft, BASS_DATA_FFT2048);
    case SpecMode of
      0 :  // "normal" FFT
      begin
		fastfill(vscreen.data,vscreen.width*vscreen.height,0);
        Z := 0;
        for X := 0 to pred(SPECWIDTH) div 2 do
        begin
          Y := Trunc(sqrt(fft[X + 1]) * 3 * SPECHEIGHT - 4); // scale it (sqrt to make low values more visible)
//      Y := Trunc(fft[X + 1] * 10 * SPECHEIGHT); // scale it (linearly)
          if Y > SPECHEIGHT then
            Y := SPECHEIGHT; // cap it

          if (X > 0) and (Z = (Y + Z) div 2) then // interpolate from previous to make the display smoother
            while (Z >= 0) do
            begin
			  putpixelclip(vscreen,x*2-1,Z,RGBA(Z+1,0,0,255));
              dec(Z);
            end;

          Z := Y;
          while (Y >= 0) do
          begin
			putpixelclip(vscreen,x*2-1,y,RGBA(y+1,0,0,255)); // draw level
            dec(Y);
          end;
        end;
      end;
      1 :   // logarithmic, acumulate & average bins
      begin
        I := 0;
				fastfill(vscreen.data,vscreen.width*vscreen.height,0);
        for X := 0 to BANDS - 1 do
        begin
          Sum := 0;
          J  := Trunc(Power(2, X * 10.0 / (BANDS - 1)));
          if J > 1023 then
            J := 1023;
          if J <= I then
            J := I + 1; // make sure it uses at least 1 FFT bin
          sc := 10 + J - I;

          while I < J do
          begin
            Sum := Sum + fft[1 + I];
            inc(I);
          end;

          Y := Trunc((sqrt(Sum / log10(sc)) * 1.7 * SPECHEIGHT) - 4); // scale it
          if Y > SPECHEIGHT then
            Y := SPECHEIGHT; // cap it
          while (Y >= 0) do
          begin
            Filldword(pointer(vscreen.data + (Y * SPECWIDTH + X * (SPECWIDTH div BANDS))*4)^, SPECWIDTH div BANDS - 2, RGBA(Y + 1,0,0,255)); // draw bar
			
			//drawbar(vscreen,0,x,y);
            dec(Y);
          end;
        end;
      end;
      2 :  // "3D"
      begin
        for X := 0 to SPECHEIGHT - 1 do
        begin
          Y := Trunc(sqrt(fft[x + 1]) * 3 * 127); // scale it (sqrt to make low values more visible)
          if Y > 127 then
            Y := 127; // cap it
  
		  putpixelclip(vscreen,specpos,x,RGBA(y,0,0,255));
        end;
        // move marker onto next position
        SpecPos := (SpecPos + 1) mod SPECWIDTH;
        for X := 0 to SPECHEIGHT do
		  		  putpixelclip(vscreen,specpos,x,RGBA(0,0,0,255));
      end;
    end;
  end;
  
  if keyboard[key_1] then specmode:=0;
  if keyboard[key_2] then specmode:=1;
  if keyboard[key_3] then specmode:=2;
  if keyboard[key_4] then specmode:=3;
  
  
  
end;


 
begin

//---------------------------------------------------------
  // check the correct BASS was loaded
  if HI(BASS_GetVersion) <> BASSVERSION then
  begin
    logwrite('An incorrect version of BASS.DLL was loaded');
    Exit;
  end;

      // initialize BASS
      if not BASS_Init(-1, 44100, 0, 0, NIL) then
      begin
        Error('Can''t initialize device');
        Exit;
      end;

      if not PlayFile then // start a file playing
      begin
        BASS_Free;
        
        Exit;
      end;

specmode:=0;
	  
initgfxsystem(640,480,false);	  


repeat

  mainloop;

updateGFXsystem;

until keyboard[key_escape];
	  
 finishgfxsystem;
 BASS_Free;

end.
