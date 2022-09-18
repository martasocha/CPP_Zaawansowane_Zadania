#include "SymbolGenerator.hpp"
#include <random>

char SymbolGenerator::generateSymbol()
{
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> distrib(0, symbols.size());

    return distrib(engine);
}
