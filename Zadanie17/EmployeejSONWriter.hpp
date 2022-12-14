#pragma once
#include <vector>
#include "Employee.hpp"
#include "IEmployeeWriter.hpp"

class EmployeejSONWriter : public IEmployeeWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath, Type type);
	void writeLogin(std::vector<Employee> employees, std::string filePath);
	void writeSalary(std::vector<Employee> employees, std::string filePath);
	//void writeEmployeesLoginsPasswords(std::vector<Employee> employees, std::string filePath);
};