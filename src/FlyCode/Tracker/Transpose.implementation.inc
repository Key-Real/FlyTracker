procedure TTracker.BuildTranspose;
var 
    x :dword;
    xx, yy : longint;
begin

    xx:= 10;
    yy:= 10;

    TextFieldTrack:= TtuiTextField.create(MainPanel, 'TextField Trak', xx + 616, yy + 37, 'Track');
    TextFieldTrack.theme:= LoadThemeTextField;
    TextFieldTrack.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldTrack);

    TextFieldPattern:= TtuiTextField.create(MainPanel, 'TextField Pattern', xx + 616, yy + 37 + 27, 'Pattern');
    TextFieldPattern.theme:= LoadThemeTextField;
    TextFieldPattern.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldPattern);

    TextFieldSong:= TtuiTextField.create(MainPanel, 'TextField Song', xx + 616, yy + 37 + 27 * 2, 'Song');
    TextFieldSong.theme:= LoadThemeTextField;
    TextFieldSong.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldSong);

    TextFieldBlock:= TtuiTextField.create(MainPanel, 'TextField Block', xx + 616, yy + 37 + 27 * 3, 'Block');
    TextFieldBlock.theme:= LoadThemeTextField;
    TextFieldBlock.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldBlock);


	TextFieldCurrentInstrument:= TtuiTextField.create(MainPanel, 'TextField CurrentInstrument', xx + 664 + 33, yy + 6, 'Current Instrument');
    TextFieldCurrentInstrument.theme:= LoadThemeTextField;
    TextFieldCurrentInstrument.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldCurrentInstrument);

    TextFieldAllInstruments:= TtuiTextField.create(MainPanel, 'TextField AllInstruments', xx + 884, yy + 6, 'All Instruments');
    TextFieldAllInstruments.theme:= LoadThemeTextField;
    TextFieldAllInstruments.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    MainPanel.addItem(TextFieldAllInstruments);

    x:= 42;
    ButtonCurrentInstrumentTrackUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentTrackUP', xx + 664, yy + 1 * 28 + 2, x, 27, 'up', @execProcButtonCurrentInstrumentTrackUP);
    ButtonCurrentInstrumentTrackUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentTrackUP);
    ButtonCurrentInstrumentTrackDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentTrackDown', xx + 664 + x + 1, yy + 1 * 28 + 2, x, 27, 'dn', @execProcButtonCurrentInstrumentTrackDown);
    ButtonCurrentInstrumentTrackDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentTrackDown);
    ButtonCurrentInstrumentTrack12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentTrack12UP', xx + 664 + x * 2 + 2, yy + 1 * 28 + 2, x, 27, '12 up', @execProcButtonCurrentInstrumentTrack12UP);
    ButtonCurrentInstrumentTrack12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentTrack12UP);
    ButtonCurrentInstrumentTrack12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentTrack12Down', xx + 664 + x * 3 + 3, yy + 1 * 28 + 2, x, 27, '12 dn', @execProcButtonCurrentInstrumentTrack12Down);
    ButtonCurrentInstrumentTrack12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentTrack12Down);

    ButtonAllInstrumentsTrackUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsTrackUP', xx + 664 + x * 4 + 8, yy + 1 * 28 + 2, x, 27, 'up', @execProcButtonAllInstrumentsTrackUP);
    ButtonAllInstrumentsTrackUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsTrackUP);
    ButtonAllInstrumentsTrackDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsTrackDown', xx + 664 + x * 5 + 1 + 8, yy + 1 * 28 + 2, x, 27, 'dn', @execProcButtonAllInstrumentsTrackDown);
    ButtonAllInstrumentsTrackDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsTrackDown);
    ButtonAllInstrumentsTrack12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsTrack12UP', xx + 664 + x * 6 + 8 + 2, yy + 1 * 28 + 2, x, 27, '12 up', @execProcButtonAllInstrumentsTrack12UP);
    ButtonAllInstrumentsTrack12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsTrack12UP);
    ButtonAllInstrumentsTrack12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsTrack12Down', xx + 664 + x * 7 + 8 + 3, yy + 1*28 + 2, x, 27, '12 dn', @execProcButtonAllInstrumentsTrack12Down);
    ButtonAllInstrumentsTrack12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsTrack12Down);

    ButtonCurrentInstrumentPatternUP:= TtuiButton.create(MainPanel,'Tracker_ButtonCurrentInstrumentPatternUP', xx + 664, yy + 2 * 28 + 3 - 1, x, 27, 'up', @execProcButtonCurrentInstrumentPatternUP);
    ButtonCurrentInstrumentPatternUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentPatternUP);
    ButtonCurrentInstrumentPatternDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentPatternDown', xx + 664 + x + 1, yy + 2 * 28 + 3 - 1, x, 27, 'dn', @execProcButtonCurrentInstrumentPatternDown);
    ButtonCurrentInstrumentPatternDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentPatternDown);
    ButtonCurrentInstrumentPattern12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentPattern12UP', xx + 664 + x * 2 + 2, yy + 2 * 28 + 3 - 1, x, 27, '12 up', @execProcButtonCurrentInstrumentPattern12UP);
    ButtonCurrentInstrumentPattern12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentPattern12UP);
    ButtonCurrentInstrumentPattern12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentPattern12Down', xx + 664 + x * 3 + 3, yy + 2 * 28 + 3 - 1, x, 27, '12 dn', @execProcButtonCurrentInstrumentPattern12Down);
    ButtonCurrentInstrumentPattern12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentPattern12Down);

    ButtonAllInstrumentsPatternUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentwPatternUP', xx + 664 + x * 4 + 8, yy + 2 * 28 + 3 - 1, x, 27, 'up', @execProcButtonAllInstrumentsPatternUP);
    ButtonAllInstrumentsPatternUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsPatternUP);
    ButtonAllInstrumentsPatternDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsPatternDown', xx + 664 + x * 5 + 1 + 8, yy + 2 * 28 + 3 - 1, x, 27, 'dn', @execProcButtonAllInstrumentsPatternDown);
    ButtonAllInstrumentsPatternDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsPatternDown);
    ButtonAllInstrumentsPattern12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsPattern12UP', xx + 664 + x * 6 + 8 + 2, yy + 2 * 28 + 3 - 1, x, 27, '12 up', @execProcButtonAllInstrumentsPattern12UP);
    ButtonAllInstrumentsPattern12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsPattern12UP);
    ButtonAllInstrumentsPattern12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsPattern12Down', xx + 664 + x * 7 + 8 + 3, yy + 2 * 28 + 3 - 1, x, 27, '12 dn', @execProcButtonAllInstrumentsPattern12Down);
    ButtonAllInstrumentsPattern12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsPattern12Down);

	ButtonCurrentInstrumentSongUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentSongUP', xx + 664, yy + 3 * 28 + 2, x, 27, 'up', @execProcButtonCurrentInstrumentSongUP);
    ButtonCurrentInstrumentSongUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentSongUP);
    ButtonCurrentInstrumentSongDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentSongDown', xx + 664 + x + 1, yy + 3 * 28 + 2, x, 27, 'dn', @execProcButtonCurrentInstrumentSongDown);
    ButtonCurrentInstrumentSongDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentSongDown);
    ButtonCurrentInstrumentSong12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentSong12UP', xx + 664 + x * 2 + 2, yy + 3 * 28 + 2, x, 27, '12 up', @execProcButtonCurrentInstrumentSong12UP);
    ButtonCurrentInstrumentSong12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentSong12UP);
    ButtonCurrentInstrumentSong12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentSong12Down', xx + 664 + x * 3 + 3, yy + 3 * 28 + 2, x, 27, '12 dn', @execProcButtonCurrentInstrumentSong12Down);
    ButtonCurrentInstrumentSong12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentSong12Down);

    ButtonAllInstrumentsSongUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsSongUP', xx + 664 + x * 4 + 8, yy + 3 * 28 + 2, x, 27, 'up', @execProcButtonAllInstrumentsSongUP);
    ButtonAllInstrumentsSongUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsSongUP);
    ButtonAllInstrumentsSongDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsSongDown', xx + 664 + x * 5 + 1 + 8, yy + 3 * 28 + 2, x, 27, 'dn', @execProcButtonAllInstrumentsSongDown);
    ButtonAllInstrumentsSongDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsSongDown);
    ButtonAllInstrumentsSong12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsSong12UP', xx + 664 + x * 6 + 8 + 2, yy + 3 * 28 + 2, x, 27, '12 up', @execProcButtonAllInstrumentsSong12UP);
    ButtonAllInstrumentsSong12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsSong12UP);
    ButtonAllInstrumentsSong12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsSong12Down', xx + 664 + x * 7 + 8 + 3, yy + 3 * 28 + 2, x, 27, '12 dn', @execProcButtonAllInstrumentsSong12Down);
    ButtonAllInstrumentsSong12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsSong12Down);

	ButtonCurrentInstrumentBlockUP:= TtuiButton.create(MainPanel,'Tracker_ButtonCurrentInstrumentBlockUP', xx + 664, yy + 4 * 28 + 2, x, 27, 'up', @execProcButtonCurrentInstrumentBlockUP);
    ButtonCurrentInstrumentBlockUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentBlockUP);
    ButtonCurrentInstrumentBlockDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentBlockDown', xx + 664 + x + 1, yy + 4 * 28 + 2, x, 27, 'dn', @execProcButtonCurrentInstrumentBlockDown);
    ButtonCurrentInstrumentBlockDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentBlockDown);
    ButtonCurrentInstrumentBlock12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentBlock12UP', xx + 664 + x * 2 + 2, yy + 4 * 28 + 2, x, 27, '12 up', @execProcButtonCurrentInstrumentBlock12UP);
    ButtonCurrentInstrumentBlock12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentBlock12UP);
    ButtonCurrentInstrumentBlock12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonCurrentInstrumentBlock12Down', xx + 664 + x * 3 + 3, yy + 4 * 28 + 2, x, 27, '12 dn', @execProcButtonCurrentInstrumentBlock12Down);
    ButtonCurrentInstrumentBlock12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonCurrentInstrumentBlock12Down);

    ButtonAllInstrumentsBlockUP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsBlockUP', xx + 664 + x * 4 + 8, yy + 4 * 28 + 2, x, 27, 'up', @execProcButtonAllInstrumentsBlockUP);
    ButtonAllInstrumentsBlockUP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsBlockUP);
    ButtonAllInstrumentsBlockDown:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsBlockDown', xx + 664 + x * 5 + 1 + 8, yy + 4 * 28 + 2, x, 27, 'dn', @execProcButtonAllInstrumentsBlockDown);
    ButtonAllInstrumentsBlockDown.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsBlockDown);
    ButtonAllInstrumentsBlock12UP:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsBlock12UP', xx + 664 + x * 6 + 8 + 2, yy + 4 * 28 + 2, x, 27, '12 up', @execProcButtonAllInstrumentsBlock12UP);
    ButtonAllInstrumentsBlock12UP.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsBlock12UP);
    ButtonAllInstrumentsBlock12Down:= TtuiButton.create(MainPanel, 'Tracker_ButtonAllInstrumentsBlock12Down', xx + 664 + x * 7 + 8 + 3, yy + 4 * 28 + 2, x, 27, '12 dn', @execProcButtonAllInstrumentsBlock12Down);
    ButtonAllInstrumentsBlock12Down.theme:= LoadThemeButton;
    MainPanel.addItem(ButtonAllInstrumentsBlock12Down);

    EnableDisableTranspose(false);

