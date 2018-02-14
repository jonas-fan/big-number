#include <bigint.h>
#include <cctype>

static inline bool isNumber(const std::string &value)
{
    if (value.empty()) {
        return false;
    }

    std::string::const_iterator iter = value.begin();

    if ((*iter == '+') || (*iter == '-')) {
        ++iter;
    }
    else if (!isdigit(*iter)) {
        return false;
    }

    while (iter != value.end()) {
        if (!isdigit(*iter)) {
            return false;
        }

        ++iter;
    }

    return true;
}

BigInt::BigInt()
    : BigInt("0")
{

}

BigInt::BigInt(long long int value)
    : BigInt(std::to_string(value))
{

}

BigInt::BigInt(const std::string &value)
    : positive_(true), data_({0})
{
    if (isNumber(value)) {
        this->assign(value);
    }
}

BigInt::~BigInt()
{

}

void BigInt::assign(const std::string &value)
{
    std::string::const_reverse_iterator begin = value.rbegin();
    std::string::const_reverse_iterator end = value.rend();

    this->data_.clear();
    this->positive_ = (value.front() != '-');

    if ((value.front() == '+') || (value.front() == '-')) {
        --end;
    }

    while (begin != end) {
        this->data_.push_back(*begin - '0');
        ++begin;
    }
}

void BigInt::trim()
{
    if (this->data_.empty()) {
        return;
    }

    std::size_t index = this->data_.size() - 1;

    while (index && (this->data_[index] == 0)) {
        this->data_.pop_back();
        --index;
    }
}

BigInt BigInt::operator + (const BigInt &rhs) const
{
    const BigInt &lhs = (*this);

    if (!rhs.positive_) {
        return lhs - rhs.abs();
    }
    else if (!lhs.positive_) {
        return rhs - lhs.abs();
    }

    const auto &ldata = lhs.data_;
    const auto &rdata = rhs.data_;
    const std::size_t length = std::max(ldata.size(), rdata.size());
    BigInt result;
    auto &output = result.data_;

    output.clear();
    output.resize(length + 1, 0);

    unsigned int carry = 0;

    for (std::size_t index = 0; index < length; ++index) {
        const int lvalue = (index < ldata.size()) ? ldata[index] : 0;
        const int rvalue = (index < rdata.size()) ? rdata[index] : 0;
        const int value = lvalue + rvalue + carry;

        carry = value / 10;

        output[index] = value % 10;
    }

    output[length] = carry;

    result.trim();

    return result;
}

BigInt BigInt::operator - (const BigInt &rhs) const
{
    const BigInt &lhs = (*this);

    if (!rhs.positive_) {
        return lhs + rhs.abs();
    }
    else if (!lhs.positive_) {
        BigInt result = lhs.abs() + rhs.abs();
        result.positive_ = false;

        return result;
    }
    else if (lhs < rhs) {
        BigInt result = rhs - lhs;
        result.positive_ = false;

        return result;
    }

    const auto &ldata = lhs.data_;
    const auto &rdata = rhs.data_;
    const std::size_t length = ldata.size();
    BigInt result;
    auto &output = result.data_;

    output.clear();
    output.resize(length, 0);

    unsigned int borrow = 0;

    for (std::size_t index = 0; index < length; ++index) {
        const int lvalue = (index < ldata.size()) ? ldata[index] : 0;
        const int rvalue = (index < rdata.size()) ? rdata[index] : 0;
        const int value = lvalue - rvalue - borrow;

        borrow = (value < 0);

        output[index] = (value + 10) % 10;
    }

    result.trim();

    return result;
}

