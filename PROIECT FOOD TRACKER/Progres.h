#include"USER.h"
#include "Aliment.h"
#pragma once
class Progres
{
private:
	int consum_cal;
	double proteine;
	double carbohidrati;
	double grasimi;
public:

	//Set function
	void setConsum_cal_real(Aliment*, int,int);
	void setConsum_cal_expected(User users);
	void setConsum_Cal(int);
	void setProteine(double);
	void setCarbohidrati(double);
	void setGrasimi(double);

	//Get function
	int getConsum_cal();
	double getProteine();
	double getCarbohidrati();
	double getGrasimi();

	friend Progres operator%(Progres, int);
};

