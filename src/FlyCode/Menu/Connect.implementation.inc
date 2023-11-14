procedure TMainMenu.getIPfromDNS;
begin
	
	if myExternalIP <> 'ERROR' then begin
		MenuTUI.closeBox(getIPfromDNSBox);
		EditFieldOwnIP.reloadText(myExternalIP);
		exit;
	end;

	getIPfromDNSBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 150, vscreen.height div 2 - 50, 300, 100, 'getIPfromDNSBox', tuiBoxStd);
    getIPfromDNSBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(getIPfromDNSBox);


	TextFiledGetIPfromDNS:= TtuiTextField.Create(getIPfromDNSBox, 'TextFiledGetIPfromDNS', 20, 24, 'Can''t get External IP');
    TextFiledGetIPfromDNS.theme:= LoadThemeTextField;
    TextFiledGetIPfromDNS.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    getIPfromDNSBox.addItem(TextFiledGetIPfromDNS);

	ButtonGetIPfromDNSRetry:= TtuiButton.create(getIPfromDNSBox, 'ButtonGetIPfromDNSRetry', getIPfromDNSBox.boxWidth - 120, getIPfromDNSBox.boxHeight - 42, 100, 32, 'Retry', @execProcTryAgain);
    ButtonGetIPfromDNSRetry.theme:= LoadThemeButton;
    getIPfromDNSBox.addItem(ButtonGetIPfromDNSRetry);

    ButtonGetIPfromDNSCancel:= TtuiButton.create(getIPfromDNSBox, 'ButtonGetIPfromDNSCancel', 20, getIPfromDNSBox.boxHeight - 42, 100, 32, 'Cancel', @execProcTryAgainCancel);
    ButtonGetIPfromDNSCancel.theme:= LoadThemeButton;
    getIPfromDNSBox.addItem(ButtonGetIPfromDNSCancel);

end;



procedure TMainMenu.execProcTryAgain(const param: string);
begin
	MenuTUI.closeBox(getIPfromDNSBox);
	retrieveIP:= true;
end;

procedure TMainMenu.execProcTryAgainCancel(const param: string);
begin
	MenuTUI.closeBox(getIPfromDNSBox);
	myExternalIP:= 'ERROR';
end;



procedure TMainMenu.execProcMenuItemConnection(const param: string);
var 
    aButton : TtuiButton;

