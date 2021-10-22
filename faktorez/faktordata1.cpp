//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "faktordata1.h"
using namespace std;

#include <queue>

//---------------------------------------------------------------------------

#pragma package(smart_init)

char pass0[]="Bardzo tajne has³o";

TFaktorzData::TFaktorzData()
{
    //TODO: Add your source code here
    TopMargin=BottomMargin=LeftMargin=RightMagin=10;
    FontSize=8;
    HeaderFontSize=12;
    LastNumber=1;
    WindowS.resize(1);
}

TFaktorzData::TFaktorzData(const TFaktorzData & FaktorzData)
{
    //TODO: Add your source code here
    TopMargin=FaktorzData.TopMargin;
    LeftMargin=FaktorzData.LeftMargin;
    BottomMargin=FaktorzData.BottomMargin;
    RightMagin=FaktorzData.RightMagin;
    FontSize=FaktorzData.FontSize;
    HeaderFontSize=FaktorzData.HeaderFontSize;
    Seller=FaktorzData.Seller;
    NIP=FaktorzData.NIP;
    REGON=FaktorzData.REGON;
    Bank=FaktorzData.Bank;
    Account=FaktorzData.Account;
    LogoFileName=FaktorzData.LogoFileName;
    LastNumber=FaktorzData.LastNumber;
    PrintFields=FaktorzData.PrintFields;
    WindowS.resize(FaktorzData.WindowS.size());
    WindowS=FaktorzData.WindowS;
    Datasources.resize(FaktorzData.Datasources.size());
    Datasources=FaktorzData.Datasources;
    UsedDSN=FaktorzData.UsedDSN;
}

TFaktorzData & TFaktorzData::operator =(const TFaktorzData & FaktorzData)
{
    int c;
    TopMargin=FaktorzData.TopMargin;
    LeftMargin=FaktorzData.LeftMargin;
    BottomMargin=FaktorzData.BottomMargin;
    RightMagin=FaktorzData.RightMagin;
    FontSize=FaktorzData.FontSize;
    HeaderFontSize=FaktorzData.HeaderFontSize;
    Seller=FaktorzData.Seller;
    NIP=FaktorzData.NIP;
    REGON=FaktorzData.REGON;
    Bank=FaktorzData.Bank;
    Account=FaktorzData.Account;
    LogoFileName=FaktorzData.LogoFileName;
    LastNumber=FaktorzData.LastNumber;
    c=FaktorzData.PrintFields.size();
    PrintFields.resize(c);
    PrintFields=FaktorzData.PrintFields;
    WindowS.resize(FaktorzData.WindowS.size());
    WindowS=FaktorzData.WindowS;
    Datasources.resize(FaktorzData.Datasources.size());
    Datasources=FaktorzData.Datasources;
    UsedDSN=FaktorzData.UsedDSN;
    return(*this);
}

TFaktorzData::~TFaktorzData()
{
    //TODO: Add your source code here
    PrintFields.clear();
    WindowS.clear();
}


TPrintField::TPrintField()
{
TRect pa(10,10,50,20);
    //TODO: Konstruktor Zwyk³y
    Header=false;
    Bold=false;
    FieldName="Nowe pole";
    Alignment=taLeftJustify;
    FResolution=300;
    SetArea(pa);
    Visible=true;
    FixedHPos=true;
    FixedVPos=true;
}

TPrintField::TPrintField(const TPrintField & PrintField)
{
    //TODO: Add your source code here
    Header=PrintField.Header;
    Bold=PrintField.Bold;
    FieldName=PrintField.FieldName;
    Alignment=PrintField.Alignment;
    FResolution=PrintField.FResolution;
    Area.Left=PrintField.Area.Left;
    Area.Right=PrintField.Area.Right;
    Area.Top=PrintField.Area.Top;
    Area.Bottom=PrintField.Area.Bottom;
    Visible=PrintField.Visible;
    FixedHPos=PrintField.FixedHPos;
    FixedVPos=PrintField.FixedVPos;
}

TPrintField & TPrintField::operator =(const TPrintField & PrintField)
{
    Header=PrintField.Header;
    Bold=PrintField.Bold;
    FieldName=PrintField.FieldName;
    Alignment=PrintField.Alignment;
    FResolution=PrintField.FResolution;
    Area.Left=PrintField.Area.Left;
    Area.Right=PrintField.Area.Right;
    Area.Top=PrintField.Area.Top;
    Area.Bottom=PrintField.Area.Bottom;
    Visible=PrintField.Visible;
    FixedHPos=PrintField.FixedHPos;
    FixedVPos=PrintField.FixedVPos;
    return(*this);
}

TPrintField::~TPrintField()
{
    //TODO: Add your source code here
    FieldName="";
}

void __fastcall TPrintField::SetResolution(int value)
{
TRect r1;
    if((FResolution != value)&&(value>0))
    {
        FResolution = value;
    }
}

int TPrintField::mmToPixel(int Milimeters)
{
    //TODO: Przelicza milimetry na piksele
    return(mmToPixel(Milimeters,FResolution));
}

int TPrintField::mmToPixel(int Milimeters,int DPI)
{
    int pixels;
    //TODO: Przelicza milimetry na piksele
    pixels=Milimeters*DPI*10;
    pixels/=254;
    return pixels;
}

int TPrintField::PixelTomm(int Pixels)
{
    //TODO: Przelicza piksele na milimetry
    return(PixelTomm(Pixels,FResolution));
}

int TPrintField::PixelTomm(int Pixels, int DPI)
{
    int mm;
    //TODO: Przelicza piksele na milimetry
    mm=Pixels*254;
    mm=mm/DPI/10;
    return mm;
}


int __fastcall TPrintField::GetResolution(void)
{
    //TODO: Okreœla rozdzielczoœæ
    return(FResolution);
}

void TPrintField::SetArea(TRect & area)
{
    //TODO: Okreœla obszar na papierze
    Area.Left=area.Left;
    Area.Right=area.Right;
    Area.Bottom=area.Bottom;
    Area.Top=area.Top;
}

void TPrintField::GetArea(TRect & area)
{
    //TODO: Pobiera obszar w milimetrach
    area.Left=Area.Left;
    area.Right=Area.Right;
    area.Top=Area.Top;
    area.Bottom=Area.Bottom;
}

void TPrintField::GetPrintArea(TRect & PrintArea)
{
    //TODO: PObiera obszar wydruku
    PrintArea.Left=mmToPixel(Area.Left);
    PrintArea.Right=mmToPixel(Area.Right);
    PrintArea.Top=mmToPixel(Area.Top);
    PrintArea.Bottom=mmToPixel(Area.Bottom);
}

