#include <iostream>
#include <string>
#include "ShiftSupervisor.h"

using namespace std;	//delete later

ShiftSupervisor::ShiftSupervisor() :Employee()
{
	anuSal = 50.0;
	proBonus = 0;

	cout << "Employee number:" << getNumber() << ", " << getName() << " was hired " << getHireDate() << "." << endl;
}

ShiftSupervisor::ShiftSupervisor(string n, int i, string d, double a, double b, int p) :Employee(n, i, d)
{
	cout << "Employee number:" << i << ", " << n << " was hired " << d << "." << "They make $" << a << " a year." << endl;

	cout << "Their production goal every year is 1500 units of chocolates and they have a annual production of " << p << "." << ejndl;


}

void ShiftSupervisor::setAnuSal(double a)
{
	anuSal = a;
}

void ShiftSupervisor::setProBonus(double b)
{
	proBonus = b;
}

void ShiftSupervisor::setProduction(int p)
{
	production = p;
}

double ShiftSupervisor::getAnuSal()
{
	return anuSal;
}

double ShiftSupervisor::getProBonus()
{
	return proBonus;
}

int ShiftSupervisor::getProduction()
{
	return production;
}

ShiftSupervisor::~ShiftSupervisor()
{

}