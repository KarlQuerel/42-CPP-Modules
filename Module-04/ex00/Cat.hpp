# pragma once

# include "Animal.hpp"

class	Cat : public Animal
{
	private:

	public:

		Cat();
		Cat(Cat const & src);
		~Cat();
		Cat & operator=(Cat const & rhs);

		virtual void	makeSound() const;

};