int TFaktorzData::PrintFieldsCount(void)
{
    //TODO: Zwraca iloœæ pól
    return(PrintFields.size());
}

int __fastcall TFaktorzData::FieldNumber(AnsiString fname)
{
    unsigned int i,c;
    //TODO: Szuka pola o podanej nazwie
    c=PrintFields.size();
    for (i=0;i<c ;i++)
    {
        if (PrintFields[i].FieldName==fname)
        {
            return(i);
        }
    }
    return(-1);
}

void TPrintField::SetPrintArea(TRect & PrintArea)
{
    //TODO: okreœla pole
    Area.Left=PixelTomm(PrintArea.Left);
    Area.Right=PixelTomm(PrintArea.Right);
    Area.Top=PixelTomm(PrintArea.Top);
    Area.Bottom=PixelTomm(PrintArea.Bottom);
}

void __fastcall TPrintField::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Zapisuje pole do Pliku Ini
    IniFile->WriteString(Section,"FieldName",FieldName);
    IniFile->WriteInteger(Section,"Top",Area.Top);
    IniFile->WriteInteger(Section,"Left",Area.Left);
    IniFile->WriteInteger(Section,"Right",Area.Right);
    IniFile->WriteInteger(Section,"Bottom",Area.Bottom);
    IniFile->WriteBool(Section,"Bold",Bold);
    IniFile->WriteBool(Section,"Header",Header);
    IniFile->WriteBool(Section,"FixedHPos",FixedHPos);
    IniFile->WriteBool(Section,"FixedVPos",FixedVPos);
    IniFile->WriteInteger(Section,"Resolution",FResolution);
    IniFile->WriteBool(Section,"Visible",Visible);
}

void __fastcall TPrintField::LoadFromIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: Odczytuje pole z pliku Ini
    FieldName=IniFile->ReadString(Section,"FieldName",FieldName);
    Area.Top=IniFile->ReadInteger(Section,"Top",Area.Top);
    Area.Left=IniFile->ReadInteger(Section,"Left",Area.Left);
    Area.Right=IniFile->ReadInteger(Section,"Right",Area.Right);
    Area.Bottom=IniFile->ReadInteger(Section,"Bottom",Area.Bottom);
    Bold=IniFile->ReadBool(Section,"Bold",Bold);
    Header=IniFile->ReadBool(Section,"Header",Header);
    FixedHPos=IniFile->ReadBool(Section,"FixedHPos",FixedHPos);
    FixedVPos=IniFile->ReadBool(Section,"FixedVPos",FixedVPos);
    FResolution=IniFile->ReadInteger(Section,"Resolution",FResolution);
    Visible=IniFile->ReadBool(Section,"Visible",Visible);
}

void __fastcall TFaktorzData::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    int i,c;
    AnsiString tbuf1;
    TPrintField pf1;
    //TODO: Zapisuje dane dokumentu
    IniFile->WriteInteger(Section,"TopMargin",TopMargin);
    IniFile->WriteInteger(Section,"LeftMargin",LeftMargin);
    IniFile->WriteInteger(Section,"RightMagin",RightMagin);
    IniFile->WriteInteger(Section,"BottomMargin",BottomMargin);
    IniFile->WriteInteger(Section,"FontSize",FontSize);
    IniFile->WriteInteger(Section,"HeaderFontSize",HeaderFontSize);
    Seller.SaveToIni(IniFile,Section);
    IniFile->WriteString(Section,"NIP",NIP);
    IniFile->WriteString(Section,"REGON",REGON);
    IniFile->WriteString(Section,"Bank",Bank);
    IniFile->WriteString(Section,"Account",Account);
    IniFile->WriteString(Section,"LogoFileName",LogoFileName);
    IniFile->WriteInteger(Section,"LastNumber",LastNumber);
    c=PrintFields.size();
    IniFile->WriteInteger(Section,"PrintFieldCount",c);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_printfield_"+IntToStr(i);
        pf1=PrintFields[i];
        pf1.SaveToIni(IniFile,tbuf1);
    }
    c=WindowS.size();
    IniFile->WriteInteger(Section,"WindowCount",c);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_window_"+IntToStr(i);
        WindowS[i].SaveToIni(IniFile,tbuf1);
    }
    c=Datasources.size();
    IniFile->WriteInteger(Section,"Datasources",Datasources.size());
    IniFile->WriteInteger(Section,"UsedDSN",UsedDSN);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_datasource_"+IntToStr(i);
        Datasources[i].SaveToIni(IniFile,tbuf1);
    }
}

void __fastcall TFaktorzData::ReadFromIni(TIniFile * IniFile, AnsiString Section)
{
    int i,c;
    AnsiString tbuf1;
    //TODO: Odczytuje dane dokumentu z pliku Ini
    TopMargin=IniFile->ReadInteger(Section,"TopMargin",TopMargin);
    LeftMargin=IniFile->ReadInteger(Section,"LeftMargin",LeftMargin);
    RightMagin=IniFile->ReadInteger(Section,"RightMagin",RightMagin);
    BottomMargin=IniFile->ReadInteger(Section,"BottomMargin",BottomMargin);
    FontSize=IniFile->ReadInteger(Section,"FontSize",FontSize);
    HeaderFontSize=IniFile->ReadInteger(Section,"HeaderFontSize",HeaderFontSize);
    Seller.ReadFromIni(IniFile,Section);
    NIP=IniFile->ReadString(Section,"NIP",NIP);
    REGON=IniFile->ReadString(Section,"REGON",REGON);
    Bank=IniFile->ReadString(Section,"Bank",Bank);
    Account=IniFile->ReadString(Section,"Account",Account);
    LogoFileName=IniFile->ReadString(Section,"LogoFileName",LogoFileName);
    LastNumber=IniFile->ReadInteger(Section,"LastNumber",LastNumber);
    c=IniFile->ReadInteger(Section,"PrintFieldCount",0);
    PrintFields.resize(c);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_printfield_"+IntToStr(i);
        PrintFields[i].LoadFromIni(IniFile,tbuf1);
    }
    c=IniFile->ReadInteger(Section,"WindowCount",WindowS.size());
    WindowS.resize(c);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_window_"+IntToStr(i);
        WindowS[i].LoadFromIni(IniFile,tbuf1);
    }
    c=IniFile->ReadInteger(Section,"Datasources",Datasources.size());
    Datasources.resize(c);
    UsedDSN=IniFile->ReadInteger(Section,"UsedDSN",UsedDSN);
    for (i=0;i<c ;i++)
    {
        tbuf1=Section+"_datasource_"+IntToStr(i);
        Datasources[i].ReadFromIni(IniFile,tbuf1);
    }
}

