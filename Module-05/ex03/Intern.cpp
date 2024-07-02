# include "Intern.hpp"

// Constructors & Destructors
Intern::Intern()
{
	std::cout << BGR INTERN D_CONS;
	return ;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	std::cout << BYE INTERN C_CONS;
	return ;
}

Intern::~Intern()
{
	std::cout << BRED INTERN D_DES;
	return ;
}

// Operators Overloads
Intern &	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	std::cout << BMA INTERN ASSIGN_OP;
	return *this;
}

std::ostream & operator<<(std::ostream & output, Intern const & rhs)
{
	(void)rhs;
	std::cout << BMA INTERN OUTPUT_OP;
	return output;
}

// Methods
AForm *	Intern::makeForm(std::string name, std::string target)
{
	const std::string formTypes[3] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};

	for (int i = 0; i < 3; ++i)
	{
		if (formTypes[i] == name)
		{
			switch (i)
			{
				case 0:
					C_INTERN << name << STR_END;
					return new PresidentialPardonForm(target);
				case 1:
					C_INTERN << name << STR_END;
					return new RobotomyRequestForm(target);
				case 2:
					C_INTERN << name << STR_END;
					return new ShrubberyCreationForm(target);
				default:
					break;
			}
		}
	}
	INV_INTERN << name << STR_END;
	return NULL;
}

// Exceptions