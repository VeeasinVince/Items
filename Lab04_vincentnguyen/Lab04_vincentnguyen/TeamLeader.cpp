#include <iostream>
#include <string>
#include "TeamLeader.h"

TeamLeader::TeamLeader() :monBonus(0), needHr(0), haveHr(0)
{

	std::cout << "Their monthly bonus is $" << 0 << ". The required hours of training for " << "a ghost" << " is " << 0 << " hours and they have " << 0 << " hours." << std::endl;
	std::cout << "They like to haunt the factory." << std::endl;
}

TeamLeader::TeamLeader(std::string n, int i, std::string d, int s, double h, double b, int need, int have) :ProductionWorker(n, i, d, s, h)
{
	std::cout << "Their monthly bonus is $" << b << ". The required hours of training for " << n << " is "
		<< need << " hours and they have " << have << " hours." << std::endl;

	if (have < need)
	{
		std::cout << "They do not have the required training hours. " << n << " has been fired and will not be missed!" << std::endl;
	}
	else
	{
		std::cout << "They have meet the required amount of " << need << " training hours. " << n << " gets to keep their job!" << std::endl;
	}
}

TeamLeader::TeamLeader(std::string n, int i, std::string d) :ProductionWorker(n, i, d), monBonus(25), needHr(10), haveHr(0) 
{
	std::cout << "Their monthly bonus is $" << monBonus << ". The required hours of training for " << n << " is "
		<< needHr << " hours and they have " << haveHr << " hours." << std::endl;

	if (haveHr < needHr)		//Determines if the Team Leader meet their trainng hour quota
	{
		std::cout << "They do not have the required training hours. " << n << " has been fired and will not be missed!" << std::endl;
	}
	else
	{
		std::cout << "They have meet the required amount of " << needHr << " training hours. " << n << " gets to keep their job!" << std::endl;
	}
}

void TeamLeader::setMonBonus(double b)
{
	monBonus = b;
}

void TeamLeader::setNeedHr(int n)
{
	needHr = n;
}

void TeamLeader::setHaveHr(int h)
{
	haveHr = h;
}

double TeamLeader::getMonBonus()
{
	return monBonus;
}

int TeamLeader::getNeedHr()
{
	return needHr;
}

int TeamLeader::getHaveHr()
{
	return haveHr;
}

void TeamLeader::lunch()
{
	std::cout << "This team leader is having lunch right now." << std::endl;
}

TeamLeader::~TeamLeader()
{

}