TArticle::TArticle()
{
    //TODO: Artyku³ tworzenie
    Price=1;
    Quantity=1;
    Rabat=0;
    VATP=0.22;
    jm="szt";
    Name="Nowy towar";
}

TArticle::TArticle(const TArticle & Article)
{
    //TODO: Add your source code here
    Name=Article.Name;
    Price=Article.Price;
    Quantity=Article.Quantity;
    Rabat=Article.Rabat;
    PKWIU=Article.PKWIU;
    VATP=Article.VATP;
    jm=Article.jm;
}

TArticle & TArticle::operator =(const TArticle & Article)
{
    Name=Article.Name;
    Price=Article.Price;
    Quantity=Article.Quantity;
    Rabat=Article.Rabat;
    PKWIU=Article.PKWIU;
    VATP=Article.VATP;
    return(*this);
}

TArticle::~TArticle() { }

double __fastcall TArticle::Netto(void)
{
    //TODO: Wartoœæ Netto towaru
    return(Price*Quantity);
}

double __fastcall TArticle::VAT(void)
{
    //TODO: VAT
    return(Netto()*VATP*0.01);
}

double __fastcall TArticle::Brutto(void)
{
    //TODO: Wartoœæ Brutto
    return(Netto()+VAT());
}

AnsiString TArticle::FormatValue(double value, bool percent,int precision)
{
    AnsiString tbuf1;
    int buf;
    int nom;
    //TODO: Formatuje dane
    if (percent)
    {
        if (precision<=0)
        {
            buf=value*100;
            if (precision<0)
            {
                nom=pow10((-precision));
                buf=buf/nom*nom;
            }
            tbuf1.sprintf("%d %%",buf);
        }
        else
        {
            tbuf1=FloatToStrF(value,ffFixed,18,precision);
            tbuf1=tbuf1+" %";
        }
    }
    else
    {
        if (precision<=0)
        {
            buf=value*100;
            if (precision<0)
            {
                nom=pow10((-precision));
                buf=buf/nom*nom;
            }
            tbuf1=IntToStr(buf);
        }
        else
        {
            tbuf1=FloatToStrF(value,ffFixed,18,precision);
        }
    }
    return(tbuf1);
}

TDocumentData::TDocumentData()
{
    //TODO: KOnstruktor domyœlny
    DocumentType='F';
    UseColons=true;
    DataWyst=Now();
    DataSprz=Now();
    Number=1;
    ShowItemCurrency=ShowTaxCurrency=0;
    Platnosc="Przelew";
}

TDocumentData::TDocumentData(const TDocumentData & DocumentData)
{
    //TODO: Konstruktor kopiuj¹cy
    DocumentType=DocumentData.DocumentType;
    UseColons=DocumentData.UseColons;
    Stock.resize(DocumentData.Stock.size());
    Stock=DocumentData.Stock;
    DataWyst=DocumentData.DataWyst;
    DataSprz=DocumentData.DataSprz;
    DataZapl=DocumentData.DataZapl;
    Number=DocumentData.Number;
    NIP=DocumentData.NIP;
    REGON=DocumentData.REGON;
    PrintMaster=DocumentData.PrintMaster;
    PrintCopy=DocumentData.PrintCopy;
    Buyer=DocumentData.Buyer;
    VATPTax.resize(DocumentData.VATPTax.size());
    VATPTax=DocumentData.VATPTax;
    ShowItemCurrency=DocumentData.ShowItemCurrency;
    ShowTaxCurrency=DocumentData.ShowTaxCurrency;
    Platnosc=DocumentData.Platnosc;
}

TDocumentData & TDocumentData::operator =(const TDocumentData & DocumentData)
{
    //TODO: Operator przypisania
    DocumentType=DocumentData.DocumentType;
    UseColons=DocumentData.UseColons;
    Stock.resize(DocumentData.Stock.size());
    Stock=DocumentData.Stock;
    DataWyst=DocumentData.DataWyst;
    DataSprz=DocumentData.DataSprz;
    DataZapl=DocumentData.DataZapl;
    Number=DocumentData.Number;
    NIP=DocumentData.NIP;
    REGON=DocumentData.REGON;
    PrintMaster=DocumentData.PrintMaster;
    PrintCopy=DocumentData.PrintCopy;
    Buyer=DocumentData.Buyer;
    VATPTax.resize(DocumentData.VATPTax.size());
    VATPTax=DocumentData.VATPTax;
    ShowItemCurrency=DocumentData.ShowItemCurrency;
    ShowTaxCurrency=DocumentData.ShowTaxCurrency;
    Platnosc=DocumentData.Platnosc;
    return(*this);
}

TDocumentData::~TDocumentData()
{
    //TODO: destruktor
    Stock.clear();
    VATPTax.clear();
}

AnsiString __fastcall TDocumentData::SetDotStyle(AnsiString value)
{
    int i;
    AnsiString ret=value;
    //TODO: Okreœla styl przecinka
    if (UseColons)
    {
        i=value.Pos(".");
        if (i>0)
            value[i]=',';
    }
    else
    {
        i=value.Pos(",");
        if (i>0)
            value[i]='.';
    }
    return ret;
}

AnsiString __fastcall TDocumentData::VAT(int index)
{
    AnsiString vat1;
    double vat;
    int c;
    //TODO: Wartoœæ VAT
    c=Stock.size();
    if ((index<c)&&(index>=0))
    {
        vat=Stock[index].VAT();
        vat1=Stock[index].FormatValue(vat,false,2);
        vat1=SetDotStyle(vat1);
        if (ShowItemCurrency)
            vat1=vat1+"z³";
    }
    else
    {
        vat1="";
    }
    return vat1;
}

AnsiString __fastcall TDocumentData::Netto(int index)
{
    AnsiString netto1;
    double netto;
    int c;
    c=Stock.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        netto=Stock[index].Netto();
        netto1=Stock[index].FormatValue(netto,false,2);
        netto1=SetDotStyle(netto1);
        if (ShowItemCurrency)
            netto1=netto1+"z³";
    }
    else
    {
        netto1="";
    }
    return netto;
}

AnsiString __fastcall TDocumentData::Quantity(int index)
{
    AnsiString qty1;
    double qty;
    int c;
    c=Stock.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        qty=Stock[index].Quantity;
        if (QuantityFloat)
        {
            qty1=Stock[index].FormatValue(qty,false,2);
            qty1=SetDotStyle(qty1);
        }
        else
            qty1=Stock[index].FormatValue(qty,false,0);
    }
    else
    {
        qty1="";
    }
    return qty1;
}

