// Zadanie5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringCesor.hpp"

int main()
{
    StringCensor stringcensor;
    stringcensor.addCensoredLetter('l');
    stringcensor.addCensoredLetter('m');
    stringcensor.addCensoredLetter('a');

    std::string str = "ala ma kota";
    std::cout << stringcensor.censor(str);

}

