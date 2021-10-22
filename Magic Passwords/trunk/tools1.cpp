//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tools1.h"
#include "magic1.h"
#include "winuser.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Trayicon"
#pragma resource "*.dfm"
TTools *Tools;

AnsiString ApplicationRegistryKey="Software\\MON.NET\\Magic Passwords";

//---------------------------------------------------------------------------
__fastcall TTools::TTools(TComponent* Owner)
    : TForm(Owner)
{
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
void __fastcall TTools::TrayIcon1Click(TObject *Sender)
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
void __fastcall TTools::Timer1Timer(TObject *Sender)
{
    Timer1->Enabled=false;
    TrayIcon1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TTools::FormActivate(TObject *Sender)
{
    if (TrayIcon1->Visible==false)
    {
        TrayIcon1->Visible=true;
    }
}
//---------------------------------------------------------------------------
void TTools::InitializeInterface(void)
{
    //TODO: Add your source code here
    try
    {
        Translator.Language=ConfigData.Language;
        TrayIcon1->Hint=Translator["T0001"];
        clo1->Caption=Translator["B4001"];
        more1->Caption=Translator["B4002"];
        copy1->Caption=Translator["B4003"];
        show1->Caption=Translator["CK4001"];
        clo1->Hint=Translator["H4001"];
        more1->Hint=Translator["H4002"];
        copy1->Hint=Translator["H4003"];
        pass1ed->Hint=Translator["H4004"];
        big1ed->Hint=Translator["H4005"];
        big1ud->Hint=Translator["H4005"];
        loo1ed->Hint=Translator["H4006"];
        loo1ud->Hint=Translator["H4006"];
        len1ed->Hint=Translator["H4007"];
        len1ud->Hint=Translator["H4007"];
        Czy1->Hint=Translator["H4008"];
        Datki1->Hint=Translator["H4009"];
        Changelog1->Hint=Translator["H4010"];
        Czy1->Caption=Translator["M4001"];
        Datki1->Caption=Translator["M4002"];
        Changelog1->Caption=Translator["M4003"];
    }
    catch(...)
    {
        ConfigData.Language="en";
        ConfigData.WriteConfigToRegistry(SafeRegistry,ApplicationRegistryKey);
    }

}
void __fastcall TTools::more1Click(TObject *Sender)
{
    MagicPassword->ConfigData=ConfigData;
    MagicPassword->Show();
    Hide();
}
//---------------------------------------------------------------------------
void __fastcall TTools::clo1Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TTools::FormShow(TObject *Sender)
{
    int x,y;
    x=Screen->Width-Width;
    y=Screen->DesktopHeight-2*Height;
    RECT r1;
    if (SystemParametersInfoA(SPI_GETWORKAREA,0,&r1,0))
    {
        if ((r1.left==0)&&(r1.top==0))
        {
            //Pasek o prawej lub w dole
            if (r1.bottom == Screen->Height)
            {
                //pasek z prawej
                x=r1.right-Width;
            }
            y=r1.bottom-Height;
        }
        else
        {
            if (r1.left>0)
            {
                //pasek z lewej
                x=r1.left;
                y=r1.bottom-Height;
            }
            else
            {
                //pasek u góry
                y=r1.top;
            }
        }
    }
    Left=x;
    Top=y;
}
//---------------------------------------------------------------------------



void __fastcall TTools::FillBrushes(void)
{
    //TODO: Wype³nianie gradientem
    bg1=new Graphics::TBitmap;
    bg1->Assign(BGMap);
    BGMap->Height=Height;
    BGMap->Canvas->StretchDraw(ClientRect,bg1);
    Brush->Bitmap=BGMap;
    show1->Color=BGMap->Canvas->Pixels[0][show1->Top];
}

void __fastcall TTools::FormDestroy(TObject *Sender)
{
    delete BGMap;
    delete bg1;
}
//---------------------------------------------------------------------------

void __fastcall TTools::copy1Click(TObject *Sender)
{
    MagicPassword->copy1Click(Sender);    
}
//---------------------------------------------------------------------------

void __fastcall TTools::pass1edChange(TObject *Sender)
{
    MagicPassword->pass1ed->Text=pass1ed->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TTools::big1edChange(TObject *Sender)
{
    if (MagicPassword==NULL)
        return;
    MagicPassword->big1tr->Position=big1ud->Position;
}
//---------------------------------------------------------------------------

void __fastcall TTools::loo1edChange(TObject *Sender)
{
    if (MagicPassword==NULL)
        return;
    MagicPassword->loo1tr->Position=loo1ud->Position;
}
//---------------------------------------------------------------------------
void __fastcall TTools::len1edChange(TObject *Sender)
{
    if (MagicPassword==NULL)
        return;
    MagicPassword->len1tr->Position=len1ud->Position;
}
//---------------------------------------------------------------------------
void __fastcall TTools::show1Click(TObject *Sender)
{
    if (show1->Checked)
        pass1ed->PasswordChar=0;
    else
        pass1ed->PasswordChar='#';
}
//---------------------------------------------------------------------------

void __fastcall TTools::Czy1Click(TObject *Sender)
{
    MagicPassword->cle1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TTools::Datki1Click(TObject *Sender)
{
    MagicPassword->don1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TTools::Changelog1Click(TObject *Sender)
{
    MagicPassword->chan1Click(Sender);
}
//---------------------------------------------------------------------------


