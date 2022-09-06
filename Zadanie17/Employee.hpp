#pragma once
#include <string>

enum class Gender {MALE, FEMALE};

class Employee
{
public:
	std::string getName();
	std::string getSurname();
	int getEmail();
	Gender getGender();
	double getSalary();
	std::string getLogin();
	std::string getPassword();
private:
	std::string _name;
	std::string _surname;
	int _email;
	double _salary;
	std::string _login;
	std::string _password;
	Gender _gender;

};