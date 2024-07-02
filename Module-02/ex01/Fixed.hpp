#ifndef FIXED_H
# define FIXED_H

// Libs
# include <iostream>
# include <string>
# include <cmath>

// Macros
# define	ERROR_ARG		"Please use the program without any arguments"
# define	D_CONS			"Default constructor called"
# define	DECONS			"Destructor called"
# define	C_CONS			"Copy constructor called"
# define	INT_CONS		"Int constructor called"
# define	FLOAT_CONS		"Float constructor called"
# define	ASSIGN_OP		"Copy assignment operator called"
# define	RAW				"getRawBit member function called"


//Colors
# define	BLK				"\e[0;30m"
# define	RED				"\e[0;31m"
# define	GRN				"\e[0;32m"
# define	YEL				"\e[0;33m"
# define	MAG				"\e[0;35m"
# define	CYN				"\e[0;36m"
# define	WHT				"\e[0;37m"
# define	BLUE			"\e[0;34m"

//Bold
# define	BRED			"\e[1;31m"
# define	BWHT			"\e[1;37m"
# define	BGR				"\e[1;32m"
# define	BYE				"\e[1;33m"
# define	BBL				"\e[1;34m"
# define	BMA				"\e[1;35m"
# define	BCY				"\e[1;36m"
//Reset
# define	COLOR_RESET		"\e[0m"

class	Fixed
{
	private:

		int					_rawBits;
		static const int	_fractBits = 8;

	public:

		// Canonical form
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);


		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

std::ostream & operator <<(std::ostream & o, Fixed const & rhs);

# endif