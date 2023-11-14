public
    

    startChannel, endChannel : dword;


    procedure reloadPatternEditor(const param: string);
    procedure PatternEditor;
    procedure DisplayPattern;

    function isInPatternEditor: boolean;
    function is1InPatternEditor: boolean;
    function is2InPatternEditor: boolean;

    procedure getStartEndChannel;

var
    selectedChannelNumberMenu : longint;

    procedure processChannelNumberMenu;
    function check4mouseClickChannelNumber: longint;

var
    ChannelMenuVerticalBox : TtuiBox;
    ChannelMenuVertical : TtuiMenuVertical;
    ChannelMenuVerticalClicked : boolean;

    MessageBoxDialog : TtuiDialogMessageBox;

    ChannelPanningBox : TtuiBox;
    TextFieldCannelPanning : TtuiTextField;
    CannelPaningScrollBar : TtuiScrollBarHorizontal;
    ButtonChannelPanningOK : TtuiButton;
    
    procedure execProcChannelPanning(const param: string);
    procedure execProcChannelPanningScrollBar(const param: string);
    procedure execProcChannelPanningOK(const param: string);


    procedure execProcChannelMixdownPattern(const param: string);
    procedure execProcChannelMixdownChannel(const param: string);
    procedure execProcChannelNirvana(const param: string);


var 
    virtualPianoPlayingNote : boolean;
    lastNote : longint;
    currentMIDIkeyPlaing : longint;

    procedure updateTrackerInEditMode;
    function updateEditModeSpecialKeys: boolean;
    procedure updateEditModeNote(key: longint);

    function recordNote(key: longint): TNote;

    function volumeStroke1(vol: TVolumeColumnEffect): TVolumeColumnEffect;
    function volumeStroke2(vol: TVolumeColumnEffect): TVolumeColumnEffect;

    function instrumentStroke1(ins: longint): longint;
    function instrumentStroke2(ins: longint): longint;

    function effectStroke1(eff: TEffectType): TEffectType;
    function effectStroke2(eff: longint): longint;
    function effectStroke3(eff: longint): longint;

    function getNumberFromKeyboard: longint;
    function getEffectFromKeyboard: TEffectType;

    procedure PrintKeyStroke;



var

    keyNoteOldTime : qword;
    keyNoteFirst : boolean;
    keyNoteAfterFirst : boolean;

    procedure processRecordNote;

var

    keyStroke : longint;

    doAdd : boolean;


    
    keySpacePressed : boolean;

    keyControlPressed : boolean;

    keyControlF9Pressed : boolean;
    keyControlF10Pressed : boolean;
    keyControlF11Pressed : boolean;
    keyControlF12Pressed : boolean;

    keyUndoPressed : boolean;
    keyRedoPressed : boolean;

    procedure HandleMainKeys;




type
    TwhoPalys = (VirtualKeyboard, MIDIKeyboard, NETKeyboard);
    TplaySample = record
        isPlaying : boolean;
        channel : longint;
        whoIsPlaying : array [0..2] of boolean;   // 0 - VirtualKeyboard, 1 - MIDI, 2 - NET
    end;

const

    maxKeys = 130;  //  <- refactor this

var
       playingSample : array [0..maxKeys] of TplaySample;

function MoreThanOneNotePlaying: boolean;