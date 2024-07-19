# pragma once

# include "Animal.hpp"

class	Brain
{
	private:

	public:

		Brain();
		Brain(Brain const & src);
		~Brain();
		Brain & operator=(Brain const & rhs);
	
		std::string	ideas[100];
};