procedure TTracker.MouseInDrawSlot(var row, column: longint);
var 
	r, c : longint;

begin

	for c:= 1 to 12 do
		for r:= 0 to 25 do begin
				
				if not isSelecting then begin

					if currentrow < 12 then
					if (((mouseY > 233 ) and (mouseY < ((232 + 12 * 18) - (currentrow * 18) + 1))) and mouseL) or (((mouse2Y > 233 ) and (mouse2Y < ((232 + 12 * 18) - (currentrow * 18) + 1))) and mouse2L)  then begin
						row:= -1;
						column:= -1;
						break;
					end;

					if currentrow > (Module.Patterns[CurrentPattern].RowsCount - 12) then
					if (((mouseY < (232 + 26 * 18) ) and (mouseY > ((232) + ((Module.Patterns[CurrentPattern].RowsCount - currentrow + 12) * 18) + 1))) and mouseL) or (((mouse2Y < (232 + 26 * 18) ) and (mouse2Y > ((232) + ((Module.Patterns[CurrentPattern].RowsCount - currentrow + 12) * 18) + 1))) and mouse2L) then begin
						row:= -1;
						column:= -1;
						break;
					end;

				end;

				
				if (((mouseY >= ((r * 18) + 236))) and mouseL) or (((mouse2Y >= ((r * 18) + 236))) and mouse2L) then begin

					row:= r;
					if (row - 12 + currentrow) > (Module.Patterns[CurrentPattern].RowsCount - 1) then row:= Module.Patterns[CurrentPattern].RowsCount - 1;
					if (row - 12 + currentrow) < 0 then row:= -1;
					
					if (((mouseX > ((c - 1) * (Theme_Tracker_DisplayPattern_ChannelWidth + 2)))) and mouseL) or (((mouse2X > ((c - 1) * (Theme_Tracker_DisplayPattern_ChannelWidth + 2)))) and mouse2L) then begin
						column:= c;
						if column >= Module.NumberOFChannels then column:= Module.NumberOFChannels;
						break;
					end;
				
				end;

		end;

end;





procedure TTracker.convertDrawSlot2realSlot;
begin

	if curDrawRowSlot < 0 then curRowSlot:= 0;

	curRowSlot:= curDrawRowSlot - 12 + currentRow;
	if curRowSlot < 0 then curRowSlot:= 0;
	if curRowSlot > (Module.Patterns[CurrentPattern].RowsCount - 1) then curRowSlot:= Module.Patterns[CurrentPattern].RowsCount - 1;


	curColumnSlot:= curDrawColumnSlot + (mainScrollBar.curValue div 64);
	if curColumnSlot < 0 then curColumnSlot:= 0;

end;


procedure TTracker.convertRealSlot2DrawSlot(row, column: longint; var y, x: longint);
begin

	x:= column - (mainScrollBar.curValue div 64);
	y:= row + 12 - currentRow;

end;



procedure TTracker.movePatternLeftWhileSelectingBlock;
var 
	l : longint;	

begin

	if (((mouseX < 16) and mouseL) or ((mouse2X < 16) and mouse2L)) and ((GetTickCount64 - oldTime) > Theme_Tracker_BlockScroll_Key_TimeOut) then begin
		l:= mainScrollBar.curValue - 64;
		if l < 0 then l:= 0;
		mainScrollBar.setCurValue(l);
		oldTime:= GetTickCount64;
		TrackerTUI.lockedItem:= -2;
	end;

end;



procedure TTracker.movePatternRightWhileSelectingBlock;
var 
	l : longint;

begin
	
	if ((((mouseX > 1264) and (mouseX < 1280) and mouseL)) or (((mouse2X > 1264) and (mouse2X < 1280)) and mouse2L)) and ((GetTickCount64 - oldTime) > Theme_Tracker_BlockScroll_Key_TimeOut) then begin
		l:= mainScrollBar.curValue + 64;
		if l >= mainScrollBar.maxValue then l:= mainScrollBar.maxValue;
		mainScrollBar.setCurValue(l);
		oldTime:= GetTickCount64;
		TrackerTUI.lockedItem:= -2;
	end;

end;


procedure TTracker.movePatternUpWhileSelectingBlock;
var 
	l : longint;

begin

	if (((mouseY < 248) and mouseL) or ((mouse2Y < 248) and mouse2L)) and ((GetTickCount64 - oldTime) > Theme_Tracker_BlockScroll_Key_TimeOut) then begin
		l:= currentRow - 1;
		if l <= 0 then l:= 0;
		currentRow:= l;
		oldTime:= GetTickCount64;
		TrackerTUI.lockedItem:= -2;
	end;

end;


procedure TTracker.movePatternDownWhileSelectingBlock;	
var 
	l : longint;

