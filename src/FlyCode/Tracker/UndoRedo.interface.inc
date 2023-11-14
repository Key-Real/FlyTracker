
type
	TcollectionItim = record
						pattern : longint;
						row : longint;
						channel : longint;
						note : Tnote;
						prevnote : Tnote;
	end;

	Tcollection = record
						singleNote : TcollectionItim;
						arrayOfNotes : array of TcollectionItim;
	end;

var
	undoCollection : array of Tcollection;
	redoCollection : array of Tcollection;


procedure undoCollectionPush(item: Tcollection);
function undoCollectionPop: Tcollection;

procedure redoCollectionPush(item: Tcollection);
function redoCollectionPop: Tcollection;


procedure collectNote(pattern, row, channel: longint; note: Tnote);
procedure collectBackspace(pattern, row, channel: longint);
procedure collectShiftBackspace(pattern, row: longint);
procedure collectInsert(pattern, row, channel: longint);
procedure collectShiftInsert(pattern, row: longint);

	
procedure UnDo;

procedure ReDo;