{$MODE OBJFPC}{$H+}
uses
    {$IFDEF UNIX}cthreads,{$ENDIF}
    sysutils,
    tools, vipgfx, myTTF,

    tui.Core, tui.Button, tui.ScrollBarHorizontal, tui.MiddleScrollBox2Entries, tui.Line,
    tui.TextField, tui.SelectBox, tui.SelectableImage, tui.EditField, tui.CheckBox, tui.EditableSelectBoxNumbered,
    tui.ButtonUP, tui.ButtonDOWN, tui.MenuVertical, tui.Image, tui.MenuHorizontal, tui.ProgressBar,
    tui.TextBox, tui.RadioButton, tui.RadioButtonGroup,
    tui.Dialog.LoadFile, tui.Dialog.SaveFile, tui.Dialog.MessageBox,

    TrackerEngine, TralalaPlayer, dev_base, loaders,
    {$IFDEF LINUX}MIDIDriverLinux,{$ENDIF} {$IFDEF WINDOWS}MIDIDriverWindows,{$ENDIF} {$IFDEF DARWIN} MIDIDriverMac,{$ENDIF} GeneralMIDI,
    theMain, theMenu, theInstrumentSelector, theTracker, theInstrumentEditor, thePianoRoll, 
    connection, networking, nettools, netUI, processbox,
    theTheme;



var
    Driver: PAudioDeviceDesc = @AudioDevices[Low(AudioDevices)];

    quitOnESC : boolean = false;
    fullscreen : boolean = true;
    showfps : boolean = false;
    oldMode : TCurrentMode;


procedure SetSoundDriver(const ASoundDriverName: string);
var
  I : Integer;
  SndDrvName : string;
begin
  SndDrvName:= LowerCase(ASoundDriverName);
  for I:= Low(AudioDevices) to High(AudioDevices) do
    if LowerCase(AudioDevices[I].Name) = SndDrvName then begin
      Driver:= @AudioDevices[I];
      exit;
    end;
  Writeln('Unrecognized driver name: ' + ASoundDriverName);
  Halt(1);
end;


procedure ListSoundDrivers;
var I:Integer;
begin
  writeln('Availible Drivers:');
  for I:= Low(AudioDevices) to High(AudioDevices) do Writeln(AudioDevices[I].Name);
end;


var
  parameterParameter : string;
function Parameter(match: string): boolean;
var 
    i, ii : Integer;
    ch : char;
    s : string;
begin
  result:= false;

  for i:=1 to paramcount do begin
    s:= '';
    parameterParameter:= '';
    for ii:=1 to length(ParamStr(i)) do begin
      ch:= ParamStr(i)[ii];
      s:= s + ch;
      if s = match then begin
        result:= true;
        continue;
      end;
      if result then begin
        parameterParameter:= parameterParameter + ch;
      end;
    end;
    if result then exit;
  end;
end;


function ParameterFileName: string;
var 
  i : Integer;
begin
  result:= '';

  for i:=1 to paramcount do begin
      if ParamStr(i)[1] <> '-' then begin
        if exist(ParamStr(i)) then 
          result:= ParamStr(i)
        else result:= '';
        exit;
      end;
  end;

end;


var 
  Module : TModule;

  sharedParameters : TtuiSharedParameters;

  winX, winY : longint;


begin

if Parameter('-help') then begin
  writeln('FlyTracker ver.', FlyTrackerVersion, ' (c) by Key-Real of VIP 2023');
  writeln;
  writeln('-list : list Sound Drivers');
  {$IFDEF LINUX}writeln('-alsa : use ALSA Sound Driver');{$ENDIF}
  writeln('-wavwriter : use wave writer for output');
  writeln('-1 : start in Tracker Mode');
  writeln('-2 : start in PianoRoll Mode');
  writeln('-4 : start in Instument Editor Mode');
  writeln('-ESC : quit on ESCAPE Key');
  writeln('-x : set X window position');
  writeln('-w : window mode');
  writeln('-fps : show fps');
  writeln('-local : connect over local network');
  writeln('-connectto : connect to client');
  writeln('-server : start server');
  writeln('-port : set port');
  writeln('-upnp : connect through uPnP');
  writeln('-pf : connect through Port Forwarding');
  writeln('-hp : connect through Hole Punching');
  halt;
end;

if Parameter('-list') then begin
    ListSoundDrivers;
    halt;
end;

if Parameter('-w') then fullscreen:= false;
if Parameter('-fps') then showfps:= true;



Driver:= nil;
if Parameter('-alsa') then SetSoundDriver('alsa');
if Parameter('-wavwriter') then SetSoundDriver('wavwriter');


currentmode:= modeTracker;
if Parameter('-1') then currentmode:= modeTracker;
if Parameter('-2') then currentmode:= modePianoRoll;  
if Parameter('-4') then currentmode:= modeInstrumentEditor;

if Parameter('-ESC') then quitOnESC:= true;



if Parameter('-connectto') then begin
    isClient:= true;
    if parameterParameter <> '' then serverIP:= parameterParameter;
end else isClient:= false;

