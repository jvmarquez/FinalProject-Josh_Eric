#include "tasks.h"

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

std::string readLine(const char* prompt) {
    std::cout << prompt << std::flush;
    std::string line;
    if (!std::getline(std::cin, line)) {
        throw std::runtime_error("end of input");
    }
    return line;
}

double parseNumber(const std::string& text) {
    const char* start = text.c_str();
    char* end = nullptr;
    errno = 0;
    double value = std::strtod(start, &end);
    if (end == start) throw std::invalid_argument("please enter a number");
    while (*end == ' ' || *end == '\t' || *end == '\r') ++end;
    if (*end != '\0') throw std::invalid_argument("please enter only one number");
    if (!std::isfinite(value)) throw std::invalid_argument("number must be finite");
    return value;
}

void printResult(const char* label, double value, const char* unit) {
    std::cout << std::fixed << std::setprecision(4)
              << label << ": " << value << " " << unit << "\n";
}

std::vector<double> readResistors() {
    int n = readCount("How many resistors (1-100)? ");
    std::vector<double> resistors;
    for (int i = 1; i <= n; ++i) {
        std::string prompt = "Resistor " + std::to_string(i) + " (ohms): ";
        resistors.push_back(readNumber(prompt.c_str()));
    }
    return resistors;
}

}  

double readNumber(const char* prompt) {
    return parseNumber(readLine(prompt));
}

int readCount(const char* prompt) {
    double value = readNumber(prompt);
    if (value != std::floor(value)) {
        throw std::invalid_argument("count must be a whole number");
    }
    if (value < 1.0 || value > 100.0) {
        throw std::invalid_argument("resistor count must be 1 to 100");
    }
    return static_cast<int>(value);
}

void resistanceTask(CircuitCalculator& calc) {
    double v = readNumber("Voltage (V): ");
    double i = readNumber("Current (A): ");
    printResult("Resistance", calc.resistance(v, i), "ohms");
}

void currentTask(CircuitCalculator& calc) {
    double v = readNumber("Voltage (V): ");
    double r = readNumber("Resistance (ohms): ");
    printResult("Current", calc.current(v, r), "A");
}

void powerTask(CircuitCalculator& calc) {
    double v = readNumber("Voltage (V): ");
    double i = readNumber("Current (A): ");
    printResult("Power", calc.power(v, i), "W");
}

void seriesTask(CircuitCalculator& calc) {
    printResult("Equivalent resistance", calc.series(readResistors()), "ohms");
}

void parallelTask(CircuitCalculator& calc) {
    printResult("Equivalent resistance", calc.parallel(readResistors()), "ohms");
}