# include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{
	std::cout << BGR MATERIA D_CONS;
	return ;
}

AMateria::AMateria(AMateria const & src) : _type(src.getType())
{
	std::cout << BYE MATERIA C_CONS;
	return ;
}

AMateria::~AMateria()
{
	std::cout << BRED MATERIA D_DES;
	return ;
}

AMateria & AMateria::operator=(const AMateria &rhs)
{
	std::cout << BMA MATERIA ASSIGN_OP;
	(void)rhs;
	return *this;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << BMA MATERIA PARAM_CONS;
	return ;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter & target)
{
	(void)target;
	return ;
}