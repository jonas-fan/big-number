#include <iostream>
#include "large_number.hpp"

int main(int argc, char *argv[])
{
    Large::LargeNumber x = -25;
    Large::LargeNumber y = -10;

    std::cout << "x = " << x << "\ny = " << y << "\n" << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    return 0;
}
