# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << BGR DOG D_CONS;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << BYE DOG C_CONS;
	*this = src;
	return ;
}

Dog::~Dog()
{
	std::cout << BRED DOG D_DES;
	return ;
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << BMA DOG ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << BRED BARK;
	return ;
}
