#include <iostream>
#include <number.hpp>

int main(int argc, char *argv[])
{
    Large::Number x("78962132878965235699846513216889615615631868464612316613153153153521898");
    Large::Number y("813048956");

    std::cout << "x = " << x << "\ny = " << y << "\n" << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    return 0;
}
