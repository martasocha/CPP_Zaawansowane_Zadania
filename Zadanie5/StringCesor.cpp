#include "StringCesor.hpp"
#include <algorithm>

void StringCensor::addCensoredLetter(char c)
{
	_letters.insert(c);
}

std::string StringCensor::censor(std::string str)
{
	std::string newStr{};
	auto censorChar = [&](char c)
	{
		if (checkLetter(c) == true)
		{
			c = changeLetter(c);
		}
		newStr += c;
	};
	std::for_each(str.begin(), str.end(), censorChar);

	return newStr;
}

bool StringCensor::checkLetter(char c)
{
	std::set<char> set = getLetters();
	for (auto it = set.begin(); it != set.end(); ++it)
	{
		if (c == (*it))
		{
			return true;
		}
	}
	return false;
}

std::set<char> StringCensor::getLetters()
{
	return _letters;
}

char StringCensor::changeLetter(char c)
{
	return '*';
}
