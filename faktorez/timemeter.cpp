//---------------------------------------------------------------------------
#include <time.h>

#pragma hdrstop

#include "timemeter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


TTimeMeter::TTimeMeter(void)
{
    //TODO: Konstruktor domyslny
    start=clock();
    end=start;
    FTimeToWait=0.5;
    FETA=0;
}

double __fastcall TTimeMeter::GetETA()
{
    end=clock();
    FETA=(end-start)/CLK_TCK;
    return FETA;
}

void __fastcall TTimeMeter::Reset(void)
{
    //DONE: reset czasomierza
    start=clock();
    end=start;
    FETA=0;
}

void __fastcall TTimeMeter::SetTimeToWait(double value)
{
    if(FTimeToWait != value)
    {
        if (FTimeToWait>0)
        {
            FTimeToWait = value;
        }
    }
}



bool __fastcall TTimeMeter::GetTestTime()
{
    if (GetETA()>=FTimeToWait)
    {
        FTestTime=true;
        Reset();
    }
    else
        FTestTime=false;
    return FTestTime;
}

__fastcall TTimeMeter::TTimeMeter(double time)
{
    //TODO: konstruktor z ustaleniem ilosci czasu
    start=clock();
    end=start;
    FTimeToWait=time;
    FETA=0;
}