end;


procedure TTracker.EnableDisableTranspose(enable: boolean);
begin

	TextFieldCurrentInstrument.enabled:= enable;
	TextFieldAllInstruments.enabled:= enable;

	TextFieldTrack.enabled:= enable;
	TextFieldPattern.enabled:= enable;
	TextFieldSong.enabled:= enable;
	TextFieldBlock.enabled:= enable;

	ButtonCurrentInstrumentTrackUP.enabled:= enable;
	ButtonCurrentInstrumentTrackDown.enabled:= enable;
	ButtonCurrentInstrumentTrack12UP.enabled:= enable;
	ButtonCurrentInstrumentTrack12Down.enabled:= enable;
	ButtonCurrentInstrumentPatternUP.enabled:= enable;
	ButtonCurrentInstrumentPatternDown.enabled:= enable;
	ButtonCurrentInstrumentPattern12Up.enabled:= enable;
	ButtonCurrentInstrumentPattern12Down.enabled:= enable;
	ButtonCurrentInstrumentSongUp.enabled:= enable;
	ButtonCurrentInstrumentSongDown.enabled:= enable;
	ButtonCurrentInstrumentSong12Up.enabled:= enable;
	ButtonCurrentInstrumentSong12Down.enabled:= enable;
	ButtonCurrentInstrumentBlockUp.enabled:= enable;
	ButtonCurrentInstrumentBlockDown.enabled:= enable;
	ButtonCurrentInstrumentBlock12Up.enabled:= enable;
	ButtonCurrentInstrumentBlock12Down.enabled:=enable;

	ButtonAllInstrumentsTrackUP.enabled:= enable;
	ButtonAllInstrumentsTrackDown.enabled:= enable;
	ButtonAllInstrumentsTrack12UP.enabled:= enable;
	ButtonAllInstrumentsTrack12Down.enabled:= enable;
	ButtonAllInstrumentsPatternUP.enabled:= enable;
	ButtonAllInstrumentsPatternDown.enabled:= enable;
	ButtonAllInstrumentsPattern12Up.enabled:= enable;
	ButtonAllInstrumentsPattern12Down.enabled:= enable;
	ButtonAllInstrumentsSongUp.enabled:= enable;
	ButtonAllInstrumentsSongDown.enabled:= enable;
	ButtonAllInstrumentsSong12Up.enabled:= enable;
	ButtonAllInstrumentsSong12Down.enabled:= enable;
	ButtonAllInstrumentsBlockUp.enabled:= enable;
	ButtonAllInstrumentsBlockDown.enabled:= enable;
	ButtonAllInstrumentsBlock12Up.enabled:= enable;
	ButtonAllInstrumentsBlock12Down.enabled:= enable;

