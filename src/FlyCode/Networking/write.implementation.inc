
procedure netSendNetSyncStatus(enable: boolean);
var 
    buf : array [0..0] of longint;

begin

    if not isConnected then exit;

    buf[0]:= longint(enable);

    sendTCP(IDNetSyncStatus, buf);

end;



var
    lastCurrentOrder : longint = 0;
procedure netSendOrder;
var 
    buf : array [0..0] of longint;

begin
    
    if (not isConnected) or (not netsync) then exit;

    if (CurrentMode = modeTracker) and assigned(tracker) then
        if lastCurrentOrder <> tracker.patternSelector.currentOrder then begin
            lastCurrentOrder:= tracker.patternSelector.currentOrder;

            buf[0]:= tracker.patternSelector.currentOrder;

            sendTCP(IDCurrentOrder, buf);
        end;
    
end;