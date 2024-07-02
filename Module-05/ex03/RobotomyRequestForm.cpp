#include "RobotomyRequestForm.hpp"

// Constructors & Destructors
RobotomyRequestForm::RobotomyRequestForm()
: AForm::AForm("Robotomy Request Form", 72, 45), _target("home")
{
	std::cout << BGR R_FORM D_CONS;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
: AForm::AForm(src), _target(src.getTarget())
{
	std::cout << BYE R_FORM C_CONS;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
: AForm::AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << BMA R_FORM PARAM_CONS;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BRED R_FORM D_DES;
	return ;
}

// Operators Overloads
RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << BMA R_FORM ASSIGN_OP;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::ostream & operator<<(std::ostream & output, RobotomyRequestForm const & rhs)
{
	std::cout << BMA R_FORM OUTPUT_OP;

	output << BGR "📋📋📋 - The Form " << rhs.getName();
	if (rhs.getSigned() == true)
		output << " is signed. - 📋📋📋" STR_END;
	else
		output << " is not (yet ?) signed. - 📋📋📋" STR_END;

	output << BYE "In order to sign the form, a grade of " << rhs.getGradeToSign() << " is required." STR_END; 
	output << BMA "In order to execute the form, a grade of " << rhs.getGradeToExecute() << " is required." STR_END; 
	output << BCY "Target is " << rhs.getTarget() << "." STR_END;
	return output;
}

// Getters & Setters
std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

// Methods
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkExecConditions(executor);
		DRILLING;
		if (rand() % 2)
			std::cout << BGR << this->_target << " has been successfully robotomized!" STR_END;
		else
			std::cout << BRED << this->_target << "'s resisted the robotomy!" STR_END;
	}
	catch(const AForm::FormNotSignedException & invalid)
	{
		throw AForm::FormNotSignedException();
	}
	catch(const AForm::GradeTooHighException & invalid)
	{
		throw AForm::GradeTooHighException();
	}
	return ;
}