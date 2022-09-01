#include "PrimeNumbers.hpp"

#include <algorithm>
#include <iostream>

std::vector<int> PrimeNumbers::lisOfNums = {};
std::vector<int> PrimeNumbers::lisOfPrimeNums = {};
std::vector<int> PrimeNumbers::lisOfNoPrimeNums = {};

std::vector<int> PrimeNumbers::FindPrimeNumbers()
{
	auto findPrimeNums = [&](int number)
	{
		if (isPrimeNumber(number) == true)
		{
			lisOfNoPrimeNums.push_back(number);
		}
		else
		{
			lisOfPrimeNums.push_back(number);
		}
	};
	std::for_each(lisOfNums.begin(), lisOfNums.end(), findPrimeNums);

	return lisOfPrimeNums;
}

void PrimeNumbers::createListofNumbs()
{
	for (unsigned int i = 1; i <= 1000; ++i)
	{
		lisOfNums.push_back(i);
	}
}

bool PrimeNumbers::isPrimeNumber(int n)
{
	for (unsigned int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			return true;
		}
	}
	return false;
}

void PrimeNumbers::printListOfNums(std::vector<int> list)
{
	for (auto n: list)
	{
		std::cout << n << ", ";
	}
	std::cout << std::endl;
}
