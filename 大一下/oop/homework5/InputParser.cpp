#include "InputParser.h"

#include <climits>
#include <iostream>
#include <sstream>

namespace {
bool parseIntToken(const std::string& token, int& value)
{
    std::stringstream ss(token);
    long long temp = 0;
    char extra = '\0';

    if (!(ss >> temp) || (ss >> extra)) {
        return false;
    }
    if (temp < INT_MIN || temp > INT_MAX) {
        return false;
    }

    value = static_cast<int>(temp);
    return true;
}

bool isArithmeticCommand(const std::string& cmd)
{
    return cmd == "+" || cmd == "-" || cmd == "*"
        || cmd == "/" || cmd == "%";
}

bool isGeometryCommand(const std::string& cmd)
{
    return cmd == "rectangle" || cmd == "triangle";
}

bool parseThreeTokens(const std::string& first, const std::string& second,
                      const std::string& third,
                      std::string& outCmd, int& outA, int& outB)
{
    if (isArithmeticCommand(second)) {
        if (!parseIntToken(first, outA) || !parseIntToken(third, outB)) {
            std::cout << "Error: non-numeric input" << std::endl;
            return false;
        }
        outCmd = second;
        return true;
    }

    if (isGeometryCommand(first)) {
        if (!parseIntToken(second, outA) || !parseIntToken(third, outB)) {
            std::cout << "Error: non-numeric input" << std::endl;
            return false;
        }
        outCmd = first;
        return true;
    }

    std::cout << "Error: invalid operator or shape name" << std::endl;
    return false;
}
}

InputParser::InputParser()
{
    std::cout << "InputParser created" << std::endl;
}

InputParser::~InputParser()
{
    std::cout << "InputParser destroyed" << std::endl;
}

bool InputParser::parseCommandLine(int argc, char* argv[],
                                   std::string& outCmd, int& outA, int& outB)
{
    if (argc != 4) {
        std::cout << "Error: invalid argument count" << std::endl;
        return false;
    }

    return parseThreeTokens(argv[1], argv[2], argv[3], outCmd, outA, outB);
}

bool InputParser::parseInteractiveLine(const std::string& line,
                                       std::string& outCmd,
                                       int& outA, int& outB)
{
    std::stringstream ss(line);
    std::string first;
    std::string second;
    std::string third;
    std::string extra;

    if (!(ss >> first)) {
        std::cout << "Error: empty input" << std::endl;
        return false;
    }

    if (first == "exit") {
        if (ss >> extra) {
            std::cout << "Error: invalid command format" << std::endl;
            return false;
        }
        outCmd = "exit";
        return true;
    }

    if (first == "reset") {
        if (ss >> extra) {
            std::cout << "Error: invalid command format" << std::endl;
            return false;
        }
        outCmd = "reset";
        return true;
    }

    if (!(ss >> second >> third) || (ss >> extra)) {
        std::cout << "Error: invalid command format" << std::endl;
        return false;
    }

    return parseThreeTokens(first, second, third, outCmd, outA, outB);
}
