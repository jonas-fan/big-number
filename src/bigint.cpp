#include <bigint.h>

static inline bool isValidInt(const std::string &value)
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
    if (isValidInt(value)) {
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

void BigInt::add(const BigInt &rhs)
{
    BigInt result;
    BigInt x(*this);
    BigInt y(rhs);

    bool positive = true;

    if (x.positive_ && y.positive_) {
        result = x.add_(y);
    }
    else if (x.positive_ && !y.positive_) {
        y.positive_ = true;

        if (x >= y) {
            x.sub_(y);
        }
        else {
            y.sub_(x);
            positive = false;
        }
    }
    else if (!x.positive_ && y.positive_) {
        x.positive_ = true;

        if (x <= y) {
            y.sub_(x);
        }
        else {
            x.sub_(y);
            positive = false;
        }
    }
    else {
        x.positive_ = true;
        y.positive_ = true;
        positive = false;

        x.add_(y);
    }

    this->data_ = result.data_;
    this->positive_ = positive;
}

BigInt BigInt::add_(const BigInt &rhs)
{
    BigInt result;
    const auto *ldata = &(this->data_);
    const auto *rdata = &(rhs.data_);
    const std::size_t length = std::max(ldata->size(), rdata->size());
    unsigned int carry = 0;

    result.data_.clear();

    for (std::size_t index = 0; index < length; ++index) {
        const int lvalue = (index < ldata->size()) ? ldata->at(index) : 0;
        const int rvalue = (index < rdata->size()) ? rdata->at(index) : 0;
        const int value = lvalue + rvalue + carry;

        carry = value / 10;

        result.data_.push_back(value % 10);
    }

    if (carry) {
        result.data_.push_back(carry);
    }

    return result;
}

void BigInt::sub(const BigInt &rhs)
{
    BigInt result;
    BigInt x(*this);
    BigInt y(rhs);

    bool positive = true;

    if (x.positive_ && y.positive_) {
        if (x >= y) {
            result = x.sub_(y);
        }
        else {
            result = y.sub_(x);
            positive = false;
        }
    }
    else if (x.positive_ && !y.positive_) {
        y.positive_ = true;

        result = x.add_(y);
    }
    else if (!x.positive_ && y.positive_) {
        x.positive_ = true;
        positive = false;

        result = x.add_(y);
    }
    else {
        x.positive_ = true;
        y.positive_ = true;

        if (x > y) {
            result = x.sub_(y);
            positive = false;
        }
        else {
            result = y.sub_(x);
        }
    }

    this->data_ = result.data_;
    this->positive_ = positive;
}

BigInt BigInt::sub_(const BigInt &rhs)
{
    BigInt result;
    const auto *ldata = &(this->data_);
    const auto *rdata = &(rhs.data_);
    const std::size_t length = ldata->size();
    std::size_t index;
    unsigned int borrow = 0;

    result.data_.clear();

    for (index = 0; index < length; ++index) {
        const int lvalue = (index < ldata->size()) ? ldata->at(index) : 0;
        const int rvalue = (index < rdata->size()) ? rdata->at(index) : 0;
        const int value = lvalue - rvalue - borrow;

        borrow = (value < 0);

        result.data_.push_back((value + 10) % 10);
    }

    index = length - 1;

    while (index && (result.data_.at(index--) == 0)) {
        result.data_.pop_back();
    }

    return result;
}

void BigInt::mul(const BigInt &rhs)
{
    BigInt x(*this);
    BigInt y(rhs);

    bool positive = !(x.positive_ ^ y.positive_);

    x.positive_ = true;
    y.positive_ = true;

    BigInt result = x.mul_(y);

    if (result == 0) {
        positive = true;
    }

    this->data_ = result.data_;
    this->positive_ = positive;
}

BigInt BigInt::mul_(const BigInt &rhs)
{
    BigInt result;
    auto *odata = &result.data_;
    const auto *ldata = &(this->data_);
    const auto *rdata = &(rhs.data_);

    odata->clear();

    for (std::size_t xIndex = 0; xIndex != ldata->size(); ++xIndex) {
        unsigned int carry = 0;

        for (std::size_t yIndex = 0; yIndex != rdata->size(); ++yIndex) {
            const int lvalue = (xIndex < ldata->size()) ? ldata->at(xIndex) : 0;
            const int rvalue = (yIndex < rdata->size()) ? rdata->at(yIndex) : 0;
            const int ovalue = (xIndex + yIndex < odata->size()) ? odata->at(xIndex + yIndex) : 0;
            const int value = lvalue * rvalue + carry + ovalue;

            carry = value / 10;

            if (xIndex + yIndex < odata->size()) {
                odata->at(xIndex + yIndex) = value % 10;
            }
            else {
                odata->push_back(value % 10);
            }
        }

        if (carry) {
            odata->push_back(carry);
        }
    }

    std::size_t index = odata->size() - 1;

    while (index && (odata->at(index--) == 0)) {
        odata->pop_back();
    }

    return result;
}

void BigInt::div(const BigInt &rhs)
{
    BigInt x(*this);
    BigInt y(rhs);

    bool positive = !(x.positive_ ^ y.positive_);

    x.positive_ = true;
    y.positive_ = true;

    BigInt result = x.div_(y);

    if (result == 0) {
        positive = true;
    }

    this->data_ = result.data_;
    this->positive_ = positive;
}

BigInt BigInt::div_(const BigInt &rhs)
{
    BigInt result;
    BigInt x(*this);
    BigInt y(rhs);

    if (y == 0) {
        return result;
    }

    for (int index = x.data_.size() - y.data_.size() + 1;
         index > 0 && x > 0;
         --index)
    {
        std::string initializer(index, '0');

        for (unsigned int number = 9; number > 0; --number) {
            initializer[0] = number + '0';

            BigInt buff(initializer);
            BigInt product(y * buff);

            if (product > x) {
                continue;
            }

            x.sub(product);

            result.add(buff);
        }
    }

    return result;
}

int BigInt::compare(const BigInt &rhs) const
{
    const BigInt &lhs = *this;
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
        const int result = *liter - *riter;

        if (result) {
            return result;
        }

        ++liter;
        ++riter;
    }

    return 0;
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

BigInt operator + (const BigInt &lhs, const BigInt &rhs)
{
    BigInt retval(lhs);

    retval.add(rhs);

    return retval;
}

BigInt operator - (const BigInt &lhs, const BigInt &rhs)
{
    BigInt retval(lhs);

    retval.sub(rhs);

    return retval;
}

BigInt operator * (const BigInt &lhs, const BigInt &rhs)
{
    BigInt retval(lhs);

    retval.mul(rhs);

    return retval;
}

BigInt operator / (const BigInt &lhs, const BigInt &rhs)
{
    BigInt retval(lhs);

    retval.div(rhs);

    return retval;
}

bool operator > (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) > 0);
}

bool operator >= (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) >= 0);
}

bool operator < (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) < 0);
}

bool operator <= (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) <= 0);
}

bool operator == (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) == 0);
}

bool operator != (const BigInt &lhs, const BigInt &rhs)
{
    return (lhs.compare(rhs) != 0);
}

std::ostream & operator << (std::ostream &os, const BigInt &bigint)
{
    return os << bigint.string();
}