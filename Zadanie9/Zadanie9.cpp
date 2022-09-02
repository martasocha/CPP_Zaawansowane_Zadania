#include <iostream>
#include "CaesarCipher.hpp"
#include <string>

int main()
{
    CaesarCipher caesar;
    std::string text= "Wxyz Ala ma kota, a kot ma Ale";
    text = caesar.cypher(text, 5);
    std::cout << text << std::endl;
    std::cout << caesar.decepher(text, 5);
}

