#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	Bureaucrat;

class	Form
{
	private:

		std::string const	_name;
		bool				_isSigned;
		unsigned int const	_gradeToSign;
		unsigned int const	_gradeToExecute;

	public:

		Form();
		Form(Form const & src);
		Form(std::string const & name, unsigned int const & gradeToSign, unsigned int const & gradeToExecute);
		~Form();

		Form & operator=(Form const & rhs);

		// Getters & Setters
		std::string const	getName() const;
		bool				getSigned() const;
		unsigned int		getGradeToSign() const;
		unsigned int		getGradeToExecute() const;

		// Methods
		void				beSigned(Bureaucrat const & bureaucrat);
	
		// Exceptions
		class	GradeTooHighException : public	std::exception
		{
			public:

				virtual const char *	what() const throw();
		};

		class	GradeTooLowException : public	std::exception
		{
			public:

				virtual const char *	what() const throw();
		};

};

std::ostream & operator<<(std::ostream & output, Form const & rhs);