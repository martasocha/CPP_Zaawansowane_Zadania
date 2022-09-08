#include "Employee.hpp"

Employee::Employee(std::string name, std::string lastName, std::string mail, Employee::Gender gender, double salary)
    : _name(name), _lastName(lastName), _mail(mail), _gender(gender), _salary(salary)
{
}

std::string Employee::getName()
{
    return _name;
}

std::string Employee::getSurname()
{
    return _lastName;
}

std::string Employee::getEmail()
{
    return _mail;
}

Employee::Gender Employee::getGender()
{
    return _gender;
}

double Employee::getSalary()
{
    return _salary;
}

std::string Employee::getLogin()
{
    return _login;
}

std::string Employee::getPassword()
{
    return _password;
}
