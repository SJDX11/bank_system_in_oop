#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include<iomanip>
#include "clsDate.h"
using namespace std;

class clsLogin 
{
private:

	
	string _UserName;
	string _Password;
	int _Permissions;
	string _DateTime;

	
	static clsLogin  _ConvertLinetoLoginobject(string line, string seperator = "#//#")
	{

		vector<string>vLDate;
		vLDate = clsString::Split(line, seperator);
		return clsLogin ( vLDate[0], vLDate[1], vLDate[2], stoi(vLDate[3]));

	}

	

	

	static vector <clsLogin>_LoadLoginDateFromFile()
	{
		vector<clsLogin>vLogin;
		fstream koko;
		koko.open("Login.txt", ios::in);
		if (koko.is_open())
		{
			string Lien;
			while (getline(koko, Lien))
			{
				clsLogin User = _ConvertLinetoLoginobject(Lien);
				vLogin.push_back(User);

			}
			koko.close();

		}
		return vLogin;
	}

	
public:

	
	clsLogin(string DateTime,string UserName, string Password, int Permissions) 
	{
		
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_DateTime = DateTime;

	}


	
	void setUserName(string UserName)
	{
		_UserName = UserName;
	}
	string getUserName()
	{
		return _UserName;
	}
	__declspec(property(get = getUserName, put = setUserName))string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}
	string getPassword()
	{
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;

	


	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	short getPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))short Permissions;

	void setDateTime(int DateTime)
	{
		_DateTime =DateTime;
	}
	string getDateTime()
	{
		return _DateTime;
	}
	__declspec(property(get = getDateTime, put = setDateTime))string DataTime;

	
	
	
	static vector <clsLogin>GetLoginRegisterList()
	{
		return _LoadLoginDateFromFile();
	}

	
	
};


