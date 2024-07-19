# pragma once

// Libs
# include <iostream>
# include <string>

/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program without any arguments! - 🛂🛂🛂" STR_END
# define	B_GRADE_HIGH	BRED "🚫🚫🚫 - Holy smoke! This grade is too high! - 🚫🚫🚫"
# define	B_GRADE_LOW		BRED "🚫🚫🚫 - Holy cow! This grade is too low! - 🚫🚫🚫"


// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Specific values
#define		MAX_GRADE		1
#define		MIN_GRADE		150

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	BUREAUCRAT		"Bureaucrat	--> "

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END
# define	OUTPUT_OP		"Output assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END

// Tests
# define	TEST			std::cout << BBL "------------------> Testing "
# define	T_DEF			<< "default constructor:" STR_END
# define	T_PAR			<< "parametric constructor:" STR_END
# define	T_GRADE_LOW		<< "low grade:" STR_END
# define	T_GRADE_HIGH	<< "high grade:" STR_END
# define	T_INCR			<< "grade incrementation:" STR_END
# define	T_DECR			<< "grade decrementation:" STR_END

// Colors
# define	BLK				"\e[0;30m"
# define	RED				"\e[0;31m"
# define	GRN				"\e[0;32m"
# define	YEL				"\e[0;33m"
# define	MAG				"\e[0;35m"
# define	CYN				"\e[0;36m"
# define	WHT				"\e[0;37m"
# define	BLUE			"\e[0;34m"

// Bold
# define	BRED			"\e[1;31m"
# define	BWHT			"\e[1;37m"
# define	BGR				"\e[1;32m"
# define	BYE				"\e[1;33m"
# define	BBL				"\e[1;34m"
# define	BMA				"\e[1;35m"
# define	BCY				"\e[1;36m"

// Reset
# define	COLOR_RESET		"\e[0m"
# define	STR_END			COLOR_RESET << std::endl


class	Bureaucrat
{

	private:

		std::string const	_name;
		int unsigned		_grade;

	public:

		Bureaucrat();
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name, unsigned int const & grade);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const	getName() const;
		unsigned int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

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

std::ostream & operator<<(std::ostream & output, Bureaucrat const & rhs);