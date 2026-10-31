#include "calculator.h"

#include <cmath>
#include <stdexcept>

namespace {
const std::size_t MIN_RESISTORS = 1;
const std::size_t MAX_RESISTORS = 100;
}

CircuitCalculator::CircuitCalculator() : lastResult(0.0) {}

double CircuitCalculator::save(double value) {
    if (!std::isfinite(value)) {
        throw std::overflow_error("result is not a finite number");
    }
    lastResult = value;
    return lastResult;
}

void CircuitCalculator::checkResistors(const std::vector<double>& resistors) {
    if (resistors.size() < MIN_RESISTORS || resistors.size() > MAX_RESISTORS) {
        throw std::invalid_argument("resistor count must be 1 to 100");
    }
    for (double r : resistors) {
        if (!std::isfinite(r) || r <= 0.0) {
            throw std::invalid_argument("every resistance must be greater than 0");
        }
    }
}

double CircuitCalculator::resistance(double voltage, double current) {
    if (voltage < 0.0) throw std::invalid_argument("voltage must be 0 or more");
    if (current <= 0.0) throw std::invalid_argument("current must be greater than 0");
    return save(voltage / current);
}

double CircuitCalculator::current(double voltage, double resistance) {
    if (voltage < 0.0) throw std::invalid_argument("voltage must be 0 or more");
    if (resistance <= 0.0) throw std::invalid_argument("resistance must be greater than 0");
    return save(voltage / resistance);
}

double CircuitCalculator::power(double voltage, double current) {
    if (voltage < 0.0) throw std::invalid_argument("voltage must be 0 or more");
    if (current < 0.0) throw std::invalid_argument("current must be 0 or more");
    return save(voltage * current);
}

double CircuitCalculator::series(const std::vector<double>& resistors) {
    checkResistors(resistors);
    double sum = 0.0;
    for (double r : resistors) sum += r;
    return save(sum);
}

double CircuitCalculator::parallel(const std::vector<double>& resistors) {
    checkResistors(resistors);
    double reciprocalSum = 0.0;
    for (double r : resistors) reciprocalSum += 1.0 / r;
    if (reciprocalSum <= 0.0) {
        throw std::invalid_argument("resistances are too large to combine");
    }
    return save(1.0 / reciprocalSum);
}

double CircuitCalculator::getLastResult() const {
    return lastResult;
}