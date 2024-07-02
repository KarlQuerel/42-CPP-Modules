# pragma once

// Libs
# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>

/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program with only one argument! - 🛂🛂🛂" STR_END
# define	ARG_EMPTY		std::cout << BRED "		Input is empty!" STR_END

// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	ARR				"Arr	-> "

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END
# define	OUTPUT_OP		"Output assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END

// Tests
# define	TEST			std::cout << BMA "---------> Testing "
# define	T_INT			<< "ints:" STR_END
# define	T_FLOAT			<< "floats:" STR_END
# define	T_CHAR			<< "chars:" STR_END
# define	T_STR			<< "strings:" STR_END
# define	T_PARAM			<< "Parametric Constructors:" STR_END
# define	T_EMPTY			<< "Empty Array:" STR_END
# define	T_OOB			<< "Out of Bounds:" STR_END
# define	T_FILL			std::cout << BYE "--> Filling array a with '1'" STR_END
# define	T_ASSIGN		std::cout << BYE "--> Assigning b to a" STR_END

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

template <typename T>
class Array
{
	private:
		T * 			_array;
		unsigned int	_size;

	public:

		// Constructors & Destructors
		Array()
		: _array(new T[0]()), _size(0)
		{
			std::cout << BGR ARR D_CONS;
			return ;
		};

		Array(unsigned int n)
		: _array(new T[n]()), _size(n)
		{
			std::cout << BCY ARR PARAM_CONS; 
			return ;
		};

		Array(Array const & src)
		: _array(new T[src.size()]), _size(src.size())
		{
			std::cout << BYE ARR C_CONS;
			for (unsigned int i = 0; i < _size; i++)
				_array[i]= src._array[i];
			return ;
		};

		~Array()
		{
			std::cout << BRED ARR D_DES;
			delete [] _array;
			return ;
		};

		// Operators Overloads
		Array &			operator=(Array const & rhs)
		{
			std::cout << BMA ARR ASSIGN_OP;
			if (this != &rhs)
			{
				delete [] _array;
				_array = new T[rhs._size];
				_size = rhs._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		};
		T &				operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _array[index];
		};

		// Methods
		unsigned int	size() const
		{
			return _size;
		};

		// Exceptions
		class	OutOfBoundsException : public std::exception
		{
			public:
			virtual const char*	what() const throw()
			{
				return BRED "Index is out of bounds!";
			};
		};
};