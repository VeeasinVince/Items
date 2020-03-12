#pragma once
//Vincent Nguyen Lab04
#include <iostream>
#include <string>

class Employee {

private:		//Employee variables
	std::string name;
	int number;
	std::string hireDate;

public:
	Employee();									//constructors
	Employee(std::string n, int i, std::string d);

	//setters
	void setName(std::string n);
	void setNumber(int n);
	void setHireDate(std::string d);

	//getters
	std::string getName();
	int getNumber();
	std::string getHireDate();

	virtual void lunch() = 0;	//Used for dynamic binding
	void lunch(std::string n);	//Used for static binding
	


	~Employee();
};