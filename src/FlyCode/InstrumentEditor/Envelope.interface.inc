var


	currentEnvelopMode : longint;



procedure BuildVolumeEnvelope;
procedure BuildPanningEnvelope;
procedure BuildPitchEnvelope;


var


	EnvelopePanel : TtuiBox;
	EnvelopeImage : gfxImage;
	EnvelopeSelectableImage : TtuiSelectableImage;



	EnvelopeCheckBoxVolume : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxVolume(const param: string);


var
	EnvelopeCheckBoxPanning : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxPanning(const param: string);

var
	EnvelopeCheckBoxPitch : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxPitch(const param: string);




var
	EnvelopePreDefButton1 : TtuiButton;

	EnvelopePreDefButton1VolumeNodes : array of TEnvelopeNode;
	EnvelopePreDefButton1VolumeSustainLoop : boolean;
	EnvelopePreDefButton1VolumeLoop : boolean;
	EnvelopePreDefButton1VolumeSustainLoopStart : longint;
	EnvelopePreDefButton1VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton1VolumeLoopStart : longint;
	EnvelopePreDefButton1VolumeLoopEnd : longint;

	EnvelopePreDefButton1PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton1PanningSustainLoop : boolean;
	EnvelopePreDefButton1PanningLoop : boolean;
	EnvelopePreDefButton1PanningSustainLoopStart : longint;
	EnvelopePreDefButton1PanningSustainLoopEnd : longint;
	EnvelopePreDefButton1PanningLoopStart : longint;
	EnvelopePreDefButton1PanningLoopEnd : longint;

	EnvelopePreDefButton1PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton1PitchSustainLoop : boolean;
	EnvelopePreDefButton1PitchLoop : boolean;
	EnvelopePreDefButton1PitchSustainLoopStart : longint;
	EnvelopePreDefButton1PitchSustainLoopEnd : longint;
	EnvelopePreDefButton1PitchLoopStart : longint;
	EnvelopePreDefButton1PitchLoopEnd : longint;


	procedure EnvelopePreDefButton1LeftClick(const param: string);
	procedure EnvelopePreDefButton1RightClick(const param: string);


var
	EnvelopePreDefButton2 : TtuiButton;

	EnvelopePreDefButton2VolumeNodes : array of TEnvelopeNode;
	EnvelopePreDefButton2VolumeSustainLoop : boolean;
	EnvelopePreDefButton2VolumeLoop : boolean;
	EnvelopePreDefButton2VolumeSustainLoopStart : longint;
	EnvelopePreDefButton2VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton2VolumeLoopStart : longint;
	EnvelopePreDefButton2VolumeLoopEnd : longint;

	EnvelopePreDefButton2PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton2PanningSustainLoop : boolean;
	EnvelopePreDefButton2PanningLoop : boolean;
	EnvelopePreDefButton2PanningSustainLoopStart : longint;
	EnvelopePreDefButton2PanningSustainLoopEnd : longint;
	EnvelopePreDefButton2PanningLoopStart : longint;
	EnvelopePreDefButton2PanningLoopEnd : longint;

	EnvelopePreDefButton2PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton2PitchSustainLoop : boolean;
	EnvelopePreDefButton2PitchLoop : boolean;
	EnvelopePreDefButton2PitchSustainLoopStart : longint;
	EnvelopePreDefButton2PitchSustainLoopEnd : longint;
	EnvelopePreDefButton2PitchLoopStart : longint;
	EnvelopePreDefButton2PitchLoopEnd : longint;


	procedure EnvelopePreDefButton2LeftClick(const param: string);
	procedure EnvelopePreDefButton2RightClick(const param: string);


var
	EnvelopePreDefButton3 : TtuiButton;

	EnvelopePreDefButton3VolumeNodes : array of TEnvelopeNode;
	EnvelopePreDefButton3VolumeSustainLoop : boolean;
	EnvelopePreDefButton3VolumeLoop : boolean;
	EnvelopePreDefButton3VolumeSustainLoopStart : longint;
	EnvelopePreDefButton3VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton3VolumeLoopStart : longint;
	EnvelopePreDefButton3VolumeLoopEnd : longint;

	EnvelopePreDefButton3PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton3PanningSustainLoop : boolean;
	EnvelopePreDefButton3PanningLoop : boolean;
	EnvelopePreDefButton3PanningSustainLoopStart : longint;
	EnvelopePreDefButton3PanningSustainLoopEnd : longint;
	EnvelopePreDefButton3PanningLoopStart : longint;
	EnvelopePreDefButton3PanningLoopEnd : longint;

	EnvelopePreDefButton3PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton3PitchSustainLoop : boolean;
	EnvelopePreDefButton3PitchLoop : boolean;
	EnvelopePreDefButton3PitchSustainLoopStart : longint;
	EnvelopePreDefButton3PitchSustainLoopEnd : longint;
	EnvelopePreDefButton3PitchLoopStart : longint;
	EnvelopePreDefButton3PitchLoopEnd : longint;


	procedure EnvelopePreDefButton3LeftClick(const param: string);
	procedure EnvelopePreDefButton3RightClick(const param: string);



