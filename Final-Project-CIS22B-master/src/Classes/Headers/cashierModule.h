// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_CASHIERMODULE_H
#define FINALPROJECT_CASHIERMODULE_H

#include <ostream>
#include <iostream>
#include "baseModule.h"
#include <iomanip>

class CashierModule : public BaseModule
{
	private:
	Storage<Book> *cart;
	float         subtotal;

	void emptyCart();
	void displayCart ();

	public:
	CashierModule (Storage<Book> *inv);
	virtual ~CashierModule ();
	void showMenu () override;
	void addBookToCart ();
	void removeBookFromCart ();
	void editQuantity ();
	void checkout ();
};


#endif //FINALPROJECT_CASHIERMODULE_H
