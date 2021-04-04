#include "Common.h"
#include <iostream>
#include <string>


#pragma once
using namespace std;
class User
{
private:
	string name;
	int varsta{};
	double inaltime{};
	double greutate{};
	int scop{};
	int metabolism{};
	int tip_activitate_fizica{};
	int greutate_dorita{};
	int sex{};
public:
	//Constructor
	//User(string, int, double, double, int, int, int, int, int);

	//Set function
	void setName(string);
	void setVarsta(int);
	void setInaltime(double);
	void setGreutate(double);
	void setScop(int);
	void setMetabolism(int);
	void setGreutateDorita(int);
	void setTip_activitate_fizica(int);
	void setSex(int);
	void setUsersStats(User*,ifstream&,int size);
	void setUsersStats(ifstream&);
	void createUser(ofstream&, int);

	//Get function
	string getName();
	int getVarsta();
	double getInaltime();
	double getGreutate();
	int getScop();
	int getMetabolism();
	int getGreutateDorita();
	int getTip_activitate_fizica();
	int getSex();

	//Display User
	void displayUsers();

	//Enum 
	
	enum Activitate {
		Sedentar=1 , Usoara, Moderata, Intensa
	};
	enum Scop {
		Scadere=1,Mentinere,Crestere
	};
	enum Metabolism {
		Rapid,Normal,Lent
	};

	//Edit user
	void editUser(ofstream& ,int);

	//Calculate BMI
	void CalculateBmi();
	//Calculate BMR
	int calculateBMR();
};

