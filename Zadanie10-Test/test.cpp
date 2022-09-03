#include "pch.h"

#include "../Zadanie10/BigInt.hpp"


TEST(TestBigInt, AddBigInt)
{
	BigInt bInt1(2);
	BigInt bInt2(4);
	EXPECT_EQ(bInt1 + bInt2, 6);
}

TEST(TestBigInt, AddBigInt2)
{
	BigInt bInt1(222);
	BigInt bInt2(444);
	EXPECT_EQ(bInt1 + bInt2, 666);
}