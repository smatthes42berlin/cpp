clear

make re

sleep 1


filename="infile.txt"
outfilename="${filename}.replace"

runTestCase() {
    testCase=$1
    searchString=$2
    replaceString=$3

    echo
    echo "******************Start Test Case***********************"
    echo TESTCASE = $testCase
    echo Function call = ./replacer $filename $searchString $replaceString
    echo

    ./replacer "$filename" "$searchString" "$replaceString"

    echo "before"
    echo
    cat "${filename}"
    echo
    echo "_______________________________________"
    echo
    echo "after"
    echo
    cat $outfilename
    echo "////////////////////////End Test Case//////////////////////"
}


cat <<EOF >"$filename"
AAA
BBB
AAA
BBBAA
AAA AAA AAA AAA 
EOF

runTestCase normal AAA ZZZ
# ---------------------------------------
runTestCase "search string no match" "1234" ZZZ
# ---------------------------------------
runTestCase "empty search string" "" ZZZ
# ---------------------------------------
runTestCase "empty replace string" "AAA" ""
# ---------------------------------------
chmod -777 $filename
runTestCase "no access rights infile" "AAA" "ZZZ"
chmod +777 $filename
# ---------------------------------------
chmod -777 $outfilename
runTestCase "no access rights otufile" "AAA" "ZZZ"
chmod +777 $outfilename
# ---------------------------------------
rm $filename
runTestCase "non existent file" "AAA" "ZZZ"
# ---------------------------------------
cat <<EOF >"$filename"
EOF

runTestCase empty file AAA ZZZ


