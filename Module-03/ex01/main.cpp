# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main(int ac, char **av)
{
	(void)av;

	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	std::cout << BYE CONS_CALL STR_END;

	ClapTrap	Clap1("Sauron");
	ClapTrap	Clap2("Gandalf");
	ClapTrap	Clap3(Clap2);

	ScavTrap	Scav1("Jean-Pierre");
	ScavTrap	Scav1bis(Scav1);
	ScavTrap	Scav2("Obi-Wan");

	std::cout << BYE MEMB_CALL STR_END;

	Clap1.attack("Jean-Pierre");
	Scav1.takeDamage(0);
	Clap1.beRepaired(50);
	Clap3.beRepaired(10);

	std::cout << BYE ENERG_CALL STR_END;
	for (int i = 0; i < 13; i++)
		Clap1.attack("Jean-Pierre");


	Scav1.attack("Gandalf");
	Clap2.beRepaired(5);
	Scav2.attack("Jean-Pierre");
	Scav1.takeDamage(20);

	Scav1.guardGate();
	Scav1bis.guardGate();
	
	std::cout << BYE DSTRUC_CALL STR_END;
	return 0;

}