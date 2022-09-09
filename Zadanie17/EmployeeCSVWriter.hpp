#pragma once
#include <vector>
#include "Employee.hpp"
#include "IEmployeeWriter.hpp"

class EmployeeCSVWriter : public IEmployeeWriter
{
public: 
	void writeEmployees(std::vector<Employee> employees, std::string filePath, Type type);
};