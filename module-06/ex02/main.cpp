# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *	generate(void)
{
	std::cout << BYE "Let's create one random class between A, B and C:" STR_END;
	DELIM;

	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << BBL "A will be created" STR_END;
			return (new A);

		case 1:
			std::cout << BBL "B will be created" STR_END;
			return (new B);

		case 2:
			std::cout << BBL "C will be created" STR_END;
			return (new C);

		default:
			return NULL;
	}

	return NULL;
}

/*
Dynamic overlapping of a subclass with a superclass pointer
Where specified, it is used to determine the type of the subclass.
dynamic_cast operation, a pointer or reference,
It enables conversion to another object type (superior or subclass in the class hierarchy).
*/

void	identify(Base * p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << BGR "A" STR_END;
	
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << BRED "B" STR_END;

	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << BMA "C" STR_END;

	return ;
}

/*
Catching the std::bad_cast exception
*/
void	identify(Base& p)
{
	Base	pointer;

	try
	{
		pointer = dynamic_cast<A&>(p);
		std::cout << BGR "A" STR_END;
	}
	catch(const std::exception& e) {}

	try
	{
		pointer = dynamic_cast<B&>(p);
		std::cout << BRED "B" STR_END;
	}
	catch(const std::exception& e) {}

	try
	{
		pointer = dynamic_cast<C&>(p);
		std::cout << BMA "C" STR_END;
	}
	catch(const std::exception& e) {}

	return ;
}


int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	Base	*base;

	base = generate();
	DELIM;

	identify(base);
	delete base;

	LINE_BREAK;

	std::cout << BCY "Let's wait a bit..." STR_END;
	sleep(1);

	std::cout << BCY "..." STR_END;
	sleep(1);

	std::cout << BCY "..." STR_END;
	sleep(1);

	LINE_BREAK;

	base = generate();
	DELIM;

	identify(*base);
	delete base;

	return 0;
}