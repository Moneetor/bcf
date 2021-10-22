//---------------------------------------------------------------------------
#ifndef bumH
#define bumH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TBumCyk : public TForm
{
__published:	// IDE-managed Components
    TImage *imag1;
    void __fastcall bum01(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
    int l1;
public:		// User declarations
    __fastcall TBumCyk(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBumCyk *BumCyk;
//---------------------------------------------------------------------------
#endif
