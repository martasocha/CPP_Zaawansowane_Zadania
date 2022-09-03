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

BigInt BigInt::operator+(BigInt& v)
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

bool BigInt::operator==(const BigInt& v) const
{
	return !(this->_value < v._value) && !(v._value < this->_value);
}


BigInt BigInt::operator*(BigInt& v)
{
	int maxSize = v._value.size() + _value.size();
	BigInt result;
	for (int i = 0; i < maxSize; ++i)
	{
		result._value.push_back(0);
	}

	for (int i = v._value.size() - 1; i >= 0; --i)
	{
		for (int j = _value.size() - 1; j >= 0; j--)
		{
			result._value[maxSize - 2 - i - j] += v._value[i] * _value[j];
		}
	}
	for (int i = 0; i < result._value.size() - 1; i++)
	{
		result._value[i + 1] += result._value[i] / 10;
		result._value[i] %= 10;
	}

	while (result._value.back() == 0)
	{
		result._value.pop_back();
	}

	std::reverse(result._value.begin(), result._value.end());
	return result;
	//reverse(v._value.begin(), v._value.end());
	//reverse(_value.begin(), _value.end());

	//for (int i = 0; _value.size() > i; ++i)
	//{
	//	for (int j = 0; v._value.size() > j; ++j)
	//	{
	//		for (int k = 1; _value.size() > k; k * 10)
	//		{
	//			int multiplication = (v._value[j] * _value[i]);
	//			int multiplicationPlusCarry = (multiplication + carry) % 10;
	//			carry = multiplicationPlusCarry / 10;
	//			result._value.push_back(multiplicationPlusCarry * k);
	//		}
	//	}
	//}

	//std::reverse(result._value.begin(), result._value.end());

	return BigInt();
}

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
