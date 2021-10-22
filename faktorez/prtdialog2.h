//---------------------------------------------------------------------------

#ifndef prtdialog2H
#define prtdialog2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TPrintMassDialog2 : public TForm
{
__published:	// IDE-managed Components
    TBitBtn *can1;
    void __fastcall can1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TPrintMassDialog2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintMassDialog2 *PrintMassDialog2;
//---------------------------------------------------------------------------
#endif
