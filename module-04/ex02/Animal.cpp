# include "Animal.hpp"

AAnimal::AAnimal() : _type("Default")
{
	std::cout << BGR ANIMAL D_CONS;
	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << BYE ANIMAL C_CONS;
	*this = src;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << BRED ANIMAL D_DES;
	return ;
}

AAnimal & AAnimal::operator=(const AAnimal & rhs)
{
	std::cout << BMA ANIMAL ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

AAnimal::AAnimal(std::string name) : _type(name)
{
	std::cout << BCY ANIMAL PARAM_CONS;
	return ;
}

void	AAnimal::makeSound() const
{
	std::cout << BRED NOISE;
	return ;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}