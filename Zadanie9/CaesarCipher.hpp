#pragma once
#include <string>


class CaesarCipher
{
public:
	std::string cypher(std::string text, int secretValue);
	std::string decepher(std::string text, int secretValue);
	std::string toUpper(std::string text);
	char cypherChar(char c, int secretValue);
	char decypherChar(char c, int secretValue);
private:
	//int _secretValue;
};