var
	EnvelopePreDefButton4 : TtuiButton;

	EnvelopePreDefButton4VolumeNodes : array of TEnvelopeNode;
	EnvelopePreDefButton4VolumeSustainLoop : boolean;
	EnvelopePreDefButton4VolumeLoop : boolean;
	EnvelopePreDefButton4VolumeSustainLoopStart : longint;
	EnvelopePreDefButton4VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton4VolumeLoopStart : longint;
	EnvelopePreDefButton4VolumeLoopEnd : longint;

	EnvelopePreDefButton4PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton4PanningSustainLoop : boolean;
	EnvelopePreDefButton4PanningLoop : boolean;
	EnvelopePreDefButton4PanningSustainLoopStart : longint;
	EnvelopePreDefButton4PanningSustainLoopEnd : longint;
	EnvelopePreDefButton4PanningLoopStart : longint;
	EnvelopePreDefButton4PanningLoopEnd : longint;

	EnvelopePreDefButton4PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton4PitchSustainLoop : boolean;
	EnvelopePreDefButton4PitchLoop : boolean;
	EnvelopePreDefButton4PitchSustainLoopStart : longint;
	EnvelopePreDefButton4PitchSustainLoopEnd : longint;
	EnvelopePreDefButton4PitchLoopStart : longint;
	EnvelopePreDefButton4PitchLoopEnd : longint;


	procedure EnvelopePreDefButton4LeftClick(const param: string);
	procedure EnvelopePreDefButton4RightClick(const param: string);


var
	EnvelopePreDefButton5 : TtuiButton;

	EnvelopePreDefButton5VolumeNodes : array of TEnvelopeNode;
	EnvelopePreDefButton5VolumeSustainLoop : boolean;
	EnvelopePreDefButton5VolumeLoop : boolean;
	EnvelopePreDefButton5VolumeSustainLoopStart : longint;
	EnvelopePreDefButton5VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton5VolumeLoopStart : longint;
	EnvelopePreDefButton5VolumeLoopEnd : longint;

	EnvelopePreDefButton5PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton5PanningSustainLoop : boolean;
	EnvelopePreDefButton5PanningLoop : boolean;
	EnvelopePreDefButton5PanningSustainLoopStart : longint;
	EnvelopePreDefButton5PanningSustainLoopEnd : longint;
	EnvelopePreDefButton5PanningLoopStart : longint;
	EnvelopePreDefButton5PanningLoopEnd : longint;

	EnvelopePreDefButton5PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton5PitchSustainLoop : boolean;
	EnvelopePreDefButton5PitchLoop : boolean;
	EnvelopePreDefButton5PitchSustainLoopStart : longint;
	EnvelopePreDefButton5PitchSustainLoopEnd : longint;
	EnvelopePreDefButton5PitchLoopStart : longint;
	EnvelopePreDefButton5PitchLoopEnd : longint;


	procedure EnvelopePreDefButton5LeftClick(const param: string);
	procedure EnvelopePreDefButton5RightClick(const param: string);


