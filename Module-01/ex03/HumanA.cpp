# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack()
{
	if (this->_weapon.getType() == "")
		std::cout << BWHT << this->_name << BRED NO_WPN COLOR_RESET << std::endl;
	else
		std::cout << BWHT << this->_name << BGR ATK << BYE << this->_weapon.getType() << COLOR_RESET << std::endl;
}
