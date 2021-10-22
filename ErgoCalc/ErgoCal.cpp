//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ErgoCal.res");
USEFORM("Ergo.cpp", ErgoCalc);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Ergocalc v 1.1";
         Application->CreateForm(__classid(TErgoCalc), &ErgoCalc);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
