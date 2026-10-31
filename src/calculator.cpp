#include "calculator.h"
#include <cmath>
#include <stdexcept>
double CircuitCalculator::save(double value) {
    if (!std::isfinite(value)) throw std::invalid_argument("Result is out of range.");
    lastResult = value;
    return lastResult;
}
double CircuitCalculator::getLastResult() const { return lastResult; }
double CircuitCalculator::resistance(double voltage, double current) {
    if (voltage < 0 || current <= 0) throw std::invalid_argument("Use voltage >= 0 and current > 0.");
    return save(voltage / current);
}
double CircuitCalculator::current(double voltage, double resistance) {
    if (voltage < 0 || resistance <= 0) throw std::invalid_argument("Use voltage >= 0 and resistance > 0.");
    return save(voltage / resistance);
}
double CircuitCalculator::power(double voltage, double current) {
    if (voltage < 0 || current < 0) throw std::invalid_argument("Use nonnegative voltage and current.");
    return save(voltage * current);
}
double CircuitCalculator::series(const std::vector<double>& resistors) {
    if (resistors.empty()) throw std::invalid_argument("Enter at least one resistor.");
    double total = 0;
    for (double r : resistors) {
        if (!std::isfinite(r) || r <= 0) throw std::invalid_argument("Resistors must be positive and finite.");
        total += r;
    }
    return save(total);
}
double CircuitCalculator::parallel(const std::vector<double>& resistors) {
    if (resistors.empty()) throw std::invalid_argument("Enter at least one resistor.");
    double reciprocalTotal = 0;
    for (double r : resistors) {
        if (!std::isfinite(r) || r <= 0) throw std::invalid_argument("Resistors must be positive and finite.");
        reciprocalTotal += 1.0 / r;
    }
    if (!std::isfinite(reciprocalTotal)) throw std::invalid_argument("Result is out of range.");
    return save(1.0 / reciprocalTotal);
}
