//---------------------------------------------------------------------------
#ifndef dispH
#define dispH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TDisplay : public TForm
{
__published:	// IDE-managed Componentsvoid __fastcall show1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TDisplay(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDisplay *Display;
//---------------------------------------------------------------------------
#endif
