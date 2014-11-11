#include <big_number_utils.hpp>


/**
 *    Public methods
 */

int BigNumber::c2I(const char &c)
{
    return c - '0';
}

char BigNumber::i2C(const int &i)
{
    return i + '0';
}