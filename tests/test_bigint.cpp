#include <bigint.h>
#include <iostream>
#include <cassert>

int main(int argc, char *argv[])
{
    BigInt num1("123456789123456789");
    BigInt num2("987654321987654321");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "1111111111111111110");

    num3 = num2 - num1;
    assert(num3.string() == "864197532864197532");

    num3 = num1 * num2;
    assert(num3.string() == "121932631356500531347203169112635269");

    num3 = num2 / num1;
    assert(num3.string() == "8");

    std::cout << "OK" << std::endl;

    return 0;
}