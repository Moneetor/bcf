//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("MagicPasswords.res");
USEFORM("magic1.cpp", MagicPassword);
USEUNIT("md5.c");
USEUNIT("VCLhashlib.cpp");
USEFORM("about.cpp", AboutBox);
USEUNIT("translator.cpp");
USEUNIT("config1.cpp");
USEUNIT("saferegistry.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "MagicPasswords v 1.0.1";
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
