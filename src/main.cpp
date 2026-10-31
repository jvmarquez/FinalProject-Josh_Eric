#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
int main() {
    CircuitCalculator calculator;
    std::cout << std::fixed << std::setprecision(4);
    while (true) {
        std::cout << "\nClassical Circuit Calculator\n"
                  << "1. Resistance\n2. Current\n3. Power\n"
                  << "4. Series resistance\n5. Parallel resistance\n0. Exit\n";
        try {
            switch (readMenuChoice()) {
                case 1: resistanceTask(calculator); break;
                case 2: currentTask(calculator); break;
                case 3: powerTask(calculator); break;
                case 4: seriesTask(calculator); break;
                case 5: parallelTask(calculator); break;
                case 0: std::cout << "Goodbye!\n"; return 0;
            }
        } catch (const std::invalid_argument& error) {
            std::cout << "Invalid input: " << error.what() << '\n';
        } catch (const std::runtime_error& error) {
            std::cout << error.what() << '\n';
            return 0;
        }
    }
}