end;


procedure TTracker.doButtonCurrentInstrumentTrackUP;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                n:= note.note;
                n:= n + 1;
                if n >= 119 then n:= 119;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
           end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TTracker.execProcButtonCurrentInstrumentTrackUP(const param: string);
begin

    doButtonCurrentInstrumentTrackUP;

    netSendButtonCurrentInstrumentTrackUP;

end;


procedure TTracker.doButtonCurrentInstrumentTrackDown;
var 
    i : longint;
    note : TNote;
    n : longint;

begin
    
    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                n:= note.note;
                n:= n - 1;
                if n <= 0 then n:= 0;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
           end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentTrackDown(const param: string);
begin

    doButtonCurrentInstrumentTrackDown;

    netSendButtonCurrentInstrumentTrackDown;

end;


procedure TTracker.doButtonCurrentInstrumentTrack12UP;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                n:= note.note;
                n:= n + 12;
                if n >= 119 then n:= 119;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;        
           end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentTrack12UP(const param: string);
begin

    doButtonCurrentInstrumentTrack12UP;

    netSendButtonCurrentInstrumentTrack12UP;

end;


procedure TTracker.doButtonCurrentInstrumentTrack12Down;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                n:= note.note;
                n:= n - 12;
                if n <= 0 then n:= 0;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
           end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentTrack12Down(const param: string);
