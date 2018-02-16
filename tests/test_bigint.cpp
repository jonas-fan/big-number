#include <bigint.h>
#include <iostream>
#include <cassert>

static void test1()
{
    BigInt num1("123456789123456789");
    BigInt num2("987654321987654321");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "1111111111111111110");

    num3 = num1 - num2;
    assert(num3.string() == "-864197532864197532");

    num3 = num1 * num2;
    assert(num3.string() == "121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "0");
}

static void test2()
{
    BigInt num1("123456789123456789");
    BigInt num2("-987654321987654321");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "-864197532864197532");

    num3 = num1 - num2;
    assert(num3.string() == "1111111111111111110");

    num3 = num1 * num2;
    assert(num3.string() == "-121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "0");
}

static void test3()
{
    BigInt num1("-123456789123456789");
    BigInt num2("987654321987654321");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "864197532864197532");

    num3 = num1 - num2;
    assert(num3.string() == "-1111111111111111110");

    num3 = num1 * num2;
    assert(num3.string() == "-121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "0");
}

static void test4()
{
    BigInt num1("-123456789123456789");
    BigInt num2("-987654321987654321");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "-1111111111111111110");

    num3 = num1 - num2;
    assert(num3.string() == "864197532864197532");

    num3 = num1 * num2;
    assert(num3.string() == "121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "0");
}

static void test5()
{
    BigInt num1("987654321987654321");
    BigInt num2("123456789123456789");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "1111111111111111110");

    num3 = num1 - num2;
    assert(num3.string() == "864197532864197532");

    num3 = num1 * num2;
    assert(num3.string() == "121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "8");
}

static void test6()
{
    BigInt num1("987654321987654321");
    BigInt num2("-123456789123456789");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "864197532864197532");

    num3 = num1 - num2;
    assert(num3.string() == "1111111111111111110");

    num3 = num1 * num2;
    assert(num3.string() == "-121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "-8");
}

static void test7()
{
    BigInt num1("-987654321987654321");
    BigInt num2("123456789123456789");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "-864197532864197532");

    num3 = num1 - num2;
    assert(num3.string() == "-1111111111111111110");

    num3 = num1 * num2;
    assert(num3.string() == "-121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "-8");
}

static void test8()
{
    BigInt num1("-987654321987654321");
    BigInt num2("-123456789123456789");
    BigInt num3;

    num3 = num1 + num2;
    assert(num3.string() == "-1111111111111111110");

    num3 = num1 - num2;
    assert(num3.string() == "-864197532864197532");

    num3 = num1 * num2;
    assert(num3.string() == "121932631356500531347203169112635269");

    num3 = num1 / num2;
    assert(num3.string() == "8");
}

static void test9()
{
    BigInt num1("123456789123456789");
    BigInt num2("987654321987654321");

    num1 += num2;
    assert(num1.string() == "1111111111111111110");

    num1 -= num2;
    assert(num1.string() == "123456789123456789");

    num1 *= num2;
    assert(num1.string() == "121932631356500531347203169112635269");

    num1 /= num2;
    assert(num1.string() == "123456789123456789");
}

static void test10()
{
    BigInt num1("123456789123456789");
    BigInt num2("-123456789123456789");
    BigInt num3;

    num3 = num1.abs();
    assert(num3.string() == "123456789123456789");

    num3 = num2.abs();
    assert(num3.string() == "123456789123456789");
}

static void test11()
{
    BigInt num1("123456789123456789");
    BigInt num2;

    num2 = num1++;
    assert(num1.string() == "123456789123456790");
    assert(num2.string() == "123456789123456789");

    num2 = ++num1;
    assert(num1.string() == "123456789123456791");
    assert(num2.string() == "123456789123456791");

    num2 = num1--;
    assert(num1.string() == "123456789123456790");
    assert(num2.string() == "123456789123456791");

    num2 = --num1;
    assert(num1.string() == "123456789123456789");
    assert(num2.string() == "123456789123456789");
}

int main(int argc, char *argv[])
{
    std::cout << "Running test1 ..." << std::endl;
    test1();

    std::cout << "Running test2 ..." << std::endl;
    test2();

    std::cout << "Running test3 ..." << std::endl;
    test3();

    std::cout << "Running test4 ..." << std::endl;
    test4();

    std::cout << "Running test5 ..." << std::endl;
    test5();

    std::cout << "Running test6 ..." << std::endl;
    test6();

    std::cout << "Running test7 ..." << std::endl;
    test7();

    std::cout << "Running test8 ..." << std::endl;
    test8();

    std::cout << "Running test9 ..." << std::endl;
    test9();

    std::cout << "Running test10 ..." << std::endl;
    test10();

    std::cout << "Running test11 ..." << std::endl;
    test11();

    std::cout << "OK" << std::endl;

    return 0;
}