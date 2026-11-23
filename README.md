# Classical Circuit Calculator

EECE 2140 Iteration 3 project by Eric Sebastian and Joshua Marquez. Eric Sebastian is the project lead.

## Build and run

Open a terminal in the repository folder. You’ll need `g++` with C++17 support.

### VS Code with WSL, Linux, or Git Bash

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o build/calculator
./build/calculator
```

### Windows PowerShell

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/tasks.cpp src/calculator.cpp -o build/calculator.exe
.\build\calculator.exe
```

## Usage

| Option | Calculation |
|---|---|
| 1 | Resistance, R = V / I |
| 2 | Current, I = V / R |
| 3 | Power, P = V × I |
| 4 | Series resistance |
| 5 | Parallel resistance |
| 0 | Exit |

Enter one number per prompt. Use volts, amperes, and ohms. For example, option 1 with 12 V and 2 A returns `6.0000 ohms`. Option 5 with two 100-ohm resistors returns `50.0000 ohms`.

The calculator uses nonnegative values for basic DC circuits. Division denominators and individual resistor values must be positive. Enter 1–100 resistors for series and parallel calculations. Results display to four decimal places.

## Project files

- `src/main.cpp` runs the repeating switch menu.
- `src/tasks.h` and `src/tasks.cpp` handle prompts and run one task per calculation.
- `src/calculator.h` and `src/calculator.cpp` define the `CircuitCalculator` class and its formulas.
- `tests/` contains saved inputs and expected outputs. `test.sh` builds the program and checks its output.
- `docs/` is the folder that contains Iteration 2 and 3 excel table and pdf report.

Eric is responsible for resistance, current, and series resistance. Joshua is responsible for power, parallel resistance, and the menu.

## Tests

Run from the repository folder in a Bash terminal:

```bash
bash test.sh
```

The merged `main` branch was built and tested in VS Code using WSL. The final test run reported **17 passed, 0 failed**.
