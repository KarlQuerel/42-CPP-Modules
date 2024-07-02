# pragma once

// Libs
# include <iostream>
# include <string>

/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "Please use the program without any arguments" STR_END
# define	ERROR_INDEX		std::cout << BRED "Please give my crappy program an index between 0 and 100" STR_END

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	ANIMAL			"Animal		--> "
# define	CAT				"Cat		--> "
# define	DOG				"Dog		--> "
# define	WRG_ANIMAL		"WrongAnimal	--> "
# define	WRG_CAT			"Wrong Cat 	--> "
# define	BRAIN			"Brain		--> "

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END
# define	DOG_CREATE		std::cout << BWHT "---------------- Creating Dogs ---------------" STR_END
# define	CAT_CREATE		std::cout << BWHT "---------------- Creating Cats ---------------" STR_END

// Animals noises and ideas
# define	MEOW			"🙀🙀🙀 MeoOoOOOOOOOooooWWWwwwW 🙀🙀🙀" STR_END
# define	BARK			"🐶🐶🐶 Woof woof 🐶🐶🐶" STR_END
# define	NOISE			"🔊🔊🔊 Animal noises 🔊🔊🔊" STR_END
# define	WRONG_NOISE		"❌❌❌ Wrong Animal noises ❌❌❌" STR_END
# define	WRG_MEOW		"This should not print!" STR_END
# define	CAT_IDEAS		"Can I scratch this?"
# define	DOG_IDEAS		"Can I eat that ?"

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

class	AAnimal
{
	protected:

		std::string	_type;

	public:

		AAnimal();
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();
		AAnimal & operator=(AAnimal const & rhs);

		AAnimal(std::string name);

	/* 
		Pure virtual:

		makeSound has no implementation in the base class, making AAnimal an abstract
		class. Cannot be instantiated because of UB's.

		Any class derived from an abstract class must override all of its pure virtual
		functions to provide concrete implementations.
		
	*/

		virtual void	makeSound() const = 0;
		std::string		getType() const;

	private:
};