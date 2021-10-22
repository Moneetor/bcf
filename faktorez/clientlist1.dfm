object ClientList: TClientList
  Left = 289
  Top = 290
  Width = 670
  Height = 382
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Lista Klientów'
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
  object Splitter1: TSplitter
    Left = 337
    Top = 0
    Width = 3
    Height = 355
    Cursor = crHSplit
    Beveled = True
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 337
    Height = 355
    Align = alLeft
    Caption = 'Panel1'
    TabOrder = 0
    object Panel11: TPanel
      Left = 1
      Top = 1
      Width = 335
      Height = 306
      Align = alClient
      Caption = 'Panel11'
      TabOrder = 0
      object ListBox1: TListBox
        Left = 1
        Top = 1
        Width = 333
        Height = 304
        Align = alClient
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox1Click
        OnDblClick = edit1Click
      end
    end
    object Panel12: TPanel
      Left = 1
      Top = 307
      Width = 335
      Height = 47
      Align = alBottom
      TabOrder = 1
      object add1: TBitBtn
        Left = 8
        Top = 8
        Width = 89
        Height = 29
        Caption = 'Dodaj'
        TabOrder = 0
      end
      object edit1: TBitBtn
        Left = 160
        Top = 8
        Width = 73
        Height = 29
        Caption = 'Zmieñ'
        TabOrder = 1
        OnClick = edit1Click
      end
      object del1: TBitBtn
        Left = 240
        Top = 8
        Width = 81
        Height = 29
        Caption = 'Usuñ'
        TabOrder = 2
      end
    end
  end
  object Panel2: TPanel
    Left = 340
    Top = 0
    Width = 322
    Height = 355
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 320
      Height = 353
      Align = alClient
      Color = clBtnFace
      Lines.Strings = (
        'Memo1')
      ReadOnly = True
      TabOrder = 0
    end
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 217
    Top = 89
  end
  object Query1: TQuery
    AfterOpen = Query1AfterOpen
    AfterClose = Query1AfterClose
    DatabaseName = 'TENNET2'
    SessionName = 'Default'
    SQL.Strings = (
      'SELECT id_k,symbol FROM prt_klient'
      'ORDER BY symbol;')
    Left = 217
    Top = 129
    object Query1id_k: TIntegerField
      FieldName = 'id_k'
      Origin = 'TENNET2.prt_klient.id_k'
    end
    object Query1symbol: TStringField
      FieldName = 'symbol'
      Origin = 'TENNET2.prt_klient.symbol'
    end
  end
  object Query2: TQuery
    AfterOpen = Query2AfterOpen
    DatabaseName = 'TENNET2'
    SessionName = 'Default'
    SQL.Strings = (
      
        'SELECT symbol,nazwisko,ulica,nr_domu1,nr_domu2,lokal1,lokal2,zip' +
        ',miasto,NIP,REGON'
      'FROM prt_klient kl'
      'JOIN prt_adresy adr'
      'ON adr.id_umow=kl.adres'
      'JOIN miasta m'
      'ON m.id_m=adr.city'
      'WHERE id_k=1;')
    Left = 257
    Top = 129
    object Query2symbol: TStringField
      FieldName = 'symbol'
    end
    object Query2nazwisko: TMemoField
      FieldName = 'nazwisko'
      BlobType = ftMemo
      Size = 1
    end
    object Query2ulica: TStringField
      FieldName = 'ulica'
      Size = 35
    end
    object Query2nr_domu1: TSmallintField
      FieldName = 'nr_domu1'
    end
    object Query2nr_domu2: TStringField
      FieldName = 'nr_domu2'
      FixedChar = True
      Size = 1
    end
    object Query2lokal1: TSmallintField
      FieldName = 'lokal1'
    end
    object Query2lokal2: TStringField
      FieldName = 'lokal2'
      FixedChar = True
      Size = 1
    end
    object Query2zip: TStringField
      FieldName = 'zip'
      Size = 6
    end
    object Query2miasto: TStringField
      FieldName = 'miasto'
      Size = 100
    end
    object Query2NIP: TStringField
      FieldName = 'NIP'
      Size = 13
    end
    object Query2REGON: TStringField
      FieldName = 'REGON'
      Size = 9
    end
  end
  object DataSource2: TDataSource
    DataSet = Query2
    Left = 257
    Top = 89
  end
  object Query3: TQuery
    DatabaseName = 'TENNET2'
    SessionName = 'Default'
    SQL.Strings = (
      'DELETE FROM prt_client'
      'WHERE id_k=1;')
    Left = 297
    Top = 129
  end
end
