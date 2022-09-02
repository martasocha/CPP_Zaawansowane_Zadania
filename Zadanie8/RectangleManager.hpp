#pragma once
#include <vector>
#include "Rectangle.hpp"


class RectangleManager
{
public:
	RectangleManager(int howMany);
	void printRectangles();
	size_t countRectangleBiggerThen(int area);
	std::vector<Rectangle> getRectangles();
	std::vector<Rectangle> copyRectangles();
	void sortAreaDescending();
	//void deleteInvalid();

private:
	std::vector<Rectangle> vectOfRectangles;
};