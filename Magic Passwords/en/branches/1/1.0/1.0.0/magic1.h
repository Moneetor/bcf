//---------------------------------------------------------------------------

#ifndef magic1H
#define magic1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMagicPassword : public TForm
{
__published:	// IDE-managed Components
    TEdit *pass1ed;
    TLabel *pass1l;
    TEdit *pass2ed;
    TLabel *pass2l;
    TTrackBar *big1tr;
    TEdit *big1ed;
    TUpDown *big1ud;
    TTrackBar *loo1tr;
    TEdit *loo1ed;
    TUpDown *loo1ud;
    TBitBtn *copy1;
    TBitBtn *inf1;
    TLabel *big1l;
    TLabel *loo1l;
    TLabel *len1l;
    TTrackBar *len1tr;
    TEdit *len1ed;
    TUpDown *len1ud;
    void __fastcall big1trChange(TObject *Sender);
    void __fastcall big1edChange(TObject *Sender);
    void __fastcall loo1trChange(TObject *Sender);
    void __fastcall loo1edChange(TObject *Sender);
    void __fastcall copy1Click(TObject *Sender);
    void __fastcall len1trChange(TObject *Sender);
    void __fastcall len1edChange(TObject *Sender);
    void __fastcall inf1Click(TObject *Sender);
private:
public:
    int Loops;
    int BigLetters;
    int PasswordLength;		// User declarations
    __fastcall TMagicPassword(TComponent* Owner);
    AnsiString __fastcall GetHash(AnsiString Text, unsigned int big);
};
//---------------------------------------------------------------------------
extern PACKAGE TMagicPassword *MagicPassword;
//---------------------------------------------------------------------------
#endif
