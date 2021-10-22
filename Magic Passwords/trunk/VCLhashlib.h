//---------------------------------------------------------------------------

#ifndef VCLhashlibH
#define VCLhashlibH
#include "md5.h"
using namespace std;
#include <vector>
//---------------------------------------------------------------------------
class TMD5Hash
{
private:
    MD5Context MD5_1;
protected:

public:
    TMD5Hash();
    AnsiString __fastcall GetHash(AnsiString Text);

};

#endif
