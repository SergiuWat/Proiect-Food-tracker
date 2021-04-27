#include "Functions.h"
#include "Aliment.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Aliment::Aliment(){}
//Set function
void Aliment::setNume(string nume) {
	this->nume = nume;

}
void Aliment::setValoare_energetica(double val_energ) {
	valoare_energetica = val_energ;
}
void Aliment::setGrasimi(double grasimi) {
	this->grasimi = grasimi;
}
void Aliment::setAcizi_grasi_saturati(double acizi_grasi) {
	acizi_grasi_saturati = acizi_grasi;
}
void Aliment::setGlucide(double glucide) {
	this->glucide = glucide;
}
void Aliment::setZaharuri(double zaharuri) {
	this->zaharuri = zaharuri;
}
void Aliment::setFibre(double fibre) {
	this->fibre = fibre;
}
void Aliment::setProteine(double proteine) {
	this->proteine = proteine;
}
void Aliment::setSare(double sare) {
	this->sare = sare;
}
void Aliment::setCantitate(double cantitate) {
	this->cantitate = cantitate;
}



//Get function
string Aliment::getNume() { return nume; }
double Aliment::getValoare_energetica() { return valoare_energetica; }
double Aliment::getGrasimi() { return grasimi; }
double Aliment::getAcizi_grasi_saturati() { return acizi_grasi_saturati; }
double Aliment::getGlucide() { return glucide; }
double Aliment::getZaharuri() { return zaharuri; }
double Aliment::getFibre() { return fibre; }
double Aliment::getProteinte() { return proteine; }
double Aliment::getSare() { return sare; }
double Aliment::getCantitate() { return cantitate; }



//Copy constructor
Aliment::Aliment(const Aliment& source) {
	this->nume = source.nume;
	this->valoare_energetica = source.valoare_energetica;
	this->grasimi = source.grasimi;
	this->acizi_grasi_saturati = source.acizi_grasi_saturati;
	this->glucide = source.glucide;
	this->zaharuri = source.zaharuri;
	this->fibre = source.fibre;
	this->proteine = source.proteine;
	this->sare = source.sare;
	this->cantitate = source.cantitate;

}

//Create product
void Aliment::createProduct(int size) {
	ofstream file;
	string line;
	string input;
	cout << "In ce categorie se afla produsul" << endl;
	cout << "1.Mic dejun\n2.Pranz\n3.Cina\n4.Gustari" << endl;
	cin >> input;
	system("cls");

	//Alegerea mesei
	if (stoi(input)== 1) {
		file.open("Mic dejun.txt",fstream::app);
		
	}
	else if (stoi(input) == 2) {
		file.open("Pranz.txt", fstream::app);
		
	}
	else if (stoi(input) == 3) {
		file.open("Cina.txt",fstream::app);
		
	}
	else if (stoi(input) == 4) {
		file.open("Gustari.txt",fstream::app);
	}

	//Se seteaza valorile
	if (!file) {
		cout << "Error" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {

			//Nume
			cout << "Nume produs: ";
			cin.ignore();
			getline(cin, input);
			line = "Nume: " + input;
			file << line;
			clearStrings(&input, &line);

			//Valoare energetica
			cout << "Valoare energetica: ";
			cin >> input;
			line = "Calori: " + input + "kcal";
			file << endl << line;
			clearStrings(&input, &line);

			//Grasimi
			cout << "Grasimi: ";
			cin >> input;
			line = "Grasimi: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Acizi grasi saturati
			cout << "Din care acizi grasi saturati: ";
			cin >> input;
			line = "Acizi grasi saturati: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Glucide
			cout << "Glucide: ";
			cin >> input;
			line = "Glucide: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Zaharuri
			cout << "Zaharuri: ";
			cin >> input;
			line = "Zaharuri: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Fibre
			cout << "Fibre: ";
			cin >> input;
			line = "Fibre: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Proteine
			cout << "Proteine: ";
			cin >> input;
			line = "Proteine: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Sare
			cout << "Sare: ";
			cin >> input;
			line = "Sare: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);

			//Cantitate
			cout << "Cantitate: ";
			cin >> input;
			line = "Cantitate: " + input + "g";
			file << endl << line;
			clearStrings(&input, &line);
			file << endl << "*********************************************" << endl;
			system("cls");
		}
	}

	file.close();
	system("cls");
}



