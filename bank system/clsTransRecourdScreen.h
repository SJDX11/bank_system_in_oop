#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsBankClient.h"
#include <vector>
using namespace std;
class clsTransRecourdScreen :protected clsScreen
{

private:

    static void PrintTransferRecordLine(clsBankClient::stTransferRecord TransferRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << TransferRecord.DateTime;
        cout << "| " << setw(10) << left << TransferRecord.UserName;
        cout << "| " << setw(10) << left << TransferRecord.sClient;
        cout << "| " << setw(10) << left << TransferRecord.dClient;
        cout << "| " << setw(10) << left << TransferRecord.SourceB;
        cout << "| " << setw(10) << left << TransferRecord.destnationB;
        cout << "| " << setw(10) << left << TransferRecord.Amount;

    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransferRecord> vTransferRecord = clsBankClient::GetTransferList();// i have wrong becuse not include vector labrary

        string Title = "Trans Register List Screen";
        string SubTitle = "(" + to_string(vTransferRecord.size()) + ") Record(s).";

        _DrawScreenHedar(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(18) << "Date/Time";
        cout << "| " << left << setw(10) << "UserName";
        cout << "| " << left << setw(10) << "Account.s";
        cout << "| " << left << setw(10) << "Account.d";
        cout << "| " << left << setw(10) << "Balance.s";
        cout << "| " << left << setw(10) << "Balance.d";
        cout << "| " << left << setw(10) << "Amount";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferRecord.size() == 0)
        {
            cout << "\t\t\t\tNo Logins Available In the System!";

        }
        else
        {
            for (clsBankClient::stTransferRecord Record : vTransferRecord)
            {

                PrintTransferRecordLine(Record);
                cout << endl;
            }

        }

           

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

