procedure TReadTCPThread.doRead;
begin
    executePacket;
end;

procedure netGetMouseButtons;
var 
    buf : array [0..2] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
    
    if buf[0] = 1 then Mouse2L:= true else Mouse2L:= false;
    if buf[1] = 1 then Mouse2M:= true else Mouse2M:= false;
    if buf[2] = 1 then Mouse2R:= true else Mouse2R:= false;

end;


procedure netGetMouseWheel;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);
    mouse2Wheel:= buf[0];

end;



procedure netGetCurrentOrder;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    tracker.patternSelector.setOrder(buf[0]);

end;


procedure netGetNetSyncStatus;
var 
    buf : array [0..0] of longint;

begin

    fprecv(socketTCP, @buf, sizeof(buf), 0);

    netsync:= boolean(buf[0]);
    syncAfterPressed:= true;
    mouse2X:= originMouseX;
    mouse2Y:= originMouseY;

end;

