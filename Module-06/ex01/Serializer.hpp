# pragma once

// Libs
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <stdint.h>

// Custom Libs
# include "Data.hpp"


/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program with only one argument! - 🛂🛂🛂" STR_END

// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	SERIALIZER		"Serializer	-->"

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
What is the uintptr_t data type?
What does it do?
Why do we use it?

It is used to convert address values ​​into integer values.
This is useful in cases where we want to represent the value of a pointer as an integer.
uintptr_t type is an integer type and can return the memory address of any data type.
can be stored regardless of its type.

Why did we use reinterpret_cast?
It is used to convert the memory address to the memory address of another data type.
Using this operator, we can convert the memory address of a data type to a pointer type like uintptr_t or void.
*/

class	Serializer
{

	private:

		// Constructors & Destructors
		Serializer();
		Serializer(Serializer const & src);

		// Operators Overloads
		Serializer & operator=(Serializer const & rhs);

	public:

		// Constructors & Destructors
		~Serializer();

		// Getters & Setters

		// Methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

		// Exceptions
};

// Non-member operators overloads
std::ostream & operator<<(std::ostream & output, Serializer const & rhs);