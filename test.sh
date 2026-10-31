#!/usr/bin/env bash
set -eu
cd "$(dirname "$0")"
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o build/calculator
passed=0
for input in tests/*.in; do
    expected="${input%.in}.expected"
    output=$(build/calculator < "$input")
    if ! printf '%s\n' "$output" | grep -Fq -f "$expected"; then
        echo "FAIL: $input"
        printf '%s\n' "$output"
        exit 1
    fi
    passed=$((passed + 1))
done
echo "$passed tests passed."