//Calcul calori produs
int Aliment::calculCaloriProdus(double cantitate) {
	int calori;
	double calcul_proteine;
	double calcul_grasimi;
	double calcult_glucide;
	
	calcul_proteine = proteine * (cantitate / 100);
	calcul_grasimi = grasimi * (cantitate / 100);
	calcult_glucide = glucide * (cantitate / 100);
	

	calcul_proteine = calcul_proteine * 4;
	calcul_grasimi = calcul_grasimi * 9;
	calcult_glucide = calcult_glucide * 4;
	calori = calcul_proteine + calcul_grasimi + calcult_glucide;


	return calori;
}

int Aliment::calculCaloriProdus() {
	int calori;
	double calcul_proteine;
	double calcul_grasimi;
	double calcult_glucide;
	
	calcul_proteine = proteine * (cantitate / 100);
	calcul_grasimi = grasimi * (cantitate / 100);
	calcult_glucide = glucide * (cantitate / 100);
	
	calcul_proteine = calcul_proteine * 4;
	calcul_grasimi = calcul_grasimi * 9;
	calcult_glucide = calcult_glucide * 4;
	calori = calcul_proteine + calcul_grasimi + calcult_glucide;
	return calori;
}

//Set product stats
void Aliment::setProductStats(Aliment* aliemnt, ifstream& in_file, int size){
	string line;
	char c;
	int i = 0;

	if (!in_file) {
		cout << "Error" << endl;
	}
	else {
		while (i != size) {
			in_file.get(c);
			line.push_back(c);
			//Set Name
			if (line == "Nume: ")  {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(aliemnt + i)->setNume(line);
				line.clear();
			}
			//SET Valoare Energetica
			if (line == "Calori: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					line.push_back(c);
				}
				(aliemnt + i)->setValoare_energetica(stoi(line));
				line.clear();
			}
			//SET Grasimi
			if (line == "Grasimi: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setGrasimi(stoi(line));
				line.clear();
			}
			//Set Din care acizi grasi saturat
			if (line == "Acizi grasi saturati: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setAcizi_grasi_saturati(stoi(line));
				line.clear();
			}
			//Set Glucide
			if (line == "Glucide: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setGlucide(stoi(line));
				line.clear();
			}
			//Set Zaharuri
			if (line == "Zaharuri: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setZaharuri(stoi(line));
				line.clear();
			}
			//Set Fibre
			if (line == "Fibre: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setFibre(stoi(line));
				line.clear();
			}
			//Set Proteine
			if (line == "Proteine: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setProteine(stoi(line));
				line.clear();
			}
			//Set Sare
			if (line == "Sare: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setSare(stoi(line));
				line.clear();
			}
			//Set Cantitate
			if (line == "Cantitate: ") {
				line.clear();
				while (c != '\n') {
					in_file.get(c);
					if (c == '\n') {
						break;
					}
					if (c != 'g') {
						line.push_back(c);
					}
				}
				(aliemnt + i)->setCantitate(stoi(line));
				line.clear();
				getline(in_file, line);
				line.clear();
				i++;
			}
		}
	}
	in_file.close();
}