begin

    doButtonCurrentInstrumentTrack12Down;

    netSendButtonCurrentInstrumentTrack12Down;

end;


procedure TTracker.doButtonAllInstrumentsTrackUP;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if note.note <> NoteNothing then begin
                n:= note.note;
                n:= n + 1;
                if n >= 119 then n:= 119;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;

procedure TTracker.execProcButtonAllInstrumentsTrackUP(const param: string);
begin

    doButtonAllInstrumentsTrackUP;

    netSendButtonAllInstrumentsTrackUP;

end;


procedure TTracker.doButtonAllInstrumentsTrackDown;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if note.note <> NoteNothing then begin
                n:= note.note;
                n:= n - 1;
                if n <= 0 then n:= 0;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;



procedure TTracker.execProcButtonAllInstrumentsTrackDown(const param: string);
begin

    doButtonAllInstrumentsTrackDown;

    netSendButtonAllInstrumentsTrackDown;

end;


procedure TTracker.doButtonAllInstrumentsTrack12UP;
var 
    i : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if note.note <> NoteNothing then begin
                n:= note.note;
                n:= n + 12;
                if n >= 119 then n:= 119;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsTrack12UP(const param: string);
begin

    doButtonAllInstrumentsTrack12UP;

    netSendButtonAllInstrumentsTrack12UP;

