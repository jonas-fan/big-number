#include <bigint.h>

static inline bool isValidInt(const std::string &value)
{
    if (value.empty()) {
        return false;
    }

    if ((value.size() == 1) && !isdigit(value[0])) {
        return false;
    }

    std::size_t index = 0;

    if ((value[0] == '+') || (value[0] == '-')) {
        ++index;
    }

    for (; index != value.size(); ++index) {
        if (!isdigit(value[index])) {
            return false;
        }
    }

    return true;
}

BigInt::BigInt()
    : BigInt("0")
{

}

BigInt::BigInt(int value)
    : positive_(true), data_()
{
    const std::string &str = std::to_string(value);

    if (isValidInt(str)) {
        this->assign(str);
    }
    else {
        this->assign("0");
    }
}

BigInt::BigInt(const std::string &value)
    : positive_(true), data_()
{
    if (isValidInt(value)) {
        this->assign(value);
    }
    else {
        this->assign("0");
    }
}

BigInt::~BigInt()
{

}

void BigInt::assign(const std::string &value)
{
    std::string::const_reverse_iterator begin = value.rbegin();
    std::string::const_reverse_iterator end = value.rend();

    this->positive_ = true;

    if (*(end - 1) == '+') {
        --end;
    }
    else if (*(end - 1) == '-') {
        this->positive_ = false;
        --end;
    }

    this->data_.clear();

    while (begin != end) {
        this->data_.push_back(*begin - '0');
        ++begin;
    }
}

void BigInt::add(const BigInt &rhs)
{
    // @TODO
}

BigInt BigInt::add_(const BigInt &rhs)
{
    // @TODO
}

void BigInt::sub(const BigInt &rhs)
{
    // @TODO
}

BigInt BigInt::sub_(const BigInt &rhs)
{
    // @TODO
}

void BigInt::mul(const BigInt &rhs)
{
    // @TODO
}

void BigInt::div(const BigInt &rhs)
{
    // @TODO
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

    std::size_t index = ldata->size();

    do {
        --index;

        const int result = ldata->at(index) - rdata->at(index);

        if (result) {
            return result;
        }
    } while(index);

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