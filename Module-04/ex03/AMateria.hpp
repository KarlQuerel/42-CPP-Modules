# pragma once

// Libs
# include <iostream>
# include <string>
# include "ICharacter.hpp"


/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "Please use the program without any arguments" STR_END
# define	ERROR_INDEX		std::cout << BRED "Please give my crappy program an index between 0 and 3" STR_END

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	MATERIA			"AMateria	--> "
# define	CHARACTER		"Character	--> "
# define	CURE			"Cure		--> "
# define	ICE				"Ice		--> "
# define	MAT_SOURCE		"Materia Source	--> "
# define	MAT_NULL		std::cout << BRED "Cannot learn a NULL Materia!" STR_END
# define	MATERIA_EMP		": I cannot equip an empty Materia!" STR_END
# define	MAT_LEARNT		" type Materia has been learned" STR_END
# define	MAT_NOT_FOUND	std::cout << BRED "Cannot find any Materia with the following type: "
# define	MAT_FULL		std::cout << BRED "MateriaSource is full!" STR_END
# define	FULL_INV		": My inventory is full! I should unequip a materia before assigning a new one..." STR_END
# define	MAT_EQU			" type Materia has been equipped to my slot inventory # "
# define	UNEQU_MAT_SUCC	" type Materia has been unequipped from my slot inventory # "
# define	UNEQU_MAT_FAIL	": I cannot unequip anything from my inventory slot # "
# define	EMP_INV			": Silly me! I don't have anything equipped on this slot!" STR_END

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END
# define	DELIM			std::cout << BYE "----------------------------------------------" STR_END

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

class ICharacter;

class	AMateria
{
	protected:

		std::string	_type;

	public:

		AMateria();
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & rhs);

		AMateria(std::string const & type);

		std::string const &	getType() const;	//Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	private:
};