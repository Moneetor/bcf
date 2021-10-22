//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VCLhashlib.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


TMD5Hash::TMD5Hash()
{
    //Done: Rozpoczêcie hashowania
    MD5Init(&MD5_1);
}

AnsiString __fastcall TMD5Hash::GetHash(AnsiString Text)
{
    //TODO: Obliczanie hashu
unsigned char sign[32];
AnsiString MD5Signature;
AnsiString tbuf1;
vector<unsigned char> buf1;
unsigned int l,i;
    MD5Init(&MD5_1);
    l=Text.Length();
    buf1.resize(l,0);
    for (i=0;i<l ;i++)
    {
        buf1[i]=Text.c_str()[i];
    }
    MD5Update(&MD5_1,buf1.begin(),l);
    buf1.clear();
    MD5Final(sign,&MD5_1);
    MD5Signature="";
    for (i=0;i<16 ;i++)
    {
        MD5Signature=MD5Signature+IntToHex((int)sign[i],2);
    }
    return MD5Signature;
}