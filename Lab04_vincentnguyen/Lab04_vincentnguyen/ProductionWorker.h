#pragma once
//Vincent Nguyen Lab04
#include <iostream>
#include <string>
#include "Employee.h"

class ProductionWorker : public Employee {

private:
	int shift;				//1 = day, 2 = night
	double hourRate;

public:
	ProductionWorker();		//Constructors, some are overloaded
	ProductionWorker(std::string n, int i, std::string d, int s, double h);
	ProductionWorker(std::string n, int i, std::string d);

	void setShift(int s);		//setters
	void setHourRate(double r);

	int getShift();		//getters
	double getHourRate();

	std::string whatShift(int s);	//whatShift determines whether 'day' or 'night' will be printed
	void lunch();		//Product Worker's lunch function

	~ProductionWorker();
};