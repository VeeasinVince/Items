#pragma once
//Vincent Nguyen Lab 3
#include <iostream>
#include <string> //Remove later

class Rectangle {
private:
	std::string name;		//To hold name
	int x1, x2, y1, y2;		//To hold coordinates

public:
	//Constructor:
	Rectangle();								
	Rectangle(int aa, int bb, int cc, int dd);	//Constructor w/ list

	//Accessor
	std::string getName();
	int getX1();
	int getX2();
	int getY1();
	int getY2();

	//Mutator
	void setName(std::string s);
	void setX1(int a);
	void setX2(int b);
	void setY1(int c);
	void setY2(int d);

	int getPerim(Rectangle per);	//Perimeter
	int getArea(Rectangle ar);		//Area

	//Overload the >> opperator to get the coordinates,
	friend std::istream& operator>>(std::istream& input, Rectangle& coor);

	//Overload the << operator so that it prints out the 4 corners of the rctangle;
	friend std::ostream& operator<<(std::ostream& output, Rectangle& coor);

	//Overload the + operator so that it will add rectangles and their empty spaces.
	Rectangle operator+(const Rectangle& boxy);

	//Overload the - operator so that it would create a new rectangle from the two and subtract the area in the middle. This is also a friend function.
	friend Rectangle operator-(const Rectangle &a, const Rectangle &boxxy);

	//Checks if rectangle can be formed
	bool invalid();

	//Destructor
	~Rectangle();

};

