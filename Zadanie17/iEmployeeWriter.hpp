#pragma once
#include <vector>
#include "Employee.hpp"

class IEmployeeWriter
{
public:
	enum class Type { A, B };
	virtual void writeEmployees(std::vector<Employee> employees, std::string filePath, Type type) = 0;
	virtual void writeLogin(std::vector<Employee> employees, std::string filePath) = 0;
	virtual void writeSalary(std::vector<Employee> employees, std::string filePath) = 0;
};