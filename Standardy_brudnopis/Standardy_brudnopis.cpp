#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> p;
    std::cout << (bool)p << std::endl;
    if (p) {
        std::cout << "Ten warunek nie wskoczy" << std::endl;
    }

    p = std::make_unique<int>();
    std::cout << (bool)p << std::endl;
    if (p) {
        std::cout << "Ten warunek wskoczy" << std::endl;
    }
}