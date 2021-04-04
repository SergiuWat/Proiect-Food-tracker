#include "Progres.h"
#include "Produs.h"
#include <vector>

#pragma once
using namespace std;
class Menu
{
private:
	Progres expected;
	Progres real;
	vector<Produs> alimente_consumate;
	vector<Produs> alimente_recomandate;
public:

	//Set function
	void setExpected(Progres);
	void setReal(Progres);
	void setAlimente_consumate(vector<Produs>);
	void setAlimente_recomandate(vector<Produs>);

	//Get function
	Progres getExpected();
	Progres getReal();
	vector<Produs> getAlimente_consumate();
	vector<Produs> getAlimente_recomandate();

};

