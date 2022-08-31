#include "MorseCodeTranslator.hpp"
#include <algorithm>

std::string MorseCodeTranslator::toMorseCode(std::string text)
{
    std::string morseCode{};
    auto changeToMorseCode = [&](char c)
    {
        morseCode += translate(c);
        morseCode += ' ';
    };

    std::for_each(text.begin(), text.end(), changeToMorseCode);
    return morseCode;
}

std::string MorseCodeTranslator::fromMorseCode(std::string morseCode)
{
    std::string text{};
    char letter;
    std::string temp{};
    auto changeFromMorseCode = [&](char c)
    {
        if (c != ' ')
        {
            temp += c;
        }
        else if (c == ' ')
        {
            letter = translate(temp);
            text += letter;
            temp = "";
        }
    };

    std::for_each(morseCode.begin(), morseCode.end(), changeFromMorseCode);
    return text;
}

std::string MorseCodeTranslator::translate(char c)
{
    std::string morseCode{};
    morseCode = mapOfLetters.at(c);
    //morseCode = mapOfLetters.find(c)->second;
    return morseCode;
}

char MorseCodeTranslator::translate(std::string morse)
{
    char letter;
    letter = mapOfMorse.at(morse);
    //letter = mapOfMorse.find(morse)->second;
    return letter;
}

bool MorseCodeTranslator::isSpace(char c)
{
    return c == ' ';
}

