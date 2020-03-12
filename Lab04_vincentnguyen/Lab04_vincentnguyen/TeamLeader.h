#pragma once
//Vincent Nguyen Lab04
#include <iostream>
#include <string>
#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker {

private:
	double monBonus;
	int needHr;
	int haveHr;

public:

	TeamLeader();
	TeamLeader(std::string n, int i, std::string d, int s, double h, double b, int need, int have);
	TeamLeader(std::string n, int i, std::string d);

	void setMonBonus(double b);
	void setNeedHr(int n);
	void setHaveHr(int h);

	double getMonBonus();
	int getNeedHr();
	int getHaveHr();

	void lunch();

	~TeamLeader();
};