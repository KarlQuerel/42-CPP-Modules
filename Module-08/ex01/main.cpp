# include "Span.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	size_t	vec_size = 10;
	std::cout << BYE "	--> Let's create a container of size " << vec_size << "." << STR_END;
	LINE_BREAK;

	Span sp = Span(vec_size);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(-20);
	sp.addNumber(200);
	sp.addNumber(123);
	sp.addNumber(-456);
	sp.addNumber(14);
	sp.addNumber(11);
	sp.print_all();

	std::cout << BGR "	--> Shortest Span is = " << sp.shortestSpan() << STR_END;
	std::cout << BYE "	--> Longest Span is = " << sp.longestSpan() << STR_END;


	std::cout << BCY "	--> Let's try to add a value while container is full:" << STR_END;
	LINE_BREAK;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception const & invalid)
	{
		std::cout << BRED << invalid.what() << STR_END;
	}

	LINE_BREAK;
	std::cout << BCY "	--> Let's try to create a container of size 1:" << STR_END;
	LINE_BREAK;

	Span cont_1 = Span(1);

	cont_1.addNumber(1);
	try
	{
		std::cout << cont_1.shortestSpan() << STR_END;
	}
	catch(std::exception const & invalid)
	{
		std::cout << BRED << invalid.what() << STR_END;
	}

	unsigned int N = 10000;

	LINE_BREAK;
	std::cout << BYE "	--> Let's create a container of size " << N << "." << STR_END;
	LINE_BREAK;

	Span cont_2 = Span(N);

	std::cout << BYE "	--> Let's generate " << N << " numbers..." << STR_END;
	LINE_BREAK;
	

	cont_2.addNumberNAmountofTime(N);

	std::cout << BGR "	--> Shortest Span is = " << cont_2.shortestSpan() << STR_END;
	std::cout << BYE "	--> Longest Span is = " << cont_2.longestSpan() << STR_END;

	LINE_BREAK;
	return 0;
}

//main from subject
// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }