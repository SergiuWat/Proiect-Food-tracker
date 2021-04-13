#include "Meal.h"
#include "Progres.h"
#include "Aliment.h"
#include <fstream>
#include "Functions.h"
#include <string>

//Set function
void Meal::setMic_dejun(Aliment mic_dejun) {
	this->mic_dejun = mic_dejun;
}
void  Meal::setPranz(Aliment pranz) {
	this->pranz = pranz;
}
void  Meal::setCina(Aliment cina) {
	this->cina = cina;
}
void  Meal::setGustari(Aliment gustari) {
	this->gustari = gustari;
}
void  Meal::setExpected(Progres expected) {
	this->expected = expected;
}
void  Meal::setReal(Progres real) {
	this->real = real;
}
void Meal::setExpected(int exp) {
	expected.setConsum_Cal(exp);
}
void Meal::setReal(int rl) {
	real.setConsum_Cal(rl);
}
void Meal::setData(string data) {
	this->data = data;
}

//Get function
Aliment Meal::getMic_dejun() { return mic_dejun; }
Aliment Meal::getPranz() { return pranz; }
Aliment Meal::getCina() { return cina; }
Aliment Meal::getGustari() { return gustari; }
string Meal::getData() { return data; }
Progres Meal::getExpected() { return expected; }
Progres Meal::getReal() { return real; }

//Check Data
bool Meal::checkData() {
	ifstream file;
	file.open("Data.txt");
	string line;
	char c;
	int i = 0;
	while (!file.eof()) {
		file.get(c);		
		line.push_back(c);
		if (i == 2) {
			break;
		}
		i++;
	}
	file.close();
	if (line != data) {
		return true;
	}
	else {
		return false;
	}
}

void Meal::setMealsStats(Meal* meals,Aliment* aliment ,int meal) {
	ifstream in_file;
	string line;
	char c;
	int i = 0;

	//Se seteaza valorile dupa alegerea mesei
	if (meal == 1) {
		in_file.open("Mic dejun.txt");
		for (int i = 0; i < calculNumarAlimente(meal); i++) {
			Aliment al = *(aliment + i);
			(meals + i)->setMic_dejun(al);
		}
	}
	else if (meal == 2) {
		in_file.open("Pranz.txt");
		for (int i = 0; i < calculNumarAlimente(meal); i++) {
			(meals + i)->setPranz(*(aliment + i));
		}
	}
	else if (meal == 3) {
		in_file.open("Cina.txt");
		for (int i = 0; i < calculNumarAlimente(meal); i++) {
			(meals + i)->setCina(*(aliment + i));
		}
	}

	in_file.close();
}

void Meal::setMealsStats(Meal* meals, Aliment* aliment) {
	ifstream in_file;
	string line;
	char c=' ';
	int i = 0;
	in_file.open("Mic dejun.txt");
	//Se seteaza valorile dupa alegerea mesei

	if (check_empty_file(in_file)) {
		goto Pranz;
	}
	else {
		while (!in_file.eof()) {
			line.push_back(c);
			in_file.get(c);
			if (c == '\n') {
				line.clear();
				c = ' ';
			}

			if (line == " Nume:") {
				(meals + i)->setMic_dejun(*(aliment + i));
				i++;
				line.clear();
			}
			
		}
	}
	
	in_file.close();
	in_file.open("Pranz.txt");
Pranz:
	if (check_empty_file(in_file)) {
		goto Cina;
	}
	else {
		while (!in_file.eof()) {
			(meals + i)->setPranz(*(aliment + i));
			i++;
		}
	}
	
	in_file.close();
	in_file.open("Cina.txt");
	Cina:
	while (!in_file.eof()) {
		(meals + i)->setCina(*(aliment + i));
		i++;
	}
	in_file.close();
	
}
