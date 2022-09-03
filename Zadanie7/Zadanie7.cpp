
#include <vector>
#include <random>
#include <iostream>

std::vector<int> generateList()
{
    std::random_device r;
    std::default_random_engine engine(r());

    std::uniform_int_distribution<int> distribution(1, 1000);

    std::vector<int> listofNumbers;

    for (unsigned int i = 0; i <= 50; ++i)
    {
        listofNumbers.push_back(distribution(engine));
    }

    return listofNumbers;
}

std::vector<int> addLists(std::vector<int> list1, std::vector<int> list2)
{
    std::vector<int> newList;
    std::copy(list1.begin(), list1.end(), std::back_inserter(newList));
    std::copy(list2.begin(), list2.end(), std::back_inserter(newList));

    return newList;
}

std::vector<int> sortList(std::vector<int> list)
{
    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;
    std::vector<int> sortedVector;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if ((*it) % 2 == 0)
        {
            evenNumbers.push_back(*it);
        }
        else
        {
            oddNumbers.push_back(*it);
        }
    }

    std::sort(evenNumbers.begin(), evenNumbers.end());
    std::sort(oddNumbers.begin(), oddNumbers.end(), std::greater<int>());

    sortedVector = addLists(evenNumbers, oddNumbers);

    return sortedVector;
}

void printListOfNums(std::vector<int> list)
{
    for (auto n : list)
    {
        std::cout << n << ", ";
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    std::vector<int> sortedList;
    std::vector<int> listOfNums = generateList();
    printListOfNums(listOfNums);
    sortedList = sortList(listOfNums);
    printListOfNums(sortedList);

    
}
