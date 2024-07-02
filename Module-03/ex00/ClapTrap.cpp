# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Default"), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
	std::cout << BGR D_CONS STR_END;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
	std::cout << BMA NAMED_CONS STR_END;
	return ;
}
ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << BYE C_CONS STR_END;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << BRED DECONS STR_END;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << BMA ASSIGN_OP STR_END;
	this->_Name = rhs._Name;
	this->_Hit_points = rhs._Hit_points;
	this->_Energy_points = rhs._Energy_points;
	this->_Attack_damage = rhs._Attack_damage;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hit_points == 0)
		std::cout << BRED "ClapTrap " << this->_Name << NO_HITPOINTS STR_END;
	else if (this->_Energy_points == 0)
		std::cout << BRED "ClapTrap " << this->_Name << NO_ENERG STR_END;
	else
	{
		std::cout << BGR "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_Attack_damage << " points of damage!" STR_END;
		this->_Energy_points--;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_Hit_points)
	{
		this->_Hit_points = 0;
		std::cout << BRED "ClapTrap " << this->_Name << NO_HITPOINTS STR_END;
		return ;
	}
	this->_Hit_points -= amount;
	std::cout << BRED << "ClapTrap " << this->_Name << " has been attacked for " << amount << " points of damage! Only " << this->_Hit_points << " hit points remain..." STR_END;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hit_points == 0)
		std::cout << BRED "ClapTrap " << this->_Name << NO_HITPOINTS STR_END;
	else if (this->_Energy_points == 0)
		std::cout << BRED "ClapTrap " << this->_Name << NO_ENERG STR_END;
	else
	{
		std::cout << BGR "ClapTrap " << this->_Name << " repairs itself for " << amount << " points!" <<std::endl;
		this->_Hit_points += amount;
		std::cout << BWHT << this->_Hit_points << " hitpoints are now remaining." STR_END;
		this->_Energy_points--;
	}
	return ;
}
