#include "math.hpp"

Large::Number Large::Math::add(const Large::Number &lhs, const Large::Number &rhs)
{
	Large::NumberType retval;
	const Large::NumberType &x = lhs.num_;
	const Large::NumberType &y = rhs.num_;

	const unsigned int length = (lhs > rhs)?  lhs.size() : rhs.size();
	unsigned int carry = 0;

	for (unsigned int index = 0; index < length; ++index) {
		int val = x.at(index) + y.at(index) + carry;
		carry = val / 10;
		retval.push(val % 10);
	}

	if (carry)
		retval.push(carry);

	return retval;
}

Large::Number Large::Math::sub(const Large::Number &lhs, const Large::Number &rhs)
{
	Large::NumberType retval;
	const Large::NumberType &x = lhs.num_;
	const Large::NumberType &y = rhs.num_;

	const unsigned int length = x.size();
	unsigned int index;
	bool carry = false;

	for (index = 0; index < length; ++index) {
		int val = x.at(index) - y.at(index) - carry;
		carry = (val < 0);
		retval.push((val + 10) % 10);
	}

	index = length - 1;

	while (index && retval.at(index--) == 0)
		retval.pop();

	return retval;
}

Large::Number Large::Math::mul(const Large::Number &lhs, const Large::Number &rhs)
{
	Large::NumberType retval;
	const Large::NumberType &x = lhs.num_;
	const Large::NumberType &y = rhs.num_;

	for (unsigned int xIndex = 0; xIndex < x.size(); ++xIndex) {
		int carry = 0;

		for (unsigned int yIndex = 0; yIndex < y.size(); ++yIndex) {
			int val = x.at(xIndex) * y.at(yIndex) + carry + retval.at(xIndex + yIndex);

			carry = val / 10;
			val %= 10;

			if (xIndex + yIndex < retval.size())
				retval.at(xIndex + yIndex, val);
			else
				retval.push(val);
		}

		if (carry)
			retval.push(carry);
	}

	unsigned int index = retval.size() - 1;

	while (index && retval.at(index--) == 0)
		retval.pop();

	return retval;
}

Large::Number Large::Math::div(const Large::Number &lhs, const Large::Number &rhs)
{
	Large::Number retval;
	Large::Number x(lhs);
	Large::Number y(rhs);

	if (y == 0)
		return retval;

	for (int index = x.size() - y.size() + 1; index > 0 && x > 0; --index) {
		std::string initializer(index, '0');

		for (int number = 9; number > 0; --number) {
			initializer.at(0) = Large::i2C(number);

			Large::Number buff(initializer);
			Large::Number product(y * buff);

			if (product > x)
				continue;

			x.sub(product);
			retval.add(buff);
		}
	}

	return retval;
}
