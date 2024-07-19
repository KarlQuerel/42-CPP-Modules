#include "Phonebook.hpp"

/***********************************************\
|					Constructor					|
\***********************************************/
Phonebook::Phonebook()
{
	//std::cout << "Phonebook constructor called\n\n" << std::endl;
}
/***********************************************\
|					Deconstructor				|
\***********************************************/
Phonebook::~Phonebook()
{
	// std::cout << "Phonebook deconstructor called\n\n" << std::endl;
}


/***********************************************\
|					Methods						|
\***********************************************/
void	Phonebook::Welcome_msg(void) const
{
	std::cout << BYE WELCOME << std::endl;
	return ;
}

void	Phonebook::Wrong_msg(void) const
{
	std::cout << BRED NO_ARG COLOR_RESET << std::endl;
	return ;
}

void	Phonebook::Ask_user(void) const
{
	std::cout << BWHT OPTIONS << std::endl;
	std::cout << BWHT DELIMITER << std::endl;
	std::cout << YEL ADD << std::endl;
	std::cout << GRN SEARCH << std::endl;
	std::cout << RED EXIT << std::endl;
	std::cout << BWHT DELIMITER COLOR_RESET << std::endl;
	std::cout <<"\t> ";
	return ;
}

bool	Phonebook::IsInputAdd(const std::string input)
{
	if (input.compare("ADD") == 0 || input.compare("add") == 0)
		return (true);
	return (false);
}

bool	Phonebook::IsInputSearch(const std::string input)
{
	if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
		return (true);
	return (false);
}

bool	Phonebook::IsInputExit(const std::string input)
{
	if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
		return (true);
	return (false);
}

bool	Phonebook::AddContact(int index)
{
	Contact	temp;

	if (temp.Valid_check_all() == false)
	{
		std::cout << BRED WRG_FRMT COLOR_RESET << std::endl;
		return (false);
	}
	this->_contacts[index] = temp;
	std::cout << BGR NEW COLOR_RESET << std::endl;
	return (true);
}

void	Phonebook::SearchContact()
{
	PrintAll();
	PrintOne();
	return ;
}

void	Phonebook::PrintAll()
{
	std::cout << WHT PRINT_HU_DELIM << std::endl;
	std::cout << WHT PRINT_CTGRS << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].DisplayAll(i + 1);
	std::cout << WHT PRINT_HD_DELIM << std::endl;
	return ;
}

void	Phonebook::PrintOne()
{
	std::string	user_input;
	int index = 0;

	std::cout << YEL TTL_INDEX << std::endl;
	while (index <= 0 || index >= 9)
	{
		std::cout << WHT WH_INDEX;
		if (!std::getline(std::cin, user_input))
			this->_contacts[0].Signal_msg();

		if (std::istringstream(user_input) >> index && index >= 1 && index <= 8 && user_input.length() == 1)
			this->_contacts[index - 1].DisplayContact();
		else
		{
			std::cout << BRED ERR_INDEX;
			std::cout << RED ERR_INDEX_1 COLOR_RESET;
		}
	}
	return ;
}

void	Phonebook::Loop(void) const
{
	Phonebook	phonebook;
	Contact		contact;
	std::string	user_input;

	int	contact_number = 0;

	while (1)
	{
		contact_number = contact.Update_contacts(contact_number);
		Ask_user();
		if (!std::getline(std::cin, user_input))
			contact.Signal_msg();
		if (phonebook.IsInputAdd(user_input))
			{
				std::cout << std::endl;
				if (phonebook.AddContact(contact_number) == true)
					contact_number++;
			}
		else if (phonebook.IsInputSearch(user_input))
			{
				std::cout << std::endl;
				phonebook.SearchContact();
			}
		else if (phonebook.IsInputExit(user_input))
			{
				std::cout << BYE EXIT_MSG COLOR_RESET << std::endl;
				exit(0);
			}
		else
			std::cout << BRED WRG_INPUT COLOR_RESET;
	}
	return ;
}