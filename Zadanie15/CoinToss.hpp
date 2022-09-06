#pragma once
#include <vector>

enum class ResultOR { O, R };

class CoinToss
{
public:
	CoinToss(int howMany);
	ResultOR generateOR();
	void checkStatistics();
	void findMax();
	void findMaxOR();
private:
	std::vector<ResultOR> vectOfResults;
	int _howMany;
};