BigInt BigInt::operator * (const BigInt &rhs) const
{
    const BigInt &lhs = (*this);
    const auto &ldata = lhs.data_;
    const auto &rdata = rhs.data_;
    BigInt result;
    auto &output = result.data_;

    output.clear();
    output.resize(ldata.size() + rdata.size(), 0);

    for (std::size_t lindex = 0; lindex != ldata.size(); ++lindex) {
        unsigned int carry = 0;

        for (std::size_t rindex = 0; rindex != rdata.size(); ++rindex) {
            const std::size_t offset = lindex + rindex;
            const int value = ldata[lindex] * rdata[rindex] + carry + output[offset];

            carry = value / 10;

            output[offset] = value % 10;
        }

        output[lindex + rdata.size()] = carry;
    }

    result.trim();
    result.positive_ = !(lhs.positive_ ^ rhs.positive_);

    return result;
}

BigInt BigInt::operator / (const BigInt &rhs) const
{
    const bool positive = !(this->positive_ ^ rhs.positive_);
    BigInt x = this->abs();
    BigInt y = rhs.abs();
    BigInt result("0");

    if ((y == 0) || (x < y)) {
        return result;
    }

    std::size_t index = x.data_.size() - y.data_.size() + 1;

    for (; (index > 0) && (x > 0); --index) {
        std::string initializer(index, '0');

        for (unsigned int number = 9; number > 0; --number) {
            initializer[0] = number + '0';

            BigInt buff(initializer);
            BigInt product(y * buff);

            if (product > x) {
                continue;
            }

            x = x - product;

            result += buff;
        }
    }

    result.positive_ = positive;

    return result;
}

BigInt & BigInt::operator += (const BigInt &rhs)
{
    (*this) = (*this) + rhs;

    return (*this);
}

BigInt & BigInt::operator -= (const BigInt &rhs)
{
    (*this) = (*this) - rhs;

    return (*this);
}

BigInt & BigInt::operator *= (const BigInt &rhs)
{
    (*this) = (*this) * rhs;

    return (*this);
}

BigInt & BigInt::operator /= (const BigInt &rhs)
{
    (*this) = (*this) / rhs;

    return (*this);
}

int BigInt::compare(const BigInt &rhs) const
{
    const BigInt &lhs = (*this);
    const auto *ldata = &(this->data_);
    const auto *rdata = &(rhs.data_);

    if (lhs.positive_ && !rhs.positive_) {
        return 1;
    }

    if (!lhs.positive_ && rhs.positive_) {
        return -1;
    }

    if (!lhs.positive_ && !rhs.positive_) {
        std::swap(ldata, rdata);
    }

    if (ldata->size() > rdata->size()) {
        return 1;
    }

    if (ldata->size() < rdata->size()) {
        return -1;
    }

    auto liter = ldata->rbegin();
    auto riter = rdata->rbegin();

    while ((liter != ldata->rend() && (riter != rdata->rend()))) {
        const int result = (*liter) - (*riter);

        if (result) {
            return result;
        }

        ++liter;
        ++riter;
    }

    return 0;
}

bool BigInt::operator > (const BigInt &rhs) const
{
    return (this->compare(rhs) > 0);
}

bool BigInt::operator >= (const BigInt &rhs) const
{
    return (this->compare(rhs) >= 0);
}

bool BigInt::operator < (const BigInt &rhs) const
{
    return (this->compare(rhs) < 0);
}

bool BigInt::operator <= (const BigInt &rhs) const
{
    return (this->compare(rhs) <= 0);
}

bool BigInt::operator == (const BigInt &rhs) const
{
    return (this->compare(rhs) == 0);
}

bool BigInt::operator != (const BigInt &rhs) const
{
    return (this->compare(rhs) != 0);
}

BigInt BigInt::abs() const
{
    BigInt retval(*this);

    retval.positive_ = true;

    return retval;
}

std::string BigInt::string() const
{
    std::string retval;

    for (auto iter = this->data_.rbegin(); iter != this->data_.rend(); ++iter) {
        retval.push_back(*iter + '0');
    }

    if ((retval.size() == 1) && (retval[0] == '0')) {
        return retval;
    }

    if (this->positive_) {
        return retval;
    }

    return ("-" + retval);
}