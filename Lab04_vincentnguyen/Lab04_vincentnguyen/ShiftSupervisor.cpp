#include <iostream>
#include <string>
#include "ShiftSupervisor.h"

using namespace std;	//delete later

ShiftSupervisor::ShiftSupervisor()
{

}

void ShiftSupervisor::setAnuSal(double a)
{
	anuSal = a;
}

void ShiftSupervisor::setProBonus(double b)
{
	proBonus = b;
}

double ShiftSupervisor::getAnuSal()
{
	return anuSal;
}

double ShiftSupervisor::getProBonus()
{
	return proBonus;
}

ShiftSupervisor::~ShiftSupervisor()
{

}
