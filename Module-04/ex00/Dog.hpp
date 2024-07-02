# pragma once

# include "Animal.hpp"

class	Dog : public Animal
{
	private:

	public:

		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog & operator=(Dog const & rhs);

		virtual void	makeSound() const;
};