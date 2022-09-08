#pragma once
#include <vector>
#include "Employee.hpp"

class IEmployeeWriter
{
public:
	virtual void writeEmployees(std::vector<Employee> employees, std::string filePath) = 0;
};