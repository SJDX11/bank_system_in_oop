#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsWithdrawScreen :clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowWithdreawScreen()
	{
		_DrawScreenHedar("Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] dose not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::find(AccountNumber);
		_PrintClient(Client1);
		double Amount = 0;
		cout << "\n Please enter Withdraw Amount?:";
		Amount = clsInputValidate::ReadDblNumber();
		cout << "\n Are you sure you want to perform this Transaction?y/n :";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			
			if (Client1.Withdraw(Amount))
			{cout << "\n Amount Deposit Successfully.\n";
			cout << "\nNew Balances Is: " << Client1.Accountbalance;

			}
			else
			{
				cout << "\n Cannot Withdraw ,insufecient Balance\n";
				cout << "\n Amount With Draw :" << Amount << endl;
				cout << "\n your Balance is :" << Client1.Accountbalance;
			}
			
		}
		else
		{
			cout << "\n Operation Was Cancelled.\n";
		}

	}
};



