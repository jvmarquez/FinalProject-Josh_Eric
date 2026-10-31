#include <exception>
#include <iostream>
#include <string>

#include "calculator.h"
#include "tasks.h"

namespace {

const int MENU_EOF = -2;      // input ended
const int MENU_INVALID = -1;  // not a valid menu entry

void printMenu() {
    std::cout << "\n=== Classical Circuit Calculator ===\n"
              << "1. Resistance  (R = V / I)\n"
              << "2. Current     (I = V / R)\n"
              << "3. Power       (P = V x I)\n"
              << "4. Series      (Req = sum of R)\n"
              << "5. Parallel    (Req = 1 / sum(1/R))\n"
              << "0. Exit\n"
              << "Choice: " << std::flush;
}

int readMenuChoice() {
    std::string line;
    if (!std::getline(std::cin, line)) return MENU_EOF;

    // trim whitespace
    std::size_t first = line.find_first_not_of(" \t\r");
    std::size_t last = line.find_last_not_of(" \t\r");
    if (first == std::string::npos) return MENU_INVALID;
    line = line.substr(first, last - first + 1);

    if (line.size() == 1 && line[0] >= '0' && line[0] <= '5') {
        return line[0] - '0';
    }
    return MENU_INVALID;
}

}  // namespace

int main() {
    CircuitCalculator calc;
    bool running = true;

    while (running) {
        printMenu();
        int choice = readMenuChoice();

        try {
            switch (choice) {
                case 1: resistanceTask(calc); break;
                case 2: currentTask(calc); break;
                case 3: powerTask(calc); break;
                case 4: seriesTask(calc); break;
                case 5: parallelTask(calc); break;
                case 0:
                case MENU_EOF:
                    running = false;
                    break;
                default:
                    std::cout << "Invalid menu choice. Enter 0-5.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Invalid input: " << e.what() << "\n";
        }
    }

    std::cout << "\nGoodbye.\n";
    return 0;
}