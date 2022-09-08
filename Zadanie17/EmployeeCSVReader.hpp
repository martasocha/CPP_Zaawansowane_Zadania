#pragma once
#include <fstream>
#include <vector>
#include "Employee.hpp"
#include "IEmployeeReader.hpp"

#include <vector>

class EmployeeCSVReader : public IEmployeeReader
{
public:
	std::vector<Employee> readEmployees(std::string filePath) override; //wewnatrz tej funkcji mozemy sobie tez od razu tymczasowo utworzyc wszystkie zmienne do oblsugi plikow


private:
	//pola potrzbene do obslugi plików
};