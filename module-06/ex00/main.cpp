#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ERROR_ARG;
		return 1;
	}

	DELIM;

	ScalarConverter::convert(av[1]);

	DELIM;
	LINE_BREAK;
	return 0;
}