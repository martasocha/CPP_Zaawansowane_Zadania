#include "EmployeejSONWriter.hpp"
#include <fstream>
#include <iomanip>
#include "json.hpp"
#include "Employee.hpp"


using json = nlohmann::json;

void to_json(json& j, const Employee& employee) {
	j = json{ {"_name", employee.getName()}, {"_lastName", employee.getSurname()}, {"_email", employee.getEmail()}, {"_salary", employee.getSalary()}, {"_login", employee.getLogin()}, {"_password", employee.getPassword()} , {"_gender", employee.getGender()} };
}

//void saveLoginPassword(json& j, const Employee& employee)
//{
//	j = { {"_login", employee.getLogin()} , {"_emal", employee.getEmail()},  {"_password", employee.getPassword()} };
//}

void EmployeejSONWriter::writeEmployees(std::vector<Employee> employees, std::string filePath, Type type)
{

	//std::fstream file(filePath, std::ios::out);

	json j;
	j["Employees"] = json(employees);

	std::ofstream o(filePath);

	o << std::setw(4) << j << std::endl;
}

void EmployeejSONWriter::writeLogin(std::vector<Employee> employees, std::string filePath)
{
	std::ofstream o(filePath);
	json employeeArray; // tworze tymczaoswy obiekt jasona
	
	for (auto& emp : employees)
	{
		json employee{ {"_login", emp.getLogin()} , {"_emal", emp.getEmail()},  {"_password", emp.getPassword()} };
		employeeArray.push_back(employee);
	}

	json j;
	j["Login"] = employeeArray;


	o << std::setw(4) << j << std::endl;
}

void EmployeejSONWriter::writeSalary(std::vector<Employee> employees, std::string filePath)
{

	std::ofstream o(filePath);
	json j;

	for (const auto& emp : employees)
	{
		json employee{ {"_name", emp.getName()}, {"_lastName", emp.getSurname()}, {"salary", emp.getSalary()} };
		j["SalaryData"].push_back(employee);
	}

	o << std::setw(4) << j << std::endl;

}
