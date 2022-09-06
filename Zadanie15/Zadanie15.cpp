// Zadanie15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CoinToss.hpp"
#include <vector>

int main()
{
    CoinToss cointoss(100);
    cointoss.checkStatistics();
    cointoss.findMax();
    cointoss.findMaxOR();
}
