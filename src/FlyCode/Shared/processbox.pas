{$MODE OBJFPC} {$H+}
unit processbox;
interface
uses 
    {$IFDEF UNIX}cthreads,{$ENDIF}
    tools, vipgfx, myTTF,
    theTheme;

procedure drawProcessBox;


implementation
uses theMain;

procedure drawProcessBox;
var
	boxX, boxY, boxWidth, boxHeight : dword;
    sizeX, sizeY  :longint;

begin

    boxWidth:= 300;
    boxHeight:= 100;

    boxX:= vscreen.width div 2 - boxWidth div 2;
    boxY:= vscreen.height div 2 - boxHeight div 2;


    drawBarClip(vscreen, boxX, boxY, boxX + boxWidth, boxY + boxHeight, Theme_Box_BackgroundColor);
    drawVLineClip(vscreen, boxY, boxY + boxHeight - 1, boxX, Theme_Box_LeftTopBorderColor);
    drawHLineClip(vscreen, boxX, boxX + boxWidth - 1, boxY, Theme_Box_LeftTopBorderColor);
    drawVLineClip(vscreen, boxY, boxY + boxHeight - 1, boxX + boxWidth - 1, Theme_Box_RightBottomBorderColor);
    drawHLineClip(vscreen, boxX, boxX + boxWidth - 1, boxY + boxHeight - 1, Theme_Box_RightBottomBorderColor);
    
    ttfGetStringSize(trackerTUI.mainfont, 'Processing', sizeX, sizeY);
    ttfPrintStringXY(vscreen, TrackerTUI.mainfont, boxX + boxwidth div 2 - sizeX div 2, boxY + boxHeight div 2 - sizeY div 2, $ffffffff, 'Processing');


    updategfxSystem;
end;



begin
end.