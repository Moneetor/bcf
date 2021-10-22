//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clientdata.h"
#include "faktor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientData1 *ClientData1;
//---------------------------------------------------------------------------
__fastcall TClientData1::TClientData1(TComponent* Owner)
    : TForm(Owner)
{
    
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::FormShow(TObject *Sender)
{
AnsiString tbuf1;
    tbuf1=IntToStr(RecordPos);
    Query2->Open();
    if (Insert)
    {
        Query1->Open();
        Query1->Append();
    }
    else
    {
        Query1->SQL->Strings[1]="WHERE id_k="+tbuf1+";";
        Query1->Open();
    }
}
//---------------------------------------------------------------------------


void __fastcall TClientData1::Query2AfterClose(TDataSet *DataSet)
{
    adr1->Clear();
    ids.clear();
}
//---------------------------------------------------------------------------


void __fastcall TClientData1::Query2AfterOpen(TDataSet *DataSet)
{
int i,c;
int buf1;
AnsiString tbuf1,tbuf2;
    adr1->Clear();
    ids.clear();
    c=Query2->RecordCount;
    ids.resize(c);
    for (i=0;i<c ;i++)
    {
        ids[i]=Query2->FieldByName("id_umow")->Value;
        tbuf1=Query2->FieldByName("miasto")->Text;
        tbuf2=Query2->FieldByName("ulica")->Text;
        tbuf1=tbuf1+", "+tbuf2;
        tbuf2=Query2->FieldByName("nr_domu1")->Text;
        tbuf1=tbuf1+" "+tbuf2;
        tbuf2=Query2->FieldByName("nr_domu2")->Text;
        tbuf1=tbuf1+tbuf2;
        if (!Query2->FieldByName("lokal1")->IsNull)
        {
            tbuf2=Query2->FieldByName("lokal1")->Text;
            tbuf1=tbuf1+" "+tbuf2;
            tbuf2=Query2->FieldByName("lokal2")->Text;
            tbuf1=tbuf1+tbuf2;
        }
        adr1->Items->Add(tbuf1);
        Query2->Next();
    }
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::Query1AfterClose(TDataSet *DataSet)
{
    NIP1->Clear();
    REGON1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::Query1AfterOpen(TDataSet *DataSet)
{
int i,c;
int buf;
    NIP1->Text=Query1->FieldByName("NIP")->Text;
    REGON1->Text=Query1->FieldByName("REGON")->Text;
    buf=Query1->FieldByName("adres")->Value;
    c=ids.size();
    for (i=0;i<c ;i++)
    {
        if (ids[i]==buf)
            break;
    }
    if (i<c)
        adr1->ItemIndex=i;
    else
        adr1->ItemIndex= -1;
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::can1Click(TObject *Sender)
{
    Query3->SQL->Clear();
    Query3->SQL->Add("ROLLBACK;");
    Query3->ExecSQL();
    can1->Enabled=false;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::ok1Click(TObject *Sender)
{
AnsiString tbuf1,tbuf2;
int i,c;
    if (Insert)
    {
        Query3->SQL->Clear();
        tbuf1="INSERT INTO prt_klient(symbol,nazwisko,adres,NIP,REGON)";
        Query3->SQL->Add(tbuf1);
        tbuf1="VALUES(";
        Query3->SQL->Add(tbuf1);
        tbuf1="'"+sym1->Text+"',";
        Query3->SQL->Add(tbuf1);
        //nazwa lub nazwisko
        tbuf1="'";
        c=name1->Lines->Count;
        for (i=0;i<c ;i++)
        {
            if (i)
                tbuf1=tbuf1+"\\n";
            tbuf2=name1->Lines->Strings[i];
            tbuf1=tbuf1+tbuf2;
        }
        tbuf1=tbuf1+"',";
        Query3->SQL->Add(tbuf1);
        //adres
        i=adr1->ItemIndex;
        tbuf2=IntToStr(ids[i]);
        tbuf1=tbuf2+",";
        Query3->SQL->Add(tbuf1);
        //NIP
        tbuf2=NIP1->Text;
        tbuf1="'"+tbuf2+"',";
        Query3->SQL->Add(tbuf1);
        //REGON
        tbuf2=REGON1->Text;
        tbuf1="'"+tbuf2+"');";
        Query3->SQL->Add(tbuf1);
    }
    else
    {
        Query3->SQL->Clear();
        tbuf1="UPDATE prt_klient";
        Query3->SQL->Add(tbuf1);
        tbuf1="SET symbol=";
        Query3->SQL->Add(tbuf1);
        tbuf1="'"+sym1->Text+"',";
        Query3->SQL->Add(tbuf1);
        //nazwa lub nazwisko
        tbuf1="nazwisko='";
        c=name1->Lines->Count;
        for (i=0;i<c ;i++)
        {
            if (i)
                tbuf1=tbuf1+"\\n";
            tbuf2=name1->Lines->Strings[i];
            tbuf1=tbuf1+tbuf2;
        }
        tbuf1=tbuf1+"',";
        Query3->SQL->Add(tbuf1);
        //adres
        tbuf1="adres=";
        i=adr1->ItemIndex;
        tbuf2=IntToStr(ids[i]);
        tbuf1=tbuf2+",";
        Query3->SQL->Add(tbuf1);
        //NIP
        tbuf2=NIP1->Text;
        tbuf1="NIP='"+tbuf2+"',";
        Query3->SQL->Add(tbuf1);
        //REGON
        tbuf2=REGON1->Text;
        tbuf1="REGON='"+tbuf2+"');";
        Query3->SQL->Add(tbuf1);
    }
    try
    {
        Query3->ExecSQL();
        Query3->SQL->Clear();
        Query3->SQL->Add("COMMIT;");
        Query3->ExecSQL();
        can1->Enabled=false;
        Close();
    }
    catch(...)
    {
        Query3->SQL->Clear();
        Query3->SQL->Add("ROLLBACK;");
        Query3->ExecSQL();
        can1->Enabled=false;
    }



}
//---------------------------------------------------------------------------

void __fastcall TClientData1::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if (can1->Enabled)
    {
        can1Click(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TClientData1::sym1Change(TObject *Sender)
{
    if ((sym1->Text.IsEmpty())
    ||((name1->Lines->Count)==0)
    ||((NIP1->Text!=NIP1->EditText)&&(NIP1->EditText[0]!=' ')))
    {
        ok1->Enabled=false;
    }
    else
    {
        ok1->Enabled=true;
    }



}
//---------------------------------------------------------------------------


