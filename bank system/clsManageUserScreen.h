#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsUserListScreen.h"
#include"clsUpdateUserScreen.h"
#include "clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUserScreen :protected clsScreen
{
private:
	enum enManageUserMenueOptions
	{

		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4,eFindUser=5,eMainMenu=6



	};

	static int _ReadManageUsermenuOption()
	{
		cout << setw(37) << left << "" << "choose wat do you want to do ?[1 to 6]? ";
		int  choice = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t\t\t\tplease enter number bettwen [1 to 6]:");
		return choice;
	}

	static void _showListUserScreen()
	{
		clsUserListScreen::ShowusersList();
	}
	static void  _showUpdateUserScreen1()
	{
		clsUpdateusercreen::ShowUpdateUserScreen();
	}
	static void _showAddNewUserScreen()
	{
		clsAddNewUserScreen::showAddNewUserScreen();

	}
	static void _showDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}
	static void _showFindUserScreen()
	{

		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _showMainMenuScreen()
	{


	}
	static void _GoBackTOManageUserMenu()
	{
		cout << "\n prass any key to back TransAction menu....\n";
		system("pause>0");
		ShowManageUserMenu();
	}


	static void _PerformManegeUserMenuOption(enManageUserMenueOptions ManageUsermenuoptions)
	{
		switch (ManageUsermenuoptions)
		{
		case enManageUserMenueOptions::eListUser:
			system("cls");
			_showListUserScreen();
			_GoBackTOManageUserMenu();
			break;

		case enManageUserMenueOptions::eAddNewUser:
		{
			system("cls");
			_showAddNewUserScreen();
			_GoBackTOManageUserMenu();
			break;
		}
		case enManageUserMenueOptions::eDeleteUser:
		{
			system("cls");
			_showDeleteUserScreen();
			_GoBackTOManageUserMenu();
			break;
		}
		case enManageUserMenueOptions::eUpdateUser:
		{
			system("cls");
			_showUpdateUserScreen1();
			_GoBackTOManageUserMenu();
			break;
		}
		case enManageUserMenueOptions::eFindUser:
		{
			system("cls");
			_showFindUserScreen();
			_GoBackTOManageUserMenu();
			break;
		}
		case enManageUserMenueOptions::eMainMenu:
		{
			system("cls");
			break;
		}
		}




	}
public:
	static void ShowManageUserMenu()
	{
		if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		system("cls");
		_DrawScreenHedar("Transaction Menu Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show List User. \n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete New User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManegeUserMenuOption((enManageUserMenueOptions)_ReadManageUsermenuOption());//withou braket main menu can not convert from int to enum this call cast

	}
};

