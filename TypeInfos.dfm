object FTypeInfo_11011981: TFTypeInfo_11011981
  Left = 267
  Top = 331
  ClientHeight = 388
  ClientWidth = 682
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 120
  TextHeight = 16
  object memDescription: TMemo
    Left = 0
    Top = 0
    Width = 682
    Height = 348
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitWidth = 842
    ExplicitHeight = 447
  end
  object Panel1: TPanel
    Left = 0
    Top = 348
    Width = 682
    Height = 40
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    TabOrder = 1
    Visible = False
    ExplicitTop = 447
    ExplicitWidth = 842
    object bSave: TButton
      Left = 309
      Top = 9
      Width = 75
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Save'
      TabOrder = 0
      OnClick = bSaveClick
    end
  end
end