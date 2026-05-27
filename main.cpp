#include <iostream>
#include <string>

void alterNum(int &x)
{
    x = 10;
}

int main()
{

    std::string myStrint = "test";
    std::cout << myStrint;

    int myNum = 20;
    std::cout << myNum;

    alterNum(myNum);
    std::cout << myNum;
}