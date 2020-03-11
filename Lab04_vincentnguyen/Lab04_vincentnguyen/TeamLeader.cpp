#include <iostream>
#include <string>
#include "TeamLeader.h"

using namespace std;	//delete later

TeamLeader::TeamLeader() 
{
	monBonus = 0.0;
	needHr = 0;
	haveHr = 0;

	cout << "Their monthly bonus is $" << 0 << ". The required hours of training for " << "a ghost" << " is " << 0 << " hours and they have " << 0 << " hours." << endl;
	cout << "They like to haunt the factory." << endl;
}

TeamLeader::TeamLeader(string n, int i, string d, int s, double h, double b, int need, int have) :ProductionWorker(n, i, d, s, h)
{
	cout << "Their monthly bonus is $" << b << ". The required hours of training for " << n << " is "
		<< need << " hours and they have " << have << " hours." << endl;

	if (have < need)
	{
		cout << "They do not have the required training hours. " << n << " has been fired and will not be missed!" << endl;
	}
	else
	{
		cout << "They have meet the required amount of " << need << " training hours. " << n << " gets to keep their job!" << endl;
	}
}

TeamLeader::TeamLeader(string n, int i, string d) :ProductionWorker(n, i, d), monBonus(25), needHr(10), haveHr(0)
{
	cout << "Their monthly bonus is $" << monBonus << ". The required hours of training for " << n << " is "
		<< needHr << " hours and they have " << haveHr << " hours." << endl;

	if (haveHr < needHr)
	{
		cout << "They do not have the required training hours. " << needHr << " has been fired and will not be missed!" << endl;
	}
	else
	{
		cout << "They have meet the required amount of " << needHr << " training hours. " << n << " gets to keep their job!" << endl;
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
	cout << "This team leader is having lunch right now." << endl;
}

TeamLeader::~TeamLeader()
{

}