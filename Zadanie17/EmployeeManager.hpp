#pragma once
#include "Employee.hpp"
#include <vector>

class EmployeeManager
{
public:
	std::string generateLogin();
private:
	std::vector<Employee> employees;

};