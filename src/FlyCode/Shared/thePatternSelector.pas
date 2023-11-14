{$MODE OBJFPC}{$H+}
unit thePatternSelector;
interface
uses 
    sysutils, strutils, iostream, classes,
    tools, vipgfx, myTTF,
    TrackerEngine, TralalaPlayer, loaders, loaderit,
    tui.Core, tui.Button, tui.ScrollBarHorizontal, tui.MiddleScrollBox2Entries,
    tui.TextField, tui.SelectBox, tui.SelectableImage, tui.EditField, tui.CheckBox, tui.EditableSelectBoxNumbered,
    tui.ButtonUP, tui.ButtonDOWN, tui.MenuVertical, tui.Image,
    Note2Str,
    theTheme, theMain;

type

	TPatternSelector = class

	public

		var
			panel : TtuiBox;

            currentOrder : longint;
    
            callReload : TtuiExecProc;

        constructor Create(theBox: TtuiBox);

	    procedure PatternSelectorProcChange(const param: string);

	    procedure ButtonInsertOderProc(const param: string);
	    procedure ButtonDeleteOrderProc(const param: string);
	    procedure ButtonUpOrderProc(const param: string);
	    procedure ButtonDownOrderProc(const param: string);

	    procedure buildPatternSelector;
	    procedure reloadPatternSelector(order: dword);

	    procedure updateOrder;

	    procedure SetOrder(num: dword);

    var	    
	    PatternSelector : TtuiMiddleScrollBox2Entries;
	    ButtonInsert : TtuiButton;
	    ButtonUp : TtuiButton;
	    ButtonDown : TtuiButton;
	    ButtonDel : TtuiButton;


    private

        Module : TModule;
        PlayerState : TPlayerState;
        FramesSinceLastTick : Integer;

    end;


implementation
uses networking;


constructor TPatternSelector.Create(theBox: TtuiBox);
begin

    panel:= theBox;

end;


procedure TPatternSelector.buildPatternSelector;
begin

    PatternSelector:= TtuiMiddleScrollBox2Entries.Create(Panel, 'PatternSelector_PatternSelector', 0, 1, 77, 3 * 26 + 2 + 11, @PatternSelectorProcChange);
    PatternSelector.Theme:= LoadThemeMiddleScrollBox2Entries;
    PatternSelector.Theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    Panel.addItem(PatternSelector);

    
    ButtonInsert:= TtuiButton.create(Panel, 'Button insert', 78, 1, 48, 22, 'insert', @ButtonInsertOderProc);
    ButtonInsert.Theme:= LoadThemeButton;
    Panel.addItem(ButtonInsert);

    ButtonUp:= TtuiButton.create(Panel, 'Button up', 78, 24, 48, 22, 'up', @ButtonUpOrderProc);
    ButtonUp.Theme:= LoadThemeButton;
    Panel.addItem(ButtonUp);

    ButtonDown:= TtuiButton.create(Panel, 'Button down', 78, 47, 48, 22, 'down', @ButtonDownOrderProc);
    ButtonDown.Theme:= LoadThemeButton;
    Panel.addItem(ButtonDown);

    ButtonDel:= TtuiButton.create(Panel, 'Button del', 78, 70, 48, 22, 'del', @ButtonDeleteOrderProc);
    ButtonDel.Theme:= LoadThemeButton;
    Panel.addItem(ButtonDel);

end;


procedure TPatternSelector.reloadPatternSelector(order: dword);
var
    i:dword;

begin

    PatternSelector.ClearStrings;

    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        for i:= 0 to Module.Order.LastOrder do begin
            if Module.Order[i] <> SkipToNextOrder then
                PatternSelector.addString(PatternSelector.String2Entries(numstr(i), numstr(Module.Order[i])))
            else
                PatternSelector.addString(PatternSelector.String2Entries(numstr(i), '+++'));
        end;

    tralalaEngine.Unlock_ReadOnly;

    PatternSelector.setCurValue(order);

    SetOrder(order);

end;


procedure TPatternSelector.ButtonDeleteOrderProc(const param: string);
var 
    i : dword;
    l : dword;
