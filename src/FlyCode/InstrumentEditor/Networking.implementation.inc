procedure TInstrumentEditor.netSendRadioButtonLoopTypeNoLoop;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;
    
    buf[0]:= 0;

    sendTCP(IDRadioButtonLoopTypeNoLoop, buf);

end; 


procedure TInstrumentEditor.netGetRadioButtonLoopTypeNoLoop;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupLoopType.uncheckAll;

    RadioButtonLoopTypeNoLoop.checked:= true;

    doRadioButtonLoopType;

end;


procedure TInstrumentEditor.netSendRadioButtonLoopTypeForwardLoop;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;
    
    buf[0]:= 0;

    sendTCP(IDRadioButtonLoopTypeForwardLoop, buf);

end; 


procedure TInstrumentEditor.netGetRadioButtonLoopTypeForwardLoop;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupLoopType.uncheckAll;

    RadioButtonLoopTypeForward.checked:= true;

    doRadioButtonLoopType;
    
end;


procedure TInstrumentEditor.netSendRadioButtonLoopTypePingPongLoop;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;
    
    buf[0]:= 0;

    sendTCP(IDRadioButtonLoopTypePingPongLoop, buf);

end; 


procedure TInstrumentEditor.netGetRadioButtonLoopTypePingPongLoop;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupLoopType.uncheckAll;

    RadioButtonLoopTypePingPong.checked:= true;

    doRadioButtonLoopType;
    
end;


procedure TInstrumentEditor.netSendRadioButtonSampleBits8;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonSampleBits8, buf);

end; 


procedure TInstrumentEditor.netGetRadioButtonSampleBits8;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupSampleBits.uncheckAll;
    RadioButtonSampleBits8.checked:= true;

    doRadioButtonSampleBits8;

end;


procedure TInstrumentEditor.netSendRadioButtonSampleBits16;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonSampleBits16, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonSampleBits16;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupSampleBits.uncheckAll;
    RadioButtonSampleBits16.checked:= true;

    doRadioButtonSampleBits16;

end;


procedure TInstrumentEditor.netSendRadioButtonSampleMono;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonSampleMono, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonSampleMono;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
	
	RadioButtonGroupSampleMonoStereo.uncheckAll;
    RadioButtonSampleMono.checked:= true;

    doRadioButtonSampleMono;

end;


procedure TInstrumentEditor.netSendRadioButtonSampleStereo;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonSampleStereo, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonSampleStereo;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupSampleMonoStereo.uncheckAll;
    RadioButtonSampleStereo.checked:= true;

    doRadioButtonSampleStereo;

end;


procedure TInstrumentEditor.netSendRadioButtonWaveStyle1;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonWaveStyle1, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonWaveStyle1;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupWaveStyle.uncheckAll;
    RadioButtonWaveStyle1.checked:= true;

    doRadioButtonWaveStyle1;

end;


procedure TInstrumentEditor.netSendRadioButtonWaveStyle2;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonWaveStyle2, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonWaveStyle2;	
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupWaveStyle.uncheckAll;
    RadioButtonWaveStyle2.checked:= true;

    doRadioButtonWaveStyle2;

end;


procedure TInstrumentEditor.netSendRadioButtonWaveStyle3;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonWaveStyle3, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonWaveStyle3;	
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupWaveStyle.uncheckAll;
    RadioButtonWaveStyle3.checked:= true;

    doRadioButtonWaveStyle3;

end;


procedure TInstrumentEditor.netSendRadioButtonWaveStyle4;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonWaveStyle4, buf);

end;


procedure TInstrumentEditor.netGetRadioButtonWaveStyle4;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupWaveStyle.uncheckAll;
    RadioButtonWaveStyle4.checked:= true;

    doRadioButtonWaveStyle4;

end;


procedure TInstrumentEditor.netSendRadioButtonWaveStyle5;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonWaveStyle5, buf);
  
end;


procedure TInstrumentEditor.netGetRadioButtonWaveStyle5;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupWaveStyle.uncheckAll;
    RadioButtonWaveStyle5.checked:= true;

    doRadioButtonWaveStyle5;

end;


procedure TInstrumentEditor.netSendRadioButtonLoopNormal;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonLoopNormal, buf);
  
end;


procedure TInstrumentEditor.netGetRadioButtonLoopNormal;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupLoopSustainOrNormal.uncheckAll;
    RadioButtonLoopNormal.checked:= true;

    doRadioButtonLoop;

end;


