#include "Rectangle.hpp"

Rectangle::Rectangle(int side1, int side2)
    : _side1(side1), _side2(side2)
{
}

int Rectangle::calculateField()
{
    return _side1 * _side2;
}

int Rectangle::getSide1()
{
    return _side1;
}

int Rectangle::getSide2()
{
    return _side2;
}

int Rectangle::getField()
{
    return calculateField();
}
