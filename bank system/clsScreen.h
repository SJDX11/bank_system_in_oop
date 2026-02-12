#pragma once
#include<iostream>
#include "clsUser.h"
#include "global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
    static void _DrawScreenHedar(string Title, string subTitle = "")
    {
        cout <<"\t\t\t\t\t________________________________________";
        cout << "\n\n\t\t\t\t\t\t" << Title;
        if (subTitle != "")
        {
            cout << "\t\t\t\t\t\t\t" << "-" << subTitle;
        }
        cout <<"\n\t\t\t\t\t________________________________________\n\n";
        cout << "\t\t\t\t\tUser:" << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate:" << clsDate::DateToString(clsDate()) << endl;
        cout << "\n\t\t\t\t\t________________________________________\n\n";
    }
    /*static void _showDateAndUser()
    {
        cout << "\t\t\t\t\tUser:" << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate:" << clsDate::GetSystemDate().Year<<"/"<< clsDate::GetSystemDate().Month<<"/"<< clsDate::GetSystemDate().Day << endl;
    }*/
    static bool ChackAccesseRight(clsUser::enPermissions permissions)
    {
        if (!CurrentUser.ChackAccessePermission(permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }



};

