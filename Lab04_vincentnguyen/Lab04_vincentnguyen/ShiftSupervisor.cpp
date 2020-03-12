#include <iostream>
#include <string>
#include "ShiftSupervisor.h"

ShiftSupervisor::ShiftSupervisor() :anuSal(0), proBonus(0), production(0)
{

	std::cout << "They make $" << 0 << " a year." << std::endl;

	std::cout << "Their production goal every year is 1500 units of chocolates and they have a annual production of " << 0 << " units of chocolate." << std::endl;

	std::cout << "They have not reached their goal of 1500 units of chocolate. They do not recieve their bonus of $" << 0 << " , their salary is $" << 0 << " and they are a disgrace to the company!" << std::endl;
	
}

ShiftSupervisor::ShiftSupervisor(std::string n, int i, std::string d, double a, double b, int p) :Employee(n, i, d)
{
	std::cout << "They make $" << a << " a year." << std::endl;

	std::cout << "Their production goal every year is 1500 units of chocolates and they have a annual production of " << p << " units of chocolate." << std::endl;

	if (p >= 1500)		//Determines if the shoft supervisor meets the production quota
	{
		std::cout << "Congratualtions, they have reached their goal of 1500 units! Their salary this year is $" << a + static_cast<double>(p) << "!" << std::endl;
	}
	else
	{
		std::cout << "They have not reached their goal of 1500 units of chocolate. They do not recieve their bonus of $" << p << " , their salary is $" << a << " and they are a disgrace to the company!" << std::endl;
	}


}

ShiftSupervisor::ShiftSupervisor(std::string n, int i, std::string d) : anuSal(8000), production(80), proBonus(10), Employee(n, i, d)
{
	std::cout << "They make $" << anuSal << " a year." << std::endl;

	std::cout << "Their production goal every year is 1500 units of chocolates and they have a annual production of " << production << " units of chocolate.";

	
	std::cout << "They have not reached their goal of 1500 units of chocolate. They do not recieve their bonus of $" << proBonus
		<< " , their salary is $" << anuSal << " and they are a disgrace to the company!" << std::endl;
	
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

void ShiftSupervisor::lunch()
{
	std::cout << "This shift supervisor is having lunch right now." << std::endl;
}

ShiftSupervisor::~ShiftSupervisor()
{

}