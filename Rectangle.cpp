//Vincent Nguyen Lab 3
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()			//Constructor
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
}
Rectangle::Rectangle(int aa, int bb, int cc, int dd)	//Constructor that sets every point.
{
	int x1 = aa;
	int y1 = bb;
	int x2 = cc;
	int y2 = dd;
}
///////////Getters////////////
std::string Rectangle::getName()
{
	return name;
}
int Rectangle::getX1()
{
	return x1;
}
int Rectangle::getX2()
{
	return x2;
}
int Rectangle::getY1()
{
	return y1;
}
int Rectangle::getY2()
{
	return y2;
}
/////////////////Setters//////////////
void Rectangle::setName(std::string s)
{
	name = s;
}
void Rectangle::setX1(int a)
{
	x1 = a;
}
void Rectangle::setX2(int b)
{
	x2 = b;
}
void Rectangle::setY1(int c)
{
	y1 = c;
}
void Rectangle::setY2(int d)
{
	y2 = d;
}
////////////Area and perimeter//////////////
int Rectangle::getPerim(Rectangle per)
{
	return (2 * (per.x2 - per.x1)) + (2 * (per.y2 - per.y1));
}
int Rectangle::getArea(Rectangle ar)
{
	return (ar.x2 - ar.x1) * (ar.y2 - ar.y1);
}
//////Can rectangle be formed///////
bool Rectangle::invalid()
{
	return (x1 == x2 || y1 == y2) ? false : true;
}
///////////////Overloading operators///////////////////
Rectangle Rectangle::operator+(const Rectangle& boxy)	//The + operator will assign the values from the right to the left.
{
	Rectangle addRect;
	name += boxy.name;
	addRect.name = name;
	addRect.x1 = x1; //stays same
	addRect.y1 = y1;
	addRect.x2 = boxy.x2;
	addRect.y2 = boxy.y2;

	if (boxy.x1 <= x1 && boxy.y1 <= y1)		//If 2nd rectangle is below and on the left of 1st rectangle.
	{
		addRect.x1 = boxy.x1;
		addRect.y1 = boxy.y1;
		addRect.x2 = x2;
		addRect.y2 = y2;
	}
	else if (boxy.x1 <= x1 && boxy.y1 >= y1) //If 2nd rectangle is above and on the left of 1st rectangle.
	{
		addRect.x1 = boxy.x1;
		addRect.y1 = y1;
		addRect.x2 = x2;
		addRect.y2 = boxy.y2;
	}
	else if (boxy.x1 >= x1 && boxy.y1 <= y1)	//If 2nd rectangle is below and on the right of 1st rectangle.
	{
		addRect.x1 = x1;
		addRect.y1 = boxy.y1;
		addRect.x2 = boxy.x2;
		addRect.y2 = y2;
	}

	return addRect;
}
Rectangle  operator-(const Rectangle &a, const Rectangle &boxxy)	//The - operator will form the new rectanlge from the overlap (if there is one).
{
	Rectangle subRect;
	subRect.name = a.name;
	subRect.x1 = boxxy.x1;
	subRect.y1 = boxxy.y1;
	subRect.x2 = a.x2;
	subRect.y2 = a.y2;

	if (boxxy.x1 <= a.x1 && boxxy.y1 <= a.y1)		//If 2nd rectangle is below and on the left of 1st rectangle.
	{
		subRect.x1 = a.x1;
		subRect.y1 = a.y1;
		subRect.x2 = boxxy.x2;
		subRect.y2 = boxxy.y2;
	}
	else if (boxxy.x1 <= a.x1 && boxxy.y1 >= a.y1)	//If 2nd rectangle is above and on the left of 1st rectangle.
	{
		subRect.x1 = a.x1;
		subRect.y1 = boxxy.y1;
		subRect.x2 = boxxy.x2;
		subRect.y2 = a.y2;
	}
	else if (boxxy.x1 >= a.x1 && boxxy.y1 <= a.y1)	//If 2nd rectangle is below and on the right of 1st rectangle.
	{
		subRect.x1 = boxxy.x1;
		subRect.y1 = a.y1;
		subRect.x2 = a.x2;
		subRect.y2 = boxxy.y2;
	}

	//If there is no overlap
	if ((a.x2 <= boxxy.x1 &&		//upper right
		a.y2 <= boxxy.y1) ||

		(a.x1 >= boxxy.x2 &&	//upper left
			a.y2 <= boxxy.y1) ||

			(a.x1 >= boxxy.x2 &&	//lower left
				a.y1 >= boxxy.y2) ||

				(a.x2 <= boxxy.x1 &&	//lower right
					a.y1 >= boxxy.y2))
	{
		subRect.x1 = 0;
		subRect.y1 = 0;
		subRect.x2 = 0;
		subRect.y2 = 0;
	}

	return subRect;
}
std::istream& operator>>(std::istream& input, Rectangle& coor)	//Gather coordinates for the bottom left and upper right
{
	input >> coor.x1 >> coor.y1 >> coor.x2 >> coor.y2;

	return input;
}
std::ostream& operator<<(std::ostream& output, Rectangle& coor)	//Print out data of the rectangles
{
	output << "The four coordinates of Recangle " << coor.name << " are: " << std::endl;
	output << "(" << coor.x1 << ", " << coor.y1 << "), ("
		<< coor.x1 << ", " << coor.y2 << "), ("
		<< coor.x2 << ", " << coor.y2 << "), and ("
		<< coor.x2 << ", " << coor.y1 << ")."
		<< std::endl << std::endl
		<< "The perimeter is " << coor.getPerim(coor) << " and the area is " << coor.getArea(coor) << ".";

	return output;
}

/////Destructor/////
Rectangle::~Rectangle()
{

}

