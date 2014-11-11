#include <big_number.h>
#include <big_number_type.h>

#include <stdlib.h>


/**
 *    Private
 */

struct big_number_t
{
    BigNumberType *value;
};


/**
 *    Public methods
 */

BigNumber * big_number_create(const char *string)
{
    BigNumberType *value = big_number_type_create(string);

    if (!value) {
        return NULL;
    }

    BigNumber *number = (BigNumber *)malloc(sizeof(BigNumber));

    if (!number) {
        big_number_type_destroy(value);

        return NULL;
    }

    number->value = value;

    return number;
}

void big_number_destroy(BigNumber *big_number)
{
    big_number_type_destroy(big_number->value);

    free(big_number);
}

char * big_number_print(BigNumber *big_number)
{
    return big_number_type_print(big_number->value);
}

void big_number_add(BigNumber *lhs, BigNumber *rhs)
{
    // TODO
}

void big_number_sub(BigNumber *lhs, BigNumber *rhs)
{
    // TODO
}

void big_number_mul(BigNumber *lhs, BigNumber *rhs)
{
    // TODO
}

void big_number_div(BigNumber *lhs, BigNumber *rhs)
{
    // TODO
}