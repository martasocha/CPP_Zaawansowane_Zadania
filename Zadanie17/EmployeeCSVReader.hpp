#pragma once
#include <string>
#include <fstream>

class EmployeeCSVReader {
public:
    std::string readValue();
private:
    std::fstream _filestream;
};