begin

	MenuTUI.closeBox(NewFileBox);

	if assigned(ConnectBox) then exit;

	ConnectBox:= TtuiBox.create(MenuTUI, vscreen.width div 2 - 195, vscreen.height div 2 - 200, 390, 400, 'box connect', tuiBoxStd);
    ConnectBox.themeBox:= LoadThemeBox;
    MenuTUI.addBox(ConnectBox); 


    ButtonConnectNext:= TtuiButton.create(ConnectBox, 'Button Connect Next', ConnectBox.boxWidth - 80, ConnectBox.boxHeight - 42, 70, 32, '>>', @execProcConnectNext);
    ButtonConnectNext.theme:= LoadThemeButton;
    ConnectBox.addItem(ButtonConnectNext);


	ButtonConnectOK:= TtuiButton.create(ConnectBox, 'Button Connect OK', ConnectBox.boxWidth - 80, ConnectBox.boxHeight - 42, 70, 32, 'OK', @execProcConnectSuccess);
    ButtonConnectOK.theme:= LoadThemeButton;
    ButtonConnectOK.enabled:= false;
    ConnectBox.addItem(ButtonConnectOK);



    aButton:= TtuiButton.create(ConnectBox, 'Button Connect Prev', ConnectBox.boxWidth - 160, ConnectBox.boxHeight - 42, 70, 32, '<<', @execProcConnectPrev);
    aButton.theme:= LoadThemeButton;
    ConnectBox.addItem(aButton);

    aButton:= TtuiButton.create(ConnectBox, 'Button Connect Cancel', ConnectBox.boxWidth - 170 - 100, ConnectBox.boxHeight - 42, 100, 32, 'Cancel', @execProcConnectCancel);
    aButton.theme:= LoadThemeButton;
    ConnectBox.addItem(aButton);

    aButton:= TtuiButton.create(ConnectBox, 'Button Connect Help', ConnectBox.boxWidth - 170 - 100 - 100 - 10, ConnectBox.boxHeight - 42, 100, 32, 'Help', @execProcConnectHelp);
    aButton.theme:= LoadThemeButton;
    ConnectBox.addItem(aButton);






	TextFiledEstablishConnectionBoxCaption:= TtuiTextField.Create(ConnectBox, 'TextFiledEstablishConnectionBoxCaption', 10, 10, 'Establish Connection');
    TextFiledEstablishConnectionBoxCaption.theme:= LoadThemeTextField;
    TextFiledEstablishConnectionBoxCaption.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledEstablishConnectionBoxCaption);



    RadioButtonGroupIntro:= TtuiRadioButtonGroup.Create(ConnectBox, 'RadioButtonIntroGroup');
    ConnectBox.addItem(RadioButtonGroupIntro);

    radioButtonServer:= TtuiRadioButton.Create(ConnectBox, 'RadioButtonServer', 32, 64, 'as Server', nil);
    radioButtonServer.theme:= LoadThemeRadioButton;
    RadioButtonGroupIntro.add2group(radioButtonServer);

    radioButtonClient:= TtuiRadioButton.Create(ConnectBox, 'RadioButtonClient', 32, 84, 'as Client', nil);
    radioButtonClient.theme:= LoadThemeRadioButton;
    RadioButtonGroupIntro.add2group(radioButtonClient);


    RadioButtonGroupTypePage:= TtuiRadioButtonGroup.Create(ConnectBox, 'RadioButtonGroupServerPage');
    ConnectBox.addItem(RadioButtonGroupTypePage);

    radioButtonTypeLocal:= TtuiRadioButton.Create(ConnectBox, 'radioButtonTypeLocal', 32, 64, 'through Local Network', nil);
    radioButtonTypeLocal.theme:= LoadThemeRadioButton;
    RadioButtonGroupTypePage.add2group(radioButtonTypeLocal);

    radioButtonTypePortForwarding:= TtuiRadioButton.Create(ConnectBox, 'radioButtonTypePortForwarding', 32, 84, 'through Port Forwarding', nil);
    radioButtonTypePortForwarding.theme:= LoadThemeRadioButton;
    RadioButtonGroupTypePage.add2group(radioButtonTypePortForwarding);

	radioButtonTypeuPnP:= TtuiRadioButton.Create(ConnectBox, 'radioButtonTypeuPnP', 32, 104, 'through uPnP', nil);
    radioButtonTypeuPnP.theme:= LoadThemeRadioButton;
    RadioButtonGroupTypePage.add2group(radioButtonTypeuPnP);

    radioButtonTypeHolePunching:= TtuiRadioButton.Create(ConnectBox, 'radioButtonTypeHolePunching', 32, 124, 'through Hole Punching', nil);
    radioButtonTypeHolePunching.theme:= LoadThemeRadioButton;
    RadioButtonGroupTypePage.add2group(radioButtonTypeHolePunching);

    radioButtonTypeWebServer:= TtuiRadioButton.Create(ConnectBox, 'radioButtonTypeWebServer', 32, 144, 'through Web Server', nil);
    radioButtonTypeWebServer.theme:= LoadThemeRadioButton;
    RadioButtonGroupTypePage.add2group(radioButtonTypeWebServer);

	
	TextFiledOwnIP:= TtuiTextField.Create(ConnectBox, 'TextFiledOwnIP', 32, 50, 'Own IP');
    TextFiledOwnIP.theme:= LoadThemeTextField;
    TextFiledOwnIP.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledOwnIP);

    EditFieldOwnIP:= TtuiEditField.create(ConnectBox, 'EditFieldOwnIP', 32, 64, 226, getLocalIP, nil);
    EditFieldOwnIP.theme:= LoadThemeEditField;
    ConnectBox.addItem(EditFieldOwnIP);

    TextFiledPort:= TtuiTextField.Create(ConnectBox, 'TextFiledPort', 32, 89, 'Port');
    TextFiledPort.theme:= LoadThemeTextField;
    TextFiledPort.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledPort);

    EditFieldPort:= TtuiEditField.create(ConnectBox, 'EditFieldPort', 32, 104, 226, '1234', nil);
    EditFieldPort.theme:= LoadThemeEditField;
    ConnectBox.addItem(EditFieldPort);


    TextFiledRemoteIP:= TtuiTextField.Create(ConnectBox, 'TextFiledRemoteIP', 32, 129, 'Remote IP');
    TextFiledRemoteIP.theme:= LoadThemeTextField;
    TextFiledRemoteIP.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledRemoteIP);

    EditFieldRemoteIP:= TtuiEditField.create(ConnectBox, 'EditFieldRemoteIP', 32, 144, 226, '', nil);
    EditFieldRemoteIP.theme:= LoadThemeEditField;
    ConnectBox.addItem(EditFieldRemoteIP);

	TextFiledRemoteIP.enabled:= false;
	EditFieldRemoteIP.enabled:= false;

	TextFiledRemoteServer:= TtuiTextField.Create(ConnectBox, 'TextFiledRemoteServer', 32, 129, 'Remote Server');
    TextFiledRemoteServer.theme:= LoadThemeTextField;
    TextFiledRemoteServer.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledRemoteServer);

    EditFieldRemoteServer:= TtuiEditField.create(ConnectBox, 'EditFieldRemoteServer', 32, 144, 226, 'www.flytracker.net', nil);
    EditFieldRemoteServer.theme:= LoadThemeEditField;
    ConnectBox.addItem(EditFieldRemoteServer);

    TextFiledSessionName:= TtuiTextField.Create(ConnectBox, 'TextFiledSessionName', 32, 129 + 38, 'Session Name');
    TextFiledSessionName.theme:= LoadThemeTextField;
    TextFiledSessionName.theme.FontColor:= Theme_Tracker_MainPanel_FontColor;
    ConnectBox.addItem(TextFiledSessionName);

    EditFieldSessionName:= TtuiEditField.create(ConnectBox, 'EditFieldSessionName', 32, 144 + 40, 226, '', nil);
    EditFieldSessionName.theme:= LoadThemeEditField;
    ConnectBox.addItem(EditFieldSessionName);


	showPage(IntroPage, false);
    showPage(TypePage, false);
    showPage(LocalPage, false);
    showPage(ForwardingPage, false);
    showPage(uPnPPage, false);
	showPage(HolePunchingPage, false);
	showPage(WebServerPage, false);

    showPage(IntroPage, true);

    curConnectMenuPage:= IntroPage;

    inMenuItem:= true;

