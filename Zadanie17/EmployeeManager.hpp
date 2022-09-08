#pragma once
#include "Employee.hpp"
#include "IEmployeeReader.hpp"
#include "iEmployeeWriter.hpp"
#include <vector>
#include <map>
#include<iostream>

class EmployeeManager
{
public:
	EmployeeManager(std::shared_ptr<IEmployeeReader> fileReader, std::shared_ptr<IEmployeeWriter> fileWriter);

	void readDataFromFile(std::string filePath);
	//std::vector<std::string> generateLogin();
	//std::string generatePasswords();
	//b) storeLoginDataToFile
	//c) int calculateFirstNameStarting(char firstLetter)
	//c) std::map calculateUniqueNames()
	//c) calculateAvarageSalary()
	//c) calculateAvarageSalaryMen()
	//c) calculateAvarageSalaryWomen()
	//d) std::vector<E> calculateTop10Salary()
	//d) std::vector<E> calculateTop10Salary()
	//d) storeEmployeeSalary(std::vector<E>)

private:
	std::vector<Employee> _employees;
	std::shared_ptr<IEmployeeReader> _fileReader;
	std::shared_ptr<IEmployeeWriter> _fileWriter;


};