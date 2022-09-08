#include <iostream>
#include "EmployeeManager.hpp"
#include "EmployeeCSVReader.hpp"
#include "EmployeeCSVWriter.hpp"

int main()
{
    EmployeeManager empManager(std::make_shared<EmployeeCSVReader>(), std::make_shared<EmployeeCSVWriter>());
    //EmployeeManager empManager2(std::make_shared<EmployeeJSONReader>(), std::make_shared<EmployeeJSONWriter>());
    empManager.readDataFromFile("employee_input.csv");

    //empManager.generateLogin();
}