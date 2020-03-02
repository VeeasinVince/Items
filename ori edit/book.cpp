//
// Created by Happy on 2/24/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "book.h"

int Book::detail = 0;

enum Pattern
{
	ISBN = 0, Title, Author, Publisher, OriginalPrice, ListedPrice, UnitsAvailable, Date
};

const std::string& Book::getIsbn() const
{
	return ISBN;
}

void Book::setIsbn(const std::string& isbn)
{
	ISBN = isbn;
}

const std::string& Book::getTitle() const
{
	return Title;
}

void Book::setTitle(const std::string& title)
{
	Title = title;
}

const std::string& Book::getAuthor() const
{
	return Author;
}

void Book::setAuthor(const std::string& author)
{
	Author = author;
}

const std::string& Book::getPublisher() const
{
	return Publisher;
}

void Book::setPublisher(const std::string& publisher)
{
	Publisher = publisher;
}

const std::string& Book::getDate() const
{
	return Date;
}

void Book::setDate(const std::string& date)
{
	Date = date;
}

int Book::getUnits() const
{
	return Units;
}

void Book::setUnits(int units)
{
	Units = units;
}

float Book::getOriginalPrice() const
{
	return OriginalPrice;
}

void Book::setOriginalPrice(float originalPrice)
{
	OriginalPrice = originalPrice;
}

float Book::getListedPrice() const
{
	return ListedPrice;
}

void Book::setListedPrice(float listedPrice)
{
	ListedPrice = listedPrice;
}

Book::Book(const std::string& isbn,
	const std::string& title,
	const std::string& author,
	const std::string& publisher,
	const std::string& date,
	int units,
	float originalPrice,
	float listedPrice)
	: ISBN(isbn),
	Title(title),
	Author(author),
	Publisher(publisher),
	Date(date),
	Units(units),
	OriginalPrice(originalPrice),
	ListedPrice(listedPrice)
{ }

///@param line is the string from the input
///@returns A single book using information from the line
Book::Book(std::string& line)
{
	std::stringstream s(line);
	std::string       temp;
	auto              pattern = static_cast<Pattern>(0);
	while (std::getline(s, temp, '\t'))
	{
		switch (pattern)
		{
		case ::ISBN:
			this->ISBN = temp;
			break;
		case ::Title:
			this->Title = temp;
			break;
		case ::Author:
			this->Author = temp;
			break;
		case ::Publisher:
			this->Publisher = temp;
			break;
		case ::Date:
			this->Date = temp;
			break;
		case ::UnitsAvailable:
			this->Units = std::stoi(temp);
			break;
		case ::OriginalPrice:
			this->OriginalPrice = std::stof(temp);
			break;
		case ::ListedPrice:
			this->ListedPrice = std::stof(temp);
			break;
		}
		pattern = static_cast<Pattern>(pattern + 1);
	}
}

void Book::sort(Book books[], int k)
{
	int scan,
		maxIndex;

	Book maxValue;	//To hold the current lowest value


					//This for loop will go through each element of the list[] array starting with the first: books[0].
	for (scan = 0; scan < (k - 1); scan++)
	{
		maxIndex = scan;                                           //The minIndex is the first element, assigned to 0.
		maxValue = books[scan];                                     //The 'smallest element' starts at the beginning.

																	//This for loop will look to the next element for swapping.
		for (int currentIndex = scan + 1; currentIndex < k; currentIndex++)
		{
			//Determine if the current element selected is larger than what is considered the 'smallest value'.
			if (books[currentIndex] > maxValue)
			{
				maxValue = books[currentIndex];                          //Assign this element to the smallest value of this array.
				maxIndex = currentIndex;                                //The current index is now the smallest.
			}
		}
		books[maxIndex] = books[scan];
		books[scan] = maxValue;
	}

}
//void Book::sort(Book cover, int j)										//SORT
//{
//	int scan,
//		minIndex;
//
//	string minValue;
//
//
//	//This for loop will go through each element of the list[] array starting with the first: list[0].
//	for (scan = 0; scan < (i - 1); scan++)
//	{
//		minIndex = scan;                                           //The minIndex is the first element, assigned to 0.
//		minValue = list[scan];                                     //The 'smallest element' starts at the beginning.
//
//																   //This for loop will look to the next element for swapping.
//		for (int currentIndex = scan + 1; currentIndex < i; currentIndex++)
//		{
//			//Determine if the current element selected is smaller than what is considered the 'smallest value'.
//			if (list[currentIndex] < minValue)
//			{
//				minValue = list[currentIndex];                          //Assign this element to the smallest value of this array.
//				minIndex = currentIndex;                                //The current index is now the smallest.
//			}
//		}
//		list[minIndex] = list[scan];
//		list[scan] = minValue;
//	}
//
//}

Book::~Book()
{

}

Book::Book()
{
	this->Author = "";
	this->ISBN = "";
	this->Title = "";
	this->Units = 0;
	this->Date = "";
	this->ListedPrice = 0;
	this->OriginalPrice = 0;
}

std::istream& operator>> (std::istream& stream, Book& book)
{
	std::string line;
	std::getline(stream, line);
	book = Book(line);
	return stream;
}

std::ostream& operator<< (std::ostream& stream, const Book& book)
{
	stream << "ISBN: " << book.ISBN << std::endl
		<< "Title: " << book.Title << std::endl
		<< "Author: " << book.Author << std::endl
		<< "Publisher: " << book.Publisher << std::endl
		<< "Retail Price: $" << book.OriginalPrice << std::endl
		<< "Wholesale Price: $" << book.ListedPrice << std::endl
		<< "Quantity Available: " << book.Units << std::endl
		<< "Date added: " << book.Date << std::endl;
	return stream;
}

bool operator>(const Book& left, const Book& right)
{
	if (left.getDetail() == 1)									//1: Units
	{
		return (left.Units >= right.Units);
	}

	else if (left.getDetail() == 2)								//Wholesale
	{
		return (left.ListedPrice >= right.ListedPrice);
	}

	else if (left.getDetail() == 3)								//Retial
	{
		return (left.OriginalPrice >= right.OriginalPrice);
	}

	else if (left.getDetail() == 4)								//Title
	{
		return (left.Title <= right.Title);
	}

	else if (left.getDetail() == 5)								//Date
	{
		return (left.Date >= right.Date);
	}

	else if (left.getDetail() == 6)								//Author
	{
		return (left.Author <= right.Author);
	}

	else if (left.getDetail() == 7)								//ISBN
	{
		return (left.ISBN >= right.ISBN);
	}
}