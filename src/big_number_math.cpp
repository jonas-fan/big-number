#include <big_number_math.hpp>
#include <big_number_utils.hpp>


/**
 *    Public methods
 */

BigNumber::Number BigNumber::Math::add(const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Integer result;

    const BigNumber::Integer &x = lhs.num_;
    const BigNumber::Integer &y = rhs.num_;

    const unsigned int length = (lhs > rhs)?  lhs.size() : rhs.size();

    unsigned int carry = 0;

    for (unsigned int index = 0; index < length; ++index) {
        const int value = x.at(index) + y.at(index) + carry;

        carry = value / 10;

        result.push(value % 10);
    }

    if (carry) {
        result.push(carry);
    }

    return result;
}

BigNumber::Number BigNumber::Math::sub(const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Integer result;

    const BigNumber::Integer &x = lhs.num_;
    const BigNumber::Integer &y = rhs.num_;

    const unsigned int length = x.size();

    unsigned int index;

    bool borrow = false;

    for (index = 0; index < length; ++index) {
        const int value = x.at(index) - y.at(index) - borrow;

        borrow = (value < 0);

        result.push((value + 10) % 10);
    }

    index = length - 1;

    while (index &&
           result.at(index--) == 0)
    {
        result.pop();
    }

    return result;
}

BigNumber::Number BigNumber::Math::mul(const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Integer result;

    const BigNumber::Integer &x = lhs.num_;
    const BigNumber::Integer &y = rhs.num_;

    for (unsigned int xIndex = 0; xIndex < x.size(); ++xIndex) {
        unsigned int carry = 0;

        for (unsigned int yIndex = 0; yIndex < y.size(); ++yIndex) {
            const unsigned int value = x.at(xIndex) * y.at(yIndex) +
                                       carry +
                                       result.at(xIndex + yIndex);

            carry = value / 10;

            if (xIndex + yIndex < result.size()) {
                result.at(xIndex + yIndex, value % 10);
            }
            else {
                result.push(value % 10);
            }
        }

        if (carry) {
            result.push(carry);
        }
    }

    unsigned int index = result.size() - 1;

    while (index &&
           result.at(index--) == 0)
    {
        result.pop();
    }

    return result;
}

BigNumber::Number BigNumber::Math::div(const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Number result;
    BigNumber::Number x(lhs);
    BigNumber::Number y(rhs);

    if (y == 0) {
        return result;
    }

    for (int index = x.size() - y.size() + 1;
         index > 0 && x > 0;
         --index)
    {
        std::string initializer(index, '0');

        for (unsigned int number = 9; number > 0; --number) {
            initializer.at(0) = BigNumber::integer2char(number);

            BigNumber::Number buff(initializer);
            BigNumber::Number product(y * buff);

            if (product > x) {
                continue;
            }

            x.sub(product);

            result.add(buff);
        }
    }

    return result;
}