#include <iostream>
#include<vector>
#include "USER.h"
#include "Aliment.h"
#include "Progres.h"
#include "Meal.h"

using namespace std;

//Set function
void Progres::setConsum_cal_real(Aliment* aliment,int cantitate,int size) {

	for (int i = 0; i < size; i++) {
		consum_cal = consum_cal - (aliment+i)->calculCaloriProdus(cantitate);
	}
	
}
void Progres::setConsum_cal_expected(User user) {
	consum_cal = user.calculateBMR();
}
void Progres::setConsum_Cal(int cal) {
	consum_cal = cal;
}
void Progres::setProteine(double proteine) {
	this->proteine = proteine;
}
void Progres::setCarbohidrati(double carbohidrati) {
	this->carbohidrati = carbohidrati;
}
void Progres::setGrasimi(double grasimi) {
	this->grasimi = grasimi;
}

//Get function
int     Progres::getConsum_cal() { return consum_cal; }
double  Progres::getProteine() { return proteine; }
double  Progres::getCarbohidrati() { return carbohidrati; }
double  Progres::getGrasimi() { return grasimi; }

 Progres operator%(Progres p, int a) {

	 p.setConsum_Cal(p.getConsum_cal() * a/100);
	 return p;
 }