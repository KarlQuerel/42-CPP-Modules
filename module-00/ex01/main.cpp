#include "Phonebook.hpp"

int	main(int ac, char **av)
{
	Phonebook phonebook;

	(void)av;
	if (ac > 1)
	{
		phonebook.Wrong_msg();
		return 1;
	}
	phonebook.Welcome_msg();
	phonebook.Loop();
	return 0;
}
