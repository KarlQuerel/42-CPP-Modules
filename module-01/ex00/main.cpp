#include "Zombie.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}
	
	Zombie	*zombie_1 = newZombie("Karl");
	Zombie	*zombie_2 = newZombie("Yako");

	zombie_1->announce();
	zombie_2->announce();

	randomChump("Jose");
	randomChump("Manu");

	delete zombie_1;
	delete zombie_2;
	return 0;
}