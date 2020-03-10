#include <iostream>
#include <string>
#include "Employee.h"

using namespace std; //delete later

Employee::Employee()
{
	name = "a ghost";
	number = 0;
	hireDate = "never";

	cout << "Employee number:" << number << ", " << name << " was hired " << hireDate << "." << endl;
}

Employee::Employee(string n, int i, string d) :name(n), number(i), hireDate(d)
{
	name = n;
	number = i;
	hireDate = d;

	cout << "Employee number:" << number << ", " << name << " was hired " << hireDate << "." << endl;

}

void Employee::setName(string n)
{
	name = n;
}

void Employee::setNumber(int n)
{
	number = n;
}

void Employee::setHireDate(string d)
{
	hireDate = d;
}

string Employee::getName()
{
	return name;
}

int Employee::getNumber()
{
	return number;
}

string Employee::getHireDate()
{
	return hireDate;
}

Employee::~Employee()
{

}