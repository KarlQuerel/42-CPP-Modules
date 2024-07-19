# pragma once

# include "Brain.hpp"
# include "Animal.hpp"

class	Dog : public Animal
{
	private:

		Brain*	_brain;

	public:

		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog & operator=(Dog const & rhs);

		virtual void	makeSound() const;
		bool			isValidIndex(int index) const;
		void			brainwash(int index, std::string idea);
		void			showAllIdeas() const;
		void			showOneIdea(int index) const;
};