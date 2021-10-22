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
#include "Trayicon.h"
#include <ImgList.hpp>
#include "saferegistry.h"
#include "config1.h"
#include "translator.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <NMUUE.hpp>
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
    TCheckBox *show1;
    TCheckBox *show2;
    TBitBtn *don1;
    TBitBtn *cle1;
    TBitBtn *chan1;
    TTimer *Timer1;
    void __fastcall big1trChange(TObject *Sender);
    void __fastcall big1edChange(TObject *Sender);
    void __fastcall loo1trChange(TObject *Sender);
    void __fastcall loo1edChange(TObject *Sender);
    void __fastcall copy1Click(TObject *Sender);
    void __fastcall len1trChange(TObject *Sender);
    void __fastcall len1edChange(TObject *Sender);
    void __fastcall inf1Click(TObject *Sender);
    void __fastcall show1Click(TObject *Sender);
    void __fastcall show2Click(TObject *Sender);
    void __fastcall don1Click(TObject *Sender);
    void __fastcall cle1Click(TObject *Sender);
    void __fastcall chan1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
    Graphics::TBitmap *BGMap;
    Graphics::TBitmap *bg1;
    Graphics::TBitmap *bg2;
    Graphics::TBitmap *bg3;
    void InitializeInterface(void);
    void __fastcall FillBrushes(void);
public:
    int Loops;
    int BigLetters;
    int PasswordLength;		// User declarations
    TSafeRegistry *SafeRegistry;
    TConfigData ConfigData;
    TTranslator Translator;
    __fastcall TMagicPassword(TComponent* Owner);
    AnsiString __fastcall GetHash(AnsiString Text, unsigned int big);
};
//---------------------------------------------------------------------------
extern PACKAGE TMagicPassword *MagicPassword;
//---------------------------------------------------------------------------
#endif
