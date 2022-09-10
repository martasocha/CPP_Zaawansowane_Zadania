#include "EmployeeManager.hpp"
#include "EmployeeCSVWriter.hpp"
#include "Employee.hpp"
#include <algorithm>
#include <random>
#include <map>

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

    std::string numbers = "0123456789";
    std::string letters = "abcdefghijklmnoqprstuvwyzx";
    std::string LETTERS = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
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

void EmployeeManager::saveLogins(std::string filePath)
{
    _fileWriter->writeLogin(_employees, filePath);
}

void EmployeeManager::saveSalaries(std::vector<Employee> vect,std::string filePath)
{
    _fileWriter->writeSalary(vect, filePath);
}

void EmployeeManager::printMap(std::map<char, int> map)
{
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

int EmployeeManager::countUniqueNames(std::map<std::string, int> map)
{
    int countUniqueNames = 0;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second == 1)
        {
            countUniqueNames++;
        }
    }
    return countUniqueNames;
}

std::string EmployeeManager::findFrequentName(std::map<std::string, int> map)
{
    int max = 0;
    std::string frequentNames;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second > max)
        {
            max = it->second;
        }
    }
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second == max)
        {
            frequentNames += it->first;
            frequentNames += ", ";
        }
    }
    return frequentNames;
}

void EmployeeManager::firstLetterNameStats()
{
    std::map<char, int> firstLetterName = { {'A',0}, {'B',0}, {'C',0},{'D',0},{'E',0},{'F',0},{'G',0},{'H',0},{'I',0},{'J',0},{'K',0},{'L',0},{'M',0},{'N',0},{'O',0},{'P',0},{'R',0},{'S',0},{'T',0},{'U',0}, {'Q',0} ,{'W',0},{'V',0}, {'X',0}, {'Y',0}, {'Z',0} };
    
    auto calculateFirstNameStarting = [&](Employee& e)
    {
        firstLetterName.at(e.getName()[0])++;
    };

    std::for_each(_employees.begin(), _employees.end(), calculateFirstNameStarting);

    printMap(firstLetterName);
}

void EmployeeManager::calculateUniqueNames()
{
    std::map<std::string, int> names;
  

    for (unsigned int i = 0; i < _employees.size(); ++i)
    {
        names.emplace(std::make_pair(_employees[i].getName(), 0));
    }

    int k = 0;

    auto findUnigueNames = [&](Employee& e)
    {
        auto search = names.find(e.getName());
        if (search != names.end())
        {
            search->second++;
        }
    };

    std::for_each(_employees.begin(), _employees.end(), findUnigueNames);

    std::cout << "Ilosc unikalnych imion :" << countUniqueNames(names) << std::endl;
    std::cout << "Najczesciej wystepujace imie: " << findFrequentName(names) << std::endl;

}

void EmployeeManager::calculateAvarageSalary()
{
    double sumOfSalary = 0;
    int countEmployees = 0;

    auto calculateSumOfSalary = [&sumOfSalary, &countEmployees](Employee& e)
    {
        sumOfSalary += e.getSalary();
        countEmployees++;
    };

    std::for_each(_employees.begin(), _employees.end(), calculateSumOfSalary);

    double averageOfSalary = sumOfSalary / countEmployees;
    std::cout << "Srednie zarobki wszystkich pracownikow = " << averageOfSalary << std::endl;
}

void EmployeeManager::calculateAvarageSalaryMen()
{
    double sumOfSalary = 0;
    int countMenEmployees = 0;

    auto calculateMenSumOfSalary = [&sumOfSalary, &countMenEmployees](Employee& e)
    {
        if (e.getGender() == Employee::Gender::MALE)
        {
            sumOfSalary += e.getSalary();
            countMenEmployees++;
        }
    };

    std::for_each(_employees.begin(), _employees.end(), calculateMenSumOfSalary);

    double averageMenSalary = sumOfSalary / countMenEmployees;
    std::cout << "Srednie zarobki mezczyzn = " << averageMenSalary << std::endl;
}

void EmployeeManager::calculateAvarageSalaryWomen()
{
    double sumOfSalary = 0;
    int countWomenEmployees = 0;

    auto calculateWomenSumOfSalary = [&sumOfSalary, &countWomenEmployees](Employee& e)
    {
        if (e.getGender() == Employee::Gender::FEMALE)
        {
            sumOfSalary += e.getSalary();
            countWomenEmployees++;
        }
    };

    std::for_each(_employees.begin(), _employees.end(), calculateWomenSumOfSalary);

    double averageWomenSalary = sumOfSalary / countWomenEmployees;
    std::cout << "Srednie zarobki wszystkich kobiet = " << averageWomenSalary << std::endl;
}

std::vector<Employee> EmployeeManager::calculateLeast10Salary()
{
    std::vector<Employee> least10employees;
    
    std::sort(_employees.begin(), _employees.end(), [](const Employee& left, const Employee& right) { return left.getSalary() < right.getSalary(); });
    
    for (unsigned int i = 0; i < 11; ++i)
    {
        least10employees.push_back(_employees[i]);
    }
    return least10employees;
}

std::vector<Employee> EmployeeManager::calculateTop10Salary()
{
    std::vector<Employee> top10employees;

    std::sort(_employees.begin(), _employees.end(), [](const Employee& left, const Employee& right) { return left.getSalary() < right.getSalary(); });

    for (unsigned int i = _employees.size() - 1; i > _employees.size() - 11 ; --i)
    {
        top10employees.push_back(_employees[i]);
    }
    return top10employees;
}

