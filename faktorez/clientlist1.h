//---------------------------------------------------------------------------

#ifndef clientlist1H
#define clientlist1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBTables.hpp>

using namespace std;
#include <vector>

//---------------------------------------------------------------------------
class TClientList : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TSplitter *Splitter1;
    TPanel *Panel2;
    TPanel *Panel11;
    TListBox *ListBox1;
    TMemo *Memo1;
    TPanel *Panel12;
    TBitBtn *add1;
    TBitBtn *edit1;
    TBitBtn *del1;
    TDataSource *DataSource1;
    TQuery *Query1;
    TIntegerField *Query1id_k;
    TStringField *Query1symbol;
    TQuery *Query2;
    TDataSource *DataSource2;
    TQuery *Query3;
    TStringField *Query2symbol;
    TMemoField *Query2nazwisko;
    TStringField *Query2ulica;
    TSmallintField *Query2nr_domu1;
    TStringField *Query2nr_domu2;
    TSmallintField *Query2lokal1;
    TStringField *Query2lokal2;
    TStringField *Query2zip;
    TStringField *Query2miasto;
    TStringField *Query2NIP;
    TStringField *Query2REGON;
    void __fastcall Query1AfterOpen(TDataSet *DataSet);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall Query1AfterClose(TDataSet *DataSet);
    void __fastcall Query2AfterOpen(TDataSet *DataSet);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall edit1Click(TObject *Sender);
private:	// User declarations
    vector<int> klienci;
public:		// User declarations
    __fastcall TClientList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClientList *ClientList;
//---------------------------------------------------------------------------
#endif
