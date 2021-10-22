//---------------------------------------------------------------------------

#ifndef faktorH
#define faktorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include <printers.hpp>
#include "masprinter1.h"

#include "faktordata1.h"
#include "scale.h"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <AppEvnts.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFaktorez : public TForm
{
__published:	// IDE-managed Components
    TPrinterSetupDialog *PrinterSetupDialog1;
    TPrintDialog *PrintDialog1;
    TImage *Image1;
    TMainMenu *MainMenu1;
    TMenuItem *Plik1;
    TMenuItem *Konfiguracja1;
    TMenuItem *Drukuj1;
    TMenuItem *Koniec1;
    TMenuItem *Nowafaktura1;
    TMenuItem *Opcje1;
    TMenuItem *Ustawieniawydruku1;
    TMenuItem *Widok1;
    TMenuItem *Skala1;
    TMenuItem *N16001;
    TMenuItem *N8001;
    TMenuItem *N4001;
    TMenuItem *N2001;
    TMenuItem *N1001;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N751;
    TMenuItem *N501;
    TMenuItem *N251;
    TMenuItem *N1251;
    TMenuItem *N6251;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *Powiksz1;
    TMenuItem *Pomniejsz1;
    TToolBar *ToolBar1;
    TToolButton *zoom1;
    TToolButton *zoom2;
    TToolButton *zoom3;
    TImageList *ImageList1;
    TMenuItem *N5;
    TTimer *Timer1;
    TDatabase *Database1;
    TDataSource *DataSource1;
    TQuery *Query1;
    TDataSource *DataSource2;
    TQuery *Query2;
    TDataSource *DataSource3;
    TQuery *Query3;
    TToolButton *print1;
    TToolButton *print1s;
    TToolButton *ToolButton3;
    TStatusBar *StatusBar1;
    TToolButton *conn1;
    TMenuItem *Kartoteki1;
    TMenuItem *Klienci1;
    TStringField *Query2nazwa_art;
    TIntegerField *Query2id_fakt;
    TIntegerField *Query2id_a;
    TStringField *Query2PKWIU;
    TFloatField *Query2qty;
    TFloatField *Query2rabat;
    TFloatField *Query2price;
    TFloatField *Query2VATP;
    TStringField *Query2jm;
    TIntegerField *Query1id_fakt;
    TStringField *Query1faktura;
    TDateTimeField *Query1data_sprz;
    TDateTimeField *Query1data_wyst;
    TSmallintField *Query1number;
    TStringField *Query1ext;
    TBooleanField *Query1printed;
    TBooleanField *Query1to_print;
    TIntegerField *Query1klient;
    TBooleanField *Query1print_copy;
    TBooleanField *Query1print_master;
    TDateTimeField *Query1data_zapl;
    TIntegerField *Query1id_k;
    TStringField *Query1symbol;
    TStringField *Query1nazwisko;
    TIntegerField *Query1adres;
    TStringField *Query1NIP;
    TStringField *Query1REGON;
    TIntegerField *Query1id_umow;
    TStringField *Query1ulica;
    TSmallintField *Query1nr_domu1;
    TStringField *Query1nr_domu2;
    TSmallintField *Query1lokal1;
    TStringField *Query1lokal2;
    TStringField *Query1zip;
    TSmallintField *Query1city;
    TIntegerField *Query1id_m;
    TStringField *Query1miasto;
    TToolButton *add1;
    TToolButton *FV1;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *edit1;
    TDataSource *DataSource4;
    TQuery *Query4;
    TIntegerField *Query4num_kp;
    TStringField *Query4tyt;
    TStringField *Query4nazwisko;
    TStringField *Query4adres;
    TStringField *Query4kod;
    TSmallintField *Query4miasto;
    TFloatField *Query4kwota;
    TDateField *Query4data1;
    TToolButton *KP1;
    void __fastcall Konfiguracja1Click(TObject *Sender);
    void __fastcall Koniec1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Ustawieniawydruku1Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall zoom1Click(TObject *Sender);
    void __fastcall zoom2Click(TObject *Sender);
    void __fastcall zoom3Click(TObject *Sender);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall N1001Click(TObject *Sender);
    void __fastcall Drukuj1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall StatusBar1Resize(TObject *Sender);
    void __fastcall StatusBar1DrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
    void __fastcall add1Click(TObject *Sender);
    void __fastcall edit1Click(TObject *Sender);
private:	// User declarations
    Graphics::TBitmap *brief;
    Graphics::TBitmap *brief2;
    double XScale;
    double YScale;
    TScale Scale;
    TPoint DrawPos;
    TPoint LastPos;
    TPoint ClickPos;
    bool FirstRun;
    int StartKP;
    int EndKP;
    void __fastcall DrawBrief(void);
    void __fastcall SetDrawFont(TCanvas * Canvas, int num,bool paper);
    void MassPrint(void);
public:		// User declarations
    TIniFile *IniFile;
    TFaktorzData FaktorzData;
    TPrinter *Printer1;
    int Mode;
    TMassPrinter *MassPrinter;
    __fastcall TFaktorez(TComponent* Owner);
    void __fastcall PrintCopy(TPrinter * Printer, bool copy);
    void __fastcall TextRect(TCanvas * Canvas, TRect Rect, int Y, AnsiString Text,TAlignment Alignment);
    void __fastcall DrawScale(void);
    void SetDatabase(void);
    bool TestDatabase(void);
    TDocumentData Faktura;
    void __fastcall OnStopPrint(TObject * Sender);
    void __fastcall ItemsRect(TCanvas * Canvas, TRect &Rect, int Y, AnsiString Text, TAlignment Alignment,TDocumentData DocumentData);
    void __fastcall TaxesRect(TCanvas * Canvas, TRect & Rect, int Y, TAlignment Alignment, TDocumentData DocumentData);
    void PrintKP(int start, int end);
};
//---------------------------------------------------------------------------
extern PACKAGE TFaktorez *Faktorez;
//---------------------------------------------------------------------------
#endif
