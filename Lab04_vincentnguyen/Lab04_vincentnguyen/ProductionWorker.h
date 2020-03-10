#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;	//delete later

class ProductionWorker : public Employee {

private:
	int shift;				//1 = day, 2 = night
	double hourRate;

public:
	ProductionWorker();
	ProductionWorker(string n, int i, string d, int s, double h);

	void setShift(int s);
	void setHourRate(double r);

	int getShift();
	double getHourRate();

	virtual string whatShift(int s);

	~ProductionWorker();
};

