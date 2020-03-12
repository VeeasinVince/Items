//Vincent Nguyen Lab04
//This program will create class objects and orint out the relevant details.
//Pseudocode Main:
//1. Create a ProductionWorker object with no parameters
//2. Create a ProductionWorker object with 5 parameters
//	a. Create base (Employee) pointer to point to child (Production Worker) and to point to the lunch function with no parameters
//3. Create a ProductionWorker object with 3 parameters 
//	a. Create base (Employee) pointer to point to child (Production Worker) and to point to the lunch function with a string parameter
//4. Create a ShiftSupervisor object with 3 parameters
//5. Create a ShiftSupervisor object with 6 parameters
//	a. Create base (Employee) pointer to point to child (ShiftSupervisor) and to point to the lunch function with a string parameter
//6. Create a TeamLeader object with 3 parameters
//7. Create a TeamLeader object with 8 parameters
//8. End program


#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main()
{	//Constructors print out the information.

	cout << "The year has ended..." << endl;
	//Employee Nobody;
	//Employee James("James", 22, "03/12/2019");
	ProductionWorker Nobody;
	Nobody.lunch();		//statically calls the productionworker version of lunch.

	cout << endl << endl;

	ProductionWorker Kevin("Kevin" , 1, "04/04/1999", 2, 44);		//Production worker kevin.
	Employee *pKevin = &Kevin;
	pKevin->lunch();		//Prints out lunch function with no parameters.

	cout << endl << endl;
	
	ProductionWorker Daryl("Daryl", 2, "01/36/1998");		//Production Wroker Daryl
	Employee *pDaryl = &Daryl;
	pDaryl->lunch("Daryl");		//Prints out lunch function with name parameter

	cout << endl << endl;

	ShiftSupervisor Eric("Eric", 3, "01/27/1999");		//Shift supervisor Eric.

	cout << endl << endl;

	ShiftSupervisor Timmy("Timmy", 4, "01/08/1997", 25000, 1000, 1520);		//Shift supervisor Timmy.
	Employee *pTimmy = &Timmy;
	pTimmy->lunch("Timmy");		//Prints out lunch function with employee (base) pointer to Shiftsupervisor (child) class.

	cout << endl << endl;

	TeamLeader Andy("Andy", 6, "06/09/2001");		//Team Leader Andy

	cout << endl << endl;

	TeamLeader Heather("Heather", 7, "05/02/2002", 1, 82, 500, 10, 10);		//Team Leader Heather


	system("pause");




	return 0;
}