#pragma once
#include <iostream>
#include <string> //Remove later

using namespace std; //Delete later

class Rectangle{
private:
	string name;
	int x1, x2, y1, y2;
	int x3, x4, y3, y4; //Probably delete since we dont need them
	
	//Add static variable maybe
public:
	//Constructor:
	Rectangle();
	Rectangle(int aa, int bb, int cc, int dd);

	int getPerim(Rectangle per);
	int getArea(Rectangle ar);

	//Accessor
	string getName();
	int getX1();
	int getX2();
	int getY1();
	int getY2();

	//Mutator
	void setName(string s);
	void setX1(int a);
	void setX2(int b);
	void setY1(int c);
	void setY2(int d);


	//Overload the >> opperator to get the coordinates,
	friend istream & operator>>(istream &input, Rectangle &coor);

	//Overload the << operator so that it prints out the 4 corners of the rctangle;
	friend ostream & operator<<(ostream &output, Rectangle &coor);

	//Overload the + operator so that it will add rectanles and their empty spaces.
	Rectangle operator+(const Rectangle &boxy);


	//Overload the - operator so that it would create a new rectangle from the two and subtract the area in the middle. This is also a friend function.



	//Destructor
	~Rectangle();




};