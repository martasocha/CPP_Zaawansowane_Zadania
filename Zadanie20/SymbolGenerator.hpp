#pragma once
#include <string>

class SymbolGenerator
{
public:
	char generateSymbol();
private:
	std::string symbols = "!@#$%^&*";
};