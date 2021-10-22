//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "prtdialog2.h"
#include "faktor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrintMassDialog2 *PrintMassDialog2;
//---------------------------------------------------------------------------
__fastcall TPrintMassDialog2::TPrintMassDialog2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintMassDialog2::can1Click(TObject *Sender)
{
    /* TODO : Anulowanie druku */
    Faktorez->MassPrinter->Terminate();
}
//---------------------------------------------------------------------------
