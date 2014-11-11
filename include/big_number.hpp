#ifndef BIG_NUMBER_HPP_
#define BIG_NUMBER_HPP_

#include <big_number_integer.hpp>

namespace BigNumber
{

/**
 *    The big number.
 *
 *
 *    @version 0.1.2
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

class Number
{
    friend class Math;

public:
    Number();
    Number(const int &n);
    Number(const std::string &string);
    Number(const BigNumber::Integer &number);
    virtual ~Number();

    unsigned int size() const;
    std::string string() const;

    int compare(const BigNumber::Number &rhs) const;

    void add(const BigNumber::Number &rhs);
    void sub(const BigNumber::Number &rhs);
    void mul(const BigNumber::Number &rhs);
    void div(const BigNumber::Number &rhs);

private:
    BigNumber::Integer num_;
};

} // namespace BigNumber

#include <big_number.inl>

BigNumber::Number operator + (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
BigNumber::Number operator - (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
BigNumber::Number operator * (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
BigNumber::Number operator / (const BigNumber::Number &lhs, const BigNumber::Number &rhs);

bool operator > (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
bool operator < (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
bool operator >= (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
bool operator <= (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
bool operator == (const BigNumber::Number &lhs, const BigNumber::Number &rhs);
bool operator != (const BigNumber::Number &lhs, const BigNumber::Number &rhs);

std::ostream & operator << (std::ostream &os, const BigNumber::Number &num);

#endif  /* BIG_NUMBER_HPP_ */