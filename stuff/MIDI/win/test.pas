{$MODE OBJFPC}
uses Windows, MmSystem;


procedure MidiCallback(aMidiInHandle: PHMIDIIN; aMsg: Integer; aInstance, aMidiData, aTimeStamp: integer); stdcall;
begin

  case aMsg of
    MIM_DATA:
            writeln(aMidiData and $000000FF, ' ',
                                  ( aMidiData and $0000FF00) shr 8, ' ',
                                  ( aMidiData and $00FF0000) shr 16);

    MIM_LONGDATA: writeln('MIDI LongData');
    MIM_ERROR:  writeln('MIDI Error');
    MIM_LONGERROR: writeln('MIDI LongError');
  end;

end;


var
  inHandle: HMIDIIN;
  INdev : Integer;
  MidiInCaps: TMidiInCapsA;
  i: integer;

begin

    for i := 1 to midiInGetNumDevs do begin
        midiInGetDevCaps(i - 1, @MidiInCaps, sizeof(TMidiInCapsA));
        writeln('dev', i, ' ', StrPas(MidiInCaps.szPname));
    end;
    
    INdev := 0; 
    if midiInOpen(@inHandle, INdev, qword(@midiCallback), 0, CALLBACK_FUNCTION) = 0 then midiInStart(inHandle) else writeln('MIDI-IN error!'); 

    
    readln; 


    midiInReset(inHandle);
    midiInClose(inHandle);

end.