#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
class clsAddNewClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient & Client)
	{
        cout << "enter firstname:" << endl;
        Client.FirstName = clsInputValidate::ReadString();
        cout << "enter lastname:" << endl;
        Client.LastName = clsInputValidate::ReadString();
        cout << "enter email:" << endl;
        Client.Email = clsInputValidate::ReadString();
        cout << "enter phone:" << endl;
        Client.Phone = clsInputValidate::ReadString();
        cout << "enter pincode:" << endl;
        Client.Pincode = clsInputValidate::ReadString();
        cout << "enter Accountbalance:" << endl;
        Client.Accountbalance = clsInputValidate::ReadDblNumber();

	}
	static void _print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " <<Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.fullname();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " <<Client.Accountnumber();
		cout << "\nPassword    : " <<Client.Pincode;
		cout << "\nBalance     : " <<Client.Accountbalance;
		cout << "\n___________________\n";
	}
public:
	static void showAddMainMenuScreen()
	{
        if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
		    _DrawScreenHedar("Add New Client");
        
            string Accountnumber = "";
            cout << "\nplease enter Account Number:";
            Accountnumber = clsInputValidate::ReadString();
            while (clsBankClient::IsClientExist(Accountnumber))
            {
                cout << "\n Account Number is Alrady used, choose Another one:";
                Accountnumber = clsInputValidate::ReadString();
            }
            clsBankClient NewClient = clsBankClient::GetAddnewClientObject(Accountnumber);//creat objact empty insade him only account number
            _ReadClientInfo(NewClient);//read evre info and byrefrenc to newclient now client is full
            clsBankClient::enSaveResults SaveResult;
            SaveResult = NewClient.Save();
            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\n Account Added successfuly \n";
                _print(NewClient);
                break;
            case clsBankClient::enSaveResults::svFaildEmptyObject:
                cout << "\n Erorr account was not saved because its Empty\n";
                break;
            case clsBankClient::svFildAccountNumberExists:
                cout << "\n Erorr Account was not saved becuse account number is used !\n";
                break;
            }
        
	}


};

