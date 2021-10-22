//---------------------------------------------------------------------------

#ifndef timemeterH
#define timemeterH

#include <time.h>
//---------------------------------------------------------------------------
class TTimeMeter
{
private:
    clock_t start;
    clock_t end;
    double FETA;
    double FTimeToWait;
    bool FTestTime;
    double __fastcall GetETA();
    void __fastcall SetTimeToWait(double value);
    bool __fastcall GetTestTime();

protected:

public:
    TTimeMeter(void);
    void __fastcall Reset(void);
    __fastcall TTimeMeter(double time);
    __property double ETA  = { read=GetETA };
    __property double TimeToWait  = { read=FTimeToWait, write=SetTimeToWait };
    __property bool TestTime  = { read=GetTestTime };

};

#endif
