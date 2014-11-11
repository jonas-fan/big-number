#ifndef BIG_NUMBER_INTEGER_HPP_
#define BIG_NUMBER_INTEGER_HPP_

#include <vector>
#include <string>

namespace BigNumber
{

/**
 *    Big number interger
 *
 *
 *    @version 0.1.2
 *    @date    2014/11/11
 *    @author  Jian <jianfan.tw@gmail.com>
 */

class Integer
{
public:
    Integer();
    Integer(const long long int &number);
    Integer(const std::string &string);
    virtual ~Integer();

    unsigned int size() const;
    std::string string() const;

    int compare(const Integer &rhs) const;

    bool positive() const;
    void positive(const bool &sign);

    int at(const unsigned int &index) const;
    void at(const unsigned int &index, const int &num);

    void pop();
    void push(const int &num);

private:
    void init(const std::string &str);

private:
    std::vector<char> data_;
    bool positive_;
};

} // namespace BigNumber

#endif  /* BIG_NUMBER_INTEGER_HPP_ */