end;


procedure TMainMenu.showPage(curPage: TConnectMenuPage; enable: boolean);
begin
	
	if curPage = IntroPage then begin
		radioButtonServer.enabled:= enable;
		radioButtonClient.enabled:= enable;
		ButtonConnectNext.enabled:= enable
	end;

	if curPage = TypePage then begin
		radioButtonTypeLocal.enabled:= enable;
		radioButtonTypePortForwarding.enabled:= enable;
		radioButtonTypeuPnP.enabled:= enable;
		radioButtonTypeHolePunching.enabled:= enable;
		radioButtonTypeWebServer.enabled:= enable;
		ButtonConnectNext.enabled:= enable;
	end;

	if curPage = LocalPage then begin
		TextFiledOwnIP.enabled:= enable;
		EditFieldOwnIP.enabled:= enable;
		TextFiledPort.enabled:= enable;
		EditFieldPort.enabled:= enable;
		if radioButtonClient.checked then begin
			TextFiledRemoteIP.enabled:= enable;
			EditFieldRemoteIP.enabled:= enable;
		end;
		ButtonConnectNext.enabled:= false;
		ButtonConnectOK.enabled:= enable;
	end;

	if curPage = ForwardingPage then begin
		TextFiledOwnIP.enabled:= enable;
		EditFieldOwnIP.enabled:= enable;
		TextFiledPort.enabled:= enable;
		EditFieldPort.enabled:= enable;
		if radioButtonClient.checked then begin
			TextFiledRemoteIP.enabled:= enable;
			EditFieldRemoteIP.enabled:= enable;
		end;
		ButtonConnectNext.enabled:= false;
		ButtonConnectOK.enabled:= enable;
	end;

	if curPage = uPnPPage then begin
		TextFiledOwnIP.enabled:= enable;
		EditFieldOwnIP.enabled:= enable;
		TextFiledPort.enabled:= enable;
		EditFieldPort.enabled:= enable;
		if radioButtonClient.checked then begin
			TextFiledRemoteIP.enabled:= enable;
			EditFieldRemoteIP.enabled:= enable;
		end;
		ButtonConnectNext.enabled:= false;
		ButtonConnectOK.enabled:= enable;
	end;

	if curPage = HolePunchingPage then begin
		TextFiledRemoteServer.enabled:= enable;
		EditFieldRemoteServer.enabled:= enable;
		ButtonConnectNext.enabled:= false;
		ButtonConnectOK.enabled:= enable;
		TextFiledSessionName.enabled:= enable;
		EditFieldSessionName.enabled:= enable;
	end;

	if curPage = WebServerPage then begin
		TextFiledRemoteServer.enabled:= enable;
		EditFieldRemoteServer.enabled:= enable;
		ButtonConnectNext.enabled:= false;
		ButtonConnectOK.enabled:= enable;
		TextFiledSessionName.enabled:= enable;
		EditFieldSessionName.enabled:= enable;
	end;

