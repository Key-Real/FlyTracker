type
		TConnectMenuPage = (IntroPage, TypePage, LocalPage, ForwardingPage, uPnPPage, HolePunchingPage, WebServerPage);

var
        ConnectBox : TtuiBox; 

        curConnectMenuPage : TConnectMenuPage;

        TextFiledEstablishConnectionBoxCaption : TtuiTextField;
        
        ButtonConnectNext : TtuiButton;
        ButtonConnectOK : TtuiButton;

        RadioButtonGroupIntro : TtuiRadioButtonGroup;
        radioButtonServer : TtuiRadioButton;
        radioButtonClient : TtuiRadioButton;

        RadioButtonGroupTypePage : TtuiRadioButtonGroup;
        radioButtonTypeLocal : TtuiRadioButton;
        radioButtonTypePortForwarding : TtuiRadioButton;
        radioButtonTypeuPnP : TtuiRadioButton;
        radioButtonTypeHolePunching : TtuiRadioButton;
        radioButtonTypeWebServer : TtuiRadioButton;

        TextFiledOwnIP : TtuiTextField;
        EditFieldOwnIP : TtuiEditField;
        TextFiledPort : TtuiTextField;
        EditFieldPort : TtuiEditField;

        TextFiledRemoteIP : TtuiTextField;
        EditFieldRemoteIP : TtuiEditField;

        TextFiledRemoteServer : TtuiTextField;
        EditFieldRemoteServer : TtuiEditField;

        TextFiledSessionName : TtuiTextField;
        EditFieldSessionName : TtuiEditField;      


        ConnectionHelpBox : TtuiBox;

procedure execProcButtonConnectionBoxHelpOK(const param: string);


procedure execProcMenuItemConnection(const param: string);

procedure showPage(curPage: TConnectMenuPage; enable: boolean);


procedure execProcConnectSuccess(const param: string);
procedure execProcConnectNext(const param: string);
procedure execProcConnectPrev(const param: string);
procedure execProcConnectCancel(const param: string);
procedure execProcConnectHelp(const param: string);

var
    
    getIPfromDNSBox : TtuiBox;
    TextFiledGetIPfromDNS : TtuiTextField;
    ButtonGetIPfromDNSRetry : TtuiButton;
    ButtonGetIPfromDNSCancel : TtuiButton;
procedure getIPfromDNS;
procedure execProcTryAgain(const param: string);
procedure execProcTryAgainCancel(const param: string);