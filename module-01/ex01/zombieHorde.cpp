#include "Zombie.hpp"


Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0 || N > 100000)
	{
		std::cout << BRED ERROR_ALLOC COLOR_RESET << std::endl;
		return (NULL);
	}

	Zombie*	zombie_memb = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_memb[i].assign_name(name);
	return zombie_memb;
}