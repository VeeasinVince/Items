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