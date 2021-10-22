object NewField: TNewField
  Left = 450
  Top = 469
  Width = 359
  Height = 115
  Caption = 'NewField'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object fn1: TEdit
    Left = 16
    Top = 16
    Width = 321
    Height = 21
    TabOrder = 0
    OnChange = fn1Change
  end
  object ok1: TBitBtn
    Left = 80
    Top = 48
    Width = 75
    Height = 25
    TabOrder = 1
    Kind = bkOK
  end
  object can1: TBitBtn
    Left = 192
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Anuluj'
    TabOrder = 2
    Kind = bkCancel
  end
end
