#include "Bureaucrat.hpp"

int	main(int ac, char **av)
{
	
	(void)av;

	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	DELIM;
	CONS_CALL;
	DELIM;

	LINE_BREAK;
	TEST T_DEF;

	try
	{
		Bureaucrat	Default;
		std::cout << Default << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_PAR;

	try
	{
		Bureaucrat	Param("Jean-Eugene de la compta", 10);
		std::cout << Param << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_GRADE_LOW;

	try
	{
		Bureaucrat	Low_grade("Imposter", 151);
		std::cout << Low_grade << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_GRADE_HIGH;

	try
	{
		Bureaucrat	High_grade("Imposter", 0);
		std::cout << High_grade << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_INCR;

	try
	{
		Bureaucrat	Param("Micheline de la RH", 42);
		std::cout << Param << STR_END;
		for (int i = 0; i < 5; i++)
		{
			Param.incrementGrade();
			std::cout << Param << STR_END;
		}
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_DECR;

	try
	{
		Bureaucrat	Param("Roger du Marketing", 42);
		std::cout << Param << STR_END;
		for (int i = 0; i < 5; i++)
		{
			Param.decrementGrade();
			std::cout << Param << STR_END;
		}
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	return 0;
}