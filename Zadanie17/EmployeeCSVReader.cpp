#include "EmployeeCSVReader.hpp"
#include <fstream>
#include <iostream>
#include "EmployeeManager.hpp"

std::vector<Employee> EmployeeCSVReader::readEmployees()
{
    std::ifstream file("employee_input.csv");

    if (!file.is_open())
    {
        std::cout << "Nie udalo sie otworzyc pliku.";
    }

    std::vector<Employee> employees;

    std::string name;
    std::string lastName;
    std::string mail;
    Employee::Gender gender;
    double salary;

    std::string str;

    std::getline(file, str);

    while (std::getline(file, name, ','))
    {
        std::getline(file, lastName);
        std::getline(file, mail);
        //std::getline(file, gender);
        //std::getline(file, salary);

        employees.emplace_back(name, lastName, mail);
    }
    file.close();
 

    return employees;
}
