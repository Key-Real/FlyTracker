{$MODE OBJFPC}

uses asoundlib, sysutils;

var

	MIDICard : longint;
	MIDIDevice : longint;
	MIDISub : longint;

// print_card_list -- go through the list of available "soundcards"
//   in the ALSA system, printing their associated numbers and names.
//   Cards may or may not have any MIDI ports available on them (for 
//   example, a card might only have an audio interface).
procedure print_card_list;
var
   status : longint;
   card : longint = -1;  // use -1 to prime the pump of iterating through card list
	longname : pchar;
   shortname : pchar;
	
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
		writeln('Card ', card);

		status:= snd_card_get_name(card, @shortname);
		if status < 0 then begin
		 writeln('cannot determine card shortname: ', snd_strerror(status));
		 break;
		end;

		status:= snd_card_get_longname(card, @longname);

      if status < 0 then begin
         writeln('cannot determine card longname: ', snd_strerror(status));
         break;
      end;

      writeln('LONG NAME: ', longname);
      writeln('SHORT NAME: ', shortname);

      status:= snd_card_next(@card);
      if status < 0 then begin
         writeln('cannot determine card number: ', snd_strerror(status));
         break;
      end;

   end;

end;




// is_input -- returns true if specified card/device/sub can output MIDI data.
function is_input(ctl: Psnd_ctl_t; card, device, sub: longint): longint;
var
   info : Psnd_rawmidi_info_t;
   status : longint;
begin
   snd_rawmidi_info_malloc(@info);
   snd_rawmidi_info_set_device(info, device);
   snd_rawmidi_info_set_subdevice(info, sub);
   snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_INPUT);
   status:= snd_ctl_rawmidi_info(ctl, info);

   if (status < 0) and (status <> 6{-ENXIO}) then begin
      result:= status;
      exit;
   end else if status = 0 then begin
      result:= 1;
      exit;
   end;

   result:= 0;
end;


// is_output -- returns true if specified card/device/sub can output MIDI data.
function is_output(ctl: Psnd_ctl_t; card, device, sub: longint): longint;
var
   info : Psnd_rawmidi_info_t;
   status : longint;
begin
   snd_rawmidi_info_malloc(@info);
   snd_rawmidi_info_set_device(info, device);
   snd_rawmidi_info_set_subdevice(info, sub);
   snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_OUTPUT);
   
   status:= snd_ctl_rawmidi_info(ctl, info);

   if (status < 0) and (status <> 6{-ENXIO}) then begin
      result:= status;
      exit;
   end else if status = 0 then begin
      result:= 1;
      exit;
   end;

   result:= 0;
end;




// list_subdevice_info -- Print information about a subdevice
//   of a device of a card if it can handle MIDI input and/or output.
procedure list_subdevice_info(ctl: Psnd_ctl_t; card, device: longint);
var
   info : Psnd_rawmidi_info_t;
   name : array [0..255] of char;
   sub_name : array [0..255] of char;
   subs, subs_in, subs_out : longint;
   sub, _in, _out : longint;
   status : longint;

