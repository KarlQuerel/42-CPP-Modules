# include "AMateria.hpp"
# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "ICharacter.hpp"
# include "MateriaSource.hpp"

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

	AMateria	*ice_1 = new Ice();
	AMateria	*ice_2 = ice_1->clone();
	AMateria	*cure_1 = new Cure();
	AMateria	*cure_2 = cure_1->clone();

	DELIM;
	std::cout << BWHT "--> Testing adresses" STR_END;
	DELIM;

	std::cout << BMA "- ice_1's adress = " << ice_1 << " and type = " << ice_1->getType() << STR_END;
	std::cout << BMA "- ice_2's adress = " << ice_2 << " and type = " << ice_2->getType() << STR_END;
	std::cout << BBL "- cure_1's adress = " << cure_1 << " and type = " << cure_1->getType() << STR_END;
	std::cout << BBL "- cure_2's adress = " << cure_2 << " and type = " << cure_2->getType() << STR_END;

	DELIM;
	std::cout << BWHT "--> Testing MateriaSource methods: " STR_END;
	DELIM;

	IMateriaSource*	src = new MateriaSource();

	// learn
	src->learnMateria(ice_1);
	src->learnMateria(cure_2);
	src->learnMateria(NULL);
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// create
	AMateria*	ice_3 = src->createMateria("ice");
	AMateria*	cure_3 = src->createMateria("cure");
	AMateria*	ice_4 = src->createMateria("hello");
	AMateria*	cure_4 = src->createMateria("goodbye");

	std::cout << BMA "- ice_3's adress = " << ice_3 << " and type = " << ice_3->getType() << STR_END;
	std::cout << BMA "- cure_3's adress = " << cure_3 << " and type = " << cure_3->getType() << STR_END;

	std::cout << BMA "- ice_4's adress = " << ice_4 << STR_END;
	std::cout << BMA "- cure_4's adress = " << cure_4 << STR_END;

	DELIM;
	std::cout << BWHT "--> Testing Characters methods: " STR_END;
	DELIM;

	Character*	Gandalf = new Character("Gandalf");
	Character*	Saruman = new Character("Saruman");

	// equip
	Gandalf->equip(src->createMateria("ice"));
	Gandalf->equip(src->createMateria("cure"));
	Gandalf->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));
	Saruman->equip(src->createMateria("ice"));

	// use
	Gandalf->use(0, *Saruman);
	Gandalf->use(-1, *Saruman);
	Gandalf->use(10, *Saruman);
	Gandalf->use(1, *Saruman);
	Saruman->use(1, *Gandalf);

	// unequip
	AMateria *tmp = Gandalf->getMateria(0);
	Gandalf->unequip(0);
	delete tmp;
	Gandalf->use(0, *Saruman);
	Gandalf->use(10, *Saruman);

	DELIM;
	std::cout << BWHT "--> Testing Deep Copies: " STR_END;
	DELIM;

	Character	*Gandalf_the_evil_twin = new Character(*Gandalf);

	std::cout << BGR "Let us see if Gandalf is still alive Gandalf after killing Gandalf's evil twin..." STR_END;
	Gandalf_the_evil_twin->use(2, *Gandalf);
	delete Gandalf_the_evil_twin;
	Gandalf->use(2, *Saruman);
	Gandalf->use(0, *Saruman);
	std::cout << BGR "Old Gandalf is still alive!" STR_END;

	DELIM;
	DSTRUC_CALL;
	DELIM;
	delete	ice_2;
	delete	ice_3;
	delete	cure_1;
	delete	cure_3;
	delete	Gandalf;
	delete	Saruman;

	delete src;

	return 0;
}