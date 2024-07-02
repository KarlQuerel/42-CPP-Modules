#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Form	form1;
		std::cout << form1 << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST T_PAR;

	try
	{
		Form	form2("A2", 10, 42);
		std::cout << form2 << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST "an executing " T_GRADE_LOW;

	try
	{
		Form	low_grade("A3", 12, 151);
		std::cout << low_grade << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST "a signing " T_GRADE_HIGH;

	try
	{
		Form	high_grade("A4", 0, 42);
		std::cout << high_grade << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST "a bureaucrat with a low grade to sign it" STR_END;

	try
	{
		Bureaucrat	Param("Micheline de la RH", 42);
		Form		canIsignIt("A5", 1, 150);

		Param.signForm(canIsignIt);
		std::cout << canIsignIt << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST "a bureaucrat with a low grade to execute it" STR_END;

	try
	{
		Bureaucrat	Param("Roger du Marketing", 42);
		Form		canIexecuteIt("A6", 150, 1);

		Param.signForm(canIexecuteIt);
		std::cout << canIexecuteIt << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;
	TEST "a succesful attempt to sign" STR_END;

	try
	{
		Bureaucrat	Param("Andre de la compta", 1);
		Form		GreatSuccess("A7", 1, 1);

		Param.signForm(GreatSuccess);
		std::cout << GreatSuccess << STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	return 0;
}