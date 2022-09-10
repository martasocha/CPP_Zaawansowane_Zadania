#include "Employee.hpp"

Employee::Employee(std::string name, std::string lastName, std::string mail, Employee::Gender gender, double salary)
    : _name(name), _lastName(lastName), _mail(mail), _gender(gender), _salary(salary)
{
}

Employee::Employee()
{
}

std::string Employee::getName() const
{
    return _name;
}

std::string Employee::getSurname() const
{
    return _lastName;
}

std::string Employee::getEmail() const
{
    return _mail;
}

Employee::Gender Employee::getGender() const
{
    return _gender;
}

double Employee::getSalary() const
{
    return _salary;
}

std::string Employee::getLogin() const
{
    return _login;
}

void Employee::setLogin(std::string login)
{
    _login = login;
}

std::string Employee::getPassword() const
{
    return _password;
}

void Employee::setPassword(std::string password)
{
    _password = password;
}

std::string Employee::toString(Gender g)
{
    switch (g)
    {
    case Gender::FEMALE:
            return "Female";
            break;

    case Gender::MALE:
        return "Male";
        break;

    case Gender::UNKNOWN:
        return "Unknown";
        break;

    }
}
