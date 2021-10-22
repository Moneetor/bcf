//---------------------------------------------------------------------------

#ifndef clientdataH
#define clientdataH
//---------------------------------------------------------------------------
#include "faktordata1.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>

using namespace std;
#include <vector>

//---------------------------------------------------------------------------
class TClientData1 : public TForm
{
__published:	// IDE-managed Components
    TQuery *Query1;
    TDataSource *DataSource1;
    TDataSource *DataSource2;
    TGroupBox *GroupBox1;
    TDBMemo *name1;
    TDBEdit *sym1;
    TGroupBox *GroupBox2;
    TButton *add1;
    TButton *edit1;
    TButton *del1;
    TGroupBox *GroupBox3;
    TQuery *Query2;
    TMaskEdit *NIP1;
    TLabel *NIP1l;
    TEdit *REGON1;
    TLabel *REGON1l;
    TBitBtn *ok1;
    TBitBtn *can1;
    TLabel *Label1;
    TLabel *Label2;
    TQuery *Query3;
    TDataSource *DataSource3;
    TListBox *adr1;
    TStringField *Query1symbol;
    TMemoField *Query1nazwisko;
    TIntegerField *Query1adres;
    TStringField *Query1NIP;
    TStringField *Query1REGON;
    TIntegerField *Query2id_umow;
    TStringField *Query2miasto;
    TStringField *Query2ulica;
    TSmallintField *Query2nr_domu1;
    TStringField *Query2nr_domu2;
    TSmallintField *Query2lokal1;
    TStringField *Query2lokal2;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Query2AfterClose(TDataSet *DataSet);
    void __fastcall Query2AfterOpen(TDataSet *DataSet);
    void __fastcall Query1AfterClose(TDataSet *DataSet);
    void __fastcall Query1AfterOpen(TDataSet *DataSet);
    void __fastcall can1Click(TObject *Sender);
    void __fastcall ok1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall sym1Change(TObject *Sender);
private:	// User declarations
    vector<int> ids;
public:		// User declarations
    TFaktorzData FaktorzData;
    bool Insert;
    int RecordPos;
    bool Edited;
    __fastcall TClientData1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClientData1 *ClientData1;
//---------------------------------------------------------------------------
#endif
