//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("bumcykcyk.res");
USEFORM("bum.cpp", BumCyk);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Bum Cyk Cyk";
        Application->CreateForm(__classid(TBumCyk), &BumCyk);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
