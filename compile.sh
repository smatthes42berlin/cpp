clear

make

sleep 1
if [ $# -gt 0 ]; then
    valgrind --leak-check=full --show-leak-kinds=all ./exe
else
    ./test
fi
