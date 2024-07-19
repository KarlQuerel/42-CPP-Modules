# include "Phonebook.hpp"

/***********************************************\
|					Constructor					|
\***********************************************/
Contact::Contact()
{
}
void	Contact::FillContact(
					std::string	first_name,
					std::string	last_name,
					std::string	nickname,
					std::string	phone_number,
					std::string	darkest_secret)
{  
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
	return ;
}
/***********************************************\
|					Deconstructor				|
\***********************************************/
Contact::~Contact()
{
}

/***********************************************\
|					Methods						|
\***********************************************/

void	Contact::Signal_msg(void) const
{
	std::cout << BYE SIGNAL_MSG COLOR_RESET << std::endl;
	exit(1);
}

#include <stdio.h>

bool	Contact::IsValidString(std::string str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isgraph(str[i]) && !isspace(str[i]))
			return (false);
	}
	return (true);
}

bool	Contact::IsValidNumber(std::string str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		while (isspace(str[i]))
			i++;
		if (!isdigit(str[i]) )
			return (false);
	}
	return (true);
}

bool	Contact::Valid_first_name()
{
	std::cout << "\t> " << FIRST_NAME;
	if (!std::getline(std::cin, this->_first_name))
		Signal_msg();
	if (_first_name.size() == 0 || IsValidString(_first_name) == false)
		return (false);
	return (true);
}

bool	Contact::Valid_last_name()
{
	std::cout << "\t> " << LAST_NAME;
	if (!std::getline(std::cin, this->_last_name))
		Signal_msg();
	if (_last_name.size() == 0 || IsValidString(_last_name) == false)
		return (false);
	return (true);
}

bool	Contact::Valid_nickname()
{
	std::cout << "\t> " << NICKNAME;
	if (!std::getline(std::cin, this->_nickname))
		Signal_msg();
	if (_nickname.size() == 0 || IsValidString(_nickname) == false)
		return (false);
	return (true);
}

bool	Contact::Valid_phone_number()
{
	std::cout << "\t> " << PHONE_NUMBER;
	if (!std::getline(std::cin, this->_phone_number))
		Signal_msg();
	if (_phone_number.size() == 0 || IsValidNumber(_phone_number) == false)
		return (false);
	return (true);
}

bool	Contact::Valid_darkest_secret()
{
	std::cout << "\t> " << DARKEST_SECRET;
	if (!std::getline(std::cin, this->_darkest_secret))
		Signal_msg();
	if (_darkest_secret.size() == 0 || IsValidString(_darkest_secret) == false) // accepte les whitespace
		return (false);
	return (true);
}

bool	Contact::Valid_check_all()
{
	if (Valid_first_name() == false ||
		Valid_last_name() == false ||
		Valid_nickname() == false ||
		Valid_phone_number() == false ||
		Valid_darkest_secret() == false)
			return (false);
	return (true);
}

void	Contact::DisplayAll(int i)
{
	std::cout << "\t|    -" << i << "-   |";
	TruncateOverTen(this->_first_name);
	TruncateOverTen(this->_last_name);
	TruncateOverTen(this->_nickname);
	std::cout << std::endl;
	return ;
}

void	Contact::TruncateOverTen(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0,9) << "." << "|";
	else
		std::cout << std::setfill(' ') << std::setw(10) << str.substr(0,10) << "|";
	return ;
}

int	Contact::Update_contacts(int contact_number) const
{
	if (contact_number == 8)
		return (0);
	return (contact_number);
}

void	Contact::DisplayContact()
{
	std::cout << std::endl;
	std::cout << "\t" << FIRST_NAME << this->_first_name << std::endl;
	std::cout << "\t" << LAST_NAME << this->_last_name << std::endl;
	std::cout << "\t" << NICKNAME << this->_nickname << std::endl;
	std::cout << "\t" << PHONE_NUMBER << this->_phone_number << std::endl;
	std::cout << "\t" << DARKEST_SECRET << this->_darkest_secret << std::endl;
	std::cout << std::endl;
	return ;
}
