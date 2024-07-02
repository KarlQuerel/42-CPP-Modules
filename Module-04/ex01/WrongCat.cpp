# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << BGR WRG_CAT D_CONS;
	return ;
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << BYE WRG_CAT C_CONS;
	*this = src;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << BRED WRG_CAT D_DES;
	return ;
}

WrongCat & WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << BMA WRG_CAT ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << BGR WRG_MEOW;
	return ;
}
