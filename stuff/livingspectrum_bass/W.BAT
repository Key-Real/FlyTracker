@echo off
del ls.exe
c:/FPC/3.3.1/bin/i386-win32/ppcrossx64 -B -Fu..\..\..\vipgfx-code\src ls.pas
rem -Xs -Os
rem -O3 -Si -O3 -Or -Ci- -Co- -CO- -Cr-
rem -vv
rem -gchl
del *.a
del *.o
del *.ppu
ls.exe
pause