end;


procedure TMainMenu.execProcConnectNext(const param: string);
begin
	
	if curConnectMenuPage = IntroPage then begin
		showPage(IntroPage, false);
		
		curConnectMenuPage:= TypePage;

		showPage(TypePage, true);
		exit;
	end;

	if curConnectMenuPage = TypePage then begin
		showPage(TypePage, false);
		
		if radioButtonTypeLocal.checked then begin
			curConnectMenuPage:= LocalPage;
			EditFieldOwnIP.reloadText(getLocalIP);
			showPage(LocalPage, true);
			exit;
		end;

		if radioButtonTypePortForwarding.checked then begin
			curConnectMenuPage:= ForwardingPage;
			retrieveIP:=true;
			EditFieldOwnIP.reloadText('');
			showPage(ForwardingPage, true);
			exit;
		end;

		if radioButtonTypeuPnP.checked then begin
			curConnectMenuPage:= uPnPPage;
			EditFieldOwnIP.reloadText('');
			showPage(uPnPPage, true);
			exit;
		end;

		if radioButtonTypeHolePunching.checked then begin
			curConnectMenuPage:= HolePunchingPage;
			showPage(HolePunchingPage, true);
			exit;
		end;

		if radioButtonTypeWebServer.checked then begin
			curConnectMenuPage:= WebServerPage;
			showPage(WebServerPage, true);
			exit;
		end;

		exit;
	end;


end;


