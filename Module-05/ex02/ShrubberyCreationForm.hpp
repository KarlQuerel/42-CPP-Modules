#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	private:

		std::string	_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		// Getters & Setters
		std::string	getTarget() const;
	
		// Methods
		void		execute(Bureaucrat const & executor) const;

		class	OpenFileError : public std::exception
		{
			public:

				const char *	what() const throw();

		};
};

std::ostream & operator<<(std::ostream & output, ShrubberyCreationForm const & rhs);