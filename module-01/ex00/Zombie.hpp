#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <new>

// Macros
# define BRAINZ		"BraiiiiiiinnnzzzZ..."
# define SQUASHED	" has been squashed!"
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

		std::string _name;

	public:

		Zombie(std::string str);
		~Zombie();

		void	announce(void);

};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

# endif