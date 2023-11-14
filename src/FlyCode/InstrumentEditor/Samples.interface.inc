public
var
	SampleSelector : TtuiEditableSelectBoxNumbered;
	procedure execProcSampleSelectorClick(const param: string);

procedure BuildSamples;
procedure reloadSamples;

procedure attachSamples2PianoKey;
procedure selectingSamples;

var
	selectedNote : longint;
	mappedNote : longint;

	inChoseMode : boolean;

procedure MakeNoteChosen(note: longint);

var
	freshMappedSampleOnPanoKey : array [0..99] of array of longint;

procedure drawPianoSamples;


var
	TextBoxSampleDriven:TtuiTextBox;