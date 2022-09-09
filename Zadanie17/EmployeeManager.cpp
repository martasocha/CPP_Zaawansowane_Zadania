#include "EmployeeManager.hpp"
#include "EmployeeCSVWriter.hpp"
#include "Employee.hpp"
#include <algorithm>
#include <random>

EmployeeManager::EmployeeManager(std::shared_ptr<IEmployeeReader> fileReader, std::shared_ptr<IEmployeeWriter> fileWriter)
    : _fileReader(fileReader),
     _fileWriter(fileWriter)
{
}

void EmployeeManager::readDataFromFile(std::string filePath)
{
    _employees = _fileReader->readEmployees(filePath);
}

void EmployeeManager::writeDataToFile(std::string filePath, IEmployeeWriter::Type type)
{
    _fileWriter->writeEmployees(_employees, filePath, type);
}


void EmployeeManager::generateLogin()
{
    std::vector<std::string> vectOfLogins{};

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

        auto result = std::find(vectOfLogins.begin(), vectOfLogins.end(), login);
        //std::cout << *result << " " << (result == std::end(vectOfLogins)) << std::endl;
        while (result != std::end(vectOfLogins))
        {
            for (int i = 2; i < 4; ++i)
            {
                login += std::tolower(e.getSurname().at(i));
            }
            result = std::find(vectOfLogins.begin(), vectOfLogins.end(), login);
        }
        vectOfLogins.push_back(login);
        e.setLogin(login);
    };
    std::for_each(_employees.begin(), _employees.end(), genLogin);
}

std::string EmployeeManager::generateSinglePassword()
{
    int passwordLength = generate(8, 12);
    int charLeft = passwordLength;

    int smallLetterCount = generate(1, charLeft - 4);
    charLeft -= smallLetterCount;

    int capitalLetterCount = generate(1, charLeft - 3);
    charLeft -= capitalLetterCount;

    int numbersCount = generate(1, charLeft - 2);
    charLeft -= numbersCount;

    int specialCharCount = charLeft;

    // Array of numbers
    std::string numbers = "0123456789";

    // Array of small alphabets
    std::string letters = "abcdefghijklmnoqprstuvwyzx";

    // Array of capital alphabets
    std::string LETTERS = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    // Array of all the special symbols
    std::string symbols = "!@#$^&*?";

    std::string password;

    for (unsigned int i = 0; i < smallLetterCount; ++i)
    {
        password.push_back(letters[generate(letters)]);
    }
    for (unsigned int i = 0; i < capitalLetterCount; ++i)
    {
        password.push_back(LETTERS[generate(LETTERS)]);
    }
    for (unsigned int i = 0; i < numbersCount; ++i)
    {
        password.push_back(numbers[generate(numbers)]);
    }
    for (unsigned int i = 0; i < specialCharCount; ++i)
    {
        password.push_back(symbols[generate(symbols)]);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(password.begin(), password.end(), g);

    return password;
}

void EmployeeManager::generatePasswords()
{
    auto genPassword = [&](Employee& e)
    {
        std::string password = generateSinglePassword();
        e.setPassword(password);
    };

    std::for_each(_employees.begin(), _employees.end(), genPassword);
}

int EmployeeManager::generate(int num1, int num2)
{
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> distr(num1, num2);

    return distr(engine);
}

char EmployeeManager::generate(std::string str)
{
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> distrib(0, str.size());

    return distrib(engine);
}

//std::vector<Employee> EmployeeManager::calculateTop10Salary()
//{
//    auto findTop10 = []()
//    {
//
//    };
//    std::for_each(_employees.begin(), _employees.end(), findTop10);
//    return std::vector<Employee>();
//}

