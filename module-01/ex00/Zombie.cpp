# include "Zombie.hpp"

Zombie::Zombie(std::string str): _name(str)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << BWHT << this->_name << BRED SQUASHED COLOR_RESET << std::endl;
	return ;
}