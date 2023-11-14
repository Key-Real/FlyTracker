{$MODE OBJFPC}{$H+}
unit theInstrumentEditor;
interface
uses 
    sysutils, strutils, iostream, classes, math, sockets,
    tools, vipgfx, myTTF,
    TrackerEngine, TralalaPlayer, loaders, loaderit, note2str,
    tui.Core, tui.Button, tui.ScrollBarHorizontal, tui.MiddleScrollBox2Entries, tui.TextField,
    tui.SelectBox, tui.SelectableImage, tui.EditField, tui.CheckBox, tui.EditableSelectBoxNumbered, tui.Line,
    tui.ButtonUP, tui.ButtonDOWN, tui.MenuVertical, tui.Image, tui.RadioButton, tui.RadioButtonGroup, tui.TextBox,
    tui.Dialog.LoadFile, tui.Dialog.SaveFile, tui.Dialog.MessageBox,
    theTheme, theMain, theMenu, networking, connection, packetID,
    theInstrumentSelector;

type

	TInstrumentEditor = class

		module : TModule;
		PlayerState : TPlayerState;
        FramesSinceLastTick : Integer;

        MainMenu : TMainMenu;

    	InstrumentSelector : TInstrumentSelector;


        {$I ./PanelTop.interface.inc}
        {$I ./PanelBottom.interface.inc}
        {$I ./Envelope.interface.inc}
		{$I ./WaveEditor.interface.inc}
		{$I ./Toucher.interface.inc}
		{$I ./Block.interface.inc}
		{$I ./PianoKeys.interface.inc}
		{$I ./Samples.interface.inc}
		{$I ./Mapping.interface.inc}
		{$I ./Networking.interface.inc}
		

		constructor create;
		destructor Destroy; override;

		procedure build;

		procedure update;

	end;

var
	InstrumentEditor : TInstrumentEditor;

implementation


{$I ./PanelTop.implementation.inc}
{$I ./PanelBottom.implementation.inc}
{$I ./Envelope.implementation.inc}
{$I ./WaveEditor.implementation.inc}
{$I ./Toucher.implementation.inc}
{$I ./Block.implementation.inc}
{$I ./PianoKeys.implementation.inc}
{$I ./Samples.implementation.inc}
{$I ./Mapping.implementation.inc}
{$I ./Networking.implementation.inc}


constructor TInstrumentEditor.Create;
begin
	
	InstrumentEditorTUI:= TtuiTUI.Create(vscreen, '');
	InstrumentEditorTUI.mainFont:= mainFont;
	MainMenu:=TMainMenu.Create(InstrumentEditorTUI);

end;

destructor TInstrumentEditor.Destroy;
begin

	freeImage(EnvelopeImage);
	freeImage(ImageWaveStyle1Sprite);
	freeImage(ImageWaveStyle1SpriteOver);
	freeImage(ImageWaveStyle2Sprite);
	freeImage(ImageWaveStyle2SpriteOver);
	freeImage(ImageWaveStyle3Sprite);
	freeImage(ImageWaveStyle3SpriteOver);
	freeImage(ImageWaveStyle4Sprite);
	freeImage(ImageWaveStyle4SpriteOver);
	
	MainMenu.Free;

    InstrumentEditorTUI.processFinalMessages;
    InstrumentEditorTUI.Free;

end;


procedure TInstrumentEditor.build;
begin
	
	buildBottomRightPanel;
	buildTopPanel;
	buildBottomLeftPanel;

	buildEnvelopePanel;
	BuildPianoKeys;
	buildSamples;
	buildMapping;
	
	buildScrollBar;
	
	currentEnvelopMode:=1;
	
   	buildEnvelopeNodes;

end;


procedure TInstrumentEditor.reloadInstrumentEditor;
begin

	reloadTopPanel;
	reloadBottomPanel;
	reloadScrollBar;
	buildWave;
	reloadSamples;
	
	if currentEnvelopMode = 1 then execProcButtonVolume('');
	if currentEnvelopMode = 2 then execProcButtonPanning('');
	if currentEnvelopMode = 3 then execProcButtonPitch('');
	if currentEnvelopMode = 4 then execProcButtonMapping('');

end;


procedure TInstrumentEditor.execProcOnInstrumentSelect(const param: string);
begin

	reloadInstrumentEditor;

end;


procedure TInstrumentEditor.update;
begin

	if justChanged then begin
		tralalaEngine.StopPlaying;
		justChanged:= false;	

		instrumentSelector.reloadInstrumentSelector(false);
		instrumentSelector.onInstrumentSelect:= @execProcOnInstrumentSelect;

		reloadInstrumentEditor;

		allowPianoKeys:= true;
	end;

	playSample;

	updateWaveEditor;

	updateEnvelope;


	fastfill(PianoImage.data, PianoImage.width * PianoImage.height, $ff000000);
	drawPianoWhiteKeys;
	updatePianoWhiteKeys;
	drawPianoBlackKeys;
	updatePianoBlackKeys;
//	drawPianoSamples;


	InstrumentEditorTUI.update;

end;



begin
end.