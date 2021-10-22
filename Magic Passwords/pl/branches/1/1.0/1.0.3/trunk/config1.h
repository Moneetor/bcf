//---------------------------------------------------------------------------

#ifndef config1H
#define config1H

#include "saferegistry.h"

//---------------------------------------------------------------------------
class TConfigData
{
private:

protected:

public:
    AnsiString Language;
    void ReadConfigFromRegistry(TSafeRegistry *reg1, AnsiString key);
    __fastcall TConfigData();
    __fastcall TConfigData(const TConfigData &ConfigData);
    void WriteConfigToRegistry(TSafeRegistry * reg1, AnsiString key);
};

#endif
