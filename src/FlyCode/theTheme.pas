{$MODE OBJFPC}
unit theTheme;
interface
uses 
    tools,strutils,iniFiles,sysutils,
    tui.Core,
    tui.Button,tui.ButtonDOWN,tui.ButtonUP,
    tui.CheckBox,tui.DropBox,
    tui.EditableSelectBoxNumbered,
    tui.EditField,tui.MenuHorizontal,tui.MenuVertical,
    tui.MiddleScrollBox2Entries,
    tui.ProgressBar,tui.ScrollbarHorizontal,tui.ScrollbarVertical,
    tui.SelectableImage,tui.SelectBox,tui.TextBox,tui.TextField,
    tui.RadioButton;


 const
 	 Theme_Tracker_MainPanel_BackgroundColor : dword = $ff121212;
 	 Theme_Tracker_TrackerBar_BackgroundColor : dword  = $ff2D2D2D;
    Theme_Tracker_TrackerBar_NoteColor : dword  = $ffcccccc;
    Theme_Tracker_TrackerBar_NoteColor_DisabledChannel : dword  = $ff666666;
    Theme_Tracker_TrackerBar_YPosition : dword  = 450;
    Theme_Tracker_MainPanel_FontColor : dword  = $ffcccccc;
    Theme_Tracker_4Row_BackgroundColor : dword  = $ff161616;
    Theme_Tracker_BlockColor : dword = $ff404040;
    Theme_Tracker_BlockColorInMainCursor : dword = $ff505050;
    Theme_Tracker_BlockScroll_Key_TimeOut : dword  = 128;
    Theme_Tracker_MainPanel_SelectFontColor : dword = $ff0098fb;

    Theme_Tracker_EmptyInstrumentColor : dword  = $ff080808;

   Theme_Tracker_DisplayPattern_CursorColor : dword  = $ff000000;
   Theme_Tracker_DisplayPattern_ChannelWidth : dword  = 114;
   Theme_Tracker_DisplayPattern_LeftOffset : dword  = 38;
   Theme_Tracker_DisplayPattern_CursorMode_Note_Offset : dword  = 0;
   Theme_Tracker_DisplayPattern_CursorMode_Note_Length : dword  = 24;
   Theme_Tracker_DisplayPattern_CursorMode_Instrument1_Offset : dword  = 28;
   Theme_Tracker_DisplayPattern_CursorMode_Instrument1_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_CursorMode_Instrument2_Offset : dword  = 34;
   Theme_Tracker_DisplayPattern_CursorMode_Instrument2_Length : dword  = 5;
   Theme_Tracker_DisplayPattern_CursorMode_Volume1_Offset : dword  = 46;
   Theme_Tracker_DisplayPattern_CursorMode_Volume1_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_CursorMode_Volume2_Offset : dword  = 52;
   Theme_Tracker_DisplayPattern_CursorMode_Volume2_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_CursorMode_Effect1_Offset : dword  = 64;
   Theme_Tracker_DisplayPattern_CursorMode_Effect1_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_CursorMode_Effect2_Offset : dword  = 72;
   Theme_Tracker_DisplayPattern_CursorMode_Effect2_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_CursorMode_Effect3_Offset : dword  = 78;
   Theme_Tracker_DisplayPattern_CursorMode_Effect3_Length : dword  = 6;
   Theme_Tracker_DisplayPattern_Key_TimeOut : dword  = 256;
   Theme_Tracker_DisplayPattern_Key_Time_Counter : dword  = 1;
   Theme_Tracker_KeyNote_Timeout : dword  = 200;

   Theme_Tracker_UVMeters_fadeout : dword  = 3;

   Theme_InstrumentEditor_MainPanel_BackgroundColor : dword = $ff121212;
   Theme_InstrumentEditor_MainPanel_FontColor : dword = $ffcccccc;
   Theme_InstrumentEditor_EnvelopeColor : dword = $ff0000ff;
   Theme_InstrumentEditor_SelectFontColor : dword = $ff0098fb;
   Theme_InstrumentEditor_ToucherColor : dword = $ff404040;
   Theme_InstrumentEditor_ToucherMouseOverColor : dword = $ff9e9e9e;
   Theme_InstrumentEditor_LoopLineColor : dword = $ffffffff;
   Theme_InstrumentEditor_WaveColor : dword = $ffcccccc;
   Theme_InstrumentEditor_SelectColor : dword = $ff505050;
   Theme_InstrumentEditor_EnvelopeLineColor : dword = $ffcccccc;
   Theme_InstrumentEditor_EnvelopeToucherColor : dword = $ffcccccc;
   Theme_InstrumentEditor_EnvelopeCurrentToucherColor : dword = $ff0098fb;
   Theme_InstrumentEditor_EnvelopeNumbersColor : dword = $ffcccccc;
   Theme_InstrumentEditor_EnvelopePanningLineColor : dword = $ff424245;
   Theme_InstrumentEditor_EnvelopeSustainLineColor : dword = $ff424245;
   Theme_InstrumentEditor_EnvelopeLoopLineColor : dword = $ffcccccc;
   Theme_InstrumentEditor_KeyBoardSampledColor : dword = $ffff0000;
   Theme_InstrumentEditor_MappedNoteColor : dword = $ff929295;
   Theme_InstrumentEditor_MappedNoteSelectedColor : dword = $ffff0000;
   Theme_InstrumentEditor_MappedLineColor : dword = $ffcccccc;
   Theme_InstrumentEditor_MappedChosenColor : dword = $ff0000ff;

 
   Theme_Box_ActivateBorderUse : boolean = true;
   Theme_Box_ActivateBorderColor : dword = $ffffffff;
   Theme_Box_ActivateBorderInitial :dword = 8;
   Theme_Box_DockOnScreenBorder : boolean = false;
   Theme_Box_FontColorForderground : dword = $ffFFFFFF;
   Theme_Box_BackgroundColor : dword = $ff2D2D2D;
   Theme_Box_LeftTopBorderColor : dword = $ff007ACC;
   Theme_Box_RightBottomBorderColor : dword = $ff007ACC;
   Theme_Box_HintTextColor : dword = $ffffffff;
   Theme_Box_HintBackgroundColor : dword = $ff424245;

   Theme_Button_FontColorForderground :dword= $ffc0c0c0;
   Theme_Button_BackgroundColor :dword= $ff3F3F46;
   Theme_Button_LeftTopBorderColor :dword= $ff858585;
   Theme_Button_RightBottomBorderColor :dword= $ff858585;
   Theme_Button_PressedColor :dword= $ff007acc;
   Theme_Button_PressedTimeout :dword= 8;
   Theme_Button_PressedTimeoutSpeed :dword= 1;
   Theme_Button_SelectedBorderColor :dword= $ff0098fb;
   Theme_Button_YCorrection4top:dword=2;


   Theme_ButtonDOWN_ArrowColor : dword = $ff101010;
   Theme_ButtonDOWN_BackgroundColor : dword = $ff3F3F46;
   Theme_ButtonDOWN_LeftTopBorderColor : dword = $ff858585;
   Theme_ButtonDOWN_RightBottomBorderColor : dword = $ff858585;
   Theme_ButtonDOWN_PressedColor : dword = $ff007acc;
   Theme_ButtonDOWN_PressedTimeOut : dword = 8;
   Theme_ButtonDOWN_PressedTimeOutSpeed : dword = 1;
   Theme_ButtonDOWN_SelectedBorderColor : dword = $ff0098fb;
   Theme_ButtonDOWN_Width: dword = 18;
   Theme_ButtonDOWN_Height: dword = 18;
   Theme_ButtonDOWN_MouseHoldStart :dword = 512;


   Theme_ButtonUP_ArrowColor :dword= $ff101010;
   Theme_ButtonUP_BackgroundColor :dword= $ff3F3F46;
   Theme_ButtonUP_LeftTopBorderColor :dword= $ff858585;
   Theme_ButtonUP_RightBottomBorderColor :dword= $ff858585;
   Theme_ButtonUP_PressedColor :dword= $ff007acc;
   Theme_ButtonUP_PressedTimeout :dword= 8;
   Theme_ButtonUP_PressedTimeoutSpeed :dword= 1;
   Theme_ButtonUP_SelectedBorderColor :dword= $ff0098fb;
   Theme_ButtonUP_Width :dword= 18;
   Theme_ButtonUP_Height :dword= 18;
   Theme_ButtonUP_MouseHoldStart :dword = 512;

   Theme_CheckBox_FontColor :dword= $ffffffff;
   Theme_CheckBox_CheckBoxColor :dword= $ffffffff;
   Theme_CheckBox_SelectedColor :dword= $ff0098fb;

   Theme_DropBox_FontColor :dword= $ffffffff;
   Theme_DropBox_BackgroundColor :dword= $ff3F3F46;
   Theme_DropBox_TextXOffset :dword= 6;
   Theme_DropBox_TextYOffset :dword= 0;
   Theme_DropBox_Height :dword= 18;
   Theme_DropBox_BorderColor :dword= $ff858585;
   Theme_DropBox_SelectedBorderColor :dword= $ff0098fb;
   Theme_DropBox_ArrowBoxWidth:dword = 20;
   Theme_DropBox_ArrowBoxBackgroundColor:dword = $ff686868;
   Theme_DropBox_ArrowColor :dword= $ffefebef;

   Theme_EditableSelectBox_FontColor :dword= $ffffffff;
   Theme_EditableSelectBox_FontColorEmptySlot :dword= $ff000000;
   Theme_EditableSelectBox_BackgroundColor :dword= $ff3F3F46;
   Theme_EditableSelectBox_TextXOffset :dword= 6;
   Theme_EditableSelectBox_TextYOffset :dword= 2;
   Theme_EditableSelectBox_TextHeight :dword= 16;
   Theme_EditableSelectBox_BorderColor:dword= $ff858585;
   Theme_EditableSelectBox_SelectedBorderColor:dword= $ff0098fb;
   Theme_EditableSelectBox_SelectedItemColor:dword= $ff1b1b1c;
   Theme_EditableSelectBox_GlobalYoffset:dword=12;


   Theme_EditableSelectBoxNumbered_FontColor :dword= $ffffffff;
   Theme_EditableSelectBoxNumbered_FontColorEmptySlot :dword= $ff000000;
   Theme_EditableSelectBoxNumbered_BackgroundColor :dword= $ff3F3F46;
   Theme_EditableSelectBoxNumbered_TextXOffset :dword= 6;
   Theme_EditableSelectBoxNumbered_TextYOffset :dword= 2;
   Theme_EditableSelectBoxNumbered_TextHeight :dword= 16;
   Theme_EditableSelectBoxNumbered_BorderColor:dword= $ff858585;
   Theme_EditableSelectBoxNumbered_SelectedBorderColor:dword= $ff0098fb;
   Theme_EditableSelectBoxNumbered_SelectedItemColor:dword= $ff1b1b1c;
   Theme_EditableSelectBoxNumbered_GlobalYoffset:dword=12;


   Theme_EditField_FontColor :dword= $ffffffff;
   Theme_EditField_BackgroundColor :dword= $ff3F3F46;
   Theme_EditField_BackgroundSelectedColor :dword= $ff000000;
   Theme_EditField_BorderColor :dword= $ff858585;
   Theme_EditField_BorderOnMouseOver :boolean= true;
   Theme_EditField_BorderOnMouseOverColor :dword= $ff0098fb;
   Theme_EditField_Height :dword= 20;
   Theme_EditField_TextXoffset :dword= 6;
   Theme_EditField_TextYoffset :dword= 0;
   Theme_EditField_AllwaysBorder :boolean= true;
   Theme_EditField_CursorLength :dword= 4;
   Theme_EditField_KeyTimeOut :dword= 512;
   Theme_EditField_KeyTimeCounter :dword= 16;
   Theme_EditField_LastCharWidth :dword= 14;
   Theme_EditField_EditOnlyOnDoubleClick:boolean=false;


   Theme_MenuHorizontal_BackgroundColor:dword=$ff2d2d30;
   Theme_MenuHorizontal_Highlited:dword=$ff3e3e40;
   Theme_MenuHorizontal_Selected:dword=$ff1b1b1c;
   Theme_MenuHorizontal_TextColor:dword=$ffffffff;
   Theme_MenuHorizontal_XSpaceForItems:dword=16;
   Theme_MenuHorizontal_YSpaceForItems:dword=5;
   Theme_MenuHorizontal_YCorrection4top:dword=2;


   Theme_MenuVertical_BackgroundColor:dword=$ff2d2d30;
   Theme_MenuVertical_Highlited:dword=$ff3e3e40;
   Theme_MenuVertical_Selected:dword=$ff1b1b1c;
   Theme_MenuVertical_TextColor:dword=$ffffffff;
   Theme_MenuVertical_XSpaceForItems:dword=16;
   Theme_MenuVertical_YSpaceForItems:dword=5;
   Theme_MenuVertical_YCorrection4top:dword=2;
   Theme_MenuVertical_DrawBorder:boolean=false;
   Theme_MenuVertical_BorderColor:dword=$ffffffff;


   Theme_MiddleScrollBox_FontColor :dword= $ffffffff;
   Theme_MiddleScrollBox_BackgroundColor :dword= $ff3F3F46;
   Theme_MiddleScrollBox_BorderColor:dword= $ff858585;
   Theme_MiddleScrollBox_MiddleBarColor:dword= $ff858585;
   Theme_MiddleScrollBox_MiddleBarHeight:dword=16;
   Theme_MiddleScrollBox_TextXOffsetLeft:dword=6;
   Theme_MiddleScrollBox_TextXOffsetRight:dword=24;
   Theme_MiddleScrollBox_YCorrection4top:dword=0;
   Theme_MiddleScrollBox_YoffsetCorrection:dword=4;


   Theme_MiddleScrollBox2Entries_FontColor :dword= $ffffffff;
   Theme_MiddleScrollBox2Entries_BackgroundColor :dword= $ff3F3F46;
   Theme_MiddleScrollBox2Entries_BorderColor:dword= $ff858585;
   Theme_MiddleScrollBox2Entries_MiddleBarColor:dword= $ff858585;
   Theme_MiddleScrollBox2Entries_MiddleBarHeight:dword=16;
   Theme_MiddleScrollBox2Entries_TextXOffsetLeft:dword=6;
   Theme_MiddleScrollBox2Entries_TextXOffsetRight:dword=24;
   Theme_MiddleScrollBox2Entries_YCorrection4top:dword=0;
   Theme_MiddleScrollBox2Entries_YoffsetCorrection:dword=4;


   Theme_ProgressBar_FontColor :dword= $ffffffff;                           
   Theme_ProgressBar_ForeGroundColor :dword= $ff858585;                     
   Theme_ProgressBar_BackGroundColor :dword= $ff3F3F46;                     
   Theme_ProgressBar_LeftTopBorderColor :dword= $ff858585;                  
   Theme_ProgressBar_RightBottomBorderColor :dword= $ff858585;              
   Theme_ProgressBar_BorderOnMouseOver :boolean= true;
   Theme_ProgressBar_LeftTopBorderOnMouseOverColor :dword= $ff0098fb;        
   Theme_ProgressBar_RightBottomBorderOnMouseOverColor :dword= $ff0098fb;    
   Theme_ProgressBar_YCorrection4top :dword= 2;


   Theme_ScrollbarHorizontal_BackgroundColor:dword=$ff3e3e42;
   Theme_ScrollbarHorizontal_SliderInactiveColor:dword=$ff686868;
   Theme_ScrollbarHorizontal_SliderMouseOverColor:dword=$ff9e9e9e;
   Theme_ScrollbarHorizontal_SliderActiveColor:dword=$ffefebef;
   Theme_ScrollbarHorizontal_TriangleIconInactiveColor:dword=$ff999999;
   Theme_ScrollbarHorizontal_TriangleIconActiveColor:dword=$ff1c97ea;
   Theme_ScrollbarHorizontal_MinSliderWidth:dword=25;
   Theme_ScrollbarHorizontal_MinSliderHeight:dword=25;
   Theme_ScrollbarHorizontal_Width :dword= 16;
   Theme_ScrollbarHorizontal_Height :dword= 16;
   Theme_ScrollbarHorizontal_DistanceFromArrors:dword=16;
   Theme_ScrollbarHorizontal_ArrowsScrollSpeed:dword=1;
   Theme_ScrollbarHorizontal_MouseHoldStart:qword=512;



   Theme_ScrollbarVertical_BackgroundColor:dword=$ff3e3e42;
   Theme_ScrollbarVertical_SliderInactiveColor:dword=$ff686868;
   Theme_ScrollbarVertical_SliderMouseOverColor:dword=$ff9e9e9e;
   Theme_ScrollbarVertical_SliderActiveColor:dword=$ffefebef;
   Theme_ScrollbarVertical_TriangleIconInactiveColor:dword=$ff999999;
   Theme_ScrollbarVertical_TriangleIconActiveColor:dword=$ff1c97ea;
   Theme_ScrollbarVertical_MinSliderWidth:dword=25;
   Theme_ScrollbarVertical_MinSliderHeight:dword=25;
   Theme_ScrollbarVertical_Width:dword=16;
   Theme_ScrollbarVertical_Height:dword=16;
   Theme_ScrollbarVertical_DistanceFromArrors:dword=16;
   Theme_ScrollbarVertical_ArrowsScrollSpeed:dword=1;
   Theme_ScrollbarVertical_MouseHoldStart:qword=512;


   Theme_SelectableImage_FontColorForderground :dword= $ff101010;
   Theme_SelectableImage_BackgroundColor :dword= $ff3F3F46;
   Theme_SelectableImage_LeftTopBorderColor :dword= $ff858585;
   Theme_SelectableImage_RightBottomBorderColor :dword= $ff858585;
   Theme_SelectableImage_SelectedBorderColor :dword= $ff0098fb;

   Theme_SelectBox_FontColor :dword= $ffffffff;
   Theme_SelectBox_BackgroundColor :dword= $ff3F3F46;
   Theme_SelectBox_TextXOffset :dword= 6;
   Theme_SelectBox_TextYOffset :dword= 1;
   Theme_SelectBox_TextHeight :dword= 16;
   Theme_SelectBox_BorderColor:dword= $ff858585;
   Theme_SelectBox_SelectedBorderColor:dword= $ff0098fb;
   Theme_SelectBox_SelectedItemColor:dword= $ff1b1b1c;
   Theme_SelectBox_GlobalYoffset:dword=0;

   Theme_TextBox_FontColor:dword = $ffffffff;
   Theme_TextBox_BackgroundColor:dword = $ff3F3F46;
   Theme_TextBox_BorderColor:dword = $ff121212;
   Theme_TextBox_Xoffset:dword = 10;
   Theme_TextBox_Yoffset:dword = 10;


   Theme_TextField_FontColor :dword= $ffffffff;
   Theme_TextField_BorderColor :dword= $00000000;
   Theme_TextField_BorderOnMouseOver :boolean= false;
   Theme_TextField_BorderOnMouseOverColor :dword= $ff666666;
   Theme_TextField_OnMouseOverColor : dword = $ff0098fb;
   Theme_TextField_YCorrection4top:dword=2;

   Theme_RadioButton_Color : dword = $ffcccccc;
   Theme_RadioButton_SelectColor : dword = $ff0098fb;
   Theme_RadioButton_FontColor : dword = $ffcccccc;
   Theme_RadioButton_SelectFontColor : dword = $ff0098fb;


   procedure LoadTheme(const filename:string);

   function LoadThemeBox:TtuiThemeBox;
   function LoadThemeButton:TtuiThemeButton;
   function LoadThemeButtonDOWN:TtuiThemeButtonDOWN;
   function LoadThemeButtonUP:TtuiThemeButtonUP;
   function LoadThemeDropBox:TtuiThemeDropBox;
  // function LoadThemeEditableSelectBox:TtuiThemeEditableSelectBox;
   function LoadThemeEditableSelectBoxNumbered:TtuiThemeEditableSelectBoxNumbered;
   function LoadThemeEditField:TtuiThemeEditField;
   function LoadThemeMenuHorizontal:TtuiThemeMenuHorizontal;
   function LoadThemeMenuVertical:TtuiThemeMenuVertical;
 //  function LoadThemeMiddleScrollBox:TtuiThemeMiddleScrollBox;
   function LoadThemeMiddleScrollBox2Entries:TtuiThemeMiddleScrollBox2Entries;
   function LoadThemeScrollbarHorizontal:TtuiThemeScrollbarHorizontal;
   function LoadThemeScrollbarVertical:TtuiThemeScrollbarVertical;
   function LoadThemeSelectableImage:TtuiThemeSelectableImage;
   function LoadThemeSelectBox:TtuiThemeSelectBox;
   function LoadThemeTextBox:TtuiThemeTextBox;
   function LoadThemeTextField:TtuiThemeTextField;
   function LoadThemeCheckBox:TtuiThemeCheckBox;
   function LoadThemeRadioButton:TtuiThemeRadioButton;


