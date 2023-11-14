@Echo off
del FlyTracker.exe
fpc FlyTracker.pas -gl -Cio -Fu./FlyCode -Fu./FlyCode/Shared -Fu./FlyCode/Menu -Fu./FlyCode/Tracker -Fu./FlyCode/InstrumentEditor -Fu./FlyCode/PianoRoll -Fu./FlyCode/Networking -Fu../../vipgfx-code/src -Fu../../vipgfx-code/TTF/myFT1 -Fu../../tycoonuserinterface-code/src/tuicode -Fu../../tralala-code/src -Fu../../tralala-code/src/bindings/dsound
del *.o
del *.ppu
del FlyCode\*.o
del FlyCode\*.ppu
del FlyCode\InstrumentEditor\*.o
del FlyCode\InstrumentEditor\*.ppu
del FlyCode\Menu\*.o
del FlyCode\Menu\*.ppu
del FlyCode\Networking\*.o
del FlyCode\Networking\*.ppu
del FlyCode\PianoRoll\*.o
del FlyCode\PianoRoll\*.ppu
del FlyCode\Shared\*.o
del FlyCode\Shared\*.ppu
del FlyCode\Tracker\*.o
del FlyCode\Tracker\*.ppu

del ..\..\vipgfx-code\src\*.o
del ..\..\vipgfx-code\src\*.ppu
rem del ..\..\vipgfx-code\TTF\myFT1\*.o
rem del ..\..\vipgfx-code\TTF\myFT1\*.ppu

rem del ..\..\tralala-code\src\*.o
rem del ..\..\tralala-code\src\*.ppu

del ..\..\tycoonuserinterface-code\src\tuicode\*.o
del ..\..\tycoonuserinterface-code\src\tuicode\*.ppu

del link.res
FlyTracker.exe MechanismEight.s3m -1 -ESC -w -fps
pause