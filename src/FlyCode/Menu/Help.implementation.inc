

const 

        endl = #10#13;

        HelpTextHowToUse = ''
                         + 'Main Screen' + endl
                         + endl
                         + '    BPM' + endl
                         + '        The BPM settings defines how fast (ticks/second) the music player' + endl
                         + '        will run. 125 BPM <-> 50Hz.' + endl
                         + '        Number  of player ticks/second = BPM*2/5' + endl
                         + endl
                         + '    Speed' + endl
                         + '        Number of player ticks/pattern line.' + endl
                         + endl
                         + '    Note Add' + endl
                         + '        Number of pattern lines the cursor jumps when you' + endl
                         + '        edit a note' + endl
                         + endl
                         + '    Pattern Length' + endl
                         + '        The number of lines for the current pattern. Up to 256 lines.' + endl
                         + '        Note that FlyTracker won''t warn you if you decrease ths value.' + endl
                         + '        The notes at the bottom line will be trown out of the space.' + endl
                         + endl
                         + '    Song Channels' + endl
                         + '        The number of channels used by the module. Up to 64 channels.' + endl
                         + '        Note that FlyTracker won''t warn you if you decrease ths value.' + endl
                         + '        The notes at the right channel will be trown out of the space.' + endl
                         + endl
                         + '    Repeat Start' + endl
                         + '        The pattern number to play after the last order(end of song)' + endl
                         + endl
                         + '    Octave' + endl
                         + '        Scale the current Octave of the MIDI/Virtual Keyboard' + endl
                         + endl
                         + endl
                         + '    Expand' + endl
                         + '        Inserts a blank line after each pattern line.' + endl
                         + '        Usefull if you want to convert a pattern that' + endl
                         + '        runs in speed 2*x to a pattern that runs in speed x.' + endl
                         + endl
                         + '    Shrink' + endl
                         + '        Deletes all odd pattern lines.' + endl
                         + endl
                         + endl
                         + 'The Instrument Selector' + endl
                         + '        The instrument that has a mark on it''s name string, is the ' + endl
                         + '        current instrument.' + endl
                         + '        You change the name of an instrument by double clicking on the slot.' + endl
                         + '        If you click the right mouse button, the corresponding menu pop up.' + endl
                         + '        You can Clear / Load / Save or Edit the instrument.' + endl
                         + endl
                         + endl
                         + 'Scopes' + endl
                         + '        Left mouse button: Turn channel on/off.' + endl
                         + '        Right mouse button: Turn channel multi-record/edit on/off.' + endl
                         + '        Left mouse double click: Turn all channels off except the selected one.' + endl
                         + endl
                         + endl
                         + 'Advanced edit' + endl
                         + '    Copy/Paste masking' + endl
                         + '        The masking is used for copying/pasting only parts of a "note-cell".' + endl
                         + '        The different parts of a "note-cell" is Note, Instrument number,' + endl
                         + '        Volume, Effect number and Effect data.' + endl
                         + '        There are 3 columns of "enable/disable checkboxes" which has the' + endl
                         + '        letters C, P & T above.' + endl
                         + '        C  means copy, it controls which parts that goes into the copybuffer.' + endl
                         + '        P  means paste and controls which parts that goes out from the copybuffer.' + endl
                         + '        T  means transparency. If it''s enabled, the pasting doesn''t overwrite' + endl
                         + '             data with null-information, only with a note or a number <> 0.' + endl
                         + endl
                         + '        The cut functions works like pasting with zerro-data. This means that' + endl
                         + '        the cutting is controlled with P-column (or T-column).' + endl
                         + '        When you copy data with masking, the disabled parts are not cleared in' + endl
                         + '        the copybuffer. (Making it possible to collect data from several' + endl
                         + '        locations into the copybuffer.)' + endl
                         ;


        HelpTextKeyBindings = ''
                            + 'Keybindings' + endl
                            + endl
                            + '     If you have the ambition to create music efficiently we strongly recommend' + endl
                            + '     that you learn ALL the keyboard functions. Many of them are the same from' + endl
                            + '     Fast Tracker 2 to ensure that you feel comfortable using this program ' + endl
                            + '     from the very first minute.' + endl
                            + endl
                            + '     Note for Mac keyboards on MacOS:' + endl
                            + '     - The left Option Key is the left Alt key' + endl
                            + '     - The left Command Key can also be used instead of Alt for' + endl
                            + '         "select all"/cut/copy/paste for text editing.' + endl
                            + endl
                            + endl
                            + '    Cursor moves:' + endl
                            + endl
                            + '         F9..F12' + endl
                            + '             Jump in pattern.' + endl
                            + endl
                            + '         Cntrl+F9..F12' + endl
                            + '             Pattern play from F9..F12 line.' + endl
                            + endl
                            + '         PageUp' + endl
                            + '             Jump 16 lines upwards.' + endl
                            + endl
                            + '         PageDown' + endl
                            + '             Jump 16 lines downwards.' + endl
                            + endl
                            + '         Home' + endl
                            + '             Jump to 0.' + endl
                            + endl
                            + '         End' + endl
                            + '             Jump to last line.' + endl
                            + endl
                            + '         Tab' + endl
                            + '             Jump to next channel.' + endl
                            + endl
                            + '         Alt+Q..I' + endl
                            + '             Jump to channel(0..7)' + endl
                            + endl
                            + '         Alt+A..K' + endl
                            + '             Jump to channel(8..15)' + endl
                            + endl
                            + endl
                            + '    Cut/Copy/Paste:' + endl
                            + endl
                            + '         Delete' + endl
                            + '             Delete note or volume column at cursor.' + endl
                            + endl
                            + '         Shift+Delete' + endl
                            + '             Delete note, volume and effect at cursor.' + endl
                            + endl
                            + '         Alt+Delete' + endl
                            + '             Delete effect at cursor.' + endl
                            + endl
                            + '         Insert' + endl
                            + '             Insert at cursor and move all the data down.' + endl
                            + endl
                            + '         Shift+Inserts' + endl
                            + '             Insert line at cursor.' + endl
                            + endl
                            + '         Backspace' + endl
                            + '             Delete previous note and move everything up.' + endl
                            + endl
                            + '         Shift+Backspace' + endl
                            + '             Delete previous line.' + endl
                            + endl
                            + '         Alt+Cursor' + endl
                            + '             Mark block.' + endl
                            + endl
                            + '         Shift+F3' + endl
                            + '             Cut track.' + endl
                            + endl
                            + '         Shift+F4' + endl
                            + '             Copy trach.' + endl
                            + endl
                            + '         Shift+F5' + endl
                            + '             Past track.' + endl
                            + endl
                            + '         Control+F3' + endl
                            + '             Cut pattern.' + endl
                            + endl
                            + '         Control+F4' + endl
                            + '             Copy pattern.' + endl
                            + endl
                            + '         Control+F5' + endl
                            + '             Paste pattern.' + endl
                            + endl
                            + '         Alt+F3' + endl
                            + '             Cut block.' + endl
                            + endl
                            + '         Alt+F4' + endl
                            + '             Copy block.' + endl
                            + endl
                            + '         Alt+F5' + endl
                            + '             Paste block.' + endl
                            + endl
                            + '         Alt+C' + endl
                            + '             Mark current track.' + endl
                            + endl
                            + endl
                            + endl
                            + '    Miscelloneous:' + endl
                            + endl
                            + '         Control' + endl
                            + '             Play song.' + endl
                            + endl
                            + '         Alt Gr' + endl
                            + '             Play pattern.' + endl
                            + endl
                            + '         Right shift' + endl
                            + '             Record pattern.' + endl
                            + endl
                            + '         Space' + endl
                            + '             Stop/Edit.' + endl
                            + endl
                            + '         F1..F7' + endl
                            + '             Select octave.' + endl
                            + endl
                            + '         CapsLock' + endl
                            + '             Enter Keyoff - "note".' + endl
                            + endl
                            + '         <>' + endl
                            + '             Enter Keycut - "note".' + endl
                            + endl
                            + '         Shift+Left' + endl
                            + '             Increase song position.' + endl
                            + endl
                            + '         Shift+Right' + endl
                            + '             Decrease song position.' + endl
                            + endl
                            + '         Cntrol+Left' + endl
                            + '             Increase pattern number.' + endl
                            + endl
                            + '         Cntrol+Right' + endl
                            + '             Decrease pattern number.' + endl
                            + endl
                            + endl
                            + '    Miscelloneous (an a Mac keyboard):' + endl
                            + endl
                            + '         Right Control' + endl
                            + '             Play song.' + endl
                            + endl
                            + '         Right alt/option' + endl
                            + '             Play pattern.' + endl
                            + endl
                            + '         Right Shift' + endl
                            + '             Record pattern.' + endl
                            + endl
                            + endl
                            + endl
                            + '    Window switching:' + endl
                            + endl
                            + '         Control+A' + endl
                            + '             Advanced edit.' + endl
                            + endl
                            + '         Control+T' + endl
                            + '             Transpose.' + endl
                            + endl
                            + endl
                            + endl
                            + '    Instrument select (Nemeric keyboard):' + endl
                            + endl
                            + '         1..0' + endl
                            + '             Select insturment in block.'+ endl
                            + endl
                            + '         ,' + endl
                            + '             Clear instrument.'+ endl
                            + endl
                            + '         Shift+Up' + endl
                            + '             Select previous instrument.'+ endl
                            + endl
                            + '         Shift+DOWN' + endl
                            + '             Select next instrument.'+ endl
                            + endl
                            + endl
                            + endl
                            + '    Command/Volume macro:' + endl
                            + endl
                            + '         Alt+1..0' + endl
                            + '             Write command/volume at cursor.'+ endl
                            + endl
                            + '         Shift+Alt+1..0' + endl
                            + '             Read command/volume at cursor.'+ endl
                            + endl
                            + endl
                            + endl
                            + '    Scale-fade volume:' + endl
                            + endl
                            + '         Shift+V' + endl
                            + '             Scale-fade volume in track.'+ endl
                            + endl
                            + '         Control+V' + endl
                            + '             Scale-fade volume in pattern.'+ endl
                            + endl
                            + '         Alt+V' + endl
                            + '             Scale-fade volume in block.'+ endl
                            + endl
                            + endl
                            + endl
                            + '    Transpose:' + endl
                            + endl
                            + '         Shift+F7' + endl
                            + '             Transpose current instrument in track down.'+ endl
                            + endl
                            + '         Shift+F8' + endl
                            + '             Transpose current instrument in track up.'+ endl
                            + endl
                            + '         Control+F7' + endl
                            + '             Transpose current instrument in pattern down.'+ endl
                            + endl
                            + '         Control+F8' + endl
                            + '             Transpose current instrument in pattern up.'+ endl
                            + endl
                            + '         Alt+F7' + endl
                            + '             Transpose current instrument in block down.'+ endl
                            + endl
                            + '         Alt+F8' + endl
                            + '             Transpose current instrument in block up.'+ endl
                            + endl
                            + '         Shift+F1' + endl
                            + '             Transpose all instrument in track down.'+ endl
                            + endl
                            + '         Shift+F2' + endl
                            + '             Transpose all instrument in track up.'+ endl
                            + endl
                            + '         Control+F1' + endl
                            + '             Transpose all instrument in pattern down.'+ endl
                            + endl
                            + '         Control+F2' + endl
                            + '             Transpose all instrument in pattern up.'+ endl
                            + endl
                            + '         Alt+F1' + endl
                            + '             Transpose all instrument in block down.'+ endl
                            + endl
                            + '         Alt+F2' + endl
                            + '             Transpose all instrument in block up.'+ endl
                            ;


