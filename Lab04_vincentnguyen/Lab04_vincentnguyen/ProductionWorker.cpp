//Vincent Nguyen Lab04
#include <iostream>
#include <string>
#include "ProductionWorker.h"

ProductionWorker::ProductionWorker() :shift(0), hourRate(0)
{
	
	std::cout <<"They have a " << whatShift(1) << " shift and work for $" << 0 << "/hour." << std::endl;
}

ProductionWorker::ProductionWorker(std::string n, int i, std::string d, int s, double h) : shift(s), hourRate(h) , Employee(n, i, d)		//Initialization list syntax
{


	std::cout << "They have a " << whatShift(shift) << " shift and work for $" << hourRate << "/hour." << std::endl;
}

ProductionWorker::ProductionWorker(std::string n, int i, std::string d) : shift(1), hourRate(50), Employee(n, i, d)		//Initialization list syntax
{
	std::cout << "They have a " << whatShift(shift) << " shift and work for $" << hourRate << "/hour." << std::endl;
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

std::string ProductionWorker::whatShift(int s)
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
//Lunch function
void ProductionWorker::lunch()
{
	std::cout << "This Production Worker is having lunch right now." << std::endl;
}

ProductionWorker::~ProductionWorker()
{

}