#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include "User.h"
#include "Aliment.h"
#include "Meal.h"
#include "Menu.h"
#include "Produs.h"
#include "Progres.h"
#include "Functions.h"

#define USER 1
#define LOG  2
#define DATA 3

int MENU_STATE = USER;

using namespace std;

 void user_menu() {
	ifstream file;
	ofstream file2;
	User user{};

	cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
	cout << "1.Creare utilizator" << endl;
	cout << "2.Accesare utilizator" << endl;
	cout << "3.Editare utilizator" << endl;
	cout << "4.Ecranul urmator" << endl;
	int STATE_USER;
	int input = 0;
	cin >> STATE_USER;
	switch (STATE_USER)
	{
	case 1:
		//create user
		system("cls");
		user.createUser(file2, 1);
		user.setUsersStats(file);
		break;
	case 2:
		//access_user	
		system("cls");
		user.setUsersStats(file);
		user.displayUsers();
		while (true) {
			cout << "-------------------MENU-------------------" << endl;
			cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
			cout << "1.Vizualizare BMI" << endl;
			cout << "2.Vizualizare BMR" << endl;
			cout << "3.Inapoi" << endl;
			cin >> input;
			if (input == 1) {
				system("cls");
				user.CalculateBmi();
			}
			else if (input == 2) {
				system("cls");
				cout << "Trebuie sa consumati: " << user.calculateBMR() << " calori pe zi" << endl;
			}
			else if (input == 3) {
				break;
			}
		}
		break;
	case 3:
		// edit_user
		system("cls");
		user.setUsersStats(file);
		input = 0;
		cout << "Ce doresti sa editezi" << endl;
		user.displayUsers();
		cin >> input;
		system("cls");
		user.editUser(file2, input);
		break;
	case 4:
		MENU_STATE = 2;
		break;
	default:
		cout << "Error" << endl;
		break;
	}
	system("cls");
}

 void alimente_menu() {
	 ifstream file;
	 ofstream file2;
	 int size = calculNumarAlimente(file);
	 Aliment* aliment=new Aliment[size];
	 Meal* meal{};
	
	 cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
	 cout << "1. Vizualizare alimente" << endl;
	 cout << "2. Introducere alimente" << endl;
	 cout << "3.Next" << endl;
	 int STATE_USER{};
	 cin >> STATE_USER;
	 int input = 0;
	 switch (STATE_USER)
	 {
	 case 1:
		 cout << "Pentru ce masa vrei sa vezi alimentele"<<endl;
		 cout << "1.Mic dejun" << endl;
		 cout << "2.Pranz" << endl;
		 cout << "3.Cina" << endl;
		 cin >> input;
		 for (int i = 0; i < calculNumarAlimente(file,input); i++) {
			 if (input == 1) {
				 (meal + i)->getMic_dejun()->displayProduct();
			 }
			 if (input == 2) {
				 (meal + i)->getPranz()->displayProduct();
			 }
			 if (input == 3) {
				 (meal + i)->getCina()->displayProduct();
			 }
		 }
		 break;
	 case 2:	 
		 cout << "Cate alimente vrei sa adaugi: ";
		 cin >> input;
		 aliment->createProduct(file2, input);
		 aliment->setProductStats(aliment, file, input);
		 if (aliment->getMeal() == 1) {
			 meal->setMic_dejun(aliment);
			 delete[] aliment;
			 
		 }if (aliment->getMeal() == 2) {
			 meal->setPranz(aliment);
			 delete[] aliment;
		 }
		 if (aliment->getMeal() == 3) {
			 meal->setCina(aliment);
			 delete[] aliment;
		 }
		 break;
	 case 3:
		 MENU_STATE = DATA;
		 break;
	 default:
		 cout << "ERROR" << endl;
		 break;
	 }
 }

 void vizualizare_date() {

 }
  
int main()
{
	
	while (true) {
		alimente_menu();
	}
	//time_t rawtime;
	//struct tm* timeinfo;

	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	//string time = asctime(timeinfo);
	//string day;
	//for (int i = 0; i < 3; i++) {
	//	day.push_back(time.at(i));
	//}
	//
	//cout << day << endl;

	return 0;
}

