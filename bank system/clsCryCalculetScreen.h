#pragma once
#include "clsScreen.h"

#include "clsInputValidate.h"
#include "clsDate.h"
#include<iomanip>
#include "global.h"
#include <string>
#include <cstdlib>
#include "clsCurrency.h"
class clsCryCalculetScreen :protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency cry)
	{
		cout << "\ncry Card:";
		cout << "\n___________________";
		cout << "\nCountry        : " << cry.Country();
		cout << "\nCurrency code  : " << cry.CurrencyCode();
		cout << "\nCurrency name  : " << cry.CurrencyName();
		cout << "\nRate           : " << cry.Rate();
		cout << "\n___________________\n";
	}
	
	static float ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount?";
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}
	static void _printResultCalculet(float Amount, clsCurrency s, clsCurrency d)
	{
		cout << "\nconvert to USD\n";
		_PrintCurrency(s);
		float AmountinUSD = s.converttoUSD(Amount);
		cout << Amount << " " << s.CurrencyCode() << "=" << AmountinUSD << " USD" << endl;
		if (d.CurrencyCode() == "USD")
		{

			return;
		}

		cout << "\nconvert to another currency\n";
		_PrintCurrency(d);

		float Amountinanothor = d.convertToanotherCurrency(Amount, d);
		cout << AmountinUSD << " USD" << "=" << Amountinanothor << " " << d.CurrencyCode() << endl;

	}
	static clsCurrency _getCurrencycode(string massege)
	{
		string currencycode;
		cout << massege;
		currencycode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistbycode(currencycode))
		{
			cout << massege;
		 currencycode= clsInputValidate::ReadString();


		}
		clsCurrency cry = clsCurrency::FindByCode(currencycode);
		return cry;

	}
	
public:

	

	static void ShowCrycalculetScreen()
	{
		

		char Answer = 'y';
		while (Answer == 'y' || Answer == 'Y')
		{
			system("cls");
			_DrawScreenHedar("\t calculet Screen");
			clsCurrency Sourcecryt = _getCurrencycode("Please enter currency from: ");
			clsCurrency distnationcryt = _getCurrencycode("Please enter currency from: ");
			float Amount = ReadAmount();
			_printResultCalculet(Amount,Sourcecryt,distnationcryt);
			cout << "\n Are you sure you want to perform another calculet?y/n :";
			cin >> Answer;

		}

	}







};