procedure TInstrumentEditor.netSendRadioButtonLoopSustain;
var 
    buf : array [0..0] of longint;

begin

    if (not isConnected) then exit;

    buf[0]:= 0;
    
    sendTCP(IDRadioButtonLoopSustain, buf);
  
end;


procedure TInstrumentEditor.netGetRadioButtonLoopSustain;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    RadioButtonGroupLoopSustainOrNormal.uncheckAll;
    RadioButtonLoopSustain.checked:= true;

    doRadioButtonLoop;

end;


procedure TInstrumentEditor.netSendButtonUPLoopStart(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonUPLoopStart, buf);

end;


procedure TInstrumentEditor.netGetButtonUPLoopStart;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonLoopStart(buf[0]);

    if netsync then ButtonUPLoopStart.blink;

end;


procedure TInstrumentEditor.netSendButtonDOWNLoopStart(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonDOWNLoopStart, buf);

end;


procedure TInstrumentEditor.netGetButtonDOWNLoopStart;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonLoopStart(buf[0]);

    if netsync then ButtonDOWNLoopStart.blink;

end;


procedure TInstrumentEditor.netSendButtonUPLoopEnd(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonUPLoopEnd, buf);

end;


procedure TInstrumentEditor.netGetButtonUPLoopEnd;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonLoopEnd(buf[0]);

    if netsync then ButtonUPLoopEnd.blink;

end;


procedure TInstrumentEditor.netSendButtonDOWNLoopEnd(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonDOWNLoopEnd, buf);

end;


procedure TInstrumentEditor.netGetButtonDOWNLoopEnd;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonLoopEnd(buf[0]);

    if netsync then ButtonDOWNLoopEnd.blink;

end;


procedure TInstrumentEditor.netSendButtonUPSustainLoopStart(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonUPSustainLoopStart, buf);

end;


procedure TInstrumentEditor.netGetButtonUPSustainLoopStart;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonSustainLoopStart(buf[0]);

    if netsync then ButtonUPSustainLoopStart.blink;

end;


procedure TInstrumentEditor.netSendButtonDOWNSustainLoopStart(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonDOWNSustainLoopStart, buf);

end;


procedure TInstrumentEditor.netGetButtonDOWNSustainLoopStart;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonSustainLoopStart(buf[0]);

    if netsync then ButtonDOWNSustainLoopStart.blink;

end;


procedure TInstrumentEditor.netSendButtonUPSustainLoopEnd(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonUPSustainLoopEnd, buf);

end;


procedure TInstrumentEditor.netGetButtonUPSustainLoopEnd;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonSustainLoopEnd(buf[0]);

    if netsync then ButtonUPSustainLoopEnd.blink;

end;


procedure TInstrumentEditor.netSendButtonDOWNSustainLoopEnd(value: longint);
var 
    buf : array [0..0] of longint;

begin
	
	if (not isConnected) then exit;

    buf[0]:= value;
    
    sendTCP(IDButtonDOWNSustainLoopEnd, buf);

end;


procedure TInstrumentEditor.netGetButtonDOWNSustainLoopEnd;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonSustainLoopEnd(buf[0]);

    if netsync then ButtonDOWNSustainLoopEnd.blink;

end;


procedure TInstrumentEditor.netSendButtonStopWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonStopWave, buf);

end;


procedure TInstrumentEditor.netGetButtonStopWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonStop;

    if netsync then ButtonStop.blink;

end;


procedure TInstrumentEditor.netSendButtonPlayWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonPlayWave, buf);

end;

    
procedure TInstrumentEditor.netGetButtonPlayWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonWave;

    if netsync then ButtonWave.blink;

end;


procedure TInstrumentEditor.netSendButtonWaveRange;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonWaveRange, buf);

end;


procedure TInstrumentEditor.netGetButtonWaveRange;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonRange;

    if netsync then ButtonRange.blink;

end;


procedure TInstrumentEditor.netSendButtonWaveDisplay;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonWaveDisplay, buf);

end;


procedure TInstrumentEditor.netGetButtonWaveDisplay;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonDisplay;

    if netsync then ButtonDisplay.blink;

end;


procedure TInstrumentEditor.netSendButtonWaveVolume;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonWaveVolume, buf);

end;

procedure TInstrumentEditor.netGetButtonWaveVolume;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonVolume;

    if netsync then ButtonVolume.blink;

end;


procedure TInstrumentEditor.netSendButtonXFade;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonXFade, buf);

end;

