object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 281
  ClientWidth = 605
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 8
    Top = 8
    Width = 242
    Height = 265
    Indent = 19
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 256
    Top = 8
    Width = 122
    Height = 236
    Lines.Strings = (
      '')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 567
    Top = 268
    Width = 48
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 384
    Top = 188
    Width = 65
    Height = 25
    Caption = 'Add'
    TabOrder = 3
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 384
    Top = 8
    Width = 214
    Height = 169
    ColCount = 3
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 1000
    TabOrder = 4
  end
  object Button2: TButton
    Left = 455
    Top = 188
    Width = 65
    Height = 25
    Caption = 'Clear'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 526
    Top = 188
    Width = 65
    Height = 25
    Caption = 'Del tree'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 384
    Top = 219
    Width = 207
    Height = 25
    Caption = 'Remove the max in left branch'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Edit2: TEdit
    Left = 541
    Top = 252
    Width = 82
    Height = 21
    TabOrder = 8
  end
  object Button5: TButton
    Left = 256
    Top = 250
    Width = 122
    Height = 25
    Caption = 'Print'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 384
    Top = 250
    Width = 65
    Height = 25
    Caption = 'Remove'
    TabOrder = 10
    OnClick = Button6Click
  end
  object Edit3: TEdit
    Left = 455
    Top = 252
    Width = 48
    Height = 21
    TabOrder = 11
  end
end
