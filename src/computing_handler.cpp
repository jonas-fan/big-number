/**
 *
 * The basic computing of large number.
 *
 *
 * @version 1.0
 *
 * @author Jian <john33550@gmail.com>
 * @date   2013/09/07
 *
 */

#include "computing_handler.hpp"

namespace Large
{

    LargeNumber ComputingHandler::add(const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumberType retval;
        const LargeNumberType &x = lhs._num;
        const LargeNumberType &y = rhs._num;

        unsigned int length = (x.compare(y) > 0)?  x.size() : y.size();
        bool carry = false;

        for (unsigned int index = 0; index < length; ++index) {
            int val = x.at(index) + y.at(index) + carry;
            carry = (val >= 10);
            retval.push(val % 10);
        }

        if (carry)
            retval.push(carry);

        return retval;
    }

    LargeNumber ComputingHandler::sub(const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumberType retval;
        const LargeNumberType &x = lhs._num;
        const LargeNumberType &y = rhs._num;

        unsigned int length = x.size();
        unsigned int index;
        bool carry = false;

        for (index = 0; index < length; ++index) {
            int val = x.at(index) - y.at(index) - carry;

            if (val < 0) {
                val += 10;
                carry = true;
            }
            else
                carry = false;

            retval.push(val % 10);
        }

        index = length - 1;

        while (index && retval.at(index--) == 0)
            retval.pop();

        return retval;
    }

    LargeNumber ComputingHandler::mul(const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumberType retval;
        const LargeNumberType &x = lhs._num;
        const LargeNumberType &y = rhs._num;

        for (unsigned int xIndex = 0; xIndex < x.size(); ++xIndex) {
            int carry = 0;

            for (unsigned int yIndex = 0; yIndex < y.size(); ++yIndex) {
                int val = x.at(xIndex) * y.at(yIndex) + carry + retval.at(xIndex + yIndex);

                carry = val / 10;
                val %= 10;

                if (xIndex + yIndex < retval.size())
                    retval.at(xIndex + yIndex, val);
                else
                    retval.push(val);
            }

            if (carry)
                retval.push(carry);
        }

        unsigned int index = retval.size() - 1;

        while (index && retval.at(index--) == 0)
            retval.pop();

        return retval;
    }

    LargeNumber ComputingHandler::div(const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumber retval;
        LargeNumber x(lhs);
        LargeNumber y(rhs);

        for (int index = x.size() - y.size() + 1; index > 0 && x > 0; --index) {
            std::string initializer(index, '0');

            for (int number = 9; number > 0; --number) {
                initializer.at(0) = Large::i2C(number);

                LargeNumber buff(initializer);
                LargeNumber divisor(y * buff);

                if (divisor > x)
                    continue;

                x = x - divisor;
                retval = retval + buff;
            }
        }

        return retval;
    }

}
