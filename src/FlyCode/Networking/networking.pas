{$MODE OBJFPC}
unit networking;
interface

uses
{$IFDEF UNIX}
    cthreads, 
{$ENDIF}
    vipgfx, tools,
    classes, sockets, SysUtils, 
    TrackerEngine, TralalaPlayer,
    theMain, theTracker,
    nettools,  connection, packetID;



var
    originMouseX, originMouseY : longint;

    IDbuf : array [0..1] of longint;    

type   

    TReadUDPThread = class(TThread)
    protected
        
        procedure Execute; override;

    public
        
        Constructor Create(CreateSuspended: boolean);

    end;

    TReadTCPThread = class(TThread)
    protected
        
        procedure Execute; override;
        
    public

        Constructor Create(CreateSuspended: boolean);

        procedure doRead;

    end;



    TWriteThread = class(TThread)
    protected

      procedure Execute; override;
    public

      Constructor Create(CreateSuspended: boolean);
    private

        procedure sendMousePosition;
        procedure sendMouseButtons;
        procedure sendMouseWheel;

    end;


procedure StartNetworking;
procedure StopNetworking;


procedure sendTCP(id: NetID; theBuf: array of longint);

{$I ./readTCP.interface.inc}
{$I ./write.interface.inc}



implementation
uses netUI;

var
	oldMouseX, oldMouseY : longint;
    oldL, oldM, oldR : boolean;
    oldMouseWheel : longint;

	readTCPThread : TReadTCPThread;
    readUDPThread : TReadUDPThread;

	writeThread : TWriteThread;


{$I ./write.implementation.inc}
{$I ./readTCP.implementation.inc}


constructor TReadUDPThread.Create(CreateSuspended: boolean);
begin

    inherited Create(CreateSuspended);
    FreeOnTerminate:= True;

end;



procedure TReadUDPThread.Execute;
var 
    buf : array [0..3] of longint;

begin

    while (not Terminated) do begin

        buf[0]:= 0;

        fprecvfrom(socketUDP, @buf, sizeof(buf), 0, @remoteAddrUDP, @remoteAddrSLen);

        if buf[0] = 0 then continue;

        if buf[0] = 1 then begin
            originMouseX:= buf[1];
            originMouseY:= buf[2];
        end;

    end;

end;


constructor TReadTCPThread.Create(CreateSuspended: boolean);
begin

    inherited Create(CreateSuspended);
    FreeOnTerminate:= True;

end;



procedure TReadTCPThread.Execute;
begin

    while (not Terminated) do begin

        IDbuf[0]:= 0;

        fprecv(socketTCP, @IDbuf, sizeof(IDbuf), 0);

        if IDbuf[0] = 0 then continue;

        doRead;

    end;

    mouse2:= true;

end;


constructor TWriteThread.Create(CreateSuspended: boolean);
begin

    inherited Create(CreateSuspended);
    FreeOnTerminate:= True;

end;


procedure sendTCP(id: NetID; theBuf: array of longint);
var 
    buf : array [0..1] of longint;

begin

    buf[0]:= longint(id);
    buf[1]:= length(theBuf);

    if fpsend(socketTCP, @buf, 2 * 4, 0) = -1 then SocketError('send TCP');

    if fpsend(socketTCP, @theBuf, length(theBuf) * 4, 0) = -1 then SocketError('send TCP');        

end;


procedure TWriteThread.sendMousePosition;
var 
    buf : array [0..3] of longint;

begin

    if (oldMouseX <> mouseX) or (oldMouseY <> mouseY) then 
        if (mouseX < vscreen.width) and (mouseY < vscreen.height) then begin
                Buf[0]:= 1;
                Buf[1]:= mouseX;
                Buf[2]:= mouseY;    
                
                oldMouseX:= mouseX;
                oldMouseY:= mouseY;

                if fpsendto(socketUDP, @Buf, sizeof(buf), 0, @remoteAddrUDP, remoteAddrSLen) = -1 then SocketError('sendto UDP'); 

        end;

end;


procedure TWriteThread.sendMouseButtons;
var 
    buf : array [0..2] of longint;    

begin

    if (oldL <> mouseL) or (oldM <> mouseM) or (oldR <> mouseR) then begin
        if mouseL then buf[0]:= 1 else buf[0]:= 0;
        if mouseM then buf[1]:= 1 else buf[1]:= 0;
        if mouseR then buf[2]:= 1 else buf[2]:= 0;
        
        oldL:= mouseL;
        oldM:= mouseM;
        oldR:= mouseR;

        sendTCP(IDMouseButtons, buf);
    end;

end;


procedure TWriteThread.sendMouseWheel;
var 
    buf : array [0..0] of longint;

begin

    if oldMouseWheel <> mouseWheel then begin
        buf[0]:= mouseWheel;
        
        oldMouseWheel:= mouseWheel;

        sendTCP(IDMouseWheel, buf);
    end;

end;


procedure TWriteThread.Execute;
begin

    while (not Terminated) do begin

        sendMousePosition;
        sendMouseButtons;
        sendMouseWheel;

    end;

end;



procedure StartNetworking;
begin
    readTCPThread:= TReadTCPThread.Create(true);
    readUDPThread:= TReadUDPThread.Create(true);

    writeThread:= TWriteThread.Create(true);

    readTCPThread.Start;
    readUDPThread.Start;

    writeThread.Start;

end;


procedure StopNetworking;
begin

    writeThread.Terminate;
    //writeThread.WaitFor;

    readTCPThread.Terminate;
    //readTCPThread.WaitFor;

    readUDPThread.Terminate;
    //readUDPThread.WaitFor;

end;





begin
end.