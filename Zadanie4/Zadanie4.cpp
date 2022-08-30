// Zadanie4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MorseCodeTranslator.hpp"

int main()
{
    std::string text = "HEJ";
    MorseCodeTranslator translator;
    std::cout << translator.toMorseCode(text);
}