begin

    if PatternSelector.numStrings <= 1 then exit;

    PatternSelector.deleteString(PatternSelector.curStringNum);
    

    tralalaEngine.Lock_Module_ReadWrite(Module);

        if not ((PatternSelector.curStringNum = (PatternSelector.numStrings - 1)) and (PatternSelector.strings[PatternSelector.curStringNum].left = numstr(PatternSelector.curStringNum))) then begin

            for i:= PatternSelector.curStringNum to PatternSelector.numStrings - 1 do begin
                l:= strnum(PatternSelector.strings[i].left);
                dec(l);
                PatternSelector.strings[i].left:= numstr(l);
                if PatternSelector.strings[i].right <> '+++' then
                    Module.order[l]:= strnum(PatternSelector.strings[i].right)
                else
                    Module.order[l]:= 256;                    
            end;

        end;

        Module.order[PatternSelector.numStrings]:= EndOfSongMarker;

    tralalaEngine.Unlock_Module_ReadWrite;

    reloadPatternSelector(PatternSelector.curStringNum);
    PatternSelectorProcChange(numstr(PatternSelector.curStringNum));

end;


procedure TPatternSelector.ButtonInsertOderProc(const param: string);
var 
    i : dword;
    l : dword;

begin

    PatternSelector.insertString(PatternSelector.curStringNum, PatternSelector.String2Entries(numstr(PatternSelector.curStringNum), numstr(0)));
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= PatternSelector.curStringNum + 1 to PatternSelector.numStrings - 1 do begin
            l:= strnum(PatternSelector.strings[i].left);
            inc(l);
            PatternSelector.strings[i].left:= numstr(l);
            if PatternSelector.strings[i].right <> '+++' then 
                Module.order[l]:= strnum(PatternSelector.strings[i].right)
            else
                Module.order[l]:= 256;
        end;


    tralalaEngine.Unlock_Module_ReadWrite;

    reloadPatternSelector(PatternSelector.curStringNum);
    PatternSelectorProcChange(numstr(PatternSelector.curStringNum));

end;


procedure TPatternSelector.ButtonUpOrderProc(const param: string);
var
    left, right : string;
    i : longint;

begin

    left:= PatternSelector.Strings[PatternSelector.curStringNum].left;
    right:= PatternSelector.Strings[PatternSelector.curStringNum].right;

    if right = '+++' then right:= '-1';
    i:= strnum(right);
    inc(i);
    if i >= 255 then i:= 255;
    right:= numstr(i);

    tralalaEngine.Lock_Module_ReadWrite(Module);
        Module.order[strnum(left)]:= strnum(right);
    tralalaEngine.Unlock_Module_ReadWrite;

    reloadPatternSelector(strnum(left));
    currentPattern:=strnum(right);

    if assigned(callReload) then callReload('');

end;


procedure TPatternSelector.ButtonDownOrderProc(const param: string);
var 
    left, right : string;
    i : longint;

begin

    left:= PatternSelector.Strings[PatternSelector.curStringNum].left;
    right:= PatternSelector.Strings[PatternSelector.curStringNum].right;

    if right <> '+++' then i:= strnum(right) else i:= -1;
    dec(i);
    if i <= -1 then i:= -1;
    right:= numstr(i);

    tralalaEngine.Lock_Module_ReadWrite(Module);
        if strnum(right) > -1 then
            Module.order[strnum(left)]:= strnum(right)
        else
            Module.order[strnum(left)]:= 256;
    tralalaEngine.Unlock_Module_ReadWrite;

    reloadPatternSelector(strnum(left));


    if assigned(callReload) then callReload('');

end;


procedure TPatternSelector.PatternSelectorProcChange(const param: string);
begin
    
    SetOrder(PatternSelector.curStringNum);
    
    if tralalaEngine.playmode <> pmStopped then tralalaEngine.PlaySongFromOrder(CurrentOrder);

end;


procedure TPatternSelector.SetOrder(num: dword);
begin    
    
    if CurrentOrder >= PatternSelector.numStrings then CurrentOrder:= 0;

    if PatternSelector.Strings[CurrentOrder].right <> '+++' then
        currentPattern:= strnum(PatternSelector.Strings[CurrentOrder].right)
    else
        currentPattern:= -1;

    if num >= PatternSelector.numStrings then num:= 0;
    if currentorder <> num then PatternSelector.setCurValue(num);


    CurrentOrder:= num;

    netSendOrder;

end;


procedure TPatternSelector.updateOrder;
begin
    
    tralalaEngine.Lock_ReadOnly(PlayerState, Module, FramesSinceLastTick);

        if PlayerState.ModuleTickPosition.PlayMode <> TPlayMode.pmStopped then SetOrder(PlayerState.ModuleTickPosition.CurrentOrder);

    tralalaEngine.Unlock_ReadOnly;
    
end;



begin
end.
