{$linkframework AudioToolbox}
{$linkframework CoreMIDI}
{$MODE OBJFPC}
uses MacOSAll,CocoaAll;


procedure checkError(error: OSStatus; msg: string);
begin
    if (error <> noErr) then begin
        writeln('Error: ', error, ' ', msg);
        halt;
    end;
end;


type
		myMIDIPlayer = record
		end;



procedure myMIDINotifyProc(message: MIDINotificationPTR; refCon: pointer); MWPascal;
begin
	writeln('MIDI Notify ',message^.messageID);
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
		midiCommand:= midiStatus shr 4;

//		writeln(packet^.length, ' ', midiStatus);    // if midiStatus returns 0 and packet^.length an random value than your FPC is broken :(

		if (midiCommand = $09) then begin
			note:= packet^.data[1] and $7F;
			velocity:= packet^.data[2] and $7F;
			writeln('note ', note, ' stroke at ', velocity);
		end;

		if (midiCommand = $08) then begin
			note:= packet^.data[1] and $7F;
			writeln('note ', note, ' releaced');
		end;


		packet:= MIDIPacketNext(packet);

	end;

end;


var
	client : MIDIClientRef;
	inPort : MIDIPortRef;
	src : MIDIEndpointRef;

	sourceCount : dword;
	endpointName : CFStringRef;

	status : OSStatus;

	strC : array [0..255] of char;

	player : myMIDIPlayer;

	i : longint;
begin

	status:= MIDIClientCreate(CFSTR('Core MIDI Demo'), @myMIDINotifyProc, @player, client);
	checkError(status, 'Coundn''t create MIDI client');


	status:= MIDIInputPortCreate(client,CFSTR('Input Port'), @myMIDIReadProc, @player, inPort);
	checkError(status, 'Coundn''t create MIDI input port');


	sourceCount:= MIDIGetNumberOfSources;
	writeln(sourceCount, ' Sources found');

	if sourceCount = 0 then halt;


	for i:=0 to sourceCount - 1 do begin

		src:= MIDIGetSource(i);

		status:= MIDIObjectGetStringProperty(src, kMIDIPropertyName, endpointName);
		checkError(status, 'Coundn''t get endpoint name');

		CFStringGetCString(endpointName, strC, 255, kCFStringEncodingUTF8);
		writeln('- source ', i, ' ', strC);
		
		status:= MIDIPortConnectSource(inPort, src, nil);
		checkError(status, 'Coundn''t connect MIDI port');

	end;



	readln;


end.