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
#pragma resource "*.dfm"
TMagicPassword *MagicPassword;
//---------------------------------------------------------------------------
__fastcall TMagicPassword::TMagicPassword(TComponent* Owner)
    : TForm(Owner)
{
    Loops=1;
    BigLetters=0;
    PasswordLength=32;
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
    AboutBox->Show();    
}
//---------------------------------------------------------------------------

