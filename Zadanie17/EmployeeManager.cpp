#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include <algorithm>

EmployeeManager::EmployeeManager(std::shared_ptr<IEmployeeReader> fileReader, std::shared_ptr<IEmployeeWriter> fileWriter)
    : _fileReader(fileReader),
     _fileWriter(fileWriter)
{
}

void EmployeeManager::readDataFromFile(std::string filePath)
{
    _employees = _fileReader->readEmployees(filePath);
}


std::string EmployeeManager::generateLogin()
{
    auto genLogin = [&](Employee& e)
    {
        std::string login;
        for (int i = 0; i < 2; ++i)
        {
            login += e.getSurname().at(i);
        }
        for (int i = 2; i < 4; ++i)
        {
            login += e.getName().at(i);
        }
       
        auto result = std::find(_employees.begin(), _employees.end(), e.getLogin());
        do
        {
            int i;
            for (i = 4; i < 6; ++i)
            {
                login += e.getName().at(i);
            }
            auto result = std::find(_employees.begin(), _employees.end(), e.getLogin());
            i = i + 2;
        } while (result != std::end(_employees));

        e.getLogin().push_back(login);
    };
    std::for_each(_employees.begin(), _employees.end(), genLogin);

    return std::string();
}

