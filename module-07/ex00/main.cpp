# include "whatever.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;
	TEST T_INT;
	LINE_BREAK;

	int	a = 42;
	int	b = 21;

	/*
	Since the data type of the ::swap() function will receive unspecified parameter,
	a type deduction is performed where the program is called.
	It's a better practice to specify the type and explicitly cast it so the compile
	will compile the function accordingly.
	*/

	std::cout << BCY "Before Swap	-> " << a << " and " << b << STR_END;
	::swap<int>(a, b);
	std::cout << BYE "After Swap	-> " << a << " and " << b << STR_END;
	std::cout << BRED << "Min		-> " << ::min<int>(a, b) << STR_END;
	std::cout << BMA << "Max		-> " << ::max<int>(a, b) << STR_END;

	LINE_BREAK;
	TEST T_FLOAT;
	LINE_BREAK;

	float c = 42.042f;
	float d = 21.021f;

	std::cout << BCY "Before Swap	-> " << c << " and " << d << STR_END;
	::swap<float>(c, d);
	std::cout << BYE "After Swap	-> " << c << " and " << d << STR_END;
	std::cout << BRED << "Min		-> " << ::min<float>(c, d) << STR_END;
	std::cout << BMA << "Max		-> " << ::max<float>(c, d) << STR_END;

	LINE_BREAK;
	TEST T_CHAR;
	LINE_BREAK;

	char e = 'e';
	char f = 'f';

	std::cout << BCY "Before Swap	-> " << e << " and " << f << STR_END;
	::swap<char>(e, f);
	std::cout << BYE "After Swap	-> " << e << " and " << f << STR_END;
	std::cout << BRED << "Min		-> " << ::min<char>(e, f) << STR_END;
	std::cout << BMA << "Max		-> " << ::max<char>(e, f) << STR_END;

	LINE_BREAK;
	TEST T_STR;
	LINE_BREAK;

	std::string g = "Hello";
	std::string h = "Goodbye";

	std::cout << BCY "Before Swap	-> " << g << " and " << h << STR_END;
	::swap(g, h);
	std::cout << BYE "After Swap	-> " << g << " and " << h << STR_END;
	std::cout << BRED << "Min		-> " << ::min(g, h) << STR_END;
	std::cout << BMA << "Max		-> " << ::max(g, h) << STR_END;


	return 0;
}

// main subject
// int main( void )
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }