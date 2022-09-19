#pragma once
#include "Player.hpp"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer();
	int symbolSelect() override;
};