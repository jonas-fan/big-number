# Big Number
[![Build Status](https://travis-ci.org/yjfan/big-number.svg)](https://travis-ci.org/yjfan/big-number)

Implement big number in C++

## Build
```bash
$ git clone https://github.com/yjfan/big-number.git
$ cd big-number/build
$ cmake ..
$ make
$ ./test/test
```

## Example
```cpp
BigNumber::Number x("78962132878965235699846513216889615615631868464612316613153153153521898");
BigNumber::Number y("813048956");

std::cout << "x = " << x << "\ny = " << y << "\n" << std::endl;

std::cout << "x + y = " << x + y << std::endl;
std::cout << "x - y = " << x - y << std::endl;
std::cout << "x * y = " << x * y << std::endl;
std::cout << "x / y = " << x / y << std::endl;
```