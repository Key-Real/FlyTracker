{$MODE OBJFPC}
unit MIDIDriverWindows;
interface
uses 
	Windows, MmSystem,
	sysutils, classes;

type   

    TMIDIThread = class(TThread)
    protected
        
        procedure Execute; override;

    public
        
        Constructor Create(CreateSuspended: boolean);

    end;

    TMIDIProc = procedure(const command, param1, param2: longint) of object;
    TMIDIChangeProc = procedure(const status: boolean) of object;

var

	MIDIThread : TMIDIThread;
	isMIDI : boolean;
	MIDIbyStart : boolean;

	MIDIProc : TMIDIProc;
	MIDIChangeProc : TMIDIChangeProc;
	

procedure StartGeneralMIDI;
procedure EndGeneralMIDI;



implementation

var
	inHandle: HMIDIIN;
  	INdev : Integer;
  	MidiInCaps: TMidiInCapsA;
  	
  	MIDIName : string;

  	oldIsMIDI : boolean;


procedure MidiCallback(aMidiInHandle: PHMIDIIN; aMsg: Integer; aInstance, aMidiData, aTimeStamp: integer); stdcall;
begin

  case aMsg of
    MIM_DATA: if assigned(MIDIProc) then MIDIProc(aMidiData and $000000FF, (aMidiData and $0000FF00) shr 8, (aMidiData and $00FF0000) shr 16);
    {
            writeln(aMidiData and $000000FF, ' ',
                                  ( aMidiData and $0000FF00) shr 8, ' ',
                                  ( aMidiData and $00FF0000) shr 16);
}
    MIM_LONGDATA: writeln('MIDI LongData');
    MIM_ERROR:  writeln('MIDI Error');
    MIM_LONGERROR: writeln('MIDI LongError');
  end;

end;






constructor TMIDIThread.Create(CreateSuspended: boolean);
begin

    inherited Create(CreateSuspended);
    FreeOnTerminate:= True;

end;


procedure TMIDIThread.Execute;
var
	i : longint;

begin

	MIDIName:= '';
    while (not Terminated) do begin


    	if midiInGetNumDevs > 0 then begin

	    	isMIDI:= true;

	    end else isMIDI:= false;

	    if isMIDI then begin
	    	if not oldIsMIDI then begin
	    		
	    		for i := 1 to midiInGetNumDevs do begin
	        		midiInGetDevCaps(i - 1, @MidiInCaps, sizeof(TMidiInCapsA));
	       			MIDIName:= StrPas(MidiInCaps.szPname);
	    		end;

	    		oldIsMIDI:= true;

	    		INdev := 0; 
			    if midiInOpen(@inHandle, INdev, qword(@midiCallback), 0, CALLBACK_FUNCTION) = 0 then midiInStart(inHandle) else isMIDI:= false; 

			    if assigned(MIDIChangeProc) then MIDIChangeProc(true);
			    continue;
	    	end;
	    end else begin
	    	if oldIsMIDI then begin
	    		MIDIChangeProc(false);
	    		oldIsMIDI:= false;
	    		isMIDI:= false;
	    		MIDIName:= '';
	    	end;
	    end;


    end;

end;


procedure StartGeneralMIDI;
var 
	i: integer;
begin

	isMIDI:= false;
	oldIsMIDI:= false;
	MIDIbyStart:= false;

	if midiInGetNumDevs > 0 then MIDIbyStart:= true;
    
	MIDIThread:= TMIDIThread.Create(true);
	MIDIThread.Start;

end;

procedure EndGeneralMIDI;
begin

	MIDIThread.Terminate;

	if isMIDI then begin
    	midiInReset(inHandle);
    	midiInClose(inHandle);
	end;

end;


begin
end.