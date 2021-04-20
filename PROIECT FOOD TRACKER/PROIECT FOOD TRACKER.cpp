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
#define CINA 20
#define GUSTARI 10

#define USER 1
#define LOG  2
#define DATA 3
#define EXIT 4


int MENU_STATE = USER;



using namespace std;

ostream& operator<<(ostream& o, Produs p) {
	o << "Nume aliment: " << p.getAliment().getNume()<<endl;
	o << "Cantitate: " << p.getCantitate()<<endl;
	o << "Porti: " << p.getPortie() << endl;
	o << "--------------------------" << endl;
	return o;
}

ostream& operator<<(ostream& o, Menu menu) {
	for (int i = 0; i < menu.getAlimente_consumate().size(); i++) {
		o << menu.getAlimente_consumate().at(i);
	}
	return o;
}

// void user_menu() {
//	ifstream file;
//	ofstream file2;
//	User user{};
//
//	cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
//	cout << "1.Creare utilizator" << endl;
//	cout << "2.Accesare utilizator" << endl;
//	cout << "3.Editare utilizator" << endl;
//	cout << "4.Ecranul urmator" << endl;
//	int STATE_USER;
//	int input = 0;
//	cin >> STATE_USER;
//	switch (STATE_USER)
//	{
//	case 1:
//		//create user
//		system("cls");
//		user.createUser(file2, 1);
//		user.setUsersStats(file);
//		break;
//	case 2:
//		//access_user	
//		system("cls");
//		user.setUsersStats(file);
//		user.displayUsers();
//		while (true) {
//			cout << "-------------------MENU-------------------" << endl;
//			cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
//			cout << "1.Vizualizare BMI" << endl;
//			cout << "2.Vizualizare BMR" << endl;
//			cout << "3.Inapoi" << endl;
//			cin >> input;
//			if (input == 1) {
//				system("cls");
//				user.CalculateBmi();
//			}
//			else if (input == 2) {
//				system("cls");
//				cout << "Trebuie sa consumati: " << user.calculateBMR() << " calori pe zi" << endl;
//			}
//			else if (input == 3) {
//				break;
//			}
//		}
//		break;
//	case 3:
//		// edit_user
//		system("cls");
//		user.setUsersStats(file);
//		input = 0;
//		cout << "Ce doresti sa editezi" << endl;
//		user.displayUsers();
//		cin >> input;
//		system("cls");
//		user.editUser(file2, input);
//		break;
//	case 4:
//		MENU_STATE = LOG;
//		break;
//	default:
//		cout << "Comanda invalida" << endl;
//		MENU_STATE = USER;
//		break;
//	}
//	system("cls");
//}
//
// void alimente_menu() {
// Inceput:
//	 ifstream file;
//	 ofstream file2;
//	 bool check=false;
//	 int nr_al=0;
//	 char c = ' ';
//	 string line;
//	 int k=0;
//	 string data;
//	 
//	 Aliment* aliment{};
//	 Meal* meal=new Meal[calculNumarAlimente()];
//
//	 //Verific daca exista alimente in fisiere si daca exista setez meal-urile
//	 check = check_files();
//	 if (check) {
//		 setMeals(meal, aliment);
//	 }
//
//
//	 cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
//	 cout << "1. Vizualizare alimente" << endl;
//	 cout << "2. Introducere alimente" << endl;
//	 cout << "3.Next" << endl;
//	 int STATE_USER{};
//	 cin >> STATE_USER;
//	 int input = 0;
//	 system("cls");
//	 switch (STATE_USER)
//	 {
//	 case 1:
//		 // Verific daca fisierele au continut in ele
//		 check = check_files();
//		 if (!check) {
//			 cout << "*NU EXISTA PRODUSE, VA RUGAM SA LE ADAUGATI*" << endl;
//			 goto Inceput;
//		 }
//		 cout << "Pentru ce masa vrei sa vezi alimentele"<<endl;
//		 cout << "1.Mic dejun" << endl;
//		 cout << "2.Pranz" << endl;
//		 cout << "3.Cina" << endl;
//		 cout << "4.Gustari" << endl;
//		 cin >> input;
//		 system("cls");
//		 //Verific fisierele individual pt continut
//		 if (input == 1) {
//			 file.open("Mic dejun.txt");
//			 if (check_empty_file(file)) {
//				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
//				 cout << endl;
//				 goto Inceput;
//			 }
//			 file.close();
//		 }
//		 if (input == 2) {
//			 file.open("Pranz.txt");
//			 if (check_empty_file(file)) {
//				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
//				 cout << endl;
//				 goto Inceput;
//			 }
//			 file.close();
//
//		 }
//		 if (input == 3) {
//			 file.open("Cina.txt");
//			 if (check_empty_file(file)) {
//				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
//				 cout << endl;
//				 goto Inceput;
//			 }
//			 file.close();
//		 }
//		 if (input == 4) {
//			 file.open("Gustari.txt");
//			 if (check_empty_file(file)) {
//				 cout << "*NU EXISTA ALIMENTE IN ACEST FISIER*" << endl;
//				 cout << endl;
//				 goto Inceput;
//			 }
//			 file.close();
//
//		 }
//
//		 for (int i = 0; i < calculNumarAlimente(input); i++) {
//			 if (input == 1) {
//				 (meal + i)->getMic_dejun().displayProduct();
//			 }
//			 if (input == 2) {
//				 (meal + i)->getPranz().displayProduct();
//			 }
//			 if (input == 3) {
//				 (meal + i)->getCina().displayProduct();
//			 }
//			 if (input == 4) {
//				 (meal + i)->getGustari().displayProduct();
//			 }
//		 }
//		 break;
//	 case 2:
//		 cout << "Cate alimente vrei sa adaugi: ";
//		 cin >> input;	
//		 aliment->createProduct(input);		 
//		 break; 
//	 case 3:
//		 delete[] aliment;
//		 delete[] meal;
//		 MENU_STATE = DATA;
//		 break;
//	 default:
//		 cout << "Comanda invalida" << endl;
//		 MENU_STATE = LOG;
//		 break;
//	 }
// }
//
//
//void vizualizare_date() {
//	Aliment* aliment{};
//	vector<Meal> aux;
//	 string date;
//	 //FISERE
//	 ifstream file; 
//	 ofstream file2;
//
//	 int k = 0;
//	 //USER
//	 User user;	
//
//	 //Declarare variabile MENU
//	static Menu men_mic_dej;
//	static Menu men_pranz;
//	static Menu men_cina;
//	static Menu men_gustari;
//
//	string line;
//
//	bool check_nume=true;
//
//	 //Declarare variabile PROGRES
//	 Progres real;
//	 Progres expected;
//
//	 //Declarare variabile MEAL
//	 Meal meal;
//	 Meal mic_dejun{};
//	 Meal pranz{};
//	 Meal cina{};
//	 Meal gustari{};
//	 Meal* meals = new Meal[calculNumarAlimente()];
//
//	 //Produs
//	 Produs produs{};
//	 Produs* produse;
//	 user.setUsersStats(file);
//	 setMeals(meals, aliment);
//	 vector<Meal> lista_meals;
//	 for (int i = 0; i < calculNumarAlimente(); i++) {
//		 lista_meals.push_back(*(meals + i));
//	 }
//	
//
//	 //aliment=new Aliment[calculNumarAlimente()];
//	 //aliment->setProductStats(aliment);
//	
//	
//	 //Setez progresul pentru expected
//	 expected.setConsum_Cal(user.calculateBMR());
//	 mic_dejun.setExpected(expected % MIC_DEJUN);
//	 pranz.setExpected(expected % PRANZ);
//	 cina.setExpected(expected % CINA);
//	 gustari.setExpected(expected % GUSTARI);
//	 meal.setData(IDate());
//
//	 //Setez progresul pentru real
//	 file.open("Data.txt");
//	 //Verific daca fiserul Data.txt este gol sau daca data din el difera de data curenta si daca una din ele este adevarata atunci setez calorile reale cu cele expected
//	 //Si daca ambele sunt false atunci setez totul cum a fost de la ultima rulare a programului
//	 if (meal.checkData() || check_empty_file(file)) {	 
//		 setCaloriiReal(real,mic_dejun, pranz, cina, gustari,expected);	 
//		 date = currentTime();
//		 Date();	
//		 file.close();
//		 file.open("Temp_MD.txt");
//		 //Deschid fisierele istoric pentru ca pune Data in care se afla utilizatorul
//		 //Verifica daca fisierele sunt goale si daca nu transfer din fisierele temporare in fisierele istoric si dupa sterg fisierele temporare
//		 file2.open("Istoric_Mic_Dejun.txt", fstream::app);
//		 file2 << date << '\n';
//		 if (!check_empty_file(file)) {
//			 tranferFiles(file, file2);
//			 file2 << "--------------------------" << endl;
//		 }
//		
//		 
//		 file2.close();
//		 file.close();
//		 file.open("Temp_PR.txt");
//		 file2.open("Istoric_Pranz.txt", fstream::app);
//		 file2 << date << '\n';
//		 if (!check_empty_file(file)) {
//			 tranferFiles(file, file2);
//			 file2 << "--------------------------" << endl;
//		 }
//		
//		 file2.close();
//		 file.close();
//		 file.open("Temp_CN.txt");
//		 file2.open("Istoric_Cina.txt", fstream::app);
//		 file2 << date << '\n';
//		 if (!check_empty_file(file)) {
//			 tranferFiles(file, file2);
//			 file2 << "--------------------------" << endl;
//		 }
//		 file.close();
//		 file2.close();
//
//		 file.open("Temp_GS.txt");
//		 file2.open("Istoric_Gustari.txt", fstream::app);
//		 file2 << date << '\n';
//		 if (!check_empty_file(file)) {
//			 tranferFiles(file, file2);
//			 file2 << "--------------------------" << endl;
//		 }
//		 file.close();
//		 file2.close();
//
//		 
//		
//		 //Deschid fisierele temporare pentru a sterge continutul lor cand ziua se schimba
//		 file2.open("Temp_MD.txt");
//		 file2.close();
//		 file2.open("Temp_PR.txt");
//		 file2.close();
//		 file2.open("Temp_CN.txt");
//		 file2.close();
//		 file2.open("Temp_GS.txt");
//		 file2.close();
//
//	 }
//	 else {
//		 file.close();
//		 file.open("Progres real.txt");
//		 string line;
//		 int z = 0;
//		 //Setez consumul real pentru fiecare masa de la ultima rulare
//		 while (getline(file, line)) {
//			 Progres aux;
//			 if (z == 0) {
//				
//				 real.setConsum_Cal(stoi(line));
//			 }
//			 if (z == 1) {			 
//				 aux.setConsum_Cal(stoi(line));
//				 mic_dejun.setReal(aux);
//				
//			 }else if (z == 2) {
//				 aux.setConsum_Cal(stoi(line));
//				 pranz.setReal(aux);
//				
//			 }else if (z == 3) {
//				 aux.setConsum_Cal(stoi(line));
//				 cina.setReal(aux);
//			 }
//			 else if (z == 4) {
//				 aux.setConsum_Cal(stoi(line));
//				 gustari.setReal(aux);
//			 }
//			 z++;
//		 }
//		 file.close();
//		 //SET PENTRU MENU MIC DEJUN
//		 file.open("Temp_MD.txt");
//		 int a = 0;
//		 a = calculTempFilesMD();
//		 produse = new Produs[a];		
//		 produse->setProduse(file, produse, a);
//		 setMenus(men_mic_dej, produse, a);	 
//		 file.close();
//		 delete[] produse;
//
//		 //SET PENTRU MENU PRANZ
//		 file.open("Temp_PR.txt");
//		 a = calculTempFilesPR();
//		 produse = new Produs[a];
//		 produse->setProduse(file, produse, a);
//		 setMenus(men_pranz, produse, a);
//		 file.close();
//		 delete[] produse;
//
//		 //SET PENTRU MENU CINA
//		 file.open("Temp_CN.txt");
//		 a = calculTempFilesCN();
//		 produse = new Produs[a];
//		 produse->setProduse(file, produse, a);
//		 setMenus(men_cina, produse, a);
//		 delete[] produse;
//		 file.close();
//
//		 //SET PENTRU GUSTARI
//		 file.open("Temp_GS.txt");
//		 a = calculTempFilesGS();
//		 produse = new Produs[a];
//		 produse->setProduse(file, produse, a);
//		 setMenus(men_gustari, produse, a);
//		 delete[] produse;
//		 file.close();
//		 
//	 }
//	 cout << "1.Vizualizare Progres" << endl;
//	 cout << "2.Vizualizare Alimente" << endl;
//	 cout << "3.Introduce aliment consumat" << endl;
//	 cout << "4.Vizualizeaza alimente consumate" << endl;
//	 cout << "5.Exit" << endl;
//	 
//	 int STATE_USER = 0;
//	 cin >> STATE_USER;
//	
//	 switch (STATE_USER)
//	 {
//	 case 1:
//		 // Afisez progresul real si cel expected
//		 system("cls");
//		 cout << "1.Progres real" << endl;
//		 cout << "2.Progres expected" << endl;
//		 cin >> STATE_USER;
//		 if (STATE_USER == 1) {
//			 system("cls");
//			 cout << "*****************************************" << endl;
//			 cout << "Proges real total: " << real.getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres real Mic dejun: " << mic_dejun.getReal().getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres real Pranz: " <<pranz.getReal().getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres real Cina: " << cina.getReal().getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres real Gustari: " << gustari.getReal().getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//		 }
//		 else if (STATE_USER == 2) {
//			 system("cls");
//			 cout << "*****************************************" << endl;
//			 cout << "Proges expected total: " << user.calculateBMR() << endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres expect Mic dejun: "<<mic_dejun.getExpected().getConsum_cal() <<endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres expect Pranz: "<< pranz.getExpected().getConsum_cal()<<endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres expect Cina: "<<cina.getExpected().getConsum_cal() <<endl;
//			 cout << "*****************************************" << endl;
//			 cout << "Progres expect Gustari: " << gustari.getExpected().getConsum_cal() << endl;
//			 cout << "*****************************************" << endl;
//		 }
//		 break;
//	 case 2:
//
//		 //Afisez alimentele recomandatate pentru fiecare Masa
//		 cout << "ALIMENTE RECOMANDATE PENTRU" << endl;
//		 cout << "1.Mic dejun" << endl;
//		 cout << "2.Pranz" << endl;
//		 cout << "3.Cina" << endl;
//		 cout << "4.Gustari" << endl;
//		 cin >> STATE_USER;
//		 if (STATE_USER == 1) {
//		
//			 afisare_alimente_recomandateMD(mic_dejun, lista_meals);
//		 }
//		 else if (STATE_USER == 2) {
//			 afisare_alimente_recomandatePR(pranz, lista_meals);
//		 }
//		 else if (STATE_USER == 3) {
//			 afisare_alimente_recomandateCN(cina, lista_meals);
//		 }
//		 else if (STATE_USER == 4) {
//			 afisare_alimente_recomandateGS(gustari, lista_meals);
//		 }
//		
//		 break;
//	 case 3:
//	 Nume:
//
//		 cout << "Alegeti un meniu din care face parte alimentul" << endl;
//		 cout << "1.Mic dejun" << endl;
//		 cout << "2.Pranz" << endl;
//		 cout << "3.Cina" << endl;
//		 cout << "4.Gustari" << endl;
//		 cin >> STATE_USER;
//		
//		 //Introduc numele alimentului si daca il gaseste il pun sa aleaga o cantitate sau o portie
//		 //Si daca alimentul este gasit setez progesul real si il bag si in fisier
//		 //Scad din progresul real pe care il avea inainte de scadere si dupa il bag si in fisier
//
//		 //Daca nu exista numele duc inapoi si afisez un mesaj
//		 if (STATE_USER == 1) {	
//			 cout << "Introduceti numele alimentului" << endl;
//			 string name;
//			 cin >> name;
//			 file2.open("Temp_MD.txt", fstream::app);
//			 for (int i = 0; i < calculMicDejunNr(); i++) {
//				 if (lista_meals.at(i).getMic_dejun().getNume() == name) {
//					 cout << "Produsul a fost gasit" << endl;
//					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
//					 cout << "1.Cantitate" << endl;
//					 cout << "2.Portie" << endl;
//					 int input = 0;
//					 cin >> input;
//					 if (input == 1) {
//						 cout << "Cantitate: ";
//						 int cantitate = 0;
//						 cin >> cantitate;
//						 produs.setAliment(lista_meals.at(i).getMic_dejun());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(0);
//						 men_mic_dej.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 mic_dejun.setReal(mic_dejun.getReal().getConsum_cal() - lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, mic_dejun.getReal().getConsum_cal(), STATE_USER);
//					 }
//					 else if (input == 2) {
//						 int nr_porti;
//						 double cantitate;
//						 cout << "Cate porti ati consumat: ";
//						 cin >> nr_porti;
//						 cout << "Cantitatea per portie: ";
//						 cin >> cantitate;
//						 cantitate = cantitate * nr_porti;
//						 produs.setAliment(lista_meals.at(i).getMic_dejun());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(nr_porti);
//						 men_mic_dej.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 mic_dejun.setReal(mic_dejun.getReal().getConsum_cal() - lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getMic_dejun().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, mic_dejun.getReal().getConsum_cal(), STATE_USER);
//					 }
//					 
//					break;
//				 }
//			 }
//			 file2.close();
//		 }
//		 if (STATE_USER == 2) {
//			 cout << "Introduceti numele alimentului" << endl;
//			 string name;
//			 cin >> name;
//			 file2.open("Temp_PR.txt", fstream::app);
//			 for (int i = 0; i < calculPranzNr(); i++) {
//				 if (lista_meals.at(i).getPranz().getNume() == name) {
//					 cout << "Produsul a fost gasit" << endl;
//					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
//					 cout << "1.Cantitate" << endl;
//					 cout << "2.Portie" << endl;
//
//					 int input = 0;
//					 cin >> input;
//					 if (input == 1) {
//						 cout << "Cantitate: ";
//						 double cantitate = 0;
//						 cin >> cantitate;
//						 produs.setAliment(lista_meals.at(i).getPranz());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(0);
//						 men_pranz.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 pranz.setReal(pranz.getReal().getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, pranz.getReal().getConsum_cal(), STATE_USER);
//					 }
//					 else if (input == 2) {
//						 int nr_porti;
//						 double cantitate;
//						 cout << "Cate porti ati consumat: ";
//						 cin >> nr_porti;
//						 cout << "Cantitatea per portie: ";
//						 cin >> cantitate;
//						 cantitate = cantitate * nr_porti;
//						 produs.setAliment(lista_meals.at(i).getPranz());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(nr_porti);
//						 men_pranz.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 pranz.setReal(pranz.getReal().getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getPranz().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, pranz.getReal().getConsum_cal(), STATE_USER);
//					 }
//					
//					 break;
//				 }
//			 }
//			 file2.close();
//		 }
//		 if (STATE_USER == 3) {
//			 cout << "Introduceti numele alimentului" << endl;
//			 string name;
//			 cin >> name;
//			 file2.open("Temp_CN.txt", fstream::app);
//			 int k = 0;
//			 for (int i = 0; i < calculCinaNr(); i++) {
//				 if (lista_meals.at(i).getCina().getNume() == name) {
//					 cout << "Produsul a fost gasit" << endl;
//					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
//					 cout << "1.Cantitate" << endl;
//					 cout << "2.Portie" << endl;
//					 int input = 0;
//					 cin >> input;
//					 if (input == 1) {
//						 cout << "Cantitate: ";
//						 int cantitate = 0;
//						 cin >> cantitate;
//						 produs.setAliment(lista_meals.at(i).getCina());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(0);
//						 men_cina.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 cina.setReal(cina.getReal().getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, cina.getReal().getConsum_cal(), STATE_USER);
//					 }
//					 else if (input == 2) {
//						 int nr_porti;
//						 double cantitate;
//						 cout << "Cate porti ati consumat: ";
//						 cin >> nr_porti;
//						 cout << "Cantitatea per portie: ";
//						 cin >> cantitate;
//						 cantitate = cantitate * nr_porti;
//						 produs.setAliment(lista_meals.at(i).getCina());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(nr_porti);
//						 men_cina.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 cina.setReal(cina.getReal().getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getCina().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, cina.getReal().getConsum_cal(), STATE_USER);
//					 }					
//					 
//					 break;
//				 }
//				
//			 }
//		
//			 file2.close();
//		 }
//		 if (STATE_USER == 4) {
//			 cout << "Introduceti numele alimentului" << endl;
//			 string name;
//			 cin >> name;
//			 file2.open("Temp_GS.txt", fstream::app);
//			 int k = 0;
//			 for (int i = 0; i < calculGustariNr(); i++) {
//				 if (lista_meals.at(i).getGustari().getNume() == name) {
//					 cout << "Produsul a fost gasit" << endl;
//					 cout << "Va rugam sa adaugati o cantitate sau o portie" << endl;
//					 cout << "1.Cantitate" << endl;
//					 cout << "2.Portie" << endl;
//					 int input = 0;
//					 cin >> input;
//					 if (input == 1) {
//						 cout << "Cantitate: ";
//						 int cantitate = 0;
//						 cin >> cantitate;
//						 produs.setAliment(lista_meals.at(i).getGustari());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(0);
//						 men_gustari.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 gustari.setReal(gustari.getReal().getConsum_cal() - lista_meals.at(i).getGustari().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getGustari().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina,gustari ,expected, gustari.getReal().getConsum_cal(), STATE_USER);
//					 }
//					 else if (input == 2) {
//						 int nr_porti;
//						 double cantitate;
//						 cout << "Cate porti ati consumat: ";
//						 cin >> nr_porti;
//						 cout << "Cantitatea per portie: ";
//						 cin >> cantitate;
//						 cantitate = cantitate * nr_porti;
//						 produs.setAliment(lista_meals.at(i).getGustari());
//						 produs.setCantitate(cantitate);
//						 produs.setPortie(nr_porti);
//						 men_gustari.adaugareProdusConsumat(produs);
//						 produs.adaugaProdusFiser(file2);
//
//						 gustari.setReal(gustari.getReal().getConsum_cal() - lista_meals.at(i).getGustari().calculCaloriProdus(cantitate));
//						 real.setConsum_Cal(real.getConsum_cal() - lista_meals.at(i).getGustari().calculCaloriProdus(cantitate));
//						 setCaloriiReal(real, mic_dejun, pranz, cina, gustari,expected, gustari.getReal().getConsum_cal(), STATE_USER);
//					 }
//
//					 break;
//				 }
//
//			 }
//
//			 file2.close();
//		 }
//		 if (check_nume) {
//			 cout << "Produsul nu a fost gasit" << endl;
//			 goto Nume;
//		 }
//
//		 break;
//	 case 4:
//		 cout << "1.Data curenta" << endl;
//		 cout << "2.Alta data" << endl;
//		 cin >> STATE_USER;
//		 if (STATE_USER == 1) {
//			 cout << "1.Mic dejun" << endl;
//			 cout << "2.Pranz" << endl;
//			 cout << "3.Cina" << endl;
//			 cout << "4.Gustari" << endl;
//			 cin >> STATE_USER;
//			 if (STATE_USER == 1) {
//				 cout<<men_mic_dej<<endl; 
//				 
//			 }
//			 if (STATE_USER == 2) {
//				 cout << men_pranz<<endl;
//			 }
//			 if (STATE_USER == 3) {
//				 cout << men_cina<<endl;
//			 }
//			 if (STATE_USER == 4) {
//				 cout << men_gustari << endl;
//			 }
//		 }
//		 else if (STATE_USER == 2) {
//			 string data;
//			 cout << "1.Mic dejun" << endl;
//			 cout << "2.Pranz" << endl;
//			 cout << "3.Cina" << endl;
//			 cout << "4.Gustari" << endl;
//			 cin >> STATE_USER;
//			 if (STATE_USER == 1) {
//				 cout << "Scrie data din care vezi sa vezi istoricul in format DD:MM:YYYY: ";
//				 cin >> data;
//				 file.open("Istoric_Mic_Dejun.txt");
//				 showIstoric(data, file);
//				 file.close();
//
//			 }
//			 if (STATE_USER == 2) {
//				 cout << "Scrie data din care vezi sa vezi istoricul in format DD:MM:YYYY: ";
//				 cin >> data;
//				 file.open("Istoric_Pranz.txt");
//				 showIstoric(data, file);
//				 file.close();
//			 }
//			 if (STATE_USER == 3) {
//				 cout << "Scrie data din care vezi sa vezi istoricul in format DD:MM:YYYY: ";
//				 cin >> data;
//				 file.open("Istoric_Cina.txt");
//				 showIstoric(data, file);
//				 file.close();
//			 }
//			 if (STATE_USER == 4) {
//				 cout << "Scrie data din care vezi sa vezi istoricul in format DD:MM:YYYY: ";
//				 cin >> data;
//				 file.open("Istoric_Gustari.txt");
//				 showIstoric(data, file);
//				 file.close();
//			 }
//		
//
//		 }
//			 
//		 break;
//	 case 5:
//		 MENU_STATE = EXIT;
//	 default:
//		 cout << "Comanda invalida" << endl;
//		 MENU_STATE = DATA;
//		 break;
//	 }
//
// }

int main()
{
	bool exit = true;
	while (exit) {
		switch (MENU_STATE)
		{
		case USER:
			user_menu();
			break;
		case LOG:
			alimente_menu();
			break;
		case DATA:
			vizualizare_date();
			break;
		case EXIT:
			exit = false;
			break;
		default:
			break;
		}
	}


	
	
	
	return 0;
}