implementation


procedure LoadTheme(const filename:string);
var 
    Sett : TIniFile;
begin
   if not exist(filename) then exit;

   Sett:= TIniFile.Create(filename);


   Theme_Tracker_MainPanel_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_MainPanel_BackgroundColor', inttohex(Theme_Tracker_MainPanel_BackgroundColor))));
   Theme_Tracker_TrackerBar_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_TrackerBar_BackgroundColor', inttohex(Theme_Tracker_TrackerBar_BackgroundColor))));
   Theme_Tracker_TrackerBar_NoteColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_TrackerBar_NoteColor', inttohex(Theme_Tracker_TrackerBar_NoteColor))));
   Theme_Tracker_TrackerBar_NoteColor_DisabledChannel:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_TrackerBar_NoteColor_DisabledChannel', inttohex(Theme_Tracker_TrackerBar_NoteColor_DisabledChannel))));
   Theme_Tracker_MainPanel_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_MainPanel_FontColor', inttohex(Theme_Tracker_MainPanel_FontColor))));
   Theme_Tracker_4Row_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_4Row_BackgroundColor', inttohex(Theme_Tracker_4Row_BackgroundColor))));
   Theme_Tracker_BlockColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_BlockColor', inttohex(Theme_Tracker_BlockColor))));
   Theme_Tracker_BlockColorInMainCursor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_BlockColorInMainCursor', inttohex(Theme_Tracker_BlockColorInMainCursor))));
   Theme_Tracker_EmptyInstrumentColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_EmptyInstrumentColor', inttohex(Theme_Tracker_EmptyInstrumentColor))));
   Theme_Tracker_DisplayPattern_CursorColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_DisplayPattern_CursorColor', inttohex(Theme_Tracker_DisplayPattern_CursorColor))));
   Theme_Tracker_MainPanel_SelectFontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Tracker_MainPanel_SelectFontColor', inttohex(Theme_Tracker_MainPanel_SelectFontColor))));

   Theme_InstrumentEditor_MainPanel_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MainPanel_BackgroundColor', inttohex(Theme_Tracker_DisplayPattern_CursorColor))));
   Theme_InstrumentEditor_MainPanel_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MainPanel_FontColor', inttohex(Theme_InstrumentEditor_MainPanel_FontColor))));
   Theme_InstrumentEditor_EnvelopeColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeColor', inttohex(Theme_InstrumentEditor_EnvelopeColor))));
   Theme_InstrumentEditor_SelectFontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_SelectFontColor', inttohex(Theme_InstrumentEditor_SelectFontColor))));
   Theme_InstrumentEditor_ToucherColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_ToucherColor', inttohex(Theme_InstrumentEditor_ToucherColor))));
   Theme_InstrumentEditor_ToucherMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_ToucherMouseOverColor', inttohex(Theme_InstrumentEditor_ToucherMouseOverColor))));
   Theme_InstrumentEditor_LoopLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_LoopLineColor', inttohex(Theme_InstrumentEditor_LoopLineColor))));
   Theme_InstrumentEditor_WaveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_WaveColor', inttohex(Theme_InstrumentEditor_WaveColor))));
   Theme_InstrumentEditor_SelectColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_SelectColor', inttohex(Theme_InstrumentEditor_SelectColor))));
   Theme_InstrumentEditor_EnvelopeLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeLineColor', inttohex(Theme_InstrumentEditor_EnvelopeLineColor))));
   Theme_InstrumentEditor_EnvelopeToucherColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeToucherColor', inttohex(Theme_InstrumentEditor_EnvelopeToucherColor))));
   Theme_InstrumentEditor_EnvelopeCurrentToucherColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeCurrentToucherColor', inttohex(Theme_InstrumentEditor_EnvelopeCurrentToucherColor))));
   Theme_InstrumentEditor_EnvelopeNumbersColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeNumbersColor', inttohex(Theme_InstrumentEditor_EnvelopeNumbersColor))));
   Theme_InstrumentEditor_EnvelopePanningLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopePanningLineColor', inttohex(Theme_InstrumentEditor_EnvelopePanningLineColor))));
   Theme_InstrumentEditor_EnvelopeSustainLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeSustainLineColor', inttohex(Theme_InstrumentEditor_EnvelopeSustainLineColor))));
   Theme_InstrumentEditor_EnvelopeLoopLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_EnvelopeLoopLineColor', inttohex(Theme_InstrumentEditor_EnvelopeLoopLineColor))));
   Theme_InstrumentEditor_KeyBoardSampledColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_KeyBoardSampledColor', inttohex(Theme_InstrumentEditor_KeyBoardSampledColor))));
   Theme_InstrumentEditor_MappedNoteColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MappedNoteColor', inttohex(Theme_InstrumentEditor_MappedNoteColor))));
   Theme_InstrumentEditor_MappedNoteSelectedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MappedNoteSelectedColor', inttohex(Theme_InstrumentEditor_MappedNoteSelectedColor))));
   Theme_InstrumentEditor_MappedLineColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MappedLineColor', inttohex(Theme_InstrumentEditor_MappedLineColor))));
   Theme_InstrumentEditor_MappedChosenColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_InstrumentEditor_MappedChosenColor', inttohex(Theme_InstrumentEditor_MappedChosenColor))));


   Theme_Box_ActivateBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_ActivateBorderColor', inttohex(Theme_Box_ActivateBorderColor))));
   Theme_Box_FontColorForderground:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_FontColorForderground', inttohex(Theme_Box_FontColorForderground))));
   Theme_Box_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_BackgroundColor', inttohex(Theme_Box_BackgroundColor))));
   Theme_Box_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_LeftTopBorderColor', inttohex(Theme_Box_LeftTopBorderColor))));
   Theme_Box_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_RightBottomBorderColor', inttohex(Theme_Box_RightBottomBorderColor))));
   Theme_Box_HintTextColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_HintTextColor', inttohex(Theme_Box_HintTextColor))));
   Theme_Box_HintBackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Box_HintBackgroundColor', inttohex(Theme_Box_HintBackgroundColor))));

   Theme_Button_FontColorForderground:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_FontColorForderground', inttohex(Theme_Button_FontColorForderground))));
   Theme_Button_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_BackgroundColor', inttohex(Theme_Button_BackgroundColor))));
   Theme_Button_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_LeftTopBorderColor', inttohex(Theme_Button_LeftTopBorderColor))));
   Theme_Button_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_RightBottomBorderColor', inttohex(Theme_Button_RightBottomBorderColor))));
   Theme_Button_PressedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_PressedColor', inttohex(Theme_Button_PressedColor))));
   Theme_Button_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_Button_SelectedBorderColor', inttohex(Theme_Button_SelectedBorderColor))));

   Theme_ButtonDOWN_ArrowColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_ArrowColor', inttohex(Theme_ButtonDOWN_ArrowColor))));
   Theme_ButtonDOWN_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_BackgroundColor', inttohex(Theme_ButtonDOWN_BackgroundColor))));
   Theme_ButtonDOWN_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_LeftTopBorderColor', inttohex(Theme_ButtonDOWN_LeftTopBorderColor))));
   Theme_ButtonDOWN_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_RightBottomBorderColor', inttohex(Theme_ButtonDOWN_RightBottomBorderColor))));
   Theme_ButtonDOWN_PressedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_PressedColor', inttohex(Theme_ButtonDOWN_PressedColor))));
   Theme_ButtonDOWN_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonDOWN_SelectedBorderColor', inttohex(Theme_ButtonDOWN_SelectedBorderColor))));

   Theme_ButtonUP_ArrowColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_ArrowColor', inttohex(Theme_ButtonUP_ArrowColor))));
   Theme_ButtonUP_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_BackgroundColor', inttohex(Theme_ButtonUP_BackgroundColor))));
   Theme_ButtonUP_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_LeftTopBorderColor', inttohex(Theme_ButtonUP_LeftTopBorderColor))));
   Theme_ButtonUP_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_RightBottomBorderColor', inttohex(Theme_ButtonUP_RightBottomBorderColor))));
   Theme_ButtonUP_PressedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_PressedColor', inttohex(Theme_ButtonUP_PressedColor))));
   Theme_ButtonUP_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ButtonUP_SelectedBorderColor', inttohex(Theme_ButtonUP_SelectedBorderColor))));

   Theme_CheckBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_CheckBox_FontColor', inttohex(Theme_CheckBox_FontColor))));
   Theme_CheckBox_CheckBoxColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_CheckBox_CheckBoxColor', inttohex(Theme_CheckBox_CheckBoxColor))));
   Theme_CheckBox_SelectedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_CheckBox_SelectedColor', inttohex(Theme_CheckBox_SelectedColor))));

   Theme_DropBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_FontColor', inttohex(Theme_DropBox_FontColor))));
   Theme_DropBox_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_BackgroundColor', inttohex(Theme_DropBox_BackgroundColor))));
   Theme_DropBox_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_BorderColor', inttohex(Theme_DropBox_BorderColor))));
   Theme_DropBox_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_SelectedBorderColor', inttohex(Theme_DropBox_SelectedBorderColor))));
   Theme_DropBox_ArrowBoxBackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_ArrowBoxBackgroundColor', inttohex(Theme_DropBox_ArrowBoxBackgroundColor))));
   Theme_DropBox_ArrowColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_DropBox_ArrowColor', inttohex(Theme_DropBox_ArrowColor))));

   Theme_EditableSelectBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_FontColor', inttohex(Theme_EditableSelectBox_FontColor))));
   Theme_EditableSelectBox_FontColorEmptySlot:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_FontColorEmptySlot', inttohex(Theme_EditableSelectBox_FontColorEmptySlot))));
   Theme_EditableSelectBox_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_BackgroundColor', inttohex(Theme_EditableSelectBox_BackgroundColor))));
   Theme_EditableSelectBox_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_BorderColor', inttohex(Theme_EditableSelectBox_BorderColor))));
   Theme_EditableSelectBox_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_SelectedBorderColor', inttohex(Theme_EditableSelectBox_SelectedBorderColor))));
   Theme_EditableSelectBox_SelectedItemColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBox_SelectedItemColor', inttohex(Theme_EditableSelectBox_SelectedItemColor))));
   Theme_EditableSelectBoxNumbered_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_FontColor', inttohex(Theme_EditableSelectBoxNumbered_FontColor))));
   Theme_EditableSelectBoxNumbered_FontColorEmptySlot:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_FontColorEmptySlot', inttohex(Theme_EditableSelectBoxNumbered_FontColorEmptySlot))));
   Theme_EditableSelectBoxNumbered_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_BackgroundColor', inttohex(Theme_EditableSelectBoxNumbered_BackgroundColor))));
   Theme_EditableSelectBoxNumbered_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_BorderColor', inttohex(Theme_EditableSelectBoxNumbered_BorderColor))));
   Theme_EditableSelectBoxNumbered_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_SelectedBorderColor', inttohex(Theme_EditableSelectBoxNumbered_SelectedBorderColor))));
   Theme_EditableSelectBoxNumbered_SelectedItemColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditableSelectBoxNumbered_SelectedItemColor', inttohex(Theme_EditableSelectBoxNumbered_SelectedItemColor))));

   Theme_EditField_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditField_FontColor', inttohex(Theme_EditField_FontColor))));
   Theme_EditField_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditField_BackgroundColor', inttohex(Theme_EditField_BackgroundColor))));
   Theme_EditField_BackgroundSelectedColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditField_BackgroundSelectedColor', inttohex(Theme_EditField_BackgroundSelectedColor))));
   Theme_EditField_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditField_BorderColor', inttohex(Theme_EditField_BorderColor))));
   Theme_EditField_BorderOnMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_EditField_BorderOnMouseOverColor', inttohex(Theme_EditField_BorderOnMouseOverColor))));

   Theme_MenuHorizontal_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuHorizontal_BackgroundColor', inttohex(Theme_MenuHorizontal_BackgroundColor))));
   Theme_MenuHorizontal_Highlited:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuHorizontal_Highlited', inttohex(Theme_MenuHorizontal_Highlited))));
   Theme_MenuHorizontal_Selected:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuHorizontal_Selected', inttohex(Theme_MenuHorizontal_Selected))));
   Theme_MenuHorizontal_TextColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuHorizontal_TextColor', inttohex(Theme_MenuHorizontal_TextColor))));

   Theme_MenuVertical_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuVertical_BackgroundColor', inttohex(Theme_MenuVertical_BackgroundColor))));
   Theme_MenuVertical_Highlited:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuVertical_Highlited', inttohex(Theme_MenuVertical_Highlited))));
   Theme_MenuVertical_Selected:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuVertical_Selected', inttohex(Theme_MenuVertical_Selected))));
   Theme_MenuVertical_TextColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuVertical_TextColor', inttohex(Theme_MenuVertical_TextColor))));
   Theme_MenuVertical_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MenuVertical_BorderColor', inttohex(Theme_MenuVertical_BorderColor))));

   Theme_MiddleScrollBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox_FontColor', inttohex(Theme_MiddleScrollBox_FontColor))));
   Theme_MiddleScrollBox_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox_BackgroundColor', inttohex(Theme_MiddleScrollBox_BackgroundColor))));
   Theme_MiddleScrollBox_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox_MiddleBarColor', inttohex(Theme_MiddleScrollBox_MiddleBarColor))));
   Theme_MiddleScrollBox_MiddleBarColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox_MiddleBarColor', inttohex(Theme_MiddleScrollBox_MiddleBarColor))));
   Theme_MiddleScrollBox2Entries_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox2Entries_FontColor', inttohex(Theme_MiddleScrollBox2Entries_FontColor))));
   Theme_MiddleScrollBox2Entries_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox2Entries_BackgroundColor', inttohex(Theme_MiddleScrollBox2Entries_BackgroundColor))));
   Theme_MiddleScrollBox2Entries_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox2Entries_BorderColor', inttohex(Theme_MiddleScrollBox2Entries_BorderColor))));
   Theme_MiddleScrollBox2Entries_MiddleBarColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_MiddleScrollBox2Entries_MiddleBarColor', inttohex(Theme_MiddleScrollBox2Entries_MiddleBarColor))));

   Theme_ProgressBar_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_FontColor', inttohex(Theme_ProgressBar_FontColor))));
   Theme_ProgressBar_ForeGroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_ForeGroundColor', inttohex(Theme_ProgressBar_ForeGroundColor))));
   Theme_ProgressBar_BackGroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_BackGroundColor', inttohex(Theme_ProgressBar_BackGroundColor))));
   Theme_ProgressBar_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_LeftTopBorderColor', inttohex(Theme_ProgressBar_LeftTopBorderColor))));
   Theme_ProgressBar_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_RightBottomBorderColor', inttohex(Theme_ProgressBar_RightBottomBorderColor))));
   Theme_ProgressBar_LeftTopBorderOnMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_LeftTopBorderOnMouseOverColor', inttohex(Theme_ProgressBar_LeftTopBorderOnMouseOverColor))));
   Theme_ProgressBar_RightBottomBorderOnMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ProgressBar_RightBottomBorderOnMouseOverColor', inttohex(Theme_ProgressBar_RightBottomBorderOnMouseOverColor))));

   Theme_ScrollbarHorizontal_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_BackgroundColor', inttohex(Theme_ScrollbarHorizontal_BackgroundColor))));
   Theme_ScrollbarHorizontal_SliderInactiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_SliderInactiveColor', inttohex(Theme_ScrollbarHorizontal_SliderInactiveColor))));
   Theme_ScrollbarHorizontal_SliderMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_SliderMouseOverColor', inttohex(Theme_ScrollbarHorizontal_SliderMouseOverColor))));
   Theme_ScrollbarHorizontal_SliderActiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_SliderActiveColor', inttohex(Theme_ScrollbarHorizontal_SliderActiveColor))));
   Theme_ScrollbarHorizontal_TriangleIconInactiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_TriangleIconInactiveColor', inttohex(Theme_ScrollbarHorizontal_TriangleIconInactiveColor))));
   Theme_ScrollbarHorizontal_TriangleIconActiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarHorizontal_TriangleIconActiveColor', inttohex(Theme_ScrollbarHorizontal_TriangleIconActiveColor))));

   Theme_ScrollbarVertical_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_BackgroundColor', inttohex(Theme_ScrollbarVertical_BackgroundColor))));
   Theme_ScrollbarVertical_SliderInactiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_SliderInactiveColor', inttohex(Theme_ScrollbarVertical_SliderInactiveColor))));
   Theme_ScrollbarVertical_SliderMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_SliderMouseOverColor', inttohex(Theme_ScrollbarVertical_SliderMouseOverColor))));
   Theme_ScrollbarVertical_SliderActiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_SliderActiveColor', inttohex(Theme_ScrollbarVertical_SliderActiveColor))));
   Theme_ScrollbarVertical_TriangleIconInactiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_TriangleIconInactiveColor', inttohex(Theme_ScrollbarVertical_TriangleIconInactiveColor))));
   Theme_ScrollbarVertical_TriangleIconActiveColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_ScrollbarVertical_TriangleIconActiveColor', inttohex(Theme_ScrollbarVertical_TriangleIconActiveColor))));

   Theme_SelectableImage_FontColorForderground:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectableImage_FontColorForderground', inttohex(Theme_SelectableImage_FontColorForderground))));
   Theme_SelectableImage_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectableImage_BackgroundColor', inttohex(Theme_SelectableImage_BackgroundColor))));
   Theme_SelectableImage_LeftTopBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectableImage_LeftTopBorderColor', inttohex(Theme_SelectableImage_LeftTopBorderColor))));
   Theme_SelectableImage_RightBottomBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectableImage_RightBottomBorderColor', inttohex(Theme_SelectableImage_RightBottomBorderColor))));
   Theme_SelectableImage_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectableImage_SelectedBorderColor', inttohex(Theme_SelectableImage_SelectedBorderColor))));

   Theme_SelectBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectBox_FontColor', inttohex(Theme_SelectBox_FontColor))));
   Theme_SelectBox_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectBox_BackgroundColor', inttohex(Theme_SelectBox_BackgroundColor))));
   Theme_SelectBox_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectBox_BorderColor', inttohex(Theme_SelectBox_BorderColor))));
   Theme_SelectBox_SelectedBorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectBox_SelectedBorderColor', inttohex(Theme_SelectBox_SelectedBorderColor))));
   Theme_SelectBox_SelectedItemColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_SelectBox_SelectedItemColor', inttohex(Theme_SelectBox_SelectedItemColor))));

   Theme_TextBox_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextBox_FontColor', inttohex(Theme_TextBox_FontColor))));
   Theme_TextBox_BackgroundColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextBox_BackgroundColor', inttohex(Theme_TextBox_BackgroundColor))));
   Theme_TextBox_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextBox_BorderColor', inttohex(Theme_TextBox_BorderColor))));

   Theme_TextField_FontColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextField_FontColor', inttohex(Theme_TextField_FontColor))));
   Theme_TextField_BorderColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextField_BorderColor', inttohex(Theme_TextField_BorderColor))));
   Theme_TextField_BorderOnMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextField_BorderOnMouseOverColor', inttohex(Theme_TextField_BorderOnMouseOverColor))));
   Theme_TextField_OnMouseOverColor:=dword(hex2dec(Sett.ReadString('colors', 'Theme_TextField_OnMouseOverColor', inttohex(Theme_TextField_OnMouseOverColor))));

   Theme_RadioButton_Color:=dword(hex2dec(Sett.ReadString('colors', 'Theme_RadioButton_Color', inttohex(Theme_RadioButton_Color))));
   Sett.Free; 
