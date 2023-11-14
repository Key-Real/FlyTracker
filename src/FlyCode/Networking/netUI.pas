{$MODE OBJFPC}
unit netUI;
interface
uses
{$IFDEF UNIX}
    cthreads, 
{$ENDIF}
    vipgfx, tools,
    theMain,
    connection, networking; 

var
	mouseCursor : gfxImage;
	syncAfterPressed: boolean;


procedure drawSyncronizationSymbol(color: dword);
function isMouseInSyncronizationSymbol: boolean;

procedure updateNetUI;


implementation

procedure drawSyncronizationSymbol(color: dword);
begin

	putpixel(vscreen, 1219 + 0, 9 - 5, color);
	putpixel(vscreen, 1219 - 1, 9 - 5, color);
	putpixel(vscreen, 1219 + 1, 9 - 5, color);
	putpixel(vscreen, 1219 - 2, 9 - 5, color);
	putpixel(vscreen, 1219 + 2, 9 - 5, color);
	putpixel(vscreen, 1219 + 0, 9 + 5, color);
	putpixel(vscreen, 1219 - 1, 9 + 5, color);
	putpixel(vscreen, 1219 + 1, 9 + 5, color);
	putpixel(vscreen, 1219 - 2, 9 + 5, color);
	putpixel(vscreen, 1219 + 2, 9 + 5, color);
	

	putpixel(vscreen, 1219 - 3, 9 - 4, color);
	putpixel(vscreen, 1219 + 3, 9 - 4, color);
	putpixel(vscreen, 1219 - 4, 9 - 4, color);
	putpixel(vscreen, 1219 + 4, 9 - 4, color);
	putpixel(vscreen, 1219 - 3, 9 + 4, color);
	putpixel(vscreen, 1219 + 3, 9 + 4, color);
	putpixel(vscreen, 1219 - 4, 9 + 4, color);
	putpixel(vscreen, 1219 + 4, 9 + 4, color);



	putpixel(vscreen, 1219 - 5, 9 - 3, color);
	putpixel(vscreen, 1219 + 5, 9 - 3, color);
	putpixel(vscreen, 1219 - 5, 9 + 3, color);
	putpixel(vscreen, 1219 + 5, 9 + 3, color);


	putpixel(vscreen, 1219 + 5, 9 + 0, color);
	putpixel(vscreen, 1219 + 5, 9 + 1, color);
	putpixel(vscreen, 1219 + 6, 9 + 0, color);
	putpixel(vscreen, 1219 + 4, 9 + 0, color);
	putpixel(vscreen, 1219 + 4, 9 - 1, color);
	putpixel(vscreen, 1219 + 5, 9 - 1, color);
	putpixel(vscreen, 1219 + 6, 9 - 1, color);
	putpixel(vscreen, 1219 + 7, 9 - 1, color);
	putpixel(vscreen, 1219 + 3, 9 - 1, color);
	putpixel(vscreen, 1219 + 4, 9 - 2, color);
	putpixel(vscreen, 1219 + 5, 9 - 2, color);
	putpixel(vscreen, 1219 + 6, 9 - 2, color);
	putpixel(vscreen, 1219 + 7, 9 - 2, color);
	putpixel(vscreen, 1219 + 3, 9 - 2, color);
	putpixel(vscreen, 1219 + 2, 9 - 2, color);
	putpixel(vscreen, 1219 + 8, 9 - 2, color);


	putpixel(vscreen, 1219 - 5, 10 - 2, color);
	putpixel(vscreen, 1219 - 5, 10 - 1, color);
	putpixel(vscreen, 1219 - 4, 10 - 1, color);
	putpixel(vscreen, 1219 - 6, 10 - 1, color);
	putpixel(vscreen, 1219 - 5, 10 - 0, color);
	putpixel(vscreen, 1219 - 4, 10 - 0, color);
	putpixel(vscreen, 1219 - 6, 10 - 0, color);
	putpixel(vscreen, 1219 - 7, 10 - 0, color);
	putpixel(vscreen, 1219 - 3, 10 - 0, color);
	putpixel(vscreen, 1219 - 5, 10 + 1, color);
	putpixel(vscreen, 1219 - 4, 10 + 1, color);
	putpixel(vscreen, 1219 - 6, 10 + 1, color);
	putpixel(vscreen, 1219 - 7, 10 + 1, color);
	putpixel(vscreen, 1219 - 3, 10 + 1, color);
	putpixel(vscreen, 1219 - 8, 10 + 1, color);
	putpixel(vscreen, 1219 - 2, 10 + 1, color);

end;


function isMouseInSyncronizationSymbol: boolean;
begin

	result:= false;
	if (mouseX >= 1210) and (mouseX <= 1227) and (mouseY >= 4) and (mouseY <= 16) then result:= true;
	if (mouse2X >= 1210) and (mouse2X <= 1227) and (mouse2Y >= 4) and (mouse2Y <= 16) then result:= true;

end;


var
	syncSymbolPresseedOnce : boolean;
	


procedure updateNetUI;
begin
	if not isConnected then exit;

	
	
    if isMouseInSyncronizationSymbol then begin
    	if not syncAfterPressed then drawSyncronizationSymbol($ff0098fb) else begin
    		if netsync then
    			drawSyncronizationSymbol($ff00ff00)
    		else drawSyncronizationSymbol($ffffffff);
    	end;
    	
    	if mouseL and (not syncSymbolPresseedOnce) then begin
    		syncSymbolPresseedOnce:= true;
    		syncAfterPressed:= true;
    		netsync:= not netsync;
    		
    		netSendNetSyncStatus(netsync);

    	end;

    end else begin
    	if netsync then
    		drawSyncronizationSymbol($ff00ff00)
    	else drawSyncronizationSymbol($ffffffff);

    	syncAfterPressed:= false;
    end;

    if syncSymbolPresseedOnce then begin
    	if netsync then
    		drawSyncronizationSymbol($ff00ff00)
    	else drawSyncronizationSymbol($ffffffff);
    end;

    if not mouseL then begin
    	syncSymbolPresseedOnce:= false;
    end;
	

	if netsync then putspriteClip(vscreen, mouse2X, mouse2Y, mouseCursor, RGBA(255,0,255,255));


end;


begin
end.