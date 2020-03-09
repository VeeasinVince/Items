#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;	//delete later

class ShiftSupervisor : public Employee {

private:
	double anuSal;
	double proBonus;
	int production;


public:
	ShiftSupervisor();
	ShiftSupervisor(string n, int i, string d, double a, double b, int p);

	void setAnuSal(double a);
	void setProBonus(double b);
	void setProduction(int p);

	double getAnuSal();
	double getProBonus();
	int getProduction();


	~ShiftSupervisor();
};