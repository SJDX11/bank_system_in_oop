#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientscreen.h"
#include "clsFindClientScreen.h"
#include "clsTransActionsScreen.h"
#include "clsManageUserScreen.h"
#include "global.h"
#include"clsLoginregisterScreen.h"
#include "clsCurrencyMune.h"
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions 
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,loginregister=8,eCurrncy=9, eExit = 10

	     

	};

	static int _ReadManemenuOption()
	{
		cout << setw(37)<<left<<"" << "choose wat do you want to do ?[1 to 10]? ";
		int  choice = clsInputValidate::ReadIntNumberBetween(1, 10, "\t\t\t\t\t\t\tplease enter number bettwen [1 to 10]:");
		return choice;
	}
	
	static void _showAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();

	}
	static void _showCurrencyScreen()
	{
		clsCurrencyMune::ShowCurrencyMenu();
	}
	static void  _showAddNewClientScreen1()
	{
		clsAddNewClientScreen::showAddMainMenuScreen();
	}
	static void _showDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}
	static void _showUpdateClientScreen()
	{
		clsUpdateClientscreen::ShowUpdateClientScreen();

	}
	static void _showFindClientscreen()
	{
		clsFindClientScreen::ShowFindClientScreen();

	}
	static void _showTransActionsManuScreen()
	{
		clsTransActionsScreen::ShowTransactionMenu();

	}
	static void _showManagUserScreen()
	{
		clsManageUserScreen::ShowManageUserMenu();

	}
	static void _LogoutScreen()
	{
		 CurrentUser = clsUser::find("", "");
		 
	}
	static void _loginRegister()
	{
		clsLoginregisterScreen::ShowLoginRegisterScreen();
	}
	static void _GoBackTOMainMenu()
	{
		cout << "\n prass any key to back Main menu....\n";
		system("pause>0");

		ShowMainMenu();
	}
	static void _PerformMainMenuOption(enMainMenueOptions mainmenuoptions)
	{
		switch (mainmenuoptions)
		{
		case enMainMenueOptions::eCurrncy:
		{
			system("cls");
			_showCurrencyScreen();
			_GoBackTOMainMenu();
			break;
		}
		case enMainMenueOptions::loginregister:
			system("cls");
			_loginRegister();
			_GoBackTOMainMenu();
			break;
		case enMainMenueOptions::eListClients:
			system("cls");
			_showAllClientsScreen();
			_GoBackTOMainMenu();
			break;
		
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_showDeleteClientScreen();
			_GoBackTOMainMenu();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_showFindClientscreen();
			_GoBackTOMainMenu();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_LogoutScreen();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_showTransActionsManuScreen();
			_GoBackTOMainMenu();

			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_showManagUserScreen();
			_GoBackTOMainMenu();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_showUpdateClientScreen();
			_GoBackTOMainMenu();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_showAddNewClientScreen1();
			_GoBackTOMainMenu();
			break;


		}
		


	}
	public:
		static void ShowMainMenu()
		{
			system("cls");
			_DrawScreenHedar("Main Menu");
			cout << setw(37) << left << "" << "\t[1] show Client List. \n";
			cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find Client.\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t[8] Login Register.\n";
			cout << setw(37) << left << "" << "\t[9] Currency.\n";
			cout << setw(37) << left << "" << "\t[10] Logout.\n";
			cout << setw(37) << left << "" << "===========================================\n";
			_PerformMainMenuOption((enMainMenueOptions)_ReadManemenuOption());//withou braket main menu can not convert from int to enum this call cast

		}
};

