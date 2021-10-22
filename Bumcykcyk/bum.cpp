//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bum.h"
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBumCyk *BumCyk;
//---------------------------------------------------------------------------
__fastcall TBumCyk::TBumCyk(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TBumCyk::bum01(TObject *Sender)
{
int X,Y,bufX,bufY;
int i;
char buf[8];
    if(_argc<2)
        l1=1;
    else
    {
        strcpy(buf,_argv[1]);
        l1=atoi(buf);
    }
    randomize();
    for(i=0;i<l1;i++)
    {
        X=Screen->Width;
        bufX=X-Width;
        bufX=random(bufX);
        Y=Screen->Height;
        bufY=Y-Height;
        bufY=random(bufY);
    }
    Left=bufX;
    Top=bufY;
    l1++;
}
//---------------------------------------------------------------------------
void __fastcall TBumCyk::FormActivate(TObject *Sender)
{
char buf[8];
    itoa(l1,buf,10);
    spawnl(P_NOWAIT,"bumcykcyk.exe","bumcykcyk.exe",buf,NULL);
}
//---------------------------------------------------------------------------

