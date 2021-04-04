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

	//Get function
	Aliment getAliment();
	double getCantitate();
	int getPortie();

};
