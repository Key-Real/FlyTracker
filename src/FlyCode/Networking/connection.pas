{$MODE OBJFPC} {$H+}
unit connection;
interface
uses
    sockets, SysUtils, nettools
{$IFDEF UNIX}
		, unixtype
{$ENDIF}   
{$IFDEF WINDOWS}
    , winsock
{$ENDIF}
 		, tools;

type TconnectionType = (
	   	connectLocal,
	   	connectHolePunching,
    	connectUPnP,
    	connectPortForwarding
    	 );

const
	serverIP : string = '192.168.100.4';	
	ServerPORT : word = 3333;


  rootServerIP : string = '178.254.3.95';
  rootServerPORT : word = 3333;

var
		socketTCP, socketUDP : longint;
    remoteAddrTCP, remoteAddrUDP : sockaddr_in;
    remoteAddrSLen : dword;

    isClient : boolean;

    isConnected : boolean;
    theConnectionType : TconnectionType;


procedure SocketError(s: string);
procedure EstablishConnection(connectionType: TconnectionType);
procedure CloseConnection;


implementation
uses upnplib;

var
	serverSocketTCP : longint;


procedure SocketError(s: string);
begin
  logwrite('Socket Error: ' + s);
  CloseConnection;
  halt;
end;


const
    localServerPORT : word = 5544;

var
  UPnP : TUPnP;
  upnpinstalled : boolean;

procedure RefreshAndPrintPortMappings;
var
    s : string;
    i : integer;

begin

  if not UPnP.RefreshPortMapping then
      logwrite('Error RefreshPortMapping' + LineEnding + 'ResultCode: ' + UPNP.LastResultCode.ToString + LineEnding + UPnP.LastResponse);

  if Length(UPnP.PortMappings) > 0 then begin

      logwrite('Portmappings:');
      for i:= 0 to Length(UPnP.PortMappings) - 1 do begin
        
        with UPnP.PortMappings[i] do
          S:= Format('%d %s %d->%s:%d %s %d s', [i, Protocol, ExternalPort, InternalClient, InternalPort, Description, LeaseDuration]);
        	logwrite(S);

      end;

  end else
      logwrite('No portmappings');

end;


procedure setupUPnP;
var
  Status : string;
  LastError : string;
  Uptime : integer;
  s : string;

begin
	(*
		socketTCP : s:= 'TCP';
		socketUDP : s:= 'UDP';

	upnpinstalled:= false;

  UPnP:= TUPnP.Create('0.0.0.0');

  try

    if UPnP.IsUPnPAvailable then begin
      logwrite('UPnP device is available at ' + UPnP.ControlURL);

      UPnP.GetStatusInfo(Status, LastError, Uptime);

      logwrite('Internal IP: ' + UPnP.InternalIP);
      logwrite('External IP: ' + UPnP.ExternalIP);
      logwrite('Status: ' + Status);
      logwrite('Last error: ' + LastError);
      logwrite('Uptime router: ' + format('%d days %d hours %d minutes and %d seconds', [Uptime div 86400, (Uptime div 3600) mod 24, (Uptime div 60) mod 60, Uptime mod 60]));
      

      
      if UPnP.SetPortMapping(UPnP.InternalIP, localServerPORT, ServerPORT, s, 'FlyTracker') then begin
        if UPnP.GetSpecificPortMapping(ServerPORT, s).InternalClient = UPnP.InternalIP then
          logwrite('SetPortMapping OK')
        else
          logwrite('SetPortMapping reports OK but Port does not seem to be forwarded');

        RefreshAndPrintPortMappings;

        upnpinstalled:=true;
      end else begin

        logwrite('Error SetPortMapping' + LineEnding + 'ResultCode: ' + UPNP.LastResultCode.ToString + LineEnding + UPnP.LastResponse);
        halt;

      end;


    end else begin

      logwrite('UPnP is not available.');
      halt;

    end;
  finally

  end;
*)
end;


procedure FreeUPnP;
var 
	s : string;