AnsiString __fastcall TDocumentData::Rabat(int index)
{
    AnsiString rabat1;
    double rabat;
    int c;
    c=Stock.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        rabat=Stock[index].Rabat;
        rabat1=Stock[index].FormatValue(rabat,true,0);
    }
    else
    {
        rabat1="";
    }
    return rabat1;
}

AnsiString __fastcall TDocumentData::VATP(int index)
{
    AnsiString vatp1;
    double vatp;
    int c;
    c=Stock.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        vatp=Stock[index].VATP;
        if (VATFloat)
        {
            vatp1=Stock[index].FormatValue(vatp,true,2);
            vatp1=SetDotStyle(vatp1);
        }
        else
            vatp1=Stock[index].FormatValue(vatp,true,0);
    }
    else
    {
        vatp1="";
    }
    return vatp1;
}

AnsiString __fastcall TDocumentData::Brutto(int index)
{
    AnsiString brutto1;
    double brutto;
    int c;
    c=Stock.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        brutto=Stock[index].Brutto();
        brutto1=Stock[index].FormatValue(brutto,false,2);
        brutto1=SetDotStyle(brutto1);
        if (ShowItemCurrency)
            brutto1=brutto1+"z³";
    }
    else
    {
        brutto1="";
    }
    return brutto1;
}

AnsiString __fastcall TDocumentData::jm(int index)
{
    AnsiString jm1;
    int c;
    c=Stock.size();
    if ((index<c)&&(index>=0))
    {
        jm1=Stock[index].jm;
    }
    else
    {
        jm1="";
    }
    return jm1;
}



void __fastcall TDocumentData::Add(int pos, AnsiString nazwa,
    AnsiString PKWIU, double qty, AnsiString jm1, double rabat, double price,
    double vatp)
{
    TArticle art1;
    //TODO: Dodawanie nowej pozycji
    art1.PKWIU=PKWIU;
    art1.Quantity=qty;
    art1.jm=jm1;
    art1.Rabat=rabat;
    art1.Price=price;
    art1.VATP=vatp;
    Stock.push_back(art1);
    AddToTaxTable(vatp);
}

void __fastcall TDocumentData::Clear(void)
{
    //TODO: czyszczenie listy towarów
    Stock.clear();
    VATPTax.clear();
}

void __fastcall TDocumentData::Delete(int index)
{
    //TODO: Usuwanie towaru z listy
    int c;
    int i;
    double vatp;
    TArticle art1;
    if ((!Stock.empty())&&(index>=0))
    {
        c=Stock.size();
        if ((index<c))
        {
            art1=Stock[i];
            vatp=art1.VATP;
            Stock.erase(Stock.begin()+index);
            VerifyTaxTable(vatp);
        }
    }
}

void __fastcall TDocumentData::Insert(int pos, AnsiString nazwa,
    AnsiString PKWIU, double qty, AnsiString jm1, double rabat, double price,
    double vatp)
{
    TArticle art1;
    int c;
    //TODO: Wstawia towar na okreœlon¹ pozycjê
    if ((!Stock.empty())&&(pos>=0))
    {
        art1.PKWIU=PKWIU;
        art1.Quantity=qty;
        art1.jm=jm1;
        art1.Rabat=rabat;
        art1.Price=price;
        art1.VATP=vatp;
        art1.Name=nazwa;
        c=Stock.size();
        if ((pos<c))
        {
            Stock.insert(Stock.begin()+pos,art1);
        }
        else
        {
            Stock.push_back(art1);
        }
    }
    AddToTaxTable(vatp);
}

AnsiString __fastcall TDocumentData::Price(int index)
{
    AnsiString price1;
    double price;
    int c;
    c=Stock.size();
    if ((index<c)&&(index>=0))
    {
        price=Stock[index].Price;
        price1=Stock[index].FormatValue(price,false,2);
        price1=SetDotStyle(price1);
        if (ShowItemCurrency)
            price1=price1+"z³";
    }
    else
    {
        price1="";
    }
    return price1;
}

TAdres::TAdres()
{
    //TODO: Add your source code here
}

TAdres::TAdres(const TAdres & Adres)
{
    //TODO: Add your source code here
    Name.resize(Adres.Name.size());
    Name=Adres.Name;
    Adress.resize(Adres.Adress.size());
    Adress=Adres.Adress;
    zip=Adres.zip;
    city=Adres.city;
}

TAdres::~TAdres()
{
    //TODO: Add your source code here
    Name.clear();
    Adress.clear();
}

TAdres & TAdres::operator =(const TAdres & Adres)
{
    Name.resize(Adres.Name.size());
    Name=Adres.Name;
    Adress.resize(Adres.Adress.size());
    Adress=Adres.Adress;
    zip=Adres.zip;
    city=Adres.city;
    return(*this);
}


void __fastcall TAdres::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    int i,c;
    AnsiString tbuf1;
    //TODO: Add your source code here
    c=Adress.size();
    IniFile->WriteInteger(Section,"AddressLines",c);
    for (i=0;i<c ;i++)
    {
        tbuf1="Address_"+IntToStr(i);
        IniFile->WriteString(Section,tbuf1,Adress[i]);
    }
    c=Name.size();
    IniFile->WriteInteger(Section,"NameLines",c);
    for (i=0;i<c ;i++)
    {
        tbuf1="Name_"+IntToStr(i);
        IniFile->WriteString(Section,tbuf1,Name[i]);
    }
    IniFile->WriteString(Section,"zip",zip);
    IniFile->WriteString(Section,"city",city);
}

void __fastcall TAdres::ReadFromIni(TIniFile * IniFile, AnsiString Section)
{
    int i,c;
    AnsiString tbuf1;
    //TODO: Add your source code here
    c=IniFile->ReadInteger(Section,"AddressLines",c);
    Adress.resize(c);
    for (i=0;i<c ;i++)
    {
        tbuf1="Address_"+IntToStr(i);
        Adress[i]=IniFile->ReadString(Section,tbuf1,Adress[i]);
    }
    c=IniFile->ReadInteger(Section,"NameLines",0);
    Name.resize(c);
    for (i=0;i<c ;i++)
    {
        tbuf1="Name_"+IntToStr(i);
        Name[i]=IniFile->ReadString(Section,tbuf1,Name[i]);
    }
    zip=IniFile->ReadString(Section,"zip",zip);
    city=IniFile->ReadString(Section,"city",city);
}

TDatabaseCfgData::TDatabaseCfgData() { }

