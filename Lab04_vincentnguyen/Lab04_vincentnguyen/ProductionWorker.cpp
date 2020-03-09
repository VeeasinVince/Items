#include <iostream>
#include <string>
#include "ProductionWorker.h"

using namespace std; //delete later

ProductionWorker::ProductionWorker() :Employee()
{
	shift = 1;
	hourRate = 0.0;

	cout << "Employee number:" << getNumber() << ", " << getName() << " was hired " << getHireDate() << ". They have a " << whatShift(1) << " shift and work for $" << hourRate << "/hour." << endl;
}

ProductionWorker::ProductionWorker(string n, int i, string d, int s, double h) :Employee(n, i, d)
{
	shift =s;
	hourRate = h;

	cout << "Employee number:" << i << ", " << n << " was hired " << d << ". They have a " << whatShift(s) << " shift and work for $" << hourRate << "/hour." << endl;
}

void ProductionWorker::setShift(int s)
{
	shift = s;
}

void ProductionWorker::setHourRate(double r)
{
	hourRate = r;
}

int ProductionWorker::getShift()
{
	return shift;
}

double ProductionWorker::getHourRate()
{
	return hourRate;
}

string ProductionWorker::whatShift(int s)
{
	if (s == 1)
	{
		return "day";
	}
	else
	{
		return "night";
	}
}

ProductionWorker::~ProductionWorker()
{

}