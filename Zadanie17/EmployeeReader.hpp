#pragma once
#include "EmployeeCSVReader.hpp"
#include "EmployeejSONReader.hpp"

class EmployeeReader
{
protected:
    EmployeeCSVReader* csvReader;
    EmployeejSONReader* jSONReader;

 public:
     /**
      * In this case we will delegate the memory ownership to Facade Class
      */
     EmployeeReader(
         EmployeeCSVReader* csvReader1 = nullptr,
         EmployeejSONReader* jSONReader1 = nullptr) 
     {
         this->csvReader = csvReader1 ?: new EmployeeCSVReader;
         this->jSONReader = jSONReader1 ?: new EmployeejSONReader;
     }
     ~EmployeeReader() {
         delete csvReader;
         delete jSONReader;
     }

     std::string readValue() {
         std::string result = "Facade initializes csvReader:\n";
         result += this->csvReader->readValue();
         result += "Facade orders subsystems to perform the action:\n";
         result += this->csvReader->readValue();
         return result;
     }
};
