#include "Progres.h"
#include "Aliment.h"
#include <fstream>
#include <string>
#pragma once
using namespace std;
class Meal
{
private:
	Aliment* mic_dejun;
	Aliment* pranz;
	Aliment* cina;
	Aliment* gustari;
	Progres expected;
	Progres real;
	string data;
public:
	
	//Set functionS
	/*void setMic_dejun(Aliment);
	void setPranz(Aliment);
	void setCina(Aliment);
	void setGustari(Aliment);*/

	void setMic_dejun(Aliment*);
	void setPranz(Aliment*);
	void setCina(Aliment*);
	void setGustari(Aliment*);

	void setData(string);
	void setExpected(Progres);
	void setReal(Progres);

	//Get function
	Aliment* getMic_dejun();
	Aliment* getPranz();
	Aliment* getCina();
	Aliment* getGustari();
	string getData();
	Progres getExpected();
	Progres getReal();

	bool checkData(ifstream&);

};

