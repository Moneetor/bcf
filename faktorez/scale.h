//---------------------------------------------------------------------------

#ifndef scaleH
#define scaleH

#include <inifiles.hpp>

//---------------------------------------------------------------------------
class TScale
{
private:
    int Nominator;
    int Denominator;
    double ScaleFactor;
    void __fastcall UpdateScale(void);
    
protected:

public:
    TScale();
    TScale(const TScale & Scale);
    ~TScale();
    void SetNominator(int nom);
    int GetNominator(void);
    void SetDenominator(int den);
    int GetDenominator(void);
    operator double();
    TScale & operator =(const TScale & Scale);
    TScale operator *(const TScale Scale);
    TScale(const double d);
    TScale(int nom, int den);
    TScale & operator *=(const TScale & Scale);
    void Invert(void);
    void Reset(void);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall LoadFromIni(TIniFile * IniFile, AnsiString Section);
};

#endif
 