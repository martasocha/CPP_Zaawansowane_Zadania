#include "BigInt.hpp"
#include <algorithm>

BigInt::BigInt()
	: _value("0")
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
	int carry = 0;

	reverse(v._value.begin(), v._value.end());
	reverse(_value.begin(), _value.end());

	int commonSize = std::max(v._value.size(), _value.size()) + 1;

	for (unsigned int i = 0; i < commonSize; ++i)
	{
		int sum = v._value[i] + _value[i] + carry;
		carry = sum / 10;
		result._value.push_back(sum%10);
	}

	std::reverse(result._value.begin(), result._value.end());

	return result;
}

//BigInt BigInt::operator*(const BigInt& v)
//{
//	BigInt result;
//	int carry = 0;
//	int commonSize = std::max(v._value.size(), _value.size());
//
//	reverse(v._value.begin(), v._value.end());
//	reverse(_value.begin(), _value.end());
//
//	for (int i = 0; _value.size() <= 0; ++i)
//	{
//		for (int j = 0; v._value.size() <= 0; ++j)
//		{
//			int multiplication = (v._value[j] * _value[i]);
//			int multiplicationPlusCarry = (multiplication + carry) % 10;
//			carry = multiplicationPlusCarry / 10;
//			result._value.push_back(multiplicationPlusCarry);
//		}
//	}
//
//	std::reverse(result._value.begin(), result._value.end());
//
//	return BigInt();
//}
//
//BigInt BigInt::operator/(const BigInt& v)
//{
//	return BigInt();
//}

//int BigInt::length(const BigInt& v) const
//{
//	if (v._value == "0")
//		return 0;
//	return v._value.length();
//}
