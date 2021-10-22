//---------------------------------------------------------------------------

#ifndef baloonH
#define baloonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TTextBaloon : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    TTimer *Timer1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:     // User declarations
    __fastcall TTextBaloon(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTextBaloon *TextBaloon;
//---------------------------------------------------------------------------
#endif
