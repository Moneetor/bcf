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
USEFORM("baloon.cpp", TextBaloon);
USEFORM("changelog1.cpp", ChangeLog);
USEFORM("tools1.cpp", Tools);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "MagicPasswords v 1.0.4";
         Application->CreateForm(__classid(TTools), &Tools);
         Application->CreateForm(__classid(TMagicPassword), &MagicPassword);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TTextBaloon), &TextBaloon);
         Application->CreateForm(__classid(TChangeLog), &ChangeLog);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
