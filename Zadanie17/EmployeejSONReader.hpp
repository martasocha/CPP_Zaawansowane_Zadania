#pragma once
#include <string>
#include <fstream>

class EmployeejSONReader {
public:

    std::string readValue();
private:
    std::fstream _filestream;
};