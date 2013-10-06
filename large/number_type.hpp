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

	bool positive() const;
	void positive(const bool &sign);

	unsigned int size() const;
	std::string string() const;
	int compare(const NumberType &rhs) const;

	int at(unsigned int index) const;
	void at(unsigned int index, int num);

	void pop();
	void push(int num);

private:
	void initializer_(const std::string &str);

private:
	std::vector<char> data_;
	bool positive_;
};

} // namespace Large

#include "number_type.inl"

#endif
