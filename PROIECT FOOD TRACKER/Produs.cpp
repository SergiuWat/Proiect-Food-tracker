#include "Produs.h"
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
//Get function
Aliment Produs::getAliment() { return aliment; }
double Produs::getCantitate() { return cantitate; }
int    Produs::getPortie() { return portie; }