TDatabaseCfgData::TDatabaseCfgData(const TDatabaseCfgData & DatabaseData)
{
    DBEngine=DatabaseData.DBEngine;
    UseLogin=DatabaseData.UseLogin;
    UsePassword=DatabaseData.UsePassword;
    Login=DatabaseData.Login;
    FPassword=DatabaseData.FPassword;
    SavePassword=DatabaseData.SavePassword;
    DSN=DatabaseData.DSN;
}

TDatabaseCfgData::~TDatabaseCfgData() { }

void __fastcall TDatabaseCfgData::Password(AnsiString pass)
{
    if (pass.IsEmpty())
    {
        FPassword="";
        return;
    }
    AnsiString tbuf1,tbuf2;
    BlowFish.Initialize(pass0,strlen(pass0));
    vector<unsigned char> buf1,buf2;
    int i,l,l2;
    //TODO: Add your source code here
    l=pass.Length();
    l++;
    buf1.resize(l,0x00);
    for (i=1;i<l ;i++)
    {
        buf1[i-1]=pass[i];
    }
    l2=BlowFish.GetOutputLength(l);
    buf1.resize(l2,0x00);
    buf2.resize(l2,0x00);
    BlowFish.Encode(buf1.begin(),buf2.begin(),l2);
    FPassword="";
    l=buf1.size();
    for (i=0;i<l ;i++)
    {
        tbuf1=IntToHex((int)buf2[i],2);
        FPassword=FPassword+tbuf1;
    }
}

AnsiString __fastcall TDatabaseCfgData::Password(void)
{
BlowFish.Initialize(pass0,strlen(pass0));
AnsiString pass1;
unsigned int cache;
char *buf0;
vector<unsigned char> buf1,buf2,buf4;
queue<unsigned char> buf3;
int i,l,l2;
    //TODO: Add your source code here
    if (FPassword.IsEmpty())
        return FPassword;
    l=FPassword.Length();
    l++;
    buf1.resize(l,0x00);
    buf4.resize(3,0x00);
    buf0=new char[l];
    strcpy(buf0,FPassword.c_str());
    l--;
    for (i=0;i<l ;i++)
    {
        buf1[i]=buf0[i];
    }
    delete[] buf0;
    i=0;
    while (i<l)
    {
        buf4[0]=buf1[i];
        i++;
        buf4[1]=buf1[i];
        i++;
        cache=Hex2Int(buf4.begin());
        buf3.push((unsigned char)cache);
    }
    l2=buf3.size();
    buf1.resize(l2,0x00);
    buf1.assign(l2,0x00);
    for (i=0;i<l2 ;i++)
    {
        buf1[i]=buf3.front();
        buf3.pop();
    }
    buf2.resize(l2,0x00);
    buf2.assign(l2,0x00);
    BlowFish.Decode(buf1.begin(),buf2.begin(),l2);
    for (i=0;i<l2 ;i++)
    {
        if (buf2[i]==0)
        {
            buf2.resize(i+1);
        }
    }
    l=buf2.size();
    buf0=new char[l];
    for (i=0;i<l ;i++)
    {
        buf0[i]=buf2[i];
    }
    pass1=buf0;
    delete[] buf0;
    return pass1;
}

unsigned int __fastcall TDatabaseCfgData::Hex2Int(char * hex)
{
unsigned int buf=0;
char buft[3];
char a,b;
    //TODO: zamiana hexa na bajty
    strcpy(buft,hex);
    strlwr(buft);
    a=buft[0]-'a';
    a+=10;
    b=buft[0]-'0';
    if (((buft[0]>='0')&&(buft[0]<='9'))||((buft[0]>='a')&&(buft[0]<='f')))
    {
        if ((buft[0]>='0')&&(buft[0]<='9'))
        {
            buf+=b;
        }
        else
        {
            buf+=a;
        }
    }
    buf<<=4;
    a=buft[1]-'a';
    a+=10;
    b=buft[1]-'0';
    if (((buft[1]>='0')&&(buft[1]<='9'))||((buft[1]>='a')&&(buft[1]<='f')))
    {
        if ((buft[1]>='0')&&(buft[1]<='9'))
        {
            buf+=b;
        }
        else
        {
            buf+=a;
        }
    }
    return(buf);
}

void __fastcall TDatabaseCfgData::SaveToIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: zapis danych o bazach
    IniFile->WriteString(Section,"Login",Login);
    IniFile->WriteString(Section,"DSN",DSN);
    if ((SavePassword)&&(UsePassword))
        IniFile->WriteString(Section,"Password",FPassword);
    else
    {
        IniFile->DeleteKey(Section,"Password");
    }
    IniFile->WriteString(Section,"DBEngine",DBEngine);
    IniFile->WriteBool(Section,"UseLogin",UseLogin);
    IniFile->WriteBool(Section,"UsePassword",UsePassword);
    IniFile->WriteBool(Section,"SavePassword",SavePassword);
}

void __fastcall TDatabaseCfgData::ReadFromIni(TIniFile * IniFile, AnsiString Section)
{
    //TODO: odczyt danych o bazach
    DSN=IniFile->ReadString(Section,"DSN",DSN);
    Login=IniFile->ReadString(Section,"Login",Login);
    FPassword=IniFile->ReadString(Section,"Password",FPassword);
    UsePassword=IniFile->ReadBool(Section,"UsePassword",UsePassword);
    SavePassword=IniFile->ReadBool(Section,"SavePassword",SavePassword);
    UseLogin=IniFile->ReadBool(Section,"UseLogin",UseLogin);
    DBEngine=IniFile->ReadString(Section,"DBEngine",DBEngine);
}

TDatabaseCfgData & TDatabaseCfgData::operator =(const TDatabaseCfgData & DatabaseCfgData)
{
    DBEngine=DatabaseCfgData.DBEngine;
    UseLogin=DatabaseCfgData.UseLogin;
    UsePassword=DatabaseCfgData.UsePassword;
    Login=DatabaseCfgData.Login;
    FPassword=DatabaseCfgData.FPassword;
    DSN=DatabaseCfgData.DSN;
    SavePassword=DatabaseCfgData.SavePassword;
    return(*this);
}



