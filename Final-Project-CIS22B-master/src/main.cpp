// Created by Team 4
// CIS22B Goel Final Project

#define_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Classes/Headers/book.h"
#include "Classes/Headers/storage.h"
#include "Classes/Headers/cashierModule.h"
#include "Classes/Headers/reportModule.h"
#include "Classes/Headers/inventoryModule.h"

using namespace std;

void mainMenu (InventoryModule &inv, CashierModule &cash, ReportModule &report)
{
	for (int uInput = 0; uInput != 4;)
	{
		cout << "Welcome. Select module:\n"
			 << "1. Cashier\n"
			 << "2. Inventory\n"
			 << "3. Report\n"
			 << "4. Exit\n";
		cin >> uInput;
		while (uInput < 1 || uInput > 4) // Verify user input
		{
			cout << "Invalid input. Select module:\n"
				 << "1. Cashier\n"
				 << "2. Inventory\n"
				 << "3. Report\n"
				 << "4. Exit\n";
			cin >> uInput;
		}

		switch (uInput)
		{
			case 1: // Cashier Module
			{
				cash.showMenu();
				break;
			}
			case 2:    // Inventory Module
			{
				inv.showMenu();
				break;
			}
			case 3:    // Report Module
			{
				report.showMenu();
				break;
			}
			default:
				break;
		}
	}
}

int main ()
{
	string   path = "../data/catalog.txt";
	ifstream file(path);
	if (!file)
	{
		cout << "Error, can't open file" << endl;
		system("pause");
		return 1;
	}

	Storage<Book> *inventory;

	try
	{
		inventory = new Storage<Book>(file);
	}
	catch (char *ex)
	{
		cout << "Error, can't load inventory" << endl;
		cerr << ex << endl;

		system("pause");
		return 1;
	}


	ReportModule    reportModule(inventory);
	CashierModule   cashierModule(inventory);
	InventoryModule inventoryModule(inventory);

	mainMenu(inventoryModule, cashierModule, reportModule);

	file.close();
	ofstream write(path, ios::out | ios::trunc);
	inventory->save(write);

	delete inventory;
	write.close();
	system("pause");
	return 0;
}
