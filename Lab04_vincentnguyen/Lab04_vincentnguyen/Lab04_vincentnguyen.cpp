#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main()
{

	cout << "The year has ended..." << endl;
	//Employee Nobody;
	//Employee James("James", 22, "03/12/2019");

	//ProductionWorker Nobody;

	ProductionWorker Kevin("Kevin" , 1, "04/04/1999", 2, 44);
	Employee *pKevin = &Kevin;
	pKevin->lunch();

	cout << endl << endl;

	ProductionWorker Daryl("Daryl", 2, "01/36/1998");
	Employee *pDaryl = &Daryl;
	pDaryl->lunch("Daryl");

	cout << endl << endl;

	ShiftSupervisor Eric("Eric", 3, "01/27/1999");

	cout << endl << endl;

	ShiftSupervisor Timmy("Timmy", 4, "01/08/1997", 25000, 1000, 1520);
	Employee *pTimmy = &Timmy;
	pTimmy->lunch("Timmy");

	cout << endl << endl;

	TeamLeader Andy("Andy", 6, "06/09/2001");

	cout << endl << endl;

	TeamLeader Heather("Heather", 7, "05/02/2002", 1, 82, 500, 10, 10);


	system("pause");




	return 0;
}