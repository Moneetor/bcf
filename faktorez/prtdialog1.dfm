object PrintMassDialog: TPrintMassDialog
  Left = 480
  Top = 445
  Width = 356
  Height = 121
  Caption = 'Masowe drukowanie'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ok1: TBitBtn
    Left = 72
    Top = 48
    Width = 91
    Height = 33
    TabOrder = 0
    Kind = bkOK
  end
  object can1: TBitBtn
    Left = 184
    Top = 48
    Width = 89
    Height = 33
    Caption = 'Anuluj'
    TabOrder = 1
    Kind = bkCancel
  end
  object div1: TCheckBox
    Left = 16
    Top = 16
    Width = 169
    Height = 17
    Caption = 'Najpierw wszystkie orygina³y'
    TabOrder = 2
  end
end
