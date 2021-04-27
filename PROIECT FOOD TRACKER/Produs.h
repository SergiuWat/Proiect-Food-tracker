
#include <iostream>
#include "Meal.h"
#include "Aliment.h"
#pragma once
class Produs
{
private:
	Aliment aliment;
	double cantitate;
	int portie;
public:

	//Set function
	void setAliment(Aliment);
	void setCantitate(double);
	void setPortie(int);
	void setProduse(ifstream& ,Produs*, int);
	void setNumeAliment(string);
	

	//Get function
	Aliment getAliment();
	double getCantitate();
	int getPortie();

	void adaugaProdusFiser(ofstream&);

	

	//friend ostream& operator<<(ostream o, Produs& p);

};
