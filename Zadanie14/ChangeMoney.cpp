#include "ChangeMoney.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>


void ChangeMoney::print(int n, int optimalChange)
{
    double n1 = static_cast<double>(n);
    n1 = n1 / 100;
    std::cout << "Nominal " << n1 << ": " << optimalChange << std::endl;
}


void ChangeMoney::changeMoney(double amount)
{
    std::vector<int>denominationsInt;
    std::vector<int>numOfDenominaton;

    auto ChangeToInt = [&](double n)
    {
        int n1 = static_cast<int>(n * 100);
        denominationsInt.push_back(n1);
    };
    std::for_each(denominations.begin(), denominations.end(), ChangeToInt);

    amount *= 100;
    int amountInt = static_cast<int> (amount);

    auto checkRest = [&](int n)
    {
         int numOfDenom = amountInt / n;
         amountInt = amountInt % n;
         print(n, numOfDenom);
         //numOfDenominaton.push_back(numOfDenom);

         return amountInt;
    };

     std::for_each(denominationsInt.begin(), denominationsInt.end(), checkRest);

        //return numOfDenominaton;
}
