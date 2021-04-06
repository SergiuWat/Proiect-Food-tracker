#include <iostream>
#include <string>
#include <fstream>
#include "Aliment.h"
#include "USER.h"

#pragma once
using namespace std;

//Function Prototype
inline void clearStrings(string*, string*, string*);
inline void clearStrings(string*, string*);
inline bool check_empty_file(ifstream&);
inline void adaugareProdusLista(Aliment*, vector<Aliment>&, ifstream& , ofstream& );
inline void printMenu();
//inline int calculNumarAlimente(ifstream& );
inline int calculNumarAlimente(int);
inline int calculNumarAlimente();
inline bool check_files();
inline int calculMicDejunNr();
inline int calculPranzNr();
inline int calculCinaNr();

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
inline void adaugareProdusLista(Aliment* aliment, vector<Aliment>& lista_produse, ifstream& file, ofstream& file2) {
	cout << "Cate produse doriti sa adaugati: ";
	int size;
	cin >> size;
	aliment = new Aliment[lista_produse.size() + size];
	aliment->createProduct(size);
	aliment->setProductStats(aliment, file, size);
	for (int i = lista_produse.size(); i < lista_produse.size() + size; i++) {
		lista_produse.push_back(*(aliment + i));
	}
}

//Print menu
inline void printMenu() {
	cout << "************************MENU***************************" << endl;
	cout << "1.Adaugati un produs/produse" << endl;
	cout << "2.Adaugati un nou user" << endl;
	cout << "3.Calculati BMR-ul" << endl;
	cout << "4.Calculati BMI-ul" << endl;
	cout << "5.Verificati progresul dumneavoastra" << endl;
	cout << "6.Cautati un produs" << endl;
	cout << "7.Display user stats" << endl;
	cout << "9.Inchideti aplicatia" << endl;

}
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

//Calculez numarul de alimente din fisier individual
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