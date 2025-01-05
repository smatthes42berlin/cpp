clear
make re

test()
{
    echo TESTCASE: "$1"
    echo -n "RESULT: "
    ./RPN "$1"
    echo
    echo
}
correctTestCases=(
    "1 0 /"
    "-1 1 +" 
    " 1 1 +"
    "1 1 + "
    "1           1         + "
    "         1 1 + "
    "1 1 +" 
    "1 1 -" 
    "1 1 *"
    "1 1 /"
    "8 9 * 9 - 9 - 9 - 4 - 1 +"
    "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
    "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
    "0"
    "9"
    "-9"
)

errorTestCases=(
    ""
    "(1 + 1)"
    "10"
    "-10"
    "1 1 "
    "1 + "
    "+ 1 1"
    "1 1 + *"
    "1 1111111111111111111111111111111111111111111111111111111111111111 +"
)

# 8 9 * 9 - 9 - 9 - 4 - 1 +
#   > Result: 42
  
#   9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -
#   > Result: 42
  
#   1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / 
#   > Result: 15

echo CORRECT Test Cases
echo
for element in "${correctTestCases[@]}"; do
    test "$element"
done
echo
echo ERROR Test Cases
echo
for element in "${errorTestCases[@]}"; do
    test "$element"
done
