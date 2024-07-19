#ifndef CONTACT_H
# define CONTACT_H

# include "Phonebook.hpp"

class	Contact
{
	public:

			// Constructor and Destructor
			Contact(void);
			void	FillContact(
				std::string	first_name,
				std::string	last_name,
				std::string	nickname,
				std::string	phone_number,
				std::string	darkest_secret);
			~Contact(void);

			// Methods


			int		Update_contacts(int contact_number) const;
			void	Signal_msg(void) const;

			// Check
			bool	IsValidString(std::string str) const;
			bool	IsValidNumber(std::string str) const;
			bool	Valid_check_all();
			bool	Valid_first_name();
			bool	Valid_last_name();
			bool	Valid_nickname();
			bool	Valid_phone_number();
			bool	Valid_darkest_secret();
			
			void	DisplayAll(int i);
			void	DisplayContact(void);
			void	TruncateOverTen(std::string str);

	private:

			std::string	_first_name;
			std::string	_last_name;
			std::string	_nickname;
			std::string	_phone_number;
			std::string	_darkest_secret;
};

#endif