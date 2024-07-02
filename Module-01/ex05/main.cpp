# include "Harl.hpp"

int	main(int ac, char ** av)
{
	Harl	harl;

	(void)av;
	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("KARLO TANGO");

	return 0;
}