void TFaktorzData::GetDatasources(void)
{
    vector<TRegDataType> ValueTypes;
    bool noadd;
    TRegDataType vt1;
    TStrings *str1,*str2;
    TRegistry *reg1;
    AnsiString tbuf1,tbuf2;
    Datasources.clear();
    TDatabaseCfgData db1;
    int i,j;
    int c,c2;
    //TODO: Add your source code here
    UsedDSN=0;
    reg1=new TRegistry;
    str1=new TStringList;
    str2=new TStringList;
    reg1->RootKey=HKEY_CURRENT_USER;
    reg1->OpenKey("Software\\ODBC\\ODBC.INI\\ODBC Data Sources",false);
    reg1->GetValueNames(str1);
    c=str1->Count;
    for (i=0;i<c ;i++)
    {
        tbuf1=reg1->ReadString(str1->Strings[i]);
        reg1->CloseKey();
        noadd=true;
        if (tbuf1=="MySQL ODBC 3.51 Driver")
        {
            db1.DSN=str1->Strings[i];
            db1.UsePassword=true;
            db1.UseLogin=true;
            db1.DBEngine=tbuf1;
            db1.SavePassword=false;
            tbuf2="Software\\ODBC\\ODBC.INI\\"+str1->Strings[i];
            reg1->OpenKey(tbuf2,false);
            reg1->GetValueNames(str2);
            c2=str2->Count;
            ValueTypes.clear();
            ValueTypes.resize(c2);
            for (j=0;j<c2 ;j++)
            {
                tbuf1=str2->Strings[j];
                vt1=reg1->GetDataType(tbuf1);
                ValueTypes[j]=vt1;
            }
            for (j=0;j<c2 ;j++)
            {
                if (ValueTypes[j]==rdString)
                {
                    if (str2->Strings[j]=="Password")
                    {
                        db1.SavePassword=true;
                        tbuf2=reg1->ReadString("Password");
                        db1.Password(tbuf2);
                    }
                    if (str2->Strings[j]=="User")
                    {
                        tbuf2=reg1->ReadString("User");
                        db1.Login=tbuf2;
                    }
                }
            }
            noadd=false;
        }
        if (tbuf1=="SQLite3 ODBC Driver")
        {
            db1.DSN=str1->Strings[i];
            db1.Login="";
            db1.Password("");
            db1.UsePassword=false;
            db1.UseLogin=false;
            db1.SavePassword=false;
            db1.DBEngine=tbuf1;
            noadd=false;
        }
        reg1->CloseKey();
        reg1->OpenKey("Software\\ODBC\\ODBC.INI\\ODBC Data Sources",false);
        if (!noadd)
            Datasources.push_back(db1);
    }
}

void TDatabaseCfgData::SetDatabase(TDatabase * Database)
{
    AnsiString tbuf1;
    //TODO: Add your source code here
    Database->Connected=false;
    if (UseLogin)
    {
        if (SavePassword)
        {
            Database->LoginPrompt=false;
            Database->Params->Clear();
            tbuf1="Login="+Login;
            Database->Params->Add(tbuf1);
            tbuf1="Password="+(Password());
            Database->Params->Add(tbuf1);
        }
        else
        {
            Database->LoginPrompt=true;
        }
    }
    else
    {
        Database->LoginPrompt=false;
        Database->Params->Clear();
    }
}

int __fastcall TArticle::GetArticleFromDB(TQuery * Query, int Pos)
{
    int id;
    TLocateOptions Opts;
    //TODO: Odczyt towaru z bazy danych
    Opts.Clear();
    if (Query->IsEmpty())
    {
        return(-1);
    }
    id=Query->FieldByName("id_fakt")->Value;
    if (id!=Pos)
    {
        if (id>Pos)
        {
            Query->First();
        }
        if (Query->Locate("id_fakt",IntToStr(Pos),Opts))
        {
            Name=Query->FieldByName("nazwa_art")->Text;
            PKWIU=Query->FieldByName("PKWIU")->Text;
            jm=Query->FieldByName("jm")->Text;
            Quantity=Query->FieldByName("qty")->Value;
            Rabat=Query->FieldByName("rabat")->Value;
            VATP=Query->FieldByName("VATP")->Value;
            Price=Query->FieldByName("Price")->Value;
            jm=Query->FieldByName("jm")->Text;
        }
        else
            return(-1);
    }
    else
    {
        Name=Query->FieldByName("nazwa_art")->Text;
        PKWIU=Query->FieldByName("PKWIU")->Text;
        jm=Query->FieldByName("jm")->Text;
        Quantity=Query->FieldByName("qty")->Value;
        Rabat=Query->FieldByName("rabat")->Value;
        VATP=Query->FieldByName("VATP")->Value;
        Price=Query->FieldByName("Price")->Value;
        jm=Query->FieldByName("jm")->Text;
    }
    Query->Next();
    if (Query->Eof)
        return(0);
    id=Query->FieldByName("id_fakt")->Value;
    return(id);
}


bool __fastcall TDocumentData::GetDocumentFromDB(TQuery * Query,TQuery *Query2)
{
    int fnum,fnum2;
    TArticle art1;
    //TODO: Add your source code here
    if (Query->IsEmpty())
        return(false);
    Stock.clear();
    VATPTax.clear();
    fnum=Query->FieldByName("id_fakt")->Value;
    Number=Query->FieldByName("number")->Value;
    fnum2=fnum;
    while (fnum2==fnum)
    {
        fnum2=art1.GetArticleFromDB(Query2,fnum);
        if (fnum2==fnum)
        {
            Stock.push_back(art1);
            AddToTaxTable(art1.VATP);
        }
        else
        {
            if (fnum2>0)
            {
                Stock.push_back(art1);
                AddToTaxTable(art1.VATP);
            }
        }
    }
    Buyer.GetAdressFromDB(Query);
    NIP=Query->FieldByName("NIP")->Text;
    REGON=Query->FieldByName("REGON")->Text;
    Ext=Query->FieldByName("ext")->Text;
    PrintMaster=Query->FieldByName("print_master")->Value;
    PrintCopy=Query->FieldByName("print_copy")->Value;
    DataWyst=Query->FieldByName("data_wyst")->AsDateTime;
    DataSprz=Query->FieldByName("data_sprz")->AsDateTime;
    Platnosc=Query->FieldByName("platnosc")->Text;
    if (Query->FieldByName("data_zapl")->IsNull)
    {
        DataZapl=DataSprz;
    }
    else
    {
        DataZapl=Query->FieldByName("data_zapl")->AsDateTime;
    }
    return(true);
}

