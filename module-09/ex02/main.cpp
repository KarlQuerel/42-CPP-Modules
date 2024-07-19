# include "PmergeMe.hpp"

bool	is_valid_arc_count(int const ac)
{
	if (ac <= 1)
	{
		ERROR_ARG;
		return false;
	}
	else
		return true;
}

bool	are_arg_positive_int(char *av)
{
	for (size_t digits = 0; digits < strlen(av); digits++)
	{
		if (isdigit(av[digits]) == 0)
		{
			NOT_INT;
			return false;
		}
		if (atoi(av) < 0)
		{
			ABOVE_MAX;
			return false;
		}
	}
	return true;
}

void	printTime_vector(std::vector<int> vec, double const time)
{
	std::cout << BCY << "Time to process a range of "
	<< vec.size() << " elements with std::vectors: "
	<< BYE << time << " us" STR_END;

	return ;
}

void	printTime_list(std::list<int> list, double const time)
{
	std::cout << BCY << "Time to process a range of "
	<< std::distance(list.begin(), list.end()) << " elements with std::list: "
	<< BYE << time << " us" STR_END;

	return ;
}

/*
	- The Ford-Johnson algorithm, also known as merge-insertion sort is an algorithm
	which combines the merge sort and insertion sort algorithms and is 
	designed to perfom as few comparisons as possible to sort a collection.
	It basically works in 5 steps:
	
		--> Divide	= Split collection in n / 2 pairs : odd and even numbers
		(if total number of elements is odd, one element will be unpaired on purpose)
		--> Merge	= Perform n / 2 comparisons, one per pair, to determine the larger of the two
		elements in each pair. The two arrays are sorted using insertion sort.
		--> Combine	= Recursively sort the n / 2 of elements by their highest value (asc order)

	- clock_t	= data type used to store processor time
	starting time is measured with clock()

*/

int	main(int ac, char **av)
{
	if (is_valid_arc_count(ac) == false)
		return 1;
	
	
	std::vector<int>	vec(0);

	for (int index = 1; index < ac; index++)
	{
		if (are_arg_positive_int(av[index]) == false)
			return 1;
		vec.push_back(atoi(av[index]));
	}

	std::list<int>		list(vec.begin(), vec.end());

	DELIM;
	std::cout << BBL << "Before:	";
	printContainers(vec);

	clock_t	begin_vec = clock();
	
	PmergeMe<std::vector<int> >	mergevec(vec);
	clock_t	finish_vec = clock();

	std::vector<int>	vec_sorted = mergevec.getCont();

	std::cout << BGR << "After:	";
	printContainers(vec_sorted);
	
	double	time_elapsed_vec = (double)(finish_vec - begin_vec) / CLOCKS_PER_SEC * 1000;
	printTime_vector(vec_sorted, time_elapsed_vec);

	// -----------

	clock_t	begin_list = clock();
	PmergeMe<std::list<int> >	list_sorted(list);
	clock_t	finish_list = clock();

	double	time_elapsed_list = (double)(finish_list - begin_list) / CLOCKS_PER_SEC * 1000;
	printTime_list(list_sorted.getCont(), time_elapsed_list);

	DELIM;
	return 0;
}