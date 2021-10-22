object ClientData1: TClientData1
  Left = 269
  Top = 187
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'ClientData1'
  ClientHeight = 482
  ClientWidth = 502
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 489
    Height = 145
    Caption = 'Klient'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 34
      Height = 13
      Caption = 'Symbol'
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 82
      Height = 13
      Caption = 'Nazwisko/nazwa'
    end
    object name1: TDBMemo
      Left = 104
      Top = 56
      Width = 369
      Height = 81
      DataField = 'nazwisko'
      DataSource = DataSource1
      TabOrder = 0
      OnChange = sym1Change
    end
    object sym1: TDBEdit
      Left = 104
      Top = 24
      Width = 369
      Height = 21
      DataField = 'symbol'
      DataSource = DataSource1
      TabOrder = 1
      OnChange = sym1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 160
    Width = 489
    Height = 185
    Caption = 'Adres'
    TabOrder = 1
    object add1: TButton
      Left = 8
      Top = 152
      Width = 97
      Height = 25
      Caption = '&Dodaj'
      TabOrder = 0
    end
    object edit1: TButton
      Left = 184
      Top = 152
      Width = 113
      Height = 25
      Caption = '&Zmieñ'
      TabOrder = 1
    end
    object del1: TButton
      Left = 360
      Top = 152
      Width = 121
      Height = 25
      Caption = '&Usuñ'
      TabOrder = 2
    end
    object adr1: TListBox
      Left = 8
      Top = 16
      Width = 473
      Height = 129
      ItemHeight = 13
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 352
    Width = 489
    Height = 73
    Caption = 'Pozosta³e'
    TabOrder = 2
    object NIP1l: TLabel
      Left = 8
      Top = 20
      Width = 18
      Height = 13
      Caption = 'NIP'
    end
    object REGON1l: TLabel
      Left = 256
      Top = 20
      Width = 39
      Height = 13
      Caption = 'REGON'
    end
    object NIP1: TMaskEdit
      Left = 8
      Top = 36
      Width = 209
      Height = 21
      EditMask = '999-999-99-99;1;_'
      MaxLength = 13
      TabOrder = 0
      Text = '   -   -  -  '
      OnChange = sym1Change
    end
    object REGON1: TEdit
      Left = 256
      Top = 36
      Width = 209
      Height = 21
      TabOrder = 1
    end
  end
  object ok1: TBitBtn
    Left = 152
    Top = 440
    Width = 75
    Height = 33
    Enabled = False
    TabOrder = 3
    OnClick = ok1Click
    Kind = bkOK
  end
  object can1: TBitBtn
    Left = 248
    Top = 440
    Width = 81
    Height = 33
    TabOrder = 4
    OnClick = can1Click
    Kind = bkCancel
  end
  object Query1: TQuery
    AfterOpen = Query1AfterOpen
    AfterClose = Query1AfterClose
    DatabaseName = 'TENNET2'
    SessionName = 'Default'
    RequestLive = True
    SQL.Strings = (
      'SELECT symbol, nazwisko, adres, NIP, REGON FROM prt_klient'
      'WHERE id_k=1;'
      ' ')
    Left = 208
    Top = 64
    object Query1symbol: TStringField
      FieldName = 'symbol'
      Origin = 'TENNET2.prt_klient.symbol'
    end
    object Query1nazwisko: TMemoField
      FieldName = 'nazwisko'
      Origin = 'TENNET2.prt_klient.nazwisko'
      BlobType = ftMemo
      Size = 1
    end
    object Query1adres: TIntegerField
      FieldName = 'adres'
      Origin = 'TENNET2.prt_klient.adres'
    end
    object Query1NIP: TStringField
      FieldName = 'NIP'
      Origin = 'TENNET2.prt_klient.NIP'
      Size = 13
    end
    object Query1REGON: TStringField
      FieldName = 'REGON'
      Origin = 'TENNET2.prt_klient.REGON'
      Size = 9
    end
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 208
    Top = 104
  end
  object DataSource2: TDataSource
    DataSet = Query2
    Left = 240
    Top = 104
  end
  object Query2: TQuery
    AfterOpen = Query2AfterOpen
    AfterClose = Query2AfterClose
    DatabaseName = 'TENNET2'
    SQL.Strings = (
      
        'SELECT id_umow, m.miasto, ulica, nr_domu1, nr_domu2, lokal1, lok' +
        'al2 FROM prt_adresy'
      'JOIN miasta m'
      'ON id_m=city'
      'ORDER BY m.miasto, ulica, nr_domu1, nr_domu2, lokal1, lokal2;'
      ' ')
    Left = 240
    Top = 64
    object Query2id_umow: TIntegerField
      FieldName = 'id_umow'
      Origin = 'TENNET2.prt_adresy.id_umow'
    end
    object Query2miasto: TStringField
      FieldName = 'miasto'
      Origin = 'TENNET2.miasta.miasto'
      Size = 100
    end
    object Query2ulica: TStringField
      FieldName = 'ulica'
      Origin = 'TENNET2.prt_adresy.ulica'
      Size = 35
    end
    object Query2nr_domu1: TSmallintField
      FieldName = 'nr_domu1'
      Origin = 'TENNET2.prt_adresy.nr_domu1'
    end
    object Query2nr_domu2: TStringField
      FieldName = 'nr_domu2'
      Origin = 'TENNET2.prt_adresy.nr_domu2'
      FixedChar = True
      Size = 1
    end
    object Query2lokal1: TSmallintField
      FieldName = 'lokal1'
      Origin = 'TENNET2.prt_adresy.lokal1'
    end
    object Query2lokal2: TStringField
      FieldName = 'lokal2'
      Origin = 'TENNET2.prt_adresy.lokal2'
      FixedChar = True
      Size = 1
    end
  end
  object Query3: TQuery
    DatabaseName = 'TENNET2'
    Left = 272
    Top = 64
  end
  object DataSource3: TDataSource
    DataSet = Query3
    Left = 272
    Top = 104
  end
end