void __fastcall TAdres::GetAdressFromDB(TQuery * Query)
{
    AnsiString tbuf1,tbuf2;
    TStringList *str1;
    TMemoryStream *mem1;
    TStream *strm1;
    TMemoField *blob1;
    int c;
    int i;
    mem1=new TMemoryStream();
    str1=new TStringList;
    strm1=dynamic_cast<TStream *>(mem1);
    blob1=dynamic_cast<TMemoField *>(Query->FieldByName("nazwisko"));
    blob1->SaveToStream(strm1);
    mem1->Seek(0,soFromBeginning);
    str1->LoadFromStream(strm1);
    c=str1->Count;
    Name.resize(c);
    for (i=0;i<c ;i++)
    {
        Name[i]=str1->Strings[i];
    }
    //TODO: Odczyt adresu z bazy danych
    if (Query->IsEmpty())
    {
        return;
    }
    Adress.clear();
    tbuf1=Query->FieldByName("ulica")->Text;
    tbuf2=Query->FieldByName("nr_domu1")->Text;
    if (!tbuf2.IsEmpty())
    {
        tbuf1=tbuf1+" "+tbuf2;
        tbuf2=Query->FieldByName("nr_domu2")->Text;
        tbuf1=tbuf1+tbuf2;
        tbuf2=Query->FieldByName("lokal1")->Text;
        if (!tbuf2.IsEmpty())
        {
            tbuf1=tbuf1+" "+tbuf2;
            tbuf2=Query->FieldByName("lokal2")->Text;
            tbuf1=tbuf1+tbuf2;
        }
        Adress.push_back(tbuf1);
    }
    else
    {
        Adress.push_back(tbuf1);
    }
    Explode(Adress,"\n");
    city=Query->FieldByName("miasto")->Text;
    zip=Query->FieldByName("zip")->Text;
}

void __fastcall TAdres::Explode(vector<AnsiString> & buf, AnsiString delim)
{
    queue<AnsiString> buft;
    AnsiString tbuf1,tbuf2;
    int i,c;
    int p,l,l2;
    l=delim.Length();
    c=buf.size();
    //TODO: Add your source code here
    for (i=0;i<c ;i++)
    {
        tbuf1=buf[i];
        p=tbuf1.Pos(delim);
        while (p)
        {
            p--;
            tbuf2=tbuf1.SubString(1,p);
            buft.push(tbuf2);
            p+=l;
            l2=tbuf1.Length();
            l2=l2-p;
            tbuf2=tbuf1.SubString(p,l2);
            tbuf1=tbuf2;
            p=tbuf1.Pos(delim);
        }
        buft.push(tbuf1);
    }
    c=buft.size();
    buf.resize(c);
    for (i=0;i<c ;i++)
    {
        buf[i]=buft.front();
        buft.pop();
    }
}



int __fastcall TDocumentData::ItemCount(void)
{
    //TODO: Zwraca iloœæ towarów
    return(Stock.size());
}

AnsiString __fastcall TDocumentData::PKWIU(int index)
{
    AnsiString tbuf1;
    int c;
    //TODO: Add your source code here
    c=Stock.size();
    if (index>=c)
    {
        tbuf1="";
    }
    else
    {
        tbuf1=Stock[index].PKWIU;
    }
    return tbuf1;
}



AnsiString __fastcall TDocumentData::Name(int index)
{
    AnsiString tbuf1;
    int c;
    //TODO: Nazwa towaru
    c=Stock.size();
    if (index>=c)
    {
        tbuf1="";
    }
    else
    {
        tbuf1=Stock[index].Name;
    }
    return tbuf1;
}



void __fastcall TDocumentData::AddToTaxTable(double VATP)
{
int c;
int i;
    //TODO: Dodaje do listy podatków
    if (VATPTax.empty())
    {
        VATPTax.push_back(VATP);
    }
    else
    {
        for (i=0;i<c ;i++)
        {
            if (VATPTax[i]==VATP)
            {
                return;
            }
            if (VATPTax[i]>VATP)
            {
                VATPTax.insert(VATPTax.begin()+i,VATP);
                return;
            }
        }
    }
}



void __fastcall TDocumentData::VerifyTaxTable(double VATP)
{
    int c;
    int i;
    //TODO: Weryfikuje obecnoœæ wszystkich podatków
    c=Stock.size();
    for (i=0;i<c ;i++)
    {
        if (Stock[i].VATP==VATP)
        {
            return;
        }
    }
    i=0;
    c=VATPTax.size();
    while ((i<c)&&(VATPTax[i]!=VATP))
    {
        ;
    }
    if (i<c)
    {
        VATPTax.erase(VATPTax.begin()+i);
    }
}

int TDocumentData::TaxesCount(void)
{
    int c;
    //TODO: Liczy iloœæ stop podatkowych
    c=VATPTax.size();
    return c;
}

AnsiString TDocumentData::TaxVATP(int index)
{
    AnsiString vatp1;
    double vatp;
    int c;
    c=VATPTax.size();
    //TODO: Podaje stopê VAT
    if ((index<c)&&(index>=0))
    {
        vatp=VATPTax[index];
        if (VATFloat)
        {
            vatp1=Stock[0].FormatValue(vatp,true,2);
            vatp1=SetDotStyle(vatp1);
        }
        else
            vatp1=Stock[0].FormatValue(vatp,true,0);
    }
    else
    {
        vatp1="";
    }
    return vatp1;
}

AnsiString TDocumentData::TaxNetto(int index)
{
    AnsiString netto1;
    double netto;
    double vatp;
    int c;
    int i;
    c=VATPTax.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        vatp=VATPTax[index];
        c=Stock.size();
        for (i=0;i<c ;i++)
        {
            if (vatp==Stock[index].VATP)
            {
                netto+=Stock[index].Netto();
            }
        }
        netto1=Stock[index].FormatValue(netto,false,2);
        netto1=SetDotStyle(netto1);
        if (ShowTaxCurrency)
            netto1=netto1+"z³";
    }
    else
    {
        netto1="";
    }
    return netto1;
}



AnsiString TDocumentData::TaxVAT(int index)
{
    AnsiString VAT1;
    double netto,VAT;
    double vatp;
    int c;
    int i;
    c=VATPTax.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        vatp=VATPTax[index];
        c=Stock.size();
        for (i=0;i<c ;i++)
        {
            if (vatp==Stock[index].VATP)
            {
                netto+=Stock[index].Netto();
            }
        }
        VAT=netto*vatp*0.01;
        VAT1=Stock[index].FormatValue(VAT,false,2);
        VAT1=SetDotStyle(VAT1);
        if (ShowTaxCurrency)
            VAT1=VAT1+"z³";
    }
    else
    {
        VAT1="";
    }
    return VAT1;
}

AnsiString TDocumentData::TaxBrutto(int index)
{
    AnsiString Brutto1;
    double netto,Brutto;
    double vatp;
    int c;
    int i;
    c=VATPTax.size();
    //TODO: Add your source code here
    if ((index<c)&&(index>=0))
    {
        vatp=VATPTax[index];
        c=Stock.size();
        for (i=0;i<c ;i++)
        {
            if (vatp==Stock[index].VATP)
            {
                netto+=Stock[index].Netto();
            }
        }
        Brutto=netto*vatp*0.01+netto;
        Brutto1=Stock[index].FormatValue(Brutto,false,2);
        Brutto1=SetDotStyle(Brutto1);
        if (ShowTaxCurrency)
            Brutto1=Brutto1+"z³";
    }
    else
    {
        Brutto1="";
    }
    return Brutto1;
}

