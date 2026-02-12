#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen :protected clsScreen
{
private:
	static void PrintClientRecordLien(clsBankClient Client)
	{
        cout << "| " << setw(15) << left << Client.Accountnumber();
        cout << "| " << setw(20) << left << Client.fullname();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.Pincode;
        cout << "| " << setw(12) << left << Client.Accountbalance;

    }

public:

   static void ShowClientsList()

    {
       if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
       {
           return;
       }

        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        string tital = "All Clients screen\n";
       string  sub = " (" + to_string(vClients.size()) + ")  Clients.";
        _DrawScreenHedar(tital, sub);
        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "Account number";
        cout << "| " << left << setw(12) << "Client name";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(10) << "Email";
        cout << "| " << left << setw(12) << "pinc code";
        cout << "| " << left << setw(8) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0)
            cout << "\t\t\tno Clients Available in the System!";
        else
            for (clsBankClient Client : vClients)
            {
                PrintClientRecordLien(Client);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }



};

