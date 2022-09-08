#pragma once
#include "Employee.hpp"
#include <vector>

class IEmployeeReader
{
public:
    virtual std::vector<Employee> readEmployees(std::string filePath) = 0;

};
