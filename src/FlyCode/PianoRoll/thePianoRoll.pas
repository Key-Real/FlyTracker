{$MODE OBJFPC}{$H+}
unit thePianoRoll;
interface
uses 
    sysutils, strutils, iostream, classes, math,
    tools, vipgfx, myTTF,
    TrackerEngine, TralalaPlayer, loaders, loaderit, note2str,
    tui.Core,
    theTheme, theMain, theMenu, theInstrumentSelector, thePatternSelector; 


type

	TPianoRoll = class

		module : TModule;
		PlayerState : TPlayerState;
        FramesSinceLastTick : Integer;

        MainMenu : TMainMenu;

        MainPanel : TtuiBox;

        InstrumentSelector : TInstrumentSelector;


        constructor Create;
		destructor Destroy; override;

		procedure build;

		procedure update;

		{$I ./MainPanel.interface.inc}
		{$I ./Editor.interface.inc}

    end;


var
	PianoRoll : TPianoRoll;

implementation

{$I ./MainPanel.implementation.inc}
{$I ./Editor.implementation.inc}

constructor TPianoRoll.Create;
var 
	i : dword;
begin

	PianoRollTUI:= TtuiTUI.Create(vscreen, '');
	PianoRollTUI.mainFont:= mainFont;
	MainMenu:= TMainMenu.Create(PianoRollTUI);

	randseed:= 1;
	for i:=1 to 99 do InstrumentColor[i]:= $ff000000 + random($ffffff);

end;


destructor TPianoRoll.Destroy;
begin
	MainMenu.Free;
	PatternSelector.Free;

    PianoRollTUI.processFinalMessages;
    PianoRollTUI.Free;
end;


procedure TPianoRoll.build;
begin

	MainPanel:= TtuiBox.create(PianoRollTUI, 0, 18, 1280, 3 * 26 + 2 + 13, 'PianoRollMainPanel', tuiBoxStatic);
    MainPanel.ThemeBox:= LoadThemeBox;
    MainPanel.ThemeBox.BackgroundColor:= Theme_Tracker_MainPanel_BackgroundColor;
    PianoRollTUI.addBox(MainPanel);

    buildMainPanel;

end;


procedure TPianoRoll.update;
begin
	updateEditor;
	PatternSelector.updateOrder;
	PianoRollTUI.update;
end;




begin
end.