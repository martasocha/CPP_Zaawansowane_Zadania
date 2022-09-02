#include "RectangleGenerator.hpp"
#include <random>

RectangleGenerator::RectangleGenerator(int number, int number2)
    : _number(number), _number2(number2)
{
}

Rectangle RectangleGenerator::generateRectangle()
{

    std::random_device r;
    std::default_random_engine engine(r());

    std::uniform_int_distribution<int> distribution(getNum1(), getNum2());

    int side1 = distribution(engine);
    int side2 = distribution(engine);

    Rectangle rect(side1, side2);

    return rect;
}

int RectangleGenerator::getNum1()
{
    return _number;
}

int RectangleGenerator::getNum2()
{
    return _number2;
}
