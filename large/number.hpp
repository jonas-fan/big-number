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
	Number(const Large::NumberType &num);
	~Number();

	unsigned int size() const;
	std::string string() const;

	int compare(const Large::Number &rhs) const;

	void add(const Large::Number &rhs);
	void sub(const Large::Number &rhs);
	void mul(const Large::Number &rhs);
	void div(const Large::Number &rhs);

private:
	NumberType num_;
};

} // namespace Large

#include "number.inl"

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