begin

	if (((mouseY > 690) and mouseL) or ((mouse2Y > 690) and mouse2L)) and ((GetTickCount64 - oldTime) > Theme_Tracker_BlockScroll_Key_TimeOut) then begin
		l:= currentRow + 1;
		if l >= (Module.Patterns[CurrentPattern].RowsCount - 1) then l:= Module.Patterns[CurrentPattern].RowsCount - 1;
		currentRow:= l;
		oldTime:= GetTickCount64;
		TrackerTUI.lockedItem:= -2;
	end;

end;


procedure TTracker.startSelection(columnSlot, rowSlot: longint);
begin

	if not startSelect then begin
		startSelect:= true;
		
		slotX1:= ColumnSlot;
		slotY1:= RowSlot;

		slotX2:= ColumnSlot;
		slotY2:= RowSlot;

		selectionStartX:= slotX1;
		selectionStartY:= slotY1;
	end;

end;


procedure TTracker.convert2realSlot(columnSlot, RowSlot: longint);
begin

	startSelection(ColumnSlot, RowSlot);

	if ColumnSlot < selectionStartX then begin
		slotX1:= ColumnSlot;
		slotX2:= selectionStartX;
	end else begin
		slotX1:= selectionStartX;
		slotX2:= ColumnSlot;
	end;

	if RowSlot < selectionStartY then begin
		slotY1:= RowSlot;
		slotY2:= selectionStartY;
	end else begin
		slotY1:= selectionStartY;
		slotY2:= RowSlot;
	end;

end;


function TTracker.SelectingWithMouse: boolean;
begin	

	result:= false;
	
	if mouseL and is1InPatternEditor then
		if (TrackerTUI.lockedItem <> -2) then
			if (((TrackerTUI.lockedItem <> -1) and (not mainScrollBar.entered)) or (MainPanel.tuiSelf.isInAnyBox) or (not mouseClickable)) then exit;

	if mouse2L and is2InPatternEditor then
		if (TrackerTUI.lockedItem <> -2) then
			if (((TrackerTUI.lockedItem <> -1) and (not mainScrollBar.entered)) or (MainPanel.tuiSelf.is2InAnyBox) or (not mouseClickable)) then exit;


	if (mouseL and is1InPatternEditor) or (mouse2L and is2InPatternEditor) then begin
                 
		
		  
		if isInSelection then begin
			movePatternLeftWhileSelectingBlock;
			movePatternRightWhileSelectingBlock;

			movePatternUpWhileSelectingBlock;	
			movePatternDownWhileSelectingBlock;	
		end;

		MouseInDrawSlot(curDrawRowSlot, curDrawColumnSlot);
		
		if (curDrawRowSlot = -1) and (curDrawColumnSlot = -1) then begin
			result:= true;
			exit;
		end;

		convertDrawSlot2realSlot;

		convert2realSlot(curColumnSlot, curRowSlot);

		wasSelectingWithMouse:= true;

	end;

end;


procedure TTracker.SelectingWithKeyboard;
begin

	if keyboard[KEY_LALT] and (keyboard[KEY_UP] or keyboard[KEY_DOWN] or keyboard[KEY_LEFT] or keyboard[KEY_RIGHT]) then begin
		
		if (currentRow = 0) and (slotY2 = 63) then else
		if (currentChannel = 1) and (slotX2 = Module.NumberOFChannels) then else
			convert2realSlot(lastCursorPositionChannel, lastCursorPositionRow);		


		wasSelectingWithKeyboard:= true;
	end;

end;


procedure TTracker.HandleSelectBlock;
begin

	if TrackerTUI.lockedItem <> -2 then
		if TrackerTUI.lockedItem <> -1 then exit;

	if ((not mouseL) and (not mouse2L)) and isInPatternEditor and isInSelection and wasSelectingWithMouse then begin
		startSelect:= false;
		wasSelectingWithMouse:= false;
		isSelecting:= false;
	end;


	if SelectingWithMouse then exit;
	SelectingWithKeyboard;

	if (((mouseL and isInPatternEditor and (not MainPanel.tuiSelf.isInAnyBox)) or
	   (mouse2L and is2InPatternEditor and (not MainPanel.tuiSelf.is2InAnyBox))) and mouseClickable) or

		(keyboard[KEY_LALT] and keyboard[KEY_UP]) or
		(keyboard[KEY_LALT] and keyboard[KEY_DOWN]) or
		(keyboard[KEY_LALT] and keyboard[KEY_LEFT]) or
		(keyboard[KEY_LALT] and keyboard[KEY_RIGHT]) then begin
				isInSelection:= true;
				drawSelection:= true;
				selectedPattern:= CurrentPattern;
				isSelecting:= true;	
		end;

	if (not keyboard[KEY_LALT]) and wasSelectingWithKeyboard then begin
		startSelect:= false;
		wasSelectingWithKeyboard:= false;
	end;

	if keyboard[KEY_LALT] and keyboard[KEY_C] then selectTrackBlock;
	
	if (mouseR or mouse2R) and isInSelection and isInPatternEditor then begin
		clearSelection;
	end;

