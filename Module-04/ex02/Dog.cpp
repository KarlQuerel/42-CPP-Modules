# include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->ideas[i] = DOG_IDEAS;
	std::cout << BGR DOG D_CONS;
	return ;
}

Dog::Dog(Dog const & src) : AAnimal(src)
{
	std::cout << BYE DOG C_CONS;
	if (src._brain == NULL)
		this->_brain = NULL;
	else
		this->_brain = new Brain(*src._brain);
	return ;
}

Dog::~Dog()
{
	std::cout << BRED DOG D_DES;
	delete _brain;
	return ;
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << BMA DOG ASSIGN_OP;
	this->_type = rhs._type;
	delete this->_brain;
	if (rhs._brain == NULL)
		this->_brain = NULL;
	else
		this->_brain = new Brain (*rhs._brain);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << BRED BARK;
	return ;
}

bool	Dog::isValidIndex(int index) const
{
	if (index < 0 || index > 100)
	{
		ERROR_INDEX;
		return false;
	}
	return true;
}

void	Dog::brainwash(int index, std::string idea)
{
	if (isValidIndex(index))
		this->_brain->ideas[index] = idea;
	return ;
}

void	Dog::showAllIdeas() const
{
	for (int index = 0; index < 100; index++)
		this->showOneIdea(index);
	return ;
}

void	Dog::showOneIdea(int index) const
{
	if (isValidIndex(index))
		std::cout << BBL DOG << "My wonderful idea #" << index << " is " BGR << this->_brain->ideas[index] << STR_END;
	return ;
}