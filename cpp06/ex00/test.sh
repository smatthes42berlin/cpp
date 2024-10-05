#!/bin/bash

# Path to your program
PROGRAM="./convert"

# Array of test cases

test_cases_char=(
    "a"
    "'9'"
    "z"
    " "
    "' '"
    "~"
    "'~'"
    "'a'"
    "'"
    "\""
    "-"
    "+"
)

test_cases_int=(
    "1"
    "0"
    "+1"
    "-1"
    "+0"
    "-0"
    "2147483647"
    "-2147483648"
)

test_cases_float=(
    "-inff"
    "+inff"
    "nanf"
    "0.0f"
    "-0.0f"
    "+0.0f"
    "+4.2f"
    "-4.2f"
    "4.2f"
    "1234567890123456789012345678910.1234567890123456789012345678910f"
    "+1234567890123456789012345678910.1234567890123456789012345678910f"
    "-1234567890123456789012345678910.1234567890123456789012345678910f"
)

test_cases_double=(
    "-inf"
    "+inf"
    "nan"
    "0.0"
    "-0.0"
    "+0.0"
    "+4.2"
    "-4.2"
    "4.2"
    "1234567890123456789012345678910.1234567890123456789012345678910"
    "+1234567890123456789012345678910.1234567890123456789012345678910"
    "-1234567890123456789012345678910.1234567890123456789012345678910"
)

test_cases_error=(
    "abc"
    "'a''b'"
    "''"
    "+-0"
    "+-1"
    "--0"
    "--1"
    "++0"
    "++1"
    "-0..f"
    "-f"
    "+f"
    "0.0ff"
    "4.f"
    "4f"
    "0f"
    ".0f"
    "-.1f"
    "+.1f"
    "0.f"
    "-0.f"
    "-0.."
    ".0"
    "4."
    "0."
    "-.0"
    "+.0"
    ".0"
    ""
)

test_cases_task=(
    "0"
    "nan"
    "42.0f"
)

test_cases=("${test_cases_char[@]}" "${test_cases_int[@]}" "${test_cases_float[@]}" "${test_cases_double[@]}" "${test_cases_error[@]}" "${test_cases_task[@]}")

# Loop through each test case and run the program
for test_case in "${test_cases[@]}"; do
    echo "Testing input: >>>$test_case<<<"
    $PROGRAM "$test_case"
    echo "----------------------"
done
