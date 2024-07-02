#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_Name = "Default";
	_Hit_points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
	std::cout << BGR D_CONS_FRAG STR_END;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_Hit_points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
	std::cout << BMA NAMED_CONS_FRAG STR_END;
	return ;
}
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << BYE C_CONS_FRAG STR_END;
	*this = src;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << BRED DECONS_FRAG STR_END;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << BMA ASSIGN_OP STR_END;
	this->_Name = rhs._Name;
	this->_Hit_points = rhs._Hit_points;
	this->_Energy_points = rhs._Energy_points;
	this->_Attack_damage = rhs._Attack_damage;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_Hit_points == 0)
		std::cout << BRED "FragTrap " << this->_Name << NO_HITPOINTS STR_END;
	else
		std::cout << BCY "FragTrap " << this->_Name << HIGH_FIVE STR_END;
	return ;
}