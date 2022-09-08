#include "EmployeeCSVReader.hpp"
#include <fstream>
#include <iostream>
#include "EmployeeManager.hpp"

double stringToDouble(std::string str)
{
    double value = std::stod(str);
    return value;
}

Employee::Gender stringToGender(std::string str)
{
    if (str == "FEMALE")
    {
        return Employee::Gender::FEMALE;
    }
    else if (str == "MALE")
    {
        return Employee::Gender::MALE;
    }
    else
    {
        return Employee::Gender::UNKNOWN;
    }

}

std::vector<Employee> EmployeeCSVReader::readEmployees(std::string filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Nie udalo sie otworzyc pliku.";
    }

    std::vector<Employee> employees;

    std::string name;
    std::string lastName;
    std::string mail;
    std::string gender;
    std::string salary;

    std::string str;

    std::getline(file, str);

    while (std::getline(file, name, ','))
    {
        std::getline(file, lastName);
        std::getline(file, mail);
        std::getline(file, gender);
        Employee::Gender gender1 = stringToGender(gender);
        std::getline(file, salary);
        double salary1 = stringToDouble(salary);
        employees.emplace_back(name, lastName, mail, gender1, salary1);
    }
    file.close();
 

    return employees;
}
