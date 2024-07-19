#include <iostream>
#include "Array.hpp"

int	main(int ac, char ** av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	TEST T_PARAM;
	Array<int>	a(5);
	Array<int>	b(5);
	
	LINE_BREAK;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << BGR "a[" << i << "] = " << a[i] << STR_END;
	
	LINE_BREAK;

	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << BGR "b[" << i << "] = " << b[i] << STR_END;

	LINE_BREAK;
	T_FILL;
	LINE_BREAK;

	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 1;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << BGR "a[" << i << "] = " << a[i] << STR_END;
	

	LINE_BREAK;
	T_ASSIGN;
	LINE_BREAK;
	
	b = a;
	LINE_BREAK;


	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << BGR "b[" << i << "] = " << b[i] << STR_END;

	TEST T_EMPTY;
	LINE_BREAK;

	Array<int> empty;

	TEST T_OOB;
	LINE_BREAK;

	try
	{
		std::cout << a[a.size() + 1] << STR_END;
	}
	catch (std::exception & invalid)
	{
		std::cout << invalid.what() << STR_END;
	}

	LINE_BREAK;

	return 0;
}

// --> main from subject
// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }