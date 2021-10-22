//---------------------------------------------------------------------------

#ifndef changelog1H
#define changelog1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "translator.h"
//---------------------------------------------------------------------------
class TChangeLog : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    void __fastcall FormActivate(TObject *Sender);
private:
    bool LogLoaded;	// User declarations
public:		// User declarations
    TTranslator Translator;
    __fastcall TChangeLog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChangeLog *ChangeLog;
//---------------------------------------------------------------------------
#endif
