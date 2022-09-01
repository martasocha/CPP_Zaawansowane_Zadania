#pragma once
#include <vector>
#include <list>

class PrimeNumbers
{
public:
	std::vector<int> FindPrimeNumbers();
	void createListofNumbs();
	bool isPrimeNumber(int n);
	void printListOfNums(std::vector<int> list);


	static std::vector<int> lisOfNums;
	static std::vector<int> lisOfPrimeNums;
	static std::vector<int> lisOfNoPrimeNums;
};