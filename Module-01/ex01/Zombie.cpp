# include "Zombie.hpp"

Zombie::Zombie(): _name("Zombie")
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << BWHT << this->_name << BRED SQUASHED COLOR_RESET << std::endl;
	return ;
}

void	Zombie::announce() const
{
	std::cout << BWHT << this->_name << ": " << BGR BRAINZ COLOR_RESET << std::endl;
	return ;
}

void	Zombie::assign_name(std::string name)
{
	this->_name = name;
	return;
}