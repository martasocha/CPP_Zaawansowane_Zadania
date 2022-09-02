#pragma once

class Rectangle
{
public:
	Rectangle(int side1, int side2);
	int calculateField();
	int getSide1();
	int getSide2();
	int getField();
private:
	int _side1;
	int _side2;
};