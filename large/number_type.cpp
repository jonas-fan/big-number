#include "number_type.hpp"

#include <sstream>

void Large::NumberType::init(const std::string &str)
{
	this->data_.assign(str.rbegin(), str.rend());

	if (this->data_.empty())
		this->data_.push_back('0');

	if (this->data_.back() == '-') {
		this->data_.pop_back();
		this->positive(false);
	}
}

Large::NumberType::NumberType() : data_(), positive_(true)
{

}

Large::NumberType::NumberType(const long long int &n) : data_(), positive_(true)
{
	std::ostringstream buffer;

	buffer << n;

	this->init(buffer.str());
}

Large::NumberType::NumberType(const char *&str) : data_(), positive_(true)
{
	this->init(std::string(str));
}

Large::NumberType::NumberType(const std::string &str) : data_(), positive_(true)
{
	this->init(str);
}

Large::NumberType::~NumberType()
{

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
		const int &lvalue = left->at(index);
		const int &rvalue = right->at(index);

		if (rvalue < lvalue)
			return 1;

		if (lvalue < rvalue)
			return -1;
	}

	return 0;
}
