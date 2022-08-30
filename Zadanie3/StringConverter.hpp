#pragma once
#include <string>

class StringConverter
{
public:
	static std::string toCamelCase(std::string);
	static std::string toSnakeCase(std::string);
};