#pragma once
#include <string>
#include <set>

class StringCensor
{
public:
	void addCensoredLetter(char c);
	std::string censor(std::string str);
	bool checkLetter(char c);
	std::set<char> getLetters();
	char changeLetter(char c);
private:
	std::set<char> _letters;
};