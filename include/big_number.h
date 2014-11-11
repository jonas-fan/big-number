#ifndef BIG_NUMBER_H_
#define BIG_NUMBER_H_

/**
 *    Big number
 *
 *    @version 0.1.0
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct big_number_t BigNumber;

BigNumber * big_number_create(const char *string);
void big_number_destroy(BigNumber *big_number);

char * big_number_print(BigNumber *big_number);

void big_number_add(BigNumber *lhs, BigNumber *rhs);
void big_number_sub(BigNumber *lhs, BigNumber *rhs);
void big_number_mul(BigNumber *lhs, BigNumber *rhs);
void big_number_div(BigNumber *lhs, BigNumber *rhs);

#endif  /* BIG_NUMBER_H_ */