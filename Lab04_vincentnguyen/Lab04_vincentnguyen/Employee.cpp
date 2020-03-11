#include <iostream>
#include <string>
#include "Employee.h"

using namespace std; //delete later

Employee::Employee()
{

	cout << "Employee number:0, a ghost was hired never." << endl;
}

Employee::Employee(string n, int i, string d) :name(n), number(i), hireDate(d)
{

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

void Employee::lunch()
{
	cout << "This employee is having lunch right now." << endl;
}

void Employee::lunch(string n)
{
	cout << n << " is having lunch right now." << endl;
}

Employee::~Employee()
{

}