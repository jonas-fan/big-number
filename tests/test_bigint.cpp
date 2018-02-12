#include <bigint.h>
#include <iostream>

int main(int argc, char *argv[])
{
    BigInt num1("1234567890");
    BigInt num2("23456");

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << (num1 < num2) << std::endl;
    std::cout << (num1 > num2) << std::endl;
    std::cout << (num1 + num2) << std::endl;
    std::cout << (num1 - num2) << std::endl;
    std::cout << (num1 * num2) << std::endl;
    std::cout << (num1 / num2) << std::endl;

    return 0;
}