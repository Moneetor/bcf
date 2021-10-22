object Config: TConfig
  Left = 287
  Top = 218
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Konfiguracja programu'
  ClientHeight = 414
  ClientWidth = 511
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Pages1: TPageControl
    Left = 0
    Top = 0
    Width = 511
    Height = 353
    ActivePage = sell1
    Align = alTop
    TabOrder = 0
    object pap1: TTabSheet
      Caption = 'Paper'
      object marg1: TGroupBox
        Left = 8
        Top = 16
        Width = 489
        Height = 177
        Caption = 'Marginesy w mm'
        TabOrder = 0
        object marg101l: TLabel
          Left = 40
          Top = 32
          Width = 25
          Height = 13
          Caption = 'Lewy'
        end
        object marg103l: TLabel
          Left = 40
          Top = 96
          Width = 29
          Height = 13
          Caption = 'Prawy'
        end
        object marg102l: TLabel
          Left = 280
          Top = 32
          Width = 28
          Height = 13
          Caption = 'Górny'
        end
        object marg104l: TLabel
          Left = 280
          Top = 96
          Width = 27
          Height = 13
          Caption = 'Dolny'
        end
        object marg101ed: TEdit
          Left = 40
          Top = 48
          Width = 129
          Height = 21
          ReadOnly = True
          TabOrder = 0
          Text = '10'
          OnChange = marg101edChange
        end
        object marg103ed: TEdit
          Left = 40
          Top = 112
          Width = 129
          Height = 21
          ReadOnly = True
          TabOrder = 1
          Text = '10'
          OnChange = marg103edChange
        end
        object marg102ed: TEdit
          Left = 280
          Top = 48
          Width = 145
          Height = 21
          ReadOnly = True
          TabOrder = 2
          Text = '10'
          OnChange = marg102edChange
        end
        object marg104ed: TEdit
          Left = 280
          Top = 112
          Width = 145
          Height = 21
          ReadOnly = True
          TabOrder = 3
          Text = '10'
          OnChange = marg104edChange
        end
        object marg101: TUpDown
          Left = 169
          Top = 48
          Width = 15
          Height = 21
          Associate = marg101ed
          Min = 1
          Position = 10
          TabOrder = 4
          Wrap = False
        end
        object marg103: TUpDown
          Left = 169
          Top = 112
          Width = 15
          Height = 21
          Associate = marg103ed
          Min = 1
          Position = 10
          TabOrder = 5
          Wrap = False
        end
        object marg102: TUpDown
          Left = 425
          Top = 48
          Width = 15
          Height = 21
          Associate = marg102ed
          Min = 1
          Position = 10
          TabOrder = 6
          Wrap = False
        end
        object marg104: TUpDown
          Left = 425
          Top = 112
          Width = 15
          Height = 21
          Associate = marg104ed
          Min = 1
          Position = 10
          TabOrder = 7
          Wrap = False
        end
      end
      object font1: TGroupBox
        Left = 8
        Top = 208
        Width = 489
        Height = 105
        Caption = 'Wielkoœæ czcionki'
        TabOrder = 1
        object font101l: TLabel
          Left = 40
          Top = 32
          Width = 95
          Height = 13
          Caption = 'Czcionka nag³ówka'
        end
        object font102l: TLabel
          Left = 296
          Top = 32
          Width = 79
          Height = 13
          Caption = 'Czcionka ogólna'
        end
        object font101: TComboBox
          Left = 40
          Top = 48
          Width = 145
          Height = 21
          ItemHeight = 0
          TabOrder = 0
          Text = 'Wybierz wielkoœæ czcionki'
          OnChange = font101Change
        end
        object font102: TComboBox
          Left = 296
          Top = 48
          Width = 145
          Height = 21
          ItemHeight = 0
          TabOrder = 1
          Text = 'Wybierz wielkoœæ czcionki'
          OnChange = font102Change
        end
      end
    end
    object bank1: TTabSheet
      Caption = 'Bank'
      ImageIndex = 1
      object bank101l: TLabel
        Left = 32
        Top = 56
        Width = 25
        Height = 13
        Caption = 'Bank'
      end
      object bank102l: TLabel
        Left = 32
        Top = 208
        Width = 61
        Height = 13
        Caption = 'Numer konta'
      end
      object bank101ed: TEdit
        Left = 32
        Top = 72
        Width = 441
        Height = 21
        TabOrder = 0
        OnChange = bank101edChange
      end
      object bank102ed: TMaskEdit
        Left = 32
        Top = 224
        Width = 441
        Height = 21
        EditMask = '99 9999 9999 9999 9999 9999 9999;1;_'
        MaxLength = 32
        TabOrder = 1
        Text = '                                '
        OnChange = bank102edChange
      end
    end
    object sell1: TTabSheet
      Caption = 'Sprzedawca'
      ImageIndex = 2
      object NIP1l: TLabel
        Left = 8
        Top = 272
        Width = 18
        Height = 13
        Caption = 'NIP'
      end
      object zip1l: TLabel
        Left = 8
        Top = 224
        Width = 67
        Height = 13
        Caption = 'Kod pocztowy'
      end
      object city1l: TLabel
        Left = 280
        Top = 224
        Width = 31
        Height = 13
        Caption = 'Miasto'
      end
      object sell102l: TLabel
        Left = 8
        Top = 96
        Width = 86
        Height = 13
        Caption = 'Adres sprzedawcy'
      end
      object sell101l: TLabel
        Left = 8
        Top = 8
        Width = 92
        Height = 13
        Caption = 'Nazwa sprzedawcy'
      end
      object REGON1l: TLabel
        Left = 280
        Top = 272
        Width = 39
        Height = 13
        Caption = 'REGON'
      end
      object sell101m: TMemo
        Left = 8
        Top = 24
        Width = 481
        Height = 65
        TabOrder = 0
        OnChange = sell101mChange
      end
      object sell102m: TMemo
        Left = 8
        Top = 112
        Width = 481
        Height = 97
        TabOrder = 1
        OnChange = sell102mChange
      end
      object city1: TEdit
        Left = 280
        Top = 240
        Width = 209
        Height = 21
        TabOrder = 2
        OnChange = city1Change
      end
      object REGON1: TEdit
        Left = 280
        Top = 288
        Width = 209
        Height = 21
        TabOrder = 3
        OnChange = REGON1Change
      end
      object zip1: TMaskEdit
        Left = 8
        Top = 240
        Width = 209
        Height = 21
        EditMask = '99-999;1;_'
        MaxLength = 6
        TabOrder = 4
        Text = '15-157'
        OnChange = zip1Change
      end
      object NIP1: TMaskEdit
        Left = 8
        Top = 288
        Width = 209
        Height = 21
        EditMask = '999-999-99-99;1;_'
        MaxLength = 13
        TabOrder = 5
        Text = '   -   -  -  '
        OnChange = NIP1Change
      end
    end
    object logo1: TTabSheet
      Caption = 'Logos'
      ImageIndex = 3
      object logo101l: TLabel
        Left = 24
        Top = 192
        Width = 162
        Height = 13
        Caption = 'Œcie¿ka dostêpu pliku graficznego'
      end
      object Bevel1: TBevel
        Left = 24
        Top = 16
        Width = 313
        Height = 137
      end
      object logo101: TImage
        Left = 24
        Top = 16
        Width = 313
        Height = 137
        Stretch = True
      end
      object logo101ed: TEdit
        Left = 24
        Top = 208
        Width = 393
        Height = 21
        Color = clBtnFace
        ReadOnly = True
        TabOrder = 0
      end
      object logo101b: TButton
        Left = 416
        Top = 208
        Width = 73
        Height = 21
        Caption = 'Przegl¹daj'
        TabOrder = 1
        OnClick = logo101bClick
      end
    end
    object num1: TTabSheet
      Caption = 'Numeracja'
      ImageIndex = 4
      object num101ed: TEdit
        Left = 32
        Top = 152
        Width = 433
        Height = 21
        TabOrder = 0
        Text = '1'
        OnChange = num101edChange
      end
      object num101: TUpDown
        Left = 465
        Top = 152
        Width = 15
        Height = 21
        Associate = num101ed
        Min = 1
        Max = 32000
        Position = 1
        TabOrder = 1
        Wrap = False
      end
    end
    object fdat1: TTabSheet
      Caption = 'Rozk³ad pól'
      ImageIndex = 5
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 241
        Height = 325
        Align = alLeft
        Caption = 'Panel1'
        TabOrder = 0
        object fimg1: TImage
          Left = 1
          Top = 1
          Width = 239
          Height = 323
          Align = alClient
          OnMouseDown = fimg1MouseDown
          OnMouseMove = fimg1MouseMove
        end
      end
      object Panel2: TPanel
        Left = 241
        Top = 0
        Width = 262
        Height = 325
        Align = alClient
        Caption = 'Panel2'
        TabOrder = 1
        object Panel3: TPanel
          Left = 1
          Top = 1
          Width = 260
          Height = 152
          Align = alTop
          Caption = 'Panel3'
          TabOrder = 0
          object fl1: TListBox
            Left = 1
            Top = 1
            Width = 258
            Height = 150
            Align = alClient
            ItemHeight = 13
            PopupMenu = pop1
            TabOrder = 0
            OnClick = fl1Click
          end
        end
        object Panel4: TPanel
          Left = 1
          Top = 153
          Width = 260
          Height = 171
          Hint = 'Lewa krawêdŸ'
          Align = alClient
          Alignment = taLeftJustify
          TabOrder = 1
          object al101: TSpeedButton
            Left = 16
            Top = 8
            Width = 23
            Height = 22
            GroupIndex = 1
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
              0000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
              0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
              0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000FFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
              0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            OnClick = al101Click
          end
          object al102: TSpeedButton
            Left = 40
            Top = 8
            Width = 23
            Height = 22
            GroupIndex = 1
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
              0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
              0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000
              0000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            OnClick = al102Click
          end
          object al103: TSpeedButton
            Left = 64
            Top = 8
            Width = 23
            Height = 22
            GroupIndex = 1
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
              0000000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
              0000000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFF000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFF000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            OnClick = al103Click
          end
          object b1: TSpeedButton
            Left = 112
            Top = 8
            Width = 23
            Height = 22
            AllowAllUp = True
            GroupIndex = 2
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            OnClick = b1Click
          end
          object h1: TSpeedButton
            Left = 144
            Top = 8
            Width = 23
            Height = 22
            AllowAllUp = True
            GroupIndex = 3
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000
              0000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
              FFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            OnClick = h1Click
          end
          object vis1: TSpeedButton
            Left = 176
            Top = 8
            Width = 23
            Height = 22
            AllowAllUp = True
            GroupIndex = 4
            Glyph.Data = {
              36030000424D3603000000000000360000002800000010000000100000000100
              18000000000000030000130B0000130B00000000000000000000FEFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFAFDFFF2F8FCEAF3F9D6E7F4BED5EFB8CDEAB5C6E4B6C5
              E2B5C5E3C3C8E5C6CBE7FFFFFFFFFFFFFFFFFFFCFEFFF6FAFEEFF3FBDEE9F6C6
              D6F0B5C6E9A4B5E39EB1E09CB1DC8FA4D993A8D68FA8D6A0AFD9FFFFFFFFFFFF
              FEFEFFF8F8FEE7EAF8D2D8ECCED6EFC6C8E5B6BCDE9EABDC93A2D68D9CD67589
              CE738BCB7B91CE839AD0FCFCFFFEFCFFFFFEFFFFFCFDFCF8F9E5E0E9D2D3DEE3
              E0E2DFDCDFCACDD8B3BCD0A8AFCB95A2CD8B98CB8595CD8396CEF9F9FCF5F5F9
              F1F1F6FAF6F9F9F3F1BAB1AD9187759687679C8969918973899395A4AFBCA0AA
              B89EAABEA4AFC88998C3ECEFF8F9F8FCFFFFFEFFFFFCA8A2879CA0739AA07985
              916D858D699CAA877F8F7767736FA2A8ADA0A2AD9698AA8B95ADFFFFFFFFFFFF
              FFFFFFDFD5B69E91618DA88F605C3E3B392842412B69816D89A68F757D6B838F
              939AA0AAA4A8B1A8ABB6FFFFFFFFFFFFFFFFFE9C96739AA483716946211C1515
              100F12100E322B1D9C9C719C9C77737F799AA6ADA2AAABA8ABB6FFFFFFFFFFFF
              FFFFFA8B8D69B8BE9CD3C3A01F181216120E12110C211C1387895CA2A277797D
              6FADB1B1ABAFAFB3B5BCFFFFFFFFFFFFFFFFFFA8A47BE2D9B5FFFFFF5E462F13
              110C11100C302F2083917389937181897FAFB1AFA4A4A68995ABFFFFFCFFFFFF
              FFFFFFF7E7C38F855CF5F0C8635C4036332B3E3D2C6F7D61758569818567969A
              9891939A7185A0678BBAADBEDFFAF5EFFFFFFEFFFFFDDEBE8F7F7F6160857552
              79775A7D7363877B676D5C777D7D7D879E61759C5E7BB15C73AFBEC6D69EADCE
              B3BAD3EAE8EAFAF1E8CBB3A071655E545252505658525E6963718F5E759E6577
              9A7181AD616FAB505EA0FFFFFFFEFCFADEE2E8A6AFCA8D9CC18393BF7789B66B
              7FB37581AF7581A87D8BAB818BB58189B56F7DAB5E6B9E404D7FE3EBF7FEFCFD
              FFFFFEFFFEFAFEFBF8F3F0EEF0EBEAD8D8DCD3CED5C6C6D2ABABC59A96BC7F89
              AD606D93526183697D9ED0E5F9B3CDF0ABBFE7BEC6E7C8D2E9DEDBE9D9D6E8CE
              CBDEB1ADCB8183B1616796525A8B495A89526993698DB381A8CA}
            OnClick = vis1Click
          end
          object size1: TGroupBox
            Left = 16
            Top = 40
            Width = 233
            Height = 121
            Caption = 'Wymiary w mm'
            TabOrder = 0
            object Label1: TLabel
              Left = 8
              Top = 16
              Width = 8
              Height = 13
              Hint = 'Górna krawêdŸ'
              Caption = 'G'
              ParentShowHint = False
              ShowHint = True
            end
            object Label2: TLabel
              Left = 8
              Top = 40
              Width = 6
              Height = 13
              Hint = 'Lewa krawêdŸ'
              Caption = 'L'
              ParentShowHint = False
              ShowHint = True
            end
            object Label3: TLabel
              Left = 8
              Top = 64
              Width = 7
              Height = 13
              Hint = 'Szerokoœæ'
              Caption = 'S'
              ParentShowHint = False
              ShowHint = True
            end
            object Label4: TLabel
              Left = 8
              Top = 88
              Width = 11
              Height = 13
              Hint = 'Wysokoœæ'
              Caption = 'W'
              ParentShowHint = False
              ShowHint = True
            end
            object size101ed: TEdit
              Left = 24
              Top = 16
              Width = 73
              Height = 21
              Hint = 'Górna krawêdŸ'
              ParentShowHint = False
              ShowHint = True
              TabOrder = 0
              Text = '0'
            end
            object size102ed: TEdit
              Left = 24
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Lewa krawêdŸ'
              ParentShowHint = False
              ShowHint = True
              TabOrder = 1
              Text = '0'
            end
            object size103ed: TEdit
              Left = 24
              Top = 64
              Width = 73
              Height = 21
              Hint = 'Szerokoœæ'
              ParentShowHint = False
              ShowHint = True
              TabOrder = 2
              Text = '1'
            end
            object size104ed: TEdit
              Left = 24
              Top = 88
              Width = 73
              Height = 21
              Hint = 'Wysokoœæ'
              ParentShowHint = False
              ShowHint = True
              TabOrder = 3
              Text = '1'
            end
            object size10301: TCheckBox
              Left = 120
              Top = 24
              Width = 105
              Height = 17
              Caption = 'Ust. poz.pozioma.'
              TabOrder = 4
              OnClick = size10301Click
            end
            object size10401: TCheckBox
              Left = 120
              Top = 48
              Width = 105
              Height = 17
              Caption = 'Ust. poz pionowa'
              TabOrder = 5
              OnClick = size10401Click
            end
            object size101: TUpDown
              Left = 97
              Top = 16
              Width = 16
              Height = 21
              Hint = 'Górna krawêdŸ'
              Associate = size101ed
              Min = 0
              ParentShowHint = False
              Position = 0
              ShowHint = True
              TabOrder = 6
              Wrap = False
            end
            object size102: TUpDown
              Left = 97
              Top = 40
              Width = 15
              Height = 21
              Hint = 'Lewa krawêdŸ'
              Associate = size102ed
              Min = 0
              ParentShowHint = False
              Position = 0
              ShowHint = True
              TabOrder = 7
              Wrap = False
            end
            object size103: TUpDown
              Left = 97
              Top = 64
              Width = 15
              Height = 21
              Hint = 'Szerokoœæ'
              Associate = size103ed
              Min = 1
              ParentShowHint = False
              Position = 1
              ShowHint = True
              TabOrder = 8
              Wrap = False
            end
            object size104: TUpDown
              Left = 97
              Top = 88
              Width = 15
              Height = 21
              Hint = 'Wysokoœæ'
              Associate = size104ed
              Min = 1
              ParentShowHint = False
              Position = 1
              ShowHint = True
              TabOrder = 9
              Wrap = False
            end
          end
        end
      end
    end
    object dbas1: TTabSheet
      Caption = 'Baza danych'
      ImageIndex = 6
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 503
        Height = 89
        Align = alTop
        Caption = 'Panel5'
        TabOrder = 0
        object dsn1: TListBox
          Left = 8
          Top = 8
          Width = 369
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          OnClick = dsn1Click
        end
        object find1: TButton
          Left = 384
          Top = 8
          Width = 113
          Height = 33
          Hint = 'Znajduje Ÿród³a baz danych'
          Caption = 'ZnajdŸ'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = find1Click
        end
        object del1: TButton
          Left = 384
          Top = 48
          Width = 113
          Height = 33
          Hint = 'Usuwa z listy Ÿróde³ danych'
          Caption = 'Usuñ'
          Enabled = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnClick = del1Click
        end
      end
      object dbp1: TPanel
        Left = 0
        Top = 89
        Width = 503
        Height = 236
        Align = alClient
        TabOrder = 1
        object eng1l: TLabel
          Left = 8
          Top = 8
          Width = 47
          Height = 13
          Caption = 'Sterownik'
        end
        object login1l: TLabel
          Left = 8
          Top = 48
          Width = 26
          Height = 13
          Caption = 'Login'
        end
        object eng1: TEdit
          Left = 8
          Top = 24
          Width = 489
          Height = 21
          Color = clBtnFace
          ReadOnly = True
          TabOrder = 0
        end
        object login1: TEdit
          Left = 8
          Top = 64
          Width = 489
          Height = 21
          TabOrder = 1
        end
        object info: TBitBtn
          Left = 8
          Top = 200
          Width = 489
          Height = 33
          Caption = 'Informacje'
          TabOrder = 2
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000130B0000130B0000000000000000000000FF0000FF00
            00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
            0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
            FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
            00FF0000FF0000FF0000FF00FF0000FF0000FF0000FF000000FF0000FF0000FF
            0000FF0000FF0000FF0000FF0000FF0000FF0000FF00FF0000FF0000FF0000FF
            FFFFFFFFFFFF0000FF0000FF000000FF0000FF0000FF0000FF0000FF0000FF00
            00FF00FF0000FF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000FF00
            0000FF0000FF0000FF0000FF0000FF0000FF00FF0000FF0000FF0000FF0000FF
            FFFFFFFFFFFF0000FF0000FF0000FF000000FF0000FF0000FF0000FF0000FF00
            FF0000FF0000FF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000FF00
            00FF000000FF0000FF0000FF0000FF00FF0000FF0000FF0000FF0000FF0000FF
            FFFFFFFFFFFF0000FF0000FF0000FF0000FF000000FF0000FF0000FF0000FF00
            FF0000FF0000FF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000FF00
            00FF000000FF0000FF0000FF0000FF00FF0000FF0000FF0000FF0000FF0000FF
            0000FF0000FF0000FF0000FF0000FF0000FF000000FF0000FF0000FF0000FF00
            00FF00FF0000FF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000FF00
            0000FF0000FF0000FF0000FF0000FF0000FF00FF0000FF0000FF0000FF0000FF
            FFFFFFFFFFFF0000FF0000FF0000FF000000FF0000FF0000FF0000FF0000FF00
            00FF0000FF00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF000000FF
            0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00FF0000FF
            0000FF0000FF000000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
            00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
            0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
            FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00}
        end
        object pas0: TGroupBox
          Left = 8
          Top = 96
          Width = 489
          Height = 97
          Caption = 'Has³o'
          TabOrder = 3
          object pas1l: TLabel
            Left = 120
            Top = 12
            Width = 29
            Height = 13
            Caption = 'Has³o'
          end
          object pas2l: TLabel
            Left = 120
            Top = 52
            Width = 68
            Height = 13
            Caption = 'Powtórz has³o'
          end
          object pas1: TEdit
            Left = 120
            Top = 28
            Width = 361
            Height = 21
            PasswordChar = '#'
            TabOrder = 0
            OnChange = pas1Change
          end
          object pas2: TEdit
            Left = 120
            Top = 68
            Width = 361
            Height = 21
            PasswordChar = '#'
            TabOrder = 1
            OnChange = pas1Change
          end
          object pas3: TCheckBox
            Left = 16
            Top = 24
            Width = 97
            Height = 17
            Caption = 'Zapisz has³o'
            TabOrder = 2
            OnClick = pas3Click
          end
        end
      end
    end
  end
  object BitBtn1: TBitBtn
    Left = 112
    Top = 368
    Width = 105
    Height = 33
    TabOrder = 1
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 304
    Top = 368
    Width = 113
    Height = 33
    Caption = 'Anuluj'
    TabOrder = 2
    Kind = bkCancel
  end
  object logo1d: TOpenPictureDialog
    DefaultExt = 'bmp'
    Options = [ofHideReadOnly, ofNoChangeDir, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = 'Plik graficzny na logosa'
    Left = 284
    Top = 120
  end
  object pop1: TPopupMenu
    Left = 326
    Top = 121
    object Dodajpole1: TMenuItem
      Caption = 'Dodaj pole'
      OnClick = Dodajpole1Click
    end
    object Zmienazw1: TMenuItem
      Caption = 'Zmieñ nazwê'
      OnClick = Zmienazw1Click
    end
    object Usupole1: TMenuItem
      Caption = 'Usuñ pole'
      OnClick = Usupole1Click
    end
  end
end
