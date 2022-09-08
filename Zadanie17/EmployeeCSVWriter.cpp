#include "EmployeeCSVWriter.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

void EmployeeCSVWriter::writeEmployees(std::vector<Employee> employees, std::string filePath)
{
	std::fstream file(filePath);

	if (file.is_open())
	{
		for (unsigned int i = 0; i < employees.size(); ++i)
		{
			if (file.good())
			{
				file << employees[i].getName() << " ," << employees[i].getSurname() << " ," << employees[i].getEmail() << " ," << employees[i].getSalary() << "\n";
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Nie moge otworzyc pliku do zapisu";
	}


}
