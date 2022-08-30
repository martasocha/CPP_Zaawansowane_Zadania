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
    std::string str = "Hello World!";
    std::cout << reverseString(str);
}

