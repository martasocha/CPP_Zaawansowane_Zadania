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
