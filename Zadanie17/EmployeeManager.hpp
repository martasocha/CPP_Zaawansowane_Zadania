#pragma once
#include "Employee.hpp"
#include "IEmployeeReader.hpp"
#include "iEmployeeWriter.hpp"
#include <vector>
#include <map>
#include<iostream>
#include "EmployeeCSVWriter.hpp"

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
	//b) storeLoginDataToFile
	//c) int calculateFirstNameStarting(char firstLetter)
	//c) std::map calculateUniqueNames()
	//c) calculateAvarageSalary()
	//c) calculateAvarageSalaryMen()
	//c) calculateAvarageSalaryWomen()
	
	//std::vector<Employee> calculateTop10Salary();

	//std::vector<E> calculateTop10Salary()
	//d) storeEmployeeSalary(std::vector<E>)

private:
	std::vector<Employee> _employees;
	std::shared_ptr<IEmployeeReader> _fileReader;
	std::shared_ptr<IEmployeeWriter> _fileWriter;


};