#include <iostream>
#include "GuessTheNumber.hpp"

bool isEqual(int num, int secretNumber)
{
    return num == secretNumber;
}


int main()
{
    int num;
    GuessTheNumber guess;

    do
    {
        std::cout << "Podaj liczbe: ";
        std::cin >> num;
        guess.guessNumber(num);

    } while (!isEqual(num,guess.getSecretNumber()));
}


