{$linkframework AudioToolbox}
{$MODE OBJFPC}
uses MacOSAll,CocoaAll,crt,pasvorbistremor;
 
type
 
    TSoundState = packed record
        done:boolean;
    end;
 
var 

    FOgg: POggVorbis_File; // points to ogg when ov_open is successful
    Ogg: OggVorbis_File;
 
 
procedure auCallback(inUserData:pointer;  queue:AudioQueueRef;  buffer:AudioQueueBufferRef); MWPascal;
var
    SoundState : TSoundState;
    p:pointer;
    numToRead:dword;
    i,n:dword;
    w:int16;
    f:single;
    int:integer;
    arr:array of longint;
begin
   
    SoundState:=TSoundState(inUserData^);
 
 
    buffer^.mAudioDataByteSize := 4096;
   
    numToRead := buffer^.mAudioDataByteSize;
 
    i:=ov_read(FOgg,buffer^.mAudioData,numToRead,nil);
    n:=i;
    repeat
        i:=ov_read(FOgg,pointer(buffer^.mAudioData + n),numToRead-n,nil);
        n:=n+i;
    until n >= buffer^.mAudioDataByteSize;
    
 
    AudioQueueEnqueueBuffer(queue, buffer, 0, nil);
 
end;
 

 
procedure checkError(error:OSStatus);
begin
    if (error <> noErr) then begin
        writeln('Error: ', error);
        halt;
    end;
end;
 
 
var
    auDesc:AudioStreamBasicDescription;
    auQueue:AudioQueueRef;
    auBuffers:array[0..1] of AudioQueueBufferRef;
    soundState:TSoundState;
    err:OSStatus;
    bufferSize:uint32;
    f:file;
    isOK:boolean;
    streamsize:dword;
begin
 
    AssignFile(f, './WorkTheAngles.ogg');
    Reset(f, 1);
    IsOk := ov_test(@f, @Ogg, nil, -1) = 0;
    if IsOk then
        FOgg := @Ogg
    else begin
        FOgg := nil;
        ov_clear(@Ogg);
    end;
    ov_test_open(FOgg);

    streamsize:=ov_raw_total(FOgg, 0);  // the length of the OGG
 
 

    auDesc.mSampleRate := 44100;
    auDesc.mFormatID := kAudioFormatLinearPCM;
    auDesc.mFormatFlags := kLinearPCMFormatFlagIsSignedInteger or kLinearPCMFormatFlagIsPacked;
    auDesc.mBytesPerPacket := 4;
    auDesc.mFramesPerPacket := 1;
    auDesc.mBytesPerFrame := 4;
    auDesc.mChannelsPerFrame := 2;
    auDesc.mBitsPerChannel := 16;
  
   
    // our persistent state for sound playback
    soundState.done:=false;
   
    // most of the 0 and nullptr params here are for compressed sound formats etc.
    err := AudioQueueNewOutput(auDesc, @auCallback, @soundState, nil, nil, 0, auQueue);
    checkError(err);
 
 
    // generate buffers holding at most 1/16th of a second of data
    bufferSize := round(auDesc.mBytesPerFrame * (auDesc.mSampleRate / 16));
    err := AudioQueueAllocateBuffer(auQueue, bufferSize, auBuffers[0]);
    checkError(err);
 
    err := AudioQueueAllocateBuffer(auQueue, bufferSize, auBuffers[1]);
    checkError(err);
 
    // prime the buffers
    auCallback(@soundState, auQueue, auBuffers[0]);
    auCallback(@soundState, auQueue, auBuffers[1]);
 
    // enqueue for playing
    AudioQueueEnqueueBuffer(auQueue, auBuffers[0], 0, nil);
    AudioQueueEnqueueBuffer(auQueue, auBuffers[1], 0, nil);
 
    // go!
    AudioQueueStart(auQueue, nil);
 
 

 
    readln;


    
   
 
    ov_clear(FOgg);

    AudioQueueDispose(auQueue, true);
end.
 