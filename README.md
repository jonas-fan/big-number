# bigint
[![Build Status](https://travis-ci.org/jonas-fan/bigint.svg)](https://travis-ci.org/jonas-fan/bigint)

(This project is not done yet)

An implementation of big integer in C++.

## Usage
```cpp
BigInt num1("123456789123456789");
BigInt num2("987654321987654321");
BigInt num3;

// 1111111111111111110
num3 = num1 + num2;

// -864197532864197532
num3 = num1 - num2;

// 121932631356500531347203169112635269
num3 = num1 * num2;

// 8
num3 = num2 / num1;
```