end;


function LoadThemeBox:TtuiThemeBox;
begin
   result.ActivateBorderUse := Theme_Box_ActivateBorderUse;
   result.ActivateBorderColor := Theme_Box_ActivateBorderColor;
   result.ActivateBorderInitial := Theme_Box_ActivateBorderInitial;
   result.DockOnScreenBorder := Theme_Box_DockOnScreenBorder;
   result.FontColorForderground := Theme_Box_FontColorForderground;
   result.BackgroundColor := Theme_Box_BackgroundColor;
   result.LeftTopBorderColor := Theme_Box_LeftTopBorderColor;
   result.RightBottomBorderColor := Theme_Box_RightBottomBorderColor;
   result.HintTextColor:= Theme_Box_HintTextColor;
   result.HintBackgroundColor:=Theme_Box_HintBackgroundColor;
end;


function LoadThemeButton:TtuiThemeButton;
begin
   result.FontColorForderground:=Theme_Button_FontColorForderground;
   result.BackgroundColor:=Theme_Button_BackgroundColor;
   result.LeftTopBorderColor:=Theme_Button_LeftTopBorderColor;
   result.RightBottomBorderColor:=Theme_Button_RightBottomBorderColor;
   result.PressedColor:=Theme_Button_PressedColor;
   result.PressedTimeOut:=Theme_Button_PressedTimeout;
   result.PressedTimeOutSpeed:=Theme_Button_PressedTimeoutSpeed;
   result.SelectedBorderColor:=Theme_Button_SelectedBorderColor;
   result.YCorrection4top:=Theme_Button_YCorrection4top;
