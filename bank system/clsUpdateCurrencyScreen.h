
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateCurrencycreen :protected clsScreen
{
    static void _Printcry(clsCurrency cry)
    {
        cout << "\ncry Card:";
        cout << "\n___________________";
        cout << "\ncountry       : " << cry.Country();
        cout << "\ncurrency code : " << cry.CurrencyCode();
        cout << "\ncurrency name : " << cry.CurrencyName();
        cout << "\nRate(1$)      : " << cry.Rate();
        cout << "\n___________________\n";

    }

   
   

public:

    static void ShowUpdatecryScreen()
    {

        _DrawScreenHedar("\tUpdate cry Screen");

        string crycode = "";

        cout << "\nPlease Enter Cuurency code: ";
        crycode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExistbycode(crycode))
        {
            cout << "\ncrycode is not found, choose another one: ";
            crycode = clsInputValidate::ReadString();
        }

        clsCurrency cry1 = clsCurrency::FindByCode(crycode);

        _Printcry(cry1);

        cout << "\nAre you sure you want to update this cry y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate cry Info:";
            cout << "\n____________________\n";
            cout << "\nEnter Rate: ";
            double x=clsInputValidate::ReadDblNumber();
            cry1.UpdateRate(x);
            cout << "Currency update is seccessfuly\n";
            _Printcry(cry1);


        }

    }

};


