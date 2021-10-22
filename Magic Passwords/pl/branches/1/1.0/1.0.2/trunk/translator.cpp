//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "translator.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

using namespace std;
#include <algorithm>
#include <functional>


TTranslator::TTranslator()
{
    //DONE: Konstruktor
    Title.clear();
    Translation.clear();
    FDelimiter=':';
    Language="en";
}

ofstream & operator <<(ofstream &out1,TTranslator &Translator)
{
    unsigned int i,c;
    c=Translator.Title.size();
    char buf[1000];
    for (i=0;i<c ;i++)
    {
        out1<<Translator.Title[i].c_str()<<":";
        out1<<Translator.Translation[i].c_str()<<"\n";
    }
    return(out1);
}

ifstream & operator >>(ifstream &in1,TTranslator &Translator)
{
    unsigned int i,c;
    char tbuf[1000];
    AnsiString tbuf1;
    Translator.Title.clear();
    Translator.Translation.clear();
    in1.seekg(0,ios_base::end);
    c=in1.tellg();
    in1.seekg(0,ios_base::beg);
    i=0;
    while (i<c)
    {
        in1.getline(tbuf,999,Translator.FDelimiter);
        tbuf1=tbuf;
        Translator.Title.push_back(tbuf1);
        i=in1.tellg();
        if (i>=c)
            break;
        in1.getline(tbuf,999);
        tbuf1=tbuf;
        Translator.Translation.push_back(tbuf1);
        i=in1.tellg();
        if (i>=c)
            break;
    }
    return(in1);
}

void __fastcall TTranslator::SetLanguage(AnsiString value)
{
    if(FLanguage != value) {
        AnsiString lang;
        lang="lang\\"+value+".lang";
        if (FileExists(lang))
        {
            FLanguage = value;
            Translate();
        }
    }
}

void __fastcall TTranslator::SetDelimiter(char value)
{
    //DONE: Zmiana separatora
    if (FDelimiter != value)
    {
        FDelimiter=value;
        Translate();
    }

}

void __fastcall TTranslator::Translate(void)
{
    //DONE: Pobieranie danych
    ifstream in1;
    AnsiString lang;
    lang="lang\\"+FLanguage+".lang";
    if (FileExists(lang))
    {
        in1.open(lang.c_str());
        in1>>(*this);
        if (!in1)
            throw Exception("Error reading translation file!!");
        /* DONE -oMoneetor -cT³umaczenie : Dokoñczyæ wczytywanie dla zmiany jêzyka. */
        in1.close();
    }
    else
    {
        throw Exception("No translation file!");
    }
}

unsigned int __fastcall TTranslator::GetItemCount()
{
    //DONE: Pobieranie iloœci danych
    return(Title.size());
}

TTranslator::TTranslator(const TTranslator & Translator)
{
    //DONE: Konstruktor kopiuj¹cy
    unsigned int c;
    FDelimiter=Translator.FDelimiter;
    FLanguage=Translator.FLanguage;
    c=Title.size();
    Title.resize(c);
    Translation.resize(c);
    Title=Translator.Title;
    Translation=Translator.Translation;
}

TTranslator::~TTranslator()
{
    //DONE: Destruktor
    Title.clear();
    Translation.clear();
}

TTranslator & TTranslator::operator =(const TTranslator & Translator)
{
    unsigned int c;
    FDelimiter=Translator.FDelimiter;
    FLanguage=Translator.FLanguage;
    c=Title.size();
    Title.resize(c);
    Translation.resize(c);
    Title=Translator.Title;
    Translation=Translator.Translation;
    return(*this);
}

AnsiString & TTranslator::operator [](AnsiString TitleIterator)
{
    unsigned i,c;
    c=Title.size();
    i=0;
    AnsiString *pos;
    while ((i<c)&&(Title[i]!=TitleIterator))
    {
        i++;
    }
    if (i==c)
    {
        //nie znaleziono!
        Title.push_back(TitleIterator);
        Translation.push_back(TitleIterator);
        if (i>0)
            i--;
        pos=Translation.begin()+i;
    }
    else
    {
        //znalezione
        pos=Translation.begin()+i;
    }
    return (*pos);
}