end;


procedure TTracker.doButtonAllInstrumentsTrack12Down;
var 
    i : longint;
    note : TNote;
    n : longint;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            
            note:= Module.Patterns[CurrentPattern].notes[i, currentChannel];
            if note.note <> NoteNothing then begin
                n:= note.note;
                n:= n - 12;
                if n <= 0 then n:= 0;
                note.note:= n;
                Module.Patterns[CurrentPattern].notes[i, currentChannel]:= note;
            end;

        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsTrack12Down(const param: string);
begin

    doButtonAllInstrumentsTrack12Down;

    netSendButtonAllInstrumentsTrack12Down;

end;

procedure TTracker.doButtonCurrentInstrumentPatternUP;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                    n:= note.note;
                    n:= n + 1;
                    if n >= 119 then n:= 119;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i, l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentPatternUP(const param: string);
begin

    doButtonCurrentInstrumentPatternUP;

    netSendButtonCurrentInstrumentPatternUP;

end;


procedure TTracker.doButtonCurrentInstrumentPatternDown;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                    n:= note.note;
                    n:= n - 1;
                    if n <= 0 then n:= 0;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i, l]:= note;        
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentPatternDown(const param: string);
begin
    
    doButtonCurrentInstrumentPatternDown;

    netSendButtonCurrentInstrumentPatternDown;

end;


procedure TTracker.doButtonCurrentInstrumentPattern12UP;
var 
    i, l : longint;
    note : TNote;
    n : longint;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                    n:= note.note;
                    n:= n + 12;
                    if n >= 119 then n:= 119;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i,l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;


end;


procedure TTracker.execProcButtonCurrentInstrumentPattern12UP(const param: string);
begin

    doButtonCurrentInstrumentPattern12UP;

    netSendButtonCurrentInstrumentPattern12UP;

end;


procedure TTracker.doButtonCurrentInstrumentPattern12Down;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                    n:= note.note;
                    n:= n - 12;
                    if n <= 0 then n:= 0;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i, l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;



procedure TTracker.execProcButtonCurrentInstrumentPattern12Down(const param: string);
begin

    doButtonCurrentInstrumentPattern12Down;

    netSendButtonCurrentInstrumentPattern12Down;

end;


procedure TTracker.doButtonAllInstrumentsPatternUP;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if note.note <> NoteNothing then begin
                    n:= note.note;
                    n:= n + 1;
                    if n >= 119 then n:= 119;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i,l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsPatternUP(const param: string);
begin
    
    doButtonAllInstrumentsPatternUP;

    netSendButtonAllInstrumentsPatternUP;

end;


