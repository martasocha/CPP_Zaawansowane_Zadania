#pragma once
#include <iostream>
#include "Rectangle.hpp"

class RectangleGenerator
{
public:
    RectangleGenerator(int number, int number2);
    Rectangle generateRectangle();
    int getNum1();
    int getNum2();
private:
    int _number;
    int _number2;
};