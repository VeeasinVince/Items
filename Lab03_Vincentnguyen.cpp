#include <iostream>
#include<fstream>
#include "Rectangle.h"
using namespace std; //REMOVE THIS AFTER DONE

int main()
{

	Rectangle box1;
	Rectangle box2;
	string name;
	Rectangle *pRec = nullptr;
	//ofstream fout;		//use later
	//fout.open("output.txt");

	cout << "This program will do some math. " << endl;

////////////////////////////////////////////////
	cout << "What is the name of the first rectangle:";
	cout << endl << ">";

	cin >> name;
	box1.setName(name);

	cout << "What is the name of the second rectangle:";
	cout << endl << ">";

	cin >> name;
	box2.setName(name);

///////////////////////////////////////////////////
	cout << endl;
	cout << "For the first rectangle, enter x and y coordinates respectively for the bottom left corner," << endl
		<< " then enter the x and y coordinates respectively for the upper right corner " << endl
		<< "Example for (1, 2) and (3, 5): 1 2 3 5";
	cout << endl << ">";

	cin >> box1;
	cout << endl << endl;
	cout << box1;
	//fout << box1; //put after every cout.

	cout << "The perimeter of this rectangle is :" << box1.getPerim(box1) << endl;
	cout << "The area of this rectangle is: " << box1.getArea(box1);
////////////////////////////
	cout << endl << endl;
	cout << "For the second rectangle, enter x and y coordinates respectively for the bottom left corner," << endl
		<< " then enter the x and y coordinates respectively for the upper right corner " << endl
		<< "Example for (1, 2) and (3, 5): 1 2 3 5";
	cout << endl << ">";

	cin >> box2;
	cout << endl << endl;
	cout << box2;

	cout << "The perimeter of this rectangle is :" << box2.getPerim(box2) << endl;
	cout << "The area of this rectangle is: " << box2.getArea(box2) << endl;

///////////////////////////////////////////////////////
	cout << "Now I will add the two rectangles:" << endl;

	pRec = &box1;

	cout << endl << "The new rectangle gives me the coordinates: ";
	Rectangle plusRect = box1 + box2;
	cout << plusRect;





	return 0;
}