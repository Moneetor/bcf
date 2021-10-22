//---------------------------------------------------------------------------

#ifndef newfield1H
#define newfield1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>

#include "faktordata1.h"
//---------------------------------------------------------------------------
class TNewField : public TForm
{
__published:	// IDE-managed Components
    TEdit *fn1;
    TBitBtn *ok1;
    TBitBtn *can1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall fn1Change(TObject *Sender);
private:	// User declarations
public:
    bool Insert;		// User declarations
    TPrintField PrintField;
    __fastcall TNewField(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewField *NewField;
//---------------------------------------------------------------------------
#endif
