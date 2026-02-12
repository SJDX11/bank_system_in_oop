#pragma once
#include"clsInputValidate.h"
#include "clsScreen.h"
#include "clsAllCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include "clsCryCalculetScreen.h"
class clsCurrencyMune:protected clsScreen
{
private:
	enum enCurrencyMenueOptions
	{
		eListCurrencys = 1, eFindCurrency = 2,
		eUpdateCurrency = 3, eCurrencyCalauleter = 4,
	 eExit = 5



	};

	static int _ReadManemenuOption()
	{
		cout << setw(37) << left << "" << "choose wat do you want to do ?[1 to 5]? ";
		int  choice = clsInputValidate::ReadIntNumberBetween(1, 5, "\t\t\t\t\t\t\tplease enter number bettwen [1 to 5]:");
		return choice;
	}

	static void _showAllCurrencyScreen()
	{
		clsAllCurrencyScreen::ShowcrysList();
	}
	static void _showFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindcryScreen();
	}
	static void  _showUpdateCurrencyScreen()
	{
		clsUpdateCurrencycreen::ShowUpdatecryScreen();
		
	}
	static void _showCurrencyCalauleterScreen()
	{
		clsCryCalculetScreen::ShowCrycalculetScreen();

	}
	
	static void _GoBackTOCurrencyMenu()
	{
		cout << "\n prass any key to back Main menu....\n";
		system("pause>0");

		ShowCurrencyMenu();
	}
	static void _PerformMainMenuOption(enCurrencyMenueOptions mainmenuoptions)
	{
		switch (mainmenuoptions)
		{
		case enCurrencyMenueOptions::eListCurrencys:
		{
			system("cls");
			_showAllCurrencyScreen();
			_GoBackTOCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eFindCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_GoBackTOCurrencyMenu();
			break;
		case enCurrencyMenueOptions::eUpdateCurrency:
			system("cls");
			_showUpdateCurrencyScreen();
			_GoBackTOCurrencyMenu();
			break;

		case enCurrencyMenueOptions::eCurrencyCalauleter:
		{
			system("cls");
			_showCurrencyCalauleterScreen();
			_GoBackTOCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eExit:
		{
			system("cls");
			break;
		}
		}



	}
public:
	static void ShowCurrencyMenu()
	{
		system("cls");
		_DrawScreenHedar("Currency Menu");
		cout << setw(37) << left << "" << "\t[1] show Currency List. \n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Info.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculeter.\n";
		cout << setw(37) << left << "" << "\t[5] Exit.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenuOption((enCurrencyMenueOptions)_ReadManemenuOption());//withou braket main menu can not convert from int to enum this call cast

	}
};

