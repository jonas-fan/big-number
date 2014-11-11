#ifndef BIG_NUMBER_OPERATOR_H_
#define BIG_NUMBER_OPERATOR_H_

/**
 *    Big number operator
 *
 *    @version 0.1.0
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

#include <big_number_type.h>

void big_number_type_add(BigNumberType *lhs, BigNumberType *rhs);
void big_number_type_sub(BigNumberType *lhs, BigNumberType *rhs);
void big_number_type_mul(BigNumberType *lhs, BigNumberType *rhs);
void big_number_type_div(BigNumberType *lhs, BigNumberType *rhs);

#endif  /* BIG_NUMBER_OPERATOR_H_ */