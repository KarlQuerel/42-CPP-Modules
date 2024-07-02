# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(int ac, char **av)
{
	(void)av;

	if (ac > 1)
	{
		ERROR_ARG;
		return 1;
	}

	DELIM;
	CONS_CALL;
	DELIM;

	Animal*	Animals[8];
	DOG_CREATE;
	for (int i = 0; i < 4; i++)
		Animals[i] = new Dog();

	CAT_CREATE;
	for (int i = 4; i < 8; i++)
		Animals[i] = new Cat();

	std::cout << BCY "------------------> Testing sounds" STR_END;
	for (int i = 0; i < 8; i++)
		Animals[i]->makeSound();
	
	std::cout << BBL "------------------> Testing ideas" STR_END;
	Dog	Yako;
	for (int i = 0; i < 100; i++)
		Yako.brainwash(i, "Toss me the ball, you fat Human!");
	Yako.showAllIdeas();

	Cat	Cherry;
	for (int i = 0; i < 100; i++)
		Cherry.brainwash(i, "I wanna eat tuna and puke everywhere!");
	Cherry.showAllIdeas();

	Dog	Yako_clone;
	Yako_clone.showAllIdeas();

	Yako_clone = Yako;
	Yako_clone.showAllIdeas();

	{
		Dog Yako_the_real_clone(Yako_clone);
		Yako_the_real_clone.showAllIdeas();
	}
	std::cout << BRED "----- the previous 3 lines are the instance being deleted because we left the scope ----" STR_END;

	std::cout << BWHT "----- Checking deep copies success -----" STR_END;
	Yako_clone.showAllIdeas();


	DELIM;
	DSTRUC_CALL;
	DELIM;
	for (int i = 0; i < 8; i++)
		delete Animals[i];

	return 0;
}