procedure TMainMenu.execProcMenuHelpSelect(const param: string);
var 
    aItem : TtuiMenuHorizontalItem;

begin

    aItem:= MenuHorizontal.getItemByName('Menu Help');
    BoxVerticalMenuHelp:= TtuiBox.Create(MenuTUI, aItem.x, 18, 0, 0, 'Box Vertical Menu Help', tuiBoxStatic);
    BoxVerticalMenuHelp.themeBox:= LoadThemeBox;
    MenuTUI.addBox(BoxVerticalMenuHelp);

    HelpMenuVertical:= TtuiMenuVertical.create(BoxVerticalMenuHelp, 'Vertical Menu Help');
    HelpMenuVertical.addMenuVerticalItem('Vertical Menu Help - How to use', 'How to Use', @execProcMenuItemHowToUse);
    HelpMenuVertical.addMenuVerticalItem('Vertical Menu Help - Keybindings', 'Keybindings', @execProcMenuItemKeybindings);
    HelpMenuVertical.addMenuVerticalItem('Vertical Menu Help - About', 'About', @execProcMenuItemAbout);
    HelpMenuVertical.theme:= LoadThemeMenuVertical;
    HelpMenuVertical.allowMouse2Buttons:= true;
    BoxVerticalMenuHelp.addItem(HelpMenuVertical);

