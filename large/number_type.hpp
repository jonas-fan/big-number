#ifndef LARGE_NUMBER_TYPE_HPP_
#define LARGE_NUMBER_TYPE_HPP_

#include <vector>
#include <string>

namespace Large
{

/**
 *  The type of large number.
 *
 *
 *  @version 1.1
 *  @date    2013/09/07
 *  @author  Jian <john33550@gmail.com>
 */
class NumberType
{
public:
	NumberType();
	NumberType(const long long int &n);
	NumberType(const char *&str);
	NumberType(const std::string &str);
	~NumberType();

	unsigned int size() const;
	std::string string() const;

	int compare(const NumberType &rhs) const;

	bool positive() const;
	void positive(const bool &sign);
	int at(const unsigned int &index) const;
	void at(const unsigned int &index, const int &num);
	void pop();
	void push(const int &num);

private:
	void init(const std::string &str);

private:
	std::vector<char> data_;
	bool positive_;
};


int c2I(const char &c);
char i2C(const int &i);

} // namespace Large

#include "number_type.inl"

#endif
