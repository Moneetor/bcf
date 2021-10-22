//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "saferegistry.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



int __fastcall TSafeRegistry::ReadInteger(AnsiString Name, int Value)
{
    //TODO: Odczyt inta
    if (ValueExists(Name))
    {
        return(TRegistry::ReadInteger(Name));
    }
    else
    {
        return Value;
    }
}

AnsiString __fastcall TSafeRegistry::ReadString(AnsiString Name, AnsiString DefaultValue)
{
    //TODO: odczyt stringa
    if (ValueExists(Name))
    {
        return(TRegistry::ReadString(Name));
    }
    else
    {
        return DefaultValue;
    }
}

bool __fastcall TSafeRegistry::ReadBool(AnsiString Name, bool DefaultValue)
{
    //TODO: odczyt boola
    if (ValueExists(Name))
    {
        return(TRegistry::ReadBool(Name));
    }
    else
    {
        return DefaultValue;
    }
}

int __fastcall TSafeRegistry::ReadInteger(AnsiString Name)
{
    return(TRegistry::ReadInteger(Name));
}

AnsiString __fastcall TSafeRegistry::ReadString(AnsiString Name)
{
    return(TRegistry::ReadString(Name));
}

bool __fastcall TSafeRegistry::ReadBool(AnsiString Name)
{
    return(TRegistry::ReadBool(Name));
}

System::TDateTime __fastcall TSafeRegistry::ReadDate(AnsiString Name, System::TDateTime DefaultValue)
{
    if (ValueExists(Name))
    {
        return(TRegistry::ReadDate(Name));
    }
    else
    {
        return DefaultValue;
    }
}

System::TDateTime __fastcall TSafeRegistry::ReadDateTime(AnsiString Name)
{
    return(TRegistry::ReadDateTime(Name));
}

System::TDateTime __fastcall TSafeRegistry::ReadDateTime(AnsiString Name, System::TDateTime DefaultValue)
{
    if (ValueExists(Name))
    {
        return(TRegistry::ReadDateTime(Name));
    }
    else
    {
        return DefaultValue;
    }
}

System::TDateTime __fastcall TSafeRegistry::ReadDate(AnsiString Name)
{
    return(TRegistry::ReadDate(Name));
}


System::TDateTime __fastcall TSafeRegistry::ReadTime(AnsiString Name, System::TDateTime DefaultValue)
{
    if (ValueExists(Name))
    {
        return(TRegistry::ReadTime(Name));
    }
    else
    {
        return DefaultValue;
    }
}

System::TDateTime __fastcall TSafeRegistry::ReadTime(AnsiString Name)
{
    return(TRegistry::ReadTime(Name));
}



double __fastcall TSafeRegistry::ReadFloat(const AnsiString Name, double DefaultValue)
{
    if (ValueExists(Name))
    {
        return(TRegistry::ReadFloat(Name));
    }
    else
    {
        return DefaultValue;
    }
}

double __fastcall TSafeRegistry::ReadFloat(const AnsiString Name)
{
    return(TRegistry::ReadFloat(Name));
}



System::Currency __fastcall TSafeRegistry::ReadCurrency(const AnsiString Name, System::Currency DefaultValue)
{
    if (ValueExists(Name))
    {
        return(TRegistry::ReadCurrency(Name));
    }
    else
    {
        return DefaultValue;
    }
}

System::Currency __fastcall TSafeRegistry::ReadCurrency(const AnsiString Name)
{
    return(TRegistry::ReadCurrency(Name));
}
