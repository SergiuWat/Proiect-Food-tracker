#pragma warning (disable: 4996)
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include "Meal.h"
#include "Aliment.h"
#include "USER.h"

#pragma once
using namespace std;

//Function Prototype
inline void clearStrings(string*, string*, string*);
inline void clearStrings(string*, string*);
inline bool check_empty_file(ifstream&);
//inline void adaugareProdusLista(Aliment*, vector<Aliment>&);
//inline int calculNumarAlimente(ifstream& );
inline void afisare_alimente_recomandateMD(Meal , vector<Meal>& );
inline void afisare_alimente_recomandatePR(Meal , vector<Meal>& );
inline void afisare_alimente_recomandateCN(Meal , vector<Meal>& );
inline void setMeals(Meal*, Aliment* );
inline int calculNumarAlimente(int);
inline int calculNumarAlimente();
inline bool check_files();
inline int calculMicDejunNr();
inline int calculPranzNr();
inline int calculCinaNr();
inline void Date();
inline string IDate();

//Function definition
inline void clearStrings(string* string_1, string* string_2, string* string_3) {
	string_1->clear();
	string_2->clear();
	string_3->clear();
}

inline void clearStrings(string* string_1, string* string_2) {
	string_1->clear();
	string_2->clear();
}

//Check if the file is empty
inline bool check_empty_file(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

//Adaugare produs in lista
//inline void adaugareProdusLista(Aliment* aliment, vector<Aliment>& lista_produse) {
//	cout << "Cate produse doriti sa adaugati: ";
//	int size;
//	cin >> size;
//	aliment = new Aliment[lista_produse.size() + size];
//	aliment->createProduct(size);
//	aliment->setProductStats(aliment, file, size);
//	for (int i = lista_produse.size(); i < lista_produse.size() + size; i++) {
//		lista_produse.push_back(*(aliment + i));
//	}
//}



//Calcul numar alimente
inline int calculNumarAlimente(int aleg) {
	ifstream file;
	
	
	string line;
	char c = ' ';
	int count = 0;

	if (aleg == 1) {
		file.open("Mic Dejun.txt");
	}
	if (aleg == 2) {
		file.open("Pranz.txt");

	}if (aleg == 3) {
		file.open("Cina.txt");
	}
	
	while (!file.eof()) {
		line.push_back(c);
		file.get(c);
		if (c == '\n') {
			line.clear();
			c = ' ';
		}

		if (line == " Nume:") {
			count++;
			line.clear();
		}
	}
		file.close();
	
	return count;
}

//Calculez numarul de alimente din toate fisierele
inline int calculNumarAlimente() {
	ifstream file;
	string line;
	char c = ' ';
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			file.open("Mic dejun.txt");
			if (check_empty_file(file)) {
				count = count + 0;
				file.close();
			}
			else {
				while (!file.eof()) {
					line.push_back(c);
					file.get(c);
					if (c == '\n') {
						line.clear();
						c = ' ';
					}

					if (line == " Nume:") {
						count++;
						line.clear();
					}
				}
				file.close();
			}
			
		}
		if (i == 1) {
			file.open("Pranz.txt");
			if (check_empty_file(file)) {
				count = count + 0;
				file.close();
			}
			else {
				while (!file.eof()) {
					line.push_back(c);
					file.get(c);
					if (c == '\n') {
						line.clear();
						c = ' ';
					}

					if (line == " Nume:") {
						count++;
						line.clear();
					}
				}
				file.close();
			}
		}
		if (i == 2) {
			file.open("Cina.txt");
			if (check_empty_file(file)) {
				count = count + 0;
				file.close();
			}
			else {
				while (!file.eof()) {
					line.push_back(c);
					file.get(c);
					if (c == '\n') {
						line.clear();
						c = ' ';
					}
					if (line == " Nume:") {
						count++;
						line.clear();
					}
				}
				file.close();
			}
		}
	}
	return count;
}

//Calculez numarul de alimente din fisiere individual
inline int calculMicDejunNr() {
	ifstream file;
	string line;
	char c = ' ';
	int count = 0;
	file.open("Mic Dejun.txt");

	while (!file.eof()) {
		line.push_back(c);
		file.get(c);
		if (c == '\n') {
			line.clear();
			c = ' ';
		}

		if (line == " Nume:") {
			count++;
			line.clear();
		}
	}
	file.close();
	return count++;
}

