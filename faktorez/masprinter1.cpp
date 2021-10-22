//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "masprinter1.h"
#include "faktor.h"
#include "faktordata1.h"
#include "prtdialog1.h"

#pragma package(smart_init)

/*
    Mode
    1   -   Odczyt z bazy
    2   -   Drukowanie orygina³u
    3   -   Drukowanie kopii
    4   -   Oznaczanie jako wydrukowanych
*/
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Unit1::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TMassPrinter::TMassPrinter(bool CreateSuspended)
    : TThread(CreateSuspended)
{
    Query1=Faktorez->Query1;
    Query2=Faktorez->Query2;
    Query3=Faktorez->Query3;
    Printer1=Faktorez->Printer1;
    Query1->First();
    Query2->First();
    Faktury.clear();
    timer1.TimeToWait=0.2;
}
//---------------------------------------------------------------------------
void __fastcall TMassPrinter::Execute()
{
    int c;
    //---- Place thread code here ----
    UnspecifiedRowCount=false;
    eof=false;
    Synchronize(GetDocumentCount);
    Synchronize(StartPrint);
    try
    {
        Mode=1;
        Synchronize(ShowStats);
        if (UnspecifiedRowCount)
        {
            while (!eof)
            {
                Synchronize(GetDocumentData);
                if (Terminated)
                    break;
                Synchronize(Next);
                if (Terminated)
                    break;
                Synchronize(ShowStats);
            }
        }
        else
        {
            c=Faktury.size();
            for (ActualPos=0;ActualPos<c ;ActualPos++)
            {
                Synchronize(ShowStats);
                if (Terminated)
                    break;
                Synchronize(UpdateDocument);
                if (Terminated)
                    break;
                Synchronize(Next);
                if (Terminated)
                    break;
                Synchronize(ShowStats);
                if (Terminated)
                    break;
            }
        }
        c=Faktury.size();
        //drukowanie
        Mode=2;
        Priority=tpLower;
        Synchronize(ShowStats);
        if (PrintMassDialog->div1->Checked)
        {
            c=masters.size();
            for (ActualPos=0;ActualPos<c ;ActualPos++)
            {
                Synchronize(ShowStats);
                if (Terminated)
                    break;
                Synchronize(PrintDocument);
                if (Terminated)
                    break;
                Synchronize(NextPage);
                Synchronize(ShowStats);
                if (Terminated)
                    break;
            }
            Mode++;
            c=copies.size();
            for (ActualPos=0;ActualPos<c ;ActualPos++)
            {
                Synchronize(ShowStats);
                if (Terminated)
                    break;
                Synchronize(PrintDocument);
                if (Terminated)
                    break;
                if ((ActualPos+1)<c)
                    Synchronize(NextPage);
                Synchronize(ShowStats);
                if (Terminated)
                    break;
            }
        }
        else
        {
            for (ActualPos=0;ActualPos<c ;ActualPos++)
            {
                Synchronize(ShowStats);
                if (Terminated)
                    break;
                Mode=2;
                Synchronize(PrintDocument);
                if (Terminated)
                    break;
                Mode=3;
                Synchronize(PrintDocument);
                if (Terminated)
                    break;
                Synchronize(NextPage);
                Synchronize(ShowStats);
                if (Terminated)
                    break;
            }
        }
        if (Terminated)
            Synchronize(AbortPrint);
        else
        {
            Synchronize(EndPrint);
            Synchronize(SetPrinted);
        }
    }
    catch(Exception & Exception)
    {
        Synchronize(AbortPrint);
        Application->ShowException(&Exception);
    }
    Printer1=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMassPrinter::GetDocumentCount(void)
{
    int c;
    //TODO: Add your source code here
    if (!Query1->Prepared)
    {
        Query1->Close();
        Query1->Prepare();
        Query1->Open();
    }
    c=Query1->RecordCount;
    if (c<0)
    {
        c=0;
        UnspecifiedRowCount=true;
    }
    Faktury.resize(c);
}

void __fastcall TMassPrinter::Next(void)
{
    //TODO: Add your source code here
    if (!Query1->Eof)
    {
        Query1->Next();
        eof=false;
    }
    else
    {
        eof=true;
    }
    eof=Query1->Eof;
}

void __fastcall TMassPrinter::ShowStats(void)
{
    int c;
    //TODO: Pokazuje status
    c=Faktury.size();
    if (!timer1.TestTime)
        return;
    switch (Mode)
    {
      case 1:
      {
        Faktorez->StatusBar1->Panels->Items[0]->Text=
        "Odczyt faktur z bazy danych";

        if (UnspecifiedRowCount)
        {
            Faktorez->StatusBar1->Panels->Items[1]->Text="Dokumenty: "+
            IntToStr(c);
            Faktorez->StatusBar1->Tag=0;
        }
        else
        {
            Faktorez->StatusBar1->Panels->Items[1]->Text="Dokumenty: "+
            IntToStr(c)+" z "+IntToStr(ActualPos);
            Faktorez->StatusBar1->Tag=ActualPos*1000/c;
        }
      }
      break;
      case 2:
      {
        //drukowanie orygina³u
        if (PrintMassDialog->div1->Checked)
            c=masters.size();
        Faktorez->StatusBar1->Panels->Items[0]->Text=
        "Drukowanie faktur (orygina³y)";
        Faktorez->StatusBar1->Panels->Items[1]->Text="Dokumenty: "+
        IntToStr(ActualPos)+" z "+IntToStr(c);
        if (c)
            Faktorez->StatusBar1->Tag=ActualPos*1000/c;
        else
            Faktorez->StatusBar1->Tag=0;
      }
      break;
      case 3:
      {
        //drukowanie kopii
        if (PrintMassDialog->div1->Checked)
            c=copies.size();
        Faktorez->StatusBar1->Panels->Items[0]->Text=
        "Drukowanie faktur (kopie)";
        Faktorez->StatusBar1->Panels->Items[1]->Text="Dokumenty: "+
        IntToStr(ActualPos)+" z "+IntToStr(c);
        if (c)
            Faktorez->StatusBar1->Tag=ActualPos*1000/c;
        else
            Faktorez->StatusBar1->Tag=0;
      }
      break;
      case 4:
      {
        //kasowanie z drukowanych
        Faktorez->StatusBar1->Panels->Items[0]->Text=
        "Oznaczanie wydrukowanych faktur";
        Faktorez->StatusBar1->Panels->Items[1]->Text="Dokumenty: "+
        IntToStr(ActualPos)+" z "+IntToStr(c);
        if (c)
            Faktorez->StatusBar1->Tag=ActualPos*1000/c;
        else
            Faktorez->StatusBar1->Tag=0;
      }
      break;
      default: ;
    }
    Faktorez->StatusBar1->Repaint();
}

void __fastcall TMassPrinter::UpdateDocument(void)
{
    //TODO: Pobiera dane z bazy danych
    Faktury[ActualPos].GetDocumentFromDB(Query1,Query2);
    if (PrintMassDialog->div1->Checked)
    {
        if (Faktury[ActualPos].PrintCopy)
        {
            copies.push(ActualPos);
        }
        if (Faktury[ActualPos].PrintMaster)
        {
            masters.push(ActualPos);
        }
    }
}

void __fastcall TMassPrinter::PrintDocument(void)
{
    //TODO: Add your source code here
    unsigned int pos;
    if (PrintMassDialog->div1->Checked)
    {
        if (Mode==2)
        {
            //drukowanie orygina³u
            pos=masters.front();
            Faktorez->Faktura=Faktury[pos];
            Faktorez->PrintCopy(Faktorez->Printer1,false);
            Faktury[pos].PrintMaster=false;
            masters.pop();
        }
        else
        {
            //drukowanie kopii
            pos=copies.front();
            Faktorez->Faktura=Faktury[pos];
            Faktorez->PrintCopy(Faktorez->Printer1,true);
            Faktury[pos].PrintCopy=false;
            copies.pop();
        }
    }
    else
    {
        Faktorez->Faktura=Faktury[ActualPos];
        if (Faktury[ActualPos].PrintMaster)
        {
            Faktorez->PrintCopy(Faktorez->Printer1,false);
            Faktury[ActualPos].PrintMaster=false;
        }
        else
        {
            if (Faktury[ActualPos].PrintCopy)
            {
                Faktorez->PrintCopy(Faktorez->Printer1,true);
                Faktury[ActualPos].PrintCopy=false;
            }
        }
    }


}

void __fastcall TMassPrinter::StartPrint(void)
{
    Printer1->BeginDoc();
    Printer1->Canvas->Font->Name="Arial";
}

void __fastcall TMassPrinter::EndPrint(void)
{
    //TODO: Add your source code here
    Printer1->EndDoc();
}

void __fastcall TMassPrinter::NextPage(void)
{
    //TODO: Add your source code here
    Printer1->NewPage();
}

void __fastcall TMassPrinter::AbortPrint(void)
{
    //TODO: Add your source code here
    Printer1->Abort();
}

void __fastcall TMassPrinter::GetDocumentData(void)
{
    TDocumentData doc1,lastdoc;
    int c;
    //TODO: Pobiera dokument
    doc1.GetDocumentFromDB(Query1,Query2);
    if (!Query1->Eof)
    {
        Faktury.push_back(doc1);
        c=Faktury.size()-1;
        if (PrintMassDialog->div1->Checked)
        {
            if (doc1.PrintCopy)
            {
                copies.push(c);
            }
            if (doc1.PrintMaster)
            {
                masters.push(c);
            }
        }
    }
}

void __fastcall TMassPrinter::SetPrinted(void)
{
    //TODO: Oznaczanie wydrukowanych
    Query3->SQL->Clear();
    Query3->SQL->Add("UPDATE prt_faktury");
    Query3->SQL->Add("SET printed=1");
    Query3->ExecSQL();
}
