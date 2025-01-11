# clear
# make re

test()
{
    lowerBound=$1
    upperBound=$2
    numberElem=$3
    testNumbers=`shuf -i ${lowerBound}-${upperBound} -n ${numberElem} | tr "\n" " "`
    ./PmergeMe $testNumbers
}

test 1 100 11;

exit 

echo ERROR CASES
echo
./PmergeMe 1 2 3 4 5 5
./PmergeMe 1 2 3 4 5 -1
./PmergeMe 1 2 3 4 5 999999999999999999999999999999999999999999999
./PmergeMe 1 2 3 4 5 -999999999999999999999999999999999999999999999
./PmergeMe 1 2 3 4 5 a
echo
echo
echo Valid Cases
echo
./PmergeMe 1
echo
./PmergeMe 1 2
echo
./PmergeMe 2 1
echo
./PmergeMe 3 2 1
echo
./PmergeMe 2 1 3
echo
./PmergeMe 1 2 3
echo
./PmergeMe 1 2 3 4 5
echo
./PmergeMe 5 4 3 2 1
echo
./PmergeMe 4 5 1 3 2
echo
./PmergeMe 1 2 3 4 5 6 7 8 9 10 11
echo
./PmergeMe 11 2 5 6 9 7 4 3 10 8
echo
./PmergeMe 11 10 9 8 7 6 5 4 3 2 1 
echo
echo 100 Numbers
test 1 101 100;
echo 1000 Numbers
test 1 1001 1000;
echo 3000 Numbers
test 1 3001 300;
echo 5000 Numbers
test 1 5001 5000;


testNumbers=`shuf -i 1-101 -n 100 | tr "\n" " "`
valgrind ./PmergeMe $testNumbers