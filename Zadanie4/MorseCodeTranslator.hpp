#pragma oncF
#include <string>
#include <map>

class MorseCodeTranslator
{
public:
	std::string toMorseCode(std::string);
	std::string fromMorseCode(std::string);
	std::string translate(char c);
	char translate(std::string);
	bool isSpace(char c);
private:
	std::map<char, std::string> mapOfLetters{ {'A' ,".- "}, {'B' ,"-..."}, {'C' ,"-.-."}, {'D' ,"-.."}, {'E' ,"."}, {'F' ,"..-."}, {'G' ,"--."}, {'H' ,"...."}, {'I' ,".."}, {'J' ,".---"} };
	std::map<std::string, char> mapOfMorse { {".- ",'A'}, {"-...",'B'}, {"-.-.",'C'}, {"-..",'D'}, {".", 'E'}, {"..-.", 'F' }, {"--.", 'G' }, {"....", 'H'}, {"..", 'I'}, {".---", 'J' } };
};