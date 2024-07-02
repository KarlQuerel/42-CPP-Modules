# include "Brain.hpp"

Brain::Brain()
{
	std::cout << BGR BRAIN D_CONS;
	return ;
}

Brain::Brain(Brain const & src)
{
	std::cout << BYE BRAIN C_CONS;
	*this = src;
	return ;
}

Brain::~Brain()
{
	std::cout << BRED BRAIN D_DES;
	return ;
}

Brain & Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	std::cout << BMA BRAIN ASSIGN_OP;
	return *this;
}