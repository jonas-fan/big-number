#include <big_number_integer.hpp>
#include <big_number_utils.hpp>

#include <sstream>


/**
 *    Private methods
 */

void BigNumber::Integer::init(const std::string &string)
{
    this->data_.assign(string.rbegin(), string.rend());

    if (this->data_.empty()) {
        this->data_.push_back('0');
    }

    if (this->data_.back() == '-') {
        this->data_.pop_back();

        this->positive(false);
    }
}


/**
 *    Public methods
 */

BigNumber::Integer::Integer()
    : data_(),
      positive_(true)
{

}

BigNumber::Integer::Integer(long long int integer)
    : data_(),
      positive_(true)
{
    std::ostringstream caster;

    caster << integer;

    this->init(caster.str());
}

BigNumber::Integer::Integer(const std::string &string)
    : data_(),
      positive_(true)
{
    this->init(string);
}

BigNumber::Integer::~Integer()
{

}

unsigned int BigNumber::Integer::size() const
{
    return this->data_.size();
}

std::string BigNumber::Integer::string() const
{
    std::string retval(this->data_.rbegin(), this->data_.rend());

    if (this->positive()) {
        return retval;
    }

    if ((retval.size() == 1) &&
        (retval.at(0) == '0'))
    {
        return retval;
    }

    return ("-" + retval);
}

int BigNumber::Integer::compare(const Integer &rhs) const
{
    const Integer *left = this;
    const Integer *right = &rhs;

    if (left->positive() &&
        !right->positive())
    {
        return 1;
    }

    if (!left->positive() &&
        right->positive())
    {
        return -1;
    }

    if (!left->positive() &&
        !right->positive())
    {
        std::swap<const Integer *>(left, right);
    }

    if (right->size() < left->size()) {
        return 1;
    }

    if (left->size() < right->size()) {
        return -1;
    }

    for (int index = left->size() - 1; index > -1; --index) {
        const int &lvalue = left->at(index);
        const int &rvalue = right->at(index);

        if (rvalue < lvalue) {
            return 1;
        }

        if (lvalue < rvalue) {
            return -1;
        }
    }

    return 0;
}

bool BigNumber::Integer::positive() const
{
    return this->positive_;
}

void BigNumber::Integer::positive(bool sign)
{
    this->positive_ = sign;
}

int BigNumber::Integer::at(unsigned int index) const
{
    if (index < this->data_.size()) {
        return BigNumber::char2integer(this->data_.at(index));
    }

    return 0;
}

void BigNumber::Integer::at(unsigned int index, int value)
{
    if (index < this->data_.size()) {
        this->data_.at(index) = BigNumber::integer2char(value);
    }
}

void BigNumber::Integer::pop()
{
    this->data_.pop_back();
}

void BigNumber::Integer::push(int value)
{
    this->data_.push_back(BigNumber::integer2char(value));
}