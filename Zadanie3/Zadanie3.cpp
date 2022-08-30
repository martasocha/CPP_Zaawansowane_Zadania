// Zadanie3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StringConverter.hpp"

int main()
{
    
    std::string strCamel = "camelCase";
    std::string strSnake = "snake_case";
    StringConverter converter;
    std::cout << converter.toSnakeCase(strCamel) << std::endl;
    std::cout << converter.toCamelCase(strSnake);
}

