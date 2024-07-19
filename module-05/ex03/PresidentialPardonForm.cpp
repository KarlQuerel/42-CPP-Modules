#include "PresidentialPardonForm.hpp"

// Constructors & Destructors
PresidentialPardonForm::PresidentialPardonForm()
: AForm::AForm("Presidential Pardon Form", 25, 5), _target("home")
{
	std::cout << BGR P_FORM D_CONS;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
: AForm::AForm(src), _target(src.getTarget())
{
	std::cout << BYE P_FORM C_CONS;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: AForm::AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << BMA P_FORM PARAM_CONS;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BRED P_FORM D_DES;
	return ;
}

// Operators Overloads
PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << BMA P_FORM ASSIGN_OP;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::ostream & operator<<(std::ostream & output, PresidentialPardonForm const & rhs)
{
	std::cout << BMA P_FORM OUTPUT_OP;

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
std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

// Methods
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkExecConditions(executor);
		std::cout << BGR << this->_target << " has been pardoned by Zaphod Beeblerox." STR_END;
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