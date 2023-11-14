var
	MenuHelpItem : TtuiMenuHorizontalItem;
	AboutBox : TtuiBox;
	HowToUseBox : TtuiBox;
	KeyBindingsBox : TtuiBox;


procedure execProcMenuHelpSelect(const param: string);
procedure execProcMenuHelpUnSelect(const param: string);


    
procedure execProcMenuItemAbout(const param: string);
procedure execProcButton_BoxAbout_ButtonOK(const param: string);


procedure execProcMenuItemHowToUse(const param: string);
procedure execProcButton_BoxHowTo_ButtonOK(const param: string);	

procedure execProcMenuItemKeybindings(const param: string);
procedure execProcButton_BoxKeybindings_ButtonOK(const param: string);