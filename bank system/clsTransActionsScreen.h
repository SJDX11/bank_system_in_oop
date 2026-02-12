#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsMainScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfearScreen.h"
#include "clsTransRecourdScreen.h"
class clsTransActionsScreen:protected clsScreen
{
private:
	enum enTransactionMenueOptions
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,eTransfear=4,eShowtablelogtrans=5,
		eMainmenu = 6



	};

	static int _ReadManemenuOption()
	{
		cout << setw(37) << left << "" << "choose wat do you want to do ?[1 to 6]? ";
		int  choice = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t\t\t\tplease enter number bettwen [1 to 6]:");
		return choice;
	}

	static void _showDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void  _showWithdrawScreen1()
	{
		clsWithdrawScreen::ShowWithdreawScreen();
	}
	static void _showTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();

	}
	static void _showTransfearScreen()
	{
		clsTransfearScreen::ShowTransferScreen();

	}
	static void _showTransfearRecourdScreen()
	{
		clsTransRecourdScreen::ShowTransferLogScreen();

	}
	static void _showMainMenuScreen()
	{
		//cout << "\n TotalBalances screen will be here...\n";
		//clsMainScreen::ShowMainMenu();

	}

	static void _GoBackTOTransactionMenu()
	{
		cout << "\n prass any key to back TransAction menu....\n";
		system("pause>0");
		ShowTransactionMenu();
	}
	
	
	static void _PerformTransactionMenuOption(enTransactionMenueOptions transactionmenuoptions)
	{
		switch (transactionmenuoptions)
		{
		case enTransactionMenueOptions::eShowtablelogtrans:
		{
			system("cls");
			_showTransfearRecourdScreen();
			_GoBackTOTransactionMenu();

		}
		case enTransactionMenueOptions::eDeposit:
			system("cls");
			_showDepositScreen();
			_GoBackTOTransactionMenu();
			break;

		case enTransactionMenueOptions::eWithdraw:
		{
			system("cls");
			_showWithdrawScreen1();
			_GoBackTOTransactionMenu();
			break;
		}
		case enTransactionMenueOptions::eTotalBalances:
		{
			system("cls");
			_showTotalBalancesScreen();
			_GoBackTOTransactionMenu();
			break;
		}
		case clsTransActionsScreen::eTransfear:
		{
			system("cls");
			_showTransfearScreen();
			_GoBackTOTransactionMenu();
		}
		case enTransactionMenueOptions::eMainmenu:
		{
			system("cls");
			break;
		}
		}




	}
	public:
		static void ShowTransactionMenu()
		{
			if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
			{
				return;
			}
			system("cls");
			_DrawScreenHedar("Transaction Menu Screen");
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Debosit. \n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[4] Transfear.\n";
			cout << setw(37) << left << "" << "\t[5] Transfear log.\n";
			cout << setw(37) << left << "" << "\t[6] Main menu.\n";
			cout << setw(37) << left << "" << "===========================================\n";
			_PerformTransactionMenuOption((enTransactionMenueOptions)_ReadManemenuOption());//withou braket main menu can not convert from int to enum this call cast

		}
};

