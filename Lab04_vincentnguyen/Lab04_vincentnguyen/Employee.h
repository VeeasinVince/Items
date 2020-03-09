#pragma once
#include <iostream>
#include <string>

using namespace std;	//delete later


class Employee {

private:
	string name;
	int number;
	string hireDate;

public:
	Employee();
	Employee(string n, int i, string d);

	//setters
	void setName(string n);
	void setNumber(int n);
	void setHireDate(string d);

	//getters
	string getName();
	int getNumber();
	string getHireDate();



	~Employee();
};
