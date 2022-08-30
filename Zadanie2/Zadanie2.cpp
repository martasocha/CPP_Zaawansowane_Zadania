// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <set>

int findCommonLetters(std::string str1, std::string str2)
{
    std::set<char> set;
    int countCommonLetters = 0;
    for (auto it = str1.begin(); it != str1.end(); ++it)
    {
        for (auto it2 = str2.begin(); it2 != str2.end(); ++it2)
        {
            if (*it == *it2)
            {
                set.insert(*it2);
            }
        }
    }
    return set.size();
}

int main()
{
    std::string str1 = "kasia";
    std::string str2 = "tasiaaaassk";
    std::cout << findCommonLetters(str1, str2);
}

