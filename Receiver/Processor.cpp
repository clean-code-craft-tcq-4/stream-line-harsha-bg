#include <iostream>
#include <regex>
#include <sstream>
#include <memory>
#include "includes/Processor.hpp"

using namespace std;

std::vector<std::string> Processor::tokenize(const std::string str, const std::regex re)
{
    std::sregex_token_iterator it{ str.begin(), str.end(), re, -1 };
    std::vector<std::string> tokenized{ it, {} };
    return tokenized;
}

void Processor::processInput(const std::string inputData)
{
    std::istringstream iss(inputData);
    string line;
    const std::regex re("[A-Za-z]+");
    const std::regex space_re("\\s+");
    while (std::getline (iss,line))
    {
        //ignore unwanted lines
        if (!line.empty() && !(regex_match (line, re)))
        {
            const std::vector<std::string> tokenized = tokenize(line, space_re);
            //as of now have only two parameters temp and charge rate
            m_processedData.emplace_back(new Temperature(atof(tokenized[0].c_str())));
            m_processedData.emplace_back(new ChargeRate(atof(tokenized[1].c_str())));
        }
    }
}

void Processor::printProcessedInput()
{
    for (const auto itr : m_processedData)
    {
        cout << "{ ";
        switch (itr->getType())
        {
            case BMSParamType::TEMP:
            cout << "\"Temperature\"";
            break;
            case BMSParamType::SOC:
            cout << "\"SOC\"";
            break;
            case BMSParamType::CHARGE_RATE:
            cout << "\"Charge Rate\"";
            break;
            default:
            break;
        }
        cout << " : \"" <<itr->getValue() << "\" }" << std::endl;
    }
}
