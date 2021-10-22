//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "about.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
    Animate1->FileName=ExtractFilePath(Application->ExeName)+"\\video\\monnet.avi";
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::OKButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormActivate(TObject *Sender)
{
    Animate1->Active=true;
    Caption=Translator["C1001"];
    Version->Caption=Translator["L1001"];
    www1->Caption=Translator["L1002"];
    Copyright->Caption=Translator["L1003"];
    Comments->Caption=Translator["L1004"];
    Version->Caption=Translator["L1001"];
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormClose(TObject *Sender, TCloseAction &Action)
{
    Animate1->Active=false;    
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::www1Click(TObject *Sender)
{
    AnsiString tbuf1;
    tbuf1=www1->Hint;
    ShellExecuteA(NULL,"open",tbuf1.c_str(),"","",SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

