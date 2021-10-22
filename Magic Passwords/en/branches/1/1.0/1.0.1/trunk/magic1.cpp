//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "magic1.h"
#include "VCLhashlib.h"
#include <Clipbrd.hpp>
#include "about.h"

using namespace std;
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma resource "*.dfm"
TMagicPassword *MagicPassword;

AnsiString ApplicationRegistryKey="Software\\MON.NET\\Magic Passwords";
AnsiString RunKey="\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";

//---------------------------------------------------------------------------
__fastcall TMagicPassword::TMagicPassword(TComponent* Owner)
    : TForm(Owner)
{
    Loops=1;
    BigLetters=0;
    PasswordLength=32;
    SafeRegistry=new TSafeRegistry;
    SafeRegistry->RootKey=HKEY_CURRENT_USER;
    ConfigData.ReadConfigFromRegistry(SafeRegistry,ApplicationRegistryKey);
    InitializeInterface();
}
//---------------------------------------------------------------------------


AnsiString __fastcall TMagicPassword::GetHash(AnsiString Text, unsigned int big)
{
    //TODO: Pobieranie danych
    int i,l;
    AnsiString Hash,up,low;
    TMD5Hash MD5Hash;
    Hash=MD5Hash.GetHash(Text);
    up=Hash.SubString(1,big);
    low=Hash.SubString(1+big,32-big);
    low=low.LowerCase();
    up=up.UpperCase();
    Hash=up+low;
    return Hash;
}

void __fastcall TMagicPassword::big1trChange(TObject *Sender)
{
    int i;
    AnsiString tbuf1;
    BigLetters=big1tr->Position;
    big1ud->Position=BigLetters;
    tbuf1=pass1ed->Text;
    for (i=0;i<Loops ;i++)
    {
        tbuf1=GetHash(tbuf1,BigLetters);
    }
    tbuf1=tbuf1.SubString(1,PasswordLength);
    pass2ed->Text=tbuf1;
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::big1edChange(TObject *Sender)
{
    BigLetters=big1ud->Position;
    big1tr->Position=BigLetters;
    big1trChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::loo1trChange(TObject *Sender)
{
    Loops=loo1tr->Position;
    loo1ud->Position=Loops;
    big1trChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::loo1edChange(TObject *Sender)
{
    Loops=loo1ud->Position;
    loo1tr->Position=Loops;
    big1trChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::copy1Click(TObject *Sender)
{
    Clipboard()->AsText=pass2ed->Text;    
}
//---------------------------------------------------------------------------


void __fastcall TMagicPassword::len1trChange(TObject *Sender)
{
    PasswordLength=len1tr->Position;
    len1ud->Position=PasswordLength;
    big1trChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::len1edChange(TObject *Sender)
{
    PasswordLength=len1ud->Position;
    len1tr->Position=PasswordLength;
    big1trChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::inf1Click(TObject *Sender)
{
    AboutBox->Translator=Translator;
    AboutBox->Show();    
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::FormActivate(TObject *Sender)
{
    if (TrayIcon1->Visible==false)
    {
        TrayIcon1->Visible=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::TrayIcon1Click(TObject *Sender)
{
    if (TrayIcon1->Tag==0)
    {
        //normalnie - chowamy
        TrayIcon1->Minimize();
        TrayIcon1->Tag=1;
    }
    else
    {
        //zminimalizowany
        TrayIcon1->Restore();
        TrayIcon1->Tag=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::show1Click(TObject *Sender)
{
    if (show1->Checked)
        pass1ed->PasswordChar=0;
    else
        pass1ed->PasswordChar='#';                                                    
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::show2Click(TObject *Sender)
{
    if (show2->Checked)
        pass2ed->PasswordChar=0;
    else
        pass2ed->PasswordChar='#';
}
//---------------------------------------------------------------------------


void TMagicPassword::InitializeInterface(void)
{
    //TODO: Inicjalizacja programu z konfiguracji
    try
    {
        Translator.Language=ConfigData.Language;
        pass1l->Caption=Translator["L0001"];
        pass2l->Caption=Translator["L0002"];
        show1->Caption=Translator["CK0001"];
        show2->Caption=Translator["CK0001"];
        big1l->Caption=Translator["L0003"];
        loo1l->Caption=Translator["L0004"];
        len1l->Caption=Translator["L0005"];
        copy1->Caption=Translator["B0001"];
        inf1->Caption=Translator["B0002"];
        don1->Caption=Translator["B0003"];
        don1->Hint=Translator["B0003h"];
        TrayIcon1->Hint=Translator["T0001"];
    }
    catch(...)
    {
        ConfigData.Language="en";
        ConfigData.WriteConfigToRegistry(SafeRegistry,ApplicationRegistryKey);
    }

}

void __fastcall TMagicPassword::don1Click(TObject *Sender)
{
    AnsiString tbuf1;
    tbuf1="http://www.moneetor.mon.net.pl/donations/mp/"+ConfigData.Language;
    ShellExecuteA(NULL,"open",tbuf1.c_str(),"","",SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

