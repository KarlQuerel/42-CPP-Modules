# include "BitcoinExchange.hpp"

bool	is_valid_arc_count(int const ac)
{
	if (ac != 2)
	{
		ERROR_ARG;
		return false;
	}
	else
		return true;
}

bool	is_file_openable(char * const & filename, std::ifstream & file)
{
	file.open(filename);
	if (file.is_open() == 0)
	{
		F_CANT_OPEN;
		return false;
	}
	return true;
}

bool	is_file_txt(char * const & filename)
{
	std::string	filename_str(filename);
	size_t	dot_position = filename_str.find_last_of(".");

	if (dot_position != std::string::npos && filename_str.substr(dot_position + 1) == "txt")
		return true;
	else
	{
		NOT_TXT;
		return false;
	}	
}

bool	is_file_csv(std::string csv_name)
{
	size_t	dot_position = csv_name.find_last_of(".");

	if (dot_position != std::string::npos && csv_name.substr(dot_position + 1) == "csv")
		return true;
	else
	{
		NOT_CSV;
		return false;
	}
}
bool	is_valid_numeric(std::string value)
{
	bool	dot_found = false;

	for (size_t index = 0; index < value.length(); index++)
	{
		char	c = value[index];
		if (c == '.')
		{
			if (dot_found == true || index == 0 || index == value.length() - 1)
				return false;
			dot_found = true;
		}
		else if (isdigit(c) == 0)
			return false;
	}
	return true;
}

bool	is_date_valid_csv(std::string const & date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	if (are_digits(date) == false)
		return false;
	


	int	year, month, day;
	char	dash;
	std::istringstream	iss(date);

	iss >> year >> dash >> month >> dash >> day;

	if (!iss)
		return false;
	
	if (year < 0)
		return false;
	
	if (month < 1 || month > 12)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}

	return true;

	return true;
}

bool	is_csv_valid_format(std::string csv_name)
{
	std::ifstream	file(csv_name.c_str());
	
	std::string	expected_header = "date,exchange_rate";

	std::string	header;
	if (!std::getline(file, header))
	{
		EMPTY_FILE;
		return false;
	}

	if (header != expected_header)
	{
		WRONG_HEADER;
		return false;
	}

	std::string	line;
	int			expected_num_columns = 2;
	int			line_number = 2;

	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			cell;
		int					num_columns = 0;

		while (std::getline(ss, cell, ','))
			num_columns++;
		
		if (num_columns != expected_num_columns)
		{
			WRONG_FMT;
			return false;
		}

		std::string			date, value;
		std::stringstream	line_stream(line);
		std::getline(line_stream, date, ',');
		std::getline(line_stream, value);

		if (is_date_valid_csv(date) == false)
		{
			WRONG_DATE_CSV;
			return false;
		}

		if (is_valid_numeric(value) == false)
		{
			WRONG_VALUE_CSV;
			return false;
		}
		
		line_number++;
	}
	file.close();
	return true;
}


int	main(int ac, char **av)
{
	LINE_BREAK;

	if (is_valid_arc_count(ac) == false)
		return 1;

	std::ifstream	file;

	if (is_file_openable(av[1], file) == false)
	{
		file.close();
		return 1;
	}

	if (is_file_txt(av[1]) == false)
	{
		file.close();
		return 1;
	}

	std::string csv_name = "data.csv";

	if (is_file_csv(csv_name) == false)
	{
		file.close();
		return 1;
	}


	std::ifstream	csvfile;
	if (is_db_openable(csv_name, csvfile) == false)
	{
		file.close();
		return 1;
	}

	if (is_csv_valid_format(csv_name) == false)
	{
		file.close();
		return 1;
	}

	std::map<std::string, double> bitcoin = read_db(csv_name);

	process_file(file, bitcoin);

	file.close();

	LINE_BREAK;

	return 0;
}