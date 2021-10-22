//---------------------------------------------------------------------------

#ifndef saferegistryH
#define saferegistryH
#include <registry.hpp>
//---------------------------------------------------------------------------
class TSafeRegistry : public TRegistry
{
private:

protected:

public:
    __fastcall TSafeRegistry():TRegistry() {};
    __fastcall ~TSafeRegistry(){}
    int __fastcall ReadInteger(AnsiString Name, int Value);
    AnsiString __fastcall ReadString(AnsiString Name, AnsiString DefaultValue);
    bool __fastcall ReadBool(AnsiString Name, bool DefaultValue);
    int __fastcall ReadInteger(AnsiString Name);
    AnsiString __fastcall ReadString(AnsiString Name);
    bool __fastcall ReadBool(AnsiString Name);
    System::TDateTime __fastcall ReadDate(AnsiString Name, System::TDateTime DefaultValue);
    System::TDateTime __fastcall ReadDateTime(AnsiString Name);
    System::TDateTime __fastcall ReadDateTime(AnsiString Name, System::TDateTime DefaultValue);
    System::TDateTime __fastcall ReadDate(AnsiString Name);
    System::TDateTime __fastcall ReadTime(AnsiString Name, System::TDateTime DefaultValue);
    System::TDateTime __fastcall ReadTime(AnsiString Name);
    double __fastcall ReadFloat(const AnsiString Name, double DefaultValue);
    double __fastcall ReadFloat(const AnsiString Name);
    System::Currency __fastcall ReadCurrency(const AnsiString Name, System::Currency DefaultValue);
    System::Currency __fastcall ReadCurrency(const AnsiString Name);
};

#endif
