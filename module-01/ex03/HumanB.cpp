#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << BRED NO_WPN COLOR_RESET << std::endl;
	else
		std::cout << BWHT << this->_name << BGR ATK << BYE << this->_weapon->getType() << COLOR_RESET << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
