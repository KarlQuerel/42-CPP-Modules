# pragma once

# include "Animal.hpp"

class	WrongAnimal
{
	protected:

		std::string	_type;

	public:

		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
	 	virtual ~WrongAnimal();
		WrongAnimal & operator=(WrongAnimal const & rhs);

		WrongAnimal(std::string name);

		void	makeSound() const;
		std::string		getType() const;

	private:
};