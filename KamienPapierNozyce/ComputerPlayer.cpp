#include "ComputerPlayer.hpp"
#include <random>
#include <iostream>

ComputerPlayer::ComputerPlayer()
{
}

int ComputerPlayer::symbolSelect()
{
	std::cout << "Current player: Computer " << std::endl;

	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_int_distribution<int> distrib(0, 2);
	int numOfSymbol = distrib(engine);

	if (numOfSymbol == 1)
	{
		std::cout << "Computer choose Paper" << std::endl;
	}
	else if (numOfSymbol == 2)
	{
		std::cout << "Computer choose Scissors" << std::endl;
	}
	else
	{
		std::cout << "Computer choose Rock" << std::endl;
	}

	return numOfSymbol;
}
