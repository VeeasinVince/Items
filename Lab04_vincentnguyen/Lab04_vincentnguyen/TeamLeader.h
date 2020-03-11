#pragma once
#include <iostream>
#include <string>
#include "ProductionWorker.h"

using namespace std;	//delete later

class TeamLeader : public ProductionWorker {

private:
	double monBonus;
	int needHr;
	int haveHr;

public:

	TeamLeader();
	TeamLeader(string n, int i, string d, int s, double h, double b, int need, int have);
	TeamLeader(string n, int i, string d);

	void setMonBonus(double b);
	void setNeedHr(int n);
	void setHaveHr(int h);

	double getMonBonus();
	int getNeedHr();
	int getHaveHr();

	void lunch();

	~TeamLeader();
};