end;


procedure TTracker.clearSelection;
begin

	isInSelection:= false;
	drawSelection:= false;
	startSelect:= false;
	wasSelectingWithKeyboard:= false;

end;


procedure TTracker.rebaseSelection;
begin

	if slotX2 >= Module.NumberOFChannels then slotX2:= Module.NumberOFChannels;
	blockWidth:= slotX2 - slotX1;

	if (CurrentPattern > -1) and (slotY2 >= Module.Patterns[CurrentPattern].RowsCount-1) then slotY2:=Module.Patterns[CurrentPattern].RowsCount-1;
	blockHeight:= slotY2 - slotY1;

end;


procedure TTracker.handleBlock;
begin

	HandleSelectBlock;
	rebaseSelection;

	if keyboard[KEY_LALT] and keyboard[KEY_F3] then begin
		cutBlock;
	end;

	if keyboard[KEY_LALT] and keyboard[KEY_F4] then begin
		copyBlock;
	end;

	if keyboard[KEY_LALT] and keyboard[KEY_F5] then begin
		pasteBlock;
	end;

end;


procedure TTracker.getX1Y1X2Y2ofSlot(row, column: longint; var x1, y1, x2, y2: longint);
begin

	x1:= (column - 1) * Theme_Tracker_DisplayPattern_ChannelWidth + 16;
	

	if x1 > (Theme_Tracker_DisplayPattern_ChannelWidth * 11) then x1:= 1280;
	
	if x1 <= 0 then begin
		x1:= 0;
		x2:= 0;
	end else begin		
		x2:= x1 + Theme_Tracker_DisplayPattern_ChannelWidth;
	end;

	if column = 11 then x2:= 1280;
	if column = 1 then x1:= 28;


	y1:= row * 18 + 232 + 2;
	if y1 <= (235- 18)  then begin
		y1:= 235-18;
		y2:= 235-18;
	end else begin
		y2:= y1 + 17;
	end;
	
end;


procedure TTracker.DrawBlock;
var 
	x1, y1, x2, y2 : longint;
	row, column : longint;
	x, y : longint;

begin

	if not drawSelection then exit;

	if isInSelection then
		for row:= slotY1 to slotY2 do
			for column:= slotX1 to slotX2 do begin

				convertRealSlot2DrawSlot(row, column, y, x);

				getX1Y1X2Y2ofSlot(y, x, x1, y1, x2, y2);

				if y1 = Theme_Tracker_TrackerBar_YPosition then 
					drawBarClip(vscreen,x1, y1, x2, y2, Theme_Tracker_BlockColorInMainCursor)
				else
					drawBarClip(vscreen,x1, y1, x2, y2, Theme_Tracker_BlockColor);
			end;

end;


procedure TTracker.copyBlock;
var 
	x, y : longint;
	note : Tnote;
	n : Tnote;

begin

	if not isInSelection then exit;

	if selectedPattern <> CurrentPattern then exit;

	copyBlockWidth:= blockWidth;
	copyBlockHeight:= blockHeight;

	setlength(selection, blockHeight + 1, blockWidth + 1);	

	for x:= 0 to blockWidth do
		for y:= 0 to blockHeight do begin
				note:= Module.Patterns[selectedPattern].notes[slotY1+y,slotX1+x];
				
				if CheckBoxMaskingEnable.isChecked then begin

					n:= emptyNote;
					if CheckBoxNoteC.isChecked then n.note:= note.note;
					if CheckBoxInstrumentNumberC.isChecked then n.instrument:= note.instrument;
					if CheckBoxVolumeColumnC.isChecked then n.volume:= note.volume;
					if CheckBoxEffectDigit1C.isChecked then n.effectType:= note.effectType;
					if CheckBoxEffectDigit23C.isChecked then n.effectParam:= note.effectParam;
					
				end else n:= note;

				selection[y][x]:= n;
			end;

	blockCopyed:= true;

end;


procedure TTracker.pasteBlock;
var 
	x, y : longint;
	note, n, nn :Tnote;

