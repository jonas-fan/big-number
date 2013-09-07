/**
 *
 * The basic type of large number.
 *
 *
 * @version 1.0
 *
 * @author Jian <john33550@gmail.com>
 * @date   2013/09/07
 *
 */

#include "large_number_type.hpp"
#include <algorithm>
#include <sstream>

namespace Large
{

    void LargeNumberType::_initializer(const std::string &str)
    {
        this->_data = std::vector<char>(str.begin(), str.end());

        std::reverse(this->_data.begin(), this->_data.end());

        if (this->_data.size() && this->_data.back() == '-') {
            this->_data.pop_back();
            this->positive(false);
        }
    }

    LargeNumberType::LargeNumberType() : _positive(true)
    {

    }

    LargeNumberType::LargeNumberType(const int &n) : _positive(true)
    {
        std::ostringstream buffer;

        buffer << n;

        this->_initializer(buffer.str());
    }

    LargeNumberType::LargeNumberType(const char *&str) : _positive(true)
    {
        this->_initializer(std::string(str));
    }

    LargeNumberType::LargeNumberType(const std::string &str) : _positive(true)
    {
        this->_initializer(str);
    }

    LargeNumberType::~LargeNumberType()
    {

    }


    bool LargeNumberType::positive() const
    {
        return this->_positive;
    }

    void LargeNumberType::positive(const bool &sign)
    {
        this->_positive = sign;
    }


    unsigned int LargeNumberType::size() const
    {
        return this->_data.size();
    }

    std::string LargeNumberType::string() const
    {
        std::string retval(this->_data.begin(), this->_data.end());

        std::reverse(retval.begin(), retval.end());

        if (this->positive())
            return retval;

        if ((retval.size() == 1) && (retval.at(0) == '0'))
            return retval;

        retval = "-" + retval;

        return retval;
    }

    int LargeNumberType::compare(const LargeNumberType &rhs) const
    {
        const LargeNumberType *left = this;
        const LargeNumberType *right = &rhs;

        if (left->positive() && !right->positive())
            return 1;

        if (!left->positive() && right->positive())
            return -1;

        if (!left->positive() && !right->positive())
            std::swap<const LargeNumberType *>(left, right);

        if (left->size() > right->size())
            return 1;

        if (left->size() < right->size())
            return -1;

        for (int index = left->size() - 1; index > -1; --index) {
            if (left->at(index) > right->at(index))
                return 1;

            if (left->at(index) < right->at(index))
                return -1;
        }

        return 0;
    }


    int LargeNumberType::at(unsigned int index) const
    {
        if (index < this->_data.size())
            return Large::c2I(this->_data.at(index));

        return 0;
    }

    void LargeNumberType::at(unsigned int index, int num)
    {
        if (index < this->_data.size())
            this->_data.at(index) = Large::i2C(num);
    }

    void LargeNumberType::pop()
    {
        this->_data.pop_back();
    }

    void LargeNumberType::push(int num)
    {
        this->_data.push_back(i2C(num));
    }

}
