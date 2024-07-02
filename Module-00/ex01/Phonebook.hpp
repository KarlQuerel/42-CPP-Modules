#ifndef	PHONEBOOK_H
# define	PHONEBOOK_H

# include	<iostream>
# include	<iomanip>
# include	<string>
# include	<sstream>
# include	<limits>
# include	<cstdlib>
# include	"Contact.hpp"

# define SUCCESS 0;
# define FAILURE -1;

//Macros
# define	WELCOME "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\
:########:'##::::'##:'#######:'##::: ##'########'########::'#######::'#######:'##:::'##:\n\
:##.... ##:##:::: ##'##.... ##:###:: ##:##.....::##.... ##'##.... ##'##.... ##:##::'##::\n\
:##:::: ##:##:::: ##:##:::: ##:####: ##:##:::::::##:::: ##:##:::: ##:##:::: ##:##:'##:::\n\
:########::#########:##:::: ##:## ## ##:######:::########::##:::: ##:##:::: ##:#####::::\n\
:##.....:::##.... ##:##:::: ##:##. ####:##...::::##.... ##:##:::: ##:##:::: ##:##. ##:::\n\
:##::::::::##:::: ##:##:::: ##:##:. ###:##:::::::##:::: ##:##:::: ##:##:::: ##:##:. ##::\n\
:##::::::::##:::: ##. #######::##::. ##:########:########:. #######:. #######::##::. ##:\n\
:..::::::::..:::::..::.......::..::::..:........:........:::.......:::.......::..::::..:\n"

//Messages

//Errrors
# define	NO_ARG			"\n\t\tPlease use phonebook without arguments !"
# define	WRG_INPUT		"\n\t\t! Wrong input !\n\n"
# define	WRG_FRMT		"\n\t\tFormat is incorrect!\n"
# define	SIGNAL_MSG		"\n\t\tEOF detected!"
# define	ERR_INDEX		"\n\tYou have reached this phonebook's capacities... 😔"
# define	ERR_INDEX_1		"\n\tPlease be gentle with this crappy program and choose an index between 1 and 8\n"

//Others
# define	OPTIONS			"\tPlease choose between the following options:"
# define	DELIMITER		"\t--------------------------------------------"
# define	ADD				"\t➕ ADD:\t\tTo add a contact"
# define	SEARCH			"\t🔍 SEARCH:\tTo search for a contact"
# define	EXIT			"\t❌ EXIT:\tTo exit the program"
# define	NEW				"\n\t\tA new contact has been added!\n"
# define	EXIT_MSG		"\n\t\tPhonebook will now exit..."

//Display
# define	PRINT_HU_DELIM	"\t/=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\\"
# define	PRINT_CTGRS		"\t|   Index  |First Name| Last Name| Nickname |"
# define	PRINT_V_DELIM	"\t|----------|----------|----------|----------|"
# define	PRINT_HD_DELIM	"\t\\=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/\n"
# define	TTL_INDEX		"\tPlease specify the contact index of your choice"
# define	WH_INDEX		"\t> Index: "

// Attributes
# define	FIRST_NAME		"First Name: "
# define	LAST_NAME		"Last Name: "
# define	NICKNAME		"Nickname: "
# define	PHONE_NUMBER	"Phone Number: "
# define	DARKEST_SECRET	"Darkest Secret: "

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


class	Phonebook
{
	public:
			
			// Constructor and Destructor
			Phonebook(void);
			~Phonebook(void);

			// Methods

			// Message
			void	Welcome_msg(void) const;
			void	Wrong_msg(void) const;

			// Check
			bool	Is_valid_prompt(void);
			bool	IsInputAdd(const std::string input);
			bool	IsInputSearch(const std::string input);
			bool	IsInputExit(const std::string input);

			
			// Add
			bool	AddContact(int index);

			// Search
			void	SearchContact(void);
			void	PrintAll(void);
			void	PrintOne(void);

			// Others
			void	Ask_user() const;
			void	Loop(void) const;

			// Actions


	private:

			Contact	_contacts[8];

};

#endif