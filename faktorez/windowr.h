//---------------------------------------------------------------------------

#ifndef windowrH
#define windowrH
#include <vcl.h>
#include <fstream.h>
#include <inifiles.hpp>
#include "saferegistry.h"
//---------------------------------------------------------------------------
class TWindowR
{
private:
    TWindowState WindowState;
    TRect ClientRectangle;

protected:

public:
    void GetWindowRectangle(TForm * form);
    void SetWindowRectangle(TForm * form);
    TWindowR(void);
    ~TWindowR();
    TWindowR(const TWindowR & win1);
    TWindowR & operator =(const TWindowR &win1);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall LoadFromIni(TIniFile * IniFile, AnsiString Section);
    void ReadFromRegistry(TSafeRegistry *reg1, AnsiString key);
    void WriteToRegistry(TSafeRegistry * reg1, AnsiString key);
};

#endif