end;


function LoadThemeButtonDOWN:TtuiThemeButtonDOWN;
begin
   result.ArrowColor := Theme_ButtonDOWN_ArrowColor;
   result.BackgroundColor := Theme_ButtonDOWN_BackgroundColor;
   result.LeftTopBorderColor := Theme_ButtonDOWN_LeftTopBorderColor;
   result.RightBottomBorderColor := Theme_ButtonDOWN_RightBottomBorderColor;
   result.PressedColor := Theme_ButtonDOWN_PressedColor;
   result.PressedTimeout := Theme_ButtonDOWN_PressedTimeOut;
   result.PressedTimeoutSpeed := Theme_ButtonDOWN_PressedTimeOutSpeed;
   result.SelectedBorderColor := Theme_ButtonDOWN_SelectedBorderColor;
   result.Width := Theme_ButtonDOWN_Width;
   result.Height := Theme_ButtonDOWN_Height;
   result.mouseHoldStart:=Theme_ButtonDOWN_MouseHoldStart;
end;


function LoadThemeButtonUP:TtuiThemeButtonUP;
begin
   result.ArrowColor := Theme_ButtonUP_ArrowColor;
   result.BackgroundColor := Theme_ButtonUP_BackgroundColor;
   result.LeftTopBorderColor := Theme_ButtonUP_LeftTopBorderColor;
   result.RightBottomBorderColor := Theme_ButtonUP_RightBottomBorderColor;
   result.PressedColor := Theme_ButtonUP_PressedColor;
   result.PressedTimeout := Theme_ButtonUP_PressedTimeout;
   result.PressedTimeoutSpeed := Theme_ButtonUP_PressedTimeoutSpeed;
   result.SelectedBorderColor := Theme_ButtonUP_SelectedBorderColor;
   result.Width := Theme_ButtonUP_Width;
   result.Height := Theme_ButtonUP_Height;
   result.mouseHoldStart:=Theme_ButtonUP_MouseHoldStart;
