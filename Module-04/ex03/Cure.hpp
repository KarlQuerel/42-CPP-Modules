# pragma once

# include "AMateria.hpp"

class	Cure : public AMateria
{
	private:

	public:

		Cure();
		Cure(Cure const & src);
		~Cure();
		Cure & operator=(Cure const & rhs);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};