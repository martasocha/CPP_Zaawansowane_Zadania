#include "EmployeeCSVWriter.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

void EmployeeCSVWriter::writeEmployees(std::vector<Employee> employees, std::string filePath, Type type)
{
	std::fstream file(filePath, std::ios::out);

	if (file.is_open())
	{
		for (unsigned int i = 0; i < employees.size(); ++i)
		{
			if (file.good())
			{
				if (type == Type::A)
				{
					file << employees[i].getLogin() << ", " << employees[i].getEmail() << ", " << employees[i].getPassword() << "\n";
				}
				else if (type == Type::B)
				{
					file << employees[i].getName() << ", " << employees[i].getSurname() << ", " << employees[i].getSalary() << "\n";
				}
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Nie moge otworzyc pliku do zapisu";
	}


}

void EmployeeCSVWriter::writeLogin(std::vector<Employee> employees, std::string filePath)
{
	std::fstream file(filePath, std::ios::out);

	file << "login, email, password";

	if (file.is_open())
	{
		for (const auto& empl : employees)
		{
			if (file.good())
			{
				file << empl.getLogin() << ", " << empl.getEmail() << ", " << empl.getPassword() << "\n";
			}
		}
	}
	else
	{
		std::cout << "Nie moge otworzyc pliku do zapisu";
	}
	file.close();

}

void EmployeeCSVWriter::writeSalary(std::vector<Employee> employees, std::string filePath)
{
	std::ofstream o(filePath);

	o << "first name, last name, salary";

	if (o.is_open())
	{
		for (const auto& empl : employees)
		{
			o << empl.getName() << ", " << empl.getSurname() << ", " << empl.getSalary();
		}
	}
	o.close();
}
