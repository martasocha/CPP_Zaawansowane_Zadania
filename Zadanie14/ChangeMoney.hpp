#pragma once
#include <vector>

class ChangeMoney
{
public:
	void changeMoney(double amount);
	void print(int n, int optimalChange);
private:
	std::vector<double> rest;
	std::vector<double> denominations = { 200.0,100.0,50.0,20.0,10.0,5.0,2.0,1.0,0.50,0.20,0.10,0.05,0.02,0.01 };

};