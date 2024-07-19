# pragma once

# include "Brain.hpp"
# include "Animal.hpp"

class	Cat : public Animal
{
	private:

		Brain* _brain;

	public:

		Cat();
		Cat(Cat const & src);
		~Cat();
		Cat & operator=(Cat const & rhs);

		virtual void	makeSound() const;
		bool			isValidIndex(int index) const;
		void			brainwash(int index, std::string idea);
		void			showAllIdeas() const;
		void			showOneIdea(int index) const;
};