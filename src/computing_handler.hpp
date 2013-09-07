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

#ifndef LARGE_NUMBER_COMPUTING_HANDLER_HPP
#define LARGE_NUMBER_COMPUTING_HANDLER_HPP

#include "large_number.hpp"

namespace Large
{

    class LargeNumber;

    class ComputingHandler
    {
    public:
        static LargeNumber add(const LargeNumber &lhs, const LargeNumber &rhs);
        static LargeNumber sub(const LargeNumber &lhs, const LargeNumber &rhs);
        static LargeNumber mul(const LargeNumber &lhs, const LargeNumber &rhs);
        static LargeNumber div(const LargeNumber &lhs, const LargeNumber &rhs);
    };

}

#endif
