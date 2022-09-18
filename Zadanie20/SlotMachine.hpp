#pragma once
#include <vector>
#include <map>
#include <string>

class SlotMachine
{
public:
	void gen5Symbols();
	int countPoints();
	void checkSymbols();
	int findSymbol(char symbol);
private:
	std::string symbols = "!@#$%^&*";
	std::vector<char> vectOfGenerateSymbols;
	std::map<char, int> mapOfPoints = { {'!', 1}, {'@', 5}, {'#', 10},  {'$', 25}, {'%', 50}, {'^', 100}, {'&', 200}, {'*', 1000}};
	std::map<char, int> mapOfSymbols = { {'!', 0}, {'@', 0}, {'#', 0},  {'$', 0}, {'%', 0}, {'^', 0}, {'&', 0}, {'*', 0}};
};