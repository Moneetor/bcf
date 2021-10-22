//---------------------------------------------------------------------------

#ifndef faktordata1H
#define faktordata1H

#include <vcl.h>
#include <inifiles.hpp>
#include <Registry.hpp>
#include <Db.hpp>
#include <DBTables.hpp>

using namespace std;
#include <vector>
#include "windowr.h"
#include "blowfish.h"
#include "rectwrap.h"
//---------------------------------------------------------------------------
class TPrintField;
class TArticle;
class TDatabaseCfgData;
class TRectWrapper;

class TAdres
{
private:

protected:

public:
    vector<AnsiString> Name;
    vector<AnsiString> Adress;
    AnsiString zip;
    AnsiString city;
    TAdres();
    TAdres(const TAdres & Adres);
    ~TAdres();
    TAdres & operator =(const TAdres & Adres);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall ReadFromIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall GetAdressFromDB(TQuery * Query);
    void __fastcall Explode(vector<AnsiString> & buf, AnsiString delim);
};

class TFaktorzData
{
private:

protected:

public:
    //Paper
    int TopMargin;
	int LeftMargin;
	int BottomMargin;
	int RightMagin;
	int FontSize;
	int HeaderFontSize;
    //Seller
    TAdres Seller;
    AnsiString NIP;
    AnsiString REGON;
    //Bank
    AnsiString Bank;
	AnsiString Account;
    //Logo
	AnsiString LogoFileName;
    //other
    int LastNumber;
    vector<TPrintField> PrintFields;
    vector<TWindowR> WindowS;
    int UsedDSN;
    vector<TDatabaseCfgData> Datasources;
    TFaktorzData();
    TFaktorzData(const TFaktorzData & FaktorzData);
    ~TFaktorzData();
    TFaktorzData & operator =(const TFaktorzData & FaktorzData);
    int PrintFieldsCount(void);
    int __fastcall FieldNumber(AnsiString fname);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall ReadFromIni(TIniFile * IniFile, AnsiString Section);
    void GetDatasources(void);
};

class TPrintField
{
private:
    int FResolution;

protected:
    int mmToPixel(int Milimeters);
    int PixelTomm(int Pixels);
    TRect Area;

public:
    bool Header;
    bool Bold;
    bool FixedHPos;
    bool FixedVPos;
    AnsiString FieldName;
    TAlignment Alignment;
    bool Visible;
    TPrintField();
    void __fastcall SetResolution(int value);
    TPrintField(const TPrintField & PrintField);
    TPrintField & operator =(const TPrintField & PrintField);
    ~TPrintField();
    int mmToPixel(int Milimeters,int DPI);
    int PixelTomm(int Pixels, int DPI);
    int __fastcall GetResolution(void);
    void SetArea(TRect & Area);
    void GetArea(TRect & Area);
    void GetPrintArea(TRect & PrintArea);
    void SetPrintArea(TRect & PrintArea);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall LoadFromIni(TIniFile * IniFile, AnsiString Section);

};

class TDocumentData
{
private:
    vector<TArticle> Stock;
    vector<double> VATPTax;
    AnsiString __fastcall SetDotStyle(AnsiString value);
    void __fastcall AddToTaxTable(double VATP);
    void __fastcall VerifyTaxTable(double VATP);
protected:
    AnsiString __fastcall Number2Word(int Value);
public:
    bool UseColons;
    char DocumentType;
    TDateTime DataWyst;
    TDateTime DataSprz;
    TDateTime DataZapl;
    TAdres Buyer;
    bool QuantityFloat;
    bool VATFloat;
    AnsiString Ext;
    AnsiString NIP;
    AnsiString REGON;
    unsigned short Number;
    bool PrintCopy;
    bool PrintMaster;
    bool ShowTaxCurrency;
    bool ShowItemCurrency;
    AnsiString Platnosc;
    int ID;
    TDocumentData();
    TDocumentData(const TDocumentData & DocumentData);
    TDocumentData & operator =(const TDocumentData & DocumentData);
    ~TDocumentData();
    AnsiString __fastcall VAT(int index);
    AnsiString __fastcall Netto(int index);
    AnsiString __fastcall Quantity(int index);
    AnsiString __fastcall Rabat(int index);
    AnsiString __fastcall VATP(int index);
    AnsiString __fastcall Brutto(int index);
    AnsiString __fastcall jm(int index);
    void __fastcall Add(int pos, AnsiString nazwa,AnsiString PKWIU, double qty,
        AnsiString jm1, double rabat, double price, double vatp);
    void __fastcall Clear(void);
    void __fastcall Delete(int index);
    void __fastcall Insert(int pos, AnsiString nazwa, AnsiString PKWIU,
    double qty, AnsiString jm1, double rabat, double price, double vatp);
        AnsiString __fastcall Price(int index);
    bool __fastcall GetDocumentFromDB(TQuery * Query,TQuery *Query2);
    int __fastcall ItemCount(void);
    AnsiString __fastcall PKWIU(int index);
    AnsiString __fastcall Name(int index);
    int TaxesCount(void);
    AnsiString TaxVATP(int index);
    AnsiString TaxNetto(int index);
    AnsiString TaxVAT(int index);
    AnsiString TaxBrutto(int index);
    AnsiString TaxNettoSum(void);
    AnsiString TaxVATSum(void);
    AnsiString TaxBruttoSum(void);
    AnsiString SpellValue(double value);
    AnsiString SpellValue(void);
};

class TArticle
{
private:

protected:

public:
    AnsiString PKWIU;
    double Quantity;
    double Rabat;
    double Price;
    double VATP;
    AnsiString jm;
    AnsiString Name;
    TArticle();
    TArticle(const TArticle & Article);
    TArticle & operator =(const TArticle & Article);
    ~TArticle();
    double __fastcall Netto(void);
    double __fastcall VAT(void);
    double __fastcall Brutto(void);
    AnsiString FormatValue(double value, bool percent,int precision);
    int __fastcall GetArticleFromDB(TQuery * Query, int Pos);
};

class TDatabaseCfgData
{
private:
    CBlowFish BlowFish; 
    AnsiString FPassword;
    unsigned int __fastcall Hex2Int(char * hex);
protected:

public:
    AnsiString DSN;
    AnsiString Login;
    bool UsePassword;
    bool UseLogin;
    AnsiString DBEngine;
    bool SavePassword;
    TDatabaseCfgData();
    TDatabaseCfgData(const TDatabaseCfgData & DatabaseCfgData);
    TDatabaseCfgData & operator =(const TDatabaseCfgData & DatabaseCfgData);
    ~TDatabaseCfgData();
    void __fastcall Password(AnsiString pass);
    AnsiString __fastcall Password(void);
    void __fastcall SaveToIni(TIniFile * IniFile, AnsiString Section);
    void __fastcall ReadFromIni(TIniFile * IniFile, AnsiString Section);
    void SetDatabase(TDatabase * Database);
};

#endif

