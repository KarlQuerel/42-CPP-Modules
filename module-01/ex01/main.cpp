# include "Zombie.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	int	Zomb_numb = 10;

	Zombie*	zombie_1 = zombieHorde(Zomb_numb, "Frankenstein");
	if (zombie_1 == NULL)
		return 1;
	for (int i = 0; i < Zomb_numb; i++)
		zombie_1[i].announce();
	
	delete[] zombie_1;
	return 0;
}