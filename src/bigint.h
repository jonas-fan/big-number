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

    // operations
    BigInt operator + (const BigInt &rhs) const;
    BigInt operator - (const BigInt &rhs) const;
    BigInt operator * (const BigInt &rhs) const;
    BigInt operator / (const BigInt &rhs) const;
    BigInt & operator += (const BigInt &rhs);
    BigInt & operator -= (const BigInt &rhs);
    BigInt & operator *= (const BigInt &rhs);
    BigInt & operator /= (const BigInt &rhs);

    // comparers
    int compare(const BigInt &rhs) const;
    bool operator > (const BigInt &rhs) const;
    bool operator >= (const BigInt &rhs) const;
    bool operator < (const BigInt &rhs) const;
    bool operator <= (const BigInt &rhs) const;
    bool operator == (const BigInt &rhs) const;
    bool operator != (const BigInt &rhs) const;

    // helpers
    BigInt abs() const;
    std::string string() const;

private:
    void assign(const std::string &value);
    void trim();

private:
    bool positive_;
    std::vector<int> data_;
};

#endif /* __BIG_INTEGER_H__ */