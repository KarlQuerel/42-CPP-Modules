# pragma once

// Libs
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <map>
# include <sstream>
# include <stack>
# include <cctype>
# include <stdexcept>


/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program with only one argument! - 🛂🛂🛂" STR_END
# define	ARG_EMPTY		std::cout << BRED "		Input is empty!" STR_END
# define	NOT_FOUND		std::cout << BRED "	Element was not found within the container!" STR_END
# define	F_CANT_OPEN		std::cout << BRED "	- Cannot open file! - " STR_END
# define	CSV_CANT_OPEN	std::cout << BRED "	- Cannot open CSV file! - " STR_END
# define	NEGATIVE_VALUE	std::cout << BRED "Error: not a positive number." STR_END
# define	OVER_1000		std::cout << BRED "Error: too large a number." STR_END
# define	TOO_MANY_DOTS	std::cout << BRED "Error: too many dots." STR_END
# define	INVALID_DATE	std::cout << BRED "Error: invalid date." STR_END
# define	BAD_INPUT		std::cout << BRED "Error: bad input => "
# define	ZERO_DIV		BRED "Error: cannot divide by zero!"
# define	INVALID_ARG		std::cout << BRED "Error: invalid argument!" STR_END

// Exceptions
# define	TOO_FEW			"	Container must contain at least two elements!"
# define	OVER_MAX		"	Elements is over the container's max size!"

// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	BTC				"BitcoinExchange	--> "

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END
# define	OUTPUT_OP		"Output assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END

// Tests
# define	TEST			std::cout << BGR "------------------> Testing "
# define	T_INT			<< "ints:" STR_END
# define	T_FLOAT			<< "floats:" STR_END
# define	T_CHAR			<< "chars:" STR_END
# define	T_STR			<< "strings:" STR_END
# define	FOUND			std::cout << BGR "	Element was found within the container!" STR_END


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