#include "StringConverter.hpp"
#include <algorithm>

std::string StringConverter::toCamelCase(std::string snakeString)
{
	std::string camelString;
	for (auto it = snakeString.begin(); it != snakeString.end(); ++it)
	{

		if (it != snakeString.begin() && findFloor(*(it - 1)))
		{
			char letter = changeToBig(*it);
			camelString.push_back(letter);
		}
		else if (!findFloor(*it))
		{
			camelString.push_back(*it);
		}
	}
	return camelString;
}

std::string StringConverter::toSnakeCase(std::string camelString)
{
	std::string snakeString;
	for (auto it = camelString.begin(); it != camelString.end(); ++it)
	{
		if (isBiggerLetter(*it))
		{
			snakeString.push_back('_');
			char letter = changeToSmall(*it);
			snakeString.push_back(letter);
		}
		else
		{
			snakeString.push_back(*it);
		}
	}
	return snakeString;
}

bool StringConverter::isBiggerLetter(char c)
{
	return (c >= 65 && c <= 90);
}

char StringConverter::changeToSmall(char c)
{
	return std::tolower(c);
}

char StringConverter::changeToBig(char c)
{
	return std::toupper(c);
}

bool StringConverter::findFloor(char c)
{
	return c == 95;
}
