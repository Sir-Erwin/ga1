#Compile the code
# if the file ${cmd} exits then remove it

if [ -f exec ]; then
    rm exec
fi

g++ -std=c++11 *.cpp -o exec
# if the file ${cmd} does not exit then exit the test
if [ ! -f exec ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi

./exec
