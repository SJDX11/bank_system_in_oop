#pragma once
#include<iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency cry)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry       : " << cry.Country();
        cout << "\nCurrency Code : " << cry.CurrencyCode();
        cout << "\nCurrency Name : " << cry.CurrencyName();
        cout << "\nRate(1$)      : " << cry.Rate();
        cout << "\n___________________\n";
    }
public:

    static void ShowFindcryScreen()
    {
        
        _DrawScreenHedar("\tFind cry Screen");
        int x=1;
        string crycode,countryname;
        cout << "\nPlease Enter [1]cry code or [2]cry name: ";
        cin >> x;
        while ((x != 2) &&( x != 1))
        {
            cout << "\nPlease Enter [1]cry code or [2]cry name: ";
            x = clsInputValidate::ReadIntNumber();

        }
        if (x == 1)
        {
                cout << "Enter Currency Code:";
                crycode = clsInputValidate::ReadString();
                while (!clsCurrency::IsCurrencyExistbycode(crycode))
                {
                    cout << "\nCurrency code is not found, choose another one: ";
                    crycode = clsInputValidate::ReadString();
                }
                clsCurrency cry1 = clsCurrency::FindByCode(crycode);
                if (!cry1.IsEmpty())
                {
                    cout << "\ncry Found :-)\n";
                    _PrintCurrency(cry1);
                }
                else
                {
                    cout << "\ncry Was not Found :-(\n";
                }

                

        }
        if (x == 2)
        {
                cout << "Enter Currency Name:";
                countryname = clsInputValidate::ReadString();
                while (!clsCurrency::IsCurrencyExistbycountry(countryname))
                {
                    cout << "\nCurrency Name is not found, choose another one: ";
                    countryname = clsInputValidate::ReadString();
                }
                clsCurrency cry2 = clsCurrency::FindBycountry(countryname);
                if (!cry2.IsEmpty())
                {
                    cout << "\ncry Found :-)\n";
                    _PrintCurrency(cry2);
                }
                else
                {
                    cout << "\ncry Was not Found :-(\n";
                }

               
        }
    }




};



