
#include <iostream>
#include <vector>
#include <algorithm>

void printVect(std::vector<double> vect)
{
    std::for_each(vect.begin(), vect.end(), [](int n) { std::cout << n << ", "; });
}

int main()
{
    std::vector<double> denominations = { 200.0,100.0,50.0,20.0,10.0,5.0,2.0,1.0,0.50,0.20,0.10,0.05,0.02,0.01 };
    std::vector<int> denominationsInt;
    auto Lambda = [&](double n)
    {
        //n *= 100;
        int n1 = static_cast<int>(n*100); 
        denominationsInt.push_back(n1);
    };

    std::for_each(denominations.begin(), denominations.end(), Lambda);

    printVect(denominationsInt);

}