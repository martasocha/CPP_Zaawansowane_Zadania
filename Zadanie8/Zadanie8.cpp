#include <iostream>
#include <vector>
#include "Rectangle.hpp"
#include "RectangleGenerator.hpp"
#include "RectangleManager.hpp"

int main()
{
	RectangleManager manager(100);
	manager.printRectangles();

	std::cout << std::endl;
	std::cout << "Count Rectangle Bigger Then 10: ";
	std::cout << manager.countRectangleBiggerThen(10) << std::endl;

	std::cout << std::endl;
	std::cout << "Copy Rectangle: " << std::endl;
	std::vector<Rectangle> vect = manager.copyRectangles();

	std::cout << std::endl;
	std::cout << "Sort Area Rectangle: " << std::endl;
	manager.sortAreaDescending();
	manager.printRectangles();

	std::cout << std::endl;
	//std::cout << "Delete Invalid Rectangle: " << std::endl;
	//manager.deleteInvalid();
	//manager.printRectangles();
}


