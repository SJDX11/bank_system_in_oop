#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include<iomanip>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;
string Myfile2 = "Users.txt";
class clsUser : public clsPerson
{
private:

	enum enmode { emptydate = 0, upgraddate = 1, Addnewmode = 2 };
	enmode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	struct stLoginRegisterRecord;
	

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = LoginRegisterDataLine[2];
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	 string _ConverUserloginToLine( string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += clsDate::CurrentTime() + Seperator;
		stUserRecord += UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(Password,8) + Seperator;
		stUserRecord += to_string(Permissions);
		return stUserRecord;
	}
	static clsUser  _ConvertLinetoUserobject(string line, string seperator = "#//#")
	{

		vector<string>vUserDate;
		vUserDate = clsString::Split(line, seperator);
		return clsUser(enmode::upgraddate, vUserDate[0], vUserDate[1],vUserDate[2]
		, vUserDate[3], vUserDate[4], vUserDate[5],stoi(vUserDate[6]));

	}
	
	static clsUser _GetEmptyUserObject()
	{

		return clsUser(enmode::emptydate, "", "","","","","", 0);

	}

	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord +=clsUtil::EncryptText(User.Password,8) +Seperator;
		stUserRecord += to_string(User.Permissions);
		return stUserRecord;
	}

	static vector <clsUser>_LoadUsersDataFromFile()
	{
		vector<clsUser>vUsers;
		fstream koko;
		koko.open(Myfile2, ios::in);
		if (koko.is_open())
		{
			string Lien;
			while (getline(koko, Lien))
			{
				clsUser User = _ConvertLinetoUserobject(Lien);
				vUsers.push_back(User);

			}
			koko.close();

		}
		return vUsers;
	}

	static void _SaveUsersDataToFile(vector<clsUser>vUsers)
	{
		fstream koko;
		koko.open(Myfile2, ios::out);
		string DataLien;
		if (koko.is_open())
		{
			for (clsUser& c : vUsers)
			{

				DataLien = _ConverUserObjectToLine(c);
				if (c.MarkedForDeleted() == false)
				{
					koko << DataLien << endl;

				}

			}
			koko.close();
		}
	}
	void _Update()
	{
		vector<clsUser>_vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& c : _vUsers)
		{
			if (c.UserName== UserName)
			{
				c = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);
	}
	void _Addnew()
	{
		_AddDateLineToFile(_ConverUserObjectToLine(*this));

	}
	void _AddDateLineToFile(string stDateLine)
	{
		fstream koko;
		koko.open(Myfile2, ios::out | ios::app);
		if (koko.is_open())
		{
			koko << stDateLine << endl;
			koko.close();
		}

	}
public:

	enum enPermissions {
		eAll=-1,pListClients=1,pAddNewClient=2,PDeleteClient=4,
		pUpDateClients=8,pFindClient=16,pTransactions=32,pManageUsers=64,pLoginRegister=128,pCurrency=256
	};
	clsUser(enmode mode, string FirstName, string LastName, string Email, string Phone
		, string UserName, string Password, int Permissions) :clsPerson(FirstName, LastName
			, Email, Phone)
	{
		_Mode = mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		
	}
	
	
	bool IsEmpty()
	{
		return (_Mode == enmode::emptydate);
	}
	void setUserName(string UserName)
	{
		_UserName = UserName;
	}
	string getUserName()
	{
		return _UserName;
	}
	__declspec(property(get = getUserName ,put = setUserName))string UserName;
	
	void setPassword(string Password)
	{
		_Password = Password;
	}
	string getPassword()
	{
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	
	
	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	double getPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))double Permissions;
	
	
	static clsUser find(string UserName)
	{
		fstream koko;
		koko.open("Users.txt", ios::in);
		if (koko.is_open())
		{
			string Line;
			while (getline(koko, Line))
			{
				clsUser User = _ConvertLinetoUserobject(Line);
				if (User.UserName == UserName)
				{
					koko.close();
					return User;

				}

			}
			koko.close();

		}
		return _GetEmptyUserObject();
	}
	static clsUser find(string UserName, string Password)
	{
		fstream koko;
		koko.open("Users.txt", ios::in);
		if (koko.is_open())
		{
			string Line;
			while (getline(koko, Line))
			{
				clsUser User = _ConvertLinetoUserobject(Line);
				if (User.UserName == UserName &&clsUtil::DecryptText( User.Password,8) == Password)
				{
					koko.close();
					return User;

				}

			}
			koko.close();

		}
		return _GetEmptyUserObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFildUserNameExists = 2 };//if  account number exists in file return 2
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
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFildUserNameExists;

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
	static clsUser GetAddnewUserObject(string UserName)
	{
		return clsUser(enmode::Addnewmode, "", "", "", "", UserName, "", 0);
	}
	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::find(UserName);
		return (!User.IsEmpty());
	}
	bool Delete()
	{
		vector <clsUser>_vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& c : _vUsers)
		{
			if (c.UserName == _UserName)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	static vector <clsUser>GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	
     bool ChackAccessePermission(enPermissions Permissions)
	{
		int x = Permissions;
		int y = this->Permissions;

		if (this->Permissions == enPermissions::eAll)
		{
			return true;
		}
		if ((x & y ) == Permissions)
		{
			return true;

		}
			
		else
			return false;

	}
	  void SaveUsersLogin()
	 { 
		  string DataLien = _ConverUserloginToLine();
		 fstream koko;
		 koko.open("Login.txt", ios::out | ios::app);
		
		 if (koko.is_open())
		 {

			

			 koko << DataLien << endl;




			 koko.close();
		 }
	 }
	  struct stLoginRegisterRecord
	  {
		  string DateTime;
		  string UserName;
		  string Password;
		  int Permissions;

	  };

	  static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	  {
		  vector <stLoginRegisterRecord> vLoginRegisterRecord;

		  fstream MyFile;
		  MyFile.open("Login.txt", ios::in);//read Mode

		  if (MyFile.is_open())
		  {

			  string Line;

			  stLoginRegisterRecord LoginRegisterRecord;

			  while (getline(MyFile, Line))
			  {

				  LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				  vLoginRegisterRecord.push_back(LoginRegisterRecord);

			  }

			  MyFile.close();

		  }

		  return vLoginRegisterRecord;

	  }

};




