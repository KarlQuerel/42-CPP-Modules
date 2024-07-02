#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include "cstdlib"
#include "fstream"

class	Bureaucrat;

class	AForm
{
	private:

		std::string const	_name;
		bool				_isSigned;
		unsigned int const	_gradeToSign;
		unsigned int const	_gradeToExecute;

	public:

		AForm();
		AForm(AForm const & src);
		AForm(std::string const & name, unsigned int const & gradeToSign, unsigned int const & gradeToExecute);
		virtual ~AForm();

		AForm & operator=(AForm const & rhs);

		// Getters & Setters
		std::string const	getName() const;
		bool				getSigned() const;
		unsigned int		getGradeToSign() const;
		unsigned int		getGradeToExecute() const;

		// Methods
		void				beSigned(Bureaucrat const & bureaucrat);

		void				checkExecConditions(Bureaucrat const & executor) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
	
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

		class	FormNotSignedException : public	std::exception
		{
			public:

				virtual const char *	what() const throw();
		};

};

std::ostream & operator<<(std::ostream & output, AForm const & rhs);