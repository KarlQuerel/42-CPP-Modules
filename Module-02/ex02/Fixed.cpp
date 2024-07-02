# include "Fixed.hpp"

// Constructors
Fixed::Fixed() : _rawBits(0)
{
	std::cout << BGR D_CONS COLOR_RESET << std::endl;
	return ;
}

Fixed::Fixed(const int i)
{
	std::cout <<   BYE INT_CONS COLOR_RESET << std::endl;
	_rawBits = i << _fractBits;
	return ;
}

Fixed::Fixed(const float f)
{
	std::cout <<   BWHT FLOAT_CONS COLOR_RESET << std::endl;
	_rawBits = roundf(f * (1 << this->_fractBits));
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << BYE C_CONS COLOR_RESET << std::endl;
	this->_rawBits = src.getRawBits();
	return ;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << BRED DECONS COLOR_RESET << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << BMA ASSIGN_OP COLOR_RESET << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const
{
	return (float)(this->_rawBits) / (1 << this->_fractBits);
}

int	Fixed::toInt(void)const
{
	return (this->_rawBits >> this->_fractBits);
}

int	Fixed::getRawBits() const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

// Operators

// Assignment
std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

// Comparison
bool	Fixed::operator>(Fixed const & rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

// Arithmetic operators
Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed (this->toFloat() / rhs.toFloat());
}

// Iterators operators
Fixed	Fixed::operator++()
{
	Fixed	temp;
	temp._rawBits = ++_rawBits;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp._rawBits = _rawBits++;
	return *this;
}

Fixed	Fixed::operator--()
{
	Fixed	temp;
	temp._rawBits = --_rawBits;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp._rawBits = _rawBits--;
	return *this;
}

// Min and max
Fixed & Fixed::min(Fixed & left, Fixed & right)
{
	if (left < right)
		return (left);
	return (right);
}

Fixed const & Fixed::min(Fixed const & left, Fixed const & right)
{
	if (left < right)
		return (left);
	return (right);
}

Fixed & Fixed::max(Fixed & left, Fixed & right)
{
	if (left > right)
		return (left);
	return (right);
}

Fixed const & Fixed::max(Fixed const & left, Fixed const & right)
{
	if (left > right)
		return (left);
	return (right);
}

