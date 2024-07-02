#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << BGR ICE D_CONS;
	return ;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
	std::cout << BYE ICE C_CONS;
	(void)src;
	return ;
}

Ice::~Ice()
{
	std::cout << BRED ICE D_DES;
	return ;
}

Ice & Ice::operator=(const Ice &rhs)
{
	std::cout << BMA ICE ASSIGN_OP;
	(void)rhs;
	return *this;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << BBL "* shoots an ice bolt at " << target.getName() <<" *" STR_END;
	return ;
}