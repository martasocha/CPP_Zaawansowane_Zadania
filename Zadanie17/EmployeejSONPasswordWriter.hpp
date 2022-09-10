#pragma once
#include <vector>
#include "Employee.hpp"
#include "IEmployeeWriter.hpp"

class EmployeejSONPasswordWriter : public IEmployeeWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath, Type type);
	//void writeEmployeesLoginsPasswords(std::vector<Employee> employees, std::string filePath);
};