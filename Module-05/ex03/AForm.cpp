#include "AForm.hpp"

// Constructors & Destructors
AForm::AForm()
: _name("B42"), _isSigned(false), _gradeToSign(MAX_GRADE), _gradeToExecute(MAX_GRADE)
{
	std::cout << BGR FORM D_CONS;
	return ;
}

AForm::AForm(AForm const & src)
: _name(src.getName()), _isSigned(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << BYE FORM C_CONS;
	return ;
}

AForm::AForm(std::string const & name, unsigned int const & gradeToSign, unsigned int const & gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << BMA FORM PARAM_CONS;
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::~AForm()
{
	std::cout << BRED FORM D_DES;
	return ;
}

// Operators Overloads
AForm &	AForm::operator=(AForm const & rhs)
{
	std::cout << BMA FORM ASSIGN_OP;
	if (this != &rhs)
		this->_isSigned = rhs.getSigned();
	return *this;
}

std::ostream & operator<<(std::ostream & output, AForm const & rhs)
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
std::string const	AForm::getName() const
{
	return this->_name;
}

bool	AForm::getSigned() const
{
	return this->_isSigned;
}

unsigned int	AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned int	AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
	return ;
}

void	AForm::checkExecConditions(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooHighException();
	return ;
}

// Exceptions
const char *	AForm::GradeTooHighException::what() const throw()
{
	return FORM_HIGH;
}

const char *	AForm::GradeTooLowException::what() const throw()
{
	return FORM_LOW;
}

const char *	AForm::FormNotSignedException::what() const throw()
{
	return FORM_NOT_SIGNED;
}