var
	EnvelopePreDefButton6 : TtuiButton;

	EnvelopePreDefButton6VolumeNodes : array of TenvelopeNode;
	EnvelopePreDefButton6VolumeSustainLoop : boolean;
	EnvelopePreDefButton6VolumeLoop : boolean;
	EnvelopePreDefButton6VolumeSustainLoopStart : longint;
	EnvelopePreDefButton6VolumeSustainLoopEnd : longint;
	EnvelopePreDefButton6VolumeLoopStart : longint;
	EnvelopePreDefButton6VolumeLoopEnd : longint;

	EnvelopePreDefButton6PanningNodes : array of TEnvelopeNode;
	EnvelopePreDefButton6PanningSustainLoop : boolean;
	EnvelopePreDefButton6PanningLoop : boolean;
	EnvelopePreDefButton6PanningSustainLoopStart : longint;
	EnvelopePreDefButton6PanningSustainLoopEnd : longint;
	EnvelopePreDefButton6PanningLoopStart : longint;
	EnvelopePreDefButton6PanningLoopEnd : longint;

	EnvelopePreDefButton6PitchNodes : array of TEnvelopeNode;
	EnvelopePreDefButton6PitchSustainLoop : boolean;
	EnvelopePreDefButton6PitchLoop : boolean;
	EnvelopePreDefButton6PitchSustainLoopStart : longint;
	EnvelopePreDefButton6PitchSustainLoopEnd : longint;
	EnvelopePreDefButton6PitchLoopStart : longint;
	EnvelopePreDefButton6PitchLoopEnd : longint;


	procedure EnvelopePreDefButton6LeftClick(const param: string);
	procedure EnvelopePreDefButton6RightClick(const param: string);








var
	EnvelopeAddButton : TtuiButton;
	procedure calculateNewNode(x1, y1, x2, y2: longint; var x, y: longint);
	procedure drawXYtext;
	procedure execProcEnvlopeAddButton(const param: string);



var
	EnvelopeDelButton : TtuiButton;
	procedure execProcEnvlopeDelButton(const param: string);

var
	EnvelopeCheckBoxSustain : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxSustain(const param: string);

var
	EnvelopeTextFieldSustainPointBegin : TtuiTextField;
	EnvelopeTextFieldSustainPointBeginButtonUP : TtuiButtonUP;
	procedure execProcEnvelopeSustainPointBeginButtonUP(const param: string);
var
	EnvelopeTextFieldSustainPointBeginButtonDOWN : TtuiButtonDOWN;
	procedure execProcEnvelopeSustainPointBeginButtonDOWN(const param: string);

var
	EnvelopeTextFieldSustainPointEnd : TtuiTextField;
	EnvelopeTextFieldSustainPointEndButtonUP : TtuiButtonUP;
	procedure execProcEnvelopeSustainPointEndButtonUP(const param: string);
var
	EnvelopeTextFieldSustainPointEndButtonDOWN : TtuiButtonDOWN;
	procedure execProcEnvelopeSustainPointEndButtonDOWN(const param: string);


var
	EnvelopeCheckBoxLoop : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxLoop(const param: string);

var
	EnvelopeTextFieldLoopStart : TtuiTextField;
	EnvelopeEnvelopeLoopStartButtonUP : TtuiButtonUP;
	procedure execProcEnvelopeLoopPointBeginButtonUP(const param: string);
var
	EnvelopeEnvelopeLoopStartButtonDOWN : TtuiButtonDOWN;
	procedure execProcEnvelopeLoopPointBeginButtonDOWN(const param: string);

var
	EnvelopeTextFieldLoopEnd : TtuiTextField;
	EnvelopeEnvelopeLoopEndButtonUP : TtuiButtonUP;
	procedure execProcEnvelopeLoopPointEndButtonUP(const param: string);
var
	EnvelopeEnvelopeLoopEndButtonDOWN : TtuiButtonDOWN;
	procedure execProcEnvelopeLoopPointEndButtonDOWN(const param: string);

var 
	EnvelopeCheckBoxCarry : TtuiCheckBox;
	procedure execProcEnvelopeCheckBoxCarry(const param: string);

var
    currentNode : longint;
    mouseInNodeToucher : boolean;
    nodeTouched : boolean;
    oldTouchedNode : longint;


    touchedEnvelopePoint : boolean;

    oldNodeX, oldNodeY : longint;
    
procedure BuildEnvelopePanel;
procedure buildEnvelopeNodes;


procedure drawXYscale;

procedure updateEnvelope;

procedure drawNodeToucher(x, y: longint; color: dword);
function isMouseInNodeToucher(x, y: longint): boolean;

procedure getCurXcurY(num: longint; var x, y: longint);

var
	mouseValueY1 : longint;
	mouseValueY2 : longint;
	mouseValueY3 : longint;
function getMouseValueY: longint;

var
	mouseValueX : longint;
function getMouseValueX: longint;

procedure checkEnvelopeCheckBoxes;

function getNodeCount: longint;
function getNodeX(num: longint): longint;
function getNodeY(num: longint): longint;


procedure disableEnvelopePanel;
procedure enableEnvelopePanel;