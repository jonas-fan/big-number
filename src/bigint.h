#ifndef __BIG_INTEGER_H__
#define __BIG_INTEGER_H__

#include <string>
#include <vector>

class BigInt
{
public:
    BigInt();
    BigInt(long long int value);
    BigInt(const std::string &value);
    virtual ~BigInt();

    void add(const BigInt &rhs);
    void sub(const BigInt &rhs);
    void mul(const BigInt &rhs);
    void div(const BigInt &rhs);

    int compare(const BigInt &rhs) const;
    std::string string() const;

private:
    void assign(const std::string &value);

    BigInt add_(const BigInt &rhs);
    BigInt sub_(const BigInt &rhs);
    BigInt mul_(const BigInt &rhs);
    BigInt div_(const BigInt &rhs);

private:
    bool positive_;
    std::vector<int> data_;
};

BigInt operator + (const BigInt &lhs, const BigInt &rhs);
BigInt operator - (const BigInt &lhs, const BigInt &rhs);
BigInt operator * (const BigInt &lhs, const BigInt &rhs);
BigInt operator / (const BigInt &lhs, const BigInt &rhs);

bool operator > (const BigInt &lhs, const BigInt &rhs);
bool operator >= (const BigInt &lhs, const BigInt &rhs);
bool operator < (const BigInt &lhs, const BigInt &rhs);
bool operator <= (const BigInt &lhs, const BigInt &rhs);
bool operator == (const BigInt &lhs, const BigInt &rhs);
bool operator != (const BigInt &lhs, const BigInt &rhs);

std::ostream & operator << (std::ostream &os, const BigInt &num);

#endif /* __BIG_INTEGER_H__ */