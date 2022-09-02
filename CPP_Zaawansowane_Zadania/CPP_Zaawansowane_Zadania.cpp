// Zadanie 1
// Napisz funkcjê, która odwróci podanego stringa.

#include <iostream>
#include <string>


std::string reverseString(std::string str)
{
    //std::string rev;
    //std::copy(str.rbegin(), str.rend(), std::back_inserter(rev));

    std::string rev = std::string(str.rbegin(), str.rend());
    return rev;
}

int main()
{
    int number;
    std::string str = "Hello World!";
    number = 3;
    std::cout << reverseString(str);
}

