# include "Span.hpp"

// Constructors & Destructors
Span::Span()
{
	std::cout << BGR SPAN D_CONS;
	return ;
}

Span::Span(unsigned int N)
: _size_max(N), _stored(0)
{
	std::cout << BMA SPAN PARAM_CONS;
	return ;
}

Span::Span(Span const & src)
: _size_max(src._size_max), _stored(src._stored)
{
	std::cout << BYE SPAN C_CONS;
	return ;
}

Span::~Span()
{
	std::cout << BRED SPAN D_DES;
	return ;
}

// Operators Overloads
Span &	Span::operator=(Span const & rhs)
{
	std::cout << BMA SPAN ASSIGN_OP;
	if (this != &rhs)
	{
		this->_size_max = rhs._size_max;
		this->_stored = rhs._stored;
	}
	return *this;
}

// Methods
void	Span::addNumber(int to_add)
{
	if (this->_stored.size() >= this->_size_max)
		throw Span::OverSizeMaxException();
	else
		this->_stored.push_back(to_add);
	return ;
}

void	Span::addNumberNAmountofTime(unsigned int NumberQuantity)
{
	srand(time(0));
	try
	{
		for (size_t index = 0; index < NumberQuantity; index++)
			this->addNumber(rand());
	}
	catch (std::exception const & invalid)
	{
		std::cout << BRED << invalid.what() << STR_END;
	}
}

/*
	- std::sort(first, last) will sort elements in ascending order
	first	= pointing to first element
	last	= pointing to last element

	- std::at(n) will return the nth element of a container
	-->	if n is out of bounds, std::at will throw an std::out_of_range exception

	--> we start our loop at the 2nd element of our array
*/
int	Span::shortestSpan()
{
	std::vector<int> & vec = this->_stored;

	if (is_valid_size(vec) == false)
		throw Span::TooFewElementsException();

	std::sort(vec.begin(), vec.end());

	int	ret_shortest = vec[1] - vec[0];

	for (size_t index = 1; index < vec.size() - 1; index++)
	{
		int	gap_to_find = vec[index + 1] - vec[index];

		if (gap_to_find < ret_shortest)
			ret_shortest = gap_to_find;
	}
	return ret_shortest;
}
/*
	- std::min_element(first, last) will find the minimum element in the array
	- std::max_element(first, last) will find the maximum element in the array
*/
int	Span::longestSpan()
{
	std::vector<int> & vec = this->_stored;

	if (is_valid_size(vec) == false)
		throw Span::TooFewElementsException();

	int	minimum = *std::min_element(vec.begin(), vec.end());
	int	maximum = *std::max_element(vec.begin(), vec.end());
	
	return abs(minimum - maximum);
}

bool	Span::is_valid_size(std::vector<int> & vec)
{
	if (vec.size() < 2)
		return false;
	return true;
}

void	Span::print_all()
{
	std::vector<int> & vec = this->_stored;
	
	std::cout << BYE "	Container: " << STR_END;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << BGR "	" << *it << STR_END;

	LINE_BREAK;
	return ;
}

// Exceptions
const char *	Span::TooFewElementsException::what() const throw()
{
	return BRED TOO_FEW;
}

const char *	Span::OverSizeMaxException::what() const throw()
{
	return BRED OVER_MAX;
}
