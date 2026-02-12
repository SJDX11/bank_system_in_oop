//#pragma once
//#include "clsUser.h"
//#include "global.h"
//#include "clsDate.h"
//class clsLoginRegister
//{
//private:
//	static string _ConverUserloginToLine(clsUser User, string Seperator = "#//#")
//	{
//		string stUserRecord = "";
//		stUserRecord += clsDate::DateToString(clsDate()) + Seperator;
//		stUserRecord += clsDate::CurrentTime() + Seperator;
//		stUserRecord += User.UserName + Seperator;
//		stUserRecord += User.Password +Seperator;
//		stUserRecord += to_string(User.Permissions);
//		return stUserRecord;
//	}
//	static void _SaveUsersLoginToFile(clsUser CurrentUser)
//	{
//		fstream koko;
//		koko.open("Login.txt", ios::out | ios::app);
//		string DataLien;
//		if (koko.is_open())
//		{
//			
//				DataLien = _ConverUserloginToLine(CurrentUser);
//				
//					koko << DataLien << endl;
//
//				
//
//			
//			koko.close();
//		}
//	}
//
//public:
//	static void _loginFile( clsUser CurrentUser)
//	{
//		_SaveUsersLoginToFile(CurrentUser);
//
//	}
//
//};
//
