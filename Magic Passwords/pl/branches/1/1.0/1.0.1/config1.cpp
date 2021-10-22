//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "config1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall TConfigData::TConfigData()
{
    //TODO: Add your source code here
    Language="en";
}

__fastcall TConfigData::TConfigData(const TConfigData &ConfigData)
{
    //TODO: Kontruktor kopiuj¹cy
    Language=ConfigData.Language;
}

void TConfigData::ReadConfigFromRegistry(TSafeRegistry *reg1, AnsiString key)
{
    reg1->RootKey=HKEY_CURRENT_USER;
    if (reg1->KeyExists(key))
    {
        //odczyt
        reg1->OpenKey(key,true);
        Language=reg1->ReadString("Language",Language);
        reg1->CloseKey();
    }
    else
    {
        WriteConfigToRegistry(reg1,key);
    }
}

void TConfigData::WriteConfigToRegistry(TSafeRegistry * reg1, AnsiString key)
{
    //TODO: Zapisuje konfigurcjê
    reg1->OpenKey(key,true);
    reg1->RootKey=HKEY_CURRENT_USER;
    reg1->WriteString("Language",Language);
    reg1->CloseKey();
}
