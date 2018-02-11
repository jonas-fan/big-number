#include <big_number_utils.hpp>


/**
 *    Public methods
 */

int BigNumber::char2integer(char charactor)
{
    return charactor - '0';
}

char BigNumber::integer2char(int integer)
{
    return integer + '0';
}