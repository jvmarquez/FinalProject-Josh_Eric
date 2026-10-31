#ifndef TASKS_H
#define TASKS_H
#include "calculator.h"
void resistanceTask(CircuitCalculator& calculator);
void currentTask(CircuitCalculator& calculator);
void powerTask(CircuitCalculator& calculator);
void seriesTask(CircuitCalculator& calculator);
void parallelTask(CircuitCalculator& calculator);
int readMenuChoice();
#endif
