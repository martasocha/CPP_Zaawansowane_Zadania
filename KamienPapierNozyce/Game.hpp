#pragma once
#include <string>
#include "Player.hpp"
#include <memory>


class Game
{
public:
	enum class Symbol { Rock, Paper, Scissors };
	Game(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int numOfRounds);

	void changePlayers();

	void play();

	void compareSymbols(int symbol1, int symbol2);
	void setWinner(int numberOfPlayer);
	int _numOfRounds;
private:
	std::shared_ptr<Player> _player1;
	std::shared_ptr<Player> _player2 ;
	std::shared_ptr<Player> _currentPlayer;
};