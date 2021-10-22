//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newfield1.h"
#include "config1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewField *NewField;
//---------------------------------------------------------------------------
__fastcall TNewField::TNewField(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewField::FormShow(TObject *Sender)
{
    if (Insert)
    {
        fn1->Clear();
        Caption="Nowe pole";
    }
    else
    {
        Caption="Zmiana nazwy pola";
    }
}
//---------------------------------------------------------------------------
void __fastcall TNewField::fn1Change(TObject *Sender)
{
    if ((Config->FaktorzData.FieldNumber(fn1->Text)>=0)||(fn1->Text.IsEmpty()))
    {
        ok1->Enabled=false;
    }
    else
    {
        ok1->Enabled=true;
    }
}
//---------------------------------------------------------------------------
