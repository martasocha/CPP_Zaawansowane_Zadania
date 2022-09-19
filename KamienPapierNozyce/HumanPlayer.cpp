#include "HumanPlayer.hpp"
#include <iostream>

HumanPlayer::HumanPlayer(std::string name)
	: _name(name)
{
}

int HumanPlayer::symbolSelect()
{
	std::cout << "Current player: " << _name << std::endl;

	std::cout << "Enter your symbol. 0- Rock, 1- Paper, 2- Scissors ";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		std::cout << "Player choose Paper" << std::endl;
	}
	else if (choice == 2)
	{
		std::cout << "Player choose Scissors" << std::endl;
	}
	else
	{
		std::cout << "Player choose Rock" << std::endl;
	}

	return choice;

	//enum class Symbol {Rock, Paper, Scissors};
}