inline int calculPranzNr() {
	ifstream file;
	string line;
	char c = ' ';
	int count = 0;
	file.open("Pranz.txt");

	while (!file.eof()) {
		line.push_back(c);
		file.get(c);
		if (c == '\n') {
			line.clear();
			c = ' ';
		}

		if (line == " Nume:") {
			count++;
			line.clear();
		}
	}
	file.close();
	return count++;
}

inline int calculCinaNr() {
	ifstream file;
	string line;
	char c = ' ';
	int count = 0;
	file.open("Cina.txt");

	while (!file.eof()) {
		line.push_back(c);
		file.get(c);
		if (c == '\n') {
			line.clear();
			c = ' ';
		}

		if (line == " Nume:") {
			count++;
			line.clear();
		}
	}
	file.close();
	return count++;
}

inline bool check_files() {
	ifstream file;
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			file.open("Mic dejun.txt");
			if (!check_empty_file(file)) {
				return true;
			}
			file.close();
		}
		if (i == 1) {
			file.open("Pranz.txt");
			if (!check_empty_file(file)) {
				return true;
			}
			file.close();
		}
		if (i == 2) {
			file.open("Cina.txt");
			if (!check_empty_file(file)) {
				return true;
			}
			file.close();
		}
	}
	return false;
}

//Pun data din calculator in fisier
inline void Date() {
	ofstream file;
	file.open("Data.txt");
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	string time = asctime(timeinfo);
	string day;
	for (int i = 0; i < 3; i++) {
		day.push_back(time.at(i));
	}
	file << day;
	file << '\n';
	file.close();

}

inline string IDate() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	string time = asctime(timeinfo);
	string day;
	for (int i = 0; i < 3; i++) {
		day.push_back(time.at(i));
	}
	return day;
}


//Functi pentru afisarea alimentelor recomandate per/meal

inline void afisare_alimente_recomandateMD(Meal meal, vector<Meal>& lista_meals) {
	vector<Meal> aux;
	int k = 0;
	int nr_cal = meal.getExpected().getConsum_cal();
	while (!lista_meals.empty())
	{
		int i = 0;
		if (lista_meals.size() == 1) {
			i = 0;
			if (lista_meals.at(i).getMic_dejun().calculCaloriProdus() > nr_cal) {
				break;
			}
		}
		else
		{
			srand((unsigned)time(0));
			i = (rand() % (lista_meals.size() - 1));

		}

		if (lista_meals.at(i).getMic_dejun().calculCaloriProdus() <= nr_cal) {
			int temp = lista_meals.at(i).getMic_dejun().calculCaloriProdus();
			nr_cal = nr_cal - temp;
			aux.push_back(lista_meals.at(i));
			lista_meals.erase(lista_meals.begin() + i);

			for (int j = 0; j < lista_meals.size(); j++) {
				if (lista_meals.at(j).getMic_dejun().calculCaloriProdus() > nr_cal) {
					lista_meals.erase(lista_meals.begin() + j);
					k++;
				}
				else {
					temp = lista_meals.at(j).getMic_dejun().calculCaloriProdus();
					nr_cal = nr_cal - temp;
					aux.push_back(lista_meals.at(j));
					lista_meals.erase(lista_meals.begin() + j);
				}
			}

		}
		else
		{
			lista_meals.erase(lista_meals.begin() + i);
		}

	}
	for (int i = 0; i < aux.size(); i++) {
		aux.at(i).getMic_dejun().displayProduct();
	}
}

