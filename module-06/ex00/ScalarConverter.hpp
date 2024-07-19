# pragma once

// Libs
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>


/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program with only one argument! - 🛂🛂🛂" STR_END
# define	ARG_EMPTY		std::cout << BRED "		Input is empty!" STR_END
# define	P_CHAR_NO_DIS	std::cout << BYE "Char	-> Non-displayable!" STR_END
# define	P_CHAR_IMPOS	std::cout << BYE "Char	-> Impossible" STR_END
# define	P_INT_IMPOS		std::cout << BGR "Int	-> Impossible" STR_END
# define	TYPE_NOT_FOUND	std::cout << BRED "		Type is unknown!" STR_END

// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	SCALAR			"ScalarConverter	--> "

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

// Print
# define	P_CHAR			std::cout << BYE "Char	-> '"
# define	P_INT			std::cout << BGR "Int	-> "
# define	P_FLOAT			std::cout << BMA "Float	-> "
# define	P_DOUBLE		std::cout << BBL "Double	-> "

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

/*
--> Static Class
The ScalarConverter class is a static class.

You cannot define a class as static in C++. It is a specific declaration to C#.
In C++, however, if all member variables AND functions of a class are static, the class
is considered static on itself and variables won't be dependent on any object.
Thus, variables will have common values for the entire class.

Moreover, since instances cannot be created from this class, it's not necessary to define functions
related to instantion such as constructor, copy constructor, etc etc...

--> Static Member Function
A static member function cannot access any object of its class or any non-static data member or another class.
When all member functions are static, they cannot access any object. Using the self keyword "this" won't work.
So it's safe and better to declare them as private.

--> Static Variable
A static variable defined in the private section of a class is shared by all instances of the class.
Static variables have only one copy in memory and their lifetime is as long as the program's lifetime.
*/

enum	input_type
{
	EMPTY,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKWNOW
};

class	ScalarConverter
{

	private:

		// Constructors & Destructors
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);

		// Operators Overloads
		ScalarConverter & operator=(ScalarConverter const & rhs);

	public:

		// Constructors & Destructors
		~ScalarConverter();

		// Getters & Setters
		static input_type	getType(std::string literal_input);

		// Methods
		static void			convert(const std::string literal_input);

		// Exceptions
};

// Non-member operators overloads
std::ostream & operator<<(std::ostream & output, ScalarConverter const & rhs);