// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_REPORTMODULE_H
#define FINALPROJECT_REPORTMODULE_H


#include "baseModule.h"

class ReportModule : public BaseModule
{
	public:
	ReportModule (Storage<Book> *inv);
	void showInventoryList();
	void showWholesaleValue();
	void showRetailValue();
	void showInventoryByUnits();
	void showInventoryByCost();
	void showInventoryByAge();
	void showMenu () override;
};


#endif //FINALPROJECT_REPORTMODULE_H
