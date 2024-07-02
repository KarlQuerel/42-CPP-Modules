# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

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

	FragTrap	Frag1("Voldemort");
	FragTrap	Frag1bis(Frag1);
	FragTrap	Frag2("Darth Vader");

	std::cout << BYE MEMB_CALL STR_END;

	Clap1.attack("Jean-Pierre");
	Scav1.takeDamage(0);
	Clap1.beRepaired(50);
	Clap3.beRepaired(10);

	Frag1.attack("Darth Vader");
	Frag2.takeDamage(30);
	Frag2.beRepaired(100);

	std::cout << BYE ENERG_CALL STR_END;
	for (int i = 0; i < 13; i++)
		Clap1.attack("Jean-Pierre");


	for (int i = 0; i < 13; i++)
	{
		Scav1.attack("Darth Vader");
		Frag2.takeDamage(20);
	}

	Scav1.attack("Gandalf");
	Clap2.takeDamage(20);
	Clap2.beRepaired(5);
	Scav2.attack("Jean-Pierre");
	Scav1.takeDamage(20);

	Scav1.guardGate();
	Scav1bis.guardGate();
	
	Frag2.highFivesGuys();
	Frag1.highFivesGuys();


	std::cout << BYE DSTRUC_CALL STR_END;
	return 0;

}