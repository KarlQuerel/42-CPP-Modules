# include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << BGR D_CONS COLOR_RESET << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << BYE C_CONS COLOR_RESET << std::endl;
	this->setRawBits(src.getRawBits());
	return ;
}

Fixed::~Fixed()
{
	std::cout << BRED DECONS COLOR_RESET << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << BMA ASSIGN_OP COLOR_RESET << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	std::cout << BCY RAW << COLOR_RESET << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}