procedure TMainMenu.execProcConnectPrev(const param: string);
begin

	if curConnectMenuPage = IntroPage then exit;

	if curConnectMenuPage = TypePage then begin
		showPage(TypePage, false);
		showPage(IntroPage, true);
		curConnectMenuPage:= IntroPage;
		exit;
	end;

	if curConnectMenuPage = LocalPage then begin
		showPage(LocalPage, false);
		showPage(TypePage, true);
		curConnectMenuPage:= TypePage;
		exit;
	end;

	if curConnectMenuPage = ForwardingPage then begin
		showPage(ForwardingPage, false);
		showPage(TypePage, true);
		curConnectMenuPage:= TypePage;

		exit;
	end;

	if curConnectMenuPage = uPnPPage then begin
		showPage(uPnPPage, false);
		showPage(TypePage, true);
		curConnectMenuPage:= TypePage;

		exit;
	end;

	if curConnectMenuPage = HolePunchingPage then begin
		showPage(HolePunchingPage, false);
		showPage(TypePage, true);
		curConnectMenuPage:= TypePage;

		exit;
	end;

	if curConnectMenuPage = WebServerPage then begin
		showPage(WebServerPage, false);
		showPage(TypePage, true);
		curConnectMenuPage:= TypePage;

		exit;
	end;

end;


procedure TMainMenu.execProcConnectSuccess(const param: string);
begin
	
	MenuTUI.closeBox(ConnectBox);

    inMenuItem:= false;

end;


procedure TMainMenu.execProcConnectCancel(const param: string);
begin

	MenuTUI.closeBox(ConnectBox);

    inMenuItem:= false;

end;


const
        HelpTextIntro = 'Intro' + endl;
        HelpTextType = 'Connection Type' + endl;
        HelpTextLocal = 'Local' + endl;
        HelpTextForwarding = 'Forwarding' + endl;
        HelpTextuPnP = 'uPnP' + endl;
        HelpTextHolePunching = 'HolePunching' + endl;
        HelpTextWebServer = 'WebServer' + endl;


procedure TMainMenu.execProcConnectHelp(const param: string);
var
    aTextBox : TtuiTextBox;
    aButton : TtuiButton;	
begin
	
	if assigned(ConnectionHelpBox) then exit;

	ConnectionHelpBox:= TtuiBox.create(MenuTUI,vscreen.width div 2 - 232, 100, 464, 480, 'boxconnecthelp', tuiBoxStd);
	ConnectionHelpBox.themeBox:= LoadThemeBox;
	MenuTUI.addBox(ConnectionHelpBox);

    aTextBox:= TtuiTextBox.Create(ConnectionHelpBox, 'TextBox Connect Help', 10, 10, ConnectionHelpBox.boxWidth - 20, ConnectionHelpBox.boxHeight - 64);
    aTextBox.theme:= LoadThemeTextBox;
    ConnectionHelpBox.addItem(aTextBox);


    aButton:= TtuiButton.create(ConnectionHelpBox, 'Button OK', ConnectionHelpBox.boxWidth - 128, ConnectionHelpBox.boxHeight - 44, 116, 32, 'OK', @execProcButtonConnectionBoxHelpOK);
    aButton.theme:= LoadThemeButton;
    ConnectionHelpBox.addItem(aButton);

	if curConnectMenuPage = IntroPage then aTextBox.loadText(HelpTextIntro);
	if curConnectMenuPage = TypePage then aTextBox.loadText(HelpTextType);
	if curConnectMenuPage = LocalPage then aTextBox.loadText(HelpTextLocal);
	if curConnectMenuPage = ForwardingPage then aTextBox.loadText(HelpTextForwarding);
	if curConnectMenuPage = uPnPPage then aTextBox.loadText(HelpTextuPnP);
	if curConnectMenuPage = HolePunchingPage then aTextBox.loadText(HelpTextHolePunching);
	if curConnectMenuPage = WebServerPage then aTextBox.loadText(HelpTextWebServer);

    inMenuItem:= true;

end;


procedure TMainMenu.execProcButtonConnectionBoxHelpOK(const param: string);
begin

	MenuTUI.closeBox(ConnectionHelpBox);
	inMenuItem:= false;

end;