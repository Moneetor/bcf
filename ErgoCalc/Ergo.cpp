//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <math.h>
#include "Ergo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TErgoCalc *ErgoCalc;
/*
bity dzia³añ
0   -   plus
1   -   minus
2   -   mno¿enie
3   -   dzielenie
4   -   x
5   -   pamiêæ
6   -   pierwiastek % lub =
7   -   wpisano coœ po dzia³aniu
*/
//---------------------------------------------------------------------------
__fastcall TErgoCalc::TErgoCalc(TComponent* Owner)
    : TForm(Owner)
{
FILE *I;
    a_ratio=(float)disp1->Width/(float)(disp1->Height);
    f_ratio=(float)disp1->Width/(float)(disp1->Font->Size);
    wy1=0;
    wy0=0;
    dz=0;
    dot=false;
    if((I=fopen("mem.dat","r"))!=NULL)
    {
        dz=dz|0x20;
        fscanf(I,"%lf",&mem);
        fclose(I);
        Caption="ErgoCalc v 1.0.0 [M]";
    }
}
//---------------------------------------------------------------------------
void __fastcall TErgoCalc::d001(TObject *Sender, char &Key)
{
    switch(Key){
        case '0':   d0->Click();
                    break;
        case'_':    plm1->Click();
                    break;
        case ',':   p1->Click();
                    break;
        case '.':   p1->Click();
                    break;
        case '+':   plus1->Click();
                    break;
        case '\r':  equ1->Click();
                    break;
        case '1':   d1->Click();
                    break;
        case '2':   d2->Click();
                    break;
        case '3':   d3->Click();
                    break;
        case '-':   min1->Click();
                    break;
        case 'm':   mpl1->Click();
                    break;
        case '4':   d4->Click();
                    break;
        case '5':   d5->Click();
                    break;
        case '6':   d6->Click();
                    break;
        case '*':   Button3->Click();
                    break;
        case 'M':   mmin1->Click();
                    break;
        case '7':   d7->Click();
                    break;
        case '8':   d8->Click();
                    break;
        case '9':   d9->Click();
                    break;
        case '/':   IQ1->Click();
                    break;
        case 'r':   msho1->Click();
                    break;
        case 0x08:  cle1->Click();
                    break;
        case 'a':	can1->Click();
                    break;
        case 's':   sqr1->Click();
                    break;
        case '%':   proc1->Click();
                    break;
        case 'c':   mclr1->Click();
                    break;
        default:    MessageBeep(MB_OK);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TErgoCalc::d002(TObject *Sender)
{
char buf[13];
int l1;
    strcpy(buf,disp1->Text.c_str());
    l1=strlen(buf);
    if(dz)
    {
        if((dz&128))    //test czy ju¿ by³o coœ wpisane by³o
        {
            if(dot)
            {
                if(((l1==11)&&(buf[0]!='-'))||(l1==12))
                    MessageBeep(MB_OK);
                else
                {
                    strcat(buf,"0");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((buf[0]=='0')||((l1==10)&&(buf[0]!='-'))||(l1==11))
                    MessageBeep(MB_OK);
                else
                {
                    strcat(buf,"0");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            strcpy(buf,"0");
            disp1->Text=buf;
            dz+=128;
        }
    }
    else
    {
        if(dot)
        {
            if(((l1==11)&&(buf[0]!='-'))||(l1==12))
                MessageBeep(MB_OK);
            else
            {
                strcat(buf,"0");
                disp1->Text=buf;
            }
        }
        else
        {
            if((buf[0]=='0')||((l1==10)&&(buf[0]!='-'))||(l1==11))
                MessageBeep(MB_OK);
            else
            {
                strcat(buf,"0");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TErgoCalc::full1Click(TObject *Sender)
{
float buf;
    if(full1->Checked)
    {
        full1->Checked=false;
        disp1->Align=alNone;
        Width=416;
        Height=432;
        WindowState=wsNormal;
        disp1->Width=ClientWidth-16;
        buf=disp1->Width;
        buf=buf/a_ratio;
        disp1->Height=buf;
        buf=disp1->Width;
        buf=buf/f_ratio;
        disp1->Font->Size=buf;
        disp1->Left=8;
    }
    else
    {
        full1->Checked=true;
        disp1->Align=alClient;
        WindowState=wsMaximized;
        disp1->Height=buf;
        buf=disp1->Width;
        buf=buf/f_ratio;
        disp1->Font->Size=buf;

    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::clo101(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::plm101(TObject *Sender)
{
char buf[13];
int i;
    strcpy(buf,disp1->Text.c_str());
    if(dz)
    {
        if((dz&128))
        {
            if((buf[0]=='0')&&(dot==false))
                MessageBeep(MB_OK);
            else
            {
        	    if(buf[0]=='-')
                {
                	for(i=0;i<12;i++)
                    {
                        buf[i]=buf[i+1];
                    }
                    buf[i]=buf[i+1];
                }
                else
                {
                	for(i=11;i>0;i--)
                    {
                	    buf[i+1]=buf[i];
                    }
                    buf[1]=buf[0];
                    buf[0]='-';
                }
                disp1->Text=buf;
            }
        }
        else
            MessageBeep(MB_OK);
    }
    else
    {
        if((buf[0]=='0')&&(dot==false))
            MessageBeep(MB_OK);
        else
        {
    	    if(buf[0]=='-')
            {
            	for(i=0;i<12;i++)
                {
                    buf[i]=buf[i+1];
                }
                buf[i]=buf[i+1];
            }
            else
            {
            	for(i=11;i>0;i--)
                {
            	    buf[i+1]=buf[i];
                }
                buf[1]=buf[0];
                buf[0]='-';
            }
            disp1->Text=buf;
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d101(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"1");
                    else
                        strcat(buf,"1");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"1");
                    else
                        strcat(buf,"1");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="1";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"1");
                else
                    strcat(buf,"1");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"1");
                else
                    strcat(buf,"1");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::p101(TObject *Sender)
{
char buf[13];
    strcpy(buf,disp1->Text.c_str());
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
                MessageBeep(MB_OK);
            else
            {
                strcat(buf,".");
                disp1->Text=buf;
                dot=true;
            }
        }
        else
        {
            strcpy(buf,"0.");
            disp1->Text=buf;
            dot=true;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
            MessageBeep(MB_OK);
        else
        {
            strcat(buf,".");
            disp1->Text=buf;
            dot=true;
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::cle101(TObject *Sender)
{
    dz=dz&0x20;
    wy0=0;
    wy1=0;
    dot=false;
    disp1->Text="0";
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::can101(TObject *Sender)
{
    if(dz)
    {
        if(dz&128)
            MessageBeep(MB_OK);
        else
        {
            wy1=0;
            dot=false;
            disp1->Text="0";
        }
    }
    else
    {
        wy1=0;
        dot=false;
        disp1->Text="0";
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::plus101(TObject *Sender)
{
char buf[13];
    equ101(Sender);
    dz=(dz&0x20)|1;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
        wy0=0;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d201(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"2");
                    else
                        strcat(buf,"2");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"2");
                    else
                        strcat(buf,"2");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="2";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"2");
                else
                    strcat(buf,"2");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"2");
                else
                    strcat(buf,"2");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d301(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"3");
                    else
                        strcat(buf,"3");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"3");
                    else
                        strcat(buf,"3");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="3";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"3");
                else
                    strcat(buf,"3");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"3");
                else
                    strcat(buf,"3");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d401(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"4");
                    else
                        strcat(buf,"4");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"4");
                    else
                        strcat(buf,"4");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="4";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"4");
                else
                    strcat(buf,"4");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"4");
                else
                    strcat(buf,"4");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d501(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"5");
                    else
                        strcat(buf,"5");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"5");
                    else
                        strcat(buf,"5");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="5";
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"5");
                else
                    strcat(buf,"5");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"5");
                else
                    strcat(buf,"5");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d601(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"6");
                    else
                        strcat(buf,"6");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"6");
                    else
                        strcat(buf,"6");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="6";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"6");
                else
                    strcat(buf,"6");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"6");
                else
                    strcat(buf,"6");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d701(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"7");
                    else
                        strcat(buf,"7");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"7");
                    else
                        strcat(buf,"7");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="7";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"7");
                else
                    strcat(buf,"7");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"7");
                else
                    strcat(buf,"7");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d801(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"8");
                    else
                        strcat(buf,"8");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"8");
                    else
                        strcat(buf,"8");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="8";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"8");
                else
                    strcat(buf,"8");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"8");
                else
                    strcat(buf,"8");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::d901(TObject *Sender)
{
char buf[12];
int i;
    strcpy(buf,disp1->Text.c_str());
    i=strlen(buf);
    if(dz)
    {
        if((dz&128))
        {
            if(dot)
            {
                if((i==11)||((i==12)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"9");
                    else
                        strcat(buf,"9");
                    disp1->Text=buf;
                }
            }
            else
            {
                if((i==10)||((i==11)&&(buf[0]!='-')))
                    MessageBeep(MB_OK);
                else
                {
                    if(((i==1)&&(buf[0]=='0')))
                        strcpy(buf,"9");
                    else
                        strcat(buf,"9");
                    disp1->Text=buf;
                }
            }
        }
        else
        {
            disp1->Text="9";
            dot=false;
            dz=dz|0x80;
        }
    }
    else
    {
        if(dot)
        {
            if((i==11)||((i==12)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"9");
                else
                    strcat(buf,"9");
                disp1->Text=buf;
            }
        }
        else
        {
            if((i==10)||((i==11)&&(buf[0]!='-')))
                MessageBeep(MB_OK);
            else
            {
                if(((i==1)&&(buf[0]=='0')))
                    strcpy(buf,"9");
                else
                    strcat(buf,"9");
                disp1->Text=buf;
            }
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::equ101(TObject *Sender)
{
char buf[13];
    strcpy(buf,disp1->Text.c_str());
    wy1=atof(buf);
    if(dz&0x0f)
    {
        if(dz&1)
        {
            wy0+=wy1;
            dot=false;
        }
        if(dz&2)
        {
            wy0-=wy1;
            dot=false;
        }
        if(dz&4)
        {
            wy0*=wy1;
            dot=false;
        }
        if(dz&8)
        {
            if(wy1==0)
            {
                disp1->Text="0 - error(0)";
                MessageBeep(MB_ICONEXCLAMATION);
                ShowMessage("Dzielenie przez zero");
                disp1->Text="0";
                dot=false;
                dz=dz&0x20;
            }
            else
            {
                wy0/=wy1;
                dot=false;
            }
        }
    }
    else
        wy0=wy1;
    dz=(dz&0x20)|0x40;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TErgoCalc::sqr101(TObject *Sender)
{
char buf[13];
    strcpy(buf,disp1->Text.c_str());
    wy1=atof(buf);
    if(wy1<0)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Liczba ujemna");
        disp1->Text="0";
    }
    else
    {
        wy1=sqrt(wy1);
        gcvt(wy1,10,buf);
        disp1->Text=buf;
        dot=false;
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::min101(TObject *Sender)
{
char buf[13];
    equ101(Sender);
    dz=(dz&0x20)|2;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
        wy0=0;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::IQ101(TObject *Sender)
{
char buf[13];
    equ101(Sender);
    dz=(dz&0x20)|8;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::Button301(TObject *Sender)
{
char buf[13];
    equ101(Sender);
    dz=(dz&0x20)|4;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::msho101(TObject *Sender)
{
char buf[13];
    if(dz&0x20)
    {
        gcvt(mem,10,buf);
        disp1->Text=buf;
        if((ceil(mem))==mem)
            dot=false;
        else
            dot=true;
        dz=dz&0xf0;
        msho1->Down=true;
        mclr1->Down=false;
    }
    else
    {
        msho1->Down=false;
        MessageBeep(MB_OK);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::mclr101(TObject *Sender)
{
    mem=0;
    dz=dz&0xdf;
    remove("mem.dat");
    Caption="ErgoCalc v 1.0.0";
    msho1->Down=false;
    mclr1->Down=true;
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::mpl101(TObject *Sender)
{
char buf[13];
FILE *O;
    equ101(Sender);
    dz=(dz&0x20)|0x60;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    mem+=wy0;
    msho1->Down=false;
    mclr1->Down=false;
    if(mem==0)
    {
        dz=dz&0x5f;
        remove("mem.dat");
        Caption="ErgoCalc v 1.0.0";
    }
    else
    {
        if((O=fopen("mem.dat","w"))==NULL)
        {
            MessageBeep(MB_ICONEXCLAMATION);
            ShowMessage("Problemy z pamiêci¹");
        }
        else
        {
            Caption="ErgoCalc v 1.0.0 [M]";
            fprintf(O,"%10.9lf",mem);
            fclose(O);
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::mmin101(TObject *Sender)
{
char buf[13];
    equ101(Sender);
    dz=(dz&0x20)|0x60;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    mem-=wy0;
    msho1->Down=false;
    mclr1->Down=false;
    if(mem==0)
    {
        dz=dz&0x5f;
        remove("mem.dat");
        Caption="ErgoCalc v 1.0.0";
    }
    else
    {
        if((O=fopen("mem.dat","w"))==NULL)
        {
            MessageBeep(MB_ICONEXCLAMATION);
            ShowMessage("Problemy z pamiêci¹");
        }
        else
        {
            Caption="ErgoCalc v 1.0.0 [M]";
            fprintf(O,"%10.9lf",mem);
            fclose(O);
        }
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::proc101(TObject *Sender)
{
char buf[13];
    strcpy(buf,disp1->Text.c_str());
    wy1=atof(buf);
    wy1*=0.01;
    if(dz&0x0f)
    {
        if(dz&1)
            wy0=wy0+wy0*wy1;
        if(dz&2)
            wy0=wy0-wy0*wy1;
        if(dz&4)
            wy0*=wy1;
        if(dz&8)
        {
            if(wy1==0)
            {
                disp1->Text="0 - error(0)";
                MessageBeep(MB_ICONEXCLAMATION);
                ShowMessage("Dzielenie przez zero");
                disp1->Text="0";
                dot=false;
                dz=dz&0x20;
            }
            else
                wy0/=wy1;
        }
    }
    else
        wy0=wy1;
    dz=(dz&0x20)|0x40;
    if((fabs(wy0))>=10000000000.)
    {
        disp1->Text="0 - error";
        MessageBeep(MB_ICONEXCLAMATION);
        ShowMessage("Zbyt du¿y modu³ liczby");
        disp1->Text="0";
        dz=dz&0x20;
    }
    else
    {
        gcvt(wy0,10,buf);
        disp1->Text=buf;
        strcpy(buf,disp1->Text.c_str());
        wy0=atof(buf);
    }
    disp1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::paint1(TObject *Sender)
{
    disp1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TErgoCalc::copy101(TObject *Sender)
{
    disp1->CopyToClipboard();    
}
//---------------------------------------------------------------------------

void __fastcall TErgoCalc::Wklej101(TObject *Sender)
{
    disp1->PasteFromClipboard();   
}
//---------------------------------------------------------------------------