end;


procedure TMainMenu.execProcMenuHelpUnSelect(const param: string);
begin

    MenuTUI.closeBox(BoxVerticalMenuHelp);

end;


procedure TMainMenu.execProcMenuItemHowToUse(const param: string);
var
    aTextBox : TtuiTextBox;
    aButton : TtuiButton;

begin

    MenuTUI.closeBox(BoxVerticalMenuHelp);

    if assigned(HowToUseBox) then exit;

    HowToUseBox:= TtuiBox.create(MenuTUI,vscreen.width div 2 - 232, 100, 464, 480, 'box how to use', tuiBoxStd);
    HowToUseBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(HowToUseBox);

    aTextBox:= TtuiTextBox.Create(HowToUseBox, 'TextBox Help - how to use', 10, 10, HowToUseBox.boxWidth - 20, HowToUseBox.boxHeight - 64);
    aTextBox.theme:= LoadThemeTextBox;
    HowToUseBox.addItem(aTextBox);


    aButton:= TtuiButton.create(HowToUseBox, 'Button OK', HowToUseBox.boxWidth - 128, HowToUseBox.boxHeight - 44, 116, 32, 'OK', @execProcButton_BoxHowTo_ButtonOK);
    aButton.theme:= LoadThemeButton;
    HowToUseBox.addItem(aButton);

    aTextBox.loadText(HelpTextHowToUse);

    inMenuItem:= true;