end;


function LoadThemeCheckBox:TtuiThemeCheckBox;
begin
   result.FontColor := Theme_CheckBox_FontColor;
   result.CheckBoxColor := Theme_CheckBox_CheckBoxColor;
   result.SelectedColor := Theme_CheckBox_SelectedColor;
end;


function LoadThemeDropBox:TtuiThemeDropBox;
begin
   result.FontColor := Theme_DropBox_FontColor;
   result.BackgroundColor := Theme_DropBox_BackgroundColor;

   result.TextXOffset := Theme_DropBox_TextXOffset;
   result.TextYOffset := Theme_DropBox_TextYOffset;

   result.Height:=Theme_DropBox_Height;

   result.BorderColor:= Theme_DropBox_BorderColor;
   result.SelectedBorderColor:= Theme_DropBox_SelectedBorderColor;

   result.ArrowBoxWidth := Theme_DropBox_ArrowBoxWidth;
   result.ArrowBoxBackgroundColor :=Theme_DropBox_ArrowBoxBackgroundColor;
   result.ArrowColor := Theme_DropBox_ArrowColor;                   
end;

{
function LoadThemeEditableSelectBox:TtuiThemeEditableSelectBox;
begin
   result.FontColor :=Theme_EditableSelectBox_FontColor;
   result.FontColorEmptySlot := Theme_EditableSelectBox_FontColorEmptySlot;
   result.BackgroundColor := Theme_EditableSelectBox_BackgroundColor;

   result.TextXOffset := Theme_EditableSelectBox_TextXOffset;
   result.TextYOffset :=Theme_EditableSelectBox_TextYOffset;

   result.TextHeight := Theme_EditableSelectBox_TextHeight;

   result.BorderColor:= Theme_EditableSelectBox_BorderColor;
   result.SelectedBorderColor:= Theme_EditableSelectBox_SelectedBorderColor;
   result.SelectedItemColor:= Theme_EditableSelectBox_SelectedItemColor;

   result.GlobalYoffset:=Theme_EditableSelectBox_GlobalYoffset;
end;
}

