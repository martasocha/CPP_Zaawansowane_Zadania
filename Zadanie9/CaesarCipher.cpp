#include "CaesarCipher.hpp"
#include <algorithm>

std::string CaesarCipher::cypher(std::string text, int secretValue)
{
	std::string cypherText = toUpper(text);

	for (auto it = cypherText.begin(); it != cypherText.end(); ++it)
	{
		(*it) = cypherChar(*it, secretValue);
	}

	return cypherText;
}

std::string CaesarCipher::decepher(std::string text, int secretValue)
{
	std::string decypherText = toUpper(text);

	for (auto it = decypherText.begin(); it != decypherText.end(); ++it)
	{
		(*it) = decypherChar(*it, secretValue);
	}

	return decypherText;
}

std::string CaesarCipher::toUpper(std::string text)
{
	for (char& c : text) {
		c = std::toupper(c);
	}
	return text;
}

char CaesarCipher::cypherChar(char c, int secretValue)
{
	if (c >= 65 && c <= 90)
	{
		if (c + secretValue <= 90)
		{
			c += secretValue;
		}
		else
		{
			c = 64 + (secretValue - (90 - c));
		}
	}
	return c;
}

char CaesarCipher::decypherChar(char c, int secretValue)
{
	if (c >= 65 && c <= 90)
	{
		if (c - secretValue >= 65)
		{
			c -= secretValue;
		}
		else
		{
			c = 91 - (secretValue - (c - 65));
		}
	}
	return c;
}
