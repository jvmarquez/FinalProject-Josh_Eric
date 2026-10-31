#include "tasks.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdexcept>
namespace {
double readNumber(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) throw std::runtime_error("Input ended.");
    std::istringstream input(line);
    double value;
    std::string extra;
    if (!(input >> value) || (input >> extra) || !std::isfinite(value))
        throw std::invalid_argument("Enter one finite number.");
    return value;
}
std::vector<double> readResistors() {
    double count = readNumber("Number of resistors (1-100): ");
    if (count < 1 || count > 100 || std::floor(count) != count)
        throw std::invalid_argument("Enter a whole count from 1 to 100.");
    std::vector<double> resistors;
    for (int i = 0; i < static_cast<int>(count); ++i)
        resistors.push_back(readNumber("Resistor " + std::to_string(i + 1) + " (ohms): "));
    return resistors;
}
}
int readMenuChoice() {
    double choice = readNumber("Choice: ");
    if (choice < 0 || choice > 5 || std::floor(choice) != choice)
        throw std::invalid_argument("Choose a whole number from 0 to 5.");
    return static_cast<int>(choice);
}
void resistanceTask(CircuitCalculator& c) {
    double v = readNumber("Voltage (V): ");
    double i = readNumber("Current (A): ");
    std::cout << "Resistance = " << c.resistance(v, i) << " ohms\n";
}
void currentTask(CircuitCalculator& c) {
    double v = readNumber("Voltage (V): ");
    double r = readNumber("Resistance (ohms): ");
    std::cout << "Current = " << c.current(v, r) << " A\n";
}
void powerTask(CircuitCalculator& c) {
    double v = readNumber("Voltage (V): ");
    double i = readNumber("Current (A): ");
    std::cout << "Power = " << c.power(v, i) << " W\n";
}
void seriesTask(CircuitCalculator& c) {
    auto resistors = readResistors();
    std::cout << "Series resistance = " << c.series(resistors) << " ohms\n";
}
void parallelTask(CircuitCalculator& c) {
    auto resistors = readResistors();
    std::cout << "Parallel resistance = " << c.parallel(resistors) << " ohms\n";
}
