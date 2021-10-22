//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "changelog1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChangeLog *ChangeLog;
//---------------------------------------------------------------------------
__fastcall TChangeLog::TChangeLog(TComponent* Owner)
    : TForm(Owner)
{
    LogLoaded=false;
}
//---------------------------------------------------------------------------
void __fastcall TChangeLog::FormActivate(TObject *Sender)
{
    if (LogLoaded==false)
    {
        AnsiString chn=ConfigData.Language;
        Memo1->Lines->LoadFromFile("changelog-"+chn+".txt");
        LogLoaded=true;
    }
    Caption=Translator["C3001"];
}
//---------------------------------------------------------------------------
