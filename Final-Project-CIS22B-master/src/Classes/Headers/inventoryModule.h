// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_INVENTORYMODULE_H
#define FINALPROJECT_INVENTORYMODULE_H


#include "baseModule.h"

class InventoryModule : public BaseModule
{
	public:
	InventoryModule (Storage<Book> *inv);
	void showMenu () override;
	void findBook ();
	void addBook ();
	void removeBook ();
	void editBook ();
};


#endif //FINALPROJECT_INVENTORYMODULE_H
