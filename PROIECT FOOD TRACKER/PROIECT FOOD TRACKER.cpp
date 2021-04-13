#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <stdlib.h>
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


#define MIC_DEJUN 30
#define PRANZ 40
#define CINA 30
#define GUSTARI 5

#define USER 1
#define LOG  2
#define DATA 3

// sa bag menu-urile in Functions.h si sa bag argumentul MENU_STATE but for later
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
 Inceput:
	 ifstream file;
	 ofstream file2;
	 bool check=false;
	 int nr_al=0;
	 char c = ' ';
	 string line;
	 int k=0;
	 
	 Aliment* aliment{};
	 Meal* meal=new Meal[calculNumarAlimente()];

	 //Verific daca exista alimente in fisiere si daca exista setez meal-urile
	 check = check_files();
	 if (check) {
		 setMeals(meal, aliment);
	 }


	 cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
	 cout << "1. Vizualizare alimente" << endl;
	 cout << "2. Introducere alimente" << endl;
	 cout << "3.Next" << endl;
	 int STATE_USER{};
	 cin >> STATE_USER;
	 int input = 0;
	 system("cls");
	 switch (STATE_USER)
	 {
	 case 1:
		 // Verific daca fisierele au continut in ele
		 check = check_files();
		 if (!check) {
			 cout << "*NU EXISTA PRODUSE, VA RUGAM SA LE ADAUGATI*" << endl;
			 goto Inceput;
		 }
		 cout << "Pentru ce masa vrei sa vezi alimentele"<<endl;
		 cout << "1.Mic dejun" << endl;
		 cout << "2.Pranz" << endl;
		 cout << "3.Cina" << endl;
		 cin >> input;
		 system("cls");
		 //Verific fisierele individual pt continut
		 if (input == 1) {
			 file.open("Mic dejun.txt");
			 if (check_empty_file(file)) {
				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
				 cout << endl;
				 goto Inceput;
			 }
			 file.close();
		 }
		 if (input == 2) {
			 file.open("Pranz.txt");
			 if (check_empty_file(file)) {
				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
				 cout << endl;
				 goto Inceput;
			 }
			 file.close();

		 }
		 if (input == 3) {
			 file.open("Cina.txt");
			 if (check_empty_file(file)) {
				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
				 cout << endl;
				 goto Inceput;
			 }
			 file.close();
		 }

		 for (int i = 0; i < calculNumarAlimente(input); i++) {
			 if (input == 1) {
				 (meal + i)->getMic_dejun().displayProduct();
			 }
			 if (input == 2) {
				 (meal + i)->getPranz().displayProduct();
			 }
			 if (input == 3) {
				 (meal + i)->getCina().displayProduct();
			 }
		 }
		 break;
	 case 2:
		 cout << "Cate alimente vrei sa adaugi: ";
		 cin >> input;	
		 aliment->createProduct(input);		 
		 break;
	 case 3:
		 delete[] aliment;
		 delete[] meal;
		 MENU_STATE = DATA;
		 break;
	 default:
		 cout << "ERROR" << endl;
		 break;
	 }
 }

 void setCaloriiReal(Progres& real, Meal& mic_dejun, Meal& pranz, Meal& cina,Progres expected) {
	 ofstream file2;
	 file2.open("Progres real.txt" );
	 real.setConsum_Cal(expected.getConsum_cal());
	 file2 << real.getConsum_cal();
	 file2 << '\n';
	 mic_dejun.setReal(expected % MIC_DEJUN);
	 file2 << mic_dejun.getReal().getConsum_cal();
	 file2 << '\n';

	 pranz.setReal(expected % PRANZ);
	 file2 << pranz.getReal().getConsum_cal();
	 file2 << '\n';
	 
	 cina.setReal(expected % CINA);
	 file2 << cina.getReal().getConsum_cal();
	 file2 << '\n';

	 file2.close();

 }
 void setCaloriiReal(Progres& real,Meal& mic_dejun, Meal& pranz, Meal& cina, Progres expected,int cal,int ch) {
	 ofstream file2;
	 file2.open("Progres real.txt");
	 file2 << real.getConsum_cal();
	 file2 << '\n';
	 if (ch == 1) {
		 file2 << mic_dejun.getReal().getConsum_cal();
		 file2 << '\n';
		 mic_dejun.setReal(cal);
	 }
	 else {
		 mic_dejun.setReal(mic_dejun.getReal().getConsum_cal());
		 file2 << mic_dejun.getReal().getConsum_cal();
		 file2 << '\n';
	 }
	 if (ch == 2) {
		 pranz.setReal(cal);
		 file2 << pranz.getReal().getConsum_cal();
		 file2 << '\n';
	 }
	 else {
		 pranz.setReal(pranz.getReal().getConsum_cal());
		 file2 << pranz.getReal().getConsum_cal();
		 file2 << '\n';
	 }
	 if (ch == 3) {
		 cina.setReal(cal);
		 file2 << cina.getReal().getConsum_cal();
		 file2 << '\n';
	 }
	 else {
		 cina.setReal(cina.getReal().getConsum_cal());
		 file2 << cina.getReal().getConsum_cal();
		 file2 << '\n';
	 }
	
	 file2.close();

 }

