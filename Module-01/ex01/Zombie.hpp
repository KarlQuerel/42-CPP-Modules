#ifndef ZOMBIE_H
# define ZOMBIE_H

// Libs
# include <iostream>
# include <string>
# include <new>

// Macros
# define	BRAINZ			"BraiiiiiiinnnzzzZ..."
# define	SQUASHED		" has been squashed!"
# define	ERROR_ALLOC		"Please be gentle with my crappy program\nOnly allocate between 1 and 100000"
# define	ERROR_ARG		"Please use the program without any arguments"

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

class	Zombie
{
	private:

		std::string	_name;

	public:

		Zombie();
		~Zombie();

		void	announce() const;
		void	assign_name(std::string name);

};
Zombie* zombieHorde(int N, std::string name);
void	ErrorMsg(void);

# endif