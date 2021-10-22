//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "baloon.h"
#include "magic1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTextBaloon *TextBaloon;
//---------------------------------------------------------------------------
__fastcall TTextBaloon::TTextBaloon(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTextBaloon::FormShow(TObject *Sender)
{
    Timer1->Enabled=true;    
}
//---------------------------------------------------------------------------
void __fastcall TTextBaloon::Timer1Timer(TObject *Sender)
{
    Timer1->Enabled=false;
    Close();
}
//---------------------------------------------------------------------------
