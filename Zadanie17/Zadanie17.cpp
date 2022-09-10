#include <iostream>
#include "EmployeeManager.hpp"
#include "EmployeeCSVReader.hpp"
#include "EmployeeCSVWriter.hpp"
#include "EmployeejSONWriter.hpp"

int main()
{
    EmployeeManager empManager(std::make_shared<EmployeeCSVReader>(), std::make_shared<EmployeejSONWriter>());
    //EmployeeManager empManager2(std::make_shared<EmployeeJSONReader>(), std::make_shared<EmployeeJSONWriter>());

    empManager.readDataFromFile("employee_input.csv");

    empManager.generateLogin();
    empManager.generatePasswords();
    empManager.saveLogins("employees_passwords");
    std::cout << "Statystyki z liczba osob o imieniu na kazda z liter alfabetu" << std::endl;
    empManager.firstLetterNameStats();
    empManager.calculateUniqueNames();
    empManager.calculateAvarageSalary();
    empManager.calculateAvarageSalaryMen();
    empManager.calculateAvarageSalaryWomen();
    empManager.saveSalaries(empManager.calculateLeast10Salary(), "least10_salary.json");
    empManager.saveSalaries(empManager.calculateTop10Salary(), "top10_salary.json");
    //empManager.writeDataToFile("plik.csv", IEmployeeWriter::Type::A);
}