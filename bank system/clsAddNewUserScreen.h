#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
class clsAddNewUserScreen :protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "enter firstname:" << endl;
        User.FirstName = clsInputValidate::ReadString();
        cout << "enter lastname:" << endl;
        User.LastName = clsInputValidate::ReadString();
        cout << "enter email:" << endl;
        User.Email = clsInputValidate::ReadString();
        cout << "enter phone:" << endl;
        User.Phone = clsInputValidate::ReadString();
        cout << "enter Password:" << endl;
        User.Password = clsInputValidate::ReadString();
        cout << "enter Permaission:" << endl;
        User.Permissions = _ReadPermissionsToSet();

    }
    static void _print(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.fullname();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermission     : " << User.Permissions;
        cout << "\n___________________\n";
    }
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::PDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpDateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nshow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }
        cout << "\nshow Currency Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pCurrency;
        }
        return Permissions;

    }
public:
    static void showAddNewUserScreen()
    {
        _DrawScreenHedar("Add New User");

        string UserName = "";
        cout << "\nplease enter User Name:";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\n User name is Alrady used, choose Another one:";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::GetAddnewUserObject(UserName);//creat objact empty insade him only account number
        _ReadUserInfo(NewUser);//read evre info and byrefrenc to newUser now User is full
        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\n Account Added successfuly \n";
            _print(NewUser);
            break;
        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\n Erorr account was not saved because its Empty\n";
            break;
        case clsUser::svFildUserNameExists:
            cout << "\n Erorr Account was not saved becuse account number is used !\n";
            break;
        }

    }


};


