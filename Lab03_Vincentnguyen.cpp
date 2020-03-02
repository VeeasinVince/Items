//Vincent Nguyen Lab 3
//This program will ask for user input on both the names and the coordinates for bottom left and upper right of two rectanbgles.
//Then it will calculate the perimeter and area of both. Next it will add the rectanlges to form a new rectanlge, followed by subtarctin the two, also getting both perimeter and area of both.
//Finally it will ask the user if they would like to continue. Whenever the user is done, the program will print the information into an output file.
//------------------
//U.M.L:
//Rectangle
//---------------------------
//-name : string
//-x1, y1, x2, y2 : int
//------------
//+Rectangle()
//+Rectangle(aa : int, bb : int, cc : int, dd : int)
//+getName() : string
//+getX1() : int
//+getX2() : int
//+getY1() : int
//+getY2() : int
//+setX1(a : int) : void
//+setX2(b : int) : void
//+setY1(c : int) : void
//+setY2(d : int) : void
//+getPerim(per : Rectangle) : int
//+getArea(Ar : Rectangle) : int
//+operator>>(input : istream, coor : Rectangle) : istream
//+operator<<(output : ostream, coor : Rectangle) : ostream
//+operator+(boxy : Rectangle) : Rectangle
//+operator-(a : Rectangle, boxxy : Rectangle) : Rectangle
//+invalid() : bool
//~Rectangle()

//Main():
//1. Open output file
//2. Ask user for the names of thw two rectangles
//3. Ask the user for the coordinates of the bottom left and the upper right of the frist rectanlge
//	a. If rectanlge cannot be formed, repeat step 3 until valid.
//4. Repeat step 3 for the second rectangle
//5. Add both rectangles to get the third, print details.
//6. Subtract both rectangles to get fourth, print details.
//7. Ask user if they would like to rerun the program.
//	a. If yes: go back to step 1
//	b. If no: end program
//
//operator>>():
//1. input coordinate x1
//2. input coordinate y1
//3. inpout coordinate x2
//4. inout coordinate y2
//
//operator<<():
//1. output name
//2. output coordinates for bottom left
//3. output cooridnates for upper left
//4. output coordinates for upper right
//5. output cooridntaes for upper left
//6. output perimeter
//7. output area
//
//operator+():
//1. define addRect to assign to return
//2. Combine name of left with right
//3. Depending on where the second rectangle is:
//	a. assign values if 2nd is located in upper right
//  b. assign values if 2nd is located in lower left
//  c. assign values if 2nd is located in upper left
//  d. assign values if 2nd is located in lower right
// 
//operator-():
//1. define subRect to assign to return
//2. Depending on where the second rectangle is:
//	a. assign values if 2nd is located in upper right
//  b. assign values if 2nd is located in lower left
//  c. assign values if 2nd is located in upper left
//  d. assign values if 2nd is located in lower right
//
#include <iostream>
#include<fstream>
#include "Rectangle.h"
using namespace std; //REMOVE THIS AFTER DONE

int main()
{
	Rectangle box1;
	Rectangle box2;
	string name;
	int cont = 0;
	int choice = 1;

	ofstream output;		//use later
	output.open("output.txt");

	do {
		system("CLS");
		//////////////////Get the names of the two rectangles//////////////////
		cout << "What is the name of the first rectangle:";
		cout << endl << ">";

		cin >> name;
		box1.setName(name);

		cout << "What is the name of the second rectangle:";
		cout << endl << ">";

		cin >> name;
		box2.setName(name);

		system("CLS");
		////////////////////Get the coordinates of the two rectangles///////////////////
		cout << "For " << box1.getName() << " rectangle, enter x and y coordinates respectively for the bottom left corner,)" << endl
			<< "then enter the x and y coordinates respectively for the upper right corner. " << endl
			<< "Example for (1, 2) and (3, 5): 1 2 3 5";
		cout << endl << ">";

		cin >> box1;

		while (box1.invalid() == false)		//See iff the rectangle can be formed
		{
			cout << "That rectangle cannot be formed, there should be space between the bottom left and upper right coordinates." << endl
				<< "Please enter valid coordinates:";
			cout << endl << ">";
			cin >> box1;
		}

		cout << endl << endl;
		cout << box1;
		output << endl << "------------------------------------" << endl;
		output << box1;		//Print out information into file.

		cout << endl << "enter any number to continue: ";
		cin >> cont;
		system("CLS");
		////////////////////////////
		cout << "For " << box2.getName() << " rectangle, enter x and y coordinates respectively for the bottom left corner," << endl
			<< "then enter the x and y coordinates respectively for the upper right corner. " << endl
			<< "Example for (1, 2) and (3, 5): 1 2 3 5";
		cout << endl << ">";

		cin >> box2;

		while (box2.invalid() == false)
		{
			cout << "That rectangle cannot be formed, there should be space between the bottom left and upper right coordinates." << endl
				<< "Please enter valid coordinates:";
			cout << endl << ">";
			cin >> box2;
		}

		cout << endl << endl;
		cout << box2;
		output << endl << endl << box2;	

		cout << endl << "enter any number to continue: ";
		cin >> cont;
		system("CLS");
		//////////////////////Adding the two rectangles////////////////////
		cout << "Now I will add the two rectangles:" << endl << endl;

		Rectangle plusRect = box1 + box2;
		cout << plusRect;
		output << endl << endl << plusRect;
		cout << endl << endl;

		//////////////////////Subtracting the two rectangles//////////////
		cout << endl << "Now I will subtract the two rectangles:" << endl << endl;
		Rectangle minusRect = box1 - box2;
		cout << minusRect;
		output << endl << endl << minusRect;

		////////////Ask user if they would like to run the program again
		cout << endl << endl << "Would you like to rerun the program? Enter 0 to continue" << endl
			<< ">";
		cin >> choice;

	} while (choice == 0);

	cout << endl << endl << "Now printing out details into output.txt...";

	output.close();

	return 0;
}
