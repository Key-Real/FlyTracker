
var
          NewFileBox : TtuiBox;
          TextFieldNewFile : TtuiTextField;
          NewFileCheckBoxKeepPatterns : TtuiCheckBox;
          NewFileCheckBoxKeepSamples : TtuiCheckBox;
          NewFileCheckBoxKeepInstruments : TtuiCheckBox;
          NewFileCheckBoxKeepOrder : TtuiCheckBox;
          RadioButtonGroupModuleType : TtuiRadioButtonGroup;
          RadioButtonModuleTypeSample : TtuiRadioButton;
          RadioButtonModuleTypeInstrument : TtuiRadioButton;
          ButtonNewFileOK : TtuiButton;
          ButtonNewFileCancel : TtuiButton;


     procedure execProcMenuItemNewFile(const param: string);
     procedure execProcMenuItemNewFileOK(const param: string);
     procedure execProcMenuItemNewFileCancel(const param: string);


     procedure execProcMenuFileSelect(const param: string);
     procedure execProcMenuFileUnSelect(const param: string);




     procedure execProcMenuItemExit(const param: string);

const
     lastPathSaveFile : string = './';
     lastScrollSaveFile : longint = 0;
     lastChosenSaveFile : longint = 0;
     lastScrollBarPositionSaveFile : longint = 0;
type
     TmySaveFileDialog = class

          parentTUI : TtuiTUI;

          theDialogSaveFile : TtuiDialogSaveFile;

          this : PObject;
        
          constructor create(Instance: PObject; theTUI: TtuiTUI);
          destructor destroy; override;

          procedure execProcSuccess(const param: string);
          procedure execProcCancel(const param: string);
     end;

var
     aDialogSaveFile : TmySaveFileDialog;

const
     LoadFileLastStateCurPath : string = './';
     LoadFileLastStateChosen : longint = 0;
     LoadFileLastStateScrolled : longint = 0;
     LoadFileLastStateScrollBarPosition : longint = 0;

const
     lastFileName : string = 'mySong.it';



     procedure execProcMenuItemSaveFile(const param: string);


type  
    TmyLoadFileDialog = class
          theDialogLoadFile : TtuiDialogLoadFile;
          theCantLoadFileDialogMessageBox : TtuiDialogMessageBox;

          parentTUI : TtuiTUI;

          this : PObject;

          constructor create(Instance: PObject; theTUI: TtuiTUI);
          destructor destroy; override;
          
          


          procedure execProcSuccess(const param: string);
          procedure execProcCancel(const param: string);
     end;

var
    aDialogLoadFile : TmyLoadFileDialog;
    procedure execProcMenuItemLoadFile(const param: string);     





const
     lastPathWavSaveFile : string = './';
     lastScrollWavSaveFile : longint = 0;
     lastChosenWavSaveFile : longint = 0;
     lastScrollBarPositionWavSaveFile : longint = 0;


type
     TmyWavSaveFileDialog = class

          parentTUI : TtuiTUI;
          
        theDialogWavSaveFile : TtuiDialogSaveFile;
        this : PObject;
        
        constructor create(Instance: PObject; theTUI: TtuiTUI);
        destructor destroy; override;

        procedure execProcSuccess(const param: string);
        procedure execProcCancel(const param: string);
     end;

var
     aDialogWavSaveFile : TmyWavSaveFileDialog;

const
     lastWavFileName : string = 'mySong.wav';



var
     BoxVerticalMenuFileExport : TtuiBox;
     FileExportMenuVertical : TtuiMenuVertical;

     
     procedure execProcMenuItemExportFileSelect(const param: string);
     procedure execProcMenuItemExportFileUnSelect(const param: string);


     procedure execProcMenuItemNewFileSelect(const param: string);
     procedure execProcMenuItemSaveFileSelect(const param: string);
     procedure execProcMenuItemLoadFileSelect(const param: string);
     procedure execProcMenuItemWavSaveFileSelect(const param: string);
     procedure execProcMenuItemConnectionSelect(const param: string);
     procedure execProcMenuItemExitSelect(const param: string);




     procedure execProcMenuItemSaveMODFile(const param: string);
const
     lastMODFileName : string = 'myMOD.mod';
     lastPathSaveMODFile : string = './';
     lastScrollSaveMODFile : longint = 0;
     lastChosenSaveMODFile : longint = 0;
     lastScrollBarPositionSaveMODFile : longint = 0;
type
     TmySaveMODFileDialog = class

          parentTUI : TtuiTUI;

          theDialogSaveMODFile : TtuiDialogSaveFile;

          this : PObject;
        
          constructor create(Instance: PObject; theTUI: TtuiTUI);
          destructor destroy; override;

          procedure execProcSuccess(const param: string);
          procedure execProcCancel(const param: string);
     end;

var
     aDialogSaveMODFile : TmySaveMODFileDialog;




     procedure execProcMenuItemSaveS3MFile(const param: string);
const
     lastS3MFileName : string = 'myS3M.s3m';
     lastPathSaveS3MFile : string = './';
     lastScrollSaveS3MFile : longint = 0;
     lastChosenSaveS3MFile : longint = 0;
     lastScrollBarPositionSaveS3MFile : longint = 0;
type
     TmySaveS3MFileDialog = class

          parentTUI : TtuiTUI;

          theDialogSaveS3MFile : TtuiDialogSaveFile;

          this : PObject;
        
          constructor create(Instance: PObject; theTUI: TtuiTUI);
          destructor destroy; override;

          procedure execProcSuccess(const param: string);
          procedure execProcCancel(const param: string);
     end;

var
     aDialogSaveS3MFile : TmySaveS3MFileDialog;




     procedure execProcMenuItemSaveXMFile(const param: string);
const
     lastXMFileName : string = 'myXM.xm';
     lastPathSaveXMFile : string = './';
     lastScrollSaveXMFile : longint = 0;
     lastChosenSaveXMFile : longint = 0;
     lastScrollBarPositionSaveXMFile : longint = 0;
type
     TmySaveXMFileDialog = class

          parentTUI : TtuiTUI;

          theDialogSaveXMFile : TtuiDialogSaveFile;

          this : PObject;
        
          constructor create(Instance: PObject; theTUI: TtuiTUI);
          destructor destroy; override;

          procedure execProcSuccess(const param: string);
          procedure execProcCancel(const param: string);
     end;

var
     aDialogSaveXMFile : TmySaveXMFileDialog;












     procedure execProcMenuItemWavSaveFile(const param: string);

