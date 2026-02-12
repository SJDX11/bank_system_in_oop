#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsString.h"
#include <vector>
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency  _ConvertLinetoCurrencyobject(string line, string seperator = "#//#")
	{

		vector<string>vcryDate;
		vcryDate = clsString::Split(line, seperator);
		return clsCurrency(enMode::UpdateMode, vcryDate[0], vcryDate[1], vcryDate[2], stof(vcryDate[3]));

	}

	static vector<clsCurrency> _LoadeCurrencyDateFromFill()
	{
			vector<clsCurrency>vcry;
			fstream koko;
			koko.open("currencyrate.txt", ios::in);
			if (koko.is_open())
			{
				string Lien;
				while (getline(koko, Lien))
				{
					clsCurrency cry = _ConvertLinetoCurrencyobject(Lien);
					vcry.push_back(cry);

				}
				koko.close();

			}
			return vcry;
		

	}
	static string _ConverCurrencyObjectToLine(clsCurrency cry, string Seperator = "#//#")
	{
		string cryRecourd = "";
		cryRecourd += cry.Country() + Seperator;
		cryRecourd += cry.CurrencyCode() + Seperator;
		cryRecourd += cry.CurrencyName() + Seperator;
		cryRecourd += to_string(cry.Rate()) + Seperator;
		return cryRecourd;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vcry)
	{
		fstream koko;
		koko.open("currencyrate.txt", ios::out);
		string DataLien;
		if (koko.is_open())
		{
			for (clsCurrency c : vcry)
			{

				DataLien = _ConverCurrencyObjectToLine(c);
				  
				koko << DataLien << endl;

				 

			}
			koko.close();
		}
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector<clsCurrency>_vcry;
		_vcry = _LoadeCurrencyDateFromFill();
		for (clsCurrency& c : _vcry)
		{
			if (c.Country() == Country())
			{
				c = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vcry);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode,string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static vector<clsCurrency>GetAllUsdRate()
	{
		return _LoadeCurrencyDateFromFill();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName ;
	}
	void UpdateRate(float newrat)
	{
		_Rate = newrat;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream koko;
		koko.open("currencyrate.txt", ios::in);
		if (koko.is_open())
		{
			string Line;
			while (getline(koko, Line))
			{
				clsCurrency cry = _ConvertLinetoCurrencyobject(Line);
				if (cry.CurrencyCode() == CurrencyCode)
				{
					koko.close();
					return cry;

				}

			}
			koko.close();
		}

		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindBycountry(string  Country)
	{
		Country = clsString::UpperFirstLetterOfEachWord(Country);
		fstream koko;
		koko.open("currencyrate.txt", ios::in);
		if (koko.is_open())
		{
			string Line;
			while (getline(koko, Line))
			{
				clsCurrency cry = _ConvertLinetoCurrencyobject(Line);
				if (cry.Country() == Country)
				{
					koko.close();
					return cry;

				}

			}
			koko.close();
		}

		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExistbycode(string CourrencyCode)
	{
		clsCurrency c1 = clsCurrency::FindByCode(CourrencyCode);
		return (!c1.IsEmpty());
	}
	static bool IsCurrencyExistbycountry(string CountryName)
	{
		clsCurrency c2 = clsCurrency::FindBycountry(CountryName);
		return (!c2.IsEmpty());
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadeCurrencyDateFromFill();
	}
	float converttoUSD(float Amount)
	{
		return (float)Amount / Rate();
	}
	float convertToanotherCurrency(float amount ,clsCurrency Dcry)
	{
		float AmountinUsd = converttoUSD(amount);
		if (Dcry.CurrencyCode() == "USD")
		{
			exit(0);
		}
		return (float)AmountinUsd * Dcry.Rate();
	}

};

