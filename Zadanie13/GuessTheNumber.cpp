#include "GuessTheNumber.hpp"
#include <random>
#include <iostream>

GuessTheNumber::GuessTheNumber()
{
    this->_secretNumber = generateNumber();
}

int GuessTheNumber::generateNumber()
{
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> distrib(1, 100);
    int number = distrib(engine);

    return number;
}

GuessTheNumber::Result GuessTheNumber::guessNumber(int number)
{
    if (number == _secretNumber)
    {
        return Result::ROWNE;
    }
    else if (number < _secretNumber)
    {
        return Result::WIEKSZE;
    }
    else
    {
        return Result::MNIEJSZE;
    }
}

int GuessTheNumber::getSecretNumber()
{
    return _secretNumber;
}
