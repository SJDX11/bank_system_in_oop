#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
string Myfile = "Clients.txt";
class clsBankClient : public clsPerson
{
private:
	
 enum enmode{emptydate=0,upgraddate=1,Addnewmode=2};
 enmode _Mode;
  string _Accountnumber;
  string _Pincode;
  double _Accountbalance;
  bool _MarkedForDelete = false;
 
	static clsBankClient  _ConvertLinetolineobject(string line, string seperator = "#//#")
	{
	
		 vector<string>vword;
		 vword = clsString::Split(line, seperator);
		 return clsBankClient(enmode::upgraddate, vword[0], vword[1], vword[2], vword[3], vword[4], vword[5], stod(vword[6]));
		  
	}
	static clsBankClient _GetEmptyClientObject()
	{
		
		return clsBankClient(enmode::emptydate, "", "", "", "", "", "", 0); 

	}
	
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._Accountnumber += Seperator;
		stClientRecord += Client._Pincode += Seperator;
		stClientRecord += to_string(Client.Accountbalance);
		return stClientRecord;
	}

	static vector <clsBankClient>_LoadClientsDataFromFile()
	{
		vector<clsBankClient>vClients;
		fstream koko;
		koko.open(Myfile, ios::in);
		if (koko.is_open())
		{
			string Lien;
			while (getline(koko, Lien))
			{
				clsBankClient Client = _ConvertLinetolineobject(Lien);
				vClients.push_back(Client);

			}
			koko.close();

		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt",ios::out);
		string DataLien;
		if (Myfile.is_open())
		{
			for (clsBankClient &c : vClients)
			{

				DataLien = _ConverClientObjectToLine(c);
				if (c.MarkedForDeleted() == false)
				{ 
					Myfile << DataLien << endl;

				}
				
			}
			Myfile.close();
		}
	}
	void _Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& c : _vClients)
		{
			if (c.Accountnumber() == Accountnumber())
			{
				c = *this;

				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}
	 string _ConverlogtransToLine(clsBankClient Destnation,double Amount, string Seperator = "#//#")
	{
		   
			string stlogtransRecourd = "";	
			stlogtransRecourd += clsDate::CurrentTime() + Seperator;	
			stlogtransRecourd += CurrentUser.UserName + Seperator;
			stlogtransRecourd += Accountnumber() + Seperator;
			stlogtransRecourd += Destnation.Accountnumber() + Seperator;
			stlogtransRecourd += to_string(Accountbalance) + Seperator;
			stlogtransRecourd += to_string(Destnation.Accountbalance) + Seperator;
			stlogtransRecourd +=to_string( Amount) + Seperator;

			return stlogtransRecourd;	
	}
	 void _Savelogtrans(clsBankClient y,double A)
	{
		string DataLien = _ConverlogtransToLine(y,A);
		fstream koko;
		koko.open("logTrans.txt", ios::out | ios::app);

		if (koko.is_open())
		{



			koko << DataLien << endl;




			koko.close();
		}
	} struct stTransferRecord;
	 static stTransferRecord _ConvertTransLineToRecord(string Line, string Seperator = "#//#")
	 {
		 stTransferRecord TransferRecord;


		 vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		 TransferRecord.DateTime = LoginRegisterDataLine[0];
		 TransferRecord.UserName = LoginRegisterDataLine[1];
		 TransferRecord.sClient = LoginRegisterDataLine[2];
		 TransferRecord.dClient = LoginRegisterDataLine[3];
		 TransferRecord.SourceB = stod(LoginRegisterDataLine[4]);
		 TransferRecord.destnationB = stod(LoginRegisterDataLine[5]);
		 TransferRecord.Amount = stod(LoginRegisterDataLine[6]);

		 return TransferRecord;

	 }
	
	

public:


	clsBankClient(enmode mode, string FirstName, string LastName, string Email, string Phone
		, string Accountnumber, string Pincode, double Accountbalance) :clsPerson(FirstName, LastName
			, Email, Phone)
	{
		_Mode = mode;
		_Accountnumber = Accountnumber;
		_Pincode = Pincode;
		_Accountbalance = Accountbalance;

	}
	struct stTransferRecord
	{
		string DateTime;
		string UserName;
		double SourceB;
		double destnationB;
		double Amount;
		string sClient;
		string dClient;
		

	};
	static  vector <stTransferRecord> GetTransferList()
	 {
		 vector <stTransferRecord> vTransferRecord;

		 fstream koko;
		 koko.open("logTrans.txt", ios::in);//read Mode

		 if (koko.is_open())
		 {

			 string Line;

			 stTransferRecord TransferRecord;

			 while (getline(koko, Line))
			 {

				 TransferRecord = _ConvertTransLineToRecord(Line);

				 vTransferRecord.push_back(TransferRecord);

			 }

			 koko.close();

		 }

		 return vTransferRecord;

	 }
	void _AddDateLineToFile(string stDateLine)
	{
		fstream koko;
		koko.open("Clients.txt", ios::out | ios::app);
		if (koko.is_open())
		{
			koko << stDateLine << endl;
			koko.close();
		}

	}
	void _Addnew()
	{
		_AddDateLineToFile(_ConverClientObjectToLine( * this));

	}
    bool IsEmpty()
	{
		return (_Mode == enmode::emptydate);
	}
	string Accountnumber()
	{
		return _Accountnumber;

	}
	void setPincode(string Pincode)
	{
		_Pincode = Pincode;
	}
	string getPincode()
	{
		return _Pincode;
	}
	__declspec(property(get = getPincode, put = setPincode))string Pincode;
 
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	void Deposit(double Amount)
	{
		_Accountbalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _Accountbalance)
		{
			return false;
		}
		else {
			_Accountbalance -= Amount;
		Save();

		}
		
	}

	void setAccountbalance(double Accountbalance)
	{
		_Accountbalance = Accountbalance;
	}
	double getAccountBalance()
	{
		return _Accountbalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountbalance))double Accountbalance;
	
	static clsBankClient find(string rAccountnumber)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLinetolineobject(Line);
				if (Client.Accountnumber() == rAccountnumber)
				{
					Myfile.close();
					return Client;
				
				}

			}
			Myfile.close();

		}
		return _GetEmptyClientObject();
	}
	static clsBankClient find(string rAccountnumber,string rPincode)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLinetolineobject(Line);
				if (Client.Accountnumber() == rAccountnumber&&Client.Pincode==rPincode)
				{
					Myfile.close();
					return Client;

				}

			}
			Myfile.close();

		}
		return _GetEmptyClientObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFildAccountNumberExists = 2 };//if  account number exists in file return 2
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enmode::emptydate:
			return enSaveResults::svFaildEmptyObject;
			break;
		case enmode::upgraddate:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case enmode::Addnewmode:   //this is new mode add to enmode we usful by spicific mode  to print in screen what hapan naw
		{
			if (clsBankClient::IsClientExist(_Accountnumber))
			{
				return enSaveResults::svFildAccountNumberExists;

			}
			else
			{
				_Addnew();
				_Mode = enmode::upgraddate;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}
	static clsBankClient GetAddnewClientObject(string Accountnumber)
	{
		return clsBankClient(enmode::Addnewmode, "", "", "", "", Accountnumber, "", 0);
	}
	static bool IsClientExist(string Accountnumber)
	{
		clsBankClient Client = clsBankClient::find(Accountnumber);
		return (!Client.IsEmpty());
	}
	bool Delete()
	{
		vector <clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& c : _vClients)
		{
			if (c.Accountnumber() == _Accountnumber)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector <clsBankClient>GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static float GetTotalBalances()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.Accountbalance;
		}
		return TotalBalances;
	}
	
	bool Transfer(double Amount, clsBankClient& distnationClient)
	{
		if (Amount > Accountbalance)
		{
			return false;
		}
		else
		{
			
			Withdraw(Amount);
			distnationClient.Deposit(Amount);
		    _Savelogtrans( distnationClient, Amount);
			return true;

		}
			
	}
};