end;


procedure TMainMenu.execProcButton_BoxHowTo_ButtonOK(const param: string);
begin

    MenuTUI.closeBox(HowToUseBox);

    inMenuItem:= false;

end;


procedure TMainMenu.execProcMenuItemKeybindings(const param: string);
var
    aTextBox : TtuiTextBox;
    aButton : TtuiButton;

begin

    MenuTUI.closeBox(BoxVerticalMenuHelp);

    if assigned(KeyBindingsBox) then exit;

    KeyBindingsBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 232, 100, 464, 480, 'box keybindings', tuiBoxStd);
    KeyBindingsBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(KeyBindingsBox);

    aTextBox:= TtuiTextBox.Create(KeyBindingsBox, 'TextBox Help - keybindings', 10, 10, KeyBindingsBox.boxWidth - 20, KeyBindingsBox.boxHeight - 64);
    aTextBox.theme:= LoadThemeTextBox;
    KeyBindingsBox.addItem(aTextBox);


    aButton:= TtuiButton.create(KeyBindingsBox, 'Button OK', KeyBindingsBox.boxWidth - 128, KeyBindingsBox.boxHeight - 44, 116, 32, 'OK', @execProcButton_BoxKeybindings_ButtonOK);
    aButton.theme:= LoadThemeButton;
    KeyBindingsBox.addItem(aButton);

    aTextBox.loadText(HelpTextKeyBindings);

    inMenuItem:= true;

end;


