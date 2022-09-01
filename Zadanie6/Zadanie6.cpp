#include <iostream>
#include "PrimeNumbers.hpp"

int main()
{
    PrimeNumbers numbers;
    numbers.createListofNumbs();
    numbers.FindPrimeNumbers();
    numbers.printListOfNums(PrimeNumbers::lisOfPrimeNums);
    numbers.printListOfNums(PrimeNumbers::lisOfNoPrimeNums);
}
