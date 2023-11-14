{$MODE OBJFPC}{$H+}
unit theTracker;
interface
uses 
    sysutils, strutils, iostream, classes, sockets,
    tools, vipgfx, myTTF,
    TrackerEngine, TralalaPlayer, loaders, loaderit,
    tui.Core, tui.Button, tui.ScrollBarHorizontal, tui.MiddleScrollBox2Entries,
    tui.TextField, tui.SelectBox, tui.SelectableImage, tui.EditField, tui.CheckBox, tui.EditableSelectBoxNumbered,
    tui.ButtonUP, tui.ButtonDOWN, tui.MenuVertical, tui.Image,
    tui.Dialog.LoadFile, tui.Dialog.SaveFile, tui.Dialog.MessageBox,
    Note2Str,
    theTheme, theMain, theMenu, 
    theInstrumentSelector, thePatternSelector,
    connection, packetID;

type
    cursorMode = (note, instrument1, instrument2, volume1, volume2, effect1, effect2, effect3);

    TTracker = class
        public
            PatternEditorFont : ttfFont;
            
            CurrentPlaying : boolean;
            CurrentRow : longint;
            
            
            CurrentGlobalVolume : Integer;
            CurrentPlayedTime : Integer;
            CurrentPatternLength : Integer;
            CurrentNoteAdd : Integer;

            CurrentFreeChannel : Integer;

            currentChannel : Integer;
            currentChannelMode : cursorMode;

            


            
            TrackerInEditMode : boolean;

            MainPanel : TtuiBox;


            constructor Create;
            destructor Destroy; override;

            procedure build;
            procedure reload(zap : boolean);

            procedure update;

            
        var
            InstrumentSelector : TInstrumentSelector;
            PatternSelector : TPatternSelector;
            MainMenu:TMainMenu;

            {$I ./MainPanel.interface.inc}
            {$I ./PatternEditor.interface.inc}
            {$I ./ChannelVisualizer.interface.inc}
            {$I ./MoveCursor.interface.inc}
            {$I ./Transpose.interface.inc}
            {$I ./AdvancedEdit.interface.inc}
            {$I ./Block.interface.inc}
            {$I ./UndoRedo.interface.inc}
            {$I ./Networking.interface.inc}
            {$I ./Piano.interface.inc}


        private

            Module : TModule;
            PlayerState : TPlayerState;
            FramesSinceLastTick : Integer;
    end;

    

var
    Tracker : TTracker;
   



implementation
uses networking, GeneralMIDI;


constructor TTracker.Create;
begin

    TrackerTUI:= TtuiTUI.Create(vscreen,'');
    TrackerTUI.mainFont:= mainFont;
    PatternEditorFont:= mainFont;
    MainMenu:= TMainMenu.Create(TrackerTUI);

end;


destructor TTracker.Destroy;
begin

    MainMenu.Free;
    TrackerTUI.processFinalMessages;
    TrackerTUI.Free;

    freeimage(ChannelImage0);
    freeimage(ChannelImage1);
    freeimage(ChannelImage2);
    freeimage(ChannelImage3);
    freeimage(vuMetersImage);

end;


procedure TTracker.build;
begin

    CurrentGlobalVolume:= 64;
    CurrentOctave:= 4;
    CurrentChannel:= 1;

    MainPanel:= TtuiBox.create(TrackerTUI, 0, 18, 1280, 200, 'TrackerMainPanel', tuiBoxStatic);
    MainPanel.ThemeBox:= LoadThemeBox;
    MainPanel.ThemeBox.BackgroundColor:= Theme_Tracker_MainPanel_BackgroundColor;
    TrackerTUI.addBox(MainPanel);

    PatternSelector:= TPatternSelector.Create(MainPanel);
    PatternSelector.callReload:= @reloadPatternEditor;
    PatternSelector.buildPatternSelector;
    PatternSelector.reloadPatternSelector(0);


    buildScrollbar;
    reloadScrollbar;

    reloadPatternEditor('');


    buildChannelVisualizer;

    buildMainPanel;
    reloadMainPanel;

    buildVUmeters;

end;


procedure TTracker.reload(zap: boolean);
begin

    PatternSelector.reloadPatternSelector(CurrentOrder);
    reloadScrollbar;
    reloadPatternEditor('');
    instrumentSelector.reloadInstrumentSelector(zap);
    reloadMainPanel;
    reloadChannelVisualizer;
    playPatternOnly:= false;

end;


{$I ./MainPanel.implementation.inc}
{$I ./MoveCursor.implementation.inc}
{$I ./PatternEditor.implementation.inc}
{$I ./ChannelVisualizer.implementation.inc}
{$I ./Transpose.implementation.inc}
{$I ./AdvancedEdit.implementation.inc}
{$I ./Block.implementation.inc}
{$I ./UndoRedo.implementation.inc}
{$I ./Networking.implementation.inc}
{$I ./Piano.implementation.inc}


procedure TTracker.update;
begin

    if justChanged then begin
        justChanged:= false;
        instrumentSelector.reloadInstrumentSelector(false);
        instrumentSelector.onInstrumentSelect:= nil;
    end;

    if not TrackerTUI.drawonly then HandleMainKeys;

    PatternEditor;
    

        if playPatternOnly then begin
            if currentOrder <> oldOrder then begin
                tralalaEngine.PlaySongFromOrder(oldOrder);
                currentOrder:= oldOrder;
            end;
        end else begin
           PatternSelector.updateOrder;
        end;


    updateChannelVisualizer;
    updateVUMeters;
   
    TrackerTUI.update;
end;


begin
end.