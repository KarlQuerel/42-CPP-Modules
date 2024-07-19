// Libs
# include <iostream>
# include <string>
# include <fstream>

// Macros
# define	ERROR_ARG		"Please use the program in the following order : <filename> toFind toReplace"
# define	ERROR_EMPTY		"Empty strings detected!"
# define	OPEN_ERROR		"Unable to open input file!"
# define	CREATE_ERROR	"Unable to create output file!"

//Colors
# define	BRED			"\e[1;31m"
# define	COLOR_RESET		"\e[0m"

bool	empty_args(char **av)
{
	for (int i = 1; i < 3; i++)
	{
		if (av[i][0] == '\0')
			return (true);
	}
	return (false);
}

void	replace(std::string filename, const std::string& toFind, const std::string& toReplace)
{
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << BRED OPEN_ERROR COLOR_RESET << std::endl;
		return ;
	}

	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << BRED CREATE_ERROR COLOR_RESET << std::endl;
		return ;
	}

	std::string	line;
	while (std::getline(inputFile, line))
	{
		size_t	position = 0;
		while ((position = line.find(toFind, position)) != std::string::npos)
		{
			line = line.substr(0, position) + toReplace + line.substr(position + toFind.length());
			position += toReplace.length();
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();

}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << BRED ERROR_ARG << std::endl;
		return 1;
	}

	if (empty_args(av) == true)
	{
		std::cout << BRED ERROR_EMPTY << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string	toFind = av[2];
	std::string	toReplace = av[3];

	replace(filename, toFind, toReplace);


	return 0;
}