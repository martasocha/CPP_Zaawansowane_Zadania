#include <iostream>
#include "SlotMachine.hpp"

int main()
{
    int numOfAttempts = 0;
    do 
    {
        SlotMachine slotMachine;
        slotMachine.gen5Symbols();
        std::cout << slotMachine.countPoints() << std::endl;

        numOfAttempts++;
    } while (numOfAttempts != 3);
}
