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
    TTrayIcon *TrayIcon1;
    TImageList *ImageList1;
    TCheckBox *show1;
    TCheckBox *show2;
    TBitBtn *don1;
    TBitBtn *cle1;
    TTimer *Timer1;
    TBitBtn *chan1;
    void __fastcall big1trChange(TObject *Sender);
    void __fastcall big1edChange(TObject *Sender);
    void __fastcall loo1trChange(TObject *Sender);
    void __fastcall loo1edChange(TObject *Sender);
    void __fastcall copy1Click(TObject *Sender);
    void __fastcall len1trChange(TObject *Sender);
    void __fastcall len1edChange(TObject *Sender);
    void __fastcall inf1Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall TrayIcon1Click(TObject *Sender);
    void __fastcall show1Click(TObject *Sender);
    void __fastcall show2Click(TObject *Sender);
    void __fastcall don1Click(TObject *Sender);
    void __fastcall cle1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall chan1Click(TObject *Sender);
private:
    void InitializeInterface(void);
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
