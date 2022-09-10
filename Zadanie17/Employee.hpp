#pragma once
#include <string>


class Employee
{
public:
	enum class Gender { MALE, FEMALE, UNKNOWN };
	Employee(std::string name, std::string lastName, std::string mail, Employee::Gender gender, double salary);
	Employee();
	std::string getName() const;
	std::string getSurname() const;
	std::string getEmail() const;
	Employee::Gender getGender() const;
	double getSalary() const;
	std::string getLogin() const;
	void setLogin(std::string login);
	std::string getPassword() const;
	void setPassword(std::string password);

	static std::string toString(Gender g);
private:
	std::string _name;
	std::string _lastName;
	std::string _mail;
	double _salary;
	std::string _login;
	std::string _password;
	Employee::Gender _gender;

};