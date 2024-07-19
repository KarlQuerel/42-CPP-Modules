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

	/*
		We can define class members static using static keyword. When we declare
		a member of a class as static it means no matter how many objects of the class are created, 
		there is only one copy of the static member.
		A static member is shared by all objects of the class. All static data is initialized to zero
		when the first object is created, if no other initialization is present. We can't put it in the 
		class definition but it can be initialized outside the by redeclaring the static variable, 
		using the scope resolution operator :: to identify which class it belongs to.
	*/
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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	/*
		To convert a floating point to a fixed point we multiply the float number
		with the base raised to the power of n (n the size of the fractional part)
		to do the opposite we divide
	*/
		float	toFloat(void) const;
		int		toInt(void) const;

		// Comparison operators
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
	
		// Arithmetic operators
		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;

		// Iteration operators
		Fixed	operator++(); // post
		Fixed	operator++(int); // pre
		Fixed	operator--(); // post
		Fixed	operator--(int); // pre

		// Assignment operators
		Fixed & operator=(Fixed const & rhs);

	/*
		Static Function Members
		By declaring a function member as static, you make it independent of any
		 particular object of the class. A static member function can be called 
		 even if no objects of the class exist and the static functions are accessed
		 using only the class name and the scope resolution operator ::.

		A static member function can only access static data member, other static
		member functions and any other functions from outside the class.

		Static member functions have a class scope and they do not have access
		to the this pointer of the class. You could use a static member function
		to determine whether some objects of the class have been created or not.
	*/
	Fixed static & min(Fixed &left, Fixed &right);
	Fixed static const & min(Fixed const &left, Fixed const &right);
	Fixed static & max(Fixed &left, Fixed &right);
	Fixed static const & max(Fixed const &left, Fixed const &right);

};

std::ostream & operator <<(std::ostream & o, Fixed const & rhs);

# endif