begin

   snd_rawmidi_info_malloc(@info);
   snd_rawmidi_info_set_device(info, device);

   snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_INPUT);
   snd_ctl_rawmidi_info(ctl, info);
   subs_in:= snd_rawmidi_info_get_subdevices_count(info);

   snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_OUTPUT);
   snd_ctl_rawmidi_info(ctl, info);
   subs_out:= snd_rawmidi_info_get_subdevices_count(info);

   if subs_in > subs_out then subs:= subs_in else subs:= subs_out;

   sub:= 0;
   _in:= 0;
   _out:= 0;

   status:= is_output(ctl, card, device, sub);
   if status < 0 then begin
      writeln('cannot get rawmidi information ', card, ':', device, snd_strerror(status));
      halt;
   end else begin
      _out:= 1;
   end;

   if status = 0 then begin

   	status:= is_input(ctl, card, device, sub);
      if status < 0 then begin
         writeln('cannot get rawmidi information ', card, ':', device, snd_strerror(status));
         halt;
      end;

   end else if status > 0 then _in:= 1;

   if status = 0 then halt;

   name:= snd_rawmidi_info_get_name(info);
   sub_name:= snd_rawmidi_info_get_subdevice_name(info);
   
   if sub_name[0] = #0 then begin

      if subs = 1 then begin
         writeln('IN: ', _in, ' ', 'OUT: ', _out, ' ', card, ':', device, name);
      end else begin
      	writeln('IN: ', _in, ' ', 'OUT: ', _out, ' ', card, ':', device, ' ', name, ' ', subs, ' subdevices');
      end;

   end else begin

      sub:= 0;
      repeat
         writeln('IN: ', _in, ' ', 'OUT: ', _out, ' ', card, ':', device, ' ', name, ' ', subs, ' ', sub_name);
         MIDICard:= card;
         MIDIDevice:= device;
         MIDISub:= sub;

         inc(sub);
         if sub >= subs then break;

         _in:= is_input(ctl, card, device, sub);
         _out:= is_output(ctl, card, device, sub);
         snd_rawmidi_info_set_subdevice(info, sub);

         if _out > 0 then begin

            snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_OUTPUT);
            status:= snd_ctl_rawmidi_info(ctl, info);
            if status < 0 then begin
               writeln('cannot get rawmidi information ', card, ':', device, ':', sub, ' ', snd_strerror(status));
               break;
            end;

         end else begin

            snd_rawmidi_info_set_stream(info, SND_RAWMIDI_STREAM_INPUT);
            status:= snd_ctl_rawmidi_info(ctl, info);
            if status < 0 then begin
            	writeln('cannot get rawmidi information ', card, ':', device, ':', sub, ' ', snd_strerror(status));
               break;
            end;
            
         end;

         sub_name:= snd_rawmidi_info_get_subdevice_name(info);

   	until false;

   end;
end;




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
	     	writeln('cannot determine device number: ', snd_strerror(status));
	     	break;
	  	end;

     if device >= 0 then
       list_subdevice_info(ctl, card, device);

	until device < 0;

	snd_ctl_close(ctl);

end;


// print_midi_ports -- go through the list of available "soundcards",
//   checking them to see if there are devices/subdevices on them which
//   can read/write MIDI data.
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





procedure testMIDIin;
var
	status : longint;
   mode : longint = SND_RAWMIDI_SYNC;
   midiin : Psnd_rawmidi_t;
   portname : array [0..255] of char;
   count : longint = 0;         // Current count of bytes received.
   buffer : array [0..1] of char;        // Storage for input buffer received

begin

	midiin:= nil;
   portname:= 'hw:' + inttostr(MIDICard) + ',' + inttostr(MIDIDevice) + ',' + inttostr(MIDISub);
	
	status:= snd_rawmidi_open(@midiin, nil, portname, mode);
   if status < 0 then begin
      writeln('Problem opening MIDI input: ', snd_strerror(status));
      halt;
   end;


   while true do begin
   	
   	status:= snd_rawmidi_read(midiin, @buffer, 1);
      if status < 0 then writeln('Problem reading MIDI input: ', snd_strerror(status));

      write('Command:', byte(buffer[0]), ' ');


		status:= snd_rawmidi_read(midiin, @buffer, 1);
      if status < 0 then writeln('Problem reading MIDI input: ', snd_strerror(status));

      write(byte(buffer[0]), ' ');


		status:= snd_rawmidi_read(midiin, @buffer, 1);
      if status < 0 then writeln('Problem reading MIDI input: ', snd_strerror(status));

      write(byte(buffer[0]), ' ');


		writeln;         

   end;


   snd_rawmidi_close(midiin);
   midiin:= nil;

end;


begin
	//print_card_list;
	print_midi_ports;
	testMIDIin;
end.