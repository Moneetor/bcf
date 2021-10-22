//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "rectwrap.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TRectWrapper::TRectWrapper(const TRectWrapper & RectWrapper)
{
    //TODO: Konstruktor kopiuj¹cy
    Rect.left=RectWrapper.Rect.left;
    Rect.right=RectWrapper.Rect.right;
    Rect.top=RectWrapper.Rect.top;
    Rect.bottom=RectWrapper.Rect.bottom;
}

TRectWrapper & TRectWrapper::operator =(const TRectWrapper & RectWrapper)
{
    Rect.left=RectWrapper.Rect.left;
    Rect.right=RectWrapper.Rect.right;
    Rect.top=RectWrapper.Rect.top;
    Rect.bottom=RectWrapper.Rect.bottom;
    return(*this);
}

TRectWrapper & TRectWrapper::operator =(const TRect & Rectangle)
{
    Rect.left=Rectangle.left;
    Rect.right=Rectangle.right;
    Rect.top=Rectangle.top;
    Rect.bottom=Rectangle.bottom;
    return(*this);
}



TRectWrapper::TRectWrapper(TRect & Rect1)
{
    //TODO: Add your source code here
    Rect.left=Rect1.left;
    Rect.top=Rect1.top;
    Rect.right=Rect1.right;
    Rect.bottom=Rect1.bottom;
}

void __fastcall TRectWrapper::Move(int xDelta, int yDelta)
{
    //TODO: Przesuwanie kwadratu
    Rect.Top+=yDelta;
    Rect.Bottom+=yDelta;
    Rect.Left+=xDelta;
    Rect.Right+=xDelta;
}

void __fastcall TRectWrapper::Height(int value)
{
    //TODO: Okreœlenie wysokoœci
    Rect.Bottom=Rect.Top+value;
}

void __fastcall TRectWrapper::Width(int value)
{
    //TODO: Okreœlenie szerokoœci
    Rect.Right=Rect.Left+value;
}

void __fastcall TRectWrapper::Center(TPoint & Point)
{
    Point.x=Rect.Left+Rect.Width()/2;
    Point.y=Rect.Top+Rect.Height()/2;
}
