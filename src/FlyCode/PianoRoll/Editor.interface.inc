type
	TGrid = record
		instrument : longint;
		continue : boolean;
		channel : longint;
	end;

 var

 	instrumentColor : array [1..99] of dword;

 	grid : array [0..88,0..64] of TGrid;

 	procedure clearGrid;
 	procedure fillGrid;
 	procedure displayGrid;

	procedure updateEditor;