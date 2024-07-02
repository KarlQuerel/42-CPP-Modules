# include "Serializer.hpp"
# include "Data.hpp"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	LINE_BREAK;

	Data		data_1;
	Data*		data_2;

	uintptr_t	ptr_1;
	uintptr_t	ptr_2;

	data_1.name = "Banane";
	data_1.number = 11;

	std::cout << BBL "--> data_1:" << std::endl << "Name = " << data_1.name << " and number = " << data_1.number << STR_END;
	std::cout << BMA "data_1 add " << &data_1 << STR_END;

	ptr_1 = Serializer::serialize(&data_1);

	std::cout << BMA "data_1 add " << ptr_1 << STR_END;

	LINE_BREAK;
	
	data_2 = Serializer::deserialize(ptr_1);

	std::cout << BBL "--> data_2:" << std::endl << "Name = " << data_2->name << " and number = " << data_2->number << STR_END;
	std::cout << BMA "data_2 add " << &data_2 << STR_END;

	ptr_2 = Serializer::serialize(data_2);

	std::cout << BMA "data_2 add " << ptr_2 << STR_END;

	DELIM;

	if (data_2 == &data_1)
		std::cout << BGR "-->	Data's addresses are the same!	<--" STR_END;

	DELIM;
	LINE_BREAK;
	return 0;
}