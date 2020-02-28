#include "Rectangle.h"
#include <iostream>

//Constructor
Rectangle::Rectangle()
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
}

Rectangle::Rectangle(int aa, int bb, int cc, int dd)
{
	int x1 = aa;
	int y1 = bb;
	int x2 = cc;
	int y2 = dd;
}


int Rectangle::getPerim(Rectangle per)
{
	
	return (2 * (per.x2 - per.x1)) + (2 * (per.y2 - per.y1));
	
}
int Rectangle::getArea(Rectangle ar)
{
	return (ar.x2 - ar.x1) * (ar.y2 - ar.y1);
}
//////////////////////////////////
//Getters
string Rectangle::getName()
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
//////////////////////////
//Setters
void Rectangle::setName(string s)
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
/////////////
//Overloading operators
Rectangle Rectangle::operator+(const Rectangle &boxy)
{
	Rectangle addRect;
	addRect.x2 = boxy.x2;
	addRect.y2 = boxy.y2;
	addRect.x1 = x1; //stays same
	addRect.y1 = y1;

	return addRect;
}

istream & operator>>(istream &input, Rectangle &coor)
{
	input >> coor.x1 >> coor.y1 >> coor.x2 >> coor.y2;

	return input;
}

ostream & operator<<(ostream& output, Rectangle & coor)
{

	output << "The four corners of Recangle " << coor.name << " are: " << endl;
	output << "(" << coor.x1 << ", " << coor.y1 << "), ("
		<< coor.x1 << ", " << coor.y2 << "), ("
		<< coor.x2 << ", " << coor.y2 << "), and ("
		<< coor.x2 << ", " << coor.y1 << ").";

	return output;
}

//Destructor
Rectangle::~Rectangle()
{

}
