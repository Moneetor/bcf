//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Faktorez.res");
USEFORM("faktor.cpp", Faktorez);
USEFORM("config1.cpp", Config);
USEUNIT("faktordata1.cpp");
USEFORM("newfield1.cpp", NewField);
USEUNIT("scale.cpp");
USEUNIT("windowr.cpp");
USEUNIT("Blowfish\blowfish.cpp");
USEFORM("prtdialog1.cpp", PrintMassDialog);
USEFORM("prtdialog2.cpp", PrintMassDialog2);
USEUNIT("masprinter1.cpp");
USEUNIT("rectwrap.cpp");
USEUNIT("timemeter.cpp");
USEFORM("clientdata.cpp", ClientData1);
USEFORM("clientlist1.cpp", ClientList);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "Faktorez v 0.1";
         Application->CreateForm(__classid(TFaktorez), &Faktorez);
         Application->CreateForm(__classid(TConfig), &Config);
         Application->CreateForm(__classid(TNewField), &NewField);
         Application->CreateForm(__classid(TPrintMassDialog), &PrintMassDialog);
         Application->CreateForm(__classid(TPrintMassDialog2), &PrintMassDialog2);
         Application->CreateForm(__classid(TClientData1), &ClientData1);
         Application->CreateForm(__classid(TClientList), &ClientList);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