procedure TTracker.doButtonAllInstrumentsPatternDown;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if note.note <> NoteNothing then begin
                    n:= note.note;
                    n:= n - 1;
                    if n <= 0 then n:= 0;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i, l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsPatternDown(const param: string);
begin

    doButtonAllInstrumentsPatternDown;

    netSendButtonAllInstrumentsPatternDown;

end;


procedure TTracker.doButtonAllInstrumentsPattern12UP;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if note.note <> NoteNothing then begin
                    n:= note.note;
                    n:= n + 12;
                    if n >= 119 then n:= 119;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i,l]:= note;
                end;

            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsPattern12UP(const param: string);
begin

    doButtonAllInstrumentsPattern12UP;

    netSendButtonAllInstrumentsPattern12UP;

end;


procedure TTracker.doButtonAllInstrumentsPattern12Down;
var 
    i, l : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for i:= 0 to Module.Patterns[CurrentPattern].RowsCount - 1 do begin
            for l:= 1 to Module.NumberOFChannels do begin
                note:= Module.Patterns[CurrentPattern].notes[i, l];
                if note.note <> NoteNothing then begin
                    n:= note.note;
                    n:= n - 12;
                    if n <= 0 then n:= 0;
                    note.note:= n;
                    Module.Patterns[CurrentPattern].notes[i,l]:= note;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsPattern12Down(const param: string);
begin

    doButtonAllInstrumentsPattern12Down;

    netSendButtonAllInstrumentsPattern12Down;

end;


procedure TTracker.doButtonCurrentInstrumentSongUP;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);
    
        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                        n:= note.note;
                        n:= n + 1;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;
    
    tralalaEngine.Unlock_Module_ReadWrite;

end;



procedure TTracker.execProcButtonCurrentInstrumentSongUP(const param: string);
begin

    doButtonCurrentInstrumentSongUP;

    netSendButtonCurrentInstrumentSongUP;

end;


procedure TTracker.doButtonCurrentInstrumentSongDown;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                        n:= note.note;
                        n:= n - 1;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[k].notes[i,l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentSongDown(const param: string);
begin

    doButtonCurrentInstrumentSongDown;

    netSendButtonCurrentInstrumentSongDown;

end;


procedure TTracker.doButtonCurrentInstrumentSong12UP;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                        n:= note.note;
                        n:= n + 12;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentSong12UP(const param: string);
begin

    doButtonCurrentInstrumentSong12UP;

    netSendButtonCurrentInstrumentSong12UP;

end;


procedure TTracker.doButtonCurrentInstrumentSong12Down;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if (note.note <> NoteNothing) and (note.instrument = currentInstrument) then begin
                        n:= note.note;
                        n:= n - 12;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[k].notes[i,l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;
    
end;


procedure TTracker.execProcButtonCurrentInstrumentSong12Down(const param: string);
begin

    doButtonCurrentInstrumentSong12Down;

    netSendButtonCurrentInstrumentSong12Down;

end;


procedure TTracker.doButtonAllInstrumentsSongUP;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n + 1;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsSongUP(const param: string);
begin

    doButtonAllInstrumentsSongUP;

    netSendButtonAllInstrumentsSongUP;

end;


procedure TTracker.doButtonAllInstrumentsSongDown;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;
begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n - 1;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsSongDown(const param: string);
begin

    doButtonAllInstrumentsSongDown;

    netSendButtonAllInstrumentsSongDown;

end;


procedure TTracker.doButtonAllInstrumentsSong12UP;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n + 12;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;



procedure TTracker.execProcButtonAllInstrumentsSong12UP(const param: string);
begin

    doButtonAllInstrumentsSong12UP;

    netSendButtonAllInstrumentsSong12Up;

end;


procedure TTracker.doButtonAllInstrumentsSong12Down;
var 
    i, l, k : longint;
    note : TNote;
    n : longint;

begin

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for k:= 0 to Module.Patterns.HighestNonEmptyPattern do begin
            for i:= 0 to Module.Patterns[k].RowsCount - 1 do begin
                for l:= 1 to Module.NumberOFChannels do begin
                    note:= Module.Patterns[k].notes[i, l];
                    if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n - 12;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[k].notes[i, l]:= note;
                    end;
                end;
            end;
        end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsSong12Down(const param: string);
begin

    doButtonAllInstrumentsSong12Down;

    netSendButtonAllInstrumentsSong12Down;

end;


procedure TTracker.doButtonCurrentInstrumentBlockUP;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonCurrentInstrumentBlockUP;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);
    
        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if (note.note <> NoteNothing)  and (note.instrument = currentInstrument) then begin
                        n:= note.note;
                        n:= n + 1;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;
    
    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentBlockUP(const param: string);
begin

    doButtonCurrentInstrumentBlockUP;

    netSendButtonCurrentInstrumentBlockUP;

end;


procedure TTracker.doButtonCurrentInstrumentBlockDown;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonCurrentInstrumentBlockDown;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument)  then begin
                        n:= note.note;
                        n:= n - 1;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentBlockDown(const param: string);
