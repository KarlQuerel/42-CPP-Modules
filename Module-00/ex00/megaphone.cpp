#include <iostream>
#include <string>

# define LOUD "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int ac, char **av)
{
	std::string	user_input;
	std::string	output_message;

	if (ac > 1)
		output_message = "";
	else
		output_message = LOUD;
	
	for (int i = 1; i < ac; ++i)
		user_input += av[i];

	for (std::string::size_type i = 0; i < user_input.size(); ++i)
		user_input[i] = std::toupper(user_input[i]);

	std::cout << output_message << user_input << std::endl;
	return 0;
}