procedure TMainMenu.execProcButton_BoxKeybindings_ButtonOK(const param: string);
begin

    MenuTUI.closeBox(KeyBindingsBox);

    inMenuItem:= false;

end;




procedure TMainMenu.execProcMenuItemAbout(const param: string);
var
     aButton : TtuiButton;
     aTextField : TtuiTextField;
     sizeX, sizeY : longint;

begin

    MenuTUI.closeBox(BoxVerticalMenuHelp);

    if assigned(AboutBox) then exit;


    AboutBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 200, vscreen.height div 2 - 50, 400, 220, 'box about', tuiBoxStd);
    AboutBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(AboutBox); 

    
    ttfGetStringSize(MenuTUI.mainFont, 'FlyTracker', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - FlyTracker', 200 - sizeX div 2, 8, 'FlyTracker');
    aTextField.theme:= LoadThemeTextField;
    AboutBox.addItem(aTextField);

    ttfGetStringSize(MenuTUI.mainFont, 'ver ' + FlyTrackerVersion + ' (c) by Key-Real', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - FlyTracker - ver', 200 - sizeX div 2, 24, 'ver ' + FlyTrackerVersion + ' (c) by Key-Real');
    aTextField.theme:= LoadThemeTextField;
    aTextField.theme.FontColor:= RGBA(128,128,128,255);
    AboutBox.addItem(aTextField);


    ttfGetStringSize(MenuTUI.mainFont, 'Tycoon User Interface', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - TUI', 200 - sizeX div 2, 48, 'Tycoon User Interface');
    aTextField.theme:= LoadThemeTextField;
    AboutBox.addItem(aTextField);

    ttfGetStringSize(MenuTUI.mainFont, 'ver ' + TUIVer + ' (c) by Key-Real', sizeX, sizeY);
    aTextField:=TtuiTextField.create(AboutBox, 'TextField About - TUI ver', 200 - sizeX div 2, 64, 'ver ' + TUIVer + ' (c) by Key-Real');
    aTextField.theme:= LoadThemeTextField;
    aTextField.theme.FontColor:= RGBA(128,128,128,255);
    AboutBox.addItem(aTextField);


    ttfGetStringSize(MenuTUI.mainFont, 'VipGFX', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - VipGFX', 200 - sizeX div 2, 88, 'VipGFX');
    aTextField.theme:= LoadThemeTextField;
    AboutBox.addItem(aTextField);

    ttfGetStringSize(MenuTUI.mainFont, 'ver ' + GFXVer + ' (c) by Key-Real', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - VipGFX ver', 200 - sizeX div 2, 104, 'ver '+GFXVer+' (c) by Key-Real');
    aTextField.theme:= LoadThemeTextField;
    aTextField.theme.FontColor:= RGBA(128,128,128,255);
    AboutBox.addItem(aTextField);


    ttfGetStringSize(MenuTUI.mainFont, 'Tralala', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - Tralala', 200 - sizeX div 2, 130 - 2, 'Tralala');
    aTextField.theme:= LoadThemeTextField;
    AboutBox.addItem(aTextField);

    ttfGetStringSize(MenuTUI.mainFont, 'ver ' + TralalaVersionString + ' (c) by nickysn', sizeX, sizeY);
    aTextField:= TtuiTextField.create(AboutBox, 'TextField About - Tralala - ver', 200 - sizeX div 2, 140 + 6 - 2, 'ver ' + TralalaVersionString + ' (c) by nickysn');
    aTextField.theme:= LoadThemeTextField;
    aTextField.theme.FontColor:= RGBA(128,128,128,255);
    AboutBox.addItem(aTextField);


    aButton:= TtuiButton.create(AboutBox, 'Button OK', 130, 220 - 50, 140, 32, 'OK', @execProcButton_BoxAbout_ButtonOK);
    aButton.theme:= LoadThemeButton;
    AboutBox.addItem(aButton);

    inMenuItem:= true;

end;


procedure TMainMenu.execProcButton_BoxAbout_ButtonOK(const param: string);
begin
    MenuTUI.closeBox(AboutBox);

    inMenuItem:= false;
end;