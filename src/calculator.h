#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

class CircuitCalculator {
public:
    CircuitCalculator();

    double resistance(double voltage, double current);   // R = V / I
    double current(double voltage, double resistance);   // I = V / R
    double power(double voltage, double current);        // P = V * I
    double series(const std::vector<double>& resistors);   // Req = sum(R)
    double parallel(const std::vector<double>& resistors); // Req = 1 / sum(1/R)

    double getLastResult() const;

private:
    double lastResult;
    double save(double value);  // checks the answer is finite, then stores it
    static void checkResistors(const std::vector<double>& resistors);
};

#endif