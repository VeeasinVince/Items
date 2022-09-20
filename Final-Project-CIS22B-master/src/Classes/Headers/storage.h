// Created by Team 4
// CIS22B Goel Final Project

#ifndef FINALPROJECT_STORAGE_H
#define FINALPROJECT_STORAGE_H

#include <ostream>
#include <iostream>
#include <fstream>
#include "book.h"

template<class T>
	class Storage
	{
		private:
		T   *ptr;
		int amount;
		int capacity;

		public:
		Storage (std::ifstream &file);
		Storage ();
		virtual ~Storage ();

		int add (const T &obj);
		void remove (int index);
		void replace (const T &obj, int index);
		int findFirstObj (const std::string &searchStr, Pattern pattern);
		void sort (Pattern pattern);
		void save (std::ofstream &file);

		int getCapacity () const;
		void setCapacity (int c);
		int getAmount () const;

		T &operator[] (int index);

		//I have to inline the friend function because of templating
		friend std::ostream &operator<< (std::ostream &os, const Storage<T> &inventory)
		{
			for (int i = 0, k = 1; i < inventory.capacity; i++)
			{
				if (inventory.ptr[i].getIsbn() == "-1")
					continue;
				os << "\t\t[" << k << "]" << std::endl
				   << inventory.ptr[i] << std::endl;
				k++;
			}
			return os;
		}
	};

#include "../Source/storage.cpp"

#endif //FINALPROJECT_STORAGE_H
