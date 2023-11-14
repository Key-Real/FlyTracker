{$MODE OBJFPC}
unit MIDIDriverLinux;
interface
uses {$IFDEF UNIX}
    cthreads, 
	{$ENDIF}
	asoundlib, sysutils, classes;

type   

    TMIDIThread = class(TThread)
    protected
        
        procedure Execute; override;

    public

    	var
    		oldIsMIDI : boolean;
        
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

function MIDIKeyboardFound: boolean;	

procedure StartGeneralMIDI;
procedure EndGeneralMIDI;


implementation

var

	MIDICard : longint;
	MIDIDevice : longint;
	MIDISub : longint;
	MIDIName : string;

// is_input -- returns true if specified card/device/sub can output MIDI data.
function is_input(ctl: Psnd_ctl_t; card, device, sub: longint): longint;
var
   info : Psnd_rawmidi_info_t;
   status : longint;

begin
	result:= 0;
   	snd_rawmidi_info_malloc(@info);
   	snd_rawmidi_info_set_device(info, device);
   	snd_rawmidi_info_set_subdevice(info, sub);
   	snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_INPUT);
   	status:= snd_ctl_rawmidi_info(ctl, info);

   	if (status < 0) and (status <> 6{-ENXIO}) then begin
      	result:= status;
   	end else if status = 0 then begin
      	result:= 1;
   	end;

end;





// list_subdevice_info -- Print information about a subdevice
//   of a device of a card if it can handle MIDI input and/or output.
{$NOTES OFF}
procedure list_subdevice_info(ctl: Psnd_ctl_t; card, device: longint);
var
   info : Psnd_rawmidi_info_t;
   name : array [0..255] of char;
   sub_name : array [0..255] of char;
   subs_in : longint;
   sub, _in : longint;
   status : longint;
   i : longint;

begin

   snd_rawmidi_info_malloc(@info);
   snd_rawmidi_info_set_device(info, device);

   snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_INPUT);
   snd_ctl_rawmidi_info(ctl, info);
   subs_in:= snd_rawmidi_info_get_subdevices_count(info);

   _in:= 0;
   sub:= 0;

   	status:= is_input(ctl, card, device, sub);
      if status < 0 then begin
         writeln('cannot get rawmidi information ', card, ':', device, snd_strerror(status));
         halt;
      end;

   if status > 0 then _in:= 1;

   if status = 0 then begin
         writeln('status 0');
         halt;
   	exit;
   end;

   name:= snd_rawmidi_info_get_name(info);
   sub_name:= snd_rawmidi_info_get_subdevice_name(info);
   
         MIDICard:= card;
         MIDIDevice:= device;
         MIDISub:= sub;

         _in:= is_input(ctl, card, device, sub);
         snd_rawmidi_info_set_subdevice(info, sub);

         sub_name:= snd_rawmidi_info_get_subdevice_name(info);

    MIDIName:= '';
    for i:= 0 to 255 do begin
    	if name[i] = '%' then break;
    	MIDIName:= MIDIName + name[i];    	
    end;


end;
{$NOTES ON}

// list_midi_devices_on_card -- For a particular "card" look at all
//   of the "devices/subdevices" on it and print information about it
//   if it can handle MIDI input and/or output.
procedure list_midi_devices_on_card(card: longint);
var
	ctl : Psnd_ctl_t;
	name : array [0..255] of char;
	device : longint = -1;
   status : longint;

begin

	name:= 'hw:' + inttostr(card);

   status:= snd_ctl_open(@ctl, name, 0);

	if status < 0 then begin
 		writeln('cannot open control for card ', card, snd_strerror(status));
   	halt;
	end;



	repeat
   	status:= snd_ctl_rawmidi_next_device(ctl, @device);
		
		if (status < 0) and (device = 0) then begin
	     	writeln('No MIDI device attached');
	     	break;
	  	end;

		if status < 0 then begin
	     	//writeln('cannot determine device number: ', snd_strerror(status));
	     	break;
	  	end;

     if device >= 0 then
       list_subdevice_info(ctl, card, device);

	until device < 0;

	snd_ctl_close(ctl);

end;


procedure print_midi_ports;
var
	status : longint;
   	card : longint = -1;  // use -1 to prime the pump of iterating through card list

