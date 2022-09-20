// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_BASEMODULE_H
#define FINALPROJECT_BASEMODULE_H

#include "storage.h"
#include <ostream>

class BaseModule
{
	protected:
	Storage<Book> *inventory;

	public:
	BaseModule (Storage<Book> *inv);
	virtual void showMenu () = 0;
};


#endif //FINALPROJECT_BASEMODULE_H
