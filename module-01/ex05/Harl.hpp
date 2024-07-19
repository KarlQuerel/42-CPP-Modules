#ifndef HARL_H
# define HARL_H

// Libs
# include <iostream>
# include <string>

// Macros
# define	ERROR_ARG		"Please use the program without any arguments"

// Harl complaints
# define	DEBUG			"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define	INFO			"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define	WARNING			"I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month."
# define	ERROR			"This is unacceptable! I want to speak to the manager now."

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

class	Harl
{
	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		Harl();
		~Harl();

		void	complain(std::string level);

};

# endif