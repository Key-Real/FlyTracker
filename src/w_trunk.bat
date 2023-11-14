@Echo off
del FlyTracker.exe
rem c:/FPC/3.3.1/bin/i386-win32/ppcrossx64
c:/FPC/3.3.1/bin/x86_64-win64/fpc FlyTracker.pas -glps -Ciro -Fu./FlyCode/ -Fu./FlyCode/InstrumentEditor -Fu./FlyCode/Menu -Fu./FlyCode/Shared -Fu./FlyCode/Tracker -Fu./FlyCode/PianoRoll -Fu./FlyCode/Networking -Fu../../vipgfx-code/src -Fu../../vipgfx-code/TTF/myFT1 -Fu../../tycoonuserinterface-code/src/tuicode -Fu../../tralala-code/src -Fu../../tralala-code/src/bindings/dsound
del *.o
del *.ppu
del FlyCode\*.o
del FlyCode\*.ppu
del FlyCode\Menu\*.o
del FlyCode\Menu\*.ppu
del FlyCode\Tracker\*.o
del FlyCode\Tracker\*.ppu
del FlyCode\InstrumentEditor\*.o
del FlyCode\InstrumentEditor\*.ppu
del FlyCode\Shared\*.o
del FlyCode\Shared\*.ppu
del FlyCode\PianoRoll\*.o
del FlyCode\PianoRoll\*.ppu
del FlyCode\Networking\*.ppu
del FlyCode\Networking\*.o
del ..\..\vipgfx-code\src\*.o
del ..\..\vipgfx-code\src\*.ppu
del ..\..\vipgfx-code\TTF\myFT1\*.o
del ..\..\vipgfx-code\TTF\myFT1\*.ppu
rem del ..\..\tralala-code\src\*.o
rem del ..\..\tralala-code\src\*.ppu
del ..\..\tycoonuserinterface-code\src\tuicode\*.o
del ..\..\tycoonuserinterface-code\src\tuicode\*.ppu
del link.res
FlyTracker.exe dubbish.xm -1 -ESC -w
pause