AnsiString TDocumentData::TaxNettoSum(void)
{
    AnsiString netto1;
    double netto;
    int c;
    int i;
    //TODO: Oblicza sumê wartoœci netto
    c=Stock.size();
    for (i=0;i<c ;i++)
    {
        netto+=Stock[i].Netto();
    }
    netto1=Stock[0].FormatValue(netto,false,2);
    netto1=SetDotStyle(netto1);
    if (ShowTaxCurrency)
        netto1=netto1+"z³";
    return netto1;
}

AnsiString TDocumentData::TaxVATSum(void)
{
    AnsiString VAT1;
    vector<double> netto;
    double VAT;
    int c1,c2;
    int i,j;
    //TODO: oblicza sumê podatku VAT
    c1=Stock.size();
    c2=VATPTax.size();
    netto.resize(c2,0);
    for (i=0;i<c2 ;i++)
    {
        for (j=0;j<c1 ;j++)
        {
            if (VATPTax[i]==Stock[j].VATP)
            {
                netto[i]+=Stock[j].Netto();
            }
        }
    }
    VAT=0;
    for (i=0;i<c2 ;i++)
    {
        VAT+=netto[i]*VATPTax[i]*0.01;
    }
    VAT1=Stock[0].FormatValue(VAT,false,2);
    VAT1=SetDotStyle(VAT1);
    if (ShowTaxCurrency)
        VAT1=VAT1+"z³";
    return VAT1;
}

AnsiString TDocumentData::TaxBruttoSum(void)
{
    AnsiString Brutto1;
    vector<double> netto;
    double Brutto;
    int c1,c2;
    int i,j;
    //TODO: oblicza sumê wartoœci brutto
    c1=Stock.size();
    c2=VATPTax.size();
    netto.resize(c2,0);
    for (i=0;i<c2 ;i++)
    {
        for (j=0;j<c1 ;j++)
        {
            if (VATPTax[i]==Stock[j].VATP)
            {
                netto[i]+=Stock[j].Netto();
            }
        }
    }
    Brutto=0;
    for (i=0;i<c2 ;i++)
    {
        Brutto+=netto[i]*VATPTax[i]*0.01+netto[i];
    }
    Brutto1=Stock[0].FormatValue(Brutto,false,2);
    Brutto1=SetDotStyle(Brutto1);
    if (ShowTaxCurrency)
        Brutto1=Brutto1+"z³";
    return Brutto1;
}

AnsiString __fastcall TDocumentData::Number2Word(int Value)
{
AnsiString tbuf1;
AnsiString wr[]={"dziewiêæset","osiemset","siedemset","szeœæset","piêæset","czterysta","trzysta","dwieœcie","sto",
"dziewiêædziesi¹t","osiemdziesi¹t","siedemdziesi¹t","szeœædziesi¹t","piêædziesi¹t","czterdzieœci","tzydzieœci","dwadzieœcia",
"dziewiêtnaœcie","osiemnaœcie","siedemnaœcie","szesnaœcie","piêtnaœcie","czternaœcie","trzynaœcie","dwanaœcie","jedenaœcie","dziesiêæ",
"dziewiêæ","osiem","siedem","szeœæ","piêæ","cztery","trzy","dwa","jeden"};
int dig[]={900,800,700,600,500,400,300,200,100,
90,80,70,60,50,40,30,20,
19,18,17,16,15,14,13,12,11,10,
9,8,7,6,5,4,3,2,1};
int miliony,tysiace,sztuki;
int i;
    //TODO: Zamiana cyfr na s³ownie
    if (Value==0)
    {
        tbuf1="zero";
        return(tbuf1);
    }
    if (Value==1)
    {
        tbuf1="jeden";
        return(tbuf1);
    }
    miliony=Value/1000000;
    tysiace=Value%1000000/1000;
    sztuki=Value%1000;
    if (miliony)
    {
        if (miliony==1)
        {
            tbuf1=tbuf1+"milion ";
        }
        if ((miliony>1)&&(miliony<=4))
        {
            tbuf1=tbuf1+Number2Word(miliony)+"miliony ";
        }
        if (miliony>5)
        {
            tbuf1=tbuf1+Number2Word(miliony)+"milionów ";
        }
    }
    if (tysiace)
    {
        if (tysiace==1)
        {
            tbuf1=tbuf1+"milion ";
        }
        if ((tysiace>1)&&(tysiace<=4))
        {
            tbuf1=tbuf1+Number2Word(tysiace)+"tysi¹ce ";
        }
        if (tysiace>5)
        {
            tbuf1=tbuf1+Number2Word(tysiace)+"tysiêcy ";
        }
    }
    i=0;
    if (sztuki)
    {
        while (sztuki)
        {
            if (dig[i]<=sztuki)
            {
                tbuf1=tbuf1+wr[i]+" ";
                sztuki-=dig[i];
            }
            i++;
        }
    }
    return(tbuf1);
}

AnsiString TDocumentData::SpellValue(double value)
{
int zlote;
int grosze;
AnsiString tbuf1,tbuf2;
    //TODO: Podawanie kwot s³ownie
    //zaokr¹glanie wartoœci

    grosze=value*100.0;
    if ((value*100.0)<(double)grosze+0.5)
    {
        grosze=floor(value*100.0);
    }
    else
    {
        grosze=ceil(value*100.0);
    }
    zlote=grosze/100;
    grosze%=100;
    tbuf1=Number2Word(zlote);
    tbuf1=tbuf1+" z³otych ";
    tbuf2=Number2Word(grosze);
    tbuf1=tbuf1+tbuf2+" groszy";
    return tbuf1;
}

AnsiString TDocumentData::SpellValue(void)
{
    vector<double> netto;
    double Brutto;
    AnsiString Brutto1;
    int c1,c2;
    int i,j;
    //TODO: Kwota brutto s³ownie
    c1=Stock.size();
    c2=VATPTax.size();
    netto.resize(c2,0);
    for (i=0;i<c2 ;i++)
    {
        for (j=0;j<c1 ;j++)
        {
            if (VATPTax[i]==Stock[j].VATP)
            {
                netto[i]+=Stock[j].Netto();
            }
        }
    }
    Brutto=0;
    for (i=0;i<c2 ;i++)
    {
        Brutto+=netto[i]*VATPTax[i]*0.01+netto[i];
    }
    Brutto1=SpellValue(Brutto);
    return Brutto1;
}
