#include "BigInt.hpp"
#include <algorithm>

BigInt::BigInt()
	: _value(0)
{
}

BigInt::BigInt(long long value)
{
	do {
		_value.push_back(value % 10);
		value /= 10;

	} while (value);
}

BigInt::BigInt(const BigInt& other)
{
	this->_value = other._value;
}

BigInt BigInt::operator=(const BigInt& v)
{
	if (this != &v)
	{
		this->_value = v._value;
	}

	return *this;
}

BigInt BigInt::operator+(const BigInt& v)
{
	BigInt result;
	
	int commonSize = std::max(v._value.size(), _value.size());

	for (int i = commonSize; i < 0; --i)
	{
		result._value.push_back(v._value[i] + _value[i]);
	}

	std::reverse(result._value.begin(), result._value.end());

	return result;
}

BigInt BigInt::operator*(const BigInt& v)
{
	BigInt result;
	int carry = 0;

	for (int i = v._value.length() - 1; i >= 0; i--)
	{
		int sum = v._value[i] * _value[i] + carry;
		carry = sum / 10;
		result._value.push_back(sum % 10);
	}

	std::reverse(result._value.begin(), result._value.end());

	return BigInt();
}

int BigInt::length(const BigInt& v) const
{
	if (v._value == "0")
		return 0;
	return v._value.length();
}
