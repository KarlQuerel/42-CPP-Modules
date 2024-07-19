#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

class	Form;

class	Intern
{
	private:

	public:

		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern & operator=(Intern const & rhs);

		// Methods
		AForm * makeForm(std::string name, std::string target);

};

std::ostream & operator<<(std::ostream & output, Intern const & rhs);