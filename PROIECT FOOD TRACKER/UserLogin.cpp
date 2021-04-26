#include "UserLogin.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void UserLogin::setUserName(string nume) {
	user_name = nume;
}
void UserLogin::setPassword(string parola) {
	password = parola;
}

string UserLogin::getUserName() {
	return user_name;
}
string UserLogin::getPassword() {
	return password;
}

void UserLogin::createUserLogin() {
	Inceput:
	ofstream file;
	file.open("Login_Data.txt");
	string line;
	char ch;
	int i = 1;
	bool exit = true;;
	cout << "Adauga un user name: ";
	cin >> line;
	file << line << endl;
	line.clear();
	cout << "Adauga o parola" << endl;
	cout << "Parola trebuie sa aibe cel mult 25 de caractere" << endl;
	while (exit) {
		ch = _getch();
		if (ch == 13) {
			exit = false;
		}
		cout << "*";
		line.push_back(ch);
		i++;
	}
	if (i <= 25) {
		file << line << endl;
	}
	else {
		cout << "Parola este mai mare decat 25 de caractere te rog scrie una care sa aiba cel mult 25" << endl;
		file.close();
		goto Inceput;
	}
		
	file.close();
}

bool UserLogin::verifyLogin(string user,string parola) {
	ifstream file;
	string line;
	file.open("Login_Data.txt");
	int i = 0;
	bool check = false;
	while (getline(file, line)) {
		if (i == 0) {
			if (line == user) {
				check = true;
			}
			else {
				check = false;
			}
		}
		if (i == 1) {
			if (line == parola) {
				check = true;
			}
			else
			{
				check = false;
			}
		}
		i++;
		
	}
	return check;
	file.close();
}