begin
(*
	if not upnpinstalled then exit;

	case theSocketType of
		socketTCP : s:= 'TCP';
		socketUDP : s:= 'UDP';
	end;

  if UPnP.DeletePortMapping(ServerPORT,s) then begin
      logwrite('DeletePortMapping OK');
  end else begin
      logwrite('Error DeletePortMapping' + LineEnding + 'ResultCode: ' + UPNP.LastResultCode.ToString + LineEnding + UPnP.LastResponse);
  end;
 
  RefreshAndPrintPortMappings;

	UPnP.Free;
*)
end;


procedure connectByHolePunching;
var 
		buf : record
				host : dword;
    		port : word;
		end;

		hiBuf : array [0..2] of char;			
		serverAddr : sockaddr_in;
		slen : dword;
		i : longint;

begin	
(*
    fillchar(serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family:= AF_INET;
    {$IFDEF WINDOWS}
    	serverAddr.sin_addr.s_addr:= inet_addr(PChar(rootServerIP));
		{$ELSE}
			serverAddr.sin_addr:= StrToNetAddr(rootServerIP);
		{$ENDIF}
		serverAddr.sin_port:= htons(rootServerPORT);

		slen:= sizeof(serverAddr);

		if fpsendto(socket, pchar('Hi'), 2, 0, @serverAddr, sizeof(serverAddr)) = -1 then SocketError('Send wellcome message to Server');

		if fprecvfrom(socket, @buf, sizeof(buf), 0, @serverAddr, @slen) = -1 then SocketError('Receive wellcome message from Server');

		remoteAddr.sin_addr.s_addr:=buf.host;
		remoteAddr.sin_port:=buf.port;

		logwrite('Establishing Handshake...');

		repeat
			for i:=0 to 10 do begin
				if fpsendto(socket, pchar('Hi'), 2, 0, @remoteAddr, sizeof(remoteAddr)) = -1 then SocketError('Send wellcome message to Client');
			end;

			if fprecvfrom(socket, @hiBuf, sizeof(hiBuf), 0, @remoteAddr, @remoteAddrSLen) = -1 then SocketError('Receive wellcome message from Client');	
		until hiBuf = 'Hi';
*)
end;



procedure CreateServer;
var 
	hiBuf : array [0..2] of char;
	serverAddrTCP, serverAddrUDP : sockaddr_in;
	yes : longint;

begin
		logwrite('Creating Server at ' + serverIP + ':' + numstr(serverPort) + '....');

    fillchar(serverAddrTCP, 0, sizeof(serverAddrTCP));
    serverAddrTCP.sin_family:= AF_INET;
    serverAddrTCP.sin_port:= htons(localServerPORT);

		fillchar(serverAddrUDP, 0, sizeof(serverAddrUDP));
    serverAddrUDP.sin_family:= AF_INET;
    serverAddrUDP.sin_port:= htons(localServerPORT);


    serverAddrUDP.sin_addr.s_addr:= htonl(INADDR_ANY);

    {$IFDEF WINDOWS}
    	serverAddrTCP.sin_addr.s_addr:= inet_addr(PChar(serverIP));
  	{$ELSE}
	  	serverAddrTCP.sin_addr.s_addr:= 0;
	  {$ENDIF}


    if fpbind(socketTCP, @serverAddrTCP, sizeof(serverAddrTCP)) = -1 then begin
    	yes:= 1;
    	if fpsetsockopt(socketTCP, SOL_SOCKET, SO_REUSEADDR, @yes, sizeof(yes)) = -1 then SocketError('bind Sockt TCP');
    end;

    if fpbind(socketUDP, @serverAddrUDP, sizeof(serverAddrUDP)) = -1 then begin
    	yes:= 1;
    	if fpsetsockopt(socketUDP, SOL_SOCKET, SO_REUSEADDR, @yes, sizeof(yes)) = -1 then SocketError('bind Sockt UDP');
    end;


    
  	if fplisten(socketTCP, 5) = -1 then SocketError('listen TCP');

   	remoteAddrSLen:= sizeof(remoteAddrTCP);
   	serverSocketTCP:= socketTCP;
		socketTCP:= fpaccept(socketTCP, @remoteAddrTCP, @remoteAddrSLen);
		if socketTCP < 0 then SocketError('Can not accept TCP');


		repeat
			if fprecvfrom(socketUDP, @hiBuf, 3, 0, @remoteAddrUDP, @remoteAddrSLen) = -1 then SocketError('Receive IP From Client UDP');
		until hiBuf = 'Hi';


    logwrite('Connection established');

end;


procedure CreateClient;
var
		i : longint;

begin
	logwrite('Trying to connect to ' + ServerIP + ':' + numstr(ServerPORT));
	remoteAddrTCP.sin_port:= htons(ServerPORT);
	remoteAddrUDP.sin_port:= htons(ServerPORT);
	{$IFDEF WINDOWS}
    remoteAddrTCP.sin_addr.s_addr:= inet_addr(PChar(ServerIP));
    remoteAddrUDP.sin_addr.s_addr:= inet_addr(PChar(ServerIP));
	{$ELSE}
		remoteAddrTCP.sin_addr:= StrToNetAddr(ServerIP);
		remoteAddrUDP.sin_addr:= StrToNetAddr(ServerIP);
	{$ENDIF}

		if fpconnect(socketTCP, @remoteAddrTCP, sizeof(remoteAddrTCP)) < 0 then SocketError('Connect TCP');
		
		for i:= 0 to 255 do begin
			if fpsendto(socketUDP, pchar('Hi'), 2, 0, @remoteAddrUDP, sizeof(remoteAddrUDP)) = -1 then SocketError('Send IP to Client UDP');
		end;

end;


procedure EstablishConnection(connectionType: TconnectionType);
var
		tv : timeval;
		lin : linger;

begin

	socketTCP:= fpsocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	socketUDP:= fpsocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
  if socketTCP = -1 then SocketError('Init Socket TCP');
  if socketUDP = -1 then SocketError('Init Socket UDP');

  theConnectionType:= connectionType;
	
	fillchar(remoteAddrTCP, 0, sizeof(remoteAddrTCP));
	remoteAddrTCP.sin_family:= AF_INET;

	fillchar(remoteAddrUDP, 0, sizeof(remoteAddrUDP));
	remoteAddrUDP.sin_family:= AF_INET;

  remoteAddrSLen:= sizeof(remoteAddrTCP);

	if connectionType = connectLocal then begin

		logwrite('Connecting Localy....');
		if not isClient then begin
			localServerPORT:= ServerPORT;
			CreateServer;
		end else begin
			CreateClient;
		end;

	end;


	if connectionType = connectHolePunching then begin
		
		logwrite('Connecting through Hole Punching....');
		connectByHolePunching;

	end;


	if connectionType = connectUPnP then begin
		
		logwrite('Connecting through UPnP....');
		if not isClient then begin
			setupUPnP;
			CreateServer;
		end else begin
			CreateClient;
		end;

	end;


	if connectionType = connectPortForwarding then begin
		
		logwrite('Connecting through Port Forwarding....');
		if not isClient then begin
			localServerPORT:=ServerPORT;
			CreateServer;
		end else begin
			CreateClient;
		end;

	end;

	tv.tv_sec:= 2;
  tv.tv_usec:= 0;
  fpsetsockopt(socketTCP, SOL_SOCKET, SO_RCVTIMEO, @tv, sizeof(timeval));
  fpsetsockopt(socketUDP, SOL_SOCKET, SO_RCVTIMEO, @tv, sizeof(timeval));

  lin.l_onoff:= 1;
  lin.l_linger:= 0;
  fpsetsockopt(socketTCP, SOL_SOCKET, SO_LINGER, @lin, sizeof(lin));


	isConnected:= true;

end;


procedure CloseConnection;
begin
	
	fpShutDown(serverSocketTCP, 2);
	closeSocket(serverSocketTCP);
	fpShutDown(socketTCP, 2);
	closeSocket(socketTCP);

	closeSocket(socketUDP);

	if theConnectionType = connectUPnP then FreeUPnP;
end;


begin
end.