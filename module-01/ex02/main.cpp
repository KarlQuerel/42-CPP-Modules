# define	ERROR_ARG		"Please use the program without any arguments"
# define	DELIM			"------------------------------------------------"
# define	MMR_ADD			" memory address is :\t"
# define	VALUE			" value pointed is :\t"
# define	BRED			"\e[1;31m"
# define	COLOR_RESET		"\e[0m"

# include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::endl;

	std::cout << "str's" << MMR_ADD << &str << std::endl;
	std::cout << "stringPTR's" << MMR_ADD << stringPTR << std::endl;
	std::cout << "stringREF's" << MMR_ADD << &stringREF << std::endl;

	std::cout << BRED DELIM COLOR_RESET << std::endl;

	std::cout << "str's" << VALUE << str << std::endl;
	std::cout << "stringPTR's" << VALUE << *stringPTR << std::endl;
	std::cout << "stringREF's" << VALUE << stringREF << std::endl;

	return 0;
}