function LoadThemeEditableSelectBoxNumbered:TtuiThemeEditableSelectBoxNumbered;
begin
    result.FontColor := Theme_EditableSelectBoxNumbered_FontColor;
    result.FontColorEmptySlot := Theme_EditableSelectBoxNumbered_FontColorEmptySlot;
    result.BackgroundColor := Theme_EditableSelectBoxNumbered_BackgroundColor;

    result.TextXOffset := Theme_EditableSelectBoxNumbered_TextXOffset;
    result.TextYOffset := Theme_EditableSelectBoxNumbered_TextYOffset;

    result.TextHeight := Theme_EditableSelectBoxNumbered_TextHeight;

    result.BorderColor:= Theme_EditableSelectBoxNumbered_BorderColor;
    result.SelectedBorderColor:= Theme_EditableSelectBoxNumbered_SelectedBorderColor;
    result.SelectedItemColor:= Theme_EditableSelectBoxNumbered_SelectedItemColor;

    result.GlobalYoffset:=Theme_EditableSelectBoxNumbered_GlobalYoffset;
end;


function LoadThemeEditField:TtuiThemeEditField;
begin
   result.FontColor := Theme_EditField_FontColor;
   result.BackgroundColor :=Theme_EditField_BackgroundColor;
   result.BackgroundSelectedColor :=Theme_EditField_BackgroundSelectedColor;

   result.BorderColor := Theme_EditField_BorderColor;
   result.BorderOnMouseOver := Theme_EditField_BorderOnMouseOver;
   result.BorderOnMouseOverColor := Theme_EditField_BorderOnMouseOverColor;

   result.Height := Theme_EditField_Height;
   result.TextXoffset := Theme_EditField_TextXoffset;
   result.TextYoffset := Theme_EditField_TextYoffset;

   result.AllwaysBorder := Theme_EditField_AllwaysBorder;

   result.CursorLength := Theme_EditField_CursorLength;

   result.KeyTimeOut := Theme_EditField_KeyTimeOut;
   result.KeyTimeCounter := Theme_EditField_KeyTimeCounter;
   result.LastCharWidth := Theme_EditField_LastCharWidth;

   result.EditOnlyOnDoubleClick:=Theme_EditField_EditOnlyOnDoubleClick;
