# include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << BGR D_CONS COLOR_RESET << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << BRED DECONS COLOR_RESET << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
