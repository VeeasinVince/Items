#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

class ShiftSupervisor : public Employee {

private:
	double anuSal;
	double proBonus;
	int production;


public:
	ShiftSupervisor();			//constructors
	ShiftSupervisor(std::string n, int i, std::string d, double a, double b, int p);
	ShiftSupervisor(std::string n, int i, std::string d);

	void setAnuSal(double a);		//setters
	void setProBonus(double b);
	void setProduction(int p);

	double getAnuSal();			//getters
	double getProBonus();
	int getProduction();

	void lunch();					//Shift Supervsior's lunch function


	~ShiftSupervisor();
};