//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("MagicPasswords.res");
USEFORM("magic1.cpp", MagicPassword);
USEUNIT("md5.c");
USEUNIT("VCLhashlib.cpp");
USEFORM("about.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TMagicPassword), &MagicPassword);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