end;


function LoadThemeMenuHorizontal:TtuiThemeMenuHorizontal;
begin
   result.BackgroundColor:=Theme_MenuHorizontal_BackgroundColor;
   result.Highlited:=Theme_MenuHorizontal_Highlited;
   result.Selected:=Theme_MenuHorizontal_Selected;
   result.TextColor:=Theme_MenuHorizontal_TextColor;
   result.XSpaceForItems:=Theme_MenuHorizontal_XSpaceForItems;
   result.YSpaceForItems:=Theme_MenuHorizontal_YSpaceForItems;
   result.YCorrection4top:=Theme_MenuHorizontal_YCorrection4top;
end;


function LoadThemeMenuVertical:TtuiThemeMenuVertical;
begin
   result.BackgroundColor:=Theme_MenuVertical_BackgroundColor;
   result.Highlited:=Theme_MenuVertical_Highlited;
   result.Selected:=Theme_MenuVertical_Selected;
   result.TextColor:=Theme_MenuVertical_TextColor;
   result.XSpaceForItems:=Theme_MenuVertical_XSpaceForItems;
   result.YSpaceForItems:=Theme_MenuVertical_YSpaceForItems;
   result.YCorrection4top:=Theme_MenuVertical_YCorrection4top;
   result.DrawBorder:=Theme_MenuVertical_DrawBorder;
   result.BorderColor:=Theme_MenuVertical_BorderColor;
end;

{
function LoadThemeMiddleScrollBox:TtuiThemeMiddleScrollBox;
begin
   result.FontColor := Theme_MiddleScrollBox_FontColor;
   result.BackgroundColor := Theme_MiddleScrollBox_BackgroundColor;
   result.BorderColor:= Theme_MiddleScrollBox_BorderColor;
   result.MiddleBarColor:= Theme_MiddleScrollBox_MiddleBarColor;
   result.MiddleBarHeight:=Theme_MiddleScrollBox_MiddleBarHeight;
   result.TextXOffsetLeft:=Theme_MiddleScrollBox_TextXOffsetLeft;
   result.YCorrection4top:=Theme_MiddleScrollBox_YCorrection4top;
   result.YoffsetCorrection:=Theme_MiddleScrollBox_YoffsetCorrection;
end;
}

