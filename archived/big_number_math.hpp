#ifndef BIG_NUMBER_MATH_HPP_
#define BIG_NUMBER_MATH_HPP_

#include <big_number.hpp>

namespace BigNumber
{

/**
 *    The basic math computing of big number.
 *
 *    @version 0.1.2
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

class Math
{
public:
    static BigNumber::Number add(const BigNumber::Number &lhs, const BigNumber::Number &rhs);
    static BigNumber::Number sub(const BigNumber::Number &lhs, const BigNumber::Number &rhs);
    static BigNumber::Number mul(const BigNumber::Number &lhs, const BigNumber::Number &rhs);
    static BigNumber::Number div(const BigNumber::Number &lhs, const BigNumber::Number &rhs);
};

} // namespace BigNumber

#endif  /* BIG_NUMBER_MATH_HPP_ */