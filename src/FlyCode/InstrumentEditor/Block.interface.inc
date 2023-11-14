
var
	selectedBlockStart : longint;
	selectedBlockEnd : longint;
	
	drawSelectedBlockStart : longint;
	drawSelectedBlockEnd : longint;

	startSelectingBlockStart : boolean;
	startSelectingBlockStartOnce : boolean;
	allowSelectBlock : boolean;
	selectedBlockReset : boolean;

procedure selectBlock;
procedure drawBlock;
procedure getBlockDrawLeftRightPos;	


procedure doShowSelectedWave;
procedure execProcShowSelectedWave(const param: string);

procedure doZoomOutWave;
procedure execProcZoomOutWave(const param: string);

procedure doRangeAllWave;
procedure execProcRangeAllWave(const param: string);	

procedure doShowAllWave;
procedure execProcShowAllWave(const param: string);	