#include <big_number.hpp>
#include <big_number_math.hpp>


/**
 *    Public methods
 */

BigNumber::Number::Number() : num_(0)
{

}

BigNumber::Number::Number(const int &number)
    : num_(number)
{

}

BigNumber::Number::Number(const std::string &string)
    : num_(string)
{

}

BigNumber::Number::Number(const BigNumber::Integer &number)
    : num_(number)
{

}

BigNumber::Number::~Number()
{

}

unsigned int BigNumber::Number::size() const
{
    return this->num_.size();
}

std::string BigNumber::Number::string() const
{
    return this->num_.string();
}

int BigNumber::Number::compare(const BigNumber::Number &rhs) const
{
    return this->num_.compare(rhs.num_);
}

void BigNumber::Number::add(const BigNumber::Number &rhs)
{
    BigNumber::Number x(*this);
    BigNumber::Number y(rhs);
    BigNumber::Number result;

    bool positive = true;

    if (x.num_.positive() && y.num_.positive()) {
        result = BigNumber::Math::add(x, y);
    }
    else if (x.num_.positive() && !y.num_.positive()) {
        y.num_.positive(true);

        if (x >= y) {
            result = BigNumber::Math::sub(x, y);
        }
        else {
            result = BigNumber::Math::sub(y, x);
            positive = false;
        }
    }
    else if (!x.num_.positive() && y.num_.positive()) {
        x.num_.positive(true);

        if (x <= y) {
            result = BigNumber::Math::sub(y, x);
        }
        else {
            result = BigNumber::Math::sub(x, y);
            positive = false;
        }
    }
    else {
        x.num_.positive(true);
        y.num_.positive(true);
        positive = false;

        result = BigNumber::Math::add(x, y);
    }

    result.num_.positive(positive);

    this->num_ = result.num_;
}

void BigNumber::Number::sub(const BigNumber::Number &rhs)
{
    BigNumber::Number x(*this);
    BigNumber::Number y(rhs);
    BigNumber::Number result;

    bool positive = true;

    if (x.num_.positive() && y.num_.positive()) {
        if (x >= y) {
            result = BigNumber::Math::sub(x, y);
        }
        else {
            result = BigNumber::Math::sub(y, x);
            positive = false;
        }
    }
    else if (x.num_.positive() && !y.num_.positive()) {
        y.num_.positive(true);

        result = BigNumber::Math::add(x, y);
    }
    else if (!x.num_.positive() && y.num_.positive()) {
        x.num_.positive(true);
        positive = false;

        result = BigNumber::Math::add(x, y);
    }
    else {
        x.num_.positive(true);
        y.num_.positive(true);

        if (x > y) {
            result = BigNumber::Math::sub(x, y);
            positive = false;
        }
        else {
            result = BigNumber::Math::sub(y, x);
        }
    }

    result.num_.positive(positive);

    this->num_ = result.num_;
}

void BigNumber::Number::mul(const BigNumber::Number &rhs)
{
    BigNumber::Number x(*this);
    BigNumber::Number y(rhs);

    bool positive = !(x.num_.positive() ^ y.num_.positive());

    x.num_.positive(true);
    y.num_.positive(true);

    BigNumber::Number result = BigNumber::Math::mul(x, y);

    if (result == 0) {
        positive = true;
    }

    result.num_.positive(positive);

    this->num_ = result.num_;
}

void BigNumber::Number::div(const BigNumber::Number &rhs)
{
    BigNumber::Number x(*this);
    BigNumber::Number y(rhs);

    bool positive = !(x.num_.positive() ^ y.num_.positive());

    x.num_.positive(true);
    y.num_.positive(true);

    BigNumber::Number result(BigNumber::Math::div(x, y));

    if (result == 0) {
        positive = true;
    }

    result.num_.positive(positive);

    this->num_ = result.num_;
}

BigNumber::Number operator + (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Number retval(lhs);

    retval.add(rhs);

    return retval;
}

BigNumber::Number operator - (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Number retval(lhs);

    retval.sub(rhs);

    return retval;
}

BigNumber::Number operator * (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Number retval(lhs);

    retval.mul(rhs);

    return retval;
}

BigNumber::Number operator / (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    BigNumber::Number retval(lhs);

    retval.div(rhs);

    return retval;
}

bool operator > (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) > 0;
}

bool operator < (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) < 0;
}

bool operator >= (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) >= 0;
}

bool operator <= (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) <= 0;
}

bool operator == (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) == 0;
}

bool operator != (const BigNumber::Number &lhs, const BigNumber::Number &rhs)
{
    return lhs.compare(rhs) != 0;
}

std::ostream & operator << (std::ostream &os, const BigNumber::Number &num)
{
    return os << num.string();
}