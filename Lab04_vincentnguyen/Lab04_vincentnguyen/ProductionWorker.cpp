#include <iostream>
#include <string>
#include "ProductionWorker.h"

using namespace std; //delete later

ProductionWorker::ProductionWorker()
{

	cout <<"They have a " << whatShift(1) << " shift and work for $" << 0 << "/hour." << endl;
}

ProductionWorker::ProductionWorker(string n, int i, string d, int s, double h) : shift(s), hourRate(h) , Employee(n, i, d)
{


	cout << "They have a " << whatShift(shift) << " shift and work for $" << hourRate << "/hour." << endl;
}

ProductionWorker::ProductionWorker(string n, int i, string d) : shift(1), hourRate(50), Employee(n, i, d)
{
	cout << "They have a " << whatShift(shift) << " shift and work for $" << hourRate << "/hour." << endl;
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

void ProductionWorker::lunch()
{
	cout << "This Production Worker is having lunch right now." << endl;
}

ProductionWorker::~ProductionWorker()
{

}