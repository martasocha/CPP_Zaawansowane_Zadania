#pragma once


class GuessTheNumber
{
public:
	enum class Result { WIEKSZE, MNIEJSZE, ROWNE };
	GuessTheNumber();
	int generateNumber();
	enum class Result guessNumber(int number);
	int getSecretNumber();
private:
	int _secretNumber;
};