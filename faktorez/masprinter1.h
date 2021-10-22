//---------------------------------------------------------------------------

#ifndef masprinter1H
#define masprinter1H
//---------------------------------------------------------------------------
#include <Classes.hpp>

#include "timemeter.h"
#include "faktordata1.h"

using namespace std;
#include <vector>
#include <queue>
#include <printers.hpp>

//---------------------------------------------------------------------------
class TMassPrinter : public TThread
{
private:
    TQuery * Query1;
    TQuery * Query2;
    TQuery * Query3;
    int ZonkCount;
    AnsiString Description;
    int Mode;
    bool UnspecifiedRowCount;
    bool eof;
    queue<unsigned int> copies;
    queue<unsigned int> masters;
protected:
    TTimeMeter timer1;
    void __fastcall Execute();
public:
    TPrinter *Printer1;
    vector<TDocumentData> Faktury;
    int ActualPos;
    __fastcall TMassPrinter(bool CreateSuspended);
    void __fastcall GetDocumentCount(void);
    void __fastcall Next(void);
    void __fastcall ShowStats(void);
    void __fastcall UpdateDocument(void);
    void __fastcall PrintDocument(void);
    void __fastcall StartPrint(void);
    void __fastcall EndPrint(void);
    void __fastcall NextPage(void);
    void __fastcall AbortPrint(void);
    void __fastcall GetDocumentData(void);
    void __fastcall SetPrinted(void);
};
//---------------------------------------------------------------------------
#endif
