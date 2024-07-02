# include "MutantStack.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	MutantStack<int>	mutant_1;
	std::vector<int>	vec_1;

	LINE_BREAK;
	std::cout << BYE "------------------> Let's test vectors:" << STR_END;
	LINE_BREAK;

	int	arr_int[] = {42, 1, 12, -15};

	mutant_1.push(arr_int[0]);
	mutant_1.push(arr_int[1]);
	mutant_1.push(arr_int[2]);
	mutant_1.push(arr_int[3]);

	vec_1.push_back(arr_int[0]);
	vec_1.push_back(arr_int[1]);
	vec_1.push_back(arr_int[2]);
	vec_1.push_back(arr_int[3]);

	std::cout << BMA "Stack's last element	= " << mutant_1.top() << STR_END;
	std::cout << BMA "Vector's last element	= " << vec_1.back() << STR_END;

	std::cout << BCY "Stack's size		= " << mutant_1.size() << STR_END;
	std::cout << BCY "Vectors's size		= " << vec_1.size() << STR_END;

	std::cout << BYE "Let's print stack's elements:" << STR_END;

	MutantStack<int>::iterator it = mutant_1.begin();
	MutantStack<int>::iterator it_end = mutant_1.end();

	++it;
	--it;

	while (it != it_end)
	{
		std::cout << BGR << *it << STR_END;
		++it;
	}

	std::cout << BYE "Let's print vector's elements:" << STR_END;

	std::vector<int>::iterator vit = vec_1.begin();
	std::vector<int>::iterator vit_end = vec_1.end();

	++vit;
	--vit;

	while (vit != vit_end)
	{
		std::cout << BGR << *vit << STR_END;
		++vit;
	}

	std::list<int>	list_1;


	LINE_BREAK;
	std::cout << BYE "------------------> Let's test lists:" << STR_END;
	LINE_BREAK;

	list_1.push_back(arr_int[0]);
	list_1.push_back(arr_int[1]);
	list_1.push_back(arr_int[2]);
	list_1.push_back(arr_int[3]);

	std::cout << BMA "Stack's last element	= " << mutant_1.top() << STR_END;
	std::cout << BMA "List's last element	= " << list_1.back() << STR_END;

	std::cout << BCY "Stack's size		= " << mutant_1.size() << STR_END;
	std::cout << BCY "Lists's size		= " << list_1.size() << STR_END;

	std::cout << BYE "Let's print stack's elements:" << STR_END;

	it = mutant_1.begin();

	++it;
	--it;

	while (it != it_end)
	{
		std::cout << BGR << *it << STR_END;
		++it;
	}

	std::cout << BYE "Let's print list's elements:" << STR_END;

	std::list<int>::iterator lit = list_1.begin();
	std::list<int>::iterator lit_end = list_1.end();

	++lit;
	--lit;

	while (lit != lit_end)
	{
		std::cout << BGR << *lit << STR_END;
		++lit;
	}
	LINE_BREAK;
	return 0;
}


// main from subject
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }