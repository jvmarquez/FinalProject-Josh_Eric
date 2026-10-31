# Classical Circuit Calculator
Iteration 2 starter for Eric Sebastian and Joshua Marquez. Project leader: Joshua.

## Build and run
Install a C++17 compiler (g++). Open a terminal in this project folder.

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o build/calculator
./build/calculator
```

Windows PowerShell with g++ installed:
```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/tasks.cpp src/calculator.cpp -o build/calculator.exe
.\build\calculator.exe
```

## Usage
1: R=V/I. 2: I=V/R. 3: P=VI. 4: series sum. 5: reciprocal parallel sum. 0: exit.
Enter one number per prompt. Use volts, amperes, and ohms, not milli-units.
For example, option 1 with 12 V and 2 A returns 6.0000 ohms.
Option 5 with two 100-ohm resistors returns 50.0000 ohms.

This version accepts nonnegative DC magnitudes. Division denominators and all
individual resistors must be positive. Resistor count must be an integer 1-100.
Text, nonfinite values, extra tokens, and out-of-range results are rejected.
Zero voltage and zero power current are allowed. Results have four decimal places;
very small results can round to zero. AC, signed circuit analysis, ideal shorts,
and general network solving are outside this version's scope.

## Organization and responsibility
- src/main.cpp: repeating switch menu (Joshua).
- src/tasks.h and src/tasks.cpp: prompt functions, one per calculation.
- src/calculator.h and src/calculator.cpp: CircuitCalculator class and formulas.
- Eric: resistanceTask, currentTask, seriesTask and matching methods.
- Joshua: powerTask, parallelTask and matching methods, menu.
- tests/: saved input and expected result text. test.sh compiles and checks output.
- docs/: Iteration 2 PDF report and Excel plan.

## Tests
In Bash, Git Bash, WSL, macOS, or Linux, run `bash test.sh`.
The 16 cases cover all five calculations, rounding, zero power, invalid values,
text, menu recovery, resistor counts, extra text, overflow, and repeated use.
Checks match the expected result line; prompts are not compared byte for byte.
The script exits nonzero on a build or test failure.

## Team workflow and current status
This is an assisted starter implementation, not a record of either student's
completed work. Both members should understand and review their assigned code,
record actual contributions in the Excel plan, and review each other's changes.
Use separate branches and clear commits. Do not claim reviews or commits until
they happen. GitHub upload, team acceptance, and Canvas submission are pending.
Each student submits the repository link separately. Future course dates are TBD.
