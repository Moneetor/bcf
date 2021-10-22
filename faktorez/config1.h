//---------------------------------------------------------------------------

#ifndef config1H
#define config1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "faktordata1.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <AppEvnts.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
enum TFieldPosition {fpOutside, fpInside, fpTopBorder, fpLeftBorder, fpBottomBorder, fpRightBorder,
    fpLeftTopCorner, fpRightTopCorner, fpLeftBottomCorner, fpRightBottomCorner};

class TConfig : public TForm
{
__published:	// IDE-managed Components
    TPageControl *Pages1;
    TTabSheet *pap1;
    TTabSheet *bank1;
    TTabSheet *sell1;
    TTabSheet *logo1;
    TTabSheet *num1;
    TTabSheet *fdat1;
    TGroupBox *marg1;
    TGroupBox *font1;
    TEdit *marg101ed;
    TEdit *marg103ed;
    TEdit *marg102ed;
    TUpDown *marg101;
    TUpDown *marg103;
    TUpDown *marg102;
    TUpDown *marg104;
    TLabel *marg101l;
    TLabel *marg103l;
    TLabel *marg102l;
    TLabel *marg104l;
    TEdit *marg104ed;
    TComboBox *font101;
    TComboBox *font102;
    TLabel *font101l;
    TLabel *font102l;
    TLabel *bank101l;
    TLabel *bank102l;
    TLabel *logo101l;
    TEdit *logo101ed;
    TButton *logo101b;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TEdit *num101ed;
    TUpDown *num101;
    TEdit *bank101ed;
    TMemo *sell101m;
    TMemo *sell102m;
    TEdit *city1;
    TLabel *NIP1l;
    TLabel *zip1l;
    TLabel *city1l;
    TLabel *sell102l;
    TLabel *sell101l;
    TEdit *REGON1;
    TLabel *REGON1l;
    TPanel *Panel1;
    TPanel *Panel2;
    TImage *fimg1;
    TPanel *Panel3;
    TPanel *Panel4;
    TListBox *fl1;
    TMaskEdit *zip1;
    TOpenPictureDialog *logo1d;
    TSpeedButton *al101;
    TSpeedButton *al102;
    TSpeedButton *al103;
    TGroupBox *size1;
    TEdit *size101ed;
    TEdit *size102ed;
    TEdit *size103ed;
    TEdit *size104ed;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TCheckBox *size10301;
    TCheckBox *size10401;
    TSpeedButton *b1;
    TSpeedButton *h1;
    TMaskEdit *bank102ed;
    TBevel *Bevel1;
    TImage *logo101;
    TUpDown *size101;
    TUpDown *size102;
    TUpDown *size103;
    TUpDown *size104;
    TPopupMenu *pop1;
    TMenuItem *Dodajpole1;
    TMenuItem *Usupole1;
    TMenuItem *Zmienazw1;
    TSpeedButton *vis1;
    TMaskEdit *NIP1;
    TTabSheet *dbas1;
    TPanel *Panel5;
    TListBox *dsn1;
    TButton *find1;
    TButton *del1;
    TPanel *dbp1;
    TLabel *eng1l;
    TEdit *eng1;
    TEdit *login1;
    TLabel *login1l;
    TBitBtn *info;
    TGroupBox *pas0;
    TLabel *pas1l;
    TEdit *pas1;
    TLabel *pas2l;
    TEdit *pas2;
    TCheckBox *pas3;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall bank101edChange(TObject *Sender);
    void __fastcall bank102edChange(TObject *Sender);
    void __fastcall sell101mChange(TObject *Sender);
    void __fastcall sell102mChange(TObject *Sender);
    void __fastcall zip1Change(TObject *Sender);
    void __fastcall city1Change(TObject *Sender);
    void __fastcall NIP1Change(TObject *Sender);
    void __fastcall REGON1Change(TObject *Sender);
    void __fastcall logo101bClick(TObject *Sender);
    void __fastcall font101Change(TObject *Sender);
    void __fastcall font102Change(TObject *Sender);
    void __fastcall al101Click(TObject *Sender);
    void __fastcall al102Click(TObject *Sender);
    void __fastcall al103Click(TObject *Sender);
    void __fastcall b1Click(TObject *Sender);
    void __fastcall h1Click(TObject *Sender);
    void __fastcall marg101edChange(TObject *Sender);
    void __fastcall marg102edChange(TObject *Sender);
    void __fastcall marg103edChange(TObject *Sender);
    void __fastcall marg104edChange(TObject *Sender);
    void __fastcall num101edChange(TObject *Sender);
    void __fastcall size10301Click(TObject *Sender);
    void __fastcall size10401Click(TObject *Sender);
    void __fastcall fl1Click(TObject *Sender);
    void __fastcall Dodajpole1Click(TObject *Sender);
    void __fastcall Usupole1Click(TObject *Sender);
    void __fastcall Zmienazw1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall size101edChange(TObject *Sender);
    void __fastcall size102edChange(TObject *Sender);
    void __fastcall size103edChange(TObject *Sender);
    void __fastcall size104edChange(TObject *Sender);
    void __fastcall fimg1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall fimg1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall vis1Click(TObject *Sender);
    void __fastcall find1Click(TObject *Sender);
    void __fastcall dsn1Click(TObject *Sender);
    void __fastcall del1Click(TObject *Sender);
    void __fastcall pas3Click(TObject *Sender);
    void __fastcall pas1Change(TObject *Sender);
private:
    Graphics::TBitmap *bit1;
    double XScale;
    double YScale;
    bool FirstTime;
    int XPos;
    int YPos;
    vector<TFieldPosition> Clicked;
    TPoint LastPos;
    TPrintField LastField;
    void __fastcall ShowFieldParams(int Pos);
    void __fastcall UpdateList(void);
    void ApplyInterface(void);
    void DrawFields(void);
    TFieldPosition __fastcall GetCursorPositionOverField(int num,int X,int Y);
    void __fastcall GetCursorPositionOverFields(int X, int Y);
    void __fastcall SetFieldLimit(int Num);
public:		// User declarations
    TFaktorzData FaktorzData;
    __fastcall TConfig(TComponent* Owner);
    void __fastcall UpdateDSN(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfig *Config;
//---------------------------------------------------------------------------
#endif
