//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream.h>

#pragma hdrstop

#include "windowr.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TWindowR::GetWindowRectangle(TForm * form)
{
    //DONE: Get window data from form
    ClientRectangle=form->BoundsRect;
    WindowState=form->WindowState;
}

void TWindowR::SetWindowRectangle(TForm * form)
{
    //TODO: set form attributes from data
    form->WindowState=WindowState;
    if (WindowState!=wsMaximized)
        form->BoundsRect=ClientRectangle;
}

TWindowR::TWindowR(void)
{
    //DONE: Konstruktor
    ClientRectangle.Top=100;
    ClientRectangle.Left=100;
    ClientRectangle.Right=100;
    ClientRectangle.Bottom=100;
    WindowState=wsNormal;
}

TWindowR::~TWindowR()
{
    //DONE: Destruktor
    ClientRectangle.Top=0;
    ClientRectangle.Left=0;
    ClientRectangle.Right=0;
    ClientRectangle.Bottom=0;
    WindowState=(TWindowState)0;
}

TWindowR::TWindowR(const TWindowR &win1)
{
    //TODO: konstruktor kopiuj¹cy
    WindowState=win1.WindowState;
    ClientRectangle.Top=win1.ClientRectangle.Top;
    ClientRectangle.Left=win1.ClientRectangle.Left;
    ClientRectangle.Right=win1.ClientRectangle.Right;
    ClientRectangle.Bottom=win1.ClientRectangle.Bottom;
}

TWindowR & TWindowR::operator =(const TWindowR &win1)
{
    WindowState=win1.WindowState;
    ClientRectangle.Top=win1.ClientRectangle.Top;
    ClientRectangle.Left=win1.ClientRectangle.Left;
    ClientRectangle.Right=win1.ClientRectangle.Right;
    ClientRectangle.Bottom=win1.ClientRectangle.Bottom;
    return(*this);
}


void __fastcall TWindowR::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Zapis okna do pliku
    IniFile->WriteInteger(Section,"WindowState",WindowState);
    IniFile->WriteInteger(Section,"Left",ClientRectangle.Left);
    IniFile->WriteInteger(Section,"Top",ClientRectangle.Top);
    IniFile->WriteInteger(Section,"Right",ClientRectangle.Right);
    IniFile->WriteInteger(Section,"Bottom",ClientRectangle.Bottom);
}

void __fastcall TWindowR::LoadFromIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Odczyt danych z pliku ini
    WindowState=(TWindowState)IniFile->ReadInteger(Section,"WindowState",wsMaximized);
    ClientRectangle.Left=IniFile->ReadInteger(Section,"Left",0);
    ClientRectangle.Top=IniFile->ReadInteger(Section,"Top",0);
    ClientRectangle.Right=IniFile->ReadInteger(Section,"Right",1024);
    ClientRectangle.Bottom=IniFile->ReadInteger(Section,"Bottom",768);
}

void TWindowR::ReadFromRegistry(TSafeRegistry *reg1, AnsiString key)
{
    reg1->OpenKey(key,true);
    WindowState=(TWindowState) reg1->ReadInteger("WindowState",WindowState);
    ClientRectangle.Left=reg1->ReadInteger("Left",ClientRectangle.Left);
    ClientRectangle.Top=reg1->ReadInteger("Top",ClientRectangle.Top);
    ClientRectangle.Right=reg1->ReadInteger("Right",ClientRectangle.Right);
    ClientRectangle.Bottom=reg1->ReadInteger("Bottom",ClientRectangle.Bottom);
    reg1->CloseKey();
}

void TWindowR::WriteToRegistry(TSafeRegistry * reg1, AnsiString key)
{
    reg1->OpenKey(key,true);
    reg1->WriteInteger("WindowState",WindowState);
    reg1->WriteInteger("Left",ClientRectangle.Left);
    reg1->WriteInteger("Top",ClientRectangle.Top);
    reg1->WriteInteger("Right",ClientRectangle.Right);
    reg1->WriteInteger("Bottom",ClientRectangle.Bottom);
    reg1->CloseKey();
}

