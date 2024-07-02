# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << BGR WRG_ANIMAL D_CONS;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << BYE WRG_ANIMAL C_CONS;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BRED WRG_ANIMAL D_DES;
	return ;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
	std::cout << BMA WRG_ANIMAL ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
	std::cout << BCY WRG_ANIMAL PARAM_CONS;
	return ;
}

void	WrongAnimal::makeSound() const
{
	std::cout << BRED WRONG_NOISE;
	return ;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
