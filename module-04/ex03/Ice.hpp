# pragma once

# include "AMateria.hpp"

class	Ice : public AMateria
{
	private:

	public:

		Ice();
		Ice(Ice const & src);
		~Ice();
		Ice & operator=(Ice const & rhs);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};