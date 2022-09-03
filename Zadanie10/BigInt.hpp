#pragma once
#include <string>
#include <vector>

class BigInt
{
public:
	BigInt();
	BigInt(long long value);
	BigInt(const BigInt& other);
	//std::string toString();
	BigInt operator=(const BigInt& v);
	BigInt operator+(BigInt& v);
	BigInt operator*(BigInt& v);
	//BigInt operator/(BigInt& v);
	//BigInt operator%(BigInt& v);

	//int length(const BigInt& v) const;
	bool operator==(const BigInt& v) const;

private:
	//std::vector<short> _value;
	std::string _value;
};