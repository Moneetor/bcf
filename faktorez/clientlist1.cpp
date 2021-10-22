//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clientlist1.h"
#include "faktor.h"
#include "clientdata.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientList *ClientList;
//---------------------------------------------------------------------------
__fastcall TClientList::TClientList(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TClientList::Query1AfterOpen(TDataSet *DataSet)
{
int i,c,pos;
AnsiString tbuf1;
    ListBox1->Clear();
    klienci.clear();
    c=Query1->RecordCount;
    klienci.resize(c);
    for (i=0;i<c ;i++)
    {
        pos=Query1->FieldByName("id_k")->Value;
        klienci[i]=pos;
        tbuf1=Query1->FieldByName("symbol")->Text;
        ListBox1->Items->Add(tbuf1);
        Query1->Next();
    }
    Query1->First();
}
//---------------------------------------------------------------------------

void __fastcall TClientList::ListBox1Click(TObject *Sender)
{
int i,c;
int buf;
AnsiString tbuf1;
    Memo1->Clear();
    if (klienci.empty())
        return;
    c=klienci.size();
    i=ListBox1->ItemIndex;
    if ((c<0)||(i>=c))
        return;
    buf=klienci[i];
    tbuf1="WHERE id_k="+IntToStr(buf)+";";
    Query2->SQL->Strings[6]=tbuf1;
    Query2->Open();
}
//---------------------------------------------------------------------------

void __fastcall TClientList::Query1AfterClose(TDataSet *DataSet)
{
    ListBox1->Clear();
    klienci.clear();
}
//---------------------------------------------------------------------------



void __fastcall TClientList::Query2AfterOpen(TDataSet *DataSet)
{
TStringList *nazwa=new TStringList;
AnsiString tbuf1,tbuf2;
    TMemoryStream *mem1;
    TStream *strm1;
    TMemoField *blob1;
    tbuf1="Dane klienta:";
    Memo1->Lines->Add(tbuf1);
    Memo1->Lines->Add("");
    tbuf1="Nazwisko/nazwa:";
    Memo1->Lines->Add(tbuf1);
    mem1=new TMemoryStream();
    strm1=dynamic_cast<TStream *>(mem1);
    blob1=dynamic_cast<TMemoField *>(Query2->FieldByName("nazwisko"));
    blob1->SaveToStream(strm1);
    strm1->Seek(0,soFromBeginning);
    nazwa->LoadFromStream(strm1);
    Memo1->Lines->AddStrings(nazwa);
    //adres
    tbuf1="Adres:";
    Memo1->Lines->Add(tbuf1);
    tbuf1=Query2->FieldByName("ulica")->Text;
    tbuf2=Query2->FieldByName("nr_domu1")->Text;
    if (!tbuf2.IsEmpty())
    {
        tbuf1=tbuf1+" "+tbuf2;
        tbuf2=Query2->FieldByName("nr_domu2")->Text;
        tbuf1=tbuf1+tbuf2;
        tbuf2=Query2->FieldByName("lokal1")->Text;
        if (!tbuf2.IsEmpty())
        {
            tbuf1=tbuf1+" "+tbuf2;
            tbuf2=Query2->FieldByName("lokal2")->Text;
            tbuf1=tbuf1+tbuf2;
        }
        Memo1->Lines->Add(tbuf1);
    }
    else
    {
        Memo1->Lines->Add(tbuf1);
    }
    tbuf1=Query2->FieldByName("miasto")->Text;
    tbuf2=Query2->FieldByName("zip")->Text;
    tbuf1=tbuf1+" "+tbuf2;
    Memo1->Lines->Add(tbuf1);
    //NIP
    tbuf1="NIP:";
    Memo1->Lines->Add(tbuf1);
    tbuf1=Query2->FieldByName("NIP")->Text;
    Memo1->Lines->Add(tbuf1);
    //REGON
    tbuf1="REGON:";
    Memo1->Lines->Add(tbuf1);
    tbuf1=Query2->FieldByName("REGON")->Text;
    Memo1->Lines->Add(tbuf1);
    //sprz¹tamy ten bajzel
    delete nazwa;
    delete mem1;
}
//---------------------------------------------------------------------------

void __fastcall TClientList::FormShow(TObject *Sender)
{
    Query1->Open();    
}
//---------------------------------------------------------------------------

void __fastcall TClientList::edit1Click(TObject *Sender)
{
int i;
    i=ListBox1->ItemIndex;
    ClientData1->RecordPos=klienci[i];
    ClientData1->Insert=false;
    ClientData1->Show();
}
//---------------------------------------------------------------------------

