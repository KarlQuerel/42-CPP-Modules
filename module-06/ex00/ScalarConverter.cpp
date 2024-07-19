# include "ScalarConverter.hpp"

// Constructors & Destructors
ScalarConverter::ScalarConverter()
{
	std::cout << BGR SCALAR D_CONS;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	std::cout << BYE SCALAR C_CONS;
	(void) src;
	return ;
}

// Operators Overloads
ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	std::cout << BMA SCALAR ASSIGN_OP;
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BRED SCALAR D_DES;
	return ;
}

std::ostream & operator<<(std::ostream & output, ScalarConverter const & rhs)
{
	std::cout << BMA SCALAR OUTPUT_OP;
	(void) rhs;
	return output;
}

// Non-member functions
/*
static_cast is a standard type cast operation in C++.
Type casts using static_cast make code more readable and increases compliance with C++ standards.
*/
void	printChar(char c)
{
	if (std::isprint(c))
		P_CHAR << c << "'" STR_END;
	else
		P_CHAR_NO_DIS;
	
	P_INT		<< static_cast<int>(c) << STR_END;
	P_FLOAT		<< static_cast<float>(c) << 'f' << STR_END;
	P_DOUBLE	<< static_cast<double>(c) << STR_END;
	return ;
}

/*
--> CHAR_MIN and CHAR_MAX checks

Handling smallest and largest numerical values that the char data type can hold (climits library)
*/
void	printInt(long i)
{
	char c	= static_cast<char>(i);

	if (i < CHAR_MIN || i > CHAR_MAX)
		P_CHAR_IMPOS;
	else if (std::isprint(c))
		P_CHAR << c << "'" << STR_END;
	else
		P_CHAR_NO_DIS;

	if (i < INT_MIN || i > INT_MAX)
		P_INT_IMPOS;
	else
		P_INT << i << STR_END;

	P_FLOAT << static_cast<float>(i) << 'f' << STR_END;
	P_DOUBLE << static_cast<double>(i) << STR_END;
	return ;
}

/*
--> The isnan() function checks whether a decimal number is NaN (Not a Number).
--> The isinf() function checks whether a decimal number is infinity.
*/
void	printFloat(float f)
{
	char c	= static_cast<char>(f);

	if (std::isnan(f) || std::isinf(f) || f < CHAR_MIN || f > CHAR_MAX)
		P_CHAR_IMPOS;
	else if (std::isprint(c))
		P_CHAR << c << "'" << STR_END;
	else
		P_CHAR_NO_DIS;

	if (std::isnan(f) || std::isinf(f) || f < (float)INT_MIN || f > (float)INT_MAX)
		P_INT_IMPOS;
	else
		P_INT << static_cast<int>(f) << STR_END;

	P_FLOAT << f << 'f' << STR_END;
	P_DOUBLE << static_cast<double>(f) << STR_END;
	return ;
}

void	printDouble(double d)
{
	char c	= static_cast<char>(d);

	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		P_CHAR_IMPOS;
	else if (std::isprint(c))
		P_CHAR << c << "'" << STR_END;
	else
		P_CHAR_NO_DIS;

	if (std::isnan(d) || std::isinf(d) || d < (double)INT_MIN || d > (double)INT_MAX)
		P_INT_IMPOS;
	else
		P_INT << static_cast<int>(d) << STR_END;
	
	P_FLOAT << static_cast<float>(d) << 'f' << STR_END;
	P_DOUBLE << d << STR_END;
	return ;
}

bool	isEmpty(std::string const & input)
{
	if (input.length() == 0)
		return (true);
	return (false);
}

bool	isChar(std::string const & input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (true);
	return (false);
}

/*
--> std::strtol

First argument	-> c_string type to convert
Second argument	-> pointer on which the conversion stop
Third argument	-> conversion base (0 gives automatic detection)

If strol fails, it returns a pointer which won't be NULL
If it succeeds, it returns an empty pointer, thus we know the type of given string

*/
bool	isInt(std::string input)
{
	char	*ending_pointer = NULL;

	std::strtol(input.c_str(), &ending_pointer, 0);
	if (*ending_pointer == '\0')
		return true;
	return false;
}

/*
--> std::strod and std::strof

Exact same reasoning as std::strtol but without a third argument (no base needed)
*/
bool	isDouble(std::string input)
{
	char	*ending_pointer = NULL;

	std::strtod(input.c_str(), &ending_pointer);
	if (*ending_pointer == '\0')
			return true;
	return false;
}

bool	isFloat(std::string input)
{
	char	*ending_pointer = NULL;

	std::strtof(input.c_str(), &ending_pointer);
	if ((ending_pointer[0] == 'f' || ending_pointer[0] == 'F') && ending_pointer[1] == 0)
		return true;
	return false;
}

// Methods
void	ScalarConverter::convert(const std::string literal_input)
{
	input_type	type = getType(literal_input);

	switch (type)
	{
		case EMPTY:
			ARG_EMPTY;
			break ;
		
		case CHAR:
			printChar(literal_input[0]);
			break;

		case INT:
			printInt(std::atol(literal_input.c_str()));
			break;

		case FLOAT:
			printFloat(std::strtod(literal_input.c_str(), NULL));
			break;

		case DOUBLE:
			printDouble(std::strtod(literal_input.c_str(), NULL));
			break;

		case UNKWNOW:
			TYPE_NOT_FOUND;
			break;
		
		default:
			break;
	}
	return ;
}

// Getters & Setters
input_type	ScalarConverter::getType(std::string literal_input)
{
	if (isEmpty(literal_input) == true)
		return EMPTY;

	else if (isChar(literal_input) == true)
		return CHAR;

	else if (isInt(literal_input) == true)
		return INT;

	else if (isDouble(literal_input) == true)
		return DOUBLE;

	else if (isFloat(literal_input) == true)
		return FLOAT;

	return UNKWNOW;
}