void vizualizare_date() {

	 ifstream file; 
	 int k = 0;
	 User user;
	 user.setUsersStats(file);
	 Meal meal;
	 Aliment* aliment{};
	 Meal* meals = new Meal[calculNumarAlimente()];
	 setMeals(meals, aliment);
	 vector<Meal> lista_meals;
	 for (int i = 0; i < calculNumarAlimente(); i++) {
		 lista_meals.push_back(*(meals + i));
	 }
	 vector<Meal> aux;
	 Progres real;
	 Progres expected;

	 //aliment=new Aliment[calculNumarAlimente()];
	 //aliment->setProductStats(aliment);
	 Meal mic_dejun{};
	 Meal pranz{};
	 Meal cina{};
	 cout << "1.Vizualizare Progres" << endl;
	 cout << "2.Vizualizare Alimente" << endl;
	 cout << "3.Introduce aliment consumat" << endl;
	 expected.setConsum_Cal(user.calculateBMR());
	 int STATE_USER = 0;
	 cin >> STATE_USER;
	
	 //Setez progresul pentru expected
	 mic_dejun.setExpected(expected % MIC_DEJUN);
	 pranz.setExpected(expected % PRANZ);
	 cina.setExpected(expected % CINA);
	 meal.setData(IDate());

	 //Setez progresul pentru real
	 file.open("Data.txt");
	 if (meal.checkData() || check_empty_file(file)) {	 
		 setCaloriiReal(real,mic_dejun, pranz, cina, expected);	 
		 Date();	 
		 file.close();
	 }
	 else {
		 file.close();
		 file.open("Progres real.txt");
		 string line;
		 int z = 0;
		 while (getline(file, line)) {
			 Progres aux;
			 if (z == 0) {
				
				 real.setConsum_Cal(stoi(line));
			 }
			 if (z == 1) {			 
				 aux.setConsum_Cal(stoi(line));
				 mic_dejun.setReal(aux);
				
			 }else if (z == 2) {
				 aux.setConsum_Cal(stoi(line));
				 pranz.setReal(aux);
				
			 }else if (z == 3) {
				 aux.setConsum_Cal(stoi(line));
				 cina.setReal(aux);
			 }
			 z++;
		 }
		 
	 }
	
	
	 switch (STATE_USER)
	 {
	 case 1:
		 system("cls");
		 cout << "1.Progres real" << endl;
		 cout << "2.Progres expected" << endl;
		 cin >> STATE_USER;
		 if (STATE_USER == 1) {
			 system("cls");
			 cout << "*****************************************" << endl;
			 cout << "Proges real total: " << real.getConsum_cal() << endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres real Mic dejun: " << mic_dejun.getReal().getConsum_cal() << endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres real Pranz: " <<pranz.getReal().getConsum_cal() << endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres real Cina: " << cina.getReal().getConsum_cal() << endl;
			 cout << "*****************************************" << endl;
		 }
		 else if (STATE_USER == 2) {
			 system("cls");
			 cout << "*****************************************" << endl;
			 cout << "Proges expected total: " << user.calculateBMR() << endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres expect Mic dejun: "<<mic_dejun.getExpected().getConsum_cal() <<endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres expect Pranz: "<< pranz.getExpected().getConsum_cal()<<endl;
			 cout << "*****************************************" << endl;
			 cout << "Progres expect Cina: "<<cina.getExpected().getConsum_cal() <<endl;
			 cout << "*****************************************" << endl;
		 }
		 break;
	 case 2:
		 cout << "ALIMENTE RECOMANDATE PENTRU" << endl;
		 cout << "1.Mic dejun" << endl;
		 cout << "2.Pranz" << endl;
		 cout << "3.Cina" << endl;
		 cin >> STATE_USER;
		 if (STATE_USER == 1) {
		
			 afisare_alimente_recomandateMD(mic_dejun, lista_meals);
		 }
		 else if (STATE_USER == 2) {
			 afisare_alimente_recomandatePR(pranz, lista_meals);
		 }
		 else if (STATE_USER == 3) {
			 afisare_alimente_recomandateCN(cina, lista_meals);
		 }
		
		 break;
	 case 3:
		 cout << "Alegeti un meniu din care face parte alimenul" << endl;
		 cout << "1.Mic dejun" << endl;
		 cout << "2.Pranz" << endl;
		 cout << "3.Cina" << endl;
		 cin >> STATE_USER;
		
		 if (STATE_USER == 1) {	
			 cout << "Introduceti numele alimentului" << endl;
			 string name;
			 cin >> name;
			 for (int i = 0; i < calculMicDejunNr(); i++) {
				 if (lista_meals.at(i).getMic_dejun().getNume() == name) {
					 cout << "Produsul a fost gasit" << endl;
					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
					 int cantitate=0;
					 cin >> cantitate;
					mic_dejun.setReal(mic_dejun.getReal().getConsum_cal()- lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate)) ;
					real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate));
					setCaloriiReal(real,mic_dejun, pranz, cina, expected, mic_dejun.getReal().getConsum_cal(), STATE_USER);
					break;
				 }
			 }
		 }
		 if (STATE_USER == 2) {
			 cout << "Introduceti numele alimentului" << endl;
			 string name;
			 cin >> name;

			 for (int i = 0; i < calculPranzNr(); i++) {
				 if (lista_meals.at(i).getPranz().getNume() == name) {
					 cout << "Produsul a fost gasit" << endl;
					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
					 int cantitate = 0;
					 cin >> cantitate;
					 pranz.setReal(pranz.getReal().getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
					 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
					 setCaloriiReal(real, mic_dejun, pranz, cina, expected, pranz.getReal().getConsum_cal(), STATE_USER);
					 break;
				 }
			 }

		 }
		 if (STATE_USER == 3) {
			 cout << "Introduceti numele alimentului" << endl;
			 string name;
			 cin >> name;
			 for (int i = 0; i < calculCinaNr(); i++) {
				 if (lista_meals.at(i).getCina().getNume() == name) {
					 cout << "Produsul a fost gasit" << endl;
					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
					 int cantitate = 0;
					 cin >> cantitate;
					 cina.setReal(cina.getReal().getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
					 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
					 setCaloriiReal(real, mic_dejun, pranz, cina, expected, cina.getReal().getConsum_cal(), STATE_USER);
					 break;
				 }
			 }
		 }
		 break;
	 default:
		 cout << "Error" << endl;
		 break;
	 }

 }

int main()
{
	bool exit = true;
	while (exit) {
		vizualizare_date();

	}

	
	
	return 0;
}

