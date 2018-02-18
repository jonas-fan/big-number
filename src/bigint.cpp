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

    if ((iter == value.end()) || !isdigit(*iter)) {
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

static inline unsigned int intlen(long long int value)
{
    unsigned int length = 0;

    while (value) {
        value /= 10;

        ++length;
    }

    return length;
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

BigInt & BigInt::operator ++ ()
{
    (*this) = (*this) + 1;

    return (*this);
}

BigInt BigInt::operator ++ (int)
{
    BigInt retval(*this);

    (*this) = (*this) + 1;

    return retval;
}

BigInt & BigInt::operator -- ()
{
    (*this) = (*this) - 1;

    return (*this);
}

BigInt BigInt::operator -- (int)
{
    BigInt retval(*this);

    (*this) = (*this) - 1;

    return retval;
}

BigInt BigInt::operator + (int rhs) const
{
    const BigInt &lhs = (*this);

    if (rhs < 0) {
        return lhs - (-rhs);
    }
    else if (!lhs.positive_) {
        return BigInt(rhs) - lhs.abs();
    }

    const std::vector<int> &ldata = lhs.data_;

    BigInt result;
    result.data_.clear();
    result.data_.reserve(ldata.size() + 1);

    unsigned int carry = 0;

    for (std::size_t index = 0; (index < ldata.size()) || rhs; ++index) {
        const int lvalue = (index < ldata.size()) ? ldata[index] : 0;
        const int rvalue = rhs % 10;
        const int value = lvalue + rvalue + carry;

        carry = value / 10;

        result.data_.push_back(value % 10);

        rhs /= 10;
    }

    result.data_.push_back(carry);
    result.trim();

    return result;
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

    const std::vector<int> &ldata = lhs.data_;
    const std::vector<int> &rdata = rhs.data_;
    const std::size_t length = std::max(ldata.size(), rdata.size());

    BigInt result;
    result.data_.clear();
    result.data_.reserve(length + 1);

    unsigned int carry = 0;

    for (std::size_t index = 0; index < length; ++index) {
        const int lvalue = (index < ldata.size()) ? ldata[index] : 0;
        const int rvalue = (index < rdata.size()) ? rdata[index] : 0;
        const int value = lvalue + rvalue + carry;

        carry = value / 10;

        result.data_.push_back(value % 10);
    }

    result.data_.push_back(carry);
    result.trim();

    return result;
}

BigInt BigInt::operator - (int rhs) const
{
    const BigInt &lhs = (*this);

    if (rhs < 0) {
        return lhs + (-rhs);
    }
    else if (!lhs.positive_) {
        BigInt result = lhs.abs() + rhs;
        result.positive_ = false;

        return result;
    }
    else if (lhs < rhs) {
        BigInt result = BigInt(rhs) - lhs;
        result.positive_ = false;

        return result;
    }

    const std::vector<int> &ldata = lhs.data_;

    BigInt result;
    result.data_.clear();
    result.data_.reserve(ldata.size());

    unsigned int borrow = 0;

    for (std::size_t index = 0; (index < ldata.size()) || rhs; ++index) {
        const int lvalue = (index < ldata.size()) ? ldata[index] : 0;
        const int rvalue = (rhs % 10);
        const int value = lvalue - rvalue - borrow;

        borrow = (value < 0);

        result.data_.push_back((value + 10) % 10);

        rhs /= 10;
    }

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
        BigInt result = lhs.abs() + rhs;
        result.positive_ = false;

        return result;
    }

    const std::vector<int> *ldata = &(lhs.data_);
    const std::vector<int> *rdata = &(rhs.data_);
    const std::size_t length = std::max(ldata->size(), rdata->size());

    BigInt result;
    result.data_.clear();
    result.data_.reserve(length);

    if (lhs < rhs) {
        result.positive_ = false;

        std::swap(ldata, rdata);
    }

    unsigned int borrow = 0;

    for (std::size_t index = 0; index < length; ++index) {
        const int lvalue = (index < ldata->size()) ? (*ldata)[index] : 0;
        const int rvalue = (index < rdata->size()) ? (*rdata)[index] : 0;
        const int value = lvalue - rvalue - borrow;

        borrow = (value < 0);

        result.data_.push_back((value + 10) % 10);
    }

    result.trim();

    return result;
}

BigInt BigInt::operator * (int rhs) const
{
    const BigInt &lhs = (*this);
    const std::vector<int> &ldata = lhs.data_;
    const unsigned int rhs_size = intlen(rhs);

    BigInt result;
    result.data_.resize(ldata.size() + rhs_size, 0);
    result.positive_ = !(lhs.positive_ ^ (rhs >= 0 ? 1 : 0));

    for (std::size_t lindex = 0; lindex < ldata.size(); ++lindex) {
        unsigned int carry = 0;

        for (int rdata = rhs; rdata; rdata /= 10) {
            const std::size_t offset = lindex + rhs_size - intlen(rdata);
            const int value = ldata[lindex] * (rdata % 10) + carry + result.data_[offset];

            carry = value / 10;

            result.data_[offset] = value % 10;
        }

        result.data_[lindex + rhs_size] = carry;
    }

    result.trim();

    return result;
}

BigInt BigInt::operator * (const BigInt &rhs) const
{
    const BigInt &lhs = (*this);
    const std::vector<int> &ldata = lhs.data_;
    const std::vector<int> &rdata = rhs.data_;

    BigInt result;
    result.data_.resize(ldata.size() + rdata.size(), 0);
    result.positive_ = !(lhs.positive_ ^ rhs.positive_);

    for (std::size_t lindex = 0; lindex < ldata.size(); ++lindex) {
        unsigned int carry = 0;

        for (std::size_t rindex = 0; rindex < rdata.size(); ++rindex) {
            const std::size_t offset = lindex + rindex;
            const int value = ldata[lindex] * rdata[rindex] + carry + result.data_[offset];

            carry = value / 10;

            result.data_[offset] = value % 10;
        }

        result.data_[lindex + rdata.size()] = carry;
    }

    result.trim();

    return result;
}

BigInt BigInt::operator / (const BigInt &rhs) const
{
    const bool positive = !(this->positive_ ^ rhs.positive_);
    BigInt x = this->abs();
    BigInt y = rhs.abs();
    BigInt result;

    if ((y == 0) || (x < y)) {
        return result;
    }

    for (std::size_t index = x.data_.size() - y.data_.size() + 1; (index > 0) && (x > 0); --index) {
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

std::string BigInt::string() const
{
    if (this->data_.empty()) {
        return "";
    }

    std::string retval(this->data_.rbegin(), this->data_.rend());

    for (std::string::iterator iter = retval.begin(); iter != retval.end(); ++iter) {
        *iter = *iter + '0';
    }

    if ((retval.size() == 1) && (retval[0] == '0')) {
        return retval;
    }

    return (this->positive_) ? retval : ("-" + retval);
}

BigInt BigInt::abs() const
{
    BigInt retval(*this);

    retval.positive_ = true;

    return retval;
}

int BigInt::compare(const BigInt &rhs) const
{
    const BigInt &lhs = (*this);

    if (lhs.positive_ && !rhs.positive_) {
        return 1;
    }

    if (!lhs.positive_ && rhs.positive_) {
        return -1;
    }

    const std::vector<int> *ldata = &(lhs.data_);
    const std::vector<int> *rdata = &(rhs.data_);

    if (!lhs.positive_ && !rhs.positive_) {
        std::swap(ldata, rdata);
    }

    if (ldata->size() > rdata->size()) {
        return 1;
    }

    if (ldata->size() < rdata->size()) {
        return -1;
    }

    std::vector<int>::const_reverse_iterator liter = ldata->rbegin();
    std::vector<int>::const_reverse_iterator riter = rdata->rbegin();

    while ((liter != ldata->rend()) && (riter != rdata->rend())) {
        const int result = (*liter) - (*riter);

        if (result) {
            return result;
        }

        ++liter;
        ++riter;
    }

    return 0;
}