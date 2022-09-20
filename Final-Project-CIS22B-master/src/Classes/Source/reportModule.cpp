// Created by Team 4
// CIS22B Goel Final Project

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "../Headers/reportModule.h"

ReportModule::ReportModule (Storage<Book> *inv) : BaseModule(inv)
{ }

void ReportModule::showInventoryList ()
{
	inventory->sort(Pattern::ISBN);
	std::cout << "Inventory List:" << std::endl;
	std::cout << *inventory << std::endl;
}

void ReportModule::showWholesaleValue ()
{
	float total = 0.0;

	for (int i = 0, k = 1; i < inventory->getAmount(); i++)
	{
		Book &book = (*inventory)[i];
		if (book.getIsbn() == "-1")
			continue;

		std::cout << k << ". " << book.getTitle() << ", $"
				  << book.getWholesalePrice() << " Qty: " << book.getUnits()
				  << std::endl;
		total += book.getWholesalePrice() * (float) book.getUnits();
		k++;
	}

	std::cout << std::setprecision(2) << std::fixed << std::endl;
	std::cout << "Total Wholesale Prices of the inventory: $" << total << std::endl << std::endl;
}

void ReportModule::showRetailValue ()
{
	float total = 0.0;

	for (int i = 0, k = 1; i < inventory->getAmount(); i++)
	{
		Book &book = (*inventory)[i];
		if (book.getIsbn() == "-1")
			continue;

		std::cout << k << ". " << book.getTitle() << ", $"
				  << book.getRetailPrice() << " Qty: " << book.getUnits()
				  << std::endl;
		total += book.getRetailPrice() * (float) book.getUnits();
		k++;
	}

	std::cout << std::setprecision(2) << std::fixed << std::endl;
	std::cout << "Total Retail Prices of the inventory: $" << total << std::endl << std::endl;
}

void ReportModule::showInventoryByUnits ()
{
	inventory->sort(Pattern::UnitsAvailable);
	std::cout << "Inventory List By Units:" << std::endl;
	std::cout << *inventory << std::endl;
}

void ReportModule::showInventoryByCost ()
{
	inventory->sort(Pattern::WholesalePrice);
	std::cout << "Inventory List by Wholesale Price:" << std::endl;
	std::cout << *inventory << std::endl;
}

void ReportModule::showMenu ()
{
	int uInput = 0;
	do
	{
		do
		{
			std::cout << "Select desired report:\n"
					  << "1. Inventory List\n"
					  << "2. Inventory Wholesale Value\n"
					  << "3. Inventory Retail Value\n"
					  << "4. List by Quantity\n"
					  << "5. List by Cost\n"
					  << "6. List by Age\n"
					  << "7. Return to main menu\n";
			std::cin >> uInput;
			if (uInput < 1 || uInput > 7)
				std::cout << "Invalid Input" << std::endl;
		} while (uInput < 1 || uInput > 7);

		if (uInput == 7)
			break;

		switch (uInput)
		{
			case 1:
				showInventoryList();
				break;
			case 2:
				showWholesaleValue();
				break;
			case 3:
				showRetailValue();
				break;
			case 4:
				showInventoryByUnits();
				break;
			case 5:
				showInventoryByCost();
				break;
			case 6:
				showInventoryByAge();
				break;

			default:
				break;
		}
	} while (true);
}

void ReportModule::showInventoryByAge ()
{
	inventory->sort(Pattern::Date);
	std::cout << "Inventory List by Ages:" << std::endl;
	std::cout << *inventory << std::endl;
}
