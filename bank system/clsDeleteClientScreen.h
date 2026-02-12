#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
class clsDeleteClientScreen:protected clsScreen
{
private:
	static void _print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.fullname();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.Accountnumber();
		cout << "\nPassword    : " << Client.Pincode;
		cout << "\nBalance     : " << Client.Accountbalance;
		cout << "\n___________________\n";
	}
public:
	 static void ShowDeleteClientScreen()
		{
		 if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
		 {
			 return;
		 }
		_DrawScreenHedar("Delete Client Screen");
		    string Accountnumber = "";
		    cout << "\n please enter account number:";
		    Accountnumber = clsInputValidate::ReadString();
		    while (!clsBankClient::IsClientExist(Accountnumber))
		    {
		        cout << "\n Accountnumber is not found,choose another one:";
		        Accountnumber = clsInputValidate::ReadString();
		    }
		    clsBankClient Client1 = clsBankClient::find(Accountnumber);
		    _print(Client1);
		    cout << "\nAre you sure you want to delete this Client y/n?";
		    char answer = 'n';
		    cin >> answer;
		    if (answer == 'y' || answer == 'Y');
		    {
		        if (Client1.Delete())
		        {
		            cout << "\nClient Delete Successfully:-)\n";
		           _print(Client1);
		
		        }
		        else
		        {
		            cout << "\n Error Client was not Deleted\n";
		
		        }
		    }
		}
};

