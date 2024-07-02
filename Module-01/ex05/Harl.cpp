# include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug()
{
	std::cout << BYE DEBUG COLOR_RESET << std::endl;
	return ;
}

void	Harl::info()
{
	std::cout << BGR INFO COLOR_RESET << std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout << BMA WARNING COLOR_RESET << std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << BCY ERROR COLOR_RESET << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (comments[i] == level)
			return (this->*functions[i])();
	}

	return ;
}