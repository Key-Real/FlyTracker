{$MODE OBJFPC}
{$linkframework AudioToolbox}
{$linkframework CoreMIDI}
unit MIDIDriverMac;
interface
uses 
	MacOSAll,CocoaAll,
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

type
		myMIDIPlayer = record
		end;

var
	oldIsMIDI : boolean;

	client : MIDIClientRef;
	inPort : MIDIPortRef;
	src : MIDIEndpointRef;

	sourceCount : dword;
	endpointName : CFStringRef;

	status : OSStatus;

	strC : array [0..255] of char;

	player : myMIDIPlayer;

	i : longint;

	MIDIName : string;


procedure checkError(error: OSStatus; msg: string);
begin
    if (error <> noErr) then begin
        writeln('MIDI Error: ', error, ' ', msg);
    end;
end;



procedure myMIDINotifyProc(message: MIDINotificationPTR; refCon: pointer); MWPascal;
begin
	// writeln('MIDI Notify ',message^.messageID);
end;

procedure myMIDIReadProc(pktlist: MIDIPacketListPTR; refCon: pointer; connRefCon: pointer); MWPascal;
var packet : MIDIPacketPTR;
	i : longint;
	midiStatus : byte;
	midiCommand : byte;
	note : byte;
	velocity : byte;
begin

	packet:= @pktlist^.packet[0];

	for i:=0 to pktlist^.numPackets-1 do begin

		midiStatus:= packet^.data[0];
		midiCommand:= midiStatus;

//		writeln(packet^.length, ' ', midiStatus);    // if midiStatus returns 0 and packet^.length an random value than your FPC is broken :(
{
		if (midiCommand = $09) then begin
			note:= packet^.data[1] and $7F;
			velocity:= packet^.data[2] and $7F;
			writeln('note ', note, ' stroke at ', velocity);
		end;

		if (midiCommand = $08) then begin
			note:= packet^.data[1] and $7F;
			writeln('note ', note, ' releaced');
		end;
}
		if assigned(MIDIProc) then MIDIProc(midiCommand, packet^.data[1] and $7F, packet^.data[2] and $7F);

		packet:= MIDIPacketNext(packet);

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
	isMIDI:= false;
    while (not Terminated) do begin

		sourceCount:= MIDIGetNumberOfSources;
		if sourceCount > 0 then begin
			isMIDI:= true;

			if not oldIsMIDI then begin
				for i:=0 to sourceCount - 1 do begin

					src:= MIDIGetSource(i);

					status:= MIDIObjectGetStringProperty(src, kMIDIPropertyName, endpointName);
					checkError(status, 'Coundn''t get endpoint name');

					CFStringGetCString(endpointName, strC, 255, kCFStringEncodingUTF8);
					writeln('- source ', i, ' ', strC);
					MIDIName:= string(strC);
					
					status:= MIDIPortConnectSource(inPort, src, nil);
					checkError(status, 'Coundn''t connect MIDI port');

					oldIsMIDI:= true;

					if assigned(MIDIChangeProc) then MIDIChangeProc(true);

				end;
			end;
		end else begin
			if oldIsMIDI then begin
				isMIDI:= false;
				oldIsMIDI:= false;
				MIDIName:= '';
				if assigned(MIDIChangeProc) then MIDIChangeProc(false);
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

	status:= MIDIClientCreate(CFSTR('Core MIDI Demo'), @myMIDINotifyProc, @player, client);
	checkError(status, 'Coundn''t create MIDI client');


	status:= MIDIInputPortCreate(client,CFSTR('Input Port'), @myMIDIReadProc, @player, inPort);
	checkError(status, 'Coundn''t create MIDI input port');

	if MIDIGetNumberOfSources > 0 then MIDIbyStart:= true;

    
	MIDIThread:= TMIDIThread.Create(true);
	MIDIThread.Start;

end;

procedure EndGeneralMIDI;
begin

	MIDIThread.Terminate;

	if isMIDI then begin
	end;

end;


begin
end.