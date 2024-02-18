object FActiveProcesses: TFActiveProcesses
  Left = 390
  Top = 440
  BorderStyle = bsSingle
  Caption = 'Active Processes'
  ClientHeight = 382
  ClientWidth = 975
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object btnDump: TButton
    Left = 210
    Top = 352
    Width = 76
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Dump'
    TabOrder = 1
    OnClick = btnDumpClick
  end
  object btnCancel: TButton
    Left = 690
    Top = 352
    Width = 76
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnCancelClick
  end
  object lvProcesses: TListView
    Left = 0
    Top = 0
    Width = 975
    Height = 345
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    Columns = <
      item
        Caption = 'PID'
        Width = 80
      end
      item
        Caption = 'Name'
        Width = 400
      end
      item
        Caption = 'Image Size'
        Width = 150
      end
      item
        Caption = 'EP'
        Width = 150
      end
      item
        Caption = 'Base'
        Width = 150
      end>
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    RowSelect = True
    ParentFont = False
    TabOrder = 0
    ViewStyle = vsReport
    OnClick = lvProcessesClick
  end
end
