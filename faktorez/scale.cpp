//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "scale.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


TScale::TScale()
{
    //TODO: Add your source code here
    Nominator=1;
    Denominator=1;
    ScaleFactor=1;
}

TScale::TScale(const TScale & Scale)
{
    //TODO: Add your source code here
    Nominator=Scale.Nominator;
    Denominator=Scale.Denominator;
    ScaleFactor=Scale.ScaleFactor;
}

TScale::~TScale(){ }

void TScale::SetNominator(int nom)
{
    //TODO: Add your source code here
    if (nom)
    {
        Nominator=nom;
        UpdateScale();
    }

}

int TScale::GetNominator(void)
{
    //TODO: Add your source code here
    return(Nominator);
}

void __fastcall TScale::UpdateScale(void)
{
    //TODO: Add your source code here
    ScaleFactor=(double)Nominator/(double)Denominator;
}

void TScale::SetDenominator(int den)
{
    //TODO: Add your source code here
    if (den)
    {
        Denominator=den;
        UpdateScale();
    }
}

int TScale::GetDenominator(void)
{
    //TODO: Add your source code here
    return(Denominator);
}

TScale::operator double(void)
{
    return ScaleFactor;
}


TScale::TScale(int nom, int den)
{
    //TODO: Add your source code here
    if (nom==0)
    {
        Nominator=1;
    }
    else
    {
        Nominator=nom;
    }
    if (den==0)
    {
        Denominator=1;
    }
    else
    {
        Denominator=den;
    }
    ScaleFactor=Nominator/Denominator;
}

TScale & TScale::operator =(const TScale & Scale)
{
    Nominator=Scale.Nominator;
    Denominator=Scale.Denominator;
    ScaleFactor=Scale.ScaleFactor;
    return(*this);
}

TScale TScale::operator *(const TScale Scale)
{
    TScale sc1;
    sc1.Nominator=Nominator;
    sc1.Denominator=Denominator;
    if ((Nominator==Scale.Denominator)&&(Denominator==Scale.Nominator))
    {
        sc1.Nominator=sc1.Denominator=1;
        sc1.ScaleFactor=1;
        sc1.UpdateScale();
        return sc1;
    }
    if ((Scale.Nominator==1)||(Scale.Denominator==1))
    {
        if (Scale.Nominator==1)
        {
            if ((Scale.Denominator<sc1.Nominator)&&
            (sc1.Nominator%Scale.Denominator==0))
            {
                sc1.Nominator/=Scale.Denominator;
            }
            else
            {
                sc1.Denominator*=Scale.Denominator;
            }
        }
        else
        {
            if ((Scale.Nominator<sc1.Denominator)&&
            (sc1.Denominator%Scale.Nominator==0))
            {
                sc1.Denominator/=Scale.Nominator;
            }
            else
            {
                sc1.Nominator*=Scale.Nominator;
            }
        }
    }
    else
    {
        sc1.Nominator*=Scale.Nominator;
        sc1.Denominator*=Scale.Denominator;
    }
    sc1.UpdateScale();
    return sc1;
}

TScale & TScale::operator *=(const TScale & Scale)
{
    *this=*this*Scale;
    return(*this);
}


void TScale::Invert(void)
{
    int buf;
    //TODO: odwraca u³amek
    buf=Nominator;
    Nominator=Denominator;
    Denominator=buf;
}

void TScale::Reset(void)
{
    //TODO: Add your source code here
    Nominator=Denominator=ScaleFactor=1;
}

void __fastcall TScale::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Zapis skali do pliku ini
    IniFile->WriteInteger(Section,"Nominator",Nominator);
    IniFile->WriteInteger(Section,"Denomnator",Denominator);
    IniFile->WriteFloat(Section,"ScaleFactor",ScaleFactor);
}

void __fastcall TScale::LoadFromIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Odczyt skali z pliku ini
    Nominator=IniFile->ReadInteger(Section,"Nominator",Nominator);
    Denominator=IniFile->ReadInteger(Section,"Denominator",Denominator);
    ScaleFactor=IniFile->ReadFloat(Section,"ScaleFactor",ScaleFactor);
}
