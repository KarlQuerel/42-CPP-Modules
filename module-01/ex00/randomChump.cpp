#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
	return ;
}

void	Zombie::announce()
{
	std::cout << BWHT << this->_name << ": " << BGR BRAINZ COLOR_RESET << std::endl;
	return ;
}