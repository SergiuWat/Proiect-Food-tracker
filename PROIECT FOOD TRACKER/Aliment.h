#include <vector>
#include <string>
#pragma once
using namespace std;
class Aliment
{
private:
	string nume;
	double valoare_energetica;
	double grasimi;
	double acizi_grasi_saturati;
	double glucide;
	double zaharuri;
	double fibre;
	double proteine;
	double sare;
	double cantitate;

	
public:

	//Copy contructor
	Aliment(const Aliment&);
	

	//Construcot
	Aliment();

	

	//Set function
	void setNume(string);
	void setValoare_energetica(double);
	void setGrasimi(double);
	void setAcizi_grasi_saturati(double);
	void setGlucide(double);
	void setZaharuri(double);
	void setFibre(double);
	void setProteine(double);
	void setSare(double);
	void setCantitate(double);

	//Get function
	string getNume();
	double getValoare_energetica();
	double getGrasimi();
	double getAcizi_grasi_saturati();
	double getGlucide();
	double getZaharuri();
	double getFibre();
	double getProteinte();
	double getSare();
	double getCantitate();

	//Calcul calori
	int calculCaloriProdus(double);
	int calculCaloriProdus();

	//Create product
	void createProduct(int);

	//Set product stats
	void setProductStats(Aliment* , ifstream& , int );
	void setProductStats(Aliment*);

	//Dispaly product
	void displayProduct();

	//Cautare produs
	bool cautareProdus(vector<Aliment>,string);

};

