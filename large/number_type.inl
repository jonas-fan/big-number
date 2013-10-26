inline int Large::c2I(const char &c)
{
	return c - '0';
}

inline char Large::i2C(const int &i)
{
	return i + '0';
}


inline unsigned int Large::NumberType::size() const
{
	return this->data_.size();
}

inline std::string Large::NumberType::string() const
{
	std::string retval(this->data_.rbegin(), this->data_.rend());

	if (this->positive())
		return retval;

	if ((retval.size() == 1) && (retval.at(0) == '0'))
		return retval;

	return ("-" + retval);
}

inline bool Large::NumberType::positive() const
{
	return this->positive_;
}

inline void Large::NumberType::positive(const bool &sign)
{
	this->positive_ = sign;
}

inline int Large::NumberType::at(const unsigned int &index) const
{
	if (index < this->data_.size())
		return Large::c2I(this->data_.at(index));

	return 0;
}

inline void Large::NumberType::at(const unsigned int &index, const int &num)
{
	if (index < this->data_.size())
		this->data_.at(index) = Large::i2C(num);
}

inline void Large::NumberType::pop()
{
	this->data_.pop_back();
}

inline void Large::NumberType::push(const int &num)
{
	this->data_.push_back(Large::i2C(num));
}
