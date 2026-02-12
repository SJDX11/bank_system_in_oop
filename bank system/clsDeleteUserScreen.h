#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
class clsDeleteUserScreen :protected clsScreen
{
private:
	static void _print(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermission   : " << User.Permissions;
		cout << "\n___________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHedar("Delete User Screen");
		string UserName = "";
		cout << "\n please enter User Name:";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName is not found,choose another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::find(UserName);
		_print(User1);
		cout << "\nAre you sure you want to delete this User y/n?";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y');
		{
			if (User1.Delete())
			{
				cout << "\nUser Delete Successfully:-)\n";
				_print(User1);

			}
			else
			{
				cout << "\n Error User was not Deleted\n";

			}
		}
	}
};

