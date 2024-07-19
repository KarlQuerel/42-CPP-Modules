#pragma once

// Libs
# include <iostream>
# include <string>

// Macros
# define	STR_END			COLOR_RESET << std::endl

# define	ERROR_ARG		"Please use the program without any arguments"
# define	D_CONS			"Default ClapTrap constructor called"
# define	NAMED_CONS		"ClapTrap Named constructor called"
# define	DECONS			"Destructor ClapTrap called"
# define	C_CONS			"Copy constructor ClapTrap called"

// ScavTrap
# define	D_CONS_SCAV		"Default ScavTrap constructor called"
# define	NAMED_CONS_SCAV	"ScavTrap Named constructor called"
# define	DECONS_SCAV		"Destructor ScavTrap called"
# define	C_CONS_SCAV		"Copy constructor ScavTrap called"
# define	GATEKEEP		" is now in Gate keeper Mode!"

# define	ASSIGN_OP		"Copy assignment operator called"
# define	NO_ENERG		" doesn't have enough energy to attack!"
# define	NO_HITPOINTS	" doesn't have any hitpoints left!"

//Calls
# define	CONS_CALL		"--- Calling constructors ---"
# define	MEMB_CALL		"--- Testing attack, damage and repair ---"
# define	ENERG_CALL		"--- Testing energy ---"
# define	DSTRUC_CALL		"--- Calling destructors ---"


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

class	ClapTrap
{

	// Not private anymore, protected = accessible from another child or parent class
	protected:

		std::string		_Name;
		unsigned int	_Hit_points;
		unsigned int	_Energy_points;
		unsigned int	_Attack_damage;

	public:

		// Canonical form
		ClapTrap();
		ClapTrap(ClapTrap const & src);
		~ClapTrap();
		ClapTrap & operator=(ClapTrap const & rhs);

		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amout);
		void	beRepaired(unsigned int amount);

};
