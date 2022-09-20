// Created by Team 4
// CIS22B Goel Final Project

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include "../Headers/book.h"

Pattern Book::Detail = Pattern::ISBN;

const std::string &Book::getIsbn () const
{
	return ISBN;
}

void Book::setIsbn (const std::string &isbn)
{
	ISBN = isbn;
}

const std::string &Book::getTitle () const
{
	return Title;
}

void Book::setTitle (const std::string &title)
{
	Title = title;
}

const std::string &Book::getAuthor () const
{
	return Author;
}

void Book::setAuthor (const std::string &author)
{
	Author = author;
}

const std::string &Book::getPublisher () const
{
	return Publisher;
}

void Book::setPublisher (const std::string &publisher)
{
	Publisher = publisher;
}

const std::string &Book::getDate () const
{
	return Date;
}

void Book::setDate (const std::string &date)
{
	Date = date;
}

int Book::getUnits () const
{
	return Units;
}

void Book::setUnits (int units)
{
	Units = units;
}

float Book::getWholesalePrice () const
{
	return WholesalePrice;
}

void Book::setWholesalePrice (float originalPrice)
{
	WholesalePrice = originalPrice;
}

float Book::getRetailPrice () const
{
	return RetailPrice;
}

void Book::setRetailPrice (float listedPrice)
{
	RetailPrice = listedPrice;
}

Book::Book (std::string isbn,
			std::string title,
			std::string author,
			std::string publisher,
			std::string date,
			int units,
			float wholesalePrice,
			float retailPrice)
		: ISBN(std::move(isbn)),
		  Title(std::move(title)),
		  Author(std::move(author)),
		  Publisher(std::move(publisher)),
		  Date(std::move(date)),
		  Units(units),
		  WholesalePrice(wholesalePrice),
		  RetailPrice(retailPrice)
{
}

Book::Book ()
{
	this->Author         = "";
	this->ISBN           = "-1";
	this->Title          = "";
	this->Units          = 0;
	this->Date           = "";
	this->RetailPrice    = 0;
	this->WholesalePrice = 0;
}

std::istream &operator>> (std::istream &stream, Book &book)
{
	std::string line;
	if (!std::getline(stream, line))
		return stream;

	std::string       temp;
	std::stringstream s(line);

	auto pattern = static_cast<Pattern>(0);
	while (std::getline(s, temp, '\t'))
	{
		switch (pattern)
		{
			case ::ISBN:
				book.ISBN = temp;
				break;
			case ::Title:
				book.Title = temp;
				break;
			case ::Author:
				book.Author = temp;
				break;
			case ::Publisher:
				book.Publisher = temp;
				break;
			case ::Date:
				book.Date = temp;
				break;
			case ::UnitsAvailable:
				book.Units = std::stoi(temp);
				break;
			case ::WholesalePrice:
				book.WholesalePrice = std::stof(temp);
				break;
			case ::RetailPrice:
				book.RetailPrice = std::stof(temp);
				break;
		}
		pattern = static_cast<Pattern>(pattern + 1);
	}
	book.splitDate();
	return stream;
}

std::ostream &operator<< (std::ostream &stream, const Book &book)
{
	stream << "ISBN: " << book.ISBN << std::endl
		   << "Title: " << book.Title << std::endl
		   << "Author: " << book.Author << std::endl
		   << "Publisher: " << book.Publisher << std::endl
		   << "Wholesale Price: $" << book.WholesalePrice << std::endl
		   << "Retail Price: $" << book.RetailPrice << std::endl
		   << "Quantity Available: " << book.Units << std::endl
		   << "Date added: " << book.Date << std::endl;
	return stream;
}

std::ofstream &operator<< (std::ofstream &stream, const Book &book)
{
	stream << book.ISBN << "\t"
		   << book.Title << "\t"
		   << book.Author << "\t"
		   << book.Publisher << "\t"
		   << book.WholesalePrice << "\t"
		   << book.RetailPrice << "\t"
		   << book.Units << "\t"
		   << book.Date;
	return stream;
}

Book &Book::operator= (const Book &book)
{
	if (this == &book)
		return *this;

	ISBN           = book.ISBN;
	Title          = book.Title;
	Author         = book.Author;
	Publisher      = book.Publisher;
	WholesalePrice = book.WholesalePrice;
	RetailPrice    = book.RetailPrice;
	Units          = book.Units;
	Date           = book.Date;
	Year           = book.Year;
	Month          = book.Month;
	Day            = book.Day;

	return *this;
}

void Book::splitDate ()
{
	std::string mon, mon2,
				da, da2,
				ye, ye2, ye3, ye4;

	if (Date.empty())
		return;

	mon  = Date[0];
	mon2 = Date[1];
	mon += mon2;

	da  = Date[3];
	da2 = Date[4];
	da += da2;

	ye  = Date[6];
	ye2 = Date[7];
	ye3 = Date[8];
	ye4 = Date[9];
	ye += ye2 + ye3 + ye4;

	Month = mon;
	Day   = da;
	Year  = ye;
}

bool operator> (const Book &left, const Book &right)
{
	switch (Book::Detail)
	{
		case UnitsAvailable:                                                        //1: Units
			return (left.Units >= right.Units);
		case WholesalePrice:                                                        //2: Wholesale
			return (left.WholesalePrice >= right.WholesalePrice);
		case RetailPrice:                                                        //3: Retail
			return (left.RetailPrice >= right.RetailPrice);
		case Title:                                                        //4: Title
			return (left.Title <= right.Title);
		case Date:                                                        //5: Date
			if (left.Year < right.Year)
			{
				return (true);
			}
			else if (left.Year > right.Year)
			{
				return (false);
			}
			else if (left.Year == right.Year)
			{
				if (left.Month < right.Month)
				{
					return (true);
				}
				else if (left.Month > right.Month)
				{
					return (false);
				}
				else if (left.Month == right.Month)
				{
					if (left.Day < right.Day)
					{
						return (true);
					}
					else if (left.Day >= right.Day)
					{
						return (false);
					}
				}
			}
			break;
		case Author:                                                        //6: Author
			return (left.Author <= right.Author);
		case ISBN:                                                        //7. ISBN
			return (left.ISBN >= right.ISBN);
		default:
			return true;
	}
	return false;
}