begin
	
	status:= snd_card_next(@card);

   if status < 0 then begin
      writeln('cannot determine card number: ', snd_strerror(status));
      halt;
   end;

   if card < 0 then begin
      writeln('no sound cards found');
      halt;
   end;

   while card >= 0 do begin

      list_midi_devices_on_card(card);

      status:= snd_card_next(@card);
      if status < 0 then begin
         writeln('cannot determine card number: ', snd_strerror(status));
         break;
      end;

   end; 

end;




function MIDIKeyboardFound: boolean;
begin
	
	result:= false;
	MIDIName:= '';
	print_midi_ports;
	if MIDIName <> '' then result:= true;

end;


var
	status : longint;
   	mode : longint = SND_RAWMIDI_SYNC;
   	midiin : Psnd_rawmidi_t;
   	portname : array [0..255] of char;
   	MIDIbuffer : array [0..1] of char;        // Storage for input buffer received


function InitMIDI: boolean;
begin

	result:= true;

	midiin:= nil;
   	portname:= 'hw:' + inttostr(MIDICard) + ',' + inttostr(MIDIDevice) + ',' + inttostr(MIDISub);
	
	status:= snd_rawmidi_open(@midiin, nil, portname, mode);
   	if status < 0 then begin
      //writeln('Problem opening MIDI input: ', snd_strerror(status));
      //halt;
      result:= false;
   	end;

end;


function returnMIDIinput: boolean;
var
	MIDICommand : longint;
	MIDIParam1, MIDIParam2 : longint;

begin
	
	result:= true;

	MIDICommand:= 0;
	MIDIParam1:= 0;
	MIDIParam2:= 0;


	status:= snd_rawmidi_read(midiin, @MIDIbuffer, 1);
      if status < 0 then begin
      	//writeln('Problem reading MIDI input: ', snd_strerror(status));
      	result:= false;
      	exit;
      end;

      //write('Command:', byte(MIDIbuffer[0]), ' ');

      MIDICommand:= byte(MIDIbuffer[0]);


		status:= snd_rawmidi_read(midiin, @MIDIbuffer, 1);
      if status < 0 then begin
      	//writeln('Problem reading MIDI input: ', snd_strerror(status));
      	result:= false;
      	exit;
      end;

      //write(byte(MIDIbuffer[0]), ' ');

      MIDIParam1:= byte(MIDIbuffer[0]);

		status:= snd_rawmidi_read(midiin, @MIDIbuffer, 1);
      if status < 0 then begin
      	//writeln('Problem reading MIDI input: ', snd_strerror(status));
      	result:= false;
      	exit;
      end;

      //write(byte(MIDIbuffer[0]), ' ');
      MIDIParam2:= byte(MIDIbuffer[0]);

      if assigned(MIDIProc) then MIDIProc(MIDICommand, MIDIParam1, MIDIParam2);

end;

procedure MIDIchanged(status: boolean);
begin
	
	if assigned(MIDIChangeProc) then MIDIChangeProc(status);

end;


constructor TMIDIThread.Create(CreateSuspended: boolean);
begin

    inherited Create(CreateSuspended);
    FreeOnTerminate:= True;

end;


procedure TMIDIThread.Execute;
begin

    while (not Terminated) do begin

    	isMIDI:= MIDIKeyboardFound;

    	if isMIDI then begin
    		if oldIsMIDI then begin
    			isMIDI:= returnMIDIinput;
    			if not isMIDI then begin
    				snd_rawmidi_close(midiin);
   					midiin:= nil;	
   					oldIsMIDI:= false;
   					MIDIchanged(isMIDI);
    			end;
    			continue;
    		end;

    		if not oldIsMIDI then begin
				isMIDI:=InitMIDI;
				if not isMIDI then begin
    				snd_rawmidi_close(midiin);
   					midiin:= nil;	
   					oldIsMIDI:= false;
   					MIDIchanged(isMIDI);
   					continue;
    			end;
    			  			
    			oldIsMIDI:= true;
    			MIDIchanged(isMIDI);
    			continue;
    		end;

    	end else begin

    		if oldIsMIDI then begin
    			snd_rawmidi_close(midiin);
   				midiin:= nil;
   				oldIsMIDI:= false;
   				continue;
    		end;

    	end;

    end;

end;


procedure StartGeneralMIDI;
begin

	isMIDI:= false;

   MIDIbyStart:= MIDIKeyboardFound;

	MIDIThread:= TMIDIThread.Create(true);
	MIDIThread.Start;

end;

procedure EndGeneralMIDI;
begin
	
	MIDIThread.Terminate;

end;


begin
end.