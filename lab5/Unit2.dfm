object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 287
  ClientWidth = 254
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 121
    Height = 269
    ItemHeight = 13
    TabOrder = 0
  end
  object randome: TButton
    Left = 154
    Top = 35
    Width = 95
    Height = 25
    Caption = 'randome'
    TabOrder = 1
    OnClick = randomeClick
  end
  object Edit1: TEdit
    Left = 154
    Top = 8
    Width = 95
    Height = 21
    TabOrder = 2
    Text = '100'
  end
  object Edit2: TEdit
    Left = 154
    Top = 72
    Width = 23
    Height = 21
    TabOrder = 3
  end
  object Button1: TButton
    Left = 154
    Top = 99
    Width = 95
    Height = 25
    Caption = 'add'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 183
    Top = 72
    Width = 66
    Height = 21
    TabOrder = 5
  end
  object Button2: TButton
    Left = 154
    Top = 137
    Width = 95
    Height = 25
    Caption = 'remove negative'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 154
    Top = 176
    Width = 92
    Height = 25
    Caption = 'get tail'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Edit4: TEdit
    Left = 154
    Top = 207
    Width = 92
    Height = 21
    TabOrder = 8
  end
  object Button4: TButton
    Left = 154
    Top = 244
    Width = 55
    Height = 25
    Caption = 'show tail'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Edit5: TEdit
    Left = 215
    Top = 246
    Width = 31
    Height = 21
    TabOrder = 10
  end
end