//Setez alimentele din toate fisierele
void Aliment::setProductStats(Aliment* aliemnt) {
	ifstream in_file;
	string line;
	char c;
	int i = 0;
	int k = 0;

	for (int j = 0; j < 3; j++) {
		if (j == 0) {
			in_file.open("Mic dejun.txt");
			if (check_empty_file(in_file)) {
				continue;
			}
			while (k != calculMicDejunNr()) {
				in_file.get(c);
				line.push_back(c);
				//Set Name
				if (line == "Nume: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setNume(line);
					line.clear();
				}
				//SET Valoare Energetica
				if (line == "Calori: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setValoare_energetica(stoi(line));
					line.clear();
				}
				//SET Grasimi
				if (line == "Grasimi: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGrasimi(stoi(line));
					line.clear();
				}
				//Set Din care acizi grasi saturat
				if (line == "Acizi grasi saturati: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setAcizi_grasi_saturati(stoi(line));
					line.clear();
				}
				//Set Glucide
				if (line == "Glucide: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGlucide(stoi(line));
					line.clear();
				}
				//Set Zaharuri
				if (line == "Zaharuri: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setZaharuri(stoi(line));
					line.clear();
				}
				//Set Fibre
				if (line == "Fibre: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setFibre(stoi(line));
					line.clear();
				}
				//Set Proteine
				if (line == "Proteine: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setProteine(stoi(line));
					line.clear();
				}
				//Set Sare
				if (line == "Sare: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setSare(stoi(line));
					line.clear();
				}
				//Set Cantitate
				if (line == "Cantitate: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setCantitate(stoi(line));
					line.clear();
					getline(in_file, line);
					line.clear();
					k++;
					i++;
				}
			}
			in_file.close();
		}//end of first if
		if (j == 1) {
			in_file.open("Pranz.txt");
			if (check_empty_file(in_file)) {
				continue;
			}
			while (k != calculPranzNr()) {
				in_file.get(c);
				line.push_back(c);
				//Set Name
				if (line == "Nume: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setNume(line);
					line.clear();
				}
				//SET Valoare Energetica
				if (line == "Calori: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setValoare_energetica(stoi(line));
					line.clear();
				}
				//SET Grasimi
				if (line == "Grasimi: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGrasimi(stoi(line));
					line.clear();
				}
				//Set Din care acizi grasi saturat
				if (line == "Acizi grasi saturati: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setAcizi_grasi_saturati(stoi(line));
					line.clear();
				}
				//Set Glucide
				if (line == "Glucide: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGlucide(stoi(line));
					line.clear();
				}
				//Set Zaharuri
				if (line == "Zaharuri: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setZaharuri(stoi(line));
					line.clear();
				}
				//Set Fibre
				if (line == "Fibre: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setFibre(stoi(line));
					line.clear();
				}
				//Set Proteine
				if (line == "Proteine: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setProteine(stoi(line));
					line.clear();
				}
				//Set Sare
				if (line == "Sare: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setSare(stoi(line));
					line.clear();
				}
				//Set Cantitate
				if (line == "Cantitate: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setCantitate(stoi(line));
					line.clear();
					getline(in_file, line);
					line.clear();
					k++;
					i++;
				}
			}
			in_file.close();
		}//end of second if
		if (j == 2) {
			in_file.open("Cina.txt");
			if (check_empty_file(in_file)) {
				continue;
			}
			while (k != calculCinaNr()) {
				in_file.get(c);
				line.push_back(c);
				//Set Name
				if (line == "Nume: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setNume(line);
					line.clear();
				}
				//SET Valoare Energetica
				if (line == "Calori: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						line.push_back(c);
					}
					(aliemnt + i)->setValoare_energetica(stoi(line));
					line.clear();
				}
				//SET Grasimi
				if (line == "Grasimi: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGrasimi(stoi(line));
					line.clear();
				}
				//Set Din care acizi grasi saturat
				if (line == "Acizi grasi saturati: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setAcizi_grasi_saturati(stoi(line));
					line.clear();
				}
				//Set Glucide
				if (line == "Glucide: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setGlucide(stoi(line));
					line.clear();
				}
				//Set Zaharuri
				if (line == "Zaharuri: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setZaharuri(stoi(line));
					line.clear();
				}
				//Set Fibre
				if (line == "Fibre: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setFibre(stoi(line));
					line.clear();
				}
				//Set Proteine
				if (line == "Proteine: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setProteine(stoi(line));
					line.clear();
				}
				//Set Sare
				if (line == "Sare: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setSare(stoi(line));
					line.clear();
				}
				//Set Cantitate
				if (line == "Cantitate: ") {
					line.clear();
					while (c != '\n') {
						in_file.get(c);
						if (c == '\n') {
							break;
						}
						if (c != 'g') {
							line.push_back(c);
						}
					}
					(aliemnt + i)->setCantitate(stoi(line));
					line.clear();
					getline(in_file, line);
					line.clear();
					k++;
					i++;
				}
			}
			in_file.close();
		}//end of the third if
	}
	
}

//Diplay product
void Aliment::displayProduct() {
	cout << "Name: " << nume << endl;
	cout << "Calori:: " << valoare_energetica<< endl;
	cout << "Grasimi: " << grasimi << endl;
	cout << "Acizi grasi saturati: " << acizi_grasi_saturati << endl;
	cout << "Glucide: " << glucide << endl;
	cout << "Zaharuri: " << zaharuri << endl;
	cout << "Fibre: " << fibre << endl;
	cout << "Proteine: " << proteine << endl;
	cout << "Sare:: " << sare << endl;
	cout << "Cantitate: " << cantitate << endl;
	
	cout << "********************************************************" << endl;
}

//Cautare produs

bool Aliment::cautareProdus(vector<Aliment> lista,string name) {
	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getNume() == name) {
			return true;
		}
	}
	return false;
}
