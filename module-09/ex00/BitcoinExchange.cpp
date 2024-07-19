# include "BitcoinExchange.hpp"

bool	is_db_openable(std::string const & db_name, std::ifstream & db)
{
	db.open(db_name.c_str());
	if (db.is_open() == 0)
	{
		CSV_CANT_OPEN;
		return false;
	}
	return true;
}

/*
	- std::getline(input, string, delimiter)

	input		= input stream from which to read the line
	string		= string variable where the read line is stored
	delimiter	= optional, is \n by default

	getline will read a line from an input stream till it encounters a delimiter
	
	--> using getline before looping to skip the first line of the csv file

	- std::stringstream is a class that allows string manipulations by treating
	strings as streams. (on this case to use as 1st parameter in getline()).
*/
void	parse_db(std::ifstream & csvfile, std::map<std::string, double> & bitcoin_map)
{
	std::string	line_string;
	std::getline(csvfile, line_string);

	while (std::getline(csvfile, line_string))
	{
		std::string			date_string;
		std::string			value_string;
		std::stringstream	line_stream(line_string);

		if (std::getline(line_stream, date_string, ',') && std::getline(line_stream, value_string))
			bitcoin_map[date_string] = std::atof(value_string.c_str());
	}
	return ;
}

std::map<std::string, double>	read_db(std::string const & db_name)
{

	std::ifstream	csvfile;
	if (is_db_openable(db_name, csvfile) == false)
		std::exit(1);

	std::map<std::string, double> bitcoin_map;
	parse_db(csvfile, bitcoin_map);

	csvfile.close();

	return bitcoin_map;
}

/*
	- Example	= 1992-09-29
*/
bool	are_digits(std::string const & date)
{
	for (int index = 0; index < 10; index++)
	{
		if (index != 4 && index != 7 && isdigit(date[index]) == 0)
			return false;
	}
	return true;
}
/* 
	- calculates february date
*/
bool	is_date_valid_txt(std::string const & date)
{
	if (date.length() != 11)
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
}

bool	are_dots_valid(std::string const & value)
{
	int	dot_count = 0;
	
	for (size_t index = 0; index < value.length(); index++)
	{
		if (value[index] == '.')
			dot_count++;
		if (dot_count > 1)
			return false;
	}
	return true;
}

/*
	- str.erase(c)				= removes char c from string str
	- str.find_last_not_of(c)	= searches the string str in reverse for any char different from c
	If found, returns the index of c
*/
void	parse_line(std::string const & line, std::string & date, std::string & value)
{
	std::stringstream	line_stream(line);
	std::getline(line_stream, date, '|');
	std::getline(line_stream, value);
	date.erase(date.find_last_not_of("\t") + 1);
}

bool	is_data_valid(std::string const & date, std::string const & value)
{
	double	value_d = std::atof(value.c_str());

	if (value_d < 0)
	{
		NEGATIVE_VALUE;
		return false;
	}
	else if (value_d > 1000)
	{
		OVER_1000;
		return false;
	}
	else if (are_dots_valid(value) == false)
	{
		TOO_MANY_DOTS;
		return false;
	}
	else if (is_date_valid_txt(date) == false)
	{
		INVALID_DATE;
		return false;
	}


	return true;
}

/*
	- map.lower_bound(str)	= find the iterator pointing to the first element in the container(map)
	whose key is not less than str
*/
void	process_data(std::string const & date, std::string const & value, std::map<std::string, double> const btc)
{
	double	value_d = std::atof(value.c_str());

	if (btc.find(date) != btc.end())
		std::cout << BGR << date << " => " << value_d << " = " << value_d * btc.at(date) << STR_END;
	else
	{
		std::map<std::string, double>::const_iterator it = btc.lower_bound(date);
		if (it != btc.begin())
			it--;
		std::cout << BGR << date << " => " << value_d << " = " << value_d * it->second << STR_END;
	}
	return ;
}

void	process_file(std::ifstream & file, std::map<std::string, double> & bitcoin)
{
	std::string	line, date, value;
	
	std::getline(file, line);
	while (std::getline(file, line))
	{
		parse_line(line, date, value);
		if (is_data_valid(date, value) == true)
			process_data(date, value, bitcoin);
		else
			BAD_INPUT << date << STR_END;
	}
	return ;
}