#include "number.hpp"
#include "math.hpp"

Large::Number::Number() : num_(0)
{

}

Large::Number::Number(const int &n) : num_(n)
{

}

Large::Number::Number(const char *str) : num_(str)
{

}

Large::Number::Number(const std::string &str) : num_(str)
{

}

Large::Number::Number(const Large::NumberType &num) : num_(num)
{

}

Large::Number::~Number()
{

}

int Large::Number::compare(const Large::Number &rhs) const
{
	return this->num_.compare(rhs.num_);
}

void Large::Number::add(const Large::Number &rhs)
{
	Large::Number x(*this);
	Large::Number y(rhs);
	Large::Number result;

	bool positive = true;

	if (x.num_.positive() && y.num_.positive())
		result = Large::Math::add(x, y);
	else if (x.num_.positive() && !y.num_.positive()) {
		y.num_.positive(true);

		if (x >= y)
			result = Large::Math::sub(x, y);
		else {
			result = Large::Math::sub(y, x);
			positive = false;
		}
	}
	else if (!x.num_.positive() && y.num_.positive()) {
		x.num_.positive(true);

		if (x <= y)
			result = Large::Math::sub(y, x);
		else {
			result = Large::Math::sub(x, y);
			positive = false;
		}
	}
	else  {
		x.num_.positive(true);
		y.num_.positive(true);
		positive = false;

		result = Large::Math::add(x, y);
	}

	result.num_.positive(positive);

	this->num_ = result.num_;
}

void Large::Number::sub(const Large::Number &rhs)
{
	Large::Number x(*this);
	Large::Number y(rhs);
	Large::Number result;

	bool positive = true;

	if (x.num_.positive() && y.num_.positive()) {
		if (x >= y)
			result = Large::Math::sub(x, y);
		else {
			result = Large::Math::sub(y, x);
			positive = false;
		}
	}
	else if (x.num_.positive() && !y.num_.positive()) {
		y.num_.positive(true);

		result = Large::Math::add(x, y);
	}
	else if (!x.num_.positive() && y.num_.positive()) {
		x.num_.positive(true);
		positive = false;

		result = Large::Math::add(x, y);
	}
	else  {
		x.num_.positive(true);
		y.num_.positive(true);

		if (x > y) {
			result = Large::Math::sub(x, y);
			positive = false;
		}
		else
			result = Large::Math::sub(y, x);
	}

	result.num_.positive(positive);

	this->num_ = result.num_;
}

void Large::Number::mul(const Large::Number &rhs)
{
	Large::Number x(*this);
	Large::Number y(rhs);

	bool positive = !(x.num_.positive() ^ y.num_.positive());

	x.num_.positive(true);
	y.num_.positive(true);

	Large::Number result = Large::Math::mul(x, y);

	if (result == 0)
		positive = true;

	result.num_.positive(positive);

	this->num_ = result.num_;
}

void Large::Number::div(const Large::Number &rhs)
{
	Large::Number x(*this);
	Large::Number y(rhs);

	bool positive = !(x.num_.positive() ^ y.num_.positive());

	x.num_.positive(true);
	y.num_.positive(true);

	Large::Number result(Large::Math::div(x, y));

	if (result == 0)
		positive = true;

	result.num_.positive(positive);

	this->num_ = result.num_;
}

Large::Number operator + (const Large::Number &lhs, const Large::Number &rhs)
{
	Large::Number retval(lhs);
	retval.add(rhs);
	return retval;
}

Large::Number operator - (const Large::Number &lhs, const Large::Number &rhs)
{
	Large::Number retval(lhs);
	retval.sub(rhs);
	return retval;
}

Large::Number operator * (const Large::Number &lhs, const Large::Number &rhs)
{
	Large::Number retval(lhs);
	retval.mul(rhs);
	return retval;
}

Large::Number operator / (const Large::Number &lhs, const Large::Number &rhs)
{
	Large::Number retval(lhs);
	retval.div(rhs);
	return retval;
}

bool operator > (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) > 0;
}

bool operator < (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) < 0;
}

bool operator >= (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) >= 0;
}

bool operator <= (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) <= 0;
}

bool operator == (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) == 0;
}

bool operator != (const Large::Number &lhs, const Large::Number &rhs)
{
	return lhs.compare(rhs) != 0;
}

std::ostream & operator << (std::ostream &os, const Large::Number &num)
{
	return os << num.string();
}
