#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
class CircuitCalculator {
private:
    double lastResult = 0;
    double save(double value);
public:
    double resistance(double voltage, double current);
    double current(double voltage, double resistance);
    double power(double voltage, double current);
    double series(const std::vector<double>& resistors);
    double parallel(const std::vector<double>& resistors);
    double getLastResult() const;
};
#endif
