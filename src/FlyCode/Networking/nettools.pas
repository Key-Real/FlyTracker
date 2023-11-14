{$MODE OBJFPC} {$H+}
unit nettools;
interface
uses Classes, Process, SysUtils, {$IFDEF UNIX}Unix, {$IFNDEF DARWIN}cnetdb,{$ENDIF} {$IFDEF DARWIN} netdb, {$ENDIF} {$ENDIF} {$IFDEF MSWINDOWS}winsock,{$ENDIF} Sockets, fphttpclient, RegExpr;


function getLocalIP: string;
function getExternalIP : string;


implementation

{$IFDEF MSWINDOWS}
const
	CFormatIPMask = '%d.%d.%d.%d';
{$ENDIF}


function getLocalIP: string;
var
{$IFDEF LINUX}
	szBuffer : array [0..1024] of char;
	host : PHostEnt;
{$ENDIF}
{$IFDEF DARWIN}
	host : THostEntry;
{$ENDIF}
{$IFDEF MSWINDOWS}
	VWSAData: TWSAData;
	VHostEnt: PHostEnt;
	VName: string;
{$ENDIF}

begin

{$IFDEF LINUX}
	szBuffer:=gethostname;
  	host:= gethostbyname(szBuffer);
  	result:= IntToStr(Ord(host^.h_addr_list^[0])) + '.' + IntToStr(Ord(host^.h_addr_list^[1])) + '.' + IntToStr(Ord(host^.h_addr_list^[2])) + '.' + IntToStr(Ord(host^.h_addr_list^[3]));
{$ENDIF}

{$IFDEF DARWIN}
	gethostbyname(gethostname, host);
	result:= HostAddrToStr(host.addr);
{$ENDIF}

{$IFDEF WINDOWS}
   {$HINTS OFF}
		WSAStartup(2, VWSAData);
	{$HINTS ON}
	SetLength(VName, 255);
	GetHostName(PChar(VName), 255);
	SetLength(VName, StrLen(PChar(VName)));
	VHostEnt := GetHostByName(PChar(VName));
	with VHostEnt^ do
	Result := Format(CFormatIPMask, [Byte(h_addr^[0]), Byte(h_addr^[1]), Byte(h_addr^[2]), Byte(h_addr^[3])]);
	WSACleanup;
 {$ENDIF}
 
end;


function getExternalIP : string;
begin

	try
		with TRegExpr.Create('[0-9.]+') do
			if Exec(TFPHTTPClient.SimpleGet('http://checkip.dyndns.org')) then
				result:=Match[0];
	except
		result:= 'ERROR';
	end;

end;


begin
end. 
