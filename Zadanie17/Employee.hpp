#pragma once
#include <string>


class Employee
{
public:
	enum class Gender { MALE, FEMALE, UNKNOWN };
	Employee(std::string name, std::string lastName, std::string mail, Employee::Gender gender, double salary);
	std::string getName();
	std::string getSurname();
	std::string getEmail();
	Employee::Gender getGender();
	double getSalary();
	std::string getLogin();
	std::string getPassword();
private:
	std::string _name;
	std::string _lastName;
	std::string _mail;
	double _salary;
	std::string _login;
	std::string _password;
	Employee::Gender _gender;

};