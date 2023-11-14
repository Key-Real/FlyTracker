{$MODE OBJFPC} {$H+}
unit theMain;
interface
uses
    tools, vipgfx, myTTF,
    sysutils, classes, math,
    theTheme,
    tui.Core, tui.Dialog.MessageBox,
    TrackerEngine, TralalaPlayer, endian;

type
    TCurrentMode = (
                    modeTracker,
                    modePianoRoll,
                    modeInstrumentEditor
                   );

const
    FlyTrackerVersion = '1.0.0g';

var
    tralalaEngine : TTrackerEngine;
    
    CurrentMode : TCurrentMode;
    justChanged : boolean;

    CurrentInstrument : Integer = 1;
    CurrentSample : Integer;
    CurrentOctave : longint;

    CurrentPattern : longint;
    CurrentOrder : Integer;


    oldOrder : longint;
    playPatternOnly : boolean;


    allowVirtualPiano : boolean;
    PatternEditor_AllowCursor : boolean;
    isInPreviewSample  : boolean;

    mainFont : ttfFont;

    

    playSong : boolean;

    procedure chouseCurrentMode;

    procedure BuildShared;
    procedure closeShared;



var    

    TrackerTUI : TtuiTUI;
    PianoRollTUI : TtuiTUI;
    InstrumentEditorTUI : TtuiTUI;

    netsync : boolean = false;


implementation
uses theTracker, theInstrumentSelector, theInstrumentEditor, thePianoRoll;

var controllPressed : boolean;


procedure BuildShared;
var aBox : TtuiBox;
begin
    aBox:= TrackerTUI.getBoxByName('TrackerMainPanel');
    Tracker.InstrumentSelector:= TInstrumentSelector.Create(trackerTUI, aBox);
    Tracker.InstrumentSelector.buildInstrumentSelector(200 - 2);
    Tracker.InstrumentSelector.reloadInstrumentSelector(true);
    Tracker.instrumentSelector.allowMenuGo2Editor:= true;

    aBox:= PianoRollTUI.getBoxByName('PianoRollMainPanel');
    PianoRoll.InstrumentSelector:= TInstrumentSelector.Create(PianoRollTUI, aBox);
    PianoRoll.InstrumentSelector.buildInstrumentSelector(3 * 26 + 2 + 11);
    PianoRoll.InstrumentSelector.reloadInstrumentSelector(true);
    PianoRoll.instrumentSelector.allowMenuGo2Editor:= true;
    
    aBox:= InstrumentEditorTUI.getBoxByName('InstrumentEditorTopPanel');
    InstrumentEditor.InstrumentSelector:=TInstrumentSelector.Create(InstrumentEditorTUI, aBox);
    InstrumentEditor.InstrumentSelector.buildInstrumentSelector(200 - 2);
    InstrumentEditor.InstrumentSelector.reloadInstrumentSelector(true);
    InstrumentEditor.instrumentSelector.allowMenuGo2Editor:= false;
end;


procedure closeShared;
begin
    Tracker.InstrumentSelector.Free;
    PianoRoll.InstrumentSelector.Free;
    InstrumentEditor.InstrumentSelector.Free;
end;

procedure chouseCurrentMode;
begin

    if keyboard[KEY_LSHIFT] and (keyboard[KEY_LCTRL] or controllPressed) and keyboard[KEY_F1] then begin
                                                                                CurrentMode:= modeTracker;
                                                                                controllPressed:= true;
                                                                                keyboard[KEY_LCTRL]:= false;
                                                                                justChanged:= true;
                                                                                playSong:= false;
                                                                   end else
    if keyboard[KEY_LSHIFT] and (keyboard[KEY_LCTRL] or controllPressed) and keyboard[KEY_F2] then begin
                                                                                CurrentMode:= modePianoRoll;
                                                                                controllPressed:= true;
                                                                                keyboard[KEY_LCTRL]:= false;
                                                                                justChanged:= true;
                                                                                playSong:= false;
                                                                   end else                                                                   
    if keyboard[KEY_LSHIFT] and (keyboard[KEY_LCTRL] or controllPressed) and keyboard[KEY_F4] then begin
                                                                                if CurrentMode = modeTracker then tralalaEngine.StopPlaying;
                                                                                CurrentMode:= modeInstrumentEditor;
                                                                                controllPressed:= true;
                                                                                keyboard[KEY_LCTRL]:= false;
                                                                                justChanged:= true;
                                                                                playSong:= false;
                                                                       end;    
end;


//////////////////////////////////////////////////////////////////////////////////////////////////



begin    
end.