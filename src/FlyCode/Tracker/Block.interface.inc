
procedure handleBlock;
procedure DrawBlock;

procedure movePatternLeftWhileSelectingBlock;
procedure movePatternRightWhileSelectingBlock;
procedure movePatternUpWhileSelectingBlock;	
procedure movePatternDownWhileSelectingBlock;	

function SelectingWithMouse: boolean;
procedure SelectingWithKeyboard;

procedure HandleSelectBlock;

procedure copyBlock;
procedure pasteBlock;
procedure cutBlock;
procedure selectTrackBlock;

procedure MouseInDrawSlot(var row, column: longint);
procedure convert2realSlot(columnSlot, RowSlot: longint);
procedure startSelection(columnSlot, rowSlot: longint);	

procedure getX1Y1X2Y2ofSlot(row, column: longint; var x1, y1, x2, y2: longint);

procedure convertDrawSlot2realSlot;

procedure convertRealSlot2DrawSlot(row, column: longint; var y, x: longint);

procedure rebaseSelection;
procedure clearSelection;

var
	selectedPattern : longint;

	slotX1, slotY1, slotX2, slotY2 : longint;

	curDrawRowSlot, curDrawColumnSlot : longint;

	curRowSlot, curColumnSlot : longint;

	drawSelection : boolean;

	isInSelection : boolean;

	wasSelectingWithKeyboard : boolean;
	wasSelectingWithMouse : boolean;

	isSelecting : boolean;

	selection : array of array of Tnote;
	blockWidth, blockHeight : longint;


	startSelect : boolean;

	selectionStartX, selectionStartY : longint;

	blockCopyed : boolean;

	blockButtonsEnabled : boolean;

	oldTime : qword;

	copyBlockWidth, copyBlockHeight : longint;

procedure BuildBlockButtons;
procedure EnableBlockButtons(enable: boolean);

var
	TextFieldBlockText : TtuiTextField;
	ButtonCopyBlock : TtuiButton;
	ButtonCutBlock : TtuiButton;
	ButtonPasteBlock : TtuiButton;
	ButtonSelectTrackBlock : TtuiButton;

procedure execProcButtonCopyBlock(const param: string);
procedure execProcButtonCutBlock(const param: string);
procedure execProcButtonPasteBlock(const param: string);
procedure execProcButtonSelectTrackBlock(const param: string);