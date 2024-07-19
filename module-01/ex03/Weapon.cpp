#include "Weapon.hpp"
# include <cstdlib>

Weapon::Weapon(std::string type) : _type(type) 
{

	return ;
}

Weapon::Weapon(void *ptr)
{
	static_cast<void>(ptr);
}

Weapon::~Weapon()
{
	return ;
}

std::string const& Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}