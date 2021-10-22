//---------------------------------------------------------------------------

#ifndef translatorH
#define translatorH

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
//---------------------------------------------------------------------------
class TTranslator
{
private:
    AnsiString FLanguage;
    char FDelimiter;
    void __fastcall SetLanguage(AnsiString value);
    void __fastcall SetDelimiter(char value);
    void __fastcall Translate(void);
    unsigned int __fastcall GetItemCount();
    vector<AnsiString> Title;
    vector<AnsiString> Translation;
protected:

public:
    TTranslator();
    ~TTranslator();
    __property AnsiString Language  = { read=FLanguage, write=SetLanguage };
    TTranslator & operator =(const TTranslator & Translator);
    AnsiString & operator [](AnsiString TitleIterator);
    ofstream friend & operator <<(ofstream &out1,TTranslator &Translator);
    ifstream friend & operator >>(ifstream &in1,TTranslator &Translator);
    TTranslator(const TTranslator & Translator);
    __property char Delimiter  = { read=FDelimiter, write=SetDelimiter };
    __property unsigned int ItemCount  = { read=GetItemCount };
};
#endif
