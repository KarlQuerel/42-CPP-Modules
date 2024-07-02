# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_Name = "Default";
	_Hit_points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << BGR D_CONS_SCAV STR_END;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_Hit_points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << BMA NAMED_CONS_SCAV STR_END;
	return ;
}
ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << BYE C_CONS_SCAV STR_END;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << BRED DECONS_SCAV STR_END;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << BMA ASSIGN_OP STR_END;
	this->_Name = rhs._Name;
	this->_Hit_points = rhs._Hit_points;
	this->_Energy_points = rhs._Energy_points;
	this->_Attack_damage = rhs._Attack_damage;
	return *this;
}

void	ScavTrap::attack(const std::string & target)
{
	if (this->_Hit_points == 0)
		std::cout << BRED "ScavTrap " << this->_Name << NO_HITPOINTS STR_END;
	else if (this->_Energy_points == 0)
		std::cout << BRED "ScavTrap " << this->_Name << NO_ENERG STR_END;
	else
	{
		std::cout << BGR "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_Attack_damage << " points of damage!" STR_END;
		this->_Energy_points--;
	}
	return ;
}

void	ScavTrap::guardGate()
{
	if (this->_Hit_points == 0)
		std::cout << BRED "ScavTrap " << this->_Name << NO_HITPOINTS STR_END;
	else
		std::cout << BGR "ScavTrap " << this->_Name << GATEKEEP STR_END;
	return ;
}