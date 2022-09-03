#pragma once


class GuessTheNumber
{
public:
	GuessTheNumber();
	int generateNumber();
	bool guessNumber(int number);
	int getSecretNumber();
private:
	int _secretNumber;
};