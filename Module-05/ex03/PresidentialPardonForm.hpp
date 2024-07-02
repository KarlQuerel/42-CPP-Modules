#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	Bureaucrat;

class	PresidentialPardonForm : public AForm
{
	private:

		std::string	_target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		// Getters & Setters
		std::string	getTarget() const;
	
		// Methods
		void		execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<(std::ostream & output, PresidentialPardonForm const & rhs);