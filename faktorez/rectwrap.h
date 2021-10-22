//---------------------------------------------------------------------------

#ifndef rectwrapH
#define rectwrapH

#include <vcl.h>
//---------------------------------------------------------------------------
class TRectWrapper
{
private:

protected:

public:
    TRect Rect;
    TRectWrapper() { };
    TRectWrapper(const TRectWrapper & RectWrapper);
    ~TRectWrapper() { };
    TRectWrapper & operator =(const TRectWrapper & RectWrapper);
    TRectWrapper & operator =(const TRect & Rectangle);
    TRectWrapper(TRect & Rect1);
    void __fastcall Move(int xDelta, int yDelta);
    void __fastcall Height(int value);
    void __fastcall Width(int value);
    void __fastcall Center(TPoint & Point);
};

#endif
