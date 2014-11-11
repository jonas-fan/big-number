#ifndef BIG_NUMBER_TYPE_H_
#define BIG_NUMBER_TYPE_H_

/**
 *    Big number type
 *
 *    @version 0.1.0
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct big_number_type_t
{
    char *data;
    unsigned int size;
} BigNumberType;

BigNumberType * big_number_type_create(const char *string);
void big_number_type_destroy(BigNumberType *value);

char * big_number_type_print(BigNumberType *value);

#endif  /* BIG_NUMBER_TYPE_H_ */