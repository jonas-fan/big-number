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

    // Increment & Decrement
    BigInt & operator ++ ();
    BigInt   operator ++ (int);
    BigInt & operator -- ();
    BigInt   operator -- (int);

    // Arithmetic
    BigInt operator + (int rhs) const;
    BigInt operator + (const BigInt &rhs) const;
    BigInt operator - (int rhs) const;
    BigInt operator - (const BigInt &rhs) const;
    BigInt operator * (int rhs) const;
    BigInt operator * (const BigInt &rhs) const;
    BigInt operator / (const BigInt &rhs) const;

    // Assignment
    BigInt & operator += (const BigInt &rhs);
    BigInt & operator -= (const BigInt &rhs);
    BigInt & operator *= (const BigInt &rhs);
    BigInt & operator /= (const BigInt &rhs);

    // Comparsion
    bool operator >  (const BigInt &rhs) const;
    bool operator >= (const BigInt &rhs) const;
    bool operator <  (const BigInt &rhs) const;
    bool operator <= (const BigInt &rhs) const;
    bool operator == (const BigInt &rhs) const;
    bool operator != (const BigInt &rhs) const;

    // Others
    std::string string() const;
    BigInt abs() const;
    int compare(const BigInt &rhs) const;

private:
    void assign(const std::string &value);
    void trim();

private:
    bool positive_;
    std::vector<int> data_;
};

#endif /* __BIG_INTEGER_H__ */