procedure TInstrumentEditor.netGetButtonXFade;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonXFade;

    if netsync then ButtonXFade.blink;

end;


procedure TInstrumentEditor.netSendButtonCut;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonCut, buf);

end;


procedure TInstrumentEditor.netGetButtonCut;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonCut;

    if netsync then ButtonCut.blink;

end;


procedure TInstrumentEditor.netSendButtonCopy;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonCopy, buf);

end;


procedure TInstrumentEditor.netGetButtonCopy;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonCopy;

    if netsync then ButtonCopy.blink;

end;


procedure TInstrumentEditor.netSendButtonPaste;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonPaste, buf);

end;


procedure TInstrumentEditor.netGetButtonPaste;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonPaste;

    if netsync then ButtonPaste.blink;

end;


procedure TInstrumentEditor.netSendButtonShowSelectedWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netSync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonShowSelectedWave, buf);

end;


procedure TInstrumentEditor.netGetButtonShowSelectedWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doShowSelectedWave;

    if netsync then ButtonShow.blink;

end;


procedure TInstrumentEditor.netSendButtonZoomOutWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonZoomOutWave, buf);

end;


procedure TInstrumentEditor.netGetButtonZoomOutWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doZoomOutWave;

    if netsync then ButtonZoomOut.blink;

end;


procedure TInstrumentEditor.netSendButtonRangeAllWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonRangeAllWave, buf);

end;


procedure TInstrumentEditor.netGetButtonRangeAllWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doRangeAllWave;

    if netsync then ButtonRangeAll.blink;

end;


procedure TInstrumentEditor.netSendButtonShowAllWave;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonShowAllWave, buf);

end;


procedure TInstrumentEditor.netGetButtonShowAllWave;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doShowAllWave;

    if netsync then ButtonShowAll.blink;

end;




procedure TInstrumentEditor.netSendButtonCrop;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonCrop, buf);

end;


procedure TInstrumentEditor.netGetButtonCrop;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonCrop;

    if netsync then ButtonCrop.blink;

end;


procedure TInstrumentEditor.netSendButtonVolume;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonVolume, buf);

end;



procedure TInstrumentEditor.netGetButtonVolume;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonVolumeEnvelope;

    if netsync then ButtonVolumeEnvelope.blink;

end;


procedure TInstrumentEditor.netSendButtonPanning;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonPanning, buf);

end;



procedure TInstrumentEditor.netGetButtonPanning;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonPanningEnvelope;

    if netsync then ButtonPanningEnvelope.blink;

end;


procedure TInstrumentEditor.netSendButtonPitch;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonPitch, buf);

end;



procedure TInstrumentEditor.netGetButtonPitch;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonPitchEnvelope;

    if netsync then ButtonPitchEnvelope.blink;

end;


procedure TInstrumentEditor.netSendButtonMapping;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netsync) then exit;

    buf[0]:= 0;

    sendTCP(IDButtonMapping, buf);

end;



procedure TInstrumentEditor.netGetButtonMapping;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    doButtonMapping;

    if netsync then ButtonMapping.blink;

end;


procedure TInstrumentEditor.netSendEnvelopeToucher(mode, instrument, node, x, y: longint);
var 
    buf : array [0..4] of longint;

begin
    
    if (not isConnected) then exit;

    buf[0]:= mode;
    buf[1]:= instrument;
    buf[2]:= node;
    buf[3]:= x;
    buf[4]:= y;

    sendTCP(IDVolumeEnvelopeToucher, buf);

end;


procedure TInstrumentEditor.netGetEnvelopeToucher;
var 
    buf : array [0..4] of longint;
    aValue : TEnvelopeNode;
begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    aValue.x:= buf[3];
    aValue.y:= buf[4];

    if buf[0] = 1 then Module.instruments[buf[1]].VolumeEnvelope.node[buf[2]]:= aValue;
    if buf[0] = 2 then Module.instruments[buf[1]].PanningEnvelope.node[buf[2]]:= aValue;
    if buf[0] = 3 then Module.instruments[buf[1]].PitchEnvelope.node[buf[2]]:= aValue;

end;


procedure TInstrumentEditor.netSendEnvelopeTouchedNode(node: longint);
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) and (not netSync) then exit;

    buf[0]:= node;

    sendTCP(IDVolumeEnvelopeTouchedNode, buf);

end;


procedure TInstrumentEditor.netGetEnvelopeTouchedNode;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    currentNode:= buf[0];

end;