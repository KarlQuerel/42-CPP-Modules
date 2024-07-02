# include "Bureaucrat.hpp"

// Constructors & Destructors
Bureaucrat::Bureaucrat()
: _name("Gandalf the Grey"), _grade(MIN_GRADE)
{
	std::cout << BGR BUREAUCRAT D_CONS;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
: _name(src.getName()), _grade(src.getGrade())
{
	std::cout << BYE BUREAUCRAT C_CONS;
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int const & grade)
: _name(name)
{
	std::cout << BMA BUREAUCRAT PARAM_CONS;
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BRED BUREAUCRAT D_DES;
	return ;
}

// Operators Overloads
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << BMA BUREAUCRAT ASSIGN_OP;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream & operator<<(std::ostream & output, Bureaucrat const & rhs)
{
	std::cout << BMA BUREAUCRAT OUTPUT_OP;
	output << BGR "Hi! My name is " << rhs.getName() << " and my grade is " << rhs.getGrade() << "!";
	return output;
}

// Getters & Setters
std::string const	Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return ;
}

// Methods
void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return ;
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BGR << this->_name << " signed the " << form.getName() << "!" STR_END;
	}
	catch (const std::exception invalid)
	{
		std::cout << BRED << this->_name << "'s grade is too low to sign the " << form.getName() << "!" STR_END;
	}
	return ;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << BGR << this->_name << " executed the " << form.getName() << "!" STR_END;
	}
	catch (const std::exception & invalid)
	{
		std::cout << BRED << this->_name << " failed to execute the " << form.getName() << " because " << invalid.what() << STR_END;
	}
	return ;
}

// Exceptions
const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return GRADE_HIGH;
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return GRADE_LOW;
}
