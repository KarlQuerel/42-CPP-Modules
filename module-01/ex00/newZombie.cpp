#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie* zombie_ptr = new Zombie(name);
	if (!zombie_ptr)
		return (NULL);
	return zombie_ptr;
}