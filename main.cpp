#include <iostream>
#include "large/number.hpp"

int main(int argc, char *argv[])
{
    Large::Number x = -25;
    Large::Number y = -10;

    std::cout << "x = " << x << "\ny = " << y << "\n" << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    return 0;
}
