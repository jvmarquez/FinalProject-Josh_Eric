#ifndef TASKS_H
#define TASKS_H

#include "calculator.h"

double readNumber(const char* prompt);
int readCount(const char* prompt);

void resistanceTask(CircuitCalculator& calc);  // T1 (Eric)
void currentTask(CircuitCalculator& calc);     // T2 (Eric)
void powerTask(CircuitCalculator& calc);       // T3 (Joshua)
void seriesTask(CircuitCalculator& calc);      // T4 (Eric)
void parallelTask(CircuitCalculator& calc);    // T5 (Joshua)

#endif