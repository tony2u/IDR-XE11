object IdrDfmFormTree_11011981: TIdrDfmFormTree_11011981
  Left = 638
  Top = 371
  BorderStyle = bsSizeToolWin
  Caption = 'frmDfmTree'
  ClientHeight = 427
  ClientWidth = 315
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object tvForm: TTreeView
    Left = 0
    Top = 0
    Width = 315
    Height = 427
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Fixedsys'
    Font.Style = []
    Indent = 19
    ParentFont = False
    PopupMenu = mnuTree
    ReadOnly = True
    TabOrder = 0
    OnDblClick = tvFormDblClick
    OnKeyPress = tvFormKeyPress
  end
  object dlgFind: TFindDialog
    Options = [frDown, frDisableUpDown, frDisableWholeWord]
    OnFind = dlgFindFind
    Left = 112
    Top = 80
  end
  object mnuTree: TPopupMenu
    Left = 120
    Top = 144
    object Expand1: TMenuItem
      Caption = 'Expand'
      OnClick = Expand1Click
    end
    object Collapse1: TMenuItem
      Caption = 'Collapse'
      OnClick = Collapse1Click
    end
    object Find1: TMenuItem
      Caption = 'Find'
      OnClick = Find1Click
    end
  end
end
