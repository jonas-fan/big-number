#ifndef LARGE_NUMBER_HPP_
#define LARGE_NUMBER_HPP_

#include "number_type.hpp"

namespace Large
{

/**
 *  The large number.
 *
 *
 *  @version 1.1
 *  @date    2013/09/07
 *  @author  Jian <john33550@gmail.com>
 */
class Number
{
	friend class Math;

public:
	Number();
	Number(const int &n);
	Number(const char *str);
	Number(const std::string &str);
	Number(const NumberType &num);
	~Number();

	unsigned int size() const;
	std::string string() const;
	int compare(const Number &rhs) const;

	Number & add(const Number &rhs);
	Number & sub(const Number &rhs);
	Number & mul(const Number &rhs);
	Number & div(const Number &rhs);

private:
	NumberType num_;
};

} // namespace Large

Large::Number operator + (const Large::Number &lhs, const Large::Number &rhs);
Large::Number operator - (const Large::Number &lhs, const Large::Number &rhs);
Large::Number operator * (const Large::Number &lhs, const Large::Number &rhs);
Large::Number operator / (const Large::Number &lhs, const Large::Number &rhs);

bool operator > (const Large::Number &lhs, const Large::Number &rhs);
bool operator < (const Large::Number &lhs, const Large::Number &rhs);
bool operator >= (const Large::Number &lhs, const Large::Number &rhs);
bool operator <= (const Large::Number &lhs, const Large::Number &rhs);
bool operator == (const Large::Number &lhs, const Large::Number &rhs);
bool operator != (const Large::Number &lhs, const Large::Number &rhs);

std::ostream & operator << (std::ostream &os, const Large::Number &num);

#endif
