//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsLogin.h"
//#include <iomanip>
//#include <vector>
//
//class clsLoginregisterScreen :protected clsScreen
//{
//private:
//    static void PrintLoginRegisterLien(clsLogin LR)
//    {
//        cout << "| " << setw(25) << left << LR.getDateTime();
//        cout << "| " << setw(20) << left << LR.getUserName();
//        cout << "| " << setw(12) << left << LR.getPassword();
//        cout << "| " << setw(8) << left << LR.getPermissions();
//       
//
//    }
//
//public:
//
//    static void ShowLoginRegisterList()
//    {
//       
//        vector<clsLogin>vLR = clsLogin::GetLoginRegisterList();
//        string tital = "All Login Register screen\n";
//        string  sub = " (" + to_string(vLR.size()) + ")  Users.";
//        _DrawScreenHedar(tital, sub);
//        cout << "\n\t\t\t\t\tusers List (" << vLR.size() << ") Client(s).";
//        cout << "\n_______________________________________________________";
//        cout << "_________________________________________\n" << endl;
//
//        cout << "| " << left << setw(25) << "Date Time";
//        cout << "| " << left << setw(20) << "user name";
//        cout << "| " << left << setw(12) << "password";
//        cout << "| " << left << setw(8) << "permission";
//        cout << "\n_______________________________________________________";
//        cout << "_________________________________________\n" << endl;
//        if (vLR.size() == 0)
//            cout << "\t\t\tno users Available in the System Entry!";
//        else
//            for (clsLogin LR : vLR)
//            {
//                PrintLoginRegisterLien(LR);
//                cout << endl;
//            }
//        cout << "\n_______________________________________________________";
//        cout << "_________________________________________\n" << endl;
//
//
//
//    }
//
//
//
//};
//
#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"


class clsLoginregisterScreen :protected clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    { 
        if (!ChackAccesseRight(clsUser::enPermissions::pLoginRegister))
        {
           return;
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHedar(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

