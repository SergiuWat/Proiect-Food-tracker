#include "Meal.h"
#include "Progres.h"
#include "Aliment.h"

//Set function
//void Meal::setMic_dejun(Aliment mic_dejun) {
//	this->mic_dejun = mic_dejun;
//}
//void  Meal::setPranz(Aliment pranz) {
//	this->pranz = pranz;
//}
//void  Meal::setCina(Aliment cina) {
//	this->cina = cina;
//}
//void  Meal::setGustari(Aliment gustari) {
//	this->gustari = gustari;
//}

void  Meal::setExpected(Progres expected) {
	this->expected = expected;
}
void  Meal::setReal(Progres real) {
	this->real = real;
}
void Meal::setData(string data) {
	this->data = data;
}

void Meal::setMic_dejun(Aliment* aliment) {
	mic_dejun = aliment;
}
void Meal::setPranz(Aliment* aliment) {
	pranz = aliment;
}
void Meal::setCina(Aliment* aliment) {
	cina = aliment;
}
void Meal::setGustari(Aliment* aliment) {
	gustari = aliment;
}

//Get function
Aliment* Meal::getMic_dejun() { return mic_dejun; }
Aliment* Meal::getPranz() { return pranz; }
Aliment* Meal::getCina() { return cina; }
Aliment* Meal::getGustari() { return gustari; }
string Meal::getData() { return data; }
Progres Meal::getExpected() { return expected; }
Progres Meal::getReal() { return real; }

//Check Data
bool Meal::checkData(ifstream& file) {
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
