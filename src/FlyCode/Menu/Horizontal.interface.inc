public
	
	BoxVerticalMenuFile : TtuiBox;
	BoxVerticalMenuSong : TtuiBox;

	MenuHorizontal : TtuiMenuHorizontal;
	MenuHorizontalBox : TtuiBox;

	FileMenuVertical : TtuiMenuVertical;
	SongMenuVertical : TtuiMenuVertical;
	HelpMenuVertical : TtuiMenuVertical;
	BoxVerticalMenuHelp : TtuiBox;

	NoteImage : gfxImage;

	constructor Create(parentTUI: TtuiTUI);
	destructor Destroy; override;
	procedure drawNote(img: gfxImage);

    procedure execProcMenuWindowUnSelect(const param: string);
    procedure execProcMenuWindowSelect(const param: string);
    procedure execProcMenuItemFullScreen(const param: string);
    procedure execProcMenuItemWindowMode(const param: string);

    
	procedure execProcMenuNoteUnSelect(const param: string);
    procedure execProcMenuNoteSelect(const param: string);
    procedure execProcMenuItemTracker(const param: string);
    procedure execProcMenuItemPianoRoll(const param: string);
    procedure execProcMenuItemInstrumentEditor(const param: string);

	
	var DialogMessageBox : TtuiDialogMessageBox;	