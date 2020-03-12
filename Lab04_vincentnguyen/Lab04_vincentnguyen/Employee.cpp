#include <iostream>
#include <string>
#include "Employee.h"

Employee::Employee() :name("a ghost"), number(-1), hireDate("never")
{

	std::cout << "Employee number: " << number << ", " << name << ", was hired " << hireDate << "." << std::endl;
}

Employee::Employee(std::string n, int i, std::string d) :name(n), number(i), hireDate(d)		//initialization syntax
{

	std::cout << "Employee number: " << number << ", " << name << ", was hired " << hireDate << "." << std::endl;

}

void Employee::setName(std::string n)
{
	name = n;
}

void Employee::setNumber(int n)
{
	number = n;
}

void Employee::setHireDate(std::string d)
{
	hireDate = d;
}

std::string Employee::getName()
{
	return name;
}

int Employee::getNumber()
{
	return number;
}

std::string Employee::getHireDate()
{
	return hireDate;
}

void Employee::lunch()
{
	std::cout << "This employee is having lunch right now." << std::endl;
}

void Employee::lunch(std::string n)
{
	std::cout << n << " is having lunch right now." << std::endl;
}

Employee::~Employee()
{

}