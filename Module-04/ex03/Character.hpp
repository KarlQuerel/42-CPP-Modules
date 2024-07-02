# pragma once

# include "AMateria.hpp"

class Character : public ICharacter
{

	private:

		std::string	_name;
		AMateria*	_materias[4];

	public:

		Character();
		Character(Character const & src);
		~Character();
		Character & operator=(Character const & rhs);

		Character(std::string name);
		virtual std::string const &	getName() const;
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);
		bool			isValidIndex(int index) const;
		AMateria*		getMateria(int index) const;

};