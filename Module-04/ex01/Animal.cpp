# include "Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << BGR ANIMAL D_CONS;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout << BYE ANIMAL C_CONS;
	*this = src;
	return ;
}

Animal::~Animal()
{
	std::cout << BRED ANIMAL D_DES;
	return ;
}

Animal & Animal::operator=(const Animal & rhs)
{
	std::cout << BMA ANIMAL ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << BCY ANIMAL PARAM_CONS;
	return ;
}

void	Animal::makeSound() const
{
	std::cout << BRED NOISE;
	return ;
}

std::string	Animal::getType() const
{
	return this->_type;
}