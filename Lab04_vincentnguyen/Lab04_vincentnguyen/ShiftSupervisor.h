#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;	//delete later

class ShiftSupervisor : public Employee {

private:
	double anuSal;
	double proBonus;


public:
	ShiftSupervisor();

	void setAnuSal(double a);
	void setProBonus(double b);

	double getAnuSal();
	double getProBonus();

	~ShiftSupervisor();
};