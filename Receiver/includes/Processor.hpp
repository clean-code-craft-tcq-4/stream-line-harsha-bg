#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <string>
#include <vector>
#include <regex>
#include "BMSParam.hpp"

class Processor
{
    public:
    void processInput(const std::string inputData);
    void printProcessedInput(); 
    private:
    std::vector<std::string> tokenize(const std::string str, const std::regex re);
    std::vector<shared_ptr<BMSParam>> m_processedData {};
};

#endif