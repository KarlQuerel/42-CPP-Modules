#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	try
	{

		LINE_BREAK;
		std::cout << BCY "-------- Let's create some Bureaucrats --------" STR_END;
		LINE_BREAK;

		Bureaucrat	bureaucrat_1("Gandalf", 1);
		Bureaucrat	bureaucrat_2("Obi-Wan", 2);
		Bureaucrat	bureaucrat_3("Saruman", 10);
		Bureaucrat	bureaucrat_4("Darth Vader", 148);
		Bureaucrat	bureaucrat_5("Krillin", 150);

		std::cout << bureaucrat_1 << STR_END;
		std::cout << bureaucrat_2 << STR_END;
		std::cout << bureaucrat_3 << STR_END;
		std::cout << bureaucrat_4 << STR_END;
		std::cout << bureaucrat_5 << STR_END;

		LINE_BREAK;
		std::cout << BCY "-------- Now let's create some Forms --------" STR_END;
		LINE_BREAK;

		PresidentialPardonForm	form_1("Jean-Pierre");
		RobotomyRequestForm		form_2("Vegeta");
		ShrubberyCreationForm	form_3("Elwynn Forest");

		std::cout << form_1 << STR_END;
		std::cout << form_2 << STR_END;
		std::cout << form_3 << STR_END;

		LINE_BREAK;
		std::cout << BMA "-------- Let's test Presidential Pardon Form --------" STR_END;
		LINE_BREAK;

		TEST T_NOT_SIGNED;
		bureaucrat_3.executeForm(form_1);
		
		LINE_BREAK;
		TEST "Signed but bureaucrats have a " T_GRADE_LOW;
		bureaucrat_1.signForm(form_1);
		bureaucrat_4.signForm(form_1);
		bureaucrat_4.executeForm(form_1);

		LINE_BREAK;
		TEST "Signed and bureaucrats have a " T_GRADE_HIGH;
		bureaucrat_1.executeForm(form_1);

		LINE_BREAK;
		std::cout << BMA "-------- Let's test Robotomy Request Form --------" STR_END;
		LINE_BREAK;

		TEST T_NOT_SIGNED;
		bureaucrat_3.executeForm(form_2);
		
		LINE_BREAK;
		TEST "Signed but bureaucrats have a " T_GRADE_LOW;
		bureaucrat_1.signForm(form_2);
		bureaucrat_4.signForm(form_2);
		bureaucrat_4.executeForm(form_2);

		LINE_BREAK;
		TEST "Signed and bureaucrats have a " T_GRADE_HIGH;
		bureaucrat_1.executeForm(form_2);

		LINE_BREAK;
		std::cout << BMA "-------- Let's test Shrubbery Creation Form --------" STR_END;
		LINE_BREAK;

		TEST T_NOT_SIGNED;
		bureaucrat_3.executeForm(form_3);
		
		LINE_BREAK;
		TEST "Signed but bureaucrats have a " T_GRADE_LOW;
		bureaucrat_1.signForm(form_3);
		bureaucrat_4.signForm(form_3);
		bureaucrat_4.executeForm(form_3);

		LINE_BREAK;
		TEST "Signed and bureaucrats have a " T_GRADE_HIGH;
		bureaucrat_1.executeForm(form_3);
	}
	catch (std::exception const & invalid)
	{
		std::cout << BRED << invalid.what() << STR_END;
	}

	return 0;
}