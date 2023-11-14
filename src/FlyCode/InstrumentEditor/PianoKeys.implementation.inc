procedure TInstrumentEditor.BuildPianoKeys;
begin

	pianoKeysBox:= TtuiBox.create(InstrumentEditorTUI, 0, 720 - 86, 1280, 86, 'InstrumentEditorPianoKeysBox', tuiBoxStatic);
    pianoKeysBox.ThemeBox:= LoadThemeBox;
    pianoKeysBox.ThemeBox.BackgroundColor:= $ff000000;
    InstrumentEditorTUI.addBox(pianoKeysBox);

    allocImage(PianoImage, 1280, 86);
    fastfill(PianoImage.data, PianoImage.width * PianoImage.height, $ff000000);
    pianoSelectableImage:= TtuiSelectableImage.create(pianoKeysBox, 'pianoSelectableImage', 0, 0, PianoImage, nil);
    pianoSelectableImage.theme:= LoadThemeSelectableImage;
    pianoSelectableImage.drawBorder:= false;
    pianoKeysBox.addItem(pianoSelectableImage);

    drawPianoWhiteKeys;
    drawPianoBlackKeys;
end;


procedure TInstrumentEditor.DrawPianoWhiteKey(x: longint);
begin
	drawBar(PianoImage, x, 0,x + pianokeywhitewidth, PianoImage.height - 1, $ffaaaaaa);
	drawhline(PianoImage, x, x + 3,PianoImage.height - 1, $ff666666);
	drawhline(PianoImage, x, x + 3,PianoImage.height - 2, $ff666666);
	drawhline(PianoImage, x, x + 3,PianoImage.height - 3, $ff666666);

	drawhline(PianoImage, x + pianokeyWhiteWidth - 3, x + pianokeyWhiteWidth, PianoImage.height - 1, $ff666666);
	drawhline(PianoImage, x + pianokeyWhiteWidth - 3, x + pianokeyWhiteWidth, PianoImage.height - 2, $ff666666);
	drawhline(PianoImage, x + pianokeyWhiteWidth - 3, x + pianokeyWhiteWidth, PianoImage.height - 3, $ff666666);
end;


procedure TInstrumentEditor.DrawPianoPressedWhiteKey(x: longint);
var 
	height : longint;
begin
	height:= 24;


	drawHline(PianoImage, x, x + pianokeyWhiteWidth, PianoImage.height - 1, $ff000000);
	drawHline(PianoImage, x, x + pianokeyWhiteWidth, PianoImage.height - 2, $ff000000);

	drawVline(PianoImage, PianoImage.height - height, PianoImage.height - 1, x, $ff000000);
	drawVline(PianoImage, PianoImage.height - height, PianoImage.height - 1, x + 1, $ff000000);	
	
	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight, PianoImage.height - 1 - height, x, $ff666666);
	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight, PianoImage.height - 1 - height, x + 1, $ff666666);

	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight - pianokeyWhiteLineHeight, PianoImage.height - 1 - height-pianokeyWhiteLineHeight, x, $ff888888);
	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight - pianokeyWhiteLineHeight, PianoImage.height - 1 - height-pianokeyWhiteLineHeight, x + 1, $ff888888);


	drawVline(PianoImage, PianoImage.height - height, PianoImage.height - 1, x + pianokeyWhiteWidth - 0, $ff000000);
	drawVline(PianoImage, PianoImage.height - height, PianoImage.height - 1, x + pianokeyWhiteWidth - 1, $ff000000);

	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight, PianoImage.height - 1 - height, x + pianokeyWhiteWidth - 0, $ff666666);
	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight, PianoImage.height - 1 - height, x + pianokeyWhiteWidth - 1, $ff666666);

	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight - pianokeyWhiteLineHeight, PianoImage.height - 1 - height - pianokeyWhiteLineHeight, x + pianokeyWhiteWidth - 0, $ff888888);
	drawVline(PianoImage, PianoImage.height - height - pianokeyWhiteLineHeight - pianokeyWhiteLineHeight, PianoImage.height - 1 - height - pianokeyWhiteLineHeight, x + pianokeyWhiteWidth - 1, $ff888888);
	
	
	drawhline(PianoImage, x + 2, x + 5, PianoImage.height - 2 - 1, $ff666666);
	drawhline(PianoImage, x + 2, x + 5, PianoImage.height - 3 - 1, $ff666666);

	drawhline(PianoImage, x + pianokeywhitewidth - 5, x + pianokeywhitewidth - 2, PianoImage.height - 2 - 1, $ff666666);
	drawhline(PianoImage, x + pianokeywhitewidth - 5, x + pianokeywhitewidth - 2, PianoImage.height - 3 - 1, $ff666666);

end;

