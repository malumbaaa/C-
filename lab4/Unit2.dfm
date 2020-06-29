object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 109
  ClientWidth = 450
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 135
    Top = 27
    Width = 8
    Height = 13
    Caption = '='
  end
  object Label2: TLabel
    Left = 276
    Top = 27
    Width = 8
    Height = 13
    Caption = '='
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '(a+b)*(c-d)/e'
  end
  object Edit2: TEdit
    Left = 149
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 290
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 336
    Top = 51
    Width = 75
    Height = 25
    Caption = 'press'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit4: TEdit
    Left = 8
    Top = 51
    Width = 33
    Height = 21
    TabOrder = 4
    Text = '0,8'
  end
  object Edit5: TEdit
    Left = 48
    Top = 51
    Width = 33
    Height = 21
    TabOrder = 5
    Text = '4,1'
  end
  object Edit6: TEdit
    Left = 88
    Top = 51
    Width = 33
    Height = 21
    TabOrder = 6
    Text = '7,9'
  end
  object Edit7: TEdit
    Left = 128
    Top = 51
    Width = 33
    Height = 21
    TabOrder = 7
    Text = '6,2'
  end
  object Edit8: TEdit
    Left = 168
    Top = 51
    Width = 34
    Height = 21
    TabOrder = 8
    Text = '3,5'
  end
end
