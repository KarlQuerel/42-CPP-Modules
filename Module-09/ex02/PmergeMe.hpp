# pragma once

// Libs
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <map>
# include <sstream>
# include <stack>
# include <cctype>
# include <stdexcept>
# include <cstring>
# include <climits>
# include <ctime>

/***********************************\
|				Macros				|
\***********************************/

// Errors
# define	ERROR_ARG		std::cout << BRED "🛂🛂🛂 - Please use my crappy program with at least one argument! - 🛂🛂🛂" STR_END
# define	NOT_INT			std::cout << BRED "Error: Arguments are not positive integers!" STR_END
# define	ABOVE_MAX		std::cout << BRED "Error: Arguments are too big!" STR_END
# define	ARG_EMPTY		std::cout << BRED "		Input is empty!" STR_END
# define	NOT_FOUND		std::cout << BRED "	Element was not found within the container!" STR_END
# define	F_CANT_OPEN		std::cout << BRED "	- Cannot open file! - " STR_END
# define	CSV_CANT_OPEN	std::cout << BRED "	- Cannot open CSV file! - " STR_END
# define	NEGATIVE_VALUE	std::cout << BRED "Error: not a positive number." STR_END
# define	OVER_1000		std::cout << BRED "Error: too large a number." STR_END
# define	TOO_MANY_DOTS	std::cout << BRED "Error: too many dots." STR_END
# define	INVALID_DATE	std::cout << BRED "Error: invalid date." STR_END
# define	BAD_INPUT		std::cout << BRED "Error: bad input => "
# define	ZERO_DIV		BRED "Error: cannot divide by zero!"
# define	INVALID_ARG		std::cout << BRED "Error: invalid argument!" STR_END

// Exceptions
# define	TOO_FEW			"	Container must contain at least two elements!"
# define	OVER_MAX		"	Elements is over the container's max size!"

// Visuals
# define	DELIM			std::cout << BYE "----------------------------------------------------------" STR_END
# define	LINE_BREAK		std::cout << std::endl

// Constructors and Destructors
# define	D_CONS			"Default constructor called" STR_END
# define	PARAM_CONS		"Parametric constructor called" STR_END
# define	D_DES			"Destructor called" STR_END
# define	C_CONS			"Copy constructor called" STR_END
# define	BTC				"BitcoinExchange	--> "

// Operators
# define	ASSIGN_OP		"Copy assignment operator called" STR_END
# define	OUTPUT_OP		"Output assignment operator called" STR_END

// Calls
# define	CONS_CALL		std::cout << BYE "------------ Calling constructors ------------" STR_END
# define	DSTRUC_CALL		std::cout << BYE "------------ Calling destructors -------------" STR_END

// Tests
# define	TEST			std::cout << BGR "------------------> Testing "
# define	T_INT			<< "ints:" STR_END
# define	T_FLOAT			<< "floats:" STR_END
# define	T_CHAR			<< "chars:" STR_END
# define	T_STR			<< "strings:" STR_END
# define	FOUND			std::cout << BGR "	Element was found within the container!" STR_END


// Colors
# define	BLK				"\e[0;30m"
# define	RED				"\e[0;31m"
# define	GRN				"\e[0;32m"
# define	YEL				"\e[0;33m"
# define	MAG				"\e[0;35m"
# define	CYN				"\e[0;36m"
# define	WHT				"\e[0;37m"
# define	BLUE			"\e[0;34m"

// Bold
# define	BRED			"\e[1;31m"
# define	BWHT			"\e[1;37m"
# define	BGR				"\e[1;32m"
# define	BYE				"\e[1;33m"
# define	BBL				"\e[1;34m"
# define	BMA				"\e[1;35m"
# define	BCY				"\e[1;36m"

// Reset
# define	COLOR_RESET		"\e[0m"
# define	STR_END			COLOR_RESET << std::endl

template <typename T>
class	PmergeMe
{
	private:

		T	_cont;

	public:

		PmergeMe(T arr);
		~PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe & operator=(PmergeMe const & rhs);

		// Getters
		T	getCont();

		// Methods
		std::vector<int>	divide_merge(std::vector<int> arr);
		std::list<int>		divide_merge(std::list<int> arr);
		T	combine(T left, T right);
};

template <typename T>
void	printContainers(T number)
{
	for (typename T::iterator it = number.begin(); it != number.end(); it++)
		std::cout << BYE << *it << " ";
	std::cout << STR_END;
	return ;
}

// Const and Dest

template <typename T>
PmergeMe<T>::PmergeMe(T arr)
: _cont(0)
{
	T	result = divide_merge(arr);
	return ;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
	return ;
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe<T> const & src)
{
	*this = src;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe<T> const & rhs)
{
	_cont = rhs._cont;
	return *this;
}

// Getters

template <typename T>
T	PmergeMe<T>::getCont()
{
	return _cont;
}

// Methods

/*
	- Divide	= If the segment contains more than one element and that is not sorted
	median is calculated by adding the leftmost and rightmost element
	then divide by two.
	- Operate	= Once the median has been calculated, the left part is sorted (left to median),
	then the right part (median + 1 to right) using recursion.
	- Combine	= Both segments are merged.
*/
template <typename T>
std::vector<int> PmergeMe<T>::divide_merge(std::vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;

	std::vector<int>::iterator	median = arr.begin() + (arr.size() / 2);
	std::vector<int>	left(arr.begin(), median);
	std::vector<int>	right(median, arr.end());

	left = divide_merge(left);
	right = divide_merge(right);

	return combine(left, right);
}

template <typename T>
std::list<int> PmergeMe<T>::divide_merge(std::list<int> arr)
{
	if (arr.size() <= 1)
		return arr;

	std::list<int>::iterator	median = arr.begin();
	std::advance(median, arr.size() / 2);

	std::list<int>	left(arr.begin(), median);
	std::list<int>	right(median, arr.end());

	left = divide_merge(left);
	right = divide_merge(right);

	return combine(left, right);
}

template <typename T>
T PmergeMe<T>::combine(T left, T right)
{
	_cont.clear();

	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			_cont.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			_cont.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty())
	{
		_cont.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty())
	{
		_cont.push_back(right.front());
		right.erase(right.begin());
	}

	return _cont;
}