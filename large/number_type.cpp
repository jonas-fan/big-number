#include "number_type.hpp"

#include <sstream>
#include <algorithm>

void Large::NumberType::initializer_(const std::string &str)
{
	this->data_ = std::vector<char>(str.begin(), str.end());

	std::reverse(this->data_.begin(), this->data_.end());

	if (this->data_.size() && this->data_.back() == '-') {
		this->data_.pop_back();
		this->positive(false);
	}
}

Large::NumberType::NumberType() : positive_(true)
{

}

Large::NumberType::NumberType(const long long int &n) : positive_(true)
{
	std::ostringstream buffer;

	buffer << n;

	this->initializer_(buffer.str());
}

Large::NumberType::NumberType(const char *&str) : positive_(true)
{
	this->initializer_(std::string(str));
}

Large::NumberType::NumberType(const std::string &str) : positive_(true)
{
	this->initializer_(str);
}

Large::NumberType::~NumberType()
{

}

bool Large::NumberType::positive() const
{
	return this->positive_;
}

void Large::NumberType::positive(const bool &sign)
{
	this->positive_ = sign;
}


unsigned int Large::NumberType::size() const
{
	return this->data_.size();
}

std::string Large::NumberType::string() const
{
	std::string retval(this->data_.begin(), this->data_.end());

	std::reverse(retval.begin(), retval.end());

	if (this->positive())
		return retval;

	if ((retval.size() == 1) && (retval.at(0) == '0'))
		return retval;

	return ("-" + retval);
}

int Large::NumberType::compare(const NumberType &rhs) const
{
	const NumberType *left = this;
	const NumberType *right = &rhs;

	if (left->positive() && !right->positive())
		return 1;
	if (!left->positive() && right->positive())
		return -1;

	if (!left->positive() && !right->positive())
		std::swap<const NumberType *>(left, right);

	if (right->size() < left->size())
		return 1;
	if (left->size() < right->size())
		return -1;

	for (int index = left->size() - 1; index > -1; --index) {
		if (right->at(index) < left->at(index))
			return 1;
		if (left->at(index) < right->at(index))
			return -1;
	}

	return 0;
}

int Large::NumberType::at(unsigned int index) const
{
	if (index < this->data_.size())
		return Large::c2I(this->data_.at(index));

	return 0;
}

void Large::NumberType::at(unsigned int index, int num)
{
	if (index < this->data_.size())
		this->data_.at(index) = Large::i2C(num);
}

void Large::NumberType::pop()
{
	this->data_.pop_back();
}

void Large::NumberType::push(int num)
{
	this->data_.push_back(i2C(num));
}
