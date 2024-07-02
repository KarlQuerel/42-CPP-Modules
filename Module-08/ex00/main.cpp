# include "easyfind.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	size_t	vec_size = 10;
	std::cout << BYE "-->	Let's create a vector of size " << vec_size << "." << STR_END;
	
	std::vector<int>	vec_1;

	/*
		- vector.push_back(value)
		value	= value added at the end of the vector
		The vector size is changed automatically
	*/

	for (size_t index = 0; index <= vec_size; index++)
		vec_1.push_back(index);

	std::cout << BMA "-->	Now let's print all elements :" << STR_END;
	
	std::vector<int>::iterator	begin = vec_1.begin();
	std::vector<int>::iterator	end = vec_1.end();

	for (; begin != end; begin++)
		std::cout << BGR << *begin << " " STR_END;

	
	std::cout << BCY "-->	Let's try to find a value within our bounds:" << STR_END;
	LINE_BREAK;

	easyfind(vec_1, 3);

	LINE_BREAK;

	std::cout << BCY "-->	Let's try to find a value beyond our bounds:" << STR_END;
	LINE_BREAK;

	easyfind(vec_1, -2);

	LINE_BREAK;
	return 0;
}