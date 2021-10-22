//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "faktor.h"
#include "faktordata1.h"
#include "config1.h"
#include "scale.h"
#include "windowr.h"
#include "prtdialog1.h"
#include "prtdialog2.h"
#include "clientdata.h"
#include "clientlist1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//Mo¿liwoœæ oddzielenie kopii od faktur

TFaktorez *Faktorez;
//---------------------------------------------------------------------------
__fastcall TFaktorez::TFaktorez(TComponent* Owner)
    : TForm(Owner)
{
    AnsiString tbuf1;
    Printer1=Printer();
    tbuf1=GetCurrentDir()+"\\Faktorz.ini";
    IniFile=new TIniFile(tbuf1);
    brief=new Graphics::TBitmap();
    brief2=new Graphics::TBitmap();
}
//---------------------------------------------------------------------------
void __fastcall TFaktorez::Konfiguracja1Click(TObject *Sender)
{
    Faktorez->OnShow=NULL;
    try
    {
        Config->FaktorzData=FaktorzData;
        if (Config->ShowModal()==mrOk)
        {
            FaktorzData=Config->FaktorzData;
            FaktorzData.WindowS[0].GetWindowRectangle(Faktorez);
            DrawBrief();
        }
    }
    __finally
    {
        Faktorez->OnShow=FormShow;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::Koniec1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TFaktorez::FormShow(TObject *Sender)
{
    FaktorzData.ReadFromIni(IniFile,"Faktura");
    Scale.LoadFromIni(IniFile,"Skala");
    XScale=Image1->Width/(double)Faktorez->Printer1->PageWidth;
    YScale=Image1->Height/(double)Faktorez->Printer1->PageHeight;
    FaktorzData.WindowS[0].SetWindowRectangle(Faktorez);
    DrawScale();
    Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TFaktorez::Ustawieniawydruku1Click(TObject *Sender)
{
    if (PrinterSetupDialog1->Execute())
    {
        Printer1=Printer();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFaktorez::FormResize(TObject *Sender)
{
    brief->Width=Image1->Width;
    brief->Height=Image1->Height;
    Image1->Picture->Bitmap->Width=brief->Width;
    Image1->Picture->Bitmap->Height=brief->Height;
    DrawBrief();
    DrawScale();
}
//---------------------------------------------------------------------------



void __fastcall TFaktorez::DrawBrief(void)
{
    int i,j,c,c2;
    TRect r1,r2,r3;
    TRect r0;
    int xpos,ypos;
    TPoint p1;
    TScale FontScale;
    AnsiString tbuf1;
    FontScale.SetNominator(Printer1->Canvas->Font->PixelsPerInch);
    FontScale.SetDenominator(Image1->Canvas->Font->PixelsPerInch);
    r1.Left=brief->Canvas->ClipRect.Left;
    r1.Right=brief->Canvas->ClipRect.Right;
    r1.Top=brief->Canvas->ClipRect.Top;
    r1.Bottom=brief->Canvas->ClipRect.Bottom;
    brief->Canvas->Pen->Width=0;
    brief->Canvas->Brush->Color=clBtnShadow;
    brief->Canvas->Rectangle(r1);
    r2.Left=(Printer1->Canvas->ClipRect.Left)*Scale-DrawPos.x;
    r2.Right=(Printer1->Canvas->ClipRect.Right)*Scale-DrawPos.x;
    r2.Top=(Printer1->Canvas->ClipRect.Top)*Scale-DrawPos.y;
    r2.Bottom=(Printer1->Canvas->ClipRect.Bottom)*Scale-DrawPos.y;
    brief->Canvas->Brush->Color=clWhite;
    brief->Canvas->Rectangle(r2);
    c=FaktorzData.PrintFields.size();
    for (i=0;i<c ;i++)
    {
        FaktorzData.PrintFields[i].GetPrintArea(r1);
        r2.Left=(r1.Left*Scale)-DrawPos.x;
        r2.Right=(r1.Right*Scale)-DrawPos.x;
        r2.Top=(r1.Top*Scale)-DrawPos.y;
        r2.Bottom=(r1.Bottom*Scale)-DrawPos.y;
        brief2->Width=r1.Width();
        brief2->Height=r1.Height();
        brief2->Canvas->Brush->Style=bsSolid;
        brief2->Canvas->Font->Name="Arial";
        if (!FaktorzData.PrintFields[i].Visible)
        {
            continue;
        }
        if (FaktorzData.PrintFields[i].FieldName=="Logo")
        {
            try
            {
                brief2->LoadFromFile(FaktorzData.LogoFileName);
            }
            catch(...)
            {
                ;
            }
            brief->Canvas->StretchDraw(r2,brief2);
        }
        if (FaktorzData.PrintFields[i].FieldName=="Sprzedawca")
        {
            SetDrawFont(brief2->Canvas,i,false);
            brief2->Canvas->Pen->Width=0;
            brief2->Canvas->Pen->Color=clWhite;
            brief2->Canvas->Brush->Color=clWhite;
            r3.Left=0;
            r3.Top=0;
            r3.Right=r1.Width();
            r3.Bottom=r1.Height();
            brief2->Canvas->Rectangle(r3);
            brief2->Canvas->Brush->Style=bsClear;
            TextRect(brief2->Canvas,r3,0,"Sprzedawca",FaktorzData.PrintFields[i].Alignment);
            p1.x=0;
            p1.y=brief2->Canvas->TextHeight("Sprzedawca");
            brief2->Canvas->Font->Style=TFontStyles()<< fsBold;
            c2=FaktorzData.Seller.Name.size();
            for (j=0;j<c2 ;j++)
            {
                TextRect(brief2->Canvas,r3,p1.y,FaktorzData.Seller.Name[j],FaktorzData.PrintFields[i].Alignment);
                p1.y+=brief2->Canvas->TextHeight(FaktorzData.Seller.Name[j]);
            }
            if (FaktorzData.PrintFields[i].Bold)
                brief2->Canvas->Font->Style=TFontStyles()<< fsBold;
            else
                brief2->Canvas->Font->Style=TFontStyles();
            c2=FaktorzData.Seller.Adress.size();
            for (j=0;j<c2 ;j++)
            {
                TextRect(brief2->Canvas,r3,p1.y,FaktorzData.Seller.Adress[j],FaktorzData.PrintFields[i].Alignment);
                p1.y+=brief2->Canvas->TextHeight(FaktorzData.Seller.Adress[j]);
            }
            //kod pocztowy i miasto
            tbuf1=FaktorzData.Seller.zip+"  "+FaktorzData.Seller.city;
            TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
            p1.y+=brief2->Canvas->TextHeight(tbuf1);
            //NIP
            if (!FaktorzData.NIP.IsEmpty())
            {
                tbuf1="NIP: "+FaktorzData.NIP;
                TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=brief2->Canvas->TextHeight(tbuf1);
            }
            //REGON
            if (!FaktorzData.REGON.IsEmpty())
            {
                tbuf1="REGON: "+FaktorzData.REGON;
                TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=brief2->Canvas->TextHeight(tbuf1);
            }
            brief->Canvas->StretchDraw(r2,brief2);
        }
        if (FaktorzData.PrintFields[i].FieldName=="Bank")
        {
            SetDrawFont(brief2->Canvas,i,false);
            brief2->Canvas->Pen->Width=0;
            brief2->Canvas->Pen->Color=clWhite;
            brief2->Canvas->Brush->Color=clWhite;
            r3.Left=0;
            r3.Top=0;
            r3.Right=r1.Width();
            r3.Bottom=r1.Height();
            brief2->Canvas->Rectangle(r3);
            brief2->Canvas->Brush->Style=bsClear;
            p1.x=0;
            p1.y=0;
            //Bank
            if (!FaktorzData.Bank.IsEmpty())
            {
                tbuf1="Bank: "+FaktorzData.Bank;
                TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=brief2->Canvas->TextHeight(tbuf1);
                //konto
                if (!FaktorzData.Account.IsEmpty())
                {
                    tbuf1="Konto:  "+FaktorzData.Account;
                    TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=brief2->Canvas->TextHeight(tbuf1);
                }
            }
            brief->Canvas->StretchDraw(r2,brief2);
        }
        if (FaktorzData.PrintFields[i].FieldName=="Faktura")
        {
            SetDrawFont(brief2->Canvas,i,false);
            brief2->Canvas->Pen->Width=0;
            brief2->Canvas->Pen->Color=clWhite;
            brief2->Canvas->Brush->Color=clWhite;
            r3.Left=0;
            r3.Top=0;
            r3.Right=r1.Width();
            r3.Bottom=r1.Height();
            brief2->Canvas->Rectangle(r3);
            brief2->Canvas->Brush->Style=bsClear;
            p1.x=0;
            p1.y=0;
            //Faktura
            tbuf1="Faktura VAT nr ";
            TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
            brief->Canvas->StretchDraw(r2,brief2);
        }
        if (FaktorzData.PrintFields[i].FieldName=="Kopia")
        {
            SetDrawFont(brief2->Canvas,i,false);
            brief2->Canvas->Pen->Width=0;
            brief2->Canvas->Pen->Color=clWhite;
            brief2->Canvas->Brush->Color=clWhite;
            r3.Left=0;
            r3.Top=0;
            r3.Right=r1.Width();
            r3.Bottom=r1.Height();
            brief2->Canvas->Rectangle(r3);
            brief2->Canvas->Brush->Style=bsClear;
            p1.x=0;
            p1.y=0;
            //Kopia/orygina³
            tbuf1="ORYGINA£";
            TextRect(brief2->Canvas,r3,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
            brief->Canvas->StretchDraw(r2,brief2);
        }
    }
    Image1->Canvas->Draw(0,0,brief);
}

void __fastcall TFaktorez::TextRect(TCanvas * Canvas, TRect Rect, int Y, AnsiString Text,TAlignment Alignment)
{
    int X;
    int xsize,ysize;
    //DONE: Pisze
    xsize=Canvas->TextWidth(Text);
    switch (Alignment)
    {
        case taLeftJustify:
        {
            X=Rect.Left;
        }
        break;
        case taCenter:
        {
            X=(Rect.Width()-xsize)/2;
            X+=Rect.Left;
            if (X<Rect.Left)
                X=Rect.Left;
        }
        break;
        case taRightJustify:
        {
            X=Rect.Right-xsize;
            if (X<Rect.Left)
                X=Rect.Left;
        }
        break;
    }
    Canvas->TextRect(Rect,X,Y,Text);
}



void __fastcall TFaktorez::zoom1Click(TObject *Sender)
{
    TScale sc1=TScale(2,1);
    if (Scale<16)
    {
        Scale*=sc1;
        zoom2->Enabled=true;
        if (Scale.GetNominator()>=16)
        {
            zoom1->Enabled=false;
        }
        FormResize(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::zoom2Click(TObject *Sender)
{
    TScale sc1=TScale(1,2);
    if (Scale>0.0625)
    {
        Scale*=sc1;
        zoom1->Enabled=true;
        if (Scale.GetDenominator()>=16)
        {
            zoom2->Enabled=false;
        }
        FormResize(Sender);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFaktorez::DrawScale(void)
{
    int n,d;
    //DONE: Wyœwietla skalê na pasku tytu³u
    n=Scale.GetNominator();
    d=Scale.GetDenominator();
    Caption="Faktorez [skala "+IntToStr(n)+":"+IntToStr(d)+"] ["+IntToStr(DrawPos.x)+" "+IntToStr(DrawPos.y)+"]";
}

void __fastcall TFaktorez::zoom3Click(TObject *Sender)
{
    Scale.Reset();
    zoom1->Enabled=true;
    zoom2->Enabled=true;
    FormResize(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TFaktorez::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssRight))
    {
        ClickPos.x=X;
        ClickPos.y=Y;
        Image1->Cursor=crHandPoint;
    }
}

//---------------------------------------------------------------------------
void __fastcall TFaktorez::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    int dx,dy;
    if (Shift.Contains(ssRight))
    {
        dx=ClickPos.x-X;
        dy=ClickPos.y-Y;
        DrawPos.x=LastPos.x+dx;
        DrawPos.y=LastPos.y+dy;
        DrawScale();
    }
}

//---------------------------------------------------------------------------
void __fastcall TFaktorez::Image1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

    FormResize(Sender);
    LastPos.x=DrawPos.x;
    LastPos.y=DrawPos.y;
    Image1->Cursor=crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::N1001Click(TObject *Sender)
{
    N1001->Checked=true;    
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::Drukuj1Click(TObject *Sender)
{
    Printer1->BeginDoc();
    Printer1->Canvas->Font->Name="Arial";
    try
    {
        PrintCopy(Printer1,false);
        Printer1->NewPage();
        PrintCopy(Printer1,true);
        Printer1->EndDoc();
    }
    catch(...)
    {
        Printer1->Abort();
        ShowMessage("Drukowanie zakoñczone niepowodzeniem");
    }
}

//---------------------------------------------------------------------------


void __fastcall TFaktorez::PrintCopy(TPrinter * Printer, bool copy)
{
    TRect r1,r2;
    TRectWrapper r3,r4;
    int i,j,c,c2;
    int days;
    vector<TPrintField> ActualPrintFields;
    TPoint p1;
    AnsiString tbuf1;
    vector<AnsiString> DoZaplaty;
    DoZaplaty.resize(4);
    int space;
    int diff;
    int DPI;
    int brutto;
    int size;
    //DONE: Drukowanie kopii lub orygina³u
    try
    {
        c=FaktorzData.PrintFields.size();
        ActualPrintFields.resize(c);
        ActualPrintFields=FaktorzData.PrintFields;
        for (i=0;i<c ;i++)
        {
            FaktorzData.PrintFields[i].GetPrintArea(r1);
            if (FaktorzData.PrintFields[i].FieldName=="Logo")
            {
                try
                {
                    brief2->LoadFromFile(FaktorzData.LogoFileName);
                }
                catch(...)
                {
                    ;
                }
                Printer1->Canvas->StretchDraw(r1,brief2);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Sprzedawca")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                TextRect(Printer1->Canvas,r1,p1.y,"Sprzedawca",FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight("Sprzedawca");
                Printer1->Canvas->Font->Style=TFontStyles()<< fsBold;
                c2=FaktorzData.Seller.Name.size();
                for (j=0;j<c2 ;j++)
                {
                    TextRect(Printer1->Canvas,r1,p1.y,FaktorzData.Seller.Name[j],FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(FaktorzData.Seller.Name[j]);
                }
                if (FaktorzData.PrintFields[i].Bold)
                    Printer1->Canvas->Font->Style=TFontStyles()<< fsBold;
                else
                    Printer1->Canvas->Font->Style=TFontStyles();
                c2=FaktorzData.Seller.Adress.size();
                for (j=0;j<c2 ;j++)
                {
                    TextRect(Printer1->Canvas,r1,p1.y,FaktorzData.Seller.Adress[j],FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(FaktorzData.Seller.Adress[j]);
                }
                //kod pocztowy i miasto
                tbuf1=FaktorzData.Seller.zip+"  "+FaktorzData.Seller.city;
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                //NIP
                if (!FaktorzData.NIP.IsEmpty())
                {
                    tbuf1="NIP: "+FaktorzData.NIP;
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                }
                //REGON
                if (!FaktorzData.REGON.IsEmpty())
                {
                    tbuf1="REGON: "+FaktorzData.REGON;
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                }
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Bank")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                //Bank
                if (!FaktorzData.Bank.IsEmpty())
                {
                    tbuf1="Bank:  "+FaktorzData.Bank;
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                    if (!FaktorzData.Account.IsEmpty())
                    {
                        tbuf1="Konto:  "+FaktorzData.Account;
                        TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                        p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                    }
                }
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Faktura")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                //Faktura
                tbuf1="Faktura VAT nr "+IntToStr(Faktura.Number)+"/";
                tbuf1=tbuf1+Faktura.DataWyst.FormatString("mm'/'yyyy");
                if (!Faktura.Ext.IsEmpty())
                {
                    tbuf1=tbuf1+"/"+Faktura.Ext;
                }
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Kopia")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                //Kopia
                if (copy)
                    tbuf1="KOPIA";
                else
                    tbuf1="ORYGINA£";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if(FaktorzData.PrintFields[i].FieldName=="Towary")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                ItemsRect(Printer1->Canvas,r1,p1.y,"",ActualPrintFields[i].Alignment,Faktura);
                p1.y=r1.Bottom;
                r3=r1;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if(FaktorzData.PrintFields[i].FieldName=="Nabywca")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                TextRect(Printer1->Canvas,r1,p1.y,"Nabywca",FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight("Nabywca");
                Printer1->Canvas->Font->Style=TFontStyles()<< fsBold;
                c2=Faktura.Buyer.Name.size();
                for (j=0;j<c2 ;j++)
                {
                    TextRect(Printer1->Canvas,r1,p1.y,Faktura.Buyer.Name[j],FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(Faktura.Buyer.Name[j]);
                }
                if (FaktorzData.PrintFields[i].Bold)
                    Printer1->Canvas->Font->Style=TFontStyles()<< fsBold;
                else
                    Printer1->Canvas->Font->Style=TFontStyles();
                c2=Faktura.Buyer.Adress.size();
                for (j=0;j<c2 ;j++)
                {
                    TextRect(Printer1->Canvas,r1,p1.y,Faktura.Buyer.Adress[j],FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(Faktura.Buyer.Adress[j]);
                }
                //kod pocztowy i miasto
                tbuf1=Faktura.Buyer.zip+"  "+Faktura.Buyer.city;
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                if (!Faktura.NIP.IsEmpty())
                {
                    tbuf1="NIP: "+Faktura.NIP;
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                }
                //REGON
                if (!Faktura.REGON.IsEmpty())
                {
                    tbuf1="REGON: "+Faktura.REGON;
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                    p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                }
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if(FaktorzData.PrintFields[i].FieldName=="Data sprzeda¿y")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                tbuf1="Data wystawienia:";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,taLeftJustify);
                tbuf1=Faktura.DataWyst.FormatString("dd/mm/yyyy");
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,taRightJustify);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if(FaktorzData.PrintFields[i].FieldName=="Miesi¹c sprzeda¿y")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                tbuf1="Miesi¹c sprzeda¿y:";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,taLeftJustify);
                tbuf1=Faktura.DataWyst.FormatString("mm/yyyy");
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,taRightJustify);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Zap³ata")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                tbuf1="Forma p³atnoœci:  "+Faktura.Platnosc;
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                if (Faktura.DataSprz==Faktura.DataZapl)
                {
                    tbuf1="ZAP£ACONO";
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                }
                else
                {
                    days=((int)Faktura.DataZapl-(int)Faktura.DataSprz);
                    tbuf1="Termin p³atnoœci: "+IntToStr(days)+"dni, tj. do "+
                    Faktura.DataZapl.FormatString("dd/mm/yyyy");
                    TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                }
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Podpis sprzedawcy")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                tbuf1="Podpis osoby uprawnionej";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                tbuf1="do wystawienia faktury";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y=r1.Bottom-Printer1->Canvas->TextHeight(tbuf1);
                tbuf1=".......................................";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Podpis odbiorcy")
            {
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r1.Left;
                p1.y=r1.Top;
                Printer1->Canvas->Brush->Style=bsClear;
                tbuf1="Podpis osoby uprawnionej";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                tbuf1="do odbioru faktury";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y=r1.Bottom-Printer1->Canvas->TextHeight(tbuf1);
                tbuf1=".......................................";
                TextRect(Printer1->Canvas,r1,p1.y,tbuf1,FaktorzData.PrintFields[i].Alignment);
                p1.y+=Printer1->Canvas->TextHeight(tbuf1);
                r3=r1;
                r3.Rect.Bottom=p1.y;
                ActualPrintFields[i].SetPrintArea(r3.Rect);
            }
            if (FaktorzData.PrintFields[i].FieldName=="Rozliczenia podatków")
            {
                j=FaktorzData.FieldNumber("Towary");
                FaktorzData.PrintFields[j].GetPrintArea(r2);
                r3=r2;
                ActualPrintFields[j].GetPrintArea(r2);
                r4=r2;
                diff=r4.Rect.Bottom-r3.Rect.Bottom;
                ActualPrintFields[i].GetPrintArea(r2);
                r4=r2;
                r4.Move(0,diff);
                ActualPrintFields[i].SetPrintArea(r4.Rect);
                //parametry tekstu i obszaru drukowania rozliczenia
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r4.Rect.Left;
                p1.y=r4.Rect.Top;
                r4.Move(0,Printer1->Canvas->TextHeight(tbuf1)*2);
                Printer1->Canvas->Brush->Style=bsClear;
                TaxesRect(Printer1->Canvas,r4.Rect,p1.y,ActualPrintFields[i].Alignment,Faktura);
                /* TODO : Rozliczenie podatków */
            }
            if (FaktorzData.PrintFields[i].FieldName=="Do zap³aty")
            {
                j=FaktorzData.FieldNumber("Rozliczenia podatków");
                FaktorzData.PrintFields[j].GetPrintArea(r2);
                r3=r2;
                ActualPrintFields[j].GetPrintArea(r2);
                r4=r2;
                diff=r4.Rect.Bottom-r3.Rect.Bottom;
                ActualPrintFields[i].GetPrintArea(r2);
                r4=r2;
                r4.Move(0,diff);
                ActualPrintFields[i].SetPrintArea(r4.Rect);
                //parametry tekstu i obszaru drukowania rozliczenia
                SetDrawFont(Printer1->Canvas,i,true);
                p1.x=r4.Rect.Left;
                p1.y=r4.Rect.Top;
                r4.Move(0,Printer1->Canvas->TextHeight(tbuf1)*2);
                Printer1->Canvas->Brush->Style=bsClear;
                DoZaplaty[0]="Do Zap³aty:";
                DoZaplaty[1]=Faktura.TaxBruttoSum();
                DoZaplaty[2]="S³ownie:";
                DoZaplaty[3]=Faktura.SpellValue();
                DPI=FaktorzData.PrintFields[i].GetResolution();
                space=FaktorzData.PrintFields[i].mmToPixel(10,DPI);
                Printer1->Canvas->Font->Style=TFontStyles()<<fsBold;
                r4.Center(p1);
                p1.y=r4.Rect.Top;
                p1.x+=space;
                //Kwota cyframi
                Printer1->Canvas->TextRect(r4.Rect,p1.x,p1.y,DoZaplaty[1]);
                //Opis dla kwoty cyframi
                SetDrawFont(Printer1->Canvas,i,true);
                size=Printer1->Canvas->TextWidth(DoZaplaty[0])+space;
                p1.x-=size;
                Printer1->Canvas->TextRect(r4.Rect,p1.x,p1.y,DoZaplaty[0]);
                p1.x+=size;
                size=Printer1->Canvas->TextHeight(DoZaplaty[0])*12/10;
                //drugi wiersz
                p1.y+=size;
                //kwota s³ownie
                Printer1->Canvas->TextRect(r4.Rect,p1.x,p1.y,DoZaplaty[3]);
                size=Printer1->Canvas->TextWidth(DoZaplaty[2])+space;
                p1.x-=size;
                Printer1->Canvas->TextRect(r4.Rect,p1.x,p1.y,DoZaplaty[2]);
            }
        }
    }
    catch(...)
    {
        throw;
    }
}

void __fastcall TFaktorez::FormClose(TObject *Sender, TCloseAction &Action)
{
    OnResize=NULL;
    Scale.SaveToIni(IniFile,"Skala");
    FaktorzData.WindowS[0].GetWindowRectangle(Faktorez);
    FaktorzData.SaveToIni(IniFile,"Faktura");
    Database1->CloseDataSets();
    Database1->Connected=false;
}

//---------------------------------------------------------------------------

void __fastcall TFaktorez::SetDrawFont(TCanvas * Canvas, int num,bool paper)
{
    TScale FontScale;
    //DONE: Ustawia czcionkê, któr¹ kreœli
    if (paper)
    {
        if (FaktorzData.PrintFields[num].Header)
            Printer1->Canvas->Font->Size=FaktorzData.HeaderFontSize;
        else
            Printer1->Canvas->Font->Size=FaktorzData.FontSize;
    }
    else
    {
        FontScale.SetNominator(Printer1->Canvas->Font->PixelsPerInch);
        FontScale.SetDenominator(Image1->Canvas->Font->PixelsPerInch);
        if (FaktorzData.PrintFields[num].Header)
            Canvas->Font->Size=FaktorzData.HeaderFontSize*FontScale;
        else
            Canvas->Font->Size=FaktorzData.FontSize*FontScale;
    }
    if (FaktorzData.PrintFields[num].Bold)
        Printer1->Canvas->Font->Style=TFontStyles()<< fsBold;
    else
        Printer1->Canvas->Font->Style=TFontStyles();
}

void __fastcall TFaktorez::Timer1Timer(TObject *Sender)
{
    vector<AnsiString> argv;
    argv.resize(__argc);
    int i,c,l;
    AnsiString tbuf1,tbuf2,arg1;
    //parsuje liniê komend
    Timer1->Enabled=false;
    for (i=0;i<__argc ;i++)
    {
        argv[i]=__argv[i];
    }
    argv.erase(argv.begin(),argv.begin()+1);
    c=argv.size();
    for (i=0;i<c ;i++)
    {
        //u¿yj bazy danych wsadowo
        if (argv[i]=="-d")
        {
            Mode|=0x01;
        }
        if (argv[i]=="--KP")
        {
            Mode|=0x02;
        }
        if (argv[i]=="--FV")
        {
            Mode|=0x04;
        }
        if (argv[i]=="-s")
        {
            tbuf1=argv[++i];
            StartKP=StrToInt(tbuf1);
        }
        if (argv[i]=="-e")
        {
            tbuf1=argv[++i];
            EndKP=StrToInt(tbuf1);
        }
        if ((argv[i]=="-u")&&(FirstRun))
        {
            Database1->Params->Clear();
            tbuf1="USER NAME="+argv[++i];
            Database1->Params->Add(tbuf1);
        }
        tbuf1=argv[i];
        arg1=tbuf1.SubString(1,2);
        if ((arg1=="-p")&&(FirstRun))
        {
            l=tbuf1.Length();
            l-=2;
            tbuf2=tbuf1.SubString(3,l);
            tbuf1="PASSWORD="+tbuf2;
            Database1->Params->Add(tbuf1);
            Database1->LoginPrompt=false;
        }
    }
    if (Mode&0x01)
    {
        SetDatabase();
        if (!TestDatabase())
        {
            //Druga szansa na po³¹czenie
            if (!TestDatabase())
            {
                return;
            }
            if (Mode&0x02)
                PrintKP(StartKP,EndKP);
            if (Mode&0x04)
                MassPrint();
        }
        else
        {
            if (Mode&0x02)
                PrintKP(StartKP,EndKP);
            if (Mode&0x04)
                MassPrint();
        }
    }
}
//---------------------------------------------------------------------------


void TFaktorez::SetDatabase(void)
{
    //DONE: Ustawia parametry bazy danych
    Database1->Params->Clear();
    int i,c,l;
    AnsiString tbuf1,tbuf2;

    if (FaktorzData.Datasources.empty())
    {
        return;
    }
    Database1->Connected=false;
    Database1->AliasName=
    FaktorzData.Datasources[FaktorzData.UsedDSN].DSN;
    if (FaktorzData.Datasources[FaktorzData.UsedDSN].UseLogin)
    {
        Database1->LoginPrompt=true;
        tbuf2=FaktorzData.Datasources[FaktorzData.UsedDSN].Login;
        tbuf1="USER NAME="+tbuf2;
        Database1->Params->Clear();
        Database1->Params->Add(tbuf1);
        if (FaktorzData.Datasources[FaktorzData.UsedDSN].UsePassword)
        {
            if (FaktorzData.Datasources[FaktorzData.UsedDSN].SavePassword)
            {
                tbuf2=FaktorzData.Datasources[FaktorzData.UsedDSN].Password();
                tbuf1="PASSWORD="+tbuf2;
                Database1->Params->Add(tbuf1);
                Database1->LoginPrompt=false;
            }
        }
        else
            Database1->LoginPrompt=false;
    }
    else
    {
        Database1->LoginPrompt=false;
    }
}

bool TFaktorez::TestDatabase(void)
{
    //DONE: Testuje czy da siê po³¹czyæ...
    try
    {
        Database1->Connected=true;
        if (Query1->Active)
        {
            Query1->Close();
        }
        Query1->Fields->Clear();
        Query1->Prepare();
        if (Query2->Active)
        {
            Query2->Close();
        }
        Query2->Fields->Clear();
        Query2->Prepare();
        Query1->Open();
        if (Query1->RecordCount==0)
        {
            return false;
        }
        Query2->Open();
        if (Query2->RecordCount==0)
        {
            return false;
        }
        return(true);
    }
    catch(Exception & Exception)
    {
        Application->ShowException(&Exception);
        Database1->LoginPrompt=true;
        return(false);
    }
}

void TFaktorez::MassPrint(void)
{
    //TODO: Masowe Drukowanie
    if (Query1->IsEmpty())
    {
        return;
    }
    if (PrintMassDialog->ShowModal()==mrOk)
    {
        MassPrinter=new TMassPrinter(true);
        MassPrinter->OnTerminate=OnStopPrint;
        MassPrinter->FreeOnTerminate=true;
        MassPrinter->Resume();
        PrintMassDialog2->Show();
    }
}

void __fastcall TFaktorez::StatusBar1Resize(TObject *Sender)
{
    StatusBar1->Panels->Items[1]->Width=StatusBar1->ClientWidth-300;
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::OnStopPrint(TObject * Sender)
{
    //TODO: Kiedy anulujemy drukowanie
    Close();
}

void __fastcall TFaktorez::ItemsRect(TCanvas * Canvas, TRect &Rect, int Y, AnsiString Text, TAlignment Alignment,TDocumentData DocumentData)
{
    TRectWrapper r1;
    vector<vector<TRectWrapper> > Sizes;
    vector<vector<AnsiString> > TxtValues;
    vector<vector<TAlignment> > AlignTable;
    vector<AnsiString> TxtRow;
    vector<TRectWrapper> SizesRow;
    vector<TAlignment> AlignRow;
    int MaxWidths[11];
    int MinWidths[11];
    int extr;
    int diff,sum;
    vector<int> LinesUsed;
    vector<AnsiString> txtbuf;
    vector<AnsiString> Column;
    int iter;
    int i,j,k,l;
    int c,c2;
    AnsiString spacja=" ";
    AnsiString tbuf1;
    AnsiString undo;
    //TODO: Drukowanie artyku³ów
    TxtRow.resize(11);
    c=DocumentData.ItemCount();
    TxtValues.resize(c,TxtRow);
    //Powbieranie danych
    for (i=0,j=1;i<c ;i++,j++)
    {
        TxtValues[i][0]=IntToStr(j);
        TxtValues[i][1]=DocumentData.Name(i);
        TxtValues[i][2]=DocumentData.PKWIU(i);
        TxtValues[i][3]=DocumentData.Quantity(i);
        TxtValues[i][4]=DocumentData.jm(i);
        TxtValues[i][5]=DocumentData.Rabat(i);
        TxtValues[i][6]=DocumentData.Price(i);
        TxtValues[i][7]=DocumentData.Netto(i);
        TxtValues[i][8]=DocumentData.VATP(i);
        TxtValues[i][9]=DocumentData.VAT(i);
        TxtValues[i][10]=DocumentData.Brutto(i);
    }
    LinesUsed.resize(c,1);
    TxtRow[0]="L.P.";
    TxtRow[1]="Nazwa";
    TxtRow[2]="PKWiU";
    TxtRow[3]="Iloœæ";
    TxtRow[4]="J.m.";
    TxtRow[5]="Rabat";
    TxtRow[6]="Cena";
    TxtRow[7]="Wartoœæ";
    TxtRow[8]="VAT";
    TxtRow[9]="Kwota";
    TxtRow[10]="Wartoœæ";
    TxtValues.insert(TxtValues.begin(),TxtRow);
    TxtRow.assign(11,(AnsiString)"");
    TxtRow[6]="netto";
    TxtRow[7]="netto";
    TxtRow[9]="VAT";
    TxtRow[10]="brutto";
    TxtValues.insert(TxtValues.begin()+1,TxtRow);
    //weryfikacja szerokoœci
    c+=2;
    r1.Rect.Left=Rect.Left;
    r1.Rect.Top=Rect.Top;
    r1.Rect.Bottom=r1.Rect.Top+(Canvas->TextHeight("yfŒ")*12/10);
    r1.Rect.Right=r1.Rect.Left+Canvas->TextWidth(TxtValues[0][0])+
    r1.Rect.Height();
    SizesRow.resize(11,r1);
    Sizes.resize(c,SizesRow);
    //wpisywanie szerokoœci wychodz¹cych z szerokoœci tekstu z marginesem 0.5em
    for (i=1;i<11 ;i++)
    {
        SizesRow[i].Rect.Left=SizesRow[i-1].Rect.Right;
        SizesRow[i].Rect.Right=SizesRow[i].Rect.Left+Canvas->TextWidth(TxtValues[0][i])+
        SizesRow[i].Rect.Height();
    }
    Sizes.assign(c,SizesRow);
    for (i=1;i<c ;i++)
    {
        r1.Rect.top=SizesRow[0].Rect.bottom;
        r1.Rect.bottom=SizesRow[0].Rect.Height()+r1.Rect.Top;
        r1.Rect.Right=Canvas->TextWidth(TxtValues[i][0])+
        r1.Rect.Height();
        SizesRow.assign(11,r1);
        Sizes[i]=SizesRow;
        for (j=1;j<11 ;j++)
        {
            Sizes[i][j].Rect.Left=Sizes[i][j-1].Rect.Right;
            Sizes[i][j].Rect.Right=
            Sizes[i][j].Rect.Left+Canvas->TextWidth(TxtValues[i][j])+
            Sizes[i][j].Rect.Height();
        }
    }
    //wyrównywanie szerokoœci
    //znajdywanie ekstremów
    for (i=0;i<11 ;i++)
    {
        MaxWidths[i]=Sizes[0][i].Rect.Width();
        MinWidths[i]=MaxWidths[i];
        for (j=0;j<c ;j++)
        {
            extr=Sizes[j][i].Rect.Width();
            if (extr>MaxWidths[i])
            {
                MaxWidths[i]=extr;
            }
            if (extr<MinWidths[i])
            {
                MinWidths[i]=extr;
            }
        }
    }
    for (i=0;i<11 ;i++)
    {
        if (i==0)
        {
            Sizes[0][i].Rect.Right=Sizes[0][i].Rect.Left+MaxWidths[i];
        }
        else
        {
            Sizes[0][i].Rect.Left=Sizes[0][i-1].Rect.Right;
            Sizes[0][i].Rect.Right=Sizes[0][i].Rect.Left+MaxWidths[i];
        }
    }
    for (i=1;i<c ;i++)
    {
        for (j=0;j<11 ;j++)
        {
            Sizes[i][j].Rect.Left=Sizes[0][j].Rect.Left;
            Sizes[i][j].Rect.Right=Sizes[0][j].Rect.Right;
        }
    }
    sum=0;
    for (i=0;i<11 ;i++)
    {
        sum+=MaxWidths[i];
    }
    diff=Rect.Width()-sum;
    if (diff)
    {
        if (diff<0) //wsio jest szersze od okna
        {
            for (i=0;i<c ;i++)
            {
                //sprawdzenie, czy tekst zmieœci siê w komórce
                txtbuf.resize(1,TxtValues[i][1]);
                extr=Canvas->TextWidth(TxtValues[i][1]);
                if (extr>(MaxWidths[1]+diff))
                {
                    //zawijanie
                    //ciêcie na oddzielne wyrazy
                    DocumentData.Buyer.Explode(txtbuf,spacja);
                    //teraz szukamy najszerszego wyra¿enia, jakie mo¿emy wstawiæ w komórkê
                    j=0;
                    c2=txtbuf.size();
                    //sk³adanie czêœci zdania do kupy
                    while ((j<c2)&&(j<100))
                    {
                        if(c2<2)
                            break;
                        tbuf1=txtbuf[j]+" "+txtbuf[j+1];
                        extr=Canvas->TextWidth(tbuf1);
                        //resetowanie i limitowanie iteracji
                        iter=0;
                        while ((extr<(MaxWidths[1]+diff))&&(iter<50))
                        {
                            //dorzucanie kolejnych wyrazów
                            //dopóki nie przekroczy rozmiaru komórki
                            txtbuf.erase(txtbuf.begin()+(j+1));
                            c2=txtbuf.size();
                            if ((j+1)>=c2)
                            {
                                break;
                            }
                            else
                            {
                                undo=tbuf1;
                                tbuf1=tbuf1+" "+txtbuf[j+1];
                            }
                            extr=Canvas->TextWidth(tbuf1);
                            iter++;
                        }
                        if (extr<(MaxWidths[1]+diff))
                        {
                            txtbuf[j]=tbuf1;
                        }
                        else
                        {
                            txtbuf[j]=undo;
                        }
                        j++;
                        //nastêpna linia
                    }
                    //zdanie podzielone - Teraz mo¿na dodaæ linie
                    Column.insert(Column.end(),txtbuf.begin(),txtbuf.end());
                    LinesUsed[i]=txtbuf.size();
                }
                else
                {
                    //nie musimy zawijaæ
                    Column.push_back(TxtValues[i][1]);
                }
                //ostateczne okreœlanie szerokoœci kolumn
                for (j=1;j<11 ;j++)
                {
                    if (j==1)
                    {
                        Sizes[i][j].Rect.Right+=diff;
                    }
                    else
                    {
                        Sizes[i][j].Rect.Right+=diff;
                        Sizes[i][j].Rect.Left+=diff;
                    }
                }
            }
            //wstawianie wierszy
            j=0;
            for (i=0;i<c ;i++)
            {
                if (LinesUsed[i]>1)
                {
                    //wstawianie wierszy dla rozmiarów kolumn
                    c2=LinesUsed[i]+Sizes.size()-1;
                    Sizes.resize(c2,Sizes[0]);

                    for (k=(c2-LinesUsed[i]+1);k<c2 ;k++)
                    {
                        for (l=0;l<11 ;l++)
                        {
                            Sizes[k][l].Rect.Top=Sizes[k-1][l].Rect.Bottom;
                            Sizes[k][l].Rect.Bottom=Sizes[k][0].Rect.Top+Sizes[0][0].Rect.Height();
                        }
                    }
                    //kopiowanie n-1 lini
                    c2=LinesUsed[i]-1;
                    TxtValues.insert(TxtValues.begin()+j,c2,TxtValues[j]);
                    //wype³nianie pustkami
                    l=j+1;
                    for (k=1;k<c2 ;k++,l++)
                    {
                        TxtValues[l].assign(11,"");
                    }
                    c2++;
                    //wype³nianie danymi
                    for (k=0;k<c2 ;k++)
                    {
                        TxtValues[j][1]=Column[j];
                        j++;
                    }
                }
                else
                {
                    j++;
                }
            }

        }
        else    //wsio jest wê¿sze
        {
            for (i=0;i<c ;i++)
            {
                for (j=1;j<11 ;j++)
                {
                    if (j==1)
                    {
                        Sizes[i][j].Rect.Right+=diff;
                    }
                    else
                    {
                        Sizes[i][j].Rect.Right+=diff;
                        Sizes[i][j].Rect.Left+=diff;
                    }
                }
            }
        }
        //okreœlanie ostatecznych wielkoœci wykonane
    }
    //okreœlenie rozmieszczenia tekstu wzglêdem komórki
    c=TxtValues.size();
    AlignRow.resize(11,taRightJustify);
    AlignRow[0]=taCenter;
    AlignRow[1]=taLeftJustify;
    AlignTable.resize(c,AlignRow);
    //No to drukujemy
    for (i=0;i<c ;i++)
    {
        for (j=0;j<11 ;j++)
        {
            TextRect(Canvas,Sizes[i][j].Rect,Sizes[i][j].Rect.Top,TxtValues[i][j],AlignTable[i][j]);
        }
    }
    i--;
    r1=Sizes[i][0];
    r1.Rect.right=Sizes[0][10].Rect.Right;
    r1.Rect.top=r1.Rect.bottom-3;
    Canvas->Rectangle(r1.Rect);
    r1.Rect.top=Sizes[2][0].Rect.top;
    r1.Rect.bottom=r1.Rect.top+3;
    Canvas->Rectangle(r1.Rect);
    Rect.bottom=Sizes[i][0].Rect.bottom;
}



void __fastcall TFaktorez::TaxesRect(TCanvas * Canvas, TRect & Rect, int Y, TAlignment Alignment, TDocumentData DocumentData)
{
    //TODO: Drukowanie tabelki z podatkami
    TRectWrapper r1;
    vector<vector<TRectWrapper> > Sizes;
    vector<vector<AnsiString> > TxtValues;
    vector<vector<TAlignment> > AlignTable;
    vector<AnsiString> TxtRow;
    vector<TRectWrapper> SizesRow;
    vector<TAlignment> AlignRow;
    int MaxWidths[11];
    int MinWidths[11];
    int extr;
    int diff,sum;
    vector<int> LinesUsed;
    vector<AnsiString> txtbuf;
    vector<AnsiString> Column;
    int iter;
    int i,j,k,l;
    int c,c2;
    AnsiString spacja=" ";
    AnsiString tbuf1;
    AnsiString undo;
    c=DocumentData.TaxesCount();
    //stawki podatkowe
    AlignRow.resize(4,taRightJustify);
    AlignRow[0]=taCenter;
    AlignTable.resize(c,AlignRow);
    //razem podatki
    AlignTable.push_back(AlignRow);
    //nag³ówek
    AlignRow.assign(4,taRightJustify);
    AlignRow[0]=taCenter;
    AlignTable.insert(AlignTable.begin(),AlignRow);
    //wype³nianie danymi tabeli
    TxtRow.resize(4);
    TxtValues.resize(c,TxtRow);
    for (i=0;i<c ;i++)
    {
        TxtValues[i][0]=DocumentData.TaxVATP(i);
        TxtValues[i][1]=DocumentData.TaxNetto(i);
        TxtValues[i][2]=DocumentData.TaxVAT(i);
        TxtValues[i][3]=DocumentData.TaxBrutto(i);
    }
    //Wype³nianie nag³ówka
    TxtRow[0]="Ogó³em wg stawki";
    TxtRow[1]="Wartoœæ netto";
    TxtRow[2]="Kwota VAT";
    TxtRow[3]="Wartoœc brutto";
    TxtValues.insert(TxtValues.begin(),TxtRow);
    //podsumowanie
    TxtRow[0]="Razem";
    TxtRow[1]=DocumentData.TaxNettoSum();
    TxtRow[2]=DocumentData.TaxVATSum();
    TxtRow[3]=DocumentData.TaxBruttoSum();
    TxtValues.push_back(TxtRow);
    c=TxtValues.size();
    //obliczanie rozmiarów
    r1.Rect.Left=Rect.Left;
    r1.Rect.Top=Rect.Top;
    r1.Rect.Bottom=r1.Rect.Top+(Canvas->TextHeight("yfŒ")*12/10);
    r1.Rect.Right=r1.Rect.Left+Canvas->TextWidth(TxtValues[0][0])+
    r1.Rect.Height();
    SizesRow.resize(4,r1);
    Sizes.resize(c,SizesRow);
    for (i=0;i<c ;i++)
    {
        if ((i==0)||((i+1)==c))
            Canvas->Font->Style=TFontStyles()<< fsBold;
        else
            Canvas->Font->Style=TFontStyles();
        for (j=0;j<4 ;j++)
        {
            k=Canvas->TextWidth(TxtValues[i][j])+r1.Rect.Height();
            r1.Width(k);
            Sizes[i][j]=r1;
        }
    }
    for (i=0;i<c ;i++)
    {
        for (j=0;j<4 ;j++)
        {
            if (SizesRow[j].Rect.Width()<Sizes[i][j].Rect.Width())
            {
                SizesRow[j]=Sizes[i][j];
            }
        }
    }
    //przesuwanie w poziomie na w³aœciw¹ pozycjê
    for (i=1,j=0;i<4 ;i++,j++)
    {
        k=SizesRow[j].Rect.Right-SizesRow[0].Rect.Left;
        SizesRow[i].Move(k,0);
    }
    Sizes.assign(c,SizesRow);
    //przesuwanie w pionie
    for (i=0;i<c ;i++)
    {
        k=r1.Rect.Height()*i;
        for (j=0;j<4 ;j++)
        {
            Sizes[i][j].Move(0,k);
        }
    }
    diff=Rect.Right-Sizes[0][3].Rect.Right;
    for (i=0;i<c ;i++)
    {
        for (j=0;j<4 ;j++)
        {
            r1=Sizes[i][j];
            r1.Move(diff,0);
            Sizes[i][j]=r1;
        }
    }
    //No to drukujemy
    for (i=0;i<c ;i++)
    {
        if ((i==0)||((i+1)==c))
            Canvas->Font->Style=TFontStyles()<< fsBold;
        else
            Canvas->Font->Style=TFontStyles();
        for (j=0;j<4 ;j++)
        {
            TextRect(Canvas,Sizes[i][j].Rect,Sizes[i][j].Rect.Top,TxtValues[i][j],AlignTable[i][j]);
        }
    }
    i--;
    r1=Sizes[i][0];
    r1.Rect.Right=Sizes[i][3].Rect.Right;
    r1.Height(3);
    Canvas->Rectangle(r1.Rect);
    r1=Sizes[1][0];
    r1.Rect.Right=Sizes[1][3].Rect.Right;
    r1.Height(3);
    Canvas->Rectangle(r1.Rect);

}
void __fastcall TFaktorez::StatusBar1DrawPanel(TStatusBar *StatusBar,
      TStatusPanel *Panel, const TRect &Rect)
{
    int size;
    TRectWrapper r1;
    r1=Rect;
    if (Panel->Index==2)
    {
        StatusBar->Canvas->Brush->Color=clBtnFace;
        StatusBar->Canvas->Rectangle(Rect);
        size=StatusBar->Tag*Rect.Width()/1000;
        r1.Width(size);
        StatusBar->Canvas->Brush->Color=clHighlight;
        StatusBar->Canvas->Rectangle(r1.Rect);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFaktorez::add1Click(TObject *Sender)
{
    ClientData1->FaktorzData=FaktorzData;
    ClientData1->Insert=true;
    ClientData1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFaktorez::edit1Click(TObject *Sender)
{
    ClientList->Show();
}
//---------------------------------------------------------------------------


void TFaktorez::PrintKP(int start, int end)
{
TDateTime dat1d;
int i,j;
int c1,c2;
int xpos,ypos;
int xsize,ysize;
AnsiString title;
AnsiString tbuf1;
TStringList *prtext;
    try
    {
        if (start==end)
        {
            Query4->SQL->Strings[1]="WHERE num_kp="+IntToStr(start)+";";
        }
        else
        {
            Query4->SQL->Strings[1]="WHERE num_kp BETWEEN"+IntToStr(start)+
            " AND "+IntToStr(end)+";";
        }
        Query4->Open();
        c1=Query4->RecordCount;
        Printer1->BeginDoc();
        for (i=0;i<c1 ;i++)
        {
            
        }

    }
    catch(...)
    {
    }
    Printer1->EndDoc();
    
//kontrachent:
    //Nazwisko
    //adres
    //kod pocztowy miasto
//tytu³
//kwota
//s³ownie
//po prawej:
    //TODO: Drukowanie KP
/*
TPrinter *prt2=Printer();
    //data i czas
    //KP i numer
    ADOQuery2->Open();
    ADOQuery2->First();
    ADOQuery3->Open();
    ADOQuery3->First();
    prtext=new TStringList();
    try
    {
        prt2->BeginDoc();

        c1=ADOQuery1->RecordCount;
        if (mon1r1->Checked)
        {
            c1=ADOQuery2->RecordCount;
            ADOQuery2->First();
            for (i=0;i<c1 ;i++)
            {
                if (mon1l->Checked[i])
                {
                    //drukowanie firmy
                    xpos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    ypos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    prt2->Canvas->Font->Size=12;
                    prt2->Canvas->Font->Name="Times New Roman";
                    prt2->Canvas->Font->Style=TFontStyles()<< fsBold;
                    prtext->LoadFromFile("templates\\firma1.txt");
                    c2=prtext->Count;
                    for (j=0;j<c2 ;j++)
                    {
                        tbuf1=prtext->Strings[j];
                        prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                        ysize=prt2->Canvas->TextHeight(tbuf1);
                        ypos+=ysize;
                    }
                    //dane adresowe i bank firmy
                    prt2->Canvas->Font->Style=TFontStyles();
                    prtext->LoadFromFile("templates\\firma2.txt");
                    c2=prtext->Count;
                    for (j=0;j<c2 ;j++)
                    {
                        tbuf1=prtext->Strings[j];
                        prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                        ysize=prt2->Canvas->TextHeight(tbuf1);
                        ypos+=ysize;
                    }
                    //pobieranie daty
                    dat1d=ADOQuery2->FieldByName("date1")->AsDateTime;
                    tbuf1=ADOQuery2->FieldByName("m_name")->Text+" "+
                    dat1d.FormatString("yyyy");
                    //data KP
                    if (dat1->Checked)
                    {
                        dat1d=Now();
                    }
                    else
                    {
                        dat1d=dat202->Date+dat201->Time;
                    }
                    tbuf1="Data:      "+dat1d.FormatString("dd-mm-yyyy (hh:nn:ss)");
                    xpos=TenNetData.cols[0].cmToPixel(19.0,prt2);
                    ypos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    xsize=prt2->Canvas->TextWidth(tbuf1);
                    xpos-=xsize;
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    ysize=prt2->Canvas->TextHeight(tbuf1);
                    ypos+=ysize*2;
                    //numer KP
                    prt2->Canvas->Font->Size=14;
                    prt2->Canvas->Font->Style=TFontStyles()<< fsBold;
                    xpos=TenNetData.cols[0].cmToPixel(19.0,prt2);
                    tbuf1="KP – Dowód wp³aty nr "+
                    IntToStr(KPNum)+
                    "/"+dat1d.FormatString("yy");
                    xsize=prt2->Canvas->TextWidth(tbuf1);
                    xpos-=xsize;
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //kontrachent
                    prt2->Canvas->Font->Size=12;
                    prt2->Canvas->Font->Style=TFontStyles();
                    tbuf1="Kontrahent:";
                    xpos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    ypos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    ypos+=ysize*8;
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //nazwisko
                    prt2->Canvas->Font->Style=TFontStyles()<< fsBold;
                    xpos=TenNetData.cols[0].cmToPixel(6.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,name1->Text);
                    //adres
                    prt2->Canvas->Font->Style=TFontStyles();
                    ypos+=ysize;
                    tbuf1="ul. "+adr1->Text;
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    ypos+=ysize;
                    tbuf1=city1->Text+" "+kod1->Text;
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //Tytu³ p³atnoœci
                    tbuf1="Tytu³em:";
                    ypos+=ysize*2;
                    xpos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    xpos=TenNetData.cols[0].cmToPixel(6.0,prt2);
                    if (UseAbonament)
                    {
                        tbuf1="Abonament za Internet - "+
                        ADOQuery2->FieldByName("m_name")->Text;
                    }
                    else
                    {
                        tbuf1=tit1->Text;
                    }
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //Wp³acono
                    tbuf1="Wp³acono:";
                    ypos+=ysize*2;
                    xpos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    xpos=TenNetData.cols[0].cmToPixel(6.0,prt2);
                    tbuf1=FloatToStr(Kwota);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //s³ownie
                    tbuf1="S³ownie:";
                    ypos+=ysize*2;
                    xpos=TenNetData.cols[0].cmToPixel(2.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    xpos=TenNetData.cols[0].cmToPixel(6.0,prt2);
                    tbuf1=DigitalToCurrency(Kwota);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    //wystawi³
                    tbuf1="Wystawi³:";
                    ypos+=ysize*3;
                    xpos=TenNetData.cols[0].cmToPixel(4.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                    tbuf1=".......................................";
                    ypos+=ysize*3;
                    xpos=TenNetData.cols[0].cmToPixel(3.0,prt2);
                    prt2->Canvas->TextOutA(xpos,ypos,tbuf1);
                }
                //nastêpny miesi¹c
                KPNum++;
                if ((i+1)<c1)
                {
                    prt2->NewPage();
                    ADOQuery2->Next();
                }
            }
        }
        else
        {

        }


        prt2->EndDoc();
    }
    catch(...)
    {
        prt2->EndDoc();
    }
    delete prtext;
    ADOQuery2->Close();
    ADOQuery3->Close();
    Close();
*/
}


