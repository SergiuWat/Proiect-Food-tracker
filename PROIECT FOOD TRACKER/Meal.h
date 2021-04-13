#include "Progres.h"
#include "Aliment.h"
#include <fstream>
#include <string>
#include <vector>
#pragma once
using namespace std;
class Meal
{
private:
	Aliment mic_dejun;
	Aliment pranz;
	Aliment cina;
	Aliment gustari;
	Progres expected;
	Progres real;
	string data;


public:
	
	//Set functionS
	/*void setMic_dejun(Aliment);
	void setPranz(Aliment);
	void setCina(Aliment);
	void setGustari(Aliment);*/

	void setMic_dejun(Aliment);
	void setPranz(Aliment);
	void setCina(Aliment);
	void setGustari(Aliment);

	void setData(string);
	void setExpected(Progres);
	void setReal(Progres);
	void setExpected(int);
	void setReal(int);

	//Get function
	Aliment getMic_dejun();
	Aliment getPranz();
	Aliment getCina();
	Aliment getGustari();
	string getData();
	Progres getExpected();
	Progres getReal();
	//vector<Aliment>getMeals() { return m; }

	bool checkData();

	void setMealsStats(Meal*,Aliment*,int);
	void setMealsStats(Meal* meals, Aliment* aliment);

};

