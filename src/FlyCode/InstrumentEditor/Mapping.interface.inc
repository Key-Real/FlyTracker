var

	isInMapping : boolean;



procedure buildMapping;

procedure disableMapping;
procedure enableMapping;

procedure reloadMapping;

var
	noteTextField : array [0..88] of TtuiTextField;
	mappedNoteTextField  : array [0..88] of TtuiTextField;
	mappedSampleTextField  : array [0..88] of TtuiTextField;
	separationLine1 : TtuiLine;
	separationLine2 : TtuiLine;
	separationLine3 : TtuiLine;
	separationLine4 : TtuiLine;
	separationLine5 : TtuiLine;
	separationLine6 : TtuiLine;
	separationLine7 : TtuiLine;
	ButtonClearAll : TtuiButton;
	ButtonClear : TtuiButton;


	selectionRangeStart : longint;
	selectionRangeEnd : longint;

procedure ClearMappingTextFieldColors(clearChosen: boolean);

procedure selectNoteInSheet(note: longint);



procedure execProcButtonClearAll(const param: string);	
procedure execProcButtonClear(const param: string);	

procedure execProcNote0(const param: string);
procedure execProcNote1(const param: string);
procedure execProcNote2(const param: string);
procedure execProcNote3(const param: string);
procedure execProcNote4(const param: string);
procedure execProcNote5(const param: string);
procedure execProcNote6(const param: string);
procedure execProcNote7(const param: string);
procedure execProcNote8(const param: string);
procedure execProcNote9(const param: string);
procedure execProcNote10(const param: string);
procedure execProcNote11(const param: string);
procedure execProcNote12(const param: string);
procedure execProcNote13(const param: string);
procedure execProcNote14(const param: string);
procedure execProcNote15(const param: string);
procedure execProcNote16(const param: string);
procedure execProcNote17(const param: string);
procedure execProcNote18(const param: string);
procedure execProcNote19(const param: string);
procedure execProcNote20(const param: string);
procedure execProcNote21(const param: string);
procedure execProcNote22(const param: string);
procedure execProcNote23(const param: string);
procedure execProcNote24(const param: string);
procedure execProcNote25(const param: string);
procedure execProcNote26(const param: string);
procedure execProcNote27(const param: string);
procedure execProcNote28(const param: string);
procedure execProcNote29(const param: string);
procedure execProcNote30(const param: string);
procedure execProcNote31(const param: string);
procedure execProcNote32(const param: string);
procedure execProcNote33(const param: string);
procedure execProcNote34(const param: string);
procedure execProcNote35(const param: string);
procedure execProcNote36(const param: string);
procedure execProcNote37(const param: string);
procedure execProcNote38(const param: string);
procedure execProcNote39(const param: string);
procedure execProcNote40(const param: string);
procedure execProcNote41(const param: string);
procedure execProcNote42(const param: string);
procedure execProcNote43(const param: string);
procedure execProcNote44(const param: string);
procedure execProcNote45(const param: string);
procedure execProcNote46(const param: string);
procedure execProcNote47(const param: string);
procedure execProcNote48(const param: string);
procedure execProcNote49(const param: string);
procedure execProcNote50(const param: string);
procedure execProcNote51(const param: string);
procedure execProcNote52(const param: string);
procedure execProcNote53(const param: string);
procedure execProcNote54(const param: string);
procedure execProcNote55(const param: string);
procedure execProcNote56(const param: string);
procedure execProcNote57(const param: string);
procedure execProcNote58(const param: string);
procedure execProcNote59(const param: string);
procedure execProcNote60(const param: string);
procedure execProcNote61(const param: string);
procedure execProcNote62(const param: string);
procedure execProcNote63(const param: string);
procedure execProcNote64(const param: string);
procedure execProcNote65(const param: string);
procedure execProcNote66(const param: string);
procedure execProcNote67(const param: string);
procedure execProcNote68(const param: string);
procedure execProcNote69(const param: string);
procedure execProcNote70(const param: string);
procedure execProcNote71(const param: string);
procedure execProcNote72(const param: string);
procedure execProcNote73(const param: string);
procedure execProcNote74(const param: string);
procedure execProcNote75(const param: string);
procedure execProcNote76(const param: string);
procedure execProcNote77(const param: string);
procedure execProcNote78(const param: string);
procedure execProcNote79(const param: string);
procedure execProcNote80(const param: string);
procedure execProcNote81(const param: string);
procedure execProcNote82(const param: string);
procedure execProcNote83(const param: string);
procedure execProcNote84(const param: string);
procedure execProcNote85(const param: string);
procedure execProcNote86(const param: string);
procedure execProcNote87(const param: string);
procedure execProcNote88(const param: string); 

