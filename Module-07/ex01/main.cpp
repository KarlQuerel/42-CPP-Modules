# include "iter.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	int			arr_int[] = {0, 1, 2, 3, 4, 5};
	float		arr_float[] = {0.1f, 0.2f, 0.3f, 4.2f, 3.2f, 10.569f};
	char		arr_char[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	arr_string[] = {"salut", "les", "gens"};

	TEST T_INT;
	::iter<int>(arr_int, 6, print_all<int>);
	LINE_BREAK;

	TEST T_FLOAT;
	::iter<float>(arr_float, 6, print_all<float>);
	LINE_BREAK;

	TEST T_CHAR;
	::iter<char>(arr_char, 5, print_all<char>);
	LINE_BREAK;

	TEST T_STR;
	::iter<std::string>(arr_string, 3, print_all<std::string>);
	LINE_BREAK;

	return 0;
}