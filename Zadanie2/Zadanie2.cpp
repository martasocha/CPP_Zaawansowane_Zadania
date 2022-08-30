// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int findCommonLetters(std::string str1, std::string str2)
{
    int countCommonLetters = 0;
    for (auto it = str1.begin(); it != str1.end(); ++it)
    {
        for (auto it2 = str2.begin(); it2 != str2.end(); ++it2)
        {
            if (*it == *it2)
            {
                countCommonLetters++;
            }
        }
    }
    return countCommonLetters;
}

int main()
{
    std::string str1 = "abcdefg";
    std::string str2 = "egf";
    std::cout << findCommonLetters(str1, str2);
}