inline void afisare_alimente_recomandatePR(Meal meal, vector<Meal>& lista_meals) {
	vector<Meal> aux;
	int k = 0;
	int nr_cal = meal.getExpected().getConsum_cal();
	while (!lista_meals.empty())
	{
		int i = 0;
		if (lista_meals.size() == 1) {
			i = 0;
			if (lista_meals.at(i).getPranz().calculCaloriProdus() > nr_cal) {
				break;
			}
		}
		else
		{
			srand((unsigned)time(0));
			i = (rand() % (lista_meals.size() - 1));

		}

		if (lista_meals.at(i).getPranz().calculCaloriProdus() <= nr_cal) {
			int temp = lista_meals.at(i).getPranz().calculCaloriProdus();
			nr_cal = nr_cal - temp;
			aux.push_back(lista_meals.at(i));
			lista_meals.erase(lista_meals.begin() + i);

			for (int j = 0; j < lista_meals.size(); j++) {
				if (lista_meals.at(j).getPranz().calculCaloriProdus() > nr_cal) {
					lista_meals.erase(lista_meals.begin() + j);
					k++;
				}
				else {
					temp = lista_meals.at(j).getPranz().calculCaloriProdus();
					nr_cal = nr_cal - temp;
					aux.push_back(lista_meals.at(j));
					lista_meals.erase(lista_meals.begin() + j);
				}
			}

		}
		else
		{
			lista_meals.erase(lista_meals.begin() + i);
		}

	}
	for (int i = 0; i < aux.size(); i++) {
		aux.at(i).getPranz().displayProduct();
	}
}

inline void afisare_alimente_recomandateCN(Meal meal, vector<Meal>& lista_meals) {
	vector<Meal> aux;
	int k = 0;
	int nr_cal = meal.getExpected().getConsum_cal();
	while (!lista_meals.empty())
	{
		int i = 0;
		if (lista_meals.size() == 1) {
			i = 0;
			if (lista_meals.at(i).getCina().calculCaloriProdus() > nr_cal) {
				break;
			}
		}
		else
		{
			srand((unsigned)time(0));
			i = (rand() % (lista_meals.size() - 1));

		}

		if (lista_meals.at(i).getCina().calculCaloriProdus() <= nr_cal) {
			int temp = lista_meals.at(i).getCina().calculCaloriProdus();
			nr_cal = nr_cal - temp;
			aux.push_back(lista_meals.at(i));
			lista_meals.erase(lista_meals.begin() + i);

			for (int j = 0; j < lista_meals.size(); j++) {
				if (lista_meals.at(j).getCina().calculCaloriProdus() > nr_cal) {
					lista_meals.erase(lista_meals.begin() + j);
					k++;
				}
				else {
					temp = lista_meals.at(j).getCina().calculCaloriProdus();
					nr_cal = nr_cal - temp;
					aux.push_back(lista_meals.at(j));
					lista_meals.erase(lista_meals.begin() + j);
				}
			}

		}
		else
		{
			lista_meals.erase(lista_meals.begin() + i);
		}

	}
	for (int i = 0; i < aux.size(); i++) {
		aux.at(i).getCina().displayProduct();
	}
}

//Seteaza meal-urile
void setMeals(Meal* meal, Aliment* aliment) {
	ifstream file;
	int k = 0;
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			file.open("Mic dejun.txt");
			if (check_empty_file(file)) {
				file.close();
				continue;
			}
			else {
				aliment = new Aliment[calculMicDejunNr()];
				aliment->setProductStats(aliment, file, calculMicDejunNr());
				while (k != calculMicDejunNr()) {
					(meal + k)->setMic_dejun(*(aliment + k));
					k++;
				}
				k = 0;
				file.close();
				delete[] aliment;
			}
		}
		if (i == 1) {
			file.open("Pranz.txt");
			if (check_empty_file(file)) {
				file.close();
				continue;
			}
			else {
				aliment = new Aliment[calculPranzNr()];
				aliment->setProductStats(aliment, file, calculPranzNr());
				while (k != calculPranzNr()) {
					(meal + k)->setPranz(*(aliment + k));
					k++;
				}
				k = 0;
				file.close();
				delete[] aliment;
			}

		}
		if (i == 2) {
			file.open("Cina.txt");
			if (check_empty_file(file)) {
				file.close();
				continue;
			}
			else {
				aliment = new Aliment[calculCinaNr()];
				aliment->setProductStats(aliment, file, calculCinaNr());
				while (k != calculCinaNr()) {
					(meal + k)->setCina(*(aliment + k));
					k++;
				}
				k = 0;
				file.close();
				delete[] aliment;
			}
		}
	}
}