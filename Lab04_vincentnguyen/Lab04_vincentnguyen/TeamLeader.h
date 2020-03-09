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

	void setMonBonus(double b);
	void setNeedHr(int n);
	void setHaveHr(int h);

	double getMonBonus();
	int getNeedHr();
	int getHaveHr();




	~TeamLeader();
};