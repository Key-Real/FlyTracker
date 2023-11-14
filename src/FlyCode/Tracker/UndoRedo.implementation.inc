procedure TTracker.undoCollectionPush(item: Tcollection);
var
	i : longint;
	it : Tcollection;

begin

	setlength(undoCollection, length(undoCollection) + 1);

	if length(undoCollection) > 1 then
	for i:= length(undoCollection) - 2 downto 0 do begin
		it:= undoCollection[i];
		undoCollection[i + 1]:= it;
	end;

	undoCollection[0]:= item;

end;


function TTracker.undoCollectionPop: Tcollection;
var
	i : longint;
	it : Tcollection;

begin

	result:= undoCollection[0];
	for i:= 0 to length(undoCollection) - 2 do begin
		it:= undoCollection[i + 1];
		undoCollection[i]:= it;
	end;
	
	setlength(undoCollection, length(undoCollection) - 1);

end;


procedure TTracker.redoCollectionPush(item: Tcollection);
var
	i : longint;
	it : Tcollection;

begin

	setlength(redoCollection, length(redoCollection) + 1);

	if length(redoCollection) > 1 then
	for i:= length(redoCollection) - 2 downto 0 do begin
		it:= redoCollection[i];
		redoCollection[i + 1]:= it;
	end;

	redoCollection[0]:=item;

end;

function TTracker.redoCollectionPop: Tcollection;
var
	i : longint;
	it : Tcollection;

begin

	result:= redoCollection[0];
	for i:= 0 to length(redoCollection) - 2 do begin
		it:= redoCollection[i + 1];
		redoCollection[i]:= it;
	end;
	
	setlength(redoCollection, length(redoCollection) - 1);

end;


procedure TTracker.collectNote(pattern, row, channel: longint; note: Tnote);
var
	item : TcollectionItim;
	c : Tcollection;
begin
	
	item.prevnote:= Module.Patterns[pattern].notes[row,channel];
	item.pattern:= pattern;
	item.row:= row;
	item.channel:= channel;
	item.note:= note;

	c.singleNote:= item;
	setlength(c.arrayOfNotes, 0);

	undoCollectionPush(c);

end;


procedure TTracker.collectBackSpace(pattern, row, channel: longint);
var
	item : TcollectionItim;
	c : Tcollection;
	i : longint;

begin
	row:= row - 1;

	setlength(c.arrayOfNotes, Module.Patterns[pattern].RowsCount - row);

	for i:= row to Module.Patterns[pattern].RowsCount - 1 do begin

		if (i + 1) <= (Module.Patterns[pattern].RowsCount - 1 ) then begin
			item.note:= Module.Patterns[pattern].notes[i + 1, channel];
		end else item.note:= emptynote;

		item.prevnote:= Module.Patterns[pattern].notes[i, channel];
		item.pattern:= pattern;
		item.row:= i;
		item.channel:= channel;
		c.arrayOfNotes[i - row]:= item;
	end;

	undoCollectionPush(c);

end;


procedure TTracker.collectShiftBackspace(pattern, row: longint);
var
	item : TcollectionItim;
	c : Tcollection;
	i : longint;
	ch : longint;
begin
	
	row:=row - 1;

	setlength(c.arrayOfNotes, (Module.Patterns[pattern].RowsCount - row) *  Module.NumberOFChannels);

	for ch:= 1 to Module.NumberOFChannels do
		for i:= row to Module.Patterns[pattern].RowsCount - 1 do begin

			if (i + 1) <= (Module.Patterns[pattern].RowsCount - 1 ) then begin
				item.note:= Module.Patterns[pattern].notes[i + 1, ch];
			end else item.note:= emptynote;

			item.prevnote:= Module.Patterns[pattern].notes[i,ch];
			item.pattern:= pattern;
			item.row:= i;
			item.channel:= ch;
			c.arrayOfNotes[(i - row) + ((Module.Patterns[pattern].RowsCount - row) * (ch - 1))]:= item;
		end;

	undoCollectionPush(c);

end;



procedure TTracker.collectInsert(pattern, row, channel: longint);
var
	item : TcollectionItim;
	c : Tcollection;
	i : longint;

begin
	setlength(c.arrayOfNotes, Module.Patterns[pattern].RowsCount - row);

	for i:= row to Module.Patterns[pattern].RowsCount - 1 do begin

		if i > row  then begin
			item.note:= Module.Patterns[pattern].notes[i - 1, channel];
		end else item.note:= emptynote;

		item.prevnote:= Module.Patterns[pattern].notes[i, channel];
		item.pattern:= pattern;
		item.row:= i;
		item.channel:= channel;
		c.arrayOfNotes[i - row]:= item;
	end;

	undoCollectionPush(c);

end;


procedure TTracker.collectShiftInsert(pattern, row: longint);
var
	item : TcollectionItim;
	c : Tcollection;
	i : longint;
	ch : longint;

begin
	
	setlength(c.arrayOfNotes, (Module.Patterns[pattern].RowsCount - row) *  Module.NumberOFChannels);

	for ch:= 1 to Module.NumberOFChannels do
		for i:= row to Module.Patterns[pattern].RowsCount - 1 do begin

			if i > row  then begin
				item.note:= Module.Patterns[pattern].notes[i - 1, ch];
			end else item.note:= emptynote;

			item.prevnote:= Module.Patterns[pattern].notes[i, ch];
			item.pattern:= pattern;
			item.row:= i;
			item.channel:= ch;
			c.arrayOfNotes[(i - row) + ((Module.Patterns[pattern].RowsCount - row) * (ch - 1))]:= item;
		end;

	undoCollectionPush(c);

end;


procedure TTracker.UnDo;
var
	item : Tcollection;
	i : longint;

begin

	if length(undoCollection) = 0 then exit;
	
	item:= undoCollectionPop;
	redoCollectionPush(item);

	if length(item.arrayOfNotes) = 0 then begin
		
		Module.Patterns[item.singlenote.Pattern].notes[item.singlenote.Row, item.singlenote.Channel]:= item.singlenote.prevnote;

	end else begin
	
		for i:= 0 to length(item.arrayOfNotes) - 1 do begin
			Module.Patterns[item.arrayOfNotes[i].Pattern].notes[item.arrayOfNotes[i].Row, item.arrayOfNotes[i].Channel]:= item.arrayOfNotes[i].prevnote;
		end;

	end;
	
end;


procedure TTracker.ReDo; 
var
	item : Tcollection;
	i : longint;
begin

	if length(redoCollection) = 0 then exit;
	
	item:= redoCollectionPop;
	undoCollectionPush(item);

	if length(item.arrayOfNotes) = 0 then begin
		Module.Patterns[item.singlenote.Pattern].notes[item.singlenote.Row, item.singlenote.Channel]:= item.singlenote.note;
	end else begin
		for i:= 0 to length(item.arrayOfNotes) - 1 do begin
			Module.Patterns[item.arrayOfNotes[i].Pattern].notes[item.arrayOfNotes[i].Row, item.arrayOfNotes[i].Channel]:= item.arrayOfNotes[i].note;
		end;

	end;
	
end;