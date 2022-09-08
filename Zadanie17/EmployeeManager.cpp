#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include <algorithm>

EmployeeManager::EmployeeManager(std::shared_ptr<IEmployeeReader> fileReader, std::shared_ptr<IEmployeeWriter> fileWriter)
    : _fileReader(fileReader),
     _fileWriter(fileWriter)
{
}

void EmployeeManager::readDataFromFile(std::string filePath)
{
    _employees = _fileReader->readEmployees(filePath);
}
