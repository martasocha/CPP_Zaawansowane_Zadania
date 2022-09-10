#pragma once
#include "Employee.hpp"
#include "IEmployeeReader.hpp"
#include "iEmployeeWriter.hpp"
#include <vector>
#include <iostream>
#include "EmployeeCSVWriter.hpp"
#include <map>

class EmployeeManager
{
public:
	EmployeeManager(std::shared_ptr<IEmployeeReader> fileReader, std::shared_ptr<IEmployeeWriter> fileWriter);

	void readDataFromFile(std::string filePath);
	void writeDataToFile(std::string filePath, IEmployeeWriter::Type type);
	void generateLogin();
	std::string generateSinglePassword();
	void generatePasswords();
	int generate(int num1, int num2);
	char generate(std::string);

	void saveLogins(std::string filePath);
	void saveSalaries(std::vector<Employee> vect, std::string filePath);

	void printMap(std::map<char, int> map);
	int countUniqueNames(std::map<std::string, int> map);
	std::string findFrequentName(std::map<std::string, int> map);
	void firstLetterNameStats();
	void calculateUniqueNames();
	void calculateAvarageSalary();
	void calculateAvarageSalaryMen();
	void calculateAvarageSalaryWomen();
	
	std::vector<Employee> calculateLeast10Salary();
	std::vector<Employee> calculateTop10Salary();

private:
	std::vector<Employee> _employees;
	std::shared_ptr<IEmployeeReader> _fileReader;
	std::shared_ptr<IEmployeeWriter> _fileWriter;


};