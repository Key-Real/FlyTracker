@echo off
del test.exe
ppcrossx64 test.pas
del *.o
del *.ppu
test.exe
pause