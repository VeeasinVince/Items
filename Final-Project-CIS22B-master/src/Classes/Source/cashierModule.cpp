// Created by Team 4
// CIS22B Goel Final Project

#define CRT_SECURE_NO_WARNINGS
#include "../Headers/cashierModule.h"

CashierModule::CashierModule (Storage<Book> *inv) : BaseModule(inv)
{
	cart     = new Storage<Book>();
	subtotal = 0;
}

void CashierModule::showMenu ()
{
	int input;
	do
	{
		displayCart();
		std::cout << "Select action: \n"
				  << "1. Add book\n"
				  << "2. Remove book\n"
				  << "3. Checkout\n"
				  << "4. Exit\n";
		std::cin >> input;
		std::cin.ignore(256, '\n');
		if (input < 1 || input > 4)
			std::cout << "Invalid input.";

		if (input == 4)
			break;

		switch (input)
		{
			case 1:
				addBookToCart();
				break;
			case 2:
				removeBookFromCart();
				break;
			case 3:
				checkout();
				break;
			default:
				break;
		}
	} while (true);
}

void CashierModule::addBookToCart ()
{
	std::string input;
	int         n, units;

	std::cout << "Adding to cart. Enter ISBN:";
	std::getline(std::cin, input);

	n = cart->findFirstObj(input, ISBN);
	if (n != -1)
	{
		std::cout << "Book already in the cart, adding to the quantity." << std::endl;
		(*cart)[n].setUnits((*cart)[n].getUnits() + 1);
		subtotal += (*cart)[n].getRetailPrice() * (float) (*cart)[n].getUnits();
		return;
	}

	n = inventory->findFirstObj(input, ISBN);
	if (n == -1)
	{
		std::cout << "Book not found.\n";
	}
	else
	{
		int id = cart->add((*inventory)[n]);

		do
		{
			std::cout << "Enter quantity to be sold:\n";
			std::cin >> units;
			std::cin.ignore(256, '\n');
			if (units <= 0)
				std::cout << "Can't buy negative or 0 books. Please try again." << std::endl;
			else
				break;
		} while (true);

		(*cart)[id].setUnits(units);
		subtotal += (*cart)[id].getRetailPrice() * (float) units;
	}
}

void CashierModule::removeBookFromCart ()
{
	int n, input;

	displayCart();
	do
	{
		std::cout << "Enter item number to remove:" << std::endl;
		std::cin >> n;
		std::cin.ignore(256, '\n');
		if (n < 0 || n > cart->getAmount())
			std::cout << "Invalid Input." << std::endl;
		else
			break;
	} while (true);

	std::cout << "You are about to remove: " << (*cart)[n].getTitle() << std::endl
			  << "Confirm?" << std::endl
			  << "1. Yes" << std::endl
			  << "2. No" << std::endl;
	std::cin >> input;
	std::cin.ignore(256, '\n');

	if (input == 1)
	{
		// Remove retail from subtotal
		subtotal -= (*cart)[n].getRetailPrice() * (float) (*cart)[n].getUnits();
		// Copies empty book to cart
		cart->remove(n);
	}
}

void CashierModule::displayCart ()
{
	int k = 1;
	std::cout << "Current Cart Contents: " << std::endl;
	if (cart->getAmount() == 0)
		std::cout << "Empty" << std::endl;

	for (int i = 0; i < cart->getAmount(); i++)
	{
		if ((*cart)[i].getIsbn() == "-1")
			continue;

		std::cout << k << ". Title: " << (*cart)[i].getTitle()
				  << ", Qty: " << (*cart)[i].getUnits() << std::endl;
		k++;
	}
	std::cout << std::endl;
}

void CashierModule::editQuantity ()
{
	int input, n;
	displayCart();
	do
	{
		std::cout << "Enter item number to edit" << std::endl;
		std::cin >> input;
		std::cin.ignore(256, '\n');
		if (input < 0 || input > cart->getAmount())
			std::cout << "Invalid Input." << std::endl;
		else
			break;
	} while (true);

	do
	{
		std::cout << "Enter quantity to be sold:\n";
		std::cin >> n;
		std::cin.ignore(256, '\n');
		if (n <= 0)
			std::cout << "Can't buy negative or 0 books. Please try again." << std::endl;
		else
			break;
	} while (true);
	// Subtract old quantity from subtotal, add new quantity
	subtotal -= (*cart)[input].getRetailPrice() * (float) (*cart)[input].getUnits();
	subtotal += (*cart)[input].getRetailPrice() * (float) n;
	// Set new quantity
	(*cart)[input].setUnits(n);
}

void CashierModule::checkout ()
{
	std::string ISBN;
	int         n, units, input;
	float       tax, total;

	displayCart();
	std::cout << "Confirm purchase?" << std::endl
			  << "1. Yes" << std::endl
			  << "2. No" << std::endl;
	std::cin >> input;
	std::cin.ignore(256, '\n');

	if (input != 1)
		return;

	for (int i = 0; i < cart->getAmount(); i++)
	{
		Book &book = (*cart)[i];
		ISBN = book.getIsbn();
		if (ISBN != "-1")
		{
			// Finds book in storage and deduct quantity
			n     = inventory->findFirstObj(ISBN, ::ISBN);
			if (n == -1)
			{
				std::cout << "It would seem that book with ISBN: "
						  << ISBN << " isn't in storage, moving to the next book."
						  << std::endl;
				subtotal -= book.getRetailPrice() * (float) book.getUnits();
				continue;
			}
			units = (*inventory)[n].getUnits();
			if (units == 0)
			{
				std::cout << "We are completely out of "
						  << book.getTitle()
						  << " moving to the next book"
						  << std::endl;
				subtotal -= book.getRetailPrice() * (float) book.getUnits();
				continue;
			}
			int cartUnits = book.getUnits();
			if (cartUnits > units)
			{
				int in = 0;
				std::cout << "We do not have enough of " << book.getTitle() << " in the storage" << std::endl
						  << "Would you like to buy " << units << " units instead?" << std::endl
						  << "1. Yes" << std::endl
						  << "2. No (Removes all of the " << book.getTitle() << " from the list)" << std::endl;
				std::cin >> in;
				std::cin.ignore(256, '\n');
				if (in != 1)
				{
					subtotal -= book.getRetailPrice() * (float) cartUnits;
					continue;
				}
				else
				{
					subtotal -= book.getRetailPrice() * (float) cartUnits;
					subtotal += book.getRetailPrice() * (float) units;
					cartUnits = units;
					book.setUnits(cartUnits);
				}
			}
			(*inventory)[n].setUnits(units - cartUnits);
		}
	}
	emptyCart();
	tax   = subtotal * 0.0725f;
	total = subtotal + tax;
	std::cout << "Checking out..." << std::endl;
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Subtotal: $" << subtotal << std::endl
			  << "Sales Tax: $" << tax << std::endl
			  << "Total: $" << total << std::endl;
	std::cout << "Confirm purchase?" << std::endl
			  << "1. Yes" << std::endl
			  << "2. No" << std::endl;
	std::cin >> input;
	std::cin.ignore(256, '\n');

	if (input != 1)
		return;
	std::cout << "Payment processed. Checkout complete.\n";
}

void CashierModule::emptyCart ()
{
	for (int i = 0; i < cart->getAmount(); i++)
		cart->remove(i);

	cart->setCapacity(20);
}

CashierModule::~CashierModule ()
{
	delete cart;
}
