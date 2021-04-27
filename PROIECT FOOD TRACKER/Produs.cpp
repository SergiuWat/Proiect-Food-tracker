#include "Produs.h"
#include <fstream>
#include <string>
#include "Meal.h"
using namespace std;

//Set function
void Produs::setAliment(Aliment aliment) {
	this->aliment = aliment;
}
void Produs::setCantitate(double cantitate) {
	this->cantitate = cantitate;
}
void Produs::setPortie(int portie) {
	this->portie = portie;
}
void Produs::setNumeAliment(string nume) {
	aliment.setNume(nume);
}


//Get function
Aliment Produs::getAliment() { return aliment; }
double Produs::getCantitate() { return cantitate; }
int    Produs::getPortie() { return portie; }

//Set produse
void Produs::setProduse(ifstream& file,Produs* produs, int size) {
	string line;
	char c = ' ';
	int i = 0;
	while (i != size) {
		file.get(c);
		line.push_back(c);
		//Set NUME
		if (line == "Nume: ") {
			line.clear();
			while (c != '\n') {
				file.get(c);
				if (c == '\n') {
					break;
				}
				line.push_back(c);
			}
			(produs + i)->setNumeAliment(line);
			line.clear();
		}
		if (line == "Cantitate: ") {
			line.clear();
			while (c != '\n') {
				file.get(c);
				if (c == '\n') {
					break;
				}
				line.push_back(c);
			}
			(produs + i)->setCantitate(stoi(line));
			line.clear();
		}
		if (line == "Portie: ") {
			line.clear();
			while (c != '\n') {
				file.get(c);
				if (c == '\n') {
					break;
				}
				line.push_back(c);
			}
			(produs + i)->setPortie(stoi(line));
			line.clear();
			getline(file, line);
			line.clear();
			i++;
		}
	}
	file.close();
}

//adaug produsul in fisier
void Produs::adaugaProdusFiser(ofstream& file) {
	

	file <<"Nume: "<< aliment.getNume() << endl;
	file << "Cantitate: " << cantitate << endl;
	file << "Portie: " << portie << endl;	
	file << "**************" << endl;
	file.close();
}

//ostream& operator<<(ostream o, Produs& p) {
//	o <<"Nume aliment: "<< p.getAliment().getNume();
//	o << "Numar calorii: " << p.getAliment().calculCaloriProdus(p.getCantitate());
//	o <<"Cantitate:"<< p.getCantitate();
//	o << "Porti" << p.getPortie();
//	return o;
// }