procedure execProcMouseOverNote0(const param: string);
procedure execProcMouseOverNote1(const param: string);
procedure execProcMouseOverNote2(const param: string);
procedure execProcMouseOverNote3(const param: string);
procedure execProcMouseOverNote4(const param: string);
procedure execProcMouseOverNote5(const param: string);
procedure execProcMouseOverNote6(const param: string);
procedure execProcMouseOverNote7(const param: string);
procedure execProcMouseOverNote8(const param: string);
procedure execProcMouseOverNote9(const param: string);
procedure execProcMouseOverNote10(const param: string);
procedure execProcMouseOverNote11(const param: string);
procedure execProcMouseOverNote12(const param: string);
procedure execProcMouseOverNote13(const param: string);
procedure execProcMouseOverNote14(const param: string);
procedure execProcMouseOverNote15(const param: string);
procedure execProcMouseOverNote16(const param: string);
procedure execProcMouseOverNote17(const param: string);
procedure execProcMouseOverNote18(const param: string);
procedure execProcMouseOverNote19(const param: string);
procedure execProcMouseOverNote20(const param: string);
procedure execProcMouseOverNote21(const param: string);
procedure execProcMouseOverNote22(const param: string);
procedure execProcMouseOverNote23(const param: string);
procedure execProcMouseOverNote24(const param: string);
procedure execProcMouseOverNote25(const param: string);
procedure execProcMouseOverNote26(const param: string);
procedure execProcMouseOverNote27(const param: string);
procedure execProcMouseOverNote28(const param: string);
procedure execProcMouseOverNote29(const param: string);
procedure execProcMouseOverNote30(const param: string);
procedure execProcMouseOverNote31(const param: string);
procedure execProcMouseOverNote32(const param: string);
procedure execProcMouseOverNote33(const param: string);
procedure execProcMouseOverNote34(const param: string);
procedure execProcMouseOverNote35(const param: string);
procedure execProcMouseOverNote36(const param: string);
procedure execProcMouseOverNote37(const param: string);
procedure execProcMouseOverNote38(const param: string);
procedure execProcMouseOverNote39(const param: string);
procedure execProcMouseOverNote40(const param: string);
procedure execProcMouseOverNote41(const param: string);
procedure execProcMouseOverNote42(const param: string);
procedure execProcMouseOverNote43(const param: string);
procedure execProcMouseOverNote44(const param: string);
procedure execProcMouseOverNote45(const param: string);
procedure execProcMouseOverNote46(const param: string);
procedure execProcMouseOverNote47(const param: string);
procedure execProcMouseOverNote48(const param: string);
procedure execProcMouseOverNote49(const param: string);
procedure execProcMouseOverNote50(const param: string);
procedure execProcMouseOverNote51(const param: string);
procedure execProcMouseOverNote52(const param: string);
procedure execProcMouseOverNote53(const param: string);
procedure execProcMouseOverNote54(const param: string);
procedure execProcMouseOverNote55(const param: string);
procedure execProcMouseOverNote56(const param: string);
procedure execProcMouseOverNote57(const param: string);
procedure execProcMouseOverNote58(const param: string);
procedure execProcMouseOverNote59(const param: string);
procedure execProcMouseOverNote60(const param: string);
procedure execProcMouseOverNote61(const param: string);
procedure execProcMouseOverNote62(const param: string);
procedure execProcMouseOverNote63(const param: string);
procedure execProcMouseOverNote64(const param: string);
procedure execProcMouseOverNote65(const param: string);
procedure execProcMouseOverNote66(const param: string);
procedure execProcMouseOverNote67(const param: string);
procedure execProcMouseOverNote68(const param: string);
procedure execProcMouseOverNote69(const param: string);
procedure execProcMouseOverNote70(const param: string);
procedure execProcMouseOverNote71(const param: string);
procedure execProcMouseOverNote72(const param: string);
procedure execProcMouseOverNote73(const param: string);
procedure execProcMouseOverNote74(const param: string);
procedure execProcMouseOverNote75(const param: string);
procedure execProcMouseOverNote76(const param: string);
procedure execProcMouseOverNote77(const param: string);
procedure execProcMouseOverNote78(const param: string);
procedure execProcMouseOverNote79(const param: string);
procedure execProcMouseOverNote80(const param: string);
procedure execProcMouseOverNote81(const param: string);
procedure execProcMouseOverNote82(const param: string);
procedure execProcMouseOverNote83(const param: string);
procedure execProcMouseOverNote84(const param: string);
procedure execProcMouseOverNote85(const param: string);
procedure execProcMouseOverNote86(const param: string);
procedure execProcMouseOverNote87(const param: string);
procedure execProcMouseOverNote88(const param: string);