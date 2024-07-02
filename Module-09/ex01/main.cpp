# include "RPN.hpp"

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

bool	is_valid_operator(char oper)
{
	if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
		return true;
	return false;
}

int	calculator(int first, int second, char oper)
{
	switch(oper)
	{
		case '+' :
			return (second + first);
		case '-' :
			return (second - first);
		case '*' :
			return (first * second);
		case '/' :
			if (first == 0)
				throw std::runtime_error(ZERO_DIV);;
			return (second / first);
	}
	return 0;
}

/*
	- Using a stack container makes perfect sense since expressions are evaluted from
	left to right with RPN, when an operator is encountered, it operates on the operands
	at the top of the stack.

	Last-In-First-Out(LIFO)

	- RPN.pop()		= removes the element at the top of the stack
	- RPN.top()		= retrieves the element at the top of the stack
	- RPN.push()	= adds a new element to the top of the stack
*/

void processOperation(std::string av)
{
	std::stack<int> RPN;

	int	first;
	int	second;

	for (size_t index = 0; index < av.size(); index++)
	{
		if (is_valid_operator(av[index]))
		{
			if (RPN.size() < 2)
			{
				INVALID_ARG;
				return;
			}
			first = RPN.top();
			RPN.pop();
			second = RPN.top();
			RPN.pop();
			RPN.push(calculator(first, second, av[index]));
		}
		else if (std::isdigit(av[index]))
			RPN.push(av[index] - '0');
		else if (!std::isspace(av[index]))
		{
			INVALID_ARG;
			return;
		}
	}

	if (RPN.size() != 1)
	{
		INVALID_ARG;
		return;
	}

	std::cout << BGR << "		" << RPN.top() << STR_END;
}


int	main(int ac, char **av)
{
	if (is_valid_arc_count(ac) == false)
		return 1;

	DELIM;
	try
	{
		processOperation(av[1]);
	}
	catch (std::runtime_error & invalid)
	{
		std::cout << invalid.what() << STR_END;
		return 1;
	}
	DELIM;

	return 0;
}