if Parameter('-server') then begin
    isClient:= false;
    if parameterParameter <> '' then serverIP:= parameterParameter;
end;

if Parameter('-port') then begin
    serverPort:= strnum(parameterParameter);
end;

if Parameter('-local') then begin
    EstablishConnection(connectLocal);
end;
if Parameter('-upnp') then begin
    EstablishConnection(connectUPnP);
end;
if Parameter('-pf') then begin
    EstablishConnection(connectPortForwarding);
end;
if Parameter('-hp') then begin
    EstablishConnection(connectHolePunching);
end;



pngLoad(mouseCursor, ExtractFilePath(ParamStr(0)) + '/cursor.png');


loadTheme(ExtractFilePath(ParamStr(0)) + '/theme.ini');

try
    tralalaEngine := TTrackerEngine.Create(Driver, nil, true);
except
    on E: TObject do begin
      logWrite('Exception: ' + Exception2String(E));
      halt(2);    
    end;
end;


initTTF;
ttfCreateFont(ExtractFilePath(ParamStr(0)) + '/corbel.ttf', 31, mainFont);


initgfxsystem(1280, 720, fullscreen);
setWindowCaption('FlyTracker ' + FlyTrackerVersion);


if Parameter('-x') then begin
    getGFXwindowPos(winX, winY);
    winX:= strnum(parameterParameter);
    setGFXwindowPos(winX, winY);
end;



if ParameterFileName <> '' then begin
  tralalaEngine.LoadModule(ParameterFileName);
end else begin
  tralalaEngine.Lock_Module_ReadWrite(Module);
    Module.clear;
    Module.order[0]:= 0;
    Module.order[1]:= EndOfSongMarker;
    Module.NumberOfChannels:= 8;
  tralalaEngine.Unlock_Module_ReadWrite;
end;

Tracker:= TTracker.Create;
InstrumentEditor:= TInstrumentEditor.Create;
PianoRoll:= TPianoRoll.Create;
MIDI:= TMIDI.Create;

Tracker.build;
PianoRoll.build;
InstrumentEditor.build;

buildShared;

justChanged:= true;
oldMode:= modeTracker;
sharedParameters.mouseClickTime2Pass:= 0;

if isConnected then begin
    StartNetworking;
    netsync:= true;
end;


StartGeneralMIDI;

repeat

  try
    fastfill(vscreen.data, vscreen.width * vscreen.height, $ff000000);

    chouseCurrentMode;
    if currentmode = modeTracker then begin
      
      if oldMode <> modeTracker then justChanged:= true;
      oldMode:= currentmode;

      TrackerTUI.setSharedParameters(sharedParameters);
      Tracker.update;
      sharedParameters:= TrackerTUI.getSharedParameters;
    end;

    if currentmode = modePianoRoll then begin

      if oldMode <> modePianoRoll then justChanged:= true;
      oldMode:= currentmode;

      PianoRollTUI.setSharedParameters(sharedParameters);
      PianoRoll.update;
      sharedParameters:= PianoRollTUI.getSharedParameters;
    end;

    if currentmode = modeInstrumentEditor then begin

        if oldmode <> modeInstrumentEditor then justChanged:= true;
        oldMode:= currentmode;
        
        InstrumentEditorTUI.setSharedParameters(sharedParameters);
        InstrumentEditor.update;
        sharedParameters:= InstrumentEditorTUI.getSharedParameters;
    end;

 
    ttfPrintStringXY(vscreen, TrackerTUI.MainFont, 1280 - 48, - 1, $ffffffff, TimeToStr(Time));


    if showfps then ttfPrintStringXY(vscreen,TrackerTUI.MainFont, 1280 - 128, 0, $ffffffff, floatstr(gfxFPS) + ' FPS');



    updateNetUI;


    updateGFXsystem;

  
    if isConnected and netsync then begin    
      mouse2X:= originMouseX;
      mouse2Y:= originMouseY;
    end else begin
      mouse2X:= -1;
      mouse2Y:= -1;
    end;


    if save2wave then begin
      save2wave:= false;

      dosave2wave;
    end;


    if retrieveIP then begin
      retrieveIP:= false;

      doRetrieveIP;
    end;


  except
      on E: TObject do begin
        logWrite('Exception: ' + Exception2String(E));
        logWrite('Trying to do an emergency save in the ' + GetUserDir + ' Directory...');
        makeMessage('Trying to do an emergency save in the ' + GetUserDir + ' Directory...');
        tralalaEngine.EmergencySave;
        gfxDone:=true;
        halt;
      end;
  end;

until gfxDone or (quitOnESC and keyboard[KEY_ESCAPE]);



try

  if isConnected then begin
    StopNetworking;
    CloseConnection;
  end;

  finishGFXsystem;
  closeTTF;

  tralalaEngine.Free;

  closeShared;

  Tracker.Free;
  PianoRoll.Free;
  InstrumentEditor.Free;

  freeImage(mouseCursor);

  EndGeneralMIDI

except
      on E: TObject do begin
        logWrite('Exception on closing: ' + Exception2String(E));
      end;
end;

if showfps then ReturnFPSstring;

end.
