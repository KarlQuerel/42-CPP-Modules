# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << BGR CAT D_CONS;
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << BYE CAT C_CONS;
	*this = src;
	return ;
}

Cat::~Cat()
{
	std::cout << BRED CAT D_DES;
	return ;
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << BMA CAT ASSIGN_OP;
	this->_type = rhs._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << BGR MEOW;
	return ;
}
