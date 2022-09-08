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


void EmployeeManager::generateLogin()
{
    std::vector<std::string> vectOfLogins;

    auto genLogin = [&](Employee& e)
    {
        std::string login;
        for (int i = 0; i < 2; ++i)
        {
            login += std::tolower(e.getSurname().at(i));
        }
        for (int i = 0; i < 2; ++i)
        {
            login += std::tolower(e.getName().at(i));
        }

        auto result = std::find(vectOfLogins.begin(), vectOfLogins.end(), e.getLogin());
        while (result == std::end(vectOfLogins));
        {
            for (int i = 2; i < 4; ++i)
            {
                login += std::tolower(e.getName().at(i));
            }
            result = std::find(vectOfLogins.begin(), vectOfLogins.end(), e.getLogin());
        }
        vectOfLogins.push_back(login);
        e.setLogin(login);
    };
    std::for_each(_employees.begin(), _employees.end(), genLogin);
}