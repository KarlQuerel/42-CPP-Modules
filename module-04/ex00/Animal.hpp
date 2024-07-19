# pragma once

// Libs
# include <iostream>
# include <string>

/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "Please use the program without any arguments" STR_END

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

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END

// Animals noises
# define	MEOW			"🙀🙀🙀 MeoOoOOOOOOOooooWWWwwwW 🙀🙀🙀" STR_END
# define	BARK			"🐶🐶🐶 Woof woof 🐶🐶🐶" STR_END
# define	NOISE			"🔊🔊🔊 Animal noises 🔊🔊🔊" STR_END
# define	WRONG_NOISE		"❌❌❌ Wrong Animal noises ❌❌❌" STR_END
# define	WRG_MEOW		"Wrong Mee ah ouw Mee ah ouw, I am an imposter..." STR_END

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

class	Animal
{
	protected:

		std::string	_type;

	public:

	/*
		Virtual destructor:
		A virtual destructor is used to free up the memory space allocated by 
		the derived class object or instance while deleting instances of the derived
		class using a base class pointer object. A base or parent class destructor
		use the virtual keyword that ensures both base class and the derived class 
		destructor will be called at run time, but it called the derived class first
		and then base class to release the space occupied by both destructors.

		Every destructor down gets called no matter what. virtual makes sure it
		starts at the top instead of the middle.

		Virtual destructors are useful when you might potentially delete an instance 
		of a derived class through a pointer to base class:
	*/
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();
		Animal & operator=(Animal const & rhs);

		Animal(std::string name);

		virtual void	makeSound() const;
		std::string		getType() const;

	private:
};