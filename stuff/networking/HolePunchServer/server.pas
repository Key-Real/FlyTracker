{$MODE OBJFPC}{$H+}
uses
    sockets, SysUtils, crt;


procedure SocketError(s:string);
begin
    writeln(s);
    halt(1);
end;

type 
     Tclient = record
                host : dword;
                port : word;
                num : word;
               end;

var
    si_me, si_other : sockaddr_in;
    socket : longint;
    i, j, slen : dword;
    buf : array [0..8] of char;
    clients : array [0..2] of Tclient;
    n : longint;
   
begin
    slen:= sizeof(si_other);

    socket:= fpsocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if socket = -1 then SocketError('Init Socket');

    fillchar(si_me, 0, sizeof(si_me));
    si_me.sin_family:= AF_INET;
    si_me.sin_port:= htons(3333);
    si_me.sin_addr.s_addr:= htonl(INADDR_ANY);
    if fpbind(socket, @si_me, sizeof(si_me)) = -1 then SocketError('Bind Socket');
    
    writeln('Started, waiting for 2 Clients...');

    n:= 0;
    while n < 2 do begin        
        if fprecvfrom(socket, @buf, sizeof(buf), 0, @si_other, @slen) = -1 then SocketError('Receive from Client 1');
        writeln('Received packet from ', NetAddrToStr(si_other.sin_addr), ':', ntohs(si_other.sin_port));
        
        clients[n].host:= si_other.sin_addr.s_addr;
        clients[n].port:= si_other.sin_port;
        inc(n);
    end;
    


    i:=0;
        si_other.sin_addr.s_addr:= clients[i].host;
        si_other.sin_port:= clients[i].port;
    j:=1;       
        writeln('Sending to ', NetAddrToStr(si_other.sin_addr), ':', ntohs(si_other.sin_port));
        if fpsendto(socket, @clients[j], sizeof(clients[j]), 0, @si_other, slen) = -1 then SocketError('Send to Client 1');


    i:=1;
        si_other.sin_addr.s_addr:= clients[i].host;
        si_other.sin_port:= clients[i].port;
    j:=0;        
        writeln('Sending to ', NetAddrToStr(si_other.sin_addr), ':', ntohs(si_other.sin_port));
        if fpsendto(socket, @clients[j], sizeof(clients[j]), 0, @si_other, slen) = -1 then SocketError('Send to Client 2');



    writeln('Now we have ', n, ' clients');
        
    closeSocket(socket);
end.