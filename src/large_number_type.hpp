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

#ifndef LARGE_NUMBER_TYPE_HPP
#define LARGE_NUMBER_TYPE_HPP

#include <vector>
#include <string>

namespace Large
{

    class LargeNumberType
    {
    private:
        std::vector<char> _data;
        bool _positive;

        void _initializer(const std::string &str);

    public:
        LargeNumberType();
        LargeNumberType(const int &n);
        LargeNumberType(const char *&str);
        LargeNumberType(const std::string &str);
        ~LargeNumberType();

        bool positive() const;
        void positive(const bool &sign);

        unsigned int size() const;
        std::string string() const;
        int compare(const LargeNumberType &rhs) const;

        int at(unsigned int index) const;
        void at(unsigned int index, int num);

        void pop();
        void push(int num);
    };

}

#include "large_number_type.inl"

#endif
