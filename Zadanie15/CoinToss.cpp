#include "CoinToss.hpp"
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

CoinToss::CoinToss(int howMany)
	: _howMany(howMany)
{
	for (unsigned int i = 1; i <= _howMany; ++i)
	{
		ResultOR n = generateOR();

		if (n == ResultOR::O)
		{
			std::cout << "O";
			vectOfResults.push_back(n);
		}
		else
		{
			std::cout << "R";
			vectOfResults.push_back(n);
		}
		if (i % 20 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

ResultOR CoinToss::generateOR()
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_int_distribution<int> intDistro(0, 1);

	int number = intDistro(engine);

	if (number == 0)
	{
		return ResultOR::O;
	}
	else
	{
		return ResultOR::R;
	}
}

void CoinToss::checkStatistics()
{
	double countO = std::count_if(vectOfResults.begin(), vectOfResults.end(), [](ResultOR n) { return n == ResultOR::O; });
	double countR = std::count_if(vectOfResults.begin(), vectOfResults.end(), [](ResultOR n) { return n == ResultOR::R; });
	double O = countO / _howMany *100;
	std::cout << "Procentowym udzial Orlow - O: " << O << "%" <<std::endl;
	double R = countR / _howMany *100;
	std::cout << "Procentowym udzial Reszek - R: " << R << "%" << std::endl;
}

void CoinToss::findMax()
{
	int countR = 0;
	int countO = 0;
	int maxO = 0;
	int iO = 0;
	int iR = 0;
	int maxR = 0;
	for (unsigned int i = 0; i < vectOfResults.size(); ++i)
	{
		if (vectOfResults.at(i) == ResultOR::O)
		{
			if (countR > maxR)
			{
				maxR = countR;
				iR = i + 1 - maxR;
			}
			countR = 0;
			countO++;
		}
		else
		{
			if (countO > maxO)
			{
				maxO = countO;
				iO = i + 1 - maxO;
			}
			countO = 0;
			countR++;
		}
	}
	std::cout << "Najdluzszy ciag samych orlow : " << maxO << ", ciag zaczyna sie od proby: " << iO << std::endl;
	std::cout << "Najdluzszy ciag samych reszek : " << maxR << ", ciag zaczyna sie od proby: " << iR << std::endl;

}

void CoinToss::findMaxOR()
{
	ResultOR temp = vectOfResults.at(0);
	int count = 1;
	int max = 0;
	int number = 0;

	for (unsigned int i = 0; i < vectOfResults.size(); ++i)
	{
		if (vectOfResults.at(i) == ResultOR::O)
		{
			if (temp == ResultOR::R)
			{
				temp = ResultOR::O;
				count++;
			}
			else
			{
				if (count > max)
				{
					max = count;
					number = i + 1 - max;
				}
				count = 1;
			}
		}
		else
		{
			if (temp == ResultOR::O)
			{
				count++;
				temp = ResultOR::R;
			}
			else
			{
				if (count > max)
				{
					max = count;
					number = i + 1 - max;
				}
				count = 1;
			}
		}
	}
	std::cout << "Najdluzszy ciag OR wynosi: " << max << ", ciag zaczyna sie od proby: " << number << std::endl;
}
