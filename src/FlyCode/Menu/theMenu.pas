{$MODE OBJFPC} {$H+}
unit theMenu;
interface
uses 
    {$IFDEF UNIX}cthreads,{$ENDIF}
    tools, vipgfx, myTTF,
    sysutils, crt, classes, math,
    TrackerEngine, TralalaPlayer, Loaders, Endian,
    theMain, nettools, processbox,
    tui.Core, tui.Button, tui.TextField, tui.MenuHorizontal, tui.MenuVertical, tui.TextBox, tui.CheckBox, tui.RadioButtonGroup, tui.RadioButton, tui.EditField,
    tui.Dialog.LoadFile, tui.Dialog.SaveFile, tui.Dialog.MessageBox;


type    

    TMainMenu = class
        MenuTUI : TtuiTUI;

        {$I ./Horizontal.interface.inc}
        {$I ./File.interface.inc}
        {$I ./Song.interface.inc}
        {$I ./Help.interface.inc}
        {$I ./Connect.interface.inc}
        
        private
            Module : TModule;
            PlayerState : TPlayerState;
            FramesSinceLastTick : Integer;
    end;


const 

    inMenuItem : boolean = false;


var
    save2wave : boolean;
    retrieveIP : boolean;
    waveFileName : string;
    myExternalIP : string;

    procedure dosave2wave;
    procedure doretrieveIP;


implementation
uses theTracker, theInstrumentEditor, theTheme;

{$I ./Horizontal.implementation.inc}
{$I ./File.implementation.inc}
{$I ./Song.implementation.inc}
{$I ./Help.implementation.inc}
{$I ./Connect.implementation.inc}

var
    buf: array [0..44100 - 1, 0..1] of SmallInt;

    theSave2WaveTruncMessageBox : TtuiDialogMessageBox;

{$notes off}
procedure PlayModuleToWav(AModule: TModule; OutStream: TStream; ASilent: Boolean);
const
    WavHeader: array [0..43] of Byte =
    ($52, $49, $46, $46, $24, $00, $00, $00, $57, $41, $56, $45, $66, $6d, $74, $20,
     $10, $00, $00, $00, $01, $00, $02, $00, $44, $AC, $00, $00, $10, $B1, $02, $00,
     $04, $00, $10, $00, $64, $61, $74, $61, $00, $00, $00, $00);
    PlaybackLengthLimit = 15 * 60;  { 15 minutes }

var
    PlayerState : TPlayerState;
    Mixer : TMixer = nil;
    WavBytes : Integer;
    BytesToDo : Integer;
    SamplingRateBytes : Integer;
    BlockAlign : Word;
    BitsW : Word;
    NumChannelsW : Word;
    fmt : TPCMFormat;
    Bits : byte;
    NumChannels : byte;
    SamplingRate : word;
    RampLength : Integer;

begin

    Bits:= 16;
    NumChannels:= 2;
    SamplingRate:= 44100;
    RampLength:= 5000;

  PlayerState:= TPlayerState.Create(AModule, 0);
  try
    
    case Bits of
      32: fmt:= pcmfS32LE;
      24: fmt:= pcmfS24LE;
      16: fmt:= pcmfS16LE;
      8: fmt:= pcmfU8;
    end;

    PlayerState.InitPlaySong(AModule);
    Mixer:= CDefaultMixer.Create;
    Mixer.SetOutputPCMFormat(fmt, NumChannels);
    Mixer.SetSamplingRate(SamplingRate);
    Mixer.SetVolumeRampLength(RampLength);

    OutStream.WriteBuffer(WavHeader, SizeOf(WavHeader));
    WavBytes:= 0;

    repeat

      BytesToDo:= Min(PlayerState.TickRemainingFrames * Mixer.BytesPerFrame, SizeOf(buf));

      if BytesToDo = 0 then
        BytesToDo:= PlayerState.FramesPerTick * Mixer.BytesPerFrame;

      Mixer.MixData(PlayerState, @buf, BytesToDo, 0, nil);
    
      if PlayerState.ModuleTickPosition.LoopCount = 0 then begin
        Inc(WavBytes, BytesToDo);
        OutStream.WriteBuffer(buf, BytesToDo);
      end;

      if (WavBytes div (Mixer.BytesPerFrame * SamplingRate)) >= PlaybackLengthLimit then begin

        if not ASilent then begin
                        
            if assigned(theSave2WaveTruncMessageBox) then freeandnil(theSave2WaveTruncMessageBox);
            theSave2WaveTruncMessageBox:=TtuiDialogMessageBox.Create(@theSave2WaveTruncMessageBox,trackerTUI,'The module is either looped or longer than 15 minutes. It has been truncated to 15 minutes.');

        end;

        break;

      end;

    until PlayerState.ModuleTickPosition.LoopCount > 0;

    WavBytes:= Integer(LittleEndian(DWord(WavBytes)));
    OutStream.Seek(40, soFromBeginning);
    OutStream.WriteBuffer(WavBytes, 4);
    Inc(WavBytes, $24);
    OutStream.Seek(4, soFromBeginning);
    OutStream.WriteBuffer(WavBytes, 4);
    SamplingRateBytes:= Integer(LittleEndian(DWord(SamplingRate)));
    NumChannelsW:= LittleEndian(Word(NumChannels));
    OutStream.Seek(22, soFromBeginning);
    OutStream.WriteBuffer(NumChannelsW, 2);
    OutStream.Seek(24, soFromBeginning);
    OutStream.WriteBuffer(SamplingRateBytes, 4);
    SamplingRateBytes:= Integer(LittleEndian(DWord(SamplingRate * Mixer.BytesPerFrame)));
    OutStream.Seek(28, soFromBeginning);
    OutStream.WriteBuffer(SamplingRateBytes, 4);
    BlockAlign:= LittleEndian(Word(Mixer.BytesPerFrame));
    OutStream.Seek(32, soFromBeginning);
    OutStream.WriteBuffer(BlockAlign, 2);
    BitsW:= LittleEndian(Word(Bits));
    OutStream.Seek(34, soFromBeginning);
    OutStream.WriteBuffer(BitsW, 2);
  finally
    PlayerState.Free;
    Mixer.Free;    
  end;

end;
{$notes on}


procedure dosave2wave;
var
    OutStream : TFileStream = nil;
    module : TModule;
   

begin
    drawProcessBox;

    tralalaEngine.StopPlaying;

    OutStream:= TFileStream.Create(ChangeFileExt(waveFileName, '.wav'), fmCreate);
    
    tralalaEngine.Lock_Module_ReadOnly(Module);

        PlayModuleToWav(module, OutStream, False);      

    tralalaEngine.Unlock_Module_ReadOnly;


   OutStream.Free;

end;


procedure doRetrieveIP;
begin

    drawProcessBox;

    myExternalIP:= GetExternalIP;

    Tracker.MainMenu.getIPfromDNS;

    Tracker.MainMenu.EditFieldOwnIP.reloadText(myExternalIP);
end;




begin
end.