procedure TInstrumentEditor.DrawPianoBlackKey(x: longint);
begin
	drawBar(PianoImage, x, 0, x + pianokeyblackwidth, 0 + (PianoImage.height - 1) - 33, $ff000000);
	
	drawhline(PianoImage, x, x + 3, (PianoImage.height - 1) - 33, $ff666666);
	drawhline(PianoImage, x, x + 3, (PianoImage.height - 1) - 33 - 1, $ff666666);

	drawhline(PianoImage, x + pianokeyblackwidth - 3, x + pianokeyblackWidth, (PianoImage.height - 1) - 33, $ff666666);
	drawhline(PianoImage, x + pianokeyblackwidth - 3, x + pianokeyblackWidth, (PianoImage.height - 1) - 33 - 1, $ff666666);
end;

procedure TInstrumentEditor.DrawPianoPressedBlackKey(x: longint);
begin
	drawBar(PianoImage, x + 1, 0, x + pianokeyblackwidth - 1, (PianoImage.height - 1) - 33 - 1, $ff444444);
	
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 3, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 4, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 5, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 6, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 7, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 8, $ff888888);
	putpixel(PianoImage, x + 1, 0 + PianoImage.height - 0 - 1 - 33 - 9, $ff888888);
 	
	putpixel(PianoImage, x + 2, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 2, 0 + PianoImage.height - 0 - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + 2, 0 + PianoImage.height - 0 - 1 - 33 - 3, $ff888888);

	putpixel(PianoImage, x + 3, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 4, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 5, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 6, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + 7, 0 + PianoImage.height - 0 - 1 - 33 - 1, $ff888888);
	
	putpixel(PianoImage, x + 3, 0 + PianoImage.height - 0 - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + 4, 0 + PianoImage.height - 0 - 1 - 33 - 2, $ff888888);
	

	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 3, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 4, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 5, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 6, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 7, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 8, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 1, PianoImage.height - 1 - 33 - 9, $ff888888);
	
	putpixel(PianoImage, x + pianokeyblackwidth - 2, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 2, PianoImage.height - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 2, PianoImage.height - 1 - 33 - 3, $ff888888);

	putpixel(PianoImage, x + pianokeyblackwidth - 3, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 4, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 5, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 6, PianoImage.height - 1 - 33 - 1, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 7, PianoImage.height - 1 - 33 - 1, $ff888888);
	
	putpixel(PianoImage, x + pianokeyblackwidth - 3, PianoImage.height - 1 - 33 - 2, $ff888888);
	putpixel(PianoImage, x + pianokeyblackwidth - 4, PianoImage.height - 1 - 33 - 2, $ff888888);

end;


procedure TInstrumentEditor.DrawPianoWhiteKeys;
var i:longint;	
begin
	for i:= 0 to 51 do begin
		DrawPianoWhiteKey(17 + i * (pianokeyWhiteWidth + 4));
	end;
end;


procedure TInstrumentEditor.DrawPianoBlackKeys;
begin
	DrawPianoBlackKey(32);
	DrawPianoBlackKey(56);

	DrawPianoBlackKey(104);
	DrawPianoBlackKey(128);
	DrawPianoBlackKey(152);

	DrawPianoBlackKey(200);
	DrawPianoBlackKey(224);

	DrawPianoBlackKey(272);
	DrawPianoBlackKey(296);
	DrawPianoBlackKey(320);

	DrawPianoBlackKey(368);
	DrawPianoBlackKey(392);

	DrawPianoBlackKey(440);
	DrawPianoBlackKey(464);
	DrawPianoBlackKey(489);

	DrawPianoBlackKey(536);
	DrawPianoBlackKey(560);
	
	DrawPianoBlackKey(607);
	DrawPianoBlackKey(631);
	DrawPianoBlackKey(656);

	DrawPianoBlackKey(704);
	DrawPianoBlackKey(728);
	
	DrawPianoBlackKey(776);
	DrawPianoBlackKey(799);
	DrawPianoBlackKey(824);

	DrawPianoBlackKey(872);
	DrawPianoBlackKey(896);

	DrawPianoBlackKey(944);
	DrawPianoBlackKey(968);
	DrawPianoBlackKey(992);

	DrawPianoBlackKey(1040);
	DrawPianoBlackKey(1064);

	DrawPianoBlackKey(1112);
	DrawPianoBlackKey(1136);
	DrawPianoBlackKey(1160);

	DrawPianoBlackKey(1208);
	DrawPianoBlackKey(1232);

end;


