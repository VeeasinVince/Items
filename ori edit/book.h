//
// Created by Happy on 2/24/2020.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>
using namespace std; //delete for later

class Book
{
private:
	string ISBN;
	string Title;
	string Author;
	string Publisher;
	string Date;
	int         Units;
	float       OriginalPrice;
	float       ListedPrice;

	static int detail; //Use to determine which detail to compare
public:
	//Getter and Setter methods
	const string& getIsbn() const;
	void setIsbn(const string& isbn);

	const string& getTitle() const;
	void setTitle(const string& title);

	const string& getAuthor() const;
	void setAuthor(const string& author);

	const string& getPublisher() const;
	void setPublisher(const string& publisher);

	const string& getDate() const;
	void setDate(const string& date);

	int getUnits() const;
	void setUnits(int units);

	float getOriginalPrice() const;
	void setOriginalPrice(float originalPrice);

	float getListedPrice() const;
	void setListedPrice(float listedPrice);

	static int getDetail() { return detail; }
	static void setDetail(int d) { detail = d; }

	//Other Methods
	Book(const string& isbn,
		const string& title,
		const string& author,
		const string& publisher,
		const string& date,
		int units,
		float originalPrice,
		float listedPrice);
	Book();
	~Book();
	/// Generate a book from a single line provided from a file
	explicit Book(string& line);

	friend istream& operator>> (istream& stream, Book& book);
	friend ostream& operator<< (ostream& stream, const Book& book);

	void operator=(const Book& right) {		//To assign stuff
		this->ISBN = right.ISBN;
		this->Title = right.Title;
		this->Author = right.Author;
		this->Publisher = right.Publisher;
		this->Date = right.Date;
		this->Units = right.Units;
		this->ListedPrice = right.ListedPrice;
		this->OriginalPrice = right.OriginalPrice;
	}

	friend bool operator>(const Book &left, const Book &right);

	static void sort(Book books[], int k);		//Yea yea I'm using code from past lab



};

#endif //FINALPROJECT_BOOK_H#pragma once#pragma once
