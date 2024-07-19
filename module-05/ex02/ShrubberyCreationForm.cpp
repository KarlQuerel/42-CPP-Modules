#include "ShrubberyCreationForm.hpp"

// Constructors & Destructors
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm::AForm("Shrubbery Creation Form", 145, 137), _target("home")
{
	std::cout << BGR S_FORM D_CONS;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
: AForm::AForm(src), _target(src.getTarget())
{
	std::cout << BYE S_FORM C_CONS;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: AForm::AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << BMA S_FORM PARAM_CONS;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BRED S_FORM D_DES;
	return ;
}

// Operators Overloads
ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << BMA S_FORM ASSIGN_OP;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

std::ostream & operator<<(std::ostream & output, ShrubberyCreationForm const & rhs)
{
	std::cout << BMA S_FORM OUTPUT_OP;

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
std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

// Methods
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkExecConditions(executor);

		std::ofstream	newFile;

		newFile.open(_target.c_str(), std::fstream::out);

		if (!newFile.is_open())
			throw OpenFileError();

		newFile << DRAW_TREE;
		newFile.close();
		return ;
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

// Exceptions

const char *	ShrubberyCreationForm::OpenFileError::what() const throw()
{
	return FILE_ERROR;
}