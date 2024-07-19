// #include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}