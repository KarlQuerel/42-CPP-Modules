# include "ClapTrap.hpp"

int	main(int ac, char **av)
{
	(void)av;

	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	std::cout << BYE CONS_CALL STR_END;

	ClapTrap	Robot1("Jean-Pierre");
	ClapTrap	Robot2("Josiane");

	std::cout << BYE MEMB_CALL STR_END;

	Robot1.attack("Josiane");
	Robot2.takeDamage(0);
	Robot1.beRepaired(50);

	std::cout << BYE ENERG_CALL STR_END;
	for (int i = 0; i < 13; i++)
		Robot1.attack("Josiane");

	std::cout << BYE DSTRUC_CALL STR_END;
	return 0;

}