begin

    doButtonCurrentInstrumentBlockDown;

    netSendButtonCurrentInstrumentBlockDown;
end;


procedure TTracker.doButtonCurrentInstrumentBlock12UP;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonCurrentInstrumentBlock12Up;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument)  then begin
                        n:= note.note;
                        n:= n + 12;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentBlock12UP(const param: string);
begin

    doButtonCurrentInstrumentBlock12UP;

    netSendButtonCurrentInstrumentBlock12UP;

end;


procedure TTracker.doButtonCurrentInstrumentBlock12Down;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonCurrentInstrumentBlock12Down;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if (note.note <> NoteNothing) and (note.instrument = currentInstrument)  then begin
                        n:= note.note;
                        n:= n - 12;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonCurrentInstrumentBlock12Down(const param: string);
begin

    doButtonCurrentInstrumentBlock12Down;

    netSendButtonCurrentInstrumentBlock12Down;

end;


procedure TTracker.doButtonAllInstrumentsBlockUP;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonAllInstrumentsBlockUP;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n + 1;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsBlockUP(const param: string);
begin

    doButtonAllInstrumentsBlockUP;

    netSendButtonAllInstrumentsBlockUP;

end;


procedure TTracker.doButtonAllInstrumentsBlockDown;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonAllInstrumentsBlockDown;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n - 1;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;



procedure TTracker.execProcButtonAllInstrumentsBlockDown(const param: string);
begin

    doButtonAllInstrumentsBlockDown;

    netSendButtonAllInstrumentsBlockDown;

end;


procedure TTracker.doButtonAllInstrumentsBlock12UP;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonAllInstrumentsBlock12Up;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n + 12;
                        if n >= 119 then n:= 119;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsBlock12UP(const param: string);
begin

    doButtonAllInstrumentsBlock12UP;

    netSendButtonAllInstrumentsBlock12UP;

end;


procedure TTracker.doButtonAllInstrumentsBlock12Down;
var 
    x, y : longint;
    note : Tnote;
    n : longint;

begin

    netSendButtonAllInstrumentsBlock12Down;


    if selectedPattern <> CurrentPattern then exit;
    if not isInSelection then exit;

    tralalaEngine.Lock_Module_ReadWrite(Module);

        for x:= 0 to blockWidth do
            for y:= 0 to blockHeight do begin
                note:= Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x];
                if note.note <> NoteNothing then begin
                        n:= note.note;
                        n:= n - 12;
                        if n <= 0 then n:= 0;
                        note.note:= n;
                        Module.Patterns[selectedPattern].notes[slotY1 + y, slotX1 + x]:= note;
                end;
            end;

    tralalaEngine.Unlock_Module_ReadWrite;

end;


procedure TTracker.execProcButtonAllInstrumentsBlock12Down(const param: string);
begin

    doButtonAllInstrumentsBlock12Down;

    netSendButtonAllInstrumentsBlock12Down;

end;