# pragma once

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private:

	public:

		WrongCat();
		WrongCat(WrongCat const & src);
		~WrongCat();
		WrongCat & operator=(WrongCat const & rhs);

		virtual void	makeSound() const;
};