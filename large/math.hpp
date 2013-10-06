#ifndef LARGE_MATH_HPP_
#define LARGE_MATH_HPP_

#include "number.hpp"

namespace Large
{

/**
 *  The basic math computing of large number.
 *
 *  @version 1.1
 *  @date    2013/09/07
 *  @author  Jian <john33550@gmail.com>
 */
class Math
{
public:
	static Large::Number add(const Large::Number &lhs, const Large::Number &rhs);
	static Large::Number sub(const Large::Number &lhs, const Large::Number &rhs);
	static Large::Number mul(const Large::Number &lhs, const Large::Number &rhs);
	static Large::Number div(const Large::Number &lhs, const Large::Number &rhs);
};

} // namespace Large

#endif
