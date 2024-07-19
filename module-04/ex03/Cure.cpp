#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << BGR CURE D_CONS;
	return ;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
	std::cout << BYE CURE C_CONS;
	(void)src;
	return ;
}

Cure::~Cure()
{
	std::cout << BRED CURE D_DES;
	return ;
}

Cure & Cure::operator=(const Cure &rhs)
{
	std::cout << BMA CURE ASSIGN_OP;
	(void)rhs;
	return *this;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << BCY "* heals " << target.getName() << "'s wounds *" STR_END;
	return ;
}