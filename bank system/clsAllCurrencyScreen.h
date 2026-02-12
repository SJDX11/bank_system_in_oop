#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsUser.h"
class clsAllCurrencyScreen :protected clsScreen
{
private:
    static void PrintcryRecordLien(clsCurrency cry)
    {
        cout << "| " << setw(25) << left << cry.Country();
        cout << "| " << setw(7) << left << cry.CurrencyCode();
        cout << "| " << setw(20) << left << cry.CurrencyName();
        cout << "| " << setw(10) << left << cry.Rate();
      

    }

public:

    static void ShowcrysList()

    {
        if (!ChackAccesseRight(clsUser::enPermissions::pCurrency))
        {
            return;
        }

        vector<clsCurrency>vcrys = clsCurrency::GetAllUsdRate();
        string tital = "All Currency screen\n";
        string  sub = " (" + to_string(vcrys.size()) + ")  crys.";
        _DrawScreenHedar(tital, sub);
        cout << "\n\t\t\t\t\tcry List (" << vcrys.size() << ") cry(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(25) << "Country";
        cout << "| " << left << setw(7) << "C.Code";
        cout << "| " << left << setw(20) << "C.Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vcrys.size() == 0)
            cout << "\t\t\tno crys Available in the System!";
        else
            for (clsCurrency& cry : vcrys)
            {
                PrintcryRecordLien(cry);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }



};



