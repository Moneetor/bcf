//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "config1.h"
#include "newfield1.h"                                 
#include "faktor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfig *Config;
//---------------------------------------------------------------------------
__fastcall TConfig::TConfig(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfig::FormCreate(TObject *Sender)
{
    bit1=new Graphics::TBitmap();
    int i;
    font101->Clear();
    font102->Clear();
    for (i=1;i<=100 ;i++)
    {
        font101->Items->Add(IntToStr(i));
        font102->Items->Add(IntToStr(i));
    }
    FirstTime=true;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::bank101edChange(TObject *Sender)
{
    FaktorzData.Bank=bank101ed->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TConfig::bank102edChange(TObject *Sender)
{
    FaktorzData.Account=bank102ed->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TConfig::sell101mChange(TObject *Sender)
{
int c1,c2;
int i;
    c1=sell101m->Lines->Count;
    c2=FaktorzData.Seller.Name.size();
    if (c1!=c2)
    {
        FaktorzData.Seller.Name.resize(c1);
    }
    for (i=0;i<c1 ;i++)
    {
        FaktorzData.Seller.Name[i]=sell101m->Lines->Strings[i];
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::sell102mChange(TObject *Sender)
{
int c1,c2;
int i;
    c1=sell102m->Lines->Count;
    c2=FaktorzData.Seller.Adress.size();
    if (c1!=c2)
    {
        FaktorzData.Seller.Adress.resize(c1);
    }
    for (i=0;i<c1 ;i++)
    {
        FaktorzData.Seller.Adress[i]=sell102m->Lines->Strings[i];
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::zip1Change(TObject *Sender)
{
    FaktorzData.Seller.zip=zip1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::city1Change(TObject *Sender)
{
    FaktorzData.Seller.city=city1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::NIP1Change(TObject *Sender)
{
    FaktorzData.NIP=NIP1->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TConfig::REGON1Change(TObject *Sender)
{
    FaktorzData.REGON=REGON1->Text;    
}
//---------------------------------------------------------------------------


void __fastcall TConfig::logo101bClick(TObject *Sender)
{
    if (logo1d->Execute())
    {
        logo101->Picture->LoadFromFile(logo1d->FileName);
        FaktorzData.LogoFileName=logo1d->FileName;
        logo101ed->Text=FaktorzData.LogoFileName;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::font101Change(TObject *Sender)
{
    FaktorzData.HeaderFontSize=font101->ItemIndex+1;    
}
//---------------------------------------------------------------------------

void __fastcall TConfig::font102Change(TObject *Sender)
{
    FaktorzData.FontSize=font102->ItemIndex+1;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::al101Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].Alignment=taLeftJustify;
    }
}
//---------------------------------------------------------------------------




void __fastcall TConfig::al102Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].Alignment=taCenter;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::al103Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].Alignment=taRightJustify;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::b1Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].Bold=b1->Down;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::h1Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].Header=h1->Down;
    }
}
//---------------------------------------------------------------------------


void __fastcall TConfig::marg101edChange(TObject *Sender)
{
    FaktorzData.LeftMargin=marg101->Position;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::marg102edChange(TObject *Sender)
{
    FaktorzData.TopMargin=marg102->Position;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::marg103edChange(TObject *Sender)
{
    FaktorzData.RightMagin=marg103->Position;
}
//---------------------------------------------------------------------------

void __fastcall TConfig::marg104edChange(TObject *Sender)
{
    FaktorzData.BottomMargin=marg104->Position;
}
//---------------------------------------------------------------------------


void __fastcall TConfig::num101edChange(TObject *Sender)
{
    FaktorzData.LastNumber=num101->Position;
}
//---------------------------------------------------------------------------


void __fastcall TConfig::size10301Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].FixedHPos=size10301->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::size10401Click(TObject *Sender)
{
int i;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        FaktorzData.PrintFields[i].FixedVPos=size10401->Checked;
    }
}
//---------------------------------------------------------------------------


void __fastcall TConfig::ShowFieldParams(int Pos)
{
    TRect r1,r2;
    //DONE: Pokazuje Parametry pola
    SetFieldLimit(Pos);
    switch (FaktorzData.PrintFields[Pos].Alignment)
    {
      case taLeftJustify:
      {
        al101->Down=true;
      }
      break;
      case taCenter:
      {
        al102->Down=true;
      }
      break;
      case taRightJustify:
      {
        al103->Down=true;
      }
      break;
    }
    b1->Down=FaktorzData.PrintFields[Pos].Bold;
    h1->Down=FaktorzData.PrintFields[Pos].Header;
    vis1->Down=FaktorzData.PrintFields[Pos].Visible;
    FaktorzData.PrintFields[Pos].GetArea(r1);
    size101ed->OnChange=NULL;
    size102ed->OnChange=NULL;
    size103ed->OnChange=NULL;
    size104ed->OnChange=NULL;
    size101->Position=r1.Top;
    size102->Position=r1.Left;
    size103->Position=r1.Width();
    size104->Position=r1.Height();
    size101ed->OnChange=size101edChange;
    size102ed->OnChange=size102edChange;
    size103ed->OnChange=size103edChange;
    size104ed->OnChange=size104edChange;
    size10301->Checked=FaktorzData.PrintFields[Pos].FixedHPos;
    size10401->Checked=FaktorzData.PrintFields[Pos].FixedVPos;
}

void __fastcall TConfig::fl1Click(TObject *Sender)
{
    int i;
    if (!FaktorzData.PrintFields.empty())
    {
        i=fl1->ItemIndex;
        if (i>=0)
        {
            ShowFieldParams(i);
            DrawFields();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::Dodajpole1Click(TObject *Sender)
{
    TPrintField pf1;
    int i,c;
    NewField->Insert=true;
    if (FaktorzData.PrintFields.empty())
    {
        if (NewField->ShowModal()==mrOk)
        {
            pf1.FieldName=NewField->fn1->Text;
            FaktorzData.PrintFields.push_back(pf1);
        }
    }
    else
    {
        i=fl1->ItemIndex;
        c=FaktorzData.PrintFields.size();
        if (i<0)
            i=0;
        if (i>=c)
            i=c-1;
        pf1=FaktorzData.PrintFields[i];
        if (NewField->ShowModal()==mrOk)
        {
            pf1.FieldName=NewField->fn1->Text;
            FaktorzData.PrintFields.push_back(pf1);
        }
    }
    Clicked.push_back(fpOutside);
    UpdateList();
}
//---------------------------------------------------------------------------


void __fastcall TConfig::UpdateList(void)
{
    int i,j,c;
    //DONE: Update listy pól
    c=FaktorzData.PrintFields.size();
    if (c==0)
    {
        fl1->Clear();
        Usupole1->Enabled=false;
        Zmienazw1->Enabled=false;
        Panel4->Visible=false;
    }
    else
    {
        i=fl1->ItemIndex;
        if(i== -1)
        {
            i=0;
        }
        fl1->Clear();
        for (j=0;j<c ;j++)
        {
            fl1->Items->Add(FaktorzData.PrintFields[j].FieldName);
        }
        if (i>=fl1->Items->Count)
        {
            i=fl1->Items->Count;
        }
        fl1->ItemIndex=i;
        ShowFieldParams(i);
        Usupole1->Enabled=true;
        Zmienazw1->Enabled=true;
        Panel4->Visible=true;
    }
}

void __fastcall TConfig::Usupole1Click(TObject *Sender)
{
    int i;
    i=fl1->ItemIndex;
    if (i<0)
    {
        i=0;
    }
    FaktorzData.PrintFields.erase(FaktorzData.PrintFields.begin()+i);
    Clicked.resize(FaktorzData.PrintFields.size());
    UpdateList();
    if (FaktorzData.PrintFields.empty())
    {
        Usupole1->Enabled=false;
        Zmienazw1->Enabled=false;
    }
    else
    {
        Usupole1->Enabled=true;
        Zmienazw1->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::Zmienazw1Click(TObject *Sender)
{
    int i;
    i=fl1->ItemIndex;
    if (i<0)
    {
        i=0;
    }
    NewField->Insert=false;
    NewField->fn1->Text=FaktorzData.PrintFields[i].FieldName;
    if (NewField->ShowModal()==mrOk)
    {
        FaktorzData.PrintFields[i].FieldName=NewField->fn1->Text;
        UpdateList();
    }
}
//---------------------------------------------------------------------------
void TConfig::ApplyInterface(void)
{
    TStringList *s1=new TStringList();
    TRect r1;
    r1.Left=Faktorez->Printer1->Canvas->ClipRect.Left;
    r1.Top=Faktorez->Printer1->Canvas->ClipRect.Top;
    r1.Right=Faktorez->Printer1->Canvas->ClipRect.Right;
    r1.Bottom=Faktorez->Printer1->Canvas->ClipRect.Bottom;
    TPrintField pf1;
    int W,H;
    int i,c;
    //TODO: Ustawia interfejs
    pf1.SetResolution(Faktorez->Printer1->Canvas->Font->PixelsPerInch);
    pf1.SetPrintArea(r1);
    pf1.GetArea(r1);
    marg101->Max=r1.Width();
    marg102->Max=r1.Height();
    marg103->Max=r1.Width();
    marg104->Max=r1.Height();
    font101->ItemIndex=FaktorzData.HeaderFontSize-1;
    font102->ItemIndex=FaktorzData.FontSize-1;
    bank101ed->Text=FaktorzData.Bank;
    bank102ed->Text=FaktorzData.Account;
    s1->Clear();
    c=FaktorzData.Seller.Name.size();
    for (i=0;i<c ;i++)
    {
        s1->Add(FaktorzData.Seller.Name[i]);
    }
    sell101m->Lines->Assign(s1);
    s1->Clear();
    c=FaktorzData.Seller.Adress.size();
    for (i=0;i<c ;i++)
    {
        s1->Add(FaktorzData.Seller.Adress[i]);
    }
    sell102m->Lines->Assign(s1);
    zip1->Text=FaktorzData.Seller.zip;
    city1->Text=FaktorzData.Seller.city;
    NIP1->Text=FaktorzData.NIP;
    REGON1->Text=FaktorzData.REGON;
    try
    {
        logo101ed->Text=FaktorzData.LogoFileName;
        if (!FaktorzData.LogoFileName.IsEmpty())
        {
            logo101->Picture->LoadFromFile(FaktorzData.LogoFileName);
        }
    }
    catch(...)
    {
        ;
    }
    num101->Position=FaktorzData.LastNumber;
    delete s1;
    UpdateList();
    UpdateDSN();
    DrawFields();
}
void __fastcall TConfig::FormShow(TObject *Sender)
{
    XScale=fimg1->Width/(double)Faktorez->Printer1->PageWidth;
    YScale=fimg1->Height/(double)Faktorez->Printer1->PageHeight;
    if (FirstTime)
    {
        fimg1->Picture->Bitmap->Width=fimg1->Width;
        fimg1->Picture->Bitmap->Height=fimg1->Height;
        FirstTime=false;
    }
    ApplyInterface();
}
//---------------------------------------------------------------------------


void TConfig::DrawFields(void)
{
    TRect r1,r2;
    int i,c;
    int margins[4];
    int DPI;
    DPI=Faktorez->Printer1->Canvas->Font->PixelsPerInch;
    r1.Left=Faktorez->Printer1->Canvas->ClipRect.Left*XScale;
    r1.Top=Faktorez->Printer1->Canvas->ClipRect.Top*YScale;
    r1.Right=Faktorez->Printer1->Canvas->ClipRect.Right*XScale;
    r1.Bottom=Faktorez->Printer1->Canvas->ClipRect.Bottom*YScale;
    //papier
    bit1->Width=fimg1->Width;
    bit1->Height=fimg1->Height;
    bit1->Canvas->Pen->Color=clWhite;
    bit1->Canvas->Pen->Width=0;
    bit1->Canvas->Brush->Color=clWhite;
    bit1->Canvas->Rectangle(r1);
    if (FaktorzData.PrintFields.empty())
    {
        return;
    }
    c=FaktorzData.PrintFields.size();
    for (i=0;i<c ;i++)
    {
        FaktorzData.PrintFields[i].SetResolution(DPI);
    }
    //kreœli margines
    r2.Left=r1.Left+FaktorzData.PrintFields[0].mmToPixel(FaktorzData.LeftMargin,DPI)*XScale;
    r2.Top=r1.Top+FaktorzData.PrintFields[0].mmToPixel(FaktorzData.TopMargin,DPI)*YScale;
    r2.Right=r1.Right-FaktorzData.PrintFields[0].mmToPixel(FaktorzData.RightMagin,DPI)*XScale;
    r2.Bottom=r1.Bottom-FaktorzData.PrintFields[0].mmToPixel(FaktorzData.BottomMargin,DPI)*YScale;
    bit1->Canvas->Pen->Style=psDot;
    bit1->Canvas->Pen->Width=1;
    bit1->Canvas->Pen->Color=clBlack;
    bit1->Canvas->Rectangle(r2);
    //TODO: Kreœli pola na podgl¹dzie
    bit1->Canvas->Pen->Style=psSolid;
    bit1->Canvas->Pen->Width=2;
    bit1->Canvas->Brush->Color=clFuchsia;
    for (i=0;i<c ;i++)
    {
        if (!FaktorzData.PrintFields[i].Visible)
            continue;
        if (i==fl1->ItemIndex)
        {
            bit1->Canvas->Pen->Color=clBlue;
        }
        else
        {
            bit1->Canvas->Pen->Color=clBlack;
        }
        FaktorzData.PrintFields[i].GetPrintArea(r2);
        r2.Left*=XScale;
        r2.Top*=YScale;
        r2.Right*=XScale;
        r2.Bottom*=YScale;
        bit1->Canvas->Rectangle(r2);
    }
    fimg1->Picture->Bitmap->Canvas->Draw(0,0,bit1);
}



void __fastcall TConfig::size101edChange(TObject *Sender)
{
    int i,h;
    TRect r1;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        if (i<0)
            i=0;
        FaktorzData.PrintFields[i].GetArea(r1);
        h=r1.Height();
        r1.Top=size101->Position;
        r1.Bottom=r1.Top+h;
        FaktorzData.PrintFields[i].SetArea(r1);
        DrawFields();
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::size102edChange(TObject *Sender)
{
    int i,w;
    TRect r1;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        if (i<0)
            i=0;
        FaktorzData.PrintFields[i].GetArea(r1);
        w=r1.Width();
        r1.Left=size102->Position;
        r1.Right=r1.Left+w;
        FaktorzData.PrintFields[i].SetArea(r1);
        DrawFields();
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::size103edChange(TObject *Sender)
{
    int i;
    TRect r1;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        if (i<0)
            i=0;
        FaktorzData.PrintFields[i].GetArea(r1);
        r1.Right=r1.Left+size103->Position;
        FaktorzData.PrintFields[i].SetArea(r1);
        DrawFields();
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig::size104edChange(TObject *Sender)
{
    int i;
    TRect r1;
    if (FaktorzData.PrintFieldsCount()!=0)
    {
        i=fl1->ItemIndex;
        if (i<0)
            i=0;
        FaktorzData.PrintFields[i].GetArea(r1);
        r1.Bottom=r1.Top+size104->Position;
        FaktorzData.PrintFields[i].SetArea(r1);
        DrawFields();
    }
}
//---------------------------------------------------------------------------




void __fastcall TConfig::fimg1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    int i,c;
    TRect r1;
    TFieldPosition fp1;
    i=fl1->ItemIndex;
    c=Clicked.size();
    int dx,dy;
    int DPI;
    if (Shift.Contains(ssLeft))
    {
        DPI=FaktorzData.PrintFields[0].GetResolution();
        if (FaktorzData.PrintFields.empty())
        {
            fimg1->Cursor=crNo;
            return;
        }
        if (Clicked[i]==fpInside)
        {
            dx=X-LastPos.x;
            dy=Y-LastPos.y;
            dx/=XScale;
            dy/=YScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Left+=dx;
            r1.Right+=dx;
            r1.Top+=dy;
            r1.Bottom+=dy;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpRightBottomCorner)
        {
            dx=X-LastPos.x;
            dy=Y-LastPos.y;
            dx/=XScale;
            dy/=YScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Right+=dx;
            if (r1.Right<=r1.Left)
                r1.Right=r1.Left+1;
            r1.Bottom+=dy;
            if (r1.Bottom<=r1.Top)
                r1.Bottom=r1.Top+1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpLeftTopCorner)
        {
            dx=X-LastPos.x;
            dy=Y-LastPos.y;
            dx/=XScale;
            dy/=YScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Left+=dx;
            if (r1.Left>=r1.Right)
                r1.Left=r1.Right-1;
            r1.Top+=dy;
            ///dopisaæ
            if (r1.Top>=r1.Bottom)
                r1.Top=r1.Bottom-1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpRightTopCorner)
        {
            dx=X-LastPos.x;
            dy=Y-LastPos.y;
            dx/=XScale;
            dy/=YScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Right+=dx;
            if (r1.Right<=r1.Left)
                r1.Right=r1.Left+1;
            r1.Top+=dy;
            if (r1.Top>=r1.Bottom)
                r1.Top=r1.Bottom-1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpLeftBottomCorner)
        {
            dx=X-LastPos.x;
            dy=Y-LastPos.y;
            dx/=XScale;
            dy/=YScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Left+=dx;
            if (r1.Left>=r1.Right)
                r1.Left=r1.Right-1;
            r1.Bottom+=dy;
            if (r1.Bottom<=r1.Top)
                r1.Bottom=r1.Top+1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpLeftBorder)
        {
            dx=X-LastPos.x;
            dx/=XScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Left+=dx;
            if (r1.Left>=r1.Right)
                r1.Left=r1.Right-1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpRightBorder)
        {
            dx=X-LastPos.x;
            dx/=XScale;
            dx=FaktorzData.PrintFields[i].PixelTomm(dx,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Right+=dx;
            if (r1.Right<=r1.Left)
                r1.Right=r1.Left+1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpTopBorder)
        {
            dy=Y-LastPos.y;
            dy/=YScale;
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Top+=dy;
            if (r1.Top>=r1.Bottom)
                r1.Top=r1.Bottom-1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
        if (Clicked[i]==fpBottomBorder)
        {
            dy=Y-LastPos.y;
            dy/=YScale;
            dy=FaktorzData.PrintFields[i].PixelTomm(dy,DPI);
            FaktorzData.PrintFields[i]=LastField;
            FaktorzData.PrintFields[i].GetArea(r1);
            r1.Bottom+=dy;
            if (r1.Bottom<=r1.Top)
                r1.Bottom=r1.Top+1;
            FaktorzData.PrintFields[i].SetArea(r1);
            ShowFieldParams(i);
            DrawFields();
        }
    }
    else
    {
        fp1=GetCursorPositionOverField(i,X,Y);
        if (fp1==fpOutside)
        {
            GetCursorPositionOverFields(X,Y);
            for (i=0;i<c ;i++)
            {
                if (Clicked[i]==fpInside)
                {
                    fimg1->Cursor=crDefault;
                    return;
                }
            }
            fimg1->Cursor=crNo;
        }
        else
        {
            if (fp1==fpInside)
            {
                fimg1->Cursor=crSizeAll;
            }
            if ((fp1==fpLeftBorder)||(fp1==fpRightBorder))
            {
                fimg1->Cursor=crSizeWE;
            }
            if ((fp1==fpTopBorder)||(fp1==fpBottomBorder))
            {
                fimg1->Cursor=crSizeNS;
            }
            if ((fp1==fpLeftTopCorner)||(fp1==fpRightBottomCorner))
            {
                fimg1->Cursor=crSizeNWSE;
            }
            if ((fp1==fpLeftBottomCorner)||(fp1==fpRightTopCorner))
            {
                fimg1->Cursor=crSizeNESW;
            }
            return;
        }
    }
}
//---------------------------------------------------------------------------


TFieldPosition __fastcall TConfig::GetCursorPositionOverField(int num,int X,int Y)
{
    TRect r1,ri,ro;
    TFieldPosition fp1;
    int c;
    //TODO: Sprawdza pozycjê wzglêdem pola
    c=FaktorzData.PrintFields.size();
    if ((num<0)||(num>=c))
    {
        fp1=fpOutside;
        return fp1;
    }

    if ((num<c)&&(FaktorzData.PrintFields[num].Visible))
    {
        FaktorzData.PrintFields[num].GetPrintArea(r1);
        r1.Left*=XScale;
        r1.Top*=YScale;
        r1.Right*=XScale;
        r1.Bottom*=YScale;
        ri.Left=r1.Left+2;
        ri.Right=r1.Right-2;
        ri.Top=r1.Top+2;
        ri.Bottom=r1.Bottom-2;
        ro.Left=r1.Left-2;
        ro.Right=r1.Right+2;
        ro.Top=r1.Top-2;
        ro.Bottom=r1.Bottom+2;
        if ((X>ri.Left)&&(X<ri.Right)&&(Y>ri.Top)&&(Y<ri.Bottom))   //wewn¹trz
        {
            fp1=fpInside;
        }
        else
        {
            if (((X>=ro.Left)&&(X<=ri.Left)&&(Y>=ro.Top)&&(Y<=ro.Bottom))||
            ((X<=ro.Right)&&(X>=ri.Right)&&(Y>=ro.Top)&&(Y<=ro.Bottom))||
            ((Y>=ro.Top)&&(Y<=ri.Top)&&(X>=ro.Left)&&(X<=ro.Right))||
            ((Y<=ro.Bottom)&&(Y>=ri.Bottom)&&(X>=ro.Left)&&(X<=ro.Right)))   //naro¿niki lub krawêdzie
            {
                if (((X>=ro.Left)&&(X<=ri.Left))||
                (X<=ro.Right)&&(X>=ri.Right)) //szansa na naro¿niki
                {
                    if ((X>=ro.Left)&&(X<=ri.Left)) //lewa krawêdŸ
                    {
                        if ((Y>=ro.Top)&&(Y<=ri.Top))
                        {
                            fp1=fpLeftTopCorner;
                        }
                        if ((Y<=ro.Bottom)&&(Y>=ri.Bottom))
                        {
                            fp1=fpLeftBottomCorner;
                        }
                        if ((Y>ri.Top)&&(Y<ri.Bottom))
                        {
                            fp1=fpLeftBorder;
                        }
                    }
                    else    //prawa krawêdŸ
                    {
                        if ((Y>=ro.Top)&&(Y<=ri.Top))
                        {
                            fp1=fpRightTopCorner;
                        }
                        if ((Y<=ro.Bottom)&&(Y>=ri.Bottom))
                        {
                            fp1=fpRightBottomCorner;
                        }
                        if ((Y>ri.Top)&&(Y<ri.Bottom))
                        {
                            fp1=fpRightBorder;
                        }
                    }
                }
                else    //tylko krawêdzie
                {
                    if ((X>=ro.Left)&&(X<=ri.Left)) //lewa krawêdŸ
                    {
                        fp1=fpLeftBorder;
                    }
                    if ((X<=ro.Right)&&(X>=ri.Right)) //lewa krawêdŸ
                    {
                        fp1=fpRightBorder;
                    }
                    if ((Y>=ro.Top)&&(Y<=ri.Top))
                    {
                        fp1=fpTopBorder;
                    }
                    if ((Y<=ro.Bottom)&&(Y>=ri.Bottom))
                    {
                        fp1=fpBottomBorder;
                    }
                }
            }
            else
            {
                fp1=fpOutside;
            }
        }
    }
    else
        fp1=fpOutside;
    return fp1;
}


void __fastcall TConfig::GetCursorPositionOverFields(int X, int Y)
{
    int i,c;
    //TODO: Sprawdza pozycjê wzglêdem wszystkich pól
    c=FaktorzData.PrintFields.size();
    Clicked.resize(c);
    for (i=0;i<c ;i++)
    {
        Clicked[i]=GetCursorPositionOverField(i,X,Y);
    }
}
void __fastcall TConfig::fimg1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TFieldPosition fp1;
    int i,c;
    c=FaktorzData.PrintFields.size();
    if (Button==mbLeft)
    {
        LastPos.x=X;
        LastPos.y=Y;
        if (c>0)
        {
            i=fl1->ItemIndex;
            if (i<0)
                i=0;
            fp1=GetCursorPositionOverField(i,X,Y);
            if (fp1==fpOutside)
            {
                GetCursorPositionOverFields(X,Y);
                for (i=0;i<c ;i++)
                {
                    if (Clicked[i]==fpInside)
                    {
                        fl1->ItemIndex=i;
                        fl1Click(Sender);
                        GetCursorPositionOverFields(X,Y);
                        LastField=FaktorzData.PrintFields[i];
                    }
                }
            }
            else
            {
                GetCursorPositionOverFields(X,Y);
                LastField=FaktorzData.PrintFields[i];
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TConfig::SetFieldLimit(int Num)
{
    TRect r1,r2;
    int DPI;
    int c;
    //TODO: Add your source code here
    if (FaktorzData.PrintFields.empty())
    {
        return;
    }
    c=FaktorzData.PrintFields.size();
    if (Num<c)
    {
        DPI=FaktorzData.PrintFields[Num].GetResolution();
        r1.Left=FaktorzData.LeftMargin;
        r1.Top=FaktorzData.TopMargin;
        r1.Right=Faktorez->Printer1->PageWidth;
        r1.Right=FaktorzData.PrintFields[Num].PixelTomm(r1.Right,DPI)-
        FaktorzData.RightMagin;
        r1.Bottom=Faktorez->Printer1->PageHeight;
        r1.Bottom=FaktorzData.PrintFields[Num].PixelTomm(r1.Bottom,DPI)-
        FaktorzData.BottomMargin;
        FaktorzData.PrintFields[Num].GetArea(r2);
        if (r2.Left<r1.Left)
        {
            if (Clicked[Num]==fpInside)
                r2.Right=r1.Left+r2.Width();
            r2.Left=r1.Left;
        }
        if (r2.Right>r1.Right)
        {
            if (Clicked[Num]==fpInside)
                r2.Left=r1.Right-r2.Width();
            r2.Right=r1.Right;
        }
        if (r2.Top <r1.Top)
        {
            if (Clicked[Num]==fpInside)
                r2.Bottom=r1.Top+r2.Height();
            r2.Top=r1.Top;
        }
        if (r2.Bottom>r1.Bottom)
        {
            if (Clicked[Num]==fpInside)
                r2.Top=r1.Bottom-r2.Height();
            r2.Bottom=r1.Bottom;
        }
        FaktorzData.PrintFields[Num].SetArea(r2);
        size101->Min=r1.Top;
        size102->Min=r1.Left;
        size101->Max=r1.Bottom-1;
        size102->Max=r1.Right-1;
        size103->Max=r1.Right-r2.Left;
        size104->Max=r1.Bottom-r2.Top;
    }
}

void __fastcall TConfig::vis1Click(TObject *Sender)
{
    int i;
    if (FaktorzData.PrintFields.empty())
    {
        return;
    }
//    c=FaktorzData.PrintFields.size();
    i=fl1->ItemIndex;
    if (i<0)
        i=0;
    FaktorzData.PrintFields[i].Visible=vis1->Down;
    DrawFields();
}
//---------------------------------------------------------------------------




void __fastcall TConfig::find1Click(TObject *Sender)
{
    int i;
    int c;
    AnsiString tbuf1,tbuf2;
    FaktorzData.GetDatasources();
    UpdateDSN();
}
//---------------------------------------------------------------------------

void __fastcall TConfig::dsn1Click(TObject *Sender)
{
    int i,c;
    i=dsn1->ItemIndex;
    c=FaktorzData.Datasources.size();
    if ((i<0)||(i>=c))
    {
        FaktorzData.UsedDSN=-1;
        return;
    }
    eng1->Text=FaktorzData.Datasources[i].DBEngine;
    FaktorzData.UsedDSN=i;
    if (FaktorzData.Datasources[i].UseLogin)
    {
        login1->Visible=true;
        login1l->Visible=true;
        login1->Text=FaktorzData.Datasources[i].Login;
        if (FaktorzData.Datasources[i].UsePassword)
        {
            pas0->Visible=true;
            if (FaktorzData.Datasources[i].SavePassword)
            {
                pas3->Checked=true;
                pas1->Visible=true;
                pas1l->Visible=true;
                pas2->Visible=true;
                pas2l->Visible=true;
                pas1->Text=FaktorzData.Datasources[i].Password();
                pas2->Text=pas1->Text;
            }
            else
            {
                pas3->Checked=false;
                pas1->Visible=false;
                pas1l->Visible=false;
                pas2->Visible=false;
                pas2l->Visible=false;
                pas1->Text="";
                pas2->Text="";
            }
        }
        else
        {
            pas0->Visible=false;
            pas1->Visible=false;
            pas1l->Visible=false;
        }
    }
    else
    {
        login1->Visible=false;
        login1l->Visible=false;
        pas1->Visible=false;
        pas1l->Visible=false;
    }


}
//---------------------------------------------------------------------------

void __fastcall TConfig::del1Click(TObject *Sender)
{
    int i,c;
    c=FaktorzData.Datasources.size();
    i=dsn1->ItemIndex;
    if ((i<0)||(i>=c))
    {
        return;
    }
    else
    {
        FaktorzData.Datasources.erase(FaktorzData.Datasources.begin()+i);
    }
    UpdateDSN();
}

//---------------------------------------------------------------------------

void __fastcall TConfig::UpdateDSN(void)
{
    int i;
    int c;
    AnsiString tbuf1;
    //TODO:
    dsn1->Clear();
    if (FaktorzData.Datasources.empty())
    {
        dbp1->Visible=false;
        del1->Enabled=false;
        return;
    }
    else
    {
        c=FaktorzData.Datasources.size();
        for (i=0;i<c ;i++)
        {
            tbuf1=FaktorzData.Datasources[i].DSN;
            dsn1->Items->Add(tbuf1);
        }
        if ((FaktorzData.UsedDSN>=0)&&(FaktorzData.UsedDSN<c))
        {
            dsn1->ItemIndex=FaktorzData.UsedDSN;
        }
        else
        {
            if (FaktorzData.UsedDSN<0)
            {
                FaktorzData.UsedDSN=0;
            }
            else
            {
                FaktorzData.UsedDSN=c-1;
            }
            dsn1->ItemIndex=FaktorzData.UsedDSN;
        }
        dsn1Click(this);
        dbp1->Visible=true;
        del1->Enabled=true;
    }

}

void __fastcall TConfig::pas3Click(TObject *Sender)
{
    if (pas3->Checked)
    {
        FaktorzData.Datasources[FaktorzData.UsedDSN].SavePassword=true;
        pas1l->Visible=true;
        pas1->Visible=true;
        pas2->Visible=true;
        pas2l->Visible=true;
    }
    else
    {
        FaktorzData.Datasources[FaktorzData.UsedDSN].SavePassword=true;
        pas1l->Visible=false;
        pas1->Visible=false;
        pas2->Visible=false;
        pas2l->Visible=false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TConfig::pas1Change(TObject *Sender)
{
    if (pas1->Text==pas2->Text)
    {
        FaktorzData.Datasources[FaktorzData.UsedDSN].Password(pas1->Text);
        pas1->Color=clWindow;
        pas2->Color=clWindow;
    }
    else
    {
        pas1->Color=clRed;
        pas2->Color=clRed;
    }
}
//---------------------------------------------------------------------------

