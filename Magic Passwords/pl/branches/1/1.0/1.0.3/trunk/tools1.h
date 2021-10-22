//---------------------------------------------------------------------------

#ifndef tools1H
#define tools1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Trayicon.h"
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include "saferegistry.h"
#include "config1.h"
#include "translator.h"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TTools : public TForm
{
__published:	// IDE-managed Components
    TEdit *pass1ed;
    TCheckBox *show1;
    TTimer *Timer1;
    TImageList *ImageList1;
    TEdit *big1ed;
    TEdit *loo1ed;
    TEdit *len1ed;
    TUpDown *big1ud;
    TUpDown *loo1ud;
    TUpDown *len1ud;
    TTrayIcon *TrayIcon1;
    TToolBar *buttons1;
    TToolButton *more1;
    TToolButton *clo1;
    TToolButton *copy1;
    TPopupMenu *PopupMenu1;
    TMenuItem *Datki1;
    TMenuItem *Changelog1;
    TMenuItem *Czy1;
    TMenuItem *N1;
    void __fastcall TrayIcon1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall more1Click(TObject *Sender);
    void __fastcall clo1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall copy1Click(TObject *Sender);
    void __fastcall pass1edChange(TObject *Sender);
    void __fastcall big1edChange(TObject *Sender);
    void __fastcall loo1edChange(TObject *Sender);
    void __fastcall len1edChange(TObject *Sender);
    void __fastcall show1Click(TObject *Sender);
    void __fastcall Czy1Click(TObject *Sender);
    void __fastcall Datki1Click(TObject *Sender);
    void __fastcall Changelog1Click(TObject *Sender);
private:
    void __fastcall FillBrushes(void);	// User declarations
public:		// User declarations
    TTranslator Translator;
    TSafeRegistry *SafeRegistry;
    TConfigData ConfigData;
    __fastcall TTools(TComponent* Owner);
    Graphics::TBitmap *BGMap;
    Graphics::TBitmap *bg1;
    void InitializeInterface(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TTools *Tools;
//---------------------------------------------------------------------------
#endif
