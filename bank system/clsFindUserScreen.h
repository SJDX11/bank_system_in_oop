#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
       
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nBalance     : " << User.Permissions;
        cout << "\n___________________\n";
    }
public:

    static void ShowFindUserScreen()
    {
        if (!ChackAccesseRight(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHedar("\tFind User Screen");

        string UserName;
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }




};

