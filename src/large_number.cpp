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

#include "large_number.hpp"

namespace Large
{

    LargeNumber::LargeNumber() : _num(0)
    {

    }

    LargeNumber::LargeNumber(const int &n) : _num(n)
    {

    }

    LargeNumber::LargeNumber(const char *str) : _num(str)
    {

    }

    LargeNumber::LargeNumber(const std::string &str) : _num(str)
    {

    }

    LargeNumber::LargeNumber(const LargeNumberType &lnumt) : _num(lnumt)
    {

    }

    LargeNumber::~LargeNumber()
    {

    }


    unsigned int LargeNumber::size() const
    {
        return this->_num.size();
    }

    std::string LargeNumber::string() const
    {
        return this->_num.string();
    }

    int LargeNumber::compare(const LargeNumber &rhs) const
    {
        return this->_num.compare(rhs._num);
    }


    LargeNumber & LargeNumber::add(const LargeNumber &rhs)
    {
        LargeNumber x(*this);
        LargeNumber y(rhs);
        LargeNumber result;

        bool positive = true;

        if (x._num.positive() && y._num.positive())
            result = ComputingHandler::add(x, y);
        else if (x._num.positive() && !y._num.positive()) {
            y._num.positive(true);

            if (x >= y)
                result = ComputingHandler::sub(x, y);
            else {
                result = ComputingHandler::sub(y, x);
                positive = false;
            }
        }
        else if (!x._num.positive() && y._num.positive()) {
            x._num.positive(true);

            if (x <= y)
                result = ComputingHandler::sub(y, x);
            else {
                result = ComputingHandler::sub(x, y);
                positive = false;
            }
        }
        else  {
            x._num.positive(true);
            y._num.positive(true);
            positive = false;

            result = ComputingHandler::add(x, y);
        }

        result._num.positive(positive);

        this->_num = result._num;

        return *this;
    }

    LargeNumber & LargeNumber::sub(const LargeNumber &rhs)
    {
        LargeNumber x(*this);
        LargeNumber y(rhs);
        LargeNumber result;

        bool positive = true;

        if (x._num.positive() && y._num.positive()) {
            if (x >= y)
                result = ComputingHandler::sub(x, y);
            else {
                result = ComputingHandler::sub(y, x);
                positive = false;
            }
        }
        else if (x._num.positive() && !y._num.positive()) {
            y._num.positive(true);

            result = ComputingHandler::add(x, y);
        }
        else if (!x._num.positive() && y._num.positive()) {
            x._num.positive(true);
            positive = false;

            result = ComputingHandler::add(x, y);
        }
        else  {
            x._num.positive(true);
            y._num.positive(true);

            if (x >= y) {
                result = ComputingHandler::sub(x, y);
                positive = false;
            }
            else
                result = ComputingHandler::sub(y, x);
        }

        result._num.positive(positive);

        this->_num = result._num;

        return *this;
    }

    LargeNumber & LargeNumber::mul(const LargeNumber &rhs)
    {
        LargeNumber x(*this);
        LargeNumber y(rhs);

        bool positive = !(x._num.positive() ^ y._num.positive());

        x._num.positive(true);
        y._num.positive(true);

        LargeNumber result = ComputingHandler::mul(x, y);

        result._num.positive(positive);

        this->_num = result._num;

        return *this;
    }

    LargeNumber & LargeNumber::div(const LargeNumber &rhs)
    {
        LargeNumber x(*this);
        LargeNumber y(rhs);

        bool positive = !(x._num.positive() ^ y._num.positive());

        x._num.positive(true);
        y._num.positive(true);

        LargeNumber result = ComputingHandler::div(x, y);

        result._num.positive(positive);

        this->_num = result._num;

        return *this;
    }


    LargeNumber operator+ (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumber retval(lhs);
        return retval.add(rhs);
    }

    LargeNumber operator- (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumber retval(lhs);
        return retval.sub(rhs);
    }

    LargeNumber operator* (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumber retval(lhs);
        return retval.mul(rhs);
    }

    LargeNumber operator/ (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        LargeNumber retval(lhs);
        return retval.div(rhs);
    }

    bool operator> (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) > 0;
    }

    bool operator< (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) < 0;
    }

    bool operator>= (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) >= 0;
    }

    bool operator<= (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) <= 0;
    }

    bool operator== (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) == 0;
    }

    bool operator!= (const LargeNumber &lhs, const LargeNumber &rhs)
    {
        return lhs.compare(rhs) != 0;
    }

    std::ostream & operator<< (std::ostream &os, const LargeNumber &num)
    {
        return os << num.string();
    }

}
