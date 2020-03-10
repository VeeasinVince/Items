#include <iostream>
#include <string>
#include "TeamLeader.h"

using namespace std;	//delete later

TeamLeader::TeamLeader()
{
	monBonus = 0.0;
	needHr = 0;
	haveHr = 0;
}

TeamLeader::TeamLeader(string n, int i, string d, int s, double h, double b, int need, int have) :ProductionWorker(n, i, d, s, h)
{
	cout << "Employee number:" << i << ", " << n << " was hired " << d << ". They have a " << whatShift(s) << " shift and work for $" << h << "/hour.Their monthly bonus is $" << b << ". The required hours of training for " << n << " is "
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

TeamLeader::~TeamLeader()
{

}