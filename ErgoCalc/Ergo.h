//---------------------------------------------------------------------------
#ifndef ErgoH
#define ErgoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <OleCtnrs.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TErgoCalc : public TForm
{
__published:	// IDE-managed Components
    TEdit *disp1;
    TPopupMenu *pop1;
    TMenuItem *full1;
    TMenuItem *clo1;
    TMenuItem *mpl2;
    TMenuItem *mmin2;
    TMenuItem *msho2;
    TMenuItem *mclr2;
    TMenuItem *b1;
    TMenuItem *Pierwiastek1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *Zmianaznaku1;
    TMenuItem *copy1;
    TMenuItem *Wklej1;
	TSpeedButton *cle1;
	TSpeedButton *can1;
	TSpeedButton *mclr1;
	TSpeedButton *msho1;
	TSpeedButton *mmin1;
	TSpeedButton *mpl1;
	TSpeedButton *d1;
	TSpeedButton *d2;
	TSpeedButton *d3;
	TSpeedButton *d4;
	TSpeedButton *d5;
	TSpeedButton *d6;
	TSpeedButton *d7;
	TSpeedButton *d8;
	TSpeedButton *d9;
	TSpeedButton *d0;
	TSpeedButton *plm1;
	TSpeedButton *p1;
	TSpeedButton *sqr1;
	TSpeedButton *proc1;
	TSpeedButton *IQ1;
	TSpeedButton *Button3;
	TSpeedButton *min1;
	TSpeedButton *plus1;
	TSpeedButton *equ1;
    void __fastcall d001(TObject *Sender, char &Key);
    
    void __fastcall d002(TObject *Sender);
    
    void __fastcall full1Click(TObject *Sender);
    void __fastcall clo101(TObject *Sender);
	void __fastcall plm101(TObject *Sender);
    void __fastcall d101(TObject *Sender);
    void __fastcall p101(TObject *Sender);
    void __fastcall cle101(TObject *Sender);
    void __fastcall can101(TObject *Sender);
    void __fastcall plus101(TObject *Sender);
    void __fastcall d201(TObject *Sender);
    void __fastcall d301(TObject *Sender);
    void __fastcall d401(TObject *Sender);
    void __fastcall d501(TObject *Sender);
    void __fastcall d601(TObject *Sender);
    void __fastcall d701(TObject *Sender);
    void __fastcall d801(TObject *Sender);
    void __fastcall d901(TObject *Sender);
    void __fastcall equ101(TObject *Sender);
    
    void __fastcall sqr101(TObject *Sender);
    void __fastcall min101(TObject *Sender);
    void __fastcall IQ101(TObject *Sender);
    void __fastcall Button301(TObject *Sender);
    void __fastcall msho101(TObject *Sender);
    void __fastcall mclr101(TObject *Sender);
    void __fastcall mpl101(TObject *Sender);
    void __fastcall mmin101(TObject *Sender);
    void __fastcall proc101(TObject *Sender);
    void __fastcall paint1(TObject *Sender);
    void __fastcall copy101(TObject *Sender);
    void __fastcall Wklej101(TObject *Sender);
private:	// User declarations
    float a_ratio;
    float f_ratio;
    bool dot;	//znaczik wcisniêcia kropki
public:		// User declarations
    __fastcall TErgoCalc(TComponent* Owner);
    double wy0;	//wynik obliczeñ
    double wy1;	//poprzedni wynik obliczeñ
    double mem; // pamiêæ
    int dz;
};
//---------------------------------------------------------------------------
extern PACKAGE TErgoCalc *ErgoCalc;
//---------------------------------------------------------------------------
#endif
