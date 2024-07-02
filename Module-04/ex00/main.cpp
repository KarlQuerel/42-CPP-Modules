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

	const	Animal*	meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();
	DELIM;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	DELIM;
	CONS_CALL;
	DELIM;

	const	WrongAnimal*	strange = new WrongAnimal();
	const	WrongAnimal*	isthatacat = new WrongCat();
	const	WrongCat*	isthatanotheracat = new WrongCat();
	DELIM;

	std::cout << BWHT << strange->getType() << " " << std::endl;
	std::cout << BWHT << isthatacat->getType() << " " << std::endl;
	std::cout << BWHT << isthatanotheracat->getType() << " " << std::endl;
	strange->makeSound();
	isthatacat->makeSound();
	isthatanotheracat->makeSound();

	DELIM;
	DSTRUC_CALL;
	DELIM;

	delete meta;
	delete j;
	delete i;

	delete strange;
	delete isthatacat;
	delete isthatanotheracat;

	return 0;
}