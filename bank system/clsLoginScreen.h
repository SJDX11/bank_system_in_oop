#pragma once
#include <iostream>
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "global.h"
#include "clsLoginRegister.h"
#include "clsUtil.h"
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		string UserName, Password;
		int x = 0;
		do
		{
			
			if (LoginFaild)
			{
				x++;
				cout << "invlaid UserName/password!\n\n";
				cout << "you have-" << 3-x << "-trials to login\n" << endl;
				if (x == 3)
				{
					cout << "you are locked after 3 trials\n\n";
					return false ;
				}
			}
			cout << "Enter UserName?:";
			cin >> UserName;
			cout << endl;
			cout << "Enter Password?:";
			cin >> Password;
			cout << "\n\n";
			CurrentUser = clsUser::find(UserName,Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		CurrentUser.SaveUsersLogin();
		
		clsMainScreen::ShowMainMenu();
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHedar("login Screen");
		return  _Login();
	}
};

