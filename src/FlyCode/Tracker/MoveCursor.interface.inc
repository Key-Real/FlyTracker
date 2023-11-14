public
var
    RightKeyDB : boolean;
    RightKeyStartTimeDB : boolean;
    RightKeyStartTime : qword;
    RightKeyAllow : boolean;
    RightKeyTime : qword;

    LeftKeyDB : boolean;
    LeftKeyStartTimeDB : boolean;
    LeftKeyStartTime : qword;
    LeftKeyAllow : boolean;
    LeftKeyTime : qword;

    UpKeyDB : boolean;
    UpKeyStartTimeDB : boolean;
    UpKeyStartTime : qword;
    UpKeyAllow : boolean;
    UpKeyTime : qword;

    DownKeyDB : boolean;
    DownKeyStartTimeDB : boolean;
    DownKeyStartTime : qword;
    DownKeyAllow : boolean;
    DownKeyTime : qword;

    TabKeyOnce : boolean;
    PageUpOnce, PageDownOnce : boolean;

    lastCursorPositionChannel, lastCursorPositionRow : longint;


    drawCursorChannel : longint;

    moveLeft : boolean;
    moveRight : boolean;


            
    procedure doRightKey;
    procedure handleRightKey;
    procedure doLeftKey;
    procedure handleLeftKey;
    procedure doUpKey;
    procedure handleUpKey;
    procedure doDownKey;
    procedure handleDownKey;
    procedure handleWheel;

    procedure moveCursor;
    procedure drawCursorBar;
    procedure drawCursor;
