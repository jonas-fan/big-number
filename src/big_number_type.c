#include <big_number_type.h>

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/**
 *    Private
 */

static bool isValidNumber(const char *string);


/**
 *    Public methods
 */

BigNumberType * big_number_type_create(const char *string)
{
    if (!isValidNumber(string)) {
        return NULL;
    }

    BigNumberType *value = (BigNumberType *)malloc(sizeof(BigNumberType));

    if (!value) {
        return NULL;
    }

    memset(value, 0, sizeof(*value));

    value->size = strlen(string);
    value->data = (char *)malloc(sizeof(char) * (value->size + 1));

    if (!value->data) {
        big_number_type_destroy(value);

        return NULL;
    }

    memset(value->data, 0, value->size + 1);
    memcpy(value->data, string, value->size + 1);

    return value;
}

void big_number_type_destroy(BigNumberType *value)
{
    free(value->data);
    free(value);
}

char * big_number_type_print(BigNumberType *value)
{
    const unsigned int buffer_size = sizeof(char) * (value->size + 1);

    char *buffer = (char *)malloc(buffer_size);

    if (!buffer) {
        return NULL;
    }

    memcpy(buffer, value->data, buffer_size);

    return buffer;
}


/**
 *    Private
 */

static bool isValidNumber(const char *string)
{
    const char *iterator = string;

    while (*iterator) {
        if (*iterator < '0' ||
            *iterator > '9')
        {
            return false;
        }

        ++iterator;
    }

    return true;
}