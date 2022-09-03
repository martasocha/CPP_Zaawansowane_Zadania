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
        GuessTheNumber::Result r = guess.guessNumber(num);
        switch (r)
        {
        case GuessTheNumber::Result::ROWNE:
            std::cout << "Gratulacje zgadles/as!" << std::endl;
            break;
        case GuessTheNumber::Result::MNIEJSZE:
            std::cout << "Liczba jest mniejsza od podanej" << std::endl;
            break;
        case GuessTheNumber::Result::WIEKSZE:
            std::cout << "Liczba jest wieksza od podanej" << std::endl;
            break;
        }

    } while (!isEqual(num,guess.getSecretNumber()));
}


