#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsUserListScreen :protected clsScreen
{
private:
    static void PrintClientRecordLien(clsUser User)
    {
        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.fullname();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:

    static void ShowusersList()
    {
        if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        vector<clsUser>vusers = clsUser::GetUsersList();
        string tital = "All users screen\n";
        string  sub = " (" + to_string(vusers.size()) + ")  Clients.";
        _DrawScreenHedar(tital, sub);
        cout << "\n\t\t\t\t\tusers List (" << vusers.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "user name";
        cout << "| " << left << setw(12) << "full name";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(10) << "Email";
        cout << "| " << left << setw(12) << "password";
        cout << "| " << left << setw(8) << "permission";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vusers.size() == 0)
            cout << "\t\t\tno users Available in the System!";
        else
            for (clsUser user : vusers)
            {
                PrintClientRecordLien(user);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }



};



