/**
 *
 * The large number.
 *
 *
 * @version 1.0
 *
 * @author Jian <john33550@gmail.com>
 * @date   2013/09/07
 *
 */

#ifndef LARGE_NUMBER_HPP
#define LARGE_NUMBER_HPP

#include "large_number_type.hpp"
#include "computing_handler.hpp"
#include <iostream>
#include <string>

namespace Large
{

    class LargeNumber
    {

    private:
        LargeNumberType _num;

    public:
        LargeNumber();
        LargeNumber(const int &n);
        LargeNumber(const char *str);
        LargeNumber(const std::string &str);
        LargeNumber(const LargeNumberType &lnumt);
        ~LargeNumber();

        unsigned int size() const;
        std::string string() const;
        int compare(const LargeNumber &rhs) const;

        LargeNumber & add(const LargeNumber &rhs);
        LargeNumber & sub(const LargeNumber &rhs);
        LargeNumber & mul(const LargeNumber &rhs);
        LargeNumber & div(const LargeNumber &rhs);

        friend class ComputingHandler;

        friend LargeNumber operator+ (const LargeNumber &lhs, const LargeNumber &rhs);
        friend LargeNumber operator- (const LargeNumber &lhs, const LargeNumber &rhs);
        friend LargeNumber operator* (const LargeNumber &lhs, const LargeNumber &rhs);
        friend LargeNumber operator/ (const LargeNumber &lhs, const LargeNumber &rhs);

        friend bool operator> (const LargeNumber &lhs, const LargeNumber &rhs);
        friend bool operator< (const LargeNumber &lhs, const LargeNumber &rhs);
        friend bool operator>= (const LargeNumber &lhs, const LargeNumber &rhs);
        friend bool operator<= (const LargeNumber &lhs, const LargeNumber &rhs);
        friend bool operator== (const LargeNumber &lhs, const LargeNumber &rhs);
        friend bool operator!= (const LargeNumber &lhs, const LargeNumber &rhs);

        friend std::ostream & operator<< (std::ostream &os, const LargeNumber &num);
    };

}

#endif
