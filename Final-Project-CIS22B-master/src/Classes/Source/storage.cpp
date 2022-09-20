// Created by Team 4
// CIS22B Goel Final Project

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "../Headers/storage.h"

/**
 * Adds a book to the inventory
 * @param obj Book to add
 */
template<class T>
	int Storage<T>::add (const T &obj)
	{
		if (amount == capacity)
			setCapacity(capacity + 20);

		ptr[amount] = obj;
		amount++;
		return amount - 1;
	}

/**
 * Removes a book from the inventory
 * @param index The position in the inventory array of the specified book
 */
template<class T>
	void Storage<T>::remove (int index)
	{
		ptr[index] = Book();
		amount--;
	}

/**
 * Replace the book at the bookId position in the inventory to the book provided by the book parameter
 * @param obj Book to be replace into inventory
 * @param index The position in the inventory of the book to be replaced
 */
template<class T>
	void Storage<T>::replace (const T &obj, int index)
	{
		ptr[index] = obj;
	}

/**
 * Finds the first book in the inventory by pattern
 * @param searchStr String that is attempted to be found
 * @param pattern By which attribute the search should be done
 * @return The position of the book found, returns -1 if not found;
 */
template<class T>
	int Storage<T>::findFirstObj (const std::string &searchStr, Pattern pattern)
	{
		sort(pattern);

		int         first = 0,
					last  = capacity - 1,
					middle,
					n     = -1;
		std::string mid;
		bool        found = false;

		if (searchStr.empty())
			return n;

		while (first <= last && !found)
		{
			middle = (first + last) / 2;
			if ((pattern == ISBN && searchStr == ptr[middle].getIsbn())
				|| (pattern == Title && searchStr == ptr[middle].getTitle())
				|| (pattern == Author && searchStr == ptr[middle].getAuthor())
				|| (pattern == Publisher && searchStr == ptr[middle].getPublisher()))
			{
				n     = middle;
				found = true;
			}
			else if ((pattern == ISBN && searchStr > ptr[middle].getIsbn())
					 || (pattern == Title && searchStr < ptr[middle].getTitle())
					 || (pattern == Author && searchStr < ptr[middle].getAuthor())
					 || (pattern == Publisher && searchStr < ptr[middle].getPublisher()))// search is on left
				last = middle - 1;
			else if ((pattern == ISBN && searchStr < ptr[middle].getIsbn())
					 || (pattern == Title && searchStr > ptr[middle].getTitle())
					 || (pattern == Author && searchStr > ptr[middle].getAuthor())
					 || (pattern == Publisher && searchStr > ptr[middle].getPublisher())) // search is on right
				first = middle + 1;
		}

		return n;
	}

/**
 * Sorts book by a pattern
 * @param pattern Attribute to sort by
 */
template<class T>
	void Storage<T>::sort (Pattern a)
	{
		int scan,
			maxIndex;

		Book maxValue;    //To hold the current lowest value
		Book::setDetail(a);

		//This for loop will go through each element of the books[] array starting with the first: books[0].
		for (scan = 0; scan < (capacity - 1); scan++)
		{
			maxIndex = scan;                                           //The minIndex is the first element, assigned to 0.
			maxValue = ptr[scan];                                     //The 'smallest element' starts at the beginning.
			maxValue.splitDate();
			//This for loop will look to the next element for swapping.
			for (int currentIndex = scan + 1; currentIndex < capacity; currentIndex++)
			{
				//Determine if the current element selected is larger than what is considered the 'smallest value'.
				if (ptr[currentIndex] > maxValue)
				{
					maxValue = ptr[currentIndex];                          //Assign this element to the smallest value of this array.
					maxIndex = currentIndex;                                //The current index is now the smallest.
				}
			}
			ptr[maxIndex] = ptr[scan];
			ptr[scan]     = maxValue;
		}
	}

/**
 * Getter for the amount of ptr in the inventory
 * @return Amount of ptr in the inventory
 */
template<class T>
	int Storage<T>::getAmount () const
	{
		return amount;
	}

template<class T>
	T &Storage<T>::operator[] (int index)
	{
		if (0 < index <= amount)
			return ptr[index];
		else
			return ptr[0];
	}

template<class T>
	int Storage<T>::getCapacity () const
	{
		return capacity;
	}

template<class T>
	void Storage<T>::setCapacity (int c)
	{
		if (c < amount)
		{
			capacity = amount;
			return;
		}
		else if (c < 0)
			capacity = 0;
		else
			capacity = c;

		Book *tmp = ptr;
		ptr = new Book[capacity];
		for (int i = 0; i < amount; i++)
			ptr[i] = tmp[i];
		delete[] tmp;
	}

template<class T>
	void Storage<T>::save (std::ofstream &file)
	{
		sort(::ISBN);
		for (int i = 0; i < capacity; i++)
		{
			if (ptr[i].getIsbn() == "-1")
				continue;

			if (i == amount - 1)
				file << ptr[i];
			else
				file << ptr[i] << std::endl;
		}
	}

template<class T>
	Storage<T>::Storage (std::ifstream &file)
	{
		amount   = 0;
		capacity = 0;
		ptr      = nullptr;
		if (file)
		{
			std::string tmp;
			int         result = 0;
			while (std::getline(file, tmp))
				result++;
			file.clear();
			file.seekg(0, std::ifstream::beg);

			amount   = result;
			capacity = amount + 20;
			int i = 0;

			ptr = new T[capacity];
			while (file >> ptr[i++]);
		}
		else
			throw "File cannot be accessed!"; //
	}

template<class T>
	Storage<T>::Storage ()
	{
		amount   = 0;
		capacity = 20;
		ptr      = new T[capacity];
	}

template<class T>
	Storage<T>::~Storage ()
	{
		delete[] ptr;
	}


