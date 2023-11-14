procedure TPianoRoll.clearGrid;
var x, y : longint;
begin

	for y:=0 to 87 do
		for x:=0 to 63 do begin
			
				grid[y,x].instrument:= 0;
				grid[y,x].continue:= false;
			
		end;
	
end;



procedure TPianoRoll.fillGrid;
var 	
	channel : longint;
	aRow : longint;
	aNote : TnoteValue;
	aInstrument : longint;
	curNote : longint;
	alreadyThere : boolean;
begin

	clearGrid;


	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);
		
		for Channel:= 1 to Module.NumberOFChannels do begin

			for aRow:= 0 to 63 do begin

				aNote:= Module.Patterns[CurrentPattern].notes[aRow,Channel].note;
				
				if aNote <> NoteNothing then begin
					aInstrument:= Module.Patterns[CurrentPattern].notes[aRow,Channel].instrument;	

					grid[aNote,aRow].instrument:= aInstrument;
					grid[aNote,aRow].continue:= false;
					grid[aNote,aRow].channel:= Channel;
					
				end;

			end;
		end;	
		
		for Channel:= 1 to Module.NumberOFChannels do begin
			for aRow:= 1 to 63 do begin
			
				alreadyThere:= false;
				for curNote:=0 to 88 do
					if (grid[curNote,aRow].instrument <> 0) and (grid[curNote,aRow].channel = Channel) then begin
						alreadyThere:= true;									
						break;
					end;

				if not alreadyThere then
					for curNote:=0 to 88 do
							if (grid[curNote,aRow-1].instrument <> 0) and (grid[curNote,aRow-1].channel = Channel) then begin
								grid[curNote,aRow].instrument:= grid[curNote,aRow-1].instrument;
								grid[curNote,aRow].continue:= true;
								grid[curNote,aRow].channel:= grid[curNote,aRow-1].Channel;
							end;
				
						
			end;
		end;

	tralalaEngine.Unlock_ReadOnly;

end;


procedure TPianoRoll.displayGrid;
var 
	x, y : longint;

begin

	for y:=0 to 88 do
		for x:=0 to 63 do begin
			if grid[y,x].instrument > 0 then begin
				if not grid[y,x+1].continue then begin
					drawHlineClip(vscreen, x * 10, x * 10 + 6, 200 + y * 2, instrumentColor[grid[y, x].instrument]);
				end else
					drawHlineClip(vscreen, x * 10, x * 10 + 10, 200 + y * 2, instrumentColor[grid[y, x].instrument]);
			end;
		end;
	
end;

procedure TPianoRoll.updateEditor;
begin
	
	fillGrid;
	displayGrid;

	tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

		if PlayerState.ModuleTickPosition.PlayMode <> TPlayMode.pmStopped then begin			
			drawVlineClip(vscreen, 200, 400, PlayerState.CurrentRow * 10, $ff00ffff);
		end;

	tralalaEngine.Unlock_ReadOnly;

	if keyboard[KEY_LCTRL] then begin
    	tralalaEngine.PlaySongFromOrder(CurrentOrder, 0);
    end;
end;
