object FMain_11011981: TFMain_11011981
  Left = 243
  Top = 103
  Caption = 'Interactive Delphi Reconstructor'
  ClientHeight = 674
  ClientWidth = 1002
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu
  Position = poDefault
  WindowState = wsMaximized
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  TextHeight = 13
  object SplitterH1: TSplitter
    Left = 0
    Top = 526
    Width = 1002
    Height = 4
    Cursor = crVSplit
    Align = alBottom
    AutoSnap = False
    Beveled = True
    Color = clGray
    MinSize = 100
    ParentColor = False
  end
  object SplitterV1: TSplitter
    Left = 246
    Top = 0
    Height = 526
    AutoSnap = False
    Beveled = True
    Color = clGray
    MinSize = 3
    ParentColor = False
  end
  object pcWorkArea: TPageControl
    Left = 249
    Top = 0
    Width = 753
    Height = 526
    ActivePage = tsCodeView
    Align = alClient
    TabOrder = 1
    OnChange = pcWorkAreaChange
    ExplicitWidth = 747
    ExplicitHeight = 517
    object tsCodeView: TTabSheet
      Caption = 'CodeViewer (F6)'
      object lbCode: TListBox
        Left = 0
        Top = 25
        Width = 637
        Height = 473
        Cursor = crIBeam
        Style = lbOwnerDrawFixed
        AutoComplete = False
        Align = alClient
        Anchors = []
        Color = clWhite
        ExtendedSelect = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        ParentShowHint = False
        PopupMenu = pmCode
        ShowHint = False
        TabOrder = 0
        OnClick = lbCodeClick
        OnDblClick = lbCodeDblClick
        OnDrawItem = lbCodeDrawItem
        OnKeyDown = lbCodeKeyDown
        OnMouseMove = lbCodeMouseMove
        ExplicitWidth = 631
        ExplicitHeight = 464
      end
      object CodePanel: TPanel
        Left = 0
        Top = 0
        Width = 745
        Height = 25
        Align = alTop
        PopupMenu = pmCodePanel
        TabOrder = 1
        ExplicitWidth = 739
        object lProcName: TLabel
          Left = 126
          Top = 6
          Width = 59
          Height = 13
          Caption = 'ProcName'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object bEP: TButton
          Left = 2
          Top = 2
          Width = 22
          Height = 22
          Hint = 'Go to Program Entry Point'
          Caption = 'EP'
          Enabled = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = bEPClick
        end
        object bCodePrev: TButton
          Left = 24
          Top = 2
          Width = 22
          Height = 22
          Hint = 'Previous Subroutine'
          Caption = '<-'
          Enabled = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = bCodePrevClick
        end
        object ShowCXrefs: TPanel
          Left = 635
          Top = 1
          Width = 109
          Height = 23
          Align = alRight
          BevelOuter = bvLowered
          Caption = 'XRefs'
          TabOrder = 2
          OnClick = ShowCXrefsClick
          ExplicitLeft = 629
        end
        object bCodeNext: TButton
          Left = 46
          Top = 2
          Width = 23
          Height = 22
          Hint = 'Next Subroutine'
          Caption = '->'
          Enabled = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = bCodeNextClick
        end
        object bDecompile: TButton
          Left = 69
          Top = 2
          Width = 22
          Height = 22
          Hint = 'Push me :-)'
          Caption = 'Src'
          Enabled = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          OnClick = bDecompileClick
        end
        object cbMultipleSelection: TCheckBox
          Left = 97
          Top = 7
          Width = 13
          Height = 13
          Hint = 'Multiple Selection'
          TabOrder = 5
          Visible = False
          OnClick = cbMultipleSelectionClick
        end
      end
      object lbCXrefs: TListBox
        Left = 637
        Top = 25
        Width = 108
        Height = 473
        Style = lbOwnerDrawFixed
        Align = alRight
        Anchors = []
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 2
        OnDblClick = lbXrefsDblClick
        OnDrawItem = lbXrefsDrawItem
        OnKeyDown = lbXrefsKeyDown
        OnMouseMove = lbXrefsMouseMove
        ExplicitLeft = 631
        ExplicitHeight = 464
      end
    end
    object tsClassView: TTabSheet
      Caption = 'ClassViewer (F7)'
      ImageIndex = 1
      object tvClassesFull: TTreeView
        Left = 0
        Top = 39
        Width = 745
        Height = 459
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        HideSelection = False
        Indent = 15
        ParentFont = False
        PopupMenu = pmVMTs
        ReadOnly = True
        TabOrder = 0
        ToolTips = False
        OnClick = tvClassesFullClick
        OnDblClick = tvClassesDblClick
        OnMouseMove = tvClassesFullMouseMove
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 745
        Height = 39
        Align = alTop
        TabOrder = 1
        object rgViewerMode: TRadioGroup
          Left = 1
          Top = 1
          Width = 182
          Height = 37
          Align = alLeft
          Columns = 2
          ItemIndex = 1
          Items.Strings = (
            'Tree'
            'Branch')
          TabOrder = 0
          OnClick = rgViewerModeClick
        end
      end
      object tvClassesShort: TTreeView
        Left = 0
        Top = 39
        Width = 745
        Height = 459
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        HideSelection = False
        Indent = 18
        ParentFont = False
        PopupMenu = pmVMTs
        ReadOnly = True
        TabOrder = 2
        ToolTips = False
        OnClick = tvClassesShortClick
        OnDblClick = tvClassesDblClick
        OnKeyDown = tvClassesShortKeyDown
        OnMouseMove = tvClassesShortMouseMove
      end
    end
    object tsStrings: TTabSheet
      Caption = 'Strings (F8)'
      ImageIndex = 2
      object lbStrings: TListBox
        Left = 0
        Top = 25
        Width = 638
        Height = 477
        Style = lbOwnerDrawFixed
        AutoComplete = False
        Align = alClient
        Anchors = []
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        MultiSelect = True
        ParentFont = False
        PopupMenu = pmStrings
        TabOrder = 0
        OnClick = lbStringsClick
        OnDblClick = lbStringsDblClick
        OnDrawItem = lbStringsDrawItem
        OnMouseMove = lbStringsMouseMove
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 745
        Height = 25
        Align = alTop
        TabOrder = 1
        ExplicitWidth = 746
        object ShowSXrefs: TPanel
          Left = 636
          Top = 1
          Width = 110
          Height = 23
          Align = alRight
          BevelOuter = bvLowered
          Caption = 'XRefs'
          TabOrder = 0
          OnClick = ShowSXrefsClick
        end
      end
      object lbSXrefs: TListBox
        Left = 637
        Top = 25
        Width = 108
        Height = 473
        Style = lbOwnerDrawFixed
        Align = alRight
        Anchors = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 2
        OnDblClick = lbXrefsDblClick
        OnDrawItem = lbXrefsDrawItem
        OnKeyDown = lbXrefsKeyDown
        OnMouseMove = lbXrefsMouseMove
      end
    end
    object tsItems: TTabSheet
      Caption = 'Items'
      ImageIndex = 3
      TabVisible = False
      object sgItems: TStringGrid
        Left = 0
        Top = 0
        Width = 746
        Height = 502
        Align = alClient
        DefaultColWidth = 51
        DefaultRowHeight = 13
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        TabOrder = 0
        ColWidths = (
          51
          51
          51
          430
          17)
      end
    end
    object tsNames: TTabSheet
      Caption = 'Names (F9)'
      ImageIndex = 4
      object lbNames: TListBox
        Left = 0
        Top = 25
        Width = 638
        Height = 477
        AutoComplete = False
        Align = alClient
        Anchors = []
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 14
        ParentFont = False
        PopupMenu = pmNames
        TabOrder = 0
        OnClick = lbNamesClick
      end
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 745
        Height = 25
        Align = alTop
        TabOrder = 1
        ExplicitWidth = 746
        object ShowNXrefs: TPanel
          Left = 636
          Top = 1
          Width = 110
          Height = 23
          Align = alRight
          BevelOuter = bvLowered
          Caption = 'XRefs'
          TabOrder = 0
          OnClick = ShowSXrefsClick
        end
      end
      object lbNXrefs: TListBox
        Left = 637
        Top = 25
        Width = 108
        Height = 473
        Style = lbOwnerDrawFixed
        Align = alRight
        Anchors = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 2
        OnDblClick = lbXrefsDblClick
        OnDrawItem = lbXrefsDrawItem
        OnKeyDown = lbXrefsKeyDown
        OnMouseMove = lbXrefsMouseMove
      end
    end
    object tsSourceCode: TTabSheet
      Caption = 'SourceCode (F10)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ImageIndex = 5
      ParentFont = False
      object lbSourceCode: TListBox
        Left = 0
        Top = 0
        Width = 746
        Height = 493
        Align = alClient
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        IntegralHeight = True
        ItemHeight = 14
        ParentFont = False
        PopupMenu = pmSourceCode
        TabOrder = 0
        OnClick = lbSourceCodeClick
        OnDrawItem = lbSourceCodeDrawItem
        OnMouseMove = lbSourceCodeMouseMove
      end
    end
    object tsMap: TTabSheet
      Caption = 'Map (F11)'
      ImageIndex = 6
      object lstMap: TListBox
        Left = 0
        Top = 0
        Width = 746
        Height = 502
        Align = alClient
        ItemHeight = 13
        MultiSelect = True
        PopupMenu = pmMap
        TabOrder = 0
        OnDblClick = lstMapDblClick
      end
    end
  end
  object pcInfo: TPageControl
    Left = 0
    Top = 0
    Width = 246
    Height = 526
    ActivePage = tsUnits
    Align = alLeft
    TabOrder = 0
    OnChange = pcInfoChange
    ExplicitHeight = 517
    object tsUnits: TTabSheet
      Caption = 'Units (F2)'
      object lbUnits: TListBox
        Left = 0
        Top = 0
        Width = 238
        Height = 498
        Style = lbOwnerDrawFixed
        AutoComplete = False
        Align = alClient
        Color = clWhite
        ExtendedSelect = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        ParentShowHint = False
        PopupMenu = pmUnits
        ShowHint = False
        TabOrder = 0
        OnClick = lbUnitsClick
        OnDblClick = lbUnitsDblClick
        OnDrawItem = lbUnitsDrawItem
        OnKeyDown = lbUnitsKeyDown
        OnMouseMove = lbUnitsMouseMove
        ExplicitHeight = 489
      end
    end
    object tsRTTIs: TTabSheet
      Caption = 'Types (F4)'
      ImageIndex = 1
      object lbRTTIs: TListBox
        Left = 0
        Top = 0
        Width = 240
        Height = 502
        AutoComplete = False
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 14
        ParentFont = False
        PopupMenu = pmRTTIs
        TabOrder = 0
        OnClick = lbRTTIsClick
        OnDblClick = lbRTTIsDblClick
        OnKeyDown = lbRTTIsKeyDown
        OnMouseMove = lbRTTIsMouseMove
      end
    end
    object tsForms: TTabSheet
      Caption = 'Forms (F5)'
      ImageIndex = 3
      object Splitter1: TSplitter
        Left = 0
        Top = 326
        Width = 238
        Height = 4
        Cursor = crVSplit
        Align = alBottom
        Color = clGray
        MinSize = 3
        ParentColor = False
        ExplicitTop = 330
        ExplicitWidth = 240
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 238
        Height = 39
        Align = alTop
        TabOrder = 0
        object rgViewFormAs: TRadioGroup
          Left = 1
          Top = 1
          Width = 236
          Height = 37
          Align = alClient
          Columns = 2
          ItemIndex = 0
          Items.Strings = (
            'Text'
            'Form')
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
        end
      end
      object lbForms: TListBox
        Left = 0
        Top = 39
        Width = 238
        Height = 287
        AutoComplete = False
        Align = alClient
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 14
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 1
        OnClick = lbFormsClick
        OnDblClick = lbFormsDblClick
        OnKeyDown = lbFormsKeyDown
        OnMouseMove = lbFormsMouseMove
      end
      object Panel4: TPanel
        Left = 0
        Top = 330
        Width = 238
        Height = 168
        Align = alBottom
        TabOrder = 2
        ExplicitTop = 334
        ExplicitWidth = 240
        object lbAliases: TListBox
          Left = 1
          Top = 1
          Width = 238
          Height = 74
          Align = alClient
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Style = []
          ItemHeight = 14
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          Sorted = True
          TabOrder = 0
          OnDblClick = lbAliasesDblClick
        end
        object pnlAliases: TPanel
          Left = 1
          Top = 76
          Width = 236
          Height = 91
          Align = alBottom
          TabOrder = 1
          Visible = False
          ExplicitTop = 75
          ExplicitWidth = 238
          object lClassName: TLabel
            Left = 7
            Top = 5
            Width = 35
            Height = 15
            Caption = 'Type='
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
          end
          object cbAliases: TComboBox
            Left = 8
            Top = 30
            Width = 198
            Height = 25
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            Sorted = True
            TabOrder = 0
          end
          object bApplyAlias: TButton
            Left = 52
            Top = 62
            Width = 51
            Height = 24
            Caption = 'OK'
            Default = True
            TabOrder = 1
            OnClick = bApplyAliasClick
          end
          object bCancelAlias: TButton
            Left = 142
            Top = 62
            Width = 51
            Height = 24
            Cancel = True
            Caption = 'Cancel'
            TabOrder = 2
            OnClick = bCancelAliasClick
          end
        end
      end
    end
  end
  object lbUnitItems: TListBox
    Left = 0
    Top = 530
    Width = 1002
    Height = 144
    TabStop = False
    Style = lbOwnerDrawFixed
    AutoComplete = False
    Align = alBottom
    Color = clWhite
    ExtendedSelect = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Courier New'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    PopupMenu = pmUnitItems
    TabOrder = 2
    OnClick = lbUnitItemsClick
    OnDblClick = lbUnitItemsDblClick
    OnDrawItem = lbUnitItemsDrawItem
    OnKeyDown = lbUnitItemsKeyDown
    OnMouseMove = lbUnitItemsMouseMove
    ExplicitTop = 521
    ExplicitWidth = 996
  end
  object MainMenu: TMainMenu
    AutoHotkeys = maManual
    Left = 632
    Top = 96
    object miFile: TMenuItem
      Caption = '&File'
      object miLoadFile: TMenuItem
        Caption = 'Load File'
        object miAutodetectVersion: TMenuItem
          Caption = 'Autodetect Version'
          OnClick = miAutodetectVersionClick
        end
        object miDelphi2: TMenuItem
          Caption = 'Delphi2'
          Enabled = False
          OnClick = miDelphi2Click
        end
        object miDelphi3: TMenuItem
          Caption = 'Delphi3'
          Enabled = False
          OnClick = miDelphi3Click
        end
        object miDelphi4: TMenuItem
          Caption = 'Delphi4'
          Enabled = False
          OnClick = miDelphi4Click
        end
        object miDelphi5: TMenuItem
          Caption = 'Delphi5'
          Enabled = False
          OnClick = miDelphi5Click
        end
        object miDelphi6: TMenuItem
          Caption = 'Delphi6'
          Enabled = False
          OnClick = miDelphi6Click
        end
        object miDelphi7: TMenuItem
          Caption = 'Delphi7'
          Enabled = False
          OnClick = miDelphi7Click
        end
        object miDelphi2005: TMenuItem
          Caption = 'Delphi2005'
          Enabled = False
          OnClick = miDelphi2005Click
        end
        object miDelphi2006: TMenuItem
          Caption = 'Delphi2006'
          Enabled = False
          OnClick = miDelphi2006Click
        end
        object miDelphi2007: TMenuItem
          Caption = 'Delphi2007'
          Enabled = False
          OnClick = miDelphi2007Click
        end
        object miDelphi2009: TMenuItem
          Caption = 'Delphi2009'
          Enabled = False
          OnClick = miDelphi2009Click
        end
        object miDelphi2010: TMenuItem
          Caption = 'Delphi2010'
          Enabled = False
          OnClick = miDelphi2010Click
        end
        object miDelphiXE1: TMenuItem
          Caption = 'DelphiXE1'
          Enabled = False
          OnClick = miDelphiXE1Click
        end
        object miDelphiXE2: TMenuItem
          Caption = 'DelphiXE2'
          Enabled = False
          OnClick = miDelphiXE2Click
        end
        object miDelphiXE3: TMenuItem
          Caption = 'DelphiXE3'
          Enabled = False
          OnClick = miDelphiXE3Click
        end
        object miDelphiXE4: TMenuItem
          Caption = 'DelphiXE4'
          Enabled = False
          OnClick = miDelphiXE4Click
        end
      end
      object miOpenProject: TMenuItem
        Caption = 'Open Project'
        OnClick = miOpenProjectClick
      end
      object miMRF: TMenuItem
        Caption = 'Recent Files'
        object miExe1: TMenuItem
          Visible = False
          OnClick = miExe1Click
        end
        object miExe2: TMenuItem
          Visible = False
          OnClick = miExe2Click
        end
        object miExe3: TMenuItem
          Visible = False
          OnClick = miExe3Click
        end
        object miExe4: TMenuItem
          Visible = False
          OnClick = miExe4Click
        end
        object miExe5: TMenuItem
          Visible = False
          OnClick = miExe5Click
        end
        object miExe6: TMenuItem
          Visible = False
          OnClick = miExe6Click
        end
        object miExe7: TMenuItem
          Visible = False
          OnClick = miExe7Click
        end
        object miExe8: TMenuItem
          Visible = False
          OnClick = miExe8Click
        end
        object N1: TMenuItem
          Caption = '-'
        end
        object miIdp1: TMenuItem
          Visible = False
          OnClick = miIdp1Click
        end
        object miIdp2: TMenuItem
          Visible = False
          OnClick = miIdp2Click
        end
        object miIdp3: TMenuItem
          Visible = False
          OnClick = miIdp3Click
        end
        object miIdp4: TMenuItem
          Visible = False
          OnClick = miIdp4Click
        end
        object miIdp5: TMenuItem
          Visible = False
          OnClick = miIdp5Click
        end
        object miIdp6: TMenuItem
          Visible = False
          OnClick = miIdp6Click
        end
        object miIdp7: TMenuItem
          Visible = False
          OnClick = miIdp7Click
        end
        object miIdp8: TMenuItem
          Visible = False
          OnClick = miIdp8Click
        end
      end
      object miSaveProject: TMenuItem
        Caption = 'Save Project'
        OnClick = miSaveProjectClick
      end
      object miSaveDelphiProject: TMenuItem
        Caption = 'Save Delphi Project'
        OnClick = miSaveDelphiProjectClick
      end
      object miExit: TMenuItem
        Caption = 'E&xit'
        OnClick = miExitClick
      end
    end
    object miTools: TMenuItem
      Caption = 'Too&ls'
      object miProcessDumper: TMenuItem
        Caption = 'Process &Dumper'
        OnClick = miProcessDumperClick
      end
      object miMapGenerator: TMenuItem
        Caption = '&MAP Generator'
        OnClick = miMapGeneratorClick
      end
      object miCommentsGenerator: TMenuItem
        Caption = '&Comments Generator'
        OnClick = miCommentsGeneratorClick
      end
      object miIDCGenerator: TMenuItem
        Caption = '&IDC Generator'
        OnClick = miIDCGeneratorClick
      end
      object miHiewGenerator: TMenuItem
        Caption = 'HIEW Generator'
        OnClick = miHiewGeneratorClick
      end
      object miLister: TMenuItem
        Caption = 'Lister'
        OnClick = miListerClick
      end
      object miClassTreeBuilder: TMenuItem
        Caption = 'Class Tree &Builder'
        OnClick = miClassTreeBuilderClick
      end
      object miKBTypeInfo: TMenuItem
        Caption = 'KB TypeInfo &Viewer'
        OnClick = miKBTypeInfoClick
      end
      object miCtdPassword: TMenuItem
        Caption = 'Citadel Password &Finder'
        OnClick = miCtdPasswordClick
      end
      object miHex2Double: TMenuItem
        Caption = '&Hex->Double'
        OnClick = miHex2DoubleClick
      end
    end
    object miTabs: TMenuItem
      Caption = '&Tabs'
      object Units1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Units'
        ShortCut = 113
        OnClick = Units1Click
      end
      object RTTI1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Types'
        ShortCut = 115
        OnClick = RTTI1Click
      end
      object Forms1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Forms'
        ShortCut = 116
        OnClick = Forms1Click
      end
      object CodeViewer1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Code Viewer'
        ShortCut = 117
        OnClick = CodeViewer1Click
      end
      object ClassViewer1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Class Viewer'
        ShortCut = 118
        OnClick = ClassViewer1Click
      end
      object Strings1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Strings'
        ShortCut = 119
        OnClick = Strings1Click
      end
      object Names1: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Names'
        ShortCut = 120
        OnClick = Names1Click
      end
      object SourceCode1: TMenuItem
        Caption = 'SourceCode'
        ShortCut = 121
        OnClick = SourceCode1Click
      end
      object mniMap1: TMenuItem
        Caption = 'Map'
        ShortCut = 122
        OnClick = mniMap1Click
      end
    end
    object miPlugins: TMenuItem
      Caption = 'Plu&gins'
      OnClick = miPluginsClick
    end
    object miInformation: TMenuItem
      Caption = '&Program'
      object miAbout: TMenuItem
        AutoHotkeys = maManual
        Caption = '&About...'
        OnClick = miAboutClick
      end
      object miHelp: TMenuItem
        AutoHotkeys = maManual
        Caption = 'Help'
        ShortCut = 112
        OnClick = miHelpClick
      end
      object miLegend: TMenuItem
        Caption = 'Legend'
        OnClick = miLegendClick
      end
      object miSettings: TMenuItem
        Caption = 'Settings'
        object miacFontAll: TMenuItem
          Action = acFontAll
          Caption = 'Fonts'
        end
        object mniShellIntegration1: TMenuItem
          Caption = 'Shell Integration'
          OnClick = mniShellIntegration1Click
        end
      end
    end
  end
  object OpenDlg: TOpenDialog
    Left = 696
    Top = 96
  end
  object pmCode: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmCodePopup
    Left = 344
    Top = 96
    object miGoTo: TMenuItem
      Caption = 'GoTo Address'
      Enabled = False
      OnClick = miGoToClick
    end
    object miExploreAdr: TMenuItem
      Caption = 'Explore Address'
      Enabled = False
      OnClick = miExploreAdrClick
    end
    object miName: TMenuItem
      Caption = 'Name Position'
      Enabled = False
      OnClick = miNameClick
    end
    object miViewProto: TMenuItem
      Caption = 'View Prototype'
      Enabled = False
      OnClick = miViewProtoClick
    end
    object miEditFunctionC: TMenuItem
      Caption = 'Edit Prototype'
      Enabled = False
      OnClick = miEditFunctionCClick
    end
    object mniN3: TMenuItem
      Caption = '-'
    end
    object miCopyAddressCode: TMenuItem
      Caption = 'Copy Address'
      OnClick = miCopyAddressCodeClick
    end
    object miCopyCode: TMenuItem
      Caption = 'Copy to Clipboard'
      OnClick = miCopyCodeClick
    end
    object mniN4: TMenuItem
      Caption = '-'
    end
    object miFuzzyScanKB: TMenuItem
      Caption = 'Fuzzy scan KB'
      Enabled = False
      OnClick = miFuzzyScanKBClick
    end
    object miXRefs: TMenuItem
      Caption = 'XRefs'
      Enabled = False
    end
    object miSwitchFlag: TMenuItem
      Caption = 'Switch flag'
      Enabled = False
      object miSwitchSkipFlag: TMenuItem
        Caption = 'cfSkip'
        OnClick = miSwitchSkipFlagClick
      end
      object miSwitchFrameFlag: TMenuItem
        Caption = 'cfFrame'
        OnClick = miSwitchFrameFlagClick
      end
      object cfTry1: TMenuItem
        Caption = 'cfTry'
        OnClick = cfTry1Click
      end
    end
  end
  object SaveDlg: TSaveDialog
    Left = 736
    Top = 96
  end
  object pmUnits: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmUnitsPopup
    Left = 24
    Top = 96
    object miRenameUnit: TMenuItem
      Caption = 'Rename Unit'
      Enabled = False
      OnClick = miRenameUnitClick
    end
    object miSearchUnit: TMenuItem
      Caption = 'Search Unit'
      Enabled = False
      OnClick = miSearchUnitClick
    end
    object miSortUnits: TMenuItem
      Caption = 'Sort Units by'
      Enabled = False
      object miSortUnitsByAdr: TMenuItem
        Caption = 'Address'
        Checked = True
        OnClick = miSortUnitsByAdrClick
      end
      object miSortUnitsByOrd: TMenuItem
        Caption = 'Initialization Order'
        OnClick = miSortUnitsByOrdClick
      end
      object miSortUnitsByNam: TMenuItem
        Caption = 'Name'
        OnClick = miSortUnitsByNamClick
      end
    end
    object miUnitDumper: TMenuItem
      Caption = 'Unit Dumper'
      Enabled = False
      Visible = False
      OnClick = miUnitDumperClick
    end
    object miCopyList: TMenuItem
      Caption = 'Save Units List'
      Enabled = False
      OnClick = miCopyListClick
    end
  end
  object pmRTTIs: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmRTTIsPopup
    Left = 64
    Top = 96
    object miSearchRTTI: TMenuItem
      Caption = 'Search Type'
      Enabled = False
      OnClick = miSearchRTTIClick
    end
    object miSortRTTI: TMenuItem
      Caption = 'Sort Types by'
      Enabled = False
      object miSortRTTIsByAdr: TMenuItem
        Caption = 'Address'
        Checked = True
        OnClick = miSortRTTIsByAdrClick
      end
      object miSortRTTIsByKnd: TMenuItem
        Caption = 'Type Kind'
        OnClick = miSortRTTIsByKndClick
      end
      object miSortRTTIsByNam: TMenuItem
        Caption = 'Name'
        OnClick = miSortRTTIsByNamClick
      end
    end
    object Appearance2: TMenuItem
      Caption = 'Appearance'
      object Showbar2: TMenuItem
        Action = acShowBar
      end
      object Showhorizontalscroll2: TMenuItem
        Action = acShowHoriz
      end
      object Defaultcolumns2: TMenuItem
        Action = acDefCol
      end
      object Fontthis2: TMenuItem
        Caption = 'Font (this)'
      end
      object Fontall2: TMenuItem
        Action = acFontAll
      end
      object Colorsthis2: TMenuItem
        Action = acColorThis
      end
      object Colorsall2: TMenuItem
        Action = acColorAll
      end
    end
  end
  object pmVMTs: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmVMTsPopup
    Left = 384
    Top = 96
    object miViewClass: TMenuItem
      Caption = 'View Class'
      Enabled = False
      OnClick = miViewClassClick
    end
    object miSearchVMT: TMenuItem
      Caption = 'Search'
      Enabled = False
      OnClick = miSearchVMTClick
    end
    object miCollapseAll: TMenuItem
      Caption = 'Collapse All'
      Enabled = False
      OnClick = miCollapseAllClick
    end
    object miEditClass: TMenuItem
      Caption = 'Edit'
      Enabled = False
      OnClick = miEditClassClick
    end
  end
  object pmUnitItems: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmUnitItemsPopup
    Left = 544
    Top = 96
    object miSearchItem: TMenuItem
      Caption = 'Search Item'
      Enabled = False
      OnClick = miSearchItemClick
    end
    object miEditFunctionI: TMenuItem
      Caption = 'Edit Prototype'
      Enabled = False
      OnClick = miEditFunctionIClick
    end
    object miCopyAddressI: TMenuItem
      Caption = 'Copy Address'
      Enabled = False
      OnClick = miCopyAddressIClick
    end
    object miViewAll: TMenuItem
      Caption = 'View All'
      Enabled = False
      OnClick = miViewAllClick
    end
  end
  object pmStrings: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmStringsPopup
    Left = 424
    Top = 96
    object miSearchString: TMenuItem
      Caption = 'Search'
      OnClick = miSearchStringClick
    end
    object mniCopyLinesStrings1: TMenuItem
      Caption = 'Copy Lines'
      OnClick = mniCopyLinesStrings1Click
    end
    object miCopyStrings: TMenuItem
      Caption = 'Copy To Clipboard'
      OnClick = miCopyStringsClick
    end
  end
  object pmCodePanel: TPopupMenu
    AutoHotkeys = maManual
    OnPopup = pmCodePanelPopup
    Left = 664
    Top = 96
    object miEmptyHistory: TMenuItem
      Caption = 'Empty History'
      OnClick = miEmptyHistoryClick
    end
  end
  object alMain: TActionList
    Left = 816
    Top = 96
    object acOnTop: TAction
      Category = 'Appearance'
      Caption = 'Always on top'
    end
    object acShowBar: TAction
      Category = 'Appearance'
      Caption = 'Show bar'
    end
    object acShowHoriz: TAction
      Category = 'Appearance'
      Caption = 'Show horizontal scroll'
    end
    object acDefCol: TAction
      Category = 'Appearance'
      Caption = 'Default columns'
    end
    object acColorThis: TAction
      Category = 'Appearance'
      Caption = 'Colors (this)'
    end
    object acFontAll: TAction
      Category = 'Appearance'
      Caption = 'Font (all)'
      OnExecute = acFontAllExecute
    end
    object acColorAll: TAction
      Category = 'Appearance'
      Caption = 'Colors (all)'
    end
  end
  object FontsDlg: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Left = 776
    Top = 96
  end
  object pmSourceCode: TPopupMenu
    OnPopup = pmSourceCodePopup
    Left = 504
    Top = 96
    object miCopySource2Clipboard: TMenuItem
      Caption = 'Copy to Clipboard'
      OnClick = miCopySource2ClipboardClick
    end
    object miSetlvartype: TMenuItem
      Caption = 'Set lvar type'
      OnClick = miSetlvartypeClick
    end
  end
  object pmNames: TPopupMenu
    Left = 464
    Top = 96
    object miCopytoClipboardNames: TMenuItem
      Caption = 'Copy to Clipboard'
      OnClick = miCopytoClipboardNamesClick
    end
  end
  object pmMap: TPopupMenu
    AutoHotkeys = maManual
    Left = 584
    Top = 96
    object mniCopyLines: TMenuItem
      Caption = 'Copy Lines'
      OnClick = mniCopyLinesClick
    end
    object mniCopyAllToClipboard: TMenuItem
      Caption = 'Copy All To Clipboard'
      OnClick = mniCopyAllToClipboardClick
    end
  end
end
