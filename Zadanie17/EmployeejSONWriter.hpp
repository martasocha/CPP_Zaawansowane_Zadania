#pragma once
#include <vector>
#include "Employee.hpp"

class EmployeejSONWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath);
};
