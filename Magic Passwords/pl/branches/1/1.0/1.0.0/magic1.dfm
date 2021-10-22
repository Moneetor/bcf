object MagicPassword: TMagicPassword
  Left = 357
  Top = 347
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MagicPassword v 1.0.0'
  ClientHeight = 312
  ClientWidth = 655
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010000001002000680400001600000028000000100000002000
    0000010020000000000000000000000000000000000000000000000000000000
    0000000000004B183426501A367B4C1C327D4C1D327D4C1D337D4C1D337D4C1D
    337D4C1D347D4C1D347D4C1E347D4E1E367F280C1B4801000011000000000000
    000000000000823260FFDC2DBAFFE01BB7FFE019B4FFE017B1FFE014ADFFE013
    A8FFE010A5FFE00EA2FFE00C9DFFDC0B97FF83225AFF0000001B000000000000
    000000000000A33F82FFFF1AE3FFFF1BDDFFFF18D7FFFF17D3FFFF14CEFFFF10
    CAFFFF0EC4FFFF0ABFFFFF09BAFFFF05B6FFA61A73FF0000001B000000000000
    000000000000A24083FFFF18DCFFFF1FE2FFFF1CDEFFFF1AD8FFFF17D3FFFF14
    CFFFFF11CBFFFF0EC8FFFF0DC1FFFF09BFFFA51B75FF0000001B000000000000
    000000000000A24286FFFF20ECFFFF23E9FFFF23EAFFFF24E7FFFF23E7FFFF22
    E6FFFF1FE0FFFF13CEFFFF11C8FFFF0DC6FFA51D78FF0000001B000000000000
    000000000000AA4490FFFF29F9FFFF2DF7FFFF2DF7FFFF2DF7FFFF2DF7FFFF2D
    F7FFFF2DF7FFFF2CF6FFFF19D7FFFF11CCFFAC1E81FF0000001B000000000000
    000000000000BE46A6FFF831FFFFF734FFFFF734FFFFF734FFFFF734FFFFF734
    FFFFF734FFFFF734FFFFF735FFFFFF1EE1FFC12195FF0000001B000000000000
    000000000000D050B8FFEB66FFFFE857FFFFE857FFFFE857FFFFE857FFFFE857
    FFFFE857FFFFE857FFFFE857FFFFED58FFFFD235B2FF00000011000000000000
    000000000000CE23A279CC48B1E5E370CFFFD465BFFFD54CBDD5E04EC6CAE04E
    C7CAE34DC9C7CD5FB7FFE16DCDFFC648ABEBC021978100000000000000000000
    000000000000000000003F6E3A7BEDF1EFFFA2B3A1FF001F0038000000000000
    00000000000081967FFFE1E4E3FF32582F9B0000000400000000000000000000
    0000000000000000000051704A7FFBF9FCFFAEB8ACFF15201240000000010000
    000000000000889785FFEBE9ECFF425B3D9E0000000600000000000000000000
    000000000000000000005C7A566FF4F6F4FFC2CAC1FF35463171000000140D10
    0D04445A402E9AA598FFEEEFEDFF4B63478B0000000300000000000000000000
    000000000000000000006A846421C2CDC0FFF7F6F7FE99AA96F74B5F48894E62
    4A7A889B85F1E4E3E4FEC0CABEFF3C4B393B0000000000000000000000000000
    0000000000000000000000000000829A7DA2F4F6F3FFF9F8F9FEDDE1DCFFD6D9
    D5FFF0EFF1FEF1F3F0FF768C72B0000000000000000000000000000000000000
    00000000000000000000849C8000000000008DA38899CBD5C9FFEFF2EEFFEFF1
    EEFFC6D1C4FF869B82AA00000000000000000000000000000000000000000000
    00000000000000000000000000000000000000000000859E800E869F8156859E
    805676887216000000000000000000000000000000000000000000000000FFFF
    0000C0030000C0030000C0030000C0030000C0030000C0030000C0030000E003
    0000F3C70000F3C70000F3C70000F08F0000F00F0000F81F0000FFFF0000}
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object pass1l: TLabel
    Left = 16
    Top = 16
    Width = 59
    Height = 13
    Caption = 'Twoje has³o'
  end
  object pass2l: TLabel
    Left = 16
    Top = 72
    Width = 93
    Height = 13
    Caption = 'Zakodowane has³o'
  end
  object big1l: TLabel
    Left = 16
    Top = 120
    Width = 117
    Height = 13
    Caption = 'Iloœæ du¿ych liter w haœle'
  end
  object loo1l: TLabel
    Left = 16
    Top = 168
    Width = 55
    Height = 13
    Caption = 'Iloœæ iteracji'
  end
  object len1l: TLabel
    Left = 16
    Top = 216
    Width = 71
    Height = 13
    Caption = 'D³ugoœæ has³a'
  end
  object pass1ed: TEdit
    Left = 16
    Top = 32
    Width = 625
    Height = 21
    TabOrder = 0
    OnChange = big1trChange
  end
  object pass2ed: TEdit
    Left = 16
    Top = 88
    Width = 625
    Height = 21
    Enabled = False
    TabOrder = 1
  end
  object big1tr: TTrackBar
    Left = 16
    Top = 136
    Width = 561
    Height = 25
    Max = 32
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 2
    ThumbLength = 10
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = big1trChange
  end
  object big1ed: TEdit
    Left = 576
    Top = 136
    Width = 49
    Height = 21
    TabOrder = 3
    Text = '0'
    OnChange = big1edChange
  end
  object big1ud: TUpDown
    Left = 625
    Top = 136
    Width = 12
    Height = 21
    Associate = big1ed
    Min = 0
    Max = 32
    Position = 0
    TabOrder = 4
    Wrap = False
  end
  object loo1tr: TTrackBar
    Left = 16
    Top = 184
    Width = 561
    Height = 25
    Max = 1000
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 1
    SelEnd = 0
    SelStart = 0
    TabOrder = 5
    ThumbLength = 10
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = loo1trChange
  end
  object loo1ed: TEdit
    Left = 576
    Top = 184
    Width = 49
    Height = 21
    TabOrder = 6
    Text = '1'
    OnChange = loo1edChange
  end
  object loo1ud: TUpDown
    Left = 625
    Top = 184
    Width = 12
    Height = 21
    Associate = loo1ed
    Min = 1
    Max = 1000
    Position = 1
    TabOrder = 7
    Wrap = False
  end
  object copy1: TBitBtn
    Left = 240
    Top = 272
    Width = 121
    Height = 33
    Caption = 'Kopiuj do schowka'
    TabOrder = 8
    OnClick = copy1Click
  end
  object inf1: TBitBtn
    Left = 544
    Top = 272
    Width = 99
    Height = 33
    Caption = '&O programie'
    TabOrder = 9
    OnClick = inf1Click
    Kind = bkHelp
  end
  object len1tr: TTrackBar
    Left = 16
    Top = 232
    Width = 561
    Height = 25
    Max = 32
    Min = 6
    Orientation = trHorizontal
    Frequency = 1
    Position = 32
    SelEnd = 0
    SelStart = 0
    TabOrder = 10
    ThumbLength = 10
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = len1trChange
  end
  object len1ed: TEdit
    Left = 576
    Top = 232
    Width = 49
    Height = 21
    TabOrder = 11
    Text = '32'
    OnChange = len1edChange
  end
  object len1ud: TUpDown
    Left = 625
    Top = 232
    Width = 12
    Height = 21
    Associate = len1ed
    Min = 6
    Max = 32
    Position = 32
    TabOrder = 12
    Wrap = False
  end
end
