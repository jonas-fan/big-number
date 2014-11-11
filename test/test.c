#include <big_number.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    BigNumber *x = big_number_create("123456");
    BigNumber *y = big_number_create("234");

    big_number_add(x, y);

    char *value = big_number_print(x);

    printf("%s\n", value);

    free(value);

    big_number_destroy(y);
    big_number_destroy(x);

    return 0;
}