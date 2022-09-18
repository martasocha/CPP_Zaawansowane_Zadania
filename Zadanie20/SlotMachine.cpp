#include "SlotMachine.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

void SlotMachine::gen5Symbols()
{
	for (unsigned int i = 0; i < 5; ++i)
	{
		std::random_device r;
		std::default_random_engine engine(r());
		std::uniform_int_distribution<int> distrib(0, symbols.size()-1);
		vectOfGenerateSymbols.push_back(symbols[distrib(engine)]);
	}

	for (auto n : vectOfGenerateSymbols)
	{
		std::cout << n << ", ";
	}
}

int SlotMachine::countPoints()
{
	int points = 0;
	checkSymbols();
	for (auto it = mapOfSymbols.begin(); it != mapOfSymbols.end(); ++it)
	{
		if (it->second <= 2 && it->first != '*')
		{
			points += 0;
		}
		if (it->second > 2)
		{
			int multiplyPoints = pow(findSymbol(it->first), it->second);
			points += multiplyPoints;
		}
		if (it->first == '*')
		{
			points += 1000;
		}
	}

	return points;
}

void SlotMachine::checkSymbols()
{
	auto countSymbols = [&](char symbol)
	{
		for (auto it = mapOfSymbols.begin(); it!= mapOfSymbols.end(); ++it)
		{
			if (symbol == it->first)
			{
				it->second += 1;
			}
		}
	};
	std::for_each(vectOfGenerateSymbols.begin(), vectOfGenerateSymbols.end(), countSymbols);
}

int SlotMachine::findSymbol(char symbol)
{
	int points = 0;
	points = mapOfPoints.at(symbol);
	return points;

}
