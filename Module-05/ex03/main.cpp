#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
	LINE_BREAK;

	try
	{
		Intern		intern_1;
		Bureaucrat	bureaucrat_1("Gandalf", 1);

		LINE_BREAK;
		std::cout << BCY "-------- Let's ask our intern to create a Presidential Pardon Form --------" STR_END;
		LINE_BREAK;

		AForm*	form_1 = intern_1.makeForm("Presidential Pardon Form", "Sauron");
		if (form_1)
		{
			std::cout << *form_1 << STR_END;
			bureaucrat_1.signForm(*form_1);
			bureaucrat_1.executeForm(*form_1);
			delete(form_1);
		}
		else
			NO_FORM;


		LINE_BREAK;
		std::cout << BCY "-------- Let's ask our intern to create a Robotomy Request Form --------" STR_END;
		LINE_BREAK;

		AForm*	form_2 = intern_1.makeForm("Robotomy Request Form", "Michel");
		if (form_2)
		{
			std::cout << *form_2 << STR_END;
			bureaucrat_1.signForm(*form_2);
			bureaucrat_1.executeForm(*form_2);
			delete(form_2);
		}
		else
			NO_FORM;


		LINE_BREAK;
		std::cout << BCY "-------- Let's ask our intern to create a Shrubbery Creation Form --------" STR_END;
		LINE_BREAK;

		AForm*	form_3 = intern_1.makeForm("Shrubbery Creation Form", "NOC42");
		if (form_3)
		{
			std::cout << *form_3 << STR_END;
			bureaucrat_1.signForm(*form_3);
			bureaucrat_1.executeForm(*form_3);
			delete(form_3);
		}
		else
			NO_FORM;

		LINE_BREAK;
		std::cout << BCY "-------- Let's ask our intern to create an Invalid Form --------" STR_END;
		LINE_BREAK;

		AForm*	form_4 = intern_1.makeForm("Random sh*t", "42");
		if (form_4)
		{
			std::cout << form_4 << STR_END;
			bureaucrat_1.signForm(*form_4);
			bureaucrat_1.executeForm(*form_4);
			delete(form_4);
		}
		else
			NO_FORM;
	}
	catch (std::exception const & invalid)
	{
		std::cout << BRED << invalid.what() << STR_END;
	}
	return 0;
}