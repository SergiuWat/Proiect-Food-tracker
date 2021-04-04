#include "Menu.h"
#include "Progres.h"
#include <vector>
#include<iostream>
using namespace std;

//Set function
void Menu::setExpected(Progres expected) {
	this->expected = expected;
}
void Menu::setReal(Progres real) {
	this->real = real;
}
void Menu::setAlimente_consumate(vector<Produs> alimente_consumate) {
	this->alimente_consumate = alimente_consumate;
}
void Menu::setAlimente_recomandate(vector<Produs>alimente_recomandate) {
	this->alimente_recomandate = alimente_recomandate;
}

//Get function
Progres Menu::getExpected() { return expected; }
Progres Menu::getReal() { return real; }
vector<Produs> Menu::getAlimente_consumate() { return alimente_consumate; }
vector<Produs> Menu::getAlimente_recomandate() { return alimente_recomandate; }