// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>

enum Pattern
{
	ISBN = 0, Title, Author, Publisher, WholesalePrice, RetailPrice, UnitsAvailable, Date
};

class Book
{
	private:
	std::string ISBN;
	std::string Title;
	std::string Author;
	std::string Publisher;
	std::string Date;
	int         Units;
	float       WholesalePrice;
	float       RetailPrice;
	std::string Month, Day, Year;

	static Pattern Detail;
	public:

	//region Getters and Setters
	const std::string &getIsbn () const;
	void setIsbn (const std::string &isbn);

	const std::string &getTitle () const;
	void setTitle (const std::string &title);

	const std::string &getAuthor () const;
	void setAuthor (const std::string &author);

	const std::string &getPublisher () const;
	void setPublisher (const std::string &publisher);

	const std::string &getDate () const;
	void setDate (const std::string &date);

	int getUnits () const;
	void setUnits (int units);

	float getWholesalePrice () const;
	void setWholesalePrice (float originalPrice);

	float getRetailPrice () const;
	void setRetailPrice (float listedPrice);

	static void setDetail (Pattern detail)
	{ Detail = detail; }

	static Pattern getDetail ()
	{ return Detail; }
	//endregion

	//Other Methods
	Book (std::string isbn,
		  std::string title,
		  std::string author,
		  std::string publisher,
		  std::string date,
		  int units,
		  float wholesalePrice,
		  float retailPrice);
	Book ();

	void splitDate ();

	friend std::istream &operator>> (std::istream &stream, Book &book);
	friend std::ofstream &operator<< (std::ofstream &stream, const Book &book);
	friend std::ostream &operator<< (std::ostream &stream, const Book &book);
	friend bool operator> (const Book &left, const Book &right);

	Book &operator= (const Book &book);
};

#endif //FINALPROJECT_BOOK_H
