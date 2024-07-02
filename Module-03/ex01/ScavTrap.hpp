# pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		// Canonical Form
		ScavTrap();
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const & rhs);

		ScavTrap(std::string name);
		
		void	attack(const std::string & target);
		void	guardGate();

	private:


};