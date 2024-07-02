# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->ideas[i] = CAT_IDEAS;
	std::cout << BGR CAT D_CONS;
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << BYE CAT C_CONS;
	if (src._brain == NULL)
		this->_brain = NULL;
	else
		this->_brain = new Brain(*src._brain);
	return ;
}

Cat::~Cat()
{
	std::cout << BRED CAT D_DES;
	delete _brain;
	return ;
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << BMA CAT ASSIGN_OP;
	this->_type = rhs._type;
	delete this->_brain;
	if (rhs._brain == NULL)
		this->_brain = NULL;
	else
		this->_brain = new Brain(*rhs._brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << BGR MEOW;
	return ;
}

bool	Cat::isValidIndex(int index) const
{
	if (index < 0 || index > 100)
	{
		ERROR_INDEX;
		return false;
	}
	return true;
}

void	Cat::brainwash(int index, std::string idea)
{
	if (isValidIndex(index))
		this->_brain->ideas[index] = idea;
	return ;
}

void	Cat::showAllIdeas() const
{
	for (int index = 0; index < 100; index++)
		this->showOneIdea(index);
	return ;
}

void	Cat::showOneIdea(int index) const
{
	if (isValidIndex(index))
		std::cout << BWHT CAT << "My wonderful idea #" << index << " is " BGR << this->_brain->ideas[index] << STR_END;
	return ;
}
