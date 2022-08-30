#include "MorseCodeTranslator.hpp"
#include <algorithm>

std::string MorseCodeTranslator::toMorseCode(std::string text)
{
    std::string morseCode{};
    auto changeToMorseCode = [&](char c)
    {
        morseCode += translate(c);
    };

    std::for_each(text.begin(), text.end(), changeToMorseCode);
    return morseCode;
}

std::string MorseCodeTranslator::fromMorseCode(std::string)
{
    return std::string();
}

std::string MorseCodeTranslator::translate(char c)
{
    std::string morseCode{};
    morseCode = mapOfLetters.at(c);
    return morseCode;
}

