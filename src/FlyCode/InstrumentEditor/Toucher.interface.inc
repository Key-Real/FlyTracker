
var
	toucherLeftPos : longint;

	isMouseInToucherLeft : boolean;
	movingToucherLeft : boolean;
	
procedure drawToucherLeft;
function isInToucherLeft: boolean;
procedure drawTouchLineLeft;

var	
	toucherRightPos : longint;

	isMouseInToucherRight : boolean;
	movingToucherRight : boolean;
	
procedure drawToucherRight;
function isInToucherRight: boolean;
procedure drawTouchLineRight;
 

procedure updateToucherLeft;
procedure updateToucherRight;

procedure updateToucher;

procedure getToucherLeftRightPos;