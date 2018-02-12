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
    BigInt & operator *= (const BigInt &rhs);
    BigInt & operator /= (const BigInt &rhs);

    bool operator > (const BigInt &rhs) const;
    bool operator >= (const BigInt &rhs) const;
    bool operator < (const BigInt &rhs) const;
    bool operator <= (const BigInt &rhs) const;
    bool operator == (const BigInt &rhs) const;
    bool operator != (const BigInt &rhs) const;

    int compare(const BigInt &rhs) const;
    std::string string() const;

private:
    void assign(const std::string &value);
    void trim();

    void add(const BigInt &rhs);
    void sub(const BigInt &rhs);

    BigInt add_(const BigInt &rhs);
    BigInt sub_(const BigInt &rhs);

private:
    bool positive_;
    std::vector<int> data_;
};

#endif /* __BIG_INTEGER_H__ */