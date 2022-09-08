#pragma once
#include <fstream>
#include <vector>
#include "Employee.hpp"

class EmployeejSONReader {
public:
    std::vector<Employee> readValue();

};