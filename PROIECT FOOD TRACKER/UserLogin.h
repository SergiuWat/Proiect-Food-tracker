#include<string>
#include <iostream>
using namespace std;
#pragma once
class UserLogin
{
private:
	string user_name;
	string password;
public:
	void setUserName(string);
	void setPassword(string);

	string getUserName();
	string getPassword();

	void createUserLogin();

	bool verifyLogin(string,string);
};

