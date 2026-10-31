#!/usr/bin/env bash
# Builds the calculator and runs every tests/*.in against its *.expect file.
set -u
cd "$(dirname "$0")"
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o build/calculator || { echo "BUILD FAILED"; exit 1; }

pass=0; fail=0
for input in tests/*.in; do
    name=$(basename "$input" .in)
    output=$(./build/calculator < "$input")
    ok=1
    while IFS= read -r line; do
        if ! grep -qF -- "$line" <<< "$output"; then ok=0; echo "  missing: $line"; fi
    done < "tests/$name.expect"
    if [ $ok -eq 1 ]; then echo "PASS $name"; pass=$((pass+1)); else echo "FAIL $name"; fail=$((fail+1)); fi
done
echo "$pass passed, $fail failed"
[ $fail -eq 0 ]
