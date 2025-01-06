clear
make re


test()
{
    lowerBound=$1
    upperBound=$2
    numberElem=$3
    testNumbers=`shuf -i ${lowerBound}-${upperBound} -n ${numberElem} | tr "\n" " "`
    echo "BASH GENERATED RANDOM TEST NUMBERS: " $testNumbers
    echo -n "NUMBERS COMING FROM PROGRAM: "
    ./PmergeMe $testNumbers
}


test 1 5000 3000;
exit
echo
echo
test 1 10 10;