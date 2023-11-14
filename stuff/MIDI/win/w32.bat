@echo off
del test.exe
fpc test.pas
del *.o
del *.ppu
test.exe
pause