function LoadThemeMiddleScrollBox2Entries:TtuiThemeMiddleScrollBox2Entries;
begin
   result.FontColor := Theme_MiddleScrollBox2Entries_FontColor;
   result.BackgroundColor := Theme_MiddleScrollBox2Entries_BackgroundColor;
   result.BorderColor:= Theme_MiddleScrollBox2Entries_BorderColor;
   result.MiddleBarColor:= Theme_MiddleScrollBox2Entries_MiddleBarColor;
   result.MiddleBarHeight:=Theme_MiddleScrollBox2Entries_MiddleBarHeight;
   result.TextXOffsetLeft:=Theme_MiddleScrollBox2Entries_TextXOffsetLeft;
   result.TextXOffsetRight:=Theme_MiddleScrollBox2Entries_TextXOffsetRight;
   result.YCorrection4top:=Theme_MiddleScrollBox2Entries_YCorrection4top;
   result.YoffsetCorrection:=Theme_MiddleScrollBox2Entries_YoffsetCorrection;
end;


function LoadThemeProgressBar:TtuiThemeProgressBar;
begin
   result.FontColor := Theme_ProgressBar_FontColor;                           
   result.ForeGroundColor := Theme_ProgressBar_ForeGroundColor;                     
   result.BackGroundColor := Theme_ProgressBar_BackGroundColor;                     
   result.LeftTopBorderColor :=Theme_ProgressBar_LeftTopBorderColor;                  
   result.RightBottomBorderColor := Theme_ProgressBar_RightBottomBorderColor;              
   result.BorderOnMouseOver := Theme_ProgressBar_BorderOnMouseOver;
   result.LeftTopBorderOnMouseOverColor :=Theme_ProgressBar_LeftTopBorderOnMouseOverColor;        
   result.RightBottomBorderOnMouseOverColor := Theme_ProgressBar_RightBottomBorderOnMouseOverColor;    
   result.YCorrection4top := Theme_ProgressBar_YCorrection4top;
end;


function LoadThemeScrollbarHorizontal:TtuiThemeScrollbarHorizontal;
begin
   result.BackgroundColor:=Theme_ScrollbarHorizontal_BackgroundColor;
   result.SliderInactiveColor:=Theme_ScrollbarHorizontal_SliderInactiveColor;
   result.SliderMouseOverColor:=Theme_ScrollbarHorizontal_SliderMouseOverColor;
   result.SliderActiveColor:=Theme_ScrollbarHorizontal_SliderActiveColor;
   result.TriangleIconInactiveColor:=Theme_ScrollbarHorizontal_TriangleIconInactiveColor;
   result.TriangleIconActiveColor:=Theme_ScrollbarHorizontal_TriangleIconActiveColor;
   result.MinSliderWidth:=Theme_ScrollbarHorizontal_MinSliderWidth;
   result.MinSliderHeight:=Theme_ScrollbarHorizontal_MinSliderHeight;
   result.Width := Theme_ScrollbarHorizontal_Width;
   result.Height := Theme_ScrollbarHorizontal_Height;
   result.DistanceFromArrors:=Theme_ScrollbarHorizontal_DistanceFromArrors;
   result.ArrowsScrollSpeed:=Theme_ScrollbarHorizontal_ArrowsScrollSpeed;
   result.mouseHoldStart:=Theme_ScrollbarHorizontal_MouseHoldStart;
end;



function LoadThemeScrollbarVertical:TtuiThemeScrollbarVertical;
begin
   result.BackgroundColor:=Theme_ScrollbarVertical_BackgroundColor;
   result.SliderInactiveColor:=Theme_ScrollbarVertical_SliderInactiveColor;
   result.SliderMouseOverColor:=Theme_ScrollbarVertical_SliderMouseOverColor;
   result.SliderActiveColor:=Theme_ScrollbarVertical_SliderActiveColor;
   result.TriangleIconInactiveColor:=Theme_ScrollbarVertical_TriangleIconInactiveColor;
   result.TriangleIconActiveColor:=Theme_ScrollbarVertical_TriangleIconActiveColor;
   result.MinSliderWidth:=Theme_ScrollbarVertical_MinSliderWidth;
   result.MinSliderHeight:=Theme_ScrollbarVertical_MinSliderHeight;
   result.Width:=Theme_ScrollbarVertical_Width;
   result.Height:=Theme_ScrollbarVertical_Height;
   result.DistanceFromArrors:=Theme_ScrollbarVertical_DistanceFromArrors;
   result.ArrowsScrollSpeed:=Theme_ScrollbarVertical_ArrowsScrollSpeed;
   result.mouseHoldStart:=Theme_ScrollbarVertical_MouseHoldStart;
end;


function LoadThemeSelectableImage:TtuiThemeSelectableImage;
begin
   result.FontColorForderground := Theme_SelectableImage_FontColorForderground;
   result.BackgroundColor :=Theme_SelectableImage_BackgroundColor;
   result.LeftTopBorderColor :=Theme_SelectableImage_LeftTopBorderColor;
   result.RightBottomBorderColor := Theme_SelectableImage_RightBottomBorderColor;
   result.SelectedBorderColor :=Theme_SelectableImage_SelectedBorderColor;
end;


function LoadThemeSelectBox:TtuiThemeSelectBox;
begin
   result.FontColor := Theme_SelectBox_FontColor;
   result.BackgroundColor := Theme_SelectBox_BackgroundColor;
   result.TextXOffset := Theme_SelectBox_TextXOffset;
   result.TextYOffset := Theme_SelectBox_TextYOffset;
   result.TextHeight := Theme_SelectBox_TextHeight;
   result.BorderColor:= Theme_SelectBox_BorderColor;
   result.SelectedBorderColor:= Theme_SelectBox_SelectedBorderColor;
   result.SelectedItemColor:= Theme_SelectBox_SelectedItemColor;
   result.GlobalYoffset:=Theme_SelectBox_GlobalYoffset;
end;


function LoadThemeTextBox:TtuiThemeTextBox;
begin
   result.FontColor:= Theme_TextBox_FontColor;
   result.BackgroundColor:= Theme_TextBox_BackgroundColor;
   result.BorderColor:= Theme_TextBox_BorderColor;
   result.DrawBackground:= true;
   result.Xoffset:= Theme_TextBox_Xoffset;
   result.Yoffset:= Theme_TextBox_Yoffset;
end;


function LoadThemeTextField:TtuiThemeTextField;
begin
   result.FontColor := Theme_TextField_FontColor;
   result.BorderColor := Theme_TextField_BorderColor;
   result.BorderOnMouseOver := Theme_TextField_BorderOnMouseOver;
   result.BorderOnMouseOverColor :=Theme_TextField_BorderOnMouseOverColor;
   result.OnMouseOverColor:=Theme_TextField_OnMouseOverColor;
   result.YCorrection4top:=Theme_TextField_YCorrection4top;
   result.HighlightOnMouseOver:=false;
end;

function LoadThemeRadioButton:TtuiThemeRadioButton;
begin
   result.Color:=Theme_RadioButton_Color;
   result.SelectColor:=Theme_RadioButton_SelectColor;
   result.FontColor:=Theme_RadioButton_FontColor;
   result.SelectFontColor:=Theme_RadioButton_SelectFontColor;
end;

begin
end.