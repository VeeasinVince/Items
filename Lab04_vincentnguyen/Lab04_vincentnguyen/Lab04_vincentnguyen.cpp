#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main()
{

	cout << "The year has started..." << endl;
	//Employee Nobody;
	//Employee James("James" , 22, "03/12/2019");

	//ProductionWorker Nobody;

	ProductionWorker Kevin("Kevin" , 1, "04/04/1999", 2, 44);
	//ProductionWorker *pKevin = &Kevin;

	//ProductionWorker Daryl("Daryl", 2, "06/18/1999", 1, 33);
	//ProductionWorker *pDaryl = &Daryl;

	ShiftSupervisor Eric("Eric", 3, "01/27/1999", 22000, 1000, 200);
	//ShiftSupervisor *pEric = &Eric;


	system("pause");




	return 0;
}