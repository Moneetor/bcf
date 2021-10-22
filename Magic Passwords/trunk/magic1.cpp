//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "magic1.h"
#include "VCLhashlib.h"
#include <Clipbrd.hpp>
#include "about.h"
#include "baloon.h"
#include "changelog1.h"
#include "jpeg.hpp"
#include "tools1.h"

using namespace std;
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma resource "*.dfm"
TMagicPassword *MagicPassword;

extern AnsiString ApplicationRegistryKey;

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
    BGMap=new Graphics::TBitmap;
    TJPEGImage *jp = new TJPEGImage();
    try
    {
        jp->LoadFromFile("GFX\\bg.jpg");
        BGMap->Assign(jp);
    }
    __finally
    {
        delete jp;
    }
    FillBrushes();
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
    Tools->big1ud->Position=BigLetters;
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
    Tools->loo1ud->Position=Loops;
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
    TextBaloon->StaticText1->Caption=Translator["L2001"];
    TextBaloon->Show();
}

//---------------------------------------------------------------------------


void __fastcall TMagicPassword::len1trChange(TObject *Sender)
{
    PasswordLength=len1tr->Position;
    len1ud->Position=PasswordLength;
    big1trChange(Sender);
    Tools->len1ud->Position=PasswordLength;
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
        cle1->Caption=Translator["B0004"];
        don1->Hint=Translator["B0003h"];
        cle1->Caption=Translator["B0004"];
        cle1->Hint=Translator["B0004h"];
        chan1->Caption=Translator["B0005"];
        add1->Caption=Translator["B0006"];
        add1->Hint=Translator["B0006h"];
    }
    catch(...)
    {
        ConfigData.Language="en";
    }

}

void __fastcall TMagicPassword::don1Click(TObject *Sender)
{
    AnsiString tbuf1;
    tbuf1="http://www.moneetor.mon.net.pl/donations/mp/"+ConfigData.Language;
    ShellExecuteA(NULL,"open",tbuf1.c_str(),"","",SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::cle1Click(TObject *Sender)
{
    Clipboard()->Clear();
    TextBaloon->StaticText1->Caption=Translator["L2002"];
    TextBaloon->Show();
    Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TMagicPassword::chan1Click(TObject *Sender)
{
    ChangeLog->Translator=Translator;
    ChangeLog->ConfigData=ConfigData;
    ChangeLog->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMagicPassword::FormDestroy(TObject *Sender)
{
    //TODO: Destruktor
    delete BGMap;
    delete bg1;
    delete bg2;
    delete bg3;
}
//---------------------------------------------------------------------------


void __fastcall TMagicPassword::FillBrushes(void)
{
    //TODO: Wype³nianie gradientem
    MagicPassword->Brush->Bitmap=BGMap;
    show1->Brush->Bitmap=BGMap;
    show2->Brush->Bitmap=BGMap;
    bg1=new Graphics::TBitmap;
    bg1->Width=50;
    bg1->Height=25;
    bg1->Canvas->Draw(0,-(big1tr->Top),BGMap);
    bg2=new Graphics::TBitmap;
    bg2->Width=50;
    bg2->Height=25;
    bg2->Canvas->Draw(0,-(loo1tr->Top),BGMap);
    bg3=new Graphics::TBitmap;
    bg3->Width=50;
    bg3->Height=25;
    bg3->Canvas->Draw(0,-(len1tr->Top),BGMap);
    big1tr->Brush->Bitmap=bg1;
    loo1tr->Brush->Bitmap=bg2;
    len1tr->Brush->Bitmap=bg3;
    show1->Color=BGMap->Canvas->Pixels[0][show1->Top];
    show2->Color=BGMap->Canvas->Pixels[0][show2->Top];
}

void __fastcall TMagicPassword::FormActivate(TObject *Sender)
{
    InitializeInterface();
    CreateLangList();
}
//---------------------------------------------------------------------------


void __fastcall TMagicPassword::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Tools->Show();
}
//---------------------------------------------------------------------------
void TMagicPassword::CreateLangList(void)
{
    //TODO: Pobiera listê jêzyków
    LL1->Clear();
    LL1->Items->LoadFromFile("lang\\list.txt");
    LL1->ItemIndex=LL1->Items->IndexOf(ConfigData.Language);
}

void __fastcall TMagicPassword::LL1Click(TObject *Sender)
{
    int i;
    i=LL1->ItemIndex;
    ConfigData.Language=LL1->Items->Strings[i];
    ConfigData.WriteConfigToRegistry(SafeRegistry,ApplicationRegistryKey);
    InitializeInterface();
}
//---------------------------------------------------------------------------

