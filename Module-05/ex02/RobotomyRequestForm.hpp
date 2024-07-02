#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	Bureaucrat;

class	RobotomyRequestForm : public AForm
{
	private:

		std::string	_target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string const & target);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		// Getters & Setters
		std::string	getTarget() const;
	
		// Methods
		void		execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<(std::ostream & output, RobotomyRequestForm const & rhs);