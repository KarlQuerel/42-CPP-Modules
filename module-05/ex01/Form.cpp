#include "Form.hpp"

// Constructors & Destructors
Form::Form()
: _name("B42"), _isSigned(false), _gradeToSign(MAX_GRADE), _gradeToExecute(MAX_GRADE)
{
	std::cout << BGR FORM D_CONS;
	return ;
}

Form::Form(Form const & src)
: _name(src.getName()), _isSigned(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << BYE FORM C_CONS;
	return ;
}

Form::Form(std::string const & name, unsigned int const & gradeToSign, unsigned int const & gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << BMA FORM PARAM_CONS;
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
	return ;
}

Form::~Form()
{
	std::cout << BRED FORM D_DES;
	return ;
}

// Operators Overloads
Form &	Form::operator=(Form const & rhs)
{
	std::cout << BMA FORM ASSIGN_OP;
	if (this != &rhs)
		this->_isSigned = rhs.getSigned();
	return *this;
}

std::ostream & operator<<(std::ostream & output, Form const & rhs)
{
	std::cout << BMA FORM OUTPUT_OP;

	output << BGR "📋📋📋 - The Form " << rhs.getName();
	if (rhs.getSigned() == true)
		output << " is signed. - 📋📋📋" STR_END;
	else
		output << " is not (yet ?) signed. - 📋📋📋" STR_END;

	output << BYE "In order to sign the form, a grade of " << rhs.getGradeToSign() << " is required." STR_END; 
	output << BMA "In order to execute the form, a grade of " << rhs.getGradeToExecute() << " is required." STR_END; 
	return output;
}

// Getters & Setters
std::string const	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_isSigned;
}

unsigned int	Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned int	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
	return ;
}

// Exceptions
const char *	Form::GradeTooHighException::what() const throw()
{
	return FORM_HIGH;
}

const char *	Form::GradeTooLowException::what() const throw()
{
	return FORM_LOW;
}
