//---------------------------------------------------------------------------

#ifndef prtdialog1H
#define prtdialog1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TPrintMassDialog : public TForm
{
__published:	// IDE-managed Components
    TBitBtn *ok1;
    TBitBtn *can1;
        TCheckBox *div1;
private:	// User declarations
public:		// User declarations
        __fastcall TPrintMassDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintMassDialog *PrintMassDialog;
//---------------------------------------------------------------------------
#endif
