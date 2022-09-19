#include "Game.hpp"
#include <iostream>
#include <memory>


Game::Game(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int numOfRounds)
	: _player1(player1), _player2(player2), _numOfRounds(numOfRounds)
{
	_currentPlayer = _player1;

}

void Game::changePlayers()
{
	if (_player1 == _currentPlayer)
	{
		_currentPlayer = _player2;
	}
	else
	{
		_currentPlayer = _player1;
	}
}

void Game::play()
{
	int round = 0;
	do
	{

		int symbol1 = _currentPlayer->symbolSelect();
		changePlayers();
		int symbol2 = _currentPlayer->symbolSelect();
		compareSymbols(symbol1, symbol2);
		
		round++;
	} while (_numOfRounds != round);
}


void Game::compareSymbols(int symbol1, int symbol2)
{
	if (symbol1 == symbol2)
	{
		setWinner(0);
	}
	if (symbol1 == static_cast<int>(Symbol::Paper))
	{
		if (symbol2 == static_cast<int>(Symbol::Scissors))
		{
			setWinner(2);
		}
		if (symbol2 == static_cast<int>(Symbol::Rock))
		{
			setWinner(1);
		}
	}

	if (symbol1 == static_cast<int>(Symbol::Scissors))
	{
		if (symbol2 == static_cast<int>(Symbol::Paper))
		{
			setWinner(1);
		}
		if (symbol2 == static_cast<int>(Symbol::Rock))
		{
			setWinner(2);
		}
	}

	if (symbol1 == static_cast<int>(Symbol::Rock))
	{
		if (symbol2 == static_cast<int>(Symbol::Scissors))
		{
			setWinner(1);
		}
		if (symbol2 == static_cast<int>(Symbol::Paper))
		{
			setWinner(2);
		}
	}

}

void Game::setWinner(int numberOfPlayer)
{
	if (numberOfPlayer == 0)
	{
		std::cout << "Nobody wins" << std::endl;
	}
	else if (numberOfPlayer == 1)
	{
		std::cout << "Player number 1 wins" << std::endl;
	}
	else
	{
		std::cout << "Player number 2 wins" << std::endl;
	}
}

