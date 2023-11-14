{$MODE OBJFPC} 
unit GeneralMIDI;
interface
uses {$IFDEF LINUX}MIDIDriverLinux, {$ENDIF} {$IFDEF WINDOWS} MIDIDriverWindows, {$ENDIF} {$IFDEF DARWIN} MIDIDriverMac, {$ENDIF}
	 theMain, theTracker, theInstrumentEditor,
	 tui.Core, tui.Dialog.MessageBox;

type
	TMIDI = class
		
		aDialog : TtuiDialogMessageBox;

		constructor Create;

		procedure MIDIChange(const status: boolean);
		procedure MIDIExecProc(const command, param1, param2: longint);

	end;

var

	MIDI : TMIDI;


implementation


constructor TMIDI.Create;
begin
	MIDIChangeProc:= @MIDIChange;
	MIDIProc:= @MIDIExecProc;
end;


procedure TMIDI.MIDIChange(const status: boolean);
var
	s : string;
	ui : TtuiTUI;
begin

	if MIDIbyStart then begin
		MIDIbyStart:= false;
		exit;
	end;


	if status then s:= 'MIDI Keyboard is plugged in' else s:= 'MIDI Keyboard disconnected';

	if currentmode = modeTracker then ui:=TrackerTUI;
	if currentmode = modeInstrumentEditor then ui:=InstrumentEditorTUI;


	aDialog:=TtuiDialogMessageBox.Create(@aDialog, ui, s);

end;


procedure TMIDI.MIDIExecProc(const command, param1, param2: longint);
begin
	//writeln(command, ' ', param1, ' ', param2);
	if currentmode = modeTracker then Tracker.MIDIKeypress(command, param1, param2);
end;

begin
end.