begin

	if not blockCopyed then exit;

	for x:= 0 to copyblockWidth do
		for y:= 0 to copyblockHeight do
			if ((currentRow + y) <= Module.Patterns[CurrentPattern].RowsCount-1) and ((currentChannel + x) <= Module.NumberOFChannels) then begin
				note:= selection[y][x];

				if CheckBoxMaskingEnable.isChecked then begin

					n:= emptyNote;
					
					if CheckBoxNoteP.isChecked then n.note:= note.note;
					if CheckBoxInstrumentNumberP.isChecked then n.instrument:= note.instrument;
					if CheckBoxVolumeColumnP.isChecked then n.volume:= note.volume;
					if CheckBoxEffectDigit1P.isChecked then n.effectType:= note.effectType;
					if CheckBoxEffectDigit23P.isChecked then n.effectParam:= note.effectParam;


					nn:= Module.Patterns[CurrentPattern].notes[currentRow + y, currentChannel + x];

					if CheckBoxNoteT.isChecked then if n.note = NoteNothing then n.note:= nn.note;
					if CheckBoxInstrumentNumberT.isChecked then if n.instrument = 0 then n.instrument:= note.instrument;
					if CheckBoxVolumeColumnT.isChecked then if n.volume.EffectType = vcetNoEffect then n.volume:= note.volume;
					if CheckBoxEffectDigit1T.isChecked then if n.effectType = etNoEffect then n.effectType:= note.effectType;
					if CheckBoxEffectDigit23T.isChecked then if n.effectParam = 0 then n.effectParam:= note.effectParam;					

				end else n:= note;


				Module.Patterns[CurrentPattern].notes[currentRow + y, currentChannel + x]:= n;
			end;

end;


procedure TTracker.cutBlock;
var 
	x, y : longint;

begin

	if not isInSelection then exit;
	
	if selectedPattern <> CurrentPattern then exit;

	for x:= 0 to blockWidth do
		for y:= 0 to blockHeight do
			Module.Patterns[selectedPattern].notes[slotY1+y,slotX1+x]:= emptyNote;

end;


procedure TTracker.selectTrackBlock;
begin

	slotX1:= currentChannel;
	slotY1:= 0;

	slotX2:= currentChannel;
	slotY2:= Module.Patterns[CurrentPattern].RowsCount - 1;

	blockWidth:= slotX2 - slotX1;
	blockHeight:= slotY2 - slotY1;

	isInSelection:= true;
	drawSelection:= true;

	selectedPattern:= CurrentPattern;

end;


procedure TTracker.execProcButtonCopyBlock(const param: string);
begin

	copyBlock;

	netSendButtonCopyBlock;

end;


procedure TTracker.execProcButtonCutBlock(const param: string);
begin

	cutBlock;

end;


procedure TTracker.execProcButtonPasteBlock(const param: string);
begin

	pasteBlock;

	netSendButtonPasteBlock;

end;


procedure TTracker.execProcButtonSelectTrackBlock(const param: string);
begin

	selectTrackBlock;

	netSendButtonSelectTrackBlock;

end;


procedure TTracker.BuildBlockButtons;
var 
	x, y : longint;

begin
	
	x:= 609;
	y:= 143;

	TextFieldBlockText:= TtuiTextField.Create(MainPanel, 'TextField Block', x + 86, y - 20, 'Block');
	TextFieldBlockText.theme:= LoadThemeTextField;
	TextFieldBlockText.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
	MainPanel.addItem(TextFieldBlockText);

	ButtonCopyBlock:= TtuiButton.create(MainPanel, 'Tracker_ButtonCopyBlock', x + 0, y, 100, 28, 'Copy', @execProcButtonCopyBlock);
    ButtonCopyBlock.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCopyBlock);

	ButtonCutBlock:= TtuiButton.create(MainPanel, 'Tracker_ButtonCutBlock', x + 101, y, 100, 28, 'Clear', @execProcButtonCutBlock);
    ButtonCutBlock.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCutBlock);

	ButtonPasteBlock:= TtuiButton.create(MainPanel, 'Tracker_ButtonPasteBlock', x + 0, y + 29, 100, 28, 'Paste', @execProcButtonPasteBlock);
    ButtonPasteBlock.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonPasteBlock);

    ButtonSelectTrackBlock:= TtuiButton.create(MainPanel, 'Tracker_ButtonSlectTrackBlock', x + 101, y + 29, 100, 28, 'Select Track', @execProcButtonSelectTrackBlock);
    ButtonSelectTrackBlock.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonSelectTrackBlock);

    blockButtonsEnabled:= true;
    EnableBlockButtons(true);

end;


procedure TTracker.EnableBlockButtons(enable: boolean);
begin

	TextFieldBlockText.enabled:= enable;
	ButtonCopyBlock.enabled:= enable;
	ButtonCutBlock.enabled:= enable;
	ButtonPasteBlock.enabled:= enable;
	ButtonSelectTrackBlock.enabled:= enable;

end;
