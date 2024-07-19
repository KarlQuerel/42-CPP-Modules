# pragma once

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:


	public:

		// Canonical Form
		FragTrap();
		FragTrap(FragTrap const & src);
		~FragTrap();
		FragTrap & operator=(FragTrap const & rhs);

		FragTrap(std::string name);

		void	highFivesGuys(void);
};