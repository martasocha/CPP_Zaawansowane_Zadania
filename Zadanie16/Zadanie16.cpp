#include <iostream>
#include <vector>

template <typename OutputIterator, typename SizeType, typename ValueType>
void iota_n(OutputIterator dest, SizeType n, ValueType value)
{
    std::vector<ValueType> vect;
    //for (unsigned int i = 0; i < n; ++i)
    //{
    //    vect.push_back(value + i);
    //}

    for (OutputIterator dest = vect.begin(); dest != n; ++dest)
    {
        vect.push_back(value + *dest);
    }

    return vect;
}

template<class OutputIterator, class Size, class T>
OutputIterator iota_n(OutputIterator first, Size n, T value)
{
    while (n--)
        *first++ = value++;
    return first;
}

template<class OutputIterator, class Size, class T>
OutputIterator iota_n(OutputIterator first, Size n, T value)
{
    return std::generate_n(first, n, [&]() { return value++; });
}

template<typename ValueType>
void printVect(std::vector<ValueType> vect)
{
    for (auto& n : vect)
    {
        std::cout << n << ', ';
    }
}

int main()
{
    iota_n()
    std::cout << "Hello World!\n";
}

