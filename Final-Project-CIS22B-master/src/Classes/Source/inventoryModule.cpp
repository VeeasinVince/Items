// Created by Team 4
// CIS22B Goel Final Project

#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/inventoryModule.h"
#include <ostream>
#include <iostream>

InventoryModule::InventoryModule (Storage<Book> *inv) : BaseModule(inv)
{ }

void InventoryModule::showMenu ()
{
	int input = 0;
	do
	{
		// Prompt user to select action
		do
		{
			std::cout << "Select action:\n"
					  << "1. Search book\n"
					  << "2. Add book\n"
					  << "3. Remove book\n"
					  << "4. Change book info\n"
					  << "5. Return to main menu\n";
			std::cin >> input;
			if (input < 1 || input > 5)
				std::cout << "Invalid Input" << std::endl;
		} while (input < 1 || input > 5);

		if (input == 5)
			break;

		switch (input)
		{
			case 1:
				findBook();
				break;
			case 2:
				addBook();
				break;
			case 3:
				removeBook();
				break;
			case 4:
				editBook();
				break;
			default:
				break;
		}
	} while (true);
}

void InventoryModule::findBook ()
{
	std::string i;
	int         input = 0;
	int         index = 0;
	do
	{
		std::cout << "Search by:" << std::endl
				  << "1. ISBN" << std::endl
				  << "2. Title" << std::endl
				  << "3. Author" << std::endl
				  << "4. Exit" << std::endl;
		std::cin >> input;

		if (input < 1 || input > 4)
		{
			std::cout << "Invalid Input" << std::endl;
			continue;
		}

		if (input == 4)
			break;

		std::cout << "Enter search term: " << std::endl;
		std::cin.ignore(256, '\n');
		std::getline(std::cin, i);

		switch (input)
		{
			case 1:
				index = inventory->findFirstObj(i, ::ISBN);
				break;
			case 2:
				index = inventory->findFirstObj(i, ::Title);
				break;
			case 3:
				index = inventory->findFirstObj(i, ::Author);
				break;
			default:
				index = 0;
				break;
		}

		if (index == -1)
		{
			std::cout << "No books found with " << i << std::endl
					  << "Try again" << std::endl;
			continue;
		}

		std::cout << "Found book" << std::endl
				  << (*inventory)[index] << std::endl;

	} while (true);
}

void InventoryModule::addBook ()
{
	std::string Isbn, Title, Author, Date, Publisher;
	float       Retail, Wholesale;
	int         Units;

	std::cout << "Enter ISBN: " << std::endl;
	std::cin.ignore(256, '\n');
	std::getline(std::cin, Isbn);
	std::cout << "Enter Title: " << std::endl;
	std::getline(std::cin, Title);
	std::cout << "Enter Author: " << std::endl;
	std::getline(std::cin, Author);
	std::cout << "Enter Publisher: " << std::endl;
	std::getline(std::cin, Publisher);
	std::cout << "Enter Date: " << std::endl;
	std::getline(std::cin, Date);
	std::cout << "Enter Retail Price: " << std::endl;
	std::cin >> Retail;
	std::cin.ignore(256, '\n');
	std::cout << "Enter Wholesale Price: " << std::endl;
	std::cin >> Wholesale;
	std::cin.ignore(256, '\n');
	std::cout << "Enter Units in the Inventory: " << std::endl;
	std::cin >> Units;
	std::cin.ignore(256, '\n');

	Book book(Isbn, Title, Author, Publisher, Date, Units, Wholesale, Retail);
	inventory->add(book);

	std::cout << "Book added: " << std::endl
			  << book << std::endl;
}

void InventoryModule::removeBook ()
{
	std::string del;
	int         i = 0;

	std::cout << "Enter ISBN of the book to remove from storage" << std::endl;
	std::cin.ignore(256, '\n');
	std::getline(std::cin, del);
	int n = inventory->findFirstObj(del, ISBN);
	std::cout << (*inventory)[n] << std::endl
			  << "Would you like to delete this book?" << std::endl
			  << "1. Yes" << std::endl
			  << "2. No" << std::endl;
	std::cin >> i;
	if (i == 1)
		inventory->remove(n);
}

void InventoryModule::editBook ()
{
	std::string ISBN;
	std::string tmp;
	int         input = 0;

	int n = 0;
	std::cin.ignore(256, '\n');
	do
	{
		std::cout << "Please enter ISBN" << std::endl;
		std::getline(std::cin, ISBN);
		n = inventory->findFirstObj(ISBN, ::ISBN);
		if (n != -1)
			break;

		std::cout << "Book not found please try again" << std::endl << std::endl;
	} while (true);


	Book &book = (*inventory)[n];
	std::cout << book << std::endl;
	do
	{
		std::cout << "Please select action" << std::endl
				  << "1. ISBN" << std::endl
				  << "2. Title" << std::endl
				  << "3. Author" << std::endl
				  << "4. Publisher" << std::endl
				  << "5. Wholesale Price" << std::endl
				  << "6. Retail Price" << std::endl
				  << "7. Units" << std::endl
				  << "8. Date" << std::endl
				  << "9. Stop Editing" << std::endl;
		std::cin >> input;

		if (input == 9)
			break;

		if (input < 1 || input > 9)
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		std::cout << "Please enter new value" << std::endl;
		std::cin.ignore(256, '\n');
		std::getline(std::cin, tmp);

		switch (input)
		{
			case 1:
				book.setIsbn(tmp);
				break;
			case 2:
				book.setTitle(tmp);
				break;
			case 3:
				book.setAuthor(tmp);
				break;
			case 4:
				book.setPublisher(tmp);
				break;
			case 5:
				book.setWholesalePrice(std::stof(tmp));
				break;
			case 6:
				book.setRetailPrice(std::stof(tmp));
				break;
			case 7:
				book.setUnits(std::stoi(tmp));
				break;
			case 8:
				book.setDate(tmp);
				break;
			default:
				break;
		}
	} while (true);
}
