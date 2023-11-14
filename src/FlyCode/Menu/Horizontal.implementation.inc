constructor TMainMenu.Create(parentTUI: TtuiTUI);
begin

    MenuTUI:= parentTUI;

    MenuHorizontalBox:= TtuiBox.create(MenuTUI, 0, 0, vscreen.width, 18, 'Box Main Menu', tuiBoxStatic);
    MenuHorizontalBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(MenuHorizontalBox);

    allocImage(NoteImage, 16, 16);
    drawNote(NoteImage);

    MenuHorizontal:= TtuiMenuHorizontal.create(MenuHorizontalBox, 'Main Menu');
    MenuHorizontal.addMenuHorizontalItem('Menu Note', NoteImage, @execProcMenuNoteSelect, @execProcMenuNoteUnSelect);
    MenuHorizontal.addMenuHorizontalItem('Menu File', 'File', @execProcMenuFileSelect, @execProcMenuFileUnSelect);
    MenuHorizontal.addMenuHorizontalItem('Menu Song', 'Song', @execProcMenuSongSelect, @execProcMenuSongUnSelect);
    MenuHorizontal.addMenuHorizontalItem('Menu Window', 'Window', @execProcMenuWindowSelect, @execProcMenuWindowUnSelect);
    MenuHorizontal.addMenuHorizontalItem('Menu Help', 'Help', @execProcMenuHelpSelect, @execProcMenuHelpUnSelect);
    MenuHorizontal.theme:= LoadThemeMenuHorizontal;
    MenuHorizontal.allowMouse2Buttons:= true;  
    MenuHorizontalBox.addItem(MenuHorizontal);  

end;


procedure TMainMenu.drawNote(img: gfxImage);
begin

    putpixel(img, 5, 1, LoadThemeMenuVertical.TextColor);
    putpixel(img, 6, 1, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 1, LoadThemeMenuVertical.TextColor);
    putpixel(img, 2, 2, LoadThemeMenuVertical.TextColor);
    putpixel(img, 3, 2, LoadThemeMenuVertical.TextColor);
    putpixel(img, 4, 2, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 2, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 3, LoadThemeMenuVertical.TextColor);
    putpixel(img, 6, 4, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 4, LoadThemeMenuVertical.TextColor);
    putpixel(img, 2, 5, LoadThemeMenuVertical.TextColor);
    putpixel(img, 3, 5, LoadThemeMenuVertical.TextColor);
    putpixel(img, 4, 5, LoadThemeMenuVertical.TextColor);
    putpixel(img, 5, 5, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 5, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 6, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 7, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 8, LoadThemeMenuVertical.TextColor);
    
    putpixel(img, 7, 9, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 9, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 9, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 9, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 8, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 12, 10, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 8, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 12, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 13, 11, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 8, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 12, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 13, 12, LoadThemeMenuVertical.TextColor);
    putpixel(img, 7, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 8, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 12, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 13, 13, LoadThemeMenuVertical.TextColor);
    putpixel(img, 8, 14, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 14, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 14, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 14, LoadThemeMenuVertical.TextColor);
    putpixel(img, 12, 14, LoadThemeMenuVertical.TextColor);
    putpixel(img, 9, 15, LoadThemeMenuVertical.TextColor);
    putpixel(img, 10, 15, LoadThemeMenuVertical.TextColor);
    putpixel(img, 11, 15, LoadThemeMenuVertical.TextColor);

end;


destructor TMainMenu.Destroy;
begin   

    FreeImage(NoteImage);
    MenuTUI.processFinalMessages;

end;


procedure TMainMenu.execProcMenuWindowUnSelect(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Window');
    MenuTUI.closeBox(aBox);

end;


procedure TMainMenu.execProcMenuWindowSelect(const param: string);
var 
    aItem : TtuiMenuHorizontalItem;
    aMenuHorizontal : TtuiMenuHorizontal;
    aMenuVertical : TtuiMenuVertical;
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Main Menu');
    aMenuHorizontal:= getMenuHorizontalByName(aBox, 'Main Menu');
    aItem:= aMenuHorizontal.getItemByName('Menu Window');

    aBox:= TtuiBox.Create(MenuTUI, aItem.x, 18, 0, 0, 'Box Vertical Menu Window', tuiBoxStatic);
    aBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(aBox);

    aMenuVertical:= TtuiMenuVertical.create(aBox, 'Vertical Menu Window');
    aMenuVertical.addMenuVerticalItem('Vertical Menu Window - FullScreen', 'FullScreen', @execProcMenuItemFullScreen);
    aMenuVertical.addMenuVerticalItem('Vertical Menu Window - WindowMode', 'Window Mode', @execProcMenuItemWindowMode);
    aMenuVertical.theme:= LoadThemeMenuVertical;
    aMenuVertical.allowMouse2Buttons:= true;
    aBox.addItem(aMenuVertical);

end;


procedure TMainMenu.execProcMenuItemFullScreen(const param: string);
var
     aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Window');
    MenuTUI.closeBox(aBox);

    switchFullScreen;

end;


procedure TMainMenu.execProcMenuItemWindowMode(const param: string);
var
     aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Window');
    MenuTUI.closeBox(aBox);

    switchWindowed;

end;




procedure TMainMenu.execProcMenuNoteUnSelect(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Note');
    MenuTUI.closeBox(aBox);

end;


procedure TMainMenu.execProcMenuNoteSelect(const param: string);
var 
    aItem : TtuiMenuHorizontalItem;
    aMenuHorizontal : TtuiMenuHorizontal;
    aMenuVertical : TtuiMenuVertical;
    aBox : TtuiBox;

begin

    

    aBox:= MenuTUI.getBoxByName('Box Main Menu');
    aMenuHorizontal:= getMenuHorizontalByName(aBox, 'Main Menu');
    aItem:= aMenuHorizontal.getItemByName('Menu Note');

    aBox:= TtuiBox.Create(MenuTUI, aItem.x, 18, 0, 0, 'Box Vertical Menu Note', tuiBoxStatic);
    aBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(aBox);

    aMenuVertical:= TtuiMenuVertical.create(aBox, 'Vertical Menu Note');
    aMenuVertical.addMenuVerticalItem('Vertical Menu Note - Tracker', 'Tracker', @execProcMenuItemTracker);
    aMenuVertical.addMenuVerticalItem('Vertical Menu Note - PianoRoll','PianoRoll', @execProcMenuItemPianoRoll);
    aMenuVertical.addMenuVerticalItem('Vertical Menu Note - InstrumentEditor', 'InstrumentEditor', @execProcMenuItemInstrumentEditor);
    aMenuVertical.theme:= LoadThemeMenuVertical;
    aMenuVertical.allowMouse2Buttons:= true;
    aBox.addItem(aMenuVertical);

end;


procedure TMainMenu.execProcMenuItemTracker(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Note');
    MenuTUI.closeBox(aBox);

    currentmode:= modeTracker;    

end;


procedure TMainMenu.execProcMenuItemPianoRoll(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Note');
    MenuTUI.closeBox(aBox);

    currentmode:= modePianoRoll;    

end;


procedure TMainMenu.execProcMenuItemInstrumentEditor(const param: string);
var
    aBox : TtuiBox;

begin

    aBox:= MenuTUI.getBoxByName('Box Vertical Menu Note');
    MenuTUI.closeBox(aBox);

    currentmode:= modeInstrumentEditor;

end;