#pragma once
#include <string>
#include "Player.hpp"

class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string name);
	int symbolSelect() override;
private:
	std::string _name;
};