function TInstrumentEditor.isPianoBlackKeyMouseOver: longint;
begin

	result:= -1;	
	if (mouseX >= 32) and (mouseX <= (32 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 0; exit; end;
	if (mouseX >= 56) and (mouseX <= (56 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 1; exit; end;
	if (mouseX >= 104) and (mouseX <= (104 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 2; exit; end;
	if (mouseX >= 128) and (mouseX <= (128 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 3; exit; end;
	if (mouseX >= 152) and (mouseX <= (152 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 4; exit; end;
	if (mouseX >= 200) and (mouseX <= (200 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 5; exit; end;
	if (mouseX >= 224) and (mouseX <= (224 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 6; exit; end;
	if (mouseX >= 272) and (mouseX <= (272 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 7; exit; end;
	if (mouseX >= 296) and (mouseX <= (296 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 8; exit; end;
	if (mouseX >= 320) and (mouseX <= (320 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 9; exit; end;
	if (mouseX >= 368) and (mouseX <= (368 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 10; exit; end;
	if (mouseX >= 392) and (mouseX <= (392 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 11; exit; end;
	if (mouseX >= 440) and (mouseX <= (440 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 12; exit; end;
	if (mouseX >= 464) and (mouseX <= (464 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 13; exit; end;
	if (mouseX >= 489) and (mouseX <= (489 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 14; exit; end;
	if (mouseX >= 536) and (mouseX <= (536 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 15; exit; end;
	if (mouseX >= 560) and (mouseX <= (560 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 16; exit; end;
	if (mouseX >= 607) and (mouseX <= (607 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 17; exit; end;
	if (mouseX >= 631) and (mouseX <= (631 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 18; exit; end;
	if (mouseX >= 656) and (mouseX <= (656 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 19; exit; end;
	if (mouseX >= 704) and (mouseX <= (704 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 20; exit; end;
	if (mouseX >= 728) and (mouseX <= (728 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 21; exit; end;
	if (mouseX >= 776) and (mouseX <= (776 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 22; exit; end;
	if (mouseX >= 799) and (mouseX <= (799 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 23; exit; end;
	if (mouseX >= 824) and (mouseX <= (824 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 24; exit; end;
	if (mouseX >= 872) and (mouseX <= (872 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 25; exit; end;
	if (mouseX >= 896) and (mouseX <= (896 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 26; exit; end;
	if (mouseX >= 944) and (mouseX <= (944 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 27; exit; end;
	if (mouseX >= 968) and (mouseX <= (968 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 28; exit; end;
	if (mouseX >= 992) and (mouseX <= (992 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 29; exit; end;
	if (mouseX >= 1040) and (mouseX <= (1040 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 30; exit; end;
	if (mouseX >= 1064) and (mouseX <= (1064 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 31; exit; end;
	if (mouseX >= 1112) and (mouseX <= (1112 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 32; exit; end;
	if (mouseX >= 1136) and (mouseX <= (1136 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 33; exit; end;
	if (mouseX >= 1160) and (mouseX <= (1160 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 34; exit; end;
	if (mouseX >= 1208) and (mouseX <= (1208 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 35; exit; end;
	if (mouseX >= 1232) and (mouseX <= (1232 + pianokeyBlackWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY+vscreen.height-pianokeysY-1-33)) then begin result:= 36; exit; end;

end;


procedure TInstrumentEditor.updatePianoPressedBlackKeys(key: longint);
begin

	if key = -1 then exit;
	if key = 0 then begin DrawPianoPressedBlackKey(32); exit; end;
	if key = 1 then begin DrawPianoPressedBlackKey(56); exit; end;
	if key = 2 then begin DrawPianoPressedBlackKey(104); exit; end;
	if key = 3 then begin DrawPianoPressedBlackKey(128); exit; end;
	if key = 4 then begin DrawPianoPressedBlackKey(152); exit; end;
	if key = 5 then begin DrawPianoPressedBlackKey(200); exit; end;
	if key = 6 then begin DrawPianoPressedBlackKey(224); exit; end;
	if key = 7 then begin DrawPianoPressedBlackKey(272); exit; end;
	if key = 8 then begin DrawPianoPressedBlackKey(296); exit; end;
	if key = 9 then begin DrawPianoPressedBlackKey(320); exit; end;
	if key = 10 then begin DrawPianoPressedBlackKey(368); exit; end;
	if key = 11 then begin DrawPianoPressedBlackKey(392); exit; end;
	if key = 12 then begin DrawPianoPressedBlackKey(440); exit; end;
	if key = 13 then begin DrawPianoPressedBlackKey(464); exit; end;
	if key = 14 then begin DrawPianoPressedBlackKey(489); exit; end;
	if key = 15 then begin DrawPianoPressedBlackKey(536); exit; end;
	if key = 16 then begin DrawPianoPressedBlackKey(560); exit; end;
	if key = 17 then begin DrawPianoPressedBlackKey(607); exit; end;
	if key = 18 then begin DrawPianoPressedBlackKey(631); exit; end;
	if key = 19 then begin DrawPianoPressedBlackKey(656); exit; end;
	if key = 20 then begin DrawPianoPressedBlackKey(704); exit; end;
	if key = 21 then begin DrawPianoPressedBlackKey(728); exit; end;
	if key = 22 then begin DrawPianoPressedBlackKey(776); exit; end;
	if key = 23 then begin DrawPianoPressedBlackKey(799); exit; end;
	if key = 24 then begin DrawPianoPressedBlackKey(824); exit; end;
	if key = 25 then begin DrawPianoPressedBlackKey(872); exit; end;
	if key = 26 then begin DrawPianoPressedBlackKey(896); exit; end;
	if key = 27 then begin DrawPianoPressedBlackKey(944); exit; end;
	if key = 28 then begin DrawPianoPressedBlackKey(968); exit; end;
	if key = 29 then begin DrawPianoPressedBlackKey(992); exit; end;
	if key = 30 then begin DrawPianoPressedBlackKey(1040); exit; end;
	if key = 31 then begin DrawPianoPressedBlackKey(1064); exit; end;
	if key = 32 then begin DrawPianoPressedBlackKey(1112); exit; end;
	if key = 33 then begin DrawPianoPressedBlackKey(1136); exit; end;
	if key = 34 then begin DrawPianoPressedBlackKey(1160); exit; end;
	if key = 35 then begin DrawPianoPressedBlackKey(1208); exit; end;
	if key = 36 then begin DrawPianoPressedBlackKey(1232); exit; end;

end;




function TInstrumentEditor.isPianoWhiteKeyMouseOver: longint;
var 
	i : longint;
begin

	result:= -1;
	for i:=0 to 51 do begin
		if (mouseX >= (17 + i * (pianokeyWhiteWidth + 4))) and (mouseX <= (17 + i * (pianokeyWhiteWidth + 4) + pianokeyWhiteWidth)) and (mouseY >= pianokeysY) and (mouseY <= (pianokeysY + vscreen.height - pianokeysY - 1)) then begin result:= i; exit; end;
	end;


end;



function TInstrumentEditor.VirtualPianoGetNoteFromKeyboard: longint;
begin

    result:= -1;
    if keyboard[KEY_Z] then result:= CurrentOctave * 12 + 0;  // C4
    if keyboard[KEY_S] then result:= CurrentOctave * 12 + 1;  // C#4
    if keyboard[KEY_X] then result:= CurrentOctave * 12 + 2;  // D4
    if keyboard[KEY_D] then result:= CurrentOctave * 12 + 3;  // D#4
    if keyboard[KEY_C] then result:= CurrentOctave * 12 + 4;  // E4
    if keyboard[KEY_V] then result:= CurrentOctave * 12 + 5;  // F4
    if keyboard[KEY_G] then result:= CurrentOctave * 12 + 6;  // F#4
    if keyboard[KEY_B] then result:= CurrentOctave * 12 + 7;  // G4
    if keyboard[KEY_H] then result:= CurrentOctave * 12 + 8;  // G#4
    if keyboard[KEY_N] then result:= CurrentOctave * 12 + 9;  // A4
    if keyboard[KEY_J] then result:= CurrentOctave * 12 + 10;  // A#4
    if keyboard[KEY_M] then result:= CurrentOctave * 12 + 11;  // B4

    if keyboard[KEY_Q] then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if keyboard[KEY_OEM_COMMA] then result:= (CurrentOctave + 1) * 12 + 0;  // C5
    if keyboard[KEY_2] then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if keyboard[KEY_L] then result:= (CurrentOctave + 1) * 12 + 1;  // C#5
    if keyboard[KEY_W] then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if keyboard[KEY_OEM_PERIOD] then result:= (CurrentOctave + 1) * 12 + 2;  // D5
    if keyboard[KEY_3] then result:= (CurrentOctave + 1) * 12 + 3;  // D#5
    if keyboard[KEY_OEM_3] then result:= (CurrentOctave + 1) * 12 + 3;  // D#5   key = ö
    if keyboard[KEY_E] then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if keyboard[KEY_OEM_MINUS] then result:= (CurrentOctave + 1) * 12 + 4;  // E5
    if keyboard[KEY_R] then result:= (CurrentOctave + 1) * 12 + 5;  // F5
    if keyboard[KEY_5] then result:= (CurrentOctave + 1) * 12 + 6;  // F#5
    if keyboard[KEY_OEM_2] then result:= (CurrentOctave + 1) * 12 + 6;  // F#5   key = #
    if keyboard[KEY_T] then result:= (CurrentOctave + 1) * 12 + 7;  // G5
    if keyboard[KEY_6] then result:= (CurrentOctave + 1) * 12 + 8;  // G#5
    if keyboard[KEY_Y] then result:= (CurrentOctave + 1) * 12 + 9;  // A5
    if keyboard[KEY_7] then result:= (CurrentOctave + 1) * 12 + 10;  // A#5
    if keyboard[KEY_U] then result:= (CurrentOctave + 1) * 12 + 11;  // B5

    if keyboard[KEY_I] then result:= (CurrentOctave + 2) * 12 + 0;  // C6
    if keyboard[KEY_9] then result:= (CurrentOctave + 2) * 12 + 1;  // C#6
    if keyboard[KEY_o] then result:= (CurrentOctave + 2) * 12 + 2;  // D6
    if keyboard[KEY_0] then result:= (CurrentOctave + 2) * 12 + 3;  // D#6
    if keyboard[KEY_P] then result:= (CurrentOctave + 2) * 12 + 4;  // E6
    if keyboard[KEY_OEM_1] then result:= (CurrentOctave + 2) * 12 + 5;  // F6   key = ü
    if keyboard[KEY_OEM_6] then result:= (CurrentOctave + 2) * 12 + 6;  // F#6   key = ´
    if keyboard[KEY_OEM_PLUS] then result:= (CurrentOctave + 2) * 12 + 7;  // G6   key = +
    if keyboard[KEY_RETURN] then result:= (CurrentOctave + 2) * 12 + 9;  // A6

    if keyboard[KEY_CAPSLOCK] then result:= 125;  // NoteOff
    if keyboard[KEY_OEM_102] then result:= 126;  // NoteCut   key = <

end;


function TInstrumentEditor.GetPianoKeyFromKeyboard: longint;
begin
	result:= -1;
    if keyboard[KEY_Z] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 0); end; // C4
    if keyboard[KEY_S] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 1); end;  // C#4
    if keyboard[KEY_X] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 2); end;  // D4
    if keyboard[KEY_D] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 3); end;  // D#4
    if keyboard[KEY_C] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 4); end;  // E4
    if keyboard[KEY_V] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 5); end;  // F4
    if keyboard[KEY_G] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 6); end;  // F#4
    if keyboard[KEY_B] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 7); end;  // G4
    if keyboard[KEY_H] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 8); end;  // G#4
    if keyboard[KEY_N] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 9); end;  // A4
    if keyboard[KEY_J] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 10); end; // A#4
    if keyboard[KEY_M] then begin result:= ConvertNote2PianoKeyboard(CurrentOctave * 12 + 11); end;  // B4

    if keyboard[KEY_Q] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 0); end;  // C5
    if keyboard[KEY_OEM_COMMA] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 0); end;  // C5
    if keyboard[KEY_2] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 1); end;  // C#5
    if keyboard[KEY_L] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 1); end;  // C#5
    if keyboard[KEY_W] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 2); end;  // D5
    if keyboard[KEY_OEM_PERIOD] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 2); end;  // D5
    if keyboard[KEY_3] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 3); end;  // D#5
    if keyboard[KEY_OEM_3] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 3); end;  // D#5   key = ö
    if keyboard[KEY_E] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 4); end;  // E5
    if keyboard[KEY_OEM_MINUS] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 4); end;  // E5
    if keyboard[KEY_R] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 5); end;  // F5
    if keyboard[KEY_5] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 6); end;  // F#5
    if keyboard[KEY_OEM_2] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 6); end;  // F#5   key = #
    if keyboard[KEY_T] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 7); end;  // G5
    if keyboard[KEY_6] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 8); end; // G#5
    if keyboard[KEY_Y] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 9); end;  // A5
    if keyboard[KEY_7] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 10); end;  // A#5
    if keyboard[KEY_U] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 1) * 12 + 11); end;  // B5

    if keyboard[KEY_I] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 0); end;  // C6
    if keyboard[KEY_9] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 1); end;  // C#6
    if keyboard[KEY_o] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 2); end;  // D6
    if keyboard[KEY_0] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 3); end;  // D#6
    if keyboard[KEY_P] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 4); end;  // E6
    if keyboard[KEY_OEM_1] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 5); end;  // F6   key = ü
    if keyboard[KEY_OEM_6] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 6); end;  // F#6   key = ´
    if keyboard[KEY_OEM_PLUS] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 7); end;  // G6   key = +
    if keyboard[KEY_RETURN] then begin result:= ConvertNote2PianoKeyboard((CurrentOctave + 2) * 12 + 9); end; // A6

end;

function TInstrumentEditor.ConvertNote2PianoKeyboard(note: longint): longint;
begin

	result:= -1;
	if ConvertNote2WhitePianoKeyboard(note) <> -1 then begin result:= ConvertNote2WhitePianoKeyboard(note); exit; end;
	if ConvertNote2BlackPianoKeyboard(note) <> -1 then begin result:= ConvertNote2BlackPianoKeyboard(note); exit; end;

end;

function TInstrumentEditor.ConvertNote2WhitePianoKeyboard(note: longint): longint;
begin
	result:= -1;
	if note = 12 then result:= 0; // C1
	if note = 14 then result:= 1; // D1
	if note = 16 then result:= 2; // E1
	if note = 17 then result:= 3; // F1
	if note = 19 then result:= 4; // G1
	if note = 21 then result:= 5; // A1
	if note = 23 then result:= 6; // B1

	if note = 24 then result:= 7; // C2
	if note = 26 then result:= 8; // D2
	if note = 28 then result:= 9; // E2
	if note = 29 then result:= 10; // F2
	if note = 31 then result:= 11; // G2
	if note = 33 then result:= 12; // A2
	if note = 35 then result:= 13; // B2

	if note = 36 then result:= 14; // C3
	if note = 38 then result:= 15; // D3
	if note = 40 then result:= 16; // E3
	if note = 41 then result:= 17; // F3
	if note = 43 then result:= 18; // G3
	if note = 45 then result:= 19; // A3
	if note = 47 then result:= 20; // B3

	if note = 48 then result:= 21; // C4
	if note = 50 then result:= 22; // D4
	if note = 52 then result:= 23; // E4
	if note = 53 then result:= 24; // F4
	if note = 55 then result:= 25; // G4
	if note = 57 then result:= 26; // A4
	if note = 59 then result:= 27; // B4

	if note = 60 then result:= 28; // C5
	if note = 62 then result:= 29; // D5
	if note = 64 then result:= 30; // E5
	if note = 65 then result:= 31; // F5
	if note = 67 then result:= 32; // G5
	if note = 69 then result:= 33; // A5
	if note = 71 then result:= 34; // B5

	if note = 72 then result:= 35; // C6
	if note = 74 then result:= 36; // D6
	if note = 76 then result:= 37; // E6
	if note = 77 then result:= 38; // F6
	if note = 79 then result:= 39; // G6
	if note = 81 then result:= 40; // A6
	if note = 83 then result:= 41; // B6

	if note = 84 then result:= 42; // C7
	if note = 86 then result:= 43; // D7
	if note = 88 then result:= 44; // E7
	if note = 89 then result:= 45; // F7
	if note = 91 then result:= 46; // G7
	if note = 93 then result:= 47; // A7
	if note = 95 then result:= 48; // B7

	if note = 96 then result:= 49; // C8
	if note = 98 then result:= 50; // D8
	if note = 100 then result:= 51; // E8
	if note = 101 then result:= 52; // F8
	if note = 103 then result:= 53; // G8
	if note = 105 then result:= 54; // A8
	if note = 107 then result:= 55; // B8

	if note = 108 then result:= 56; // C9
	if note = 110 then result:= 57; // D9
	if note = 112 then result:= 58; // E9
	if note = 113 then result:= 59; // F9
	if note = 115 then result:= 60; // G9
	if note = 117 then result:= 61; // A9
	if note = 119 then result:= 62; // B9

end;


function TInstrumentEditor.ConvertNote2BlackPianoKeyboard(note: longint): longint;
begin

	result:= -1;

	if note = 13 then result:= 0; // C#1
	if note = 15 then result:= 1; // D#1
	if note = 18 then result:= 2; // F#1
	if note = 20 then result:= 3; // G#1
	if note = 22 then result:= 4; // A#1
	if note = 25 then result:= 5; // C#2
	if note = 27 then result:= 6; // D#2
	if note = 30 then result:= 7; // F#2
	if note = 32 then result:= 8; // G#2
	if note = 34 then result:= 9; // A#2
	if note = 37 then result:= 10; // C#3
	if note = 39 then result:= 11; // D#3
	if note = 42 then result:= 12; // F#3
	if note = 44 then result:= 13; // G#3
	if note = 46 then result:= 14; // A#3
	if note = 49 then result:= 15; // C#4
	if note = 51 then result:= 16; // D#4
	if note = 54 then result:= 17; // F#4
	if note = 56 then result:= 18; // G#4
	if note = 58 then result:= 19; // A#4
	if note = 61 then result:= 20; // C#5
	if note = 63 then result:= 21; // D#5
	if note = 66 then result:= 22; // F#5
	if note = 68 then result:= 23; // G#5
	if note = 70 then result:= 24; // A#5
	if note = 73 then result:= 25; // C#6
	if note = 75 then result:= 26; // D#6
	if note = 78 then result:= 27; // F#6
	if note = 80 then result:= 28; // G#6
	if note = 82 then result:= 29; // A#6
	if note = 85 then result:= 30; // C#7
	if note = 87 then result:= 31; // D#7
	if note = 90 then result:= 32; // F#7
	if note = 92 then result:= 33; // G#7
	if note = 94 then result:= 34; // A#7
	if note = 97 then result:= 35; // C#8
	if note = 99 then result:= 36; // D#8
	if note = 102 then result:= 37; // F#8
	if note = 104 then result:= 38; // G#8
	if note = 106 then result:= 39; // A#8
	if note = 109 then result:= 40; // C#9
	if note = 111 then result:= 41; // D#9
	if note = 114 then result:= 42; // F#9
	if note = 116 then result:= 43; // G#9
	if note = 118 then result:= 44; // A#9

end;


function TInstrumentEditor.convertWhiteKey2noteNumber(key: longint): longint;
var 
	note : longint;
begin

	result:= -1;
	note:= -1;

	case key of
		0 : note:= 12; //  = C1
		1 : note:= 14; //  = D1
		2 : note:= 16; //  = E1
		3 : note:= 17; //  = F1
		4 : note:= 19; //  = G1
		5 : note:= 21; //  = A1
		6 : note:= 23; //  = B1
		7 : note:= 24; //  = C2
		8 : note:= 26; //  = D2  
		9 : note:= 28; //  = E2
		10: note:= 29; //  = F2
		11: note:= 31; //  = G2
		12: note:= 33; //  = A2
		13: note:= 35; //  = B2
		14: note:= 36; //  = C3
		15: note:= 38; //  = D3
		16: note:= 40; //  = E3
		17: note:= 41; //  = F3
		18: note:= 43; //  = G3
		19: note:= 45; //  = A3
		20: note:= 47; //  = B3
		21: note:= 48; //  = C4
		22: note:= 50; //  = D4
		23: note:= 52; //  = E4
		24: note:= 53; //  = F4
		25: note:= 55; //  = G4
		26: note:= 57; //  = A4
		27: note:= 59; //  = B4
		28: note:= 60; //  = C5
		29: note:= 62; //  = D5
		30: note:= 64; //  = E5
		31: note:= 65; //  = F5
		32: note:= 67; //  = G5
		33: note:= 69; //  = A5
		34: note:= 71; //  = B5
		35: note:= 72; //  = C6
		36: note:= 74; //  = D6
		37: note:= 76; //  = E6
		38: note:= 77; //  = F6
		39: note:= 79; //  = G6
		40: note:= 81; //  = A6
		41: note:= 83; //  = B6
		42: note:= 84; //  = C7
		43: note:= 86; //  = D7
		44: note:= 88; //  = E7
		45: note:= 89; //  = F7
		46: note:= 91; //  = G7
		47: note:= 93; //  = A7
		48: note:= 95; //  = B7
		49: note:= 96; //  = C8
		50: note:= 98; //  = D8
		51: note:= 100; // = E8
	end;
	
	result:= note;

end;


function TInstrumentEditor.convertBlackKey2noteNumber(key: longint): longint;
var 
	note : longint;

begin

	result:= -1;
	note:= 0;

	case key of
		0 : note:= 13; // = C#1
		1 : note:= 15; // = D#1
		2 : note:= 18; // = F#1
		3 : note:= 20; // = G#1
		4 : note:= 22; // = A#1
		5 : note:= 25; // = C#2
		6 : note:= 27; // = D#2
		7 : note:= 30; // = F#2
		8 : note:= 32; // = G#2
		9 : note:= 34; // = A#2
		10: note:= 37; // = C#3
		11: note:= 39; // = D#3
		12: note:= 42; // = F#3
		13: note:= 44; // = G#3
		14: note:= 46; // = A#3
		15: note:= 49; // = C#4
		16: note:= 51; // = D#4
		17: note:= 54; // = F#4
		18: note:= 56; // = G#4
		19: note:= 58; // = A#4
		20: note:= 61; // = C#5
		21: note:= 63; // = D#5
		22: note:= 66; // = F#5
		23: note:= 68; // = G#5
		24: note:= 70; // = A#5
		25: note:= 73; // = C#6
		26: note:= 75; // = D#6
		27: note:= 78; // = F#6
		28: note:= 80; // = G#6
		29: note:= 82; // = A#6
		30: note:= 85; // = C#7
		31: note:= 87; // = D#7
		32: note:= 90; // = F#7
		33: note:= 92; // = G#7
		34: note:= 94; // = A#7
		35: note:= 97; // = C#8
		36: note:= 99; // = D#8
		37: note:= 102;// = F#8
		38: note:= 104;// = G#8
		39: note:= 106;// = A#8
		40: note:= 109;// = C#9
		41: note:= 111;// = D#9
		42: note:= 114;// = F#9
		43: note:= 116;// = G#9
		44: note:= 118;// = A#9
	end;

	result:= note;

end;


procedure TInstrumentEditor.updatePianoWhiteKeys;
begin
	
	if inMenuItem then exit;

	if (GetPianoKeyFromKeyboard <> -1) and (ConvertNote2WhitePianoKeyboard(VirtualPianoGetNoteFromKeyboard) <> -1) then
		DrawPianoPressedWhiteKey(17 + GetPianoKeyFromKeyboard * (pianokeyWhiteWidth + 4));
	

	if mouseL and allowPianoKeys and ((InstrumentEditorTUI.lockedItem = -1) or (InstrumentEditorTUI.lockedItem = -2)) then begin
		if (isPianoBlackKeyMouseOver = -1) and (isPianoWhiteKeyMouseOver <> -1) then begin
			DrawPianoPressedWhiteKey(17 + isPianoWhiteKeyMouseOver * (pianokeyWhiteWidth + 4));
			if isInMapping then MakeNoteChosen(convertWhiteKey2noteNumber(isPianoWhiteKeyMouseOver) - 12);
			InstrumentEditorTUI.lockedItem:= -2;
		end;
	end;

	if mouseR and allowPianoKeys and ((InstrumentEditorTUI.lockedItem = -1) or (InstrumentEditorTUI.lockedItem = -2)) then begin
		if (isPianoBlackKeyMouseOver = -1) and (isPianoWhiteKeyMouseOver <> -1) then begin
			
			selectingSamples;

			InstrumentEditorTUI.lockedItem:= -2;
		end;
	end;
	
	CurrentNoteTextField.caption:= 'Current Note: ';
	if isPianoWhiteKeyMouseOver <> -1 then begin
		CurrentNoteTextField.caption:= 'Current Note: '+NoteValueTo3Str(convertWhiteKey2noteNumber(isPianoWhiteKeyMouseOver));
	end;
	
end;


procedure TInstrumentEditor.updatePianoBlackKeys;
begin
	
	if inMenuItem then exit;

	if (GetPianoKeyFromKeyboard <> -1) and (ConvertNote2BlackPianoKeyboard(VirtualPianoGetNoteFromKeyboard) <> -1) then
			updatePianoPressedBlackKeys(GetPianoKeyFromKeyboard);

	
	if mouseL and allowPianoKeys and ((InstrumentEditorTUI.lockedItem = -1) or (InstrumentEditorTUI.lockedItem = -2)) then
		if (isPianoBlackKeyMouseOver <> -1) then begin
			updatePianoPressedBlackKeys(isPianoBlackKeyMouseOver);
			if isInMapping then MakeNoteChosen(convertBlackKey2noteNumber(isPianoBlackKeyMouseOver) - 12);
			InstrumentEditorTUI.lockedItem:= -2;
		end;

	if mouseR and allowPianoKeys and ((InstrumentEditorTUI.lockedItem = -1) or (InstrumentEditorTUI.lockedItem = -2)) then begin
		if (isPianoBlackKeyMouseOver <> -1) then begin

			
			selectingSamples;

			InstrumentEditorTUI.lockedItem:= -2;
		end;
	end;
	if isPianoBlackKeyMouseOver <> -1 then begin
		CurrentNoteTextField.caption:= 'Current Note: '+NoteValueTo3Str(convertBlackKey2noteNumber(isPianoBlackKeyMouseOver));
		selectNoteInSheet(convertBlackKey2noteNumber(isPianoBlackKeyMouseOver) - 12);
	end;
end;

procedure TInstrumentEditor.playSample;
var 
	l : longint;
	note : longint;

begin
	
	if (not allowPianoKeys) then exit;
	if inMenuItem then exit;

	if (VirtualPianoGetNoteFromKeyboard <> -1) and (not playing) then begin
			playnote(VirtualPianoGetNoteFromKeyboard);
			playing:= true;			

			if isInMapping then MakeNoteChosen(VirtualPianoGetNoteFromKeyboard - 12);

			exit;
	end;

	if (not mouseL) and (VirtualPianoGetNoteFromKeyboard = -1) then begin
		playnote(NoteCut);
		playing:= false;
		oldPlayedKey:= -1;
	end;

	
	if ((InstrumentEditorTUI.lockedItem = -1) or (InstrumentEditorTUI.lockedItem <> -2)) then exit;

	if mouseL then begin
		
		l:= isPianoBlackKeyMouseOver;
		if (l <> -1) and (l <> oldPlayedKey) then begin

			note:=convertBlackKey2noteNumber(l);

			playnote(note);			
			playing:= true;
			oldPlayedKey:= l;
			
			exit;

		end;
		if l <> -1 then exit;

		l:= isPianoWhiteKeyMouseOver;
		if (l <> -1) and (l <> oldPlayedKey) then begin
			
			note:=convertWhiteKey2noteNumber(l);

			playnote(note);
			playing:= true;
			oldPlayedKey:= l;
			exit;

		end;
	end; 

end; 


procedure TInstrumentEditor.playNote(n: longint);
var 
	note : TNote;

begin	

	Note:= EmptyNote;
	Note.Note:= n;
	Note.Instrument:= CurrentInstrument;
	tralalaEngine.PlayNote(1, Note);

end;