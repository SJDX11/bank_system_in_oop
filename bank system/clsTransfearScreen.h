#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include<iomanip>
#include "global.h"
#include <string>
#include <cstdlib>
class clsTransfearScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name      : " << Client.fullname();
		cout << "\nAccount Number : " << Client.Accountnumber();
		cout << "\nBalance        : " << Client.Accountbalance;
		cout << "\n___________________\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber to transfear from? ";
		 AccountNumber=clsInputValidate::ReadString();
		 while (!clsBankClient::IsClientExist(AccountNumber))
		 {
			 cout << "\nClient with [" << AccountNumber << "] dose not exist.\n";
			 AccountNumber = clsInputValidate::ReadString();

		 }
		return AccountNumber;
	}
	static double ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\n Enter Transfer Amount?";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount > SourceClient.Accountbalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();

		}
		return Amount;
	}
	///*static void _Deposit(string AccountNumber ,clsBankClient &Client1,double numberEntery=0)
	//{
	//	
	//	double Amount = numberEntery;
	//	
	//		Client1.Deposit(Amount);
	//		
	//}

	///*static void _Withdreaw(string AccountNumber,clsBankClient &Client1,double numberEntery=0)
	//{
	//	
	//	



	//	double Amount = numberEntery;
	//	cout << "\n Are you sure you want to perform this Transaction?y/n :";
	//	char Answer = 'n';
	//	cin >> Answer;
	//	if (Answer == 'y' || Answer == 'Y')
	//	{
	//		Client1.Withdraw(Amount);
	//		cout << "\nTransfear is Done successfully\n";

	//	}
	//	else
	//	{
	//		cout << "\n Operation Was Cancelled.\n";
	//	}

	//}*/
	// 

	
	
	
	

public:

	///*static void ShowTransfearScreen()
	//{
	//	double Amount;
	//	_DrawScreenHedar("Transfear Screen");
	//	string AccountNumberfrom = _ReadAccountNumberto();
	//	while (!clsBankClient::IsClientExist(AccountNumberfrom))
	//	{
	//		cout << "\nClient with [" << AccountNumberfrom << "] dose not exist.\n";
	//		AccountNumberfrom = _ReadAccountNumberfrom();
	//	}
	//	clsBankClient Client1 = clsBankClient::find(AccountNumberfrom);
	//	_PrintClient(Client1);

	//	string AccountNumberto = _ReadAccountNumberfrom();
	//	while (!clsBankClient::IsClientExist(AccountNumberto))
	//	{
	//		cout << "\nClient with [" << AccountNumberto << "] dose not exist.\n";
	//		AccountNumberto = _ReadAccountNumberfrom();
	//	}
	//	clsBankClient Client2 = clsBankClient::find(AccountNumberto);
	//	_PrintClient(Client2);


	//	cout << "\n\n Enter TransFear Amount:";
	//	cin >> Amount;
	//	while (Amount > Client1.Accountbalance)
	//	{
	//		cout << "\n Amount Exceeds the Avilable Balance,Enter Another Amount :";
	//		cin >> Amount;
	//	}
	//	_Withdreaw(AccountNumberfrom, Client1, Amount);
	//	_Deposit(AccountNumberto, Client2, Amount);
	//	_PrintClient(Client1);
	//	_PrintClient(Client2);


	
	static void ShowTransferScreen()
	{
		_DrawScreenHedar("\t transfer Screen");
		clsBankClient SourceClient = clsBankClient::find(_ReadAccountNumber());
		_PrintClient(SourceClient);
		clsBankClient distnationClient = clsBankClient::find(_ReadAccountNumber());
		_PrintClient(distnationClient);
		double Amount = ReadAmount(SourceClient);
		cout << "\n Are you sure you want to perform this Transaction?y/n :";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			if (SourceClient.Transfer(Amount, distnationClient))
			{
				cout << "\nTransfear is Done successfully\n";

			}

		}
		else
		{
			cout << "\n Operation Was Cancelled.\n";
		}
		_PrintClient(SourceClient);
		_PrintClient(